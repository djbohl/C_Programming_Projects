#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){

    int sum = 0;
    bool isPrime = true;

    //loop through numbers 1-100
    for(int n = 1; n <= 100; n++) {
        /* since sqrt of 1, 2, & 3 are less than 2 set isPrime conditional
        because loop can't check them */
        if(n == 1 ) {
            isPrime = false;
        } else if(n == 2 || n == 3) {
            isPrime = true;
        }
        /* iterates from 2 to sqrt of n
            example 1: sqrt(4) is 2 4 % 2 == 0 so not a prime
            example 2: 8 % 2 == 0 so also not a prime
        */
        for(int i = 2; i <= sqrt(n); i++) {
            //if divisible by i then n is not prime
            if(n % i == 0) {
                isPrime = false;
                break;
            } else {
                isPrime = true;
            }
        }
        //print all prime numbers
        if(isPrime) {
            printf("\n%d", n);
            sum += n;
        }
    }
    //printf("\nSum is %d", sum);
}