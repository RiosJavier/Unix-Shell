// Name: Javier Rios
// CS 4350 – 251 - Unix Systems Programming
// Assignment Number: 4
// Due Date: 3 / 18 / 2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() {
    return (rand() % 15) + 1;
}

int calculateReproduction(int target_sum) {
    int count = 0;
    int sum = 0;

    while (sum != target_sum) {
        int num1 = generateRandomNumber();
        int num2 = generateRandomNumber();
        sum = num1 + num2;
        count++;

        printf("\nGenerating First Number = %d\n", num1);
        printf("Generating Second Number = %d\n", num2);
        printf("The sum of the generated numbers is : %d\n", sum);
    }

    return count;
}

int main() {

    srand(time(NULL));

    printf("Practicing C Programming Language\n\n\n");

    int first_num = generateRandomNumber();
    int second_num = generateRandomNumber();
    int sum = first_num + second_num;

    printf("First Generated Number : %d\n", first_num);
    printf("Second Generated Number : %d\n\n", second_num);
    printf("First Number + Second Number = %d\n\n\n", sum);

    printf("Processing . . . . . . \n\n");

    int reproductionCount = calculateReproduction(sum);

    printf("\nNumber of Times the Numbers were Generated\n");
    printf("Before the Desired sum was reached = %d\n\n", reproductionCount);

    printf("Implemented By Javier Rios\n");
    printf("3 - 18 - 2024\n");

    return 0;
}


