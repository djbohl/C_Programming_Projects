/*  --------------------------------
-- Assignment Description --
Chapter 7 Challenge:
Calculator Using Function Pointers -
Create a menu driven program that allows the user to choose whether to add, subtract, multiply or divide two numbers.
The program should then input two double values from the user, perform the appropriate calculation and display the result.
Use an array of function pointers in which each pointer represents a function that returns void and receives two double parameters.
The corresponding unctions should each display messages indicating which calculation was performed, the values of the params and the result of the calculation.
---------------------------------- />

#include <stdio.h>

// function prototypes
void add(double value1, double value2);
void subtract(double value1, double value2);
void multiply(double value1, double value2);
void divide(double value1, double value2);

int main() {
    //initialize array of pointers to functions that take 2 double values that return void
    void(*f[4])(double, double) = {add, subtract, multiply, divide};
    printf("Enter a choice\n0:Add\n1:Subtract\n2:Multiply\n3:Divide\n4:Exit\n");
    
    int choice;
    double value1;
    double value2;
    
    while(1){
        printf("Choice: \n");
        scanf("%d", &choice);
        
        //validate user input
        if(choice < 0 || choice > 4) {
            printf("Invalid choice! Please enter a number between 0-4");
        }
        
        //stop running program/loop if user enters 4
        if(choice == 4){
            printf("Program execution complete.");
            break;
        }
        
        printf("Please enter a number\n");
        scanf("%lf", &value1);
        printf("Please enter a second number\n");
        scanf("%lf", &value2);
        
        //invoke function choice and pass the doubles into the arguments
        (*f[choice])(value1, value2);
    }
}

void add(double value1, double value2) {
    //add the two numbers
    double total = value1 + value2;
    printf("%lf plus %lf is %lf.\n", value1, value2, total);
}

void subtract(double value1, double value2) {
    //substract the two numbers
    double total = value1 - value2;
    printf("%lf minus %lf is %lf.\n", value1, value2, total);
}

void multiply(double value1, double value2) {
    //multiply the two numbers
    double total = value1 * value2;
    printf("%lf x %lf is %lf.\n", value1, value2, total);
}

void divide(double value1, double value2) {
    //divide the two numbers
    double total = value1/value2;
    printf("%lf / %lf is %lf.\n", value1, value2, total);
}
