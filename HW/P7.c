/*
NAME : _Javier Rios_
CS 4350 – 251 - Unix Systems Programming
Assignment Number: _7_
Due Date: 4 / 29 / 2024

 Description:
 This program uses 12 synchronized threads to perform different mathematical operations on a user-provided integer, X.
 Each thread calculates a unique result that contributes to a cumulative total.

*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

pthread_mutex_t mutex;
int total = 0;
double results[12];

double factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

void *thread_func(void *arg) {
    int index = *(int *)arg;
    double result = 0;
    int X = *((int *)arg + 1);

    switch (index) {
        case 1:
            result = 1.0;  // X / X
            break;
        case 2:
            result = 2.0;  // (X + X) / X
            break;
        case 3:
            result = sqrt(X);
            break;
        case 4:
            result = sqrt(X) + 1.0;
            break;
        case 5:
            result = factorial((int)sqrt(X)) - 1.0;
            break;
        case 6:
            result = X - (X / sqrt(X));
            break;
        case 7:
            result = 1.0 + X - sqrt(X);
            break;
        case 8:
            result = X - 1.0;
            break;
        case 9:
            result = X;
            break;
        case 10:
            result = 1.0 + X;
            break;
        case 11:
            result = (X * X + 2 * X) / X;
            break;
        case 12:
            result = X + (X / sqrt(X));
            break;
    }

    pthread_mutex_lock(&mutex);
    total += result;
    results[index - 1] = result;
    pthread_mutex_unlock(&mutex);

    free(arg);
    return NULL;
}

int main() {
    printf("\nWelcome to Javier Rios's Thread App\n\n");
    printf("This program will do the following:\n\n");
    printf("Accepts an integer number X from the user and then uses\n");
    printf("twelve synchronized threads in order to do some math operations:\n\n\n");

    int X;
    printf("Enter an Integer > 0 --- > ");
    scanf("%d", &X);

    if (X <= 0) {
        printf("\n**** Number must be greater than 0 ***\n");
        printf("\nProgrammed by Javier Rios\n4 – 29 - 2024\n\n");
        return 1;
    }

    pthread_t threads[12];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 1; i <= 12; i++) {
        int *arg = malloc(2 * sizeof(int));
        *arg = i;
        *(arg + 1) = X;
        pthread_create(&threads[i - 1], NULL, thread_func, arg);
    }

    for (int i = 0; i < 12; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("\nSum of Numbers Between 1 and 12 = 78\n\n");
    for (int i = 0; i < 12; i++) {
        printf("Result of the %d%s Thread = %.2f\n", i + 1, (i == 0) ? "st" : (i == 1) ? "nd" : (i == 2) ? "rd" : "th", results[i]);
    }
    printf("\n\nTotal Result from All Threads = %d\n", total);
    printf("\nSum and the total %s the same.\n", (total == 78) ? "are" : "are not");
    printf("\nProgrammed by Javier Rios\n4 – 29 - 2024\n\n");

    return 0;
}
