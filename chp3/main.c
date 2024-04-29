#include <stdio.h>

//function prototypes
int getInput();
void trackDigits(int n);
void checkNines(int n, int d);

int number = 0;

int main(){
    //assign getInput result to number
    number = getInput();
    //check for max digits
    trackDigits(number);
}

int getInput() {
    int input = 0;
    printf("Enter an integer that is 5 digits or less: ");
    scanf("%d", &input);
    return input;
}

void trackDigits(int n) {
    int d = 0;
    // while input (n) does not equal 0 divide n by 10
    while(n != 0) {
        // count digits (d) of input (n)
        n /= 10;
        d += 1;
    }
    // if digits are less than 6 call checkNines otherwise return to main
    if(d > 6) {
        main();
    } else if (d < 6){
        checkNines(number , d);
    }
}

void checkNines(int n, int d) {
    int nines = 0;
    // loop through input number to count number of 9s
    for (int i = 0; i < d - 1; i++) {
        if (n % 10 == 9) {
            nines += 1;
        }
    }
    //output results
    printf("\nInput Number %d", number);
    printf("\nNumber of 9s: %d", nines);
    printf("\nNumber of digits: %d", d);
}