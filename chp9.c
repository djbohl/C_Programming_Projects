/*  --------------------------------
-- Assignment Description --
  Reversing the Order of an Integer's Bits
  Write a program that reverses the order of the bits in an unsigned int value. 
  The program should input the value from the user and call function reverseBits to print the bits in reverse order.
  Print the value in bits both before and after the bits are reversed to confirm that the bits are reversed properly.
  --------------------------------- />

#include <stdio.h>
#include <limits.h>

// function prototype
void reverseBits (unsigned int value);

int main ()
{
  unsigned int x = 0;
  printf ("Please enter an integer.\n");
  scanf ("%u", &x);
  reverseBits (x);
}

void reverseBits(unsigned int value) {
    // Initialize the new value to 0
    unsigned int newvalue = 0;
    // Iterate through each bit of the original value
    for (int i = 0; i < CHAR_BIT * sizeof(unsigned int); ++i) {
        // Extract the least significant bit of the original value
        unsigned int bit = (value >> i) & 1;
        // Set the corresponding bit in the new value (in reverse order)
        newvalue |= bit << ((CHAR_BIT * sizeof(unsigned int) - 1) - i);
    }

    // Print the original and new values
    printf("%10u = ", value);
    printf("Original value: ");
    for (int i = 0; i < CHAR_BIT * sizeof(unsigned int); ++i) {
        putchar((value >> ((CHAR_BIT * sizeof(unsigned int) - 1) - i)) & 1 ? '1' : '0');
        if ((i + 1) % 8 == 0) putchar(' '); // print space every 8 bits
    }

    printf("\n%10u = ", newvalue);
    printf("Reversed value: ");
    for (int i = 0; i < CHAR_BIT * sizeof(unsigned int); ++i) {
        putchar((newvalue >> ((CHAR_BIT * sizeof(unsigned int) - 1) - i)) & 1 ? '1' : '0');
        if ((i + 1) % 8 == 0) putchar(' '); // print space every 8 bits
    }
    printf("\n");
}
