/*  --------------------------------
-- Assignment Description --
Chapter 5 Challenge:
(Recursive Prime) Write a recursive function isPrime that determines whether the given input is a prime number. 
Your function should return a boolean value (0 for false, 1 for true). 
Use this function in a program - ask for integer input from the user, return either "This is a prime number" or "This is not a prime number"

Sample Program Run 1:
Please enter any integer number: 5
This is a prime number

Sample Program Run 2:
Please enter any integer number: 6
This is not a prime number
------------------------------ */

#include<stdio.h>
#include <stdbool.h>

// function prototype
int isPrime(int nInput, int k);

int main(){
    int n; // init for user input
    int k = 7;
    printf("Please enter an integer number:");
    scanf("%d", &n);
    isPrime(n, k);
}

int isPrime(int n, int k){
    if (k < 2) {
      // if k is less than 2 at this point it must be a prime number
        printf("\nThis is a prime number");
    } else if(n == 1 ) {
        printf("\nThis is not a prime number");
    } else if(n == 2 || n == 3 || n == 5 || n == 7) {
      // it is easier to just return prime if input is any of these numbers
        printf("\nThis is a prime number");
    } else if(n % k == 0) {
        printf("\nThis is not a prime number");
    } else if(n % k < 0) {
        printf("\nThis is a prime number");
    } else {
      // if none of the above are true call function again pass n (user input) and k - 1
        return (isPrime(n, k - 1)); // recursive function call
    }
}
