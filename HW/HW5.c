// NAME : Javier Rios CS 4350 – Unix Systems Programming
// Assignment Number: HW5
// Due Date: 3 / 27 / 2024
// Extended Due Date: 4 / 1 / 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_MSG_SIZE 1024
#define NUM_CHARS 94

// Function prototypes
void encryptDecryptMessage(char *message, int key, int encrypt, const char *chars);
void printMessageStats(char *message, const char *chars);
int validateChoiceAndKey(int choice, int key);

int main() {
    char message[MAX_MSG_SIZE];
    int choice, key;
    char chars[NUM_CHARS] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    printf("Welcome to cryptography.\n\n");

    do {
        printf("What would you like to do to a message?\nEnter (1 - encrypt, 2 - decrypt, 15 exit)\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        while (getchar() != '\n'); // Clear input buffer

        if (choice == 15) break;
        
        if (choice == 1 || choice == 2) {
            printf("Enter your message:\n");
            fgets(message, MAX_MSG_SIZE, stdin);
            message[strcspn(message, "\n")] = 0;
            
            printf("Enter the key number (1-93): ");
            scanf("%d", &key);
            while (getchar() != '\n'); // Clear input buffer

            if (!validateChoiceAndKey(choice, key)) continue;

            encryptDecryptMessage(message, key, (choice == 1), chars);
        } else {
            printf("Invalid choice.\n\n");
        }
    } while (choice != 15);

    printf("\nJavier Rios Security Systems\n");
    printf("3-27-2024\n");

    return 0;
}

void encryptDecryptMessage(char *message, int key, int encrypt, const char *chars) {
    printMessageStats(message, chars);

    char processedMsg[MAX_MSG_SIZE] = {0};
    for (int i = 0; message[i] != '\0'; i++) {
        const char *charPtr = strchr(chars, message[i]);
        if (charPtr) {
            int charIndex = charPtr - chars;
            int newIndex = encrypt ? (charIndex + key) % NUM_CHARS : (NUM_CHARS + charIndex - key) % NUM_CHARS;
            processedMsg[i] = chars[newIndex];
        } else {
            processedMsg[i] = message[i];
        }
    }

    printf("The %s text is:\n%s\n", encrypt ? "encrypted" : "decrypted", processedMsg);
    printf("Concatenation of original and %s text: %s%s\n\n", encrypt ? "encrypted" : "decrypted", message, processedMsg);
}

void printMessageStats(char *message, const char *chars) {
    int capitals = 0, smalls = 0, digits = 0, symbols = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        if (isupper(message[i])) capitals++;
        else if (islower(message[i])) smalls++;
        else if (isdigit(message[i])) digits++;
        else if (strchr(chars, message[i])) symbols++;
    }

    printf("Number of Capital Letters: %d\n", capitals);
    printf("Number of Small Letters: %d\n", smalls);
    printf("Number of Digits: %d\n", digits);
    printf("Number of Symbols: %d\n", symbols);
    printf("Number of Characters in the message: %ld\n", strlen(message));
    // Echo the original message
    printf("Converting Letters : %s\n", message);
}

int validateChoiceAndKey(int choice, int key) {
    if (choice != 1 && choice != 2) {
        printf("Invalid Input\n\n");
        return 0;
    }
    if (key < 1 || key > 93) {
        printf("Invalid Key Number\n\n");
        return 0;
    }
    return 1; // Valid input
}
