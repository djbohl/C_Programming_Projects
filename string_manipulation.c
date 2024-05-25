/*  --------------------------------
-- Assignment Description --
  Chapter 8 Challenge

(Appending Part of a String) Write a program that uses function strncat to append part of a string to another string. The program (not the user) should input the strings, and the number of characters to be appended, then display the first string and its length after the second string was appended.

Example Program Run -- you should use your own words, not Happy_ and Birthday:
String 1: Happy_
String 2: Birthday
strncat(s2, s1, 6) = Happy_Birthday
  --------------------------------- />

#include <stdio.h>
#include <string.h>

int main(){
    // initialize char arrays
    char w1[20];
    char w2[20];

    // copy string to char arrays
    strcpy(w1, "Frosted flakes, ");
    strcpy(w2, "they'rrre great!");
    
    // prints before appending, and practice using puts
    printf("Before appending: \n");
    puts(w1);
    puts(w2);
    puts("");
    puts("After appending:");
    
    // print w1 + w2 using strncat
    printf("strncat(w1, w2, 16)= %s\n", strncat(w1, w2, 16));
    // get length of w1 after appending and print result
    printf("String length of w1 after appending: %zu\n", strlen(w1));
}
