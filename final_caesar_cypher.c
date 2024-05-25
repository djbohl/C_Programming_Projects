/******************************************************************************

Final Project - Caesar Cypher

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// global constant for max char[] max value nad alphabet array
int MAX_VALUE = 25;

// function prototypes
void encrypt(char *stringToDecrypt, char *alphabet);
bool isAllLetters(char *stringToEncrypt);

int main()
{
    // get option from user to encrypt or decrypt
    int option = 0;
    char stringToEncrypt[MAX_VALUE];
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool isValid = false;
    
    while (!isValid) {
        printf("Enter a word to encrypt (letters only, no spaces): ");
        scanf("%s", stringToEncrypt);

        // Check if the entered string contains only letters
        if (isAllLetters(stringToEncrypt)) {
            encrypt(stringToEncrypt, alphabet);
            isValid = true;
        } else {
            printf("Please enter only letters.\n");
        }
    }

    return 0;
}

bool isAllLetters(char *stringToEncrypt) {
    // loop through input
    for (int i = 0; i < strlen(stringToEncrypt); i++) {
        // check for capital and lowercase letters
        if (!((stringToEncrypt[i] >= 'A' && stringToEncrypt[i] <= 'Z') || 
              (stringToEncrypt[i] >= 'a' && stringToEncrypt[i] <= 'z'))) {
            return false; // If any character is not a letter, return false
        }
    }
    return true; // All characters are letters
}

void encrypt(char *stringToEncrypt, char *alphabet) {
    char encryptedString[MAX_VALUE];
    // initialize array to all zeros or else garbage values from previous invalid input will cause errors
    memset(encryptedString, 0, sizeof(encryptedString));
    // loop through the string to encrypt and shift char to encrypt
    for (int i = 0; i < strlen(stringToEncrypt); i++) {
        char currentChar = stringToEncrypt[i]; // Current character from stringToEncrypt

        // Calculate the index of currentChar in the alphabet
        int index;
        if (currentChar >= 'a' && currentChar <= 'z') {
            index = currentChar - 'a';
        } else if (currentChar >= 'A' && currentChar <= 'Z') {
            index = currentChar - 'A';
        } 

        // Calculate the shifted index
        int shiftedIndex = (index + 3) % strlen(alphabet);

        // Append the character at the shifted index to encryptedString
        char shiftedChar = alphabet[shiftedIndex];
        strncat(encryptedString, &shiftedChar, 1);
    }

    // Null-terminate the encrypted string
    encryptedString[strlen(stringToEncrypt)] = '\0';
    // Print the encrypted string
    printf("Encrypted String: %s\n", encryptedString);
}
