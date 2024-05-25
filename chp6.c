/*  --------------------------------
-- Assignment Description --
  Chapter 6 Challenge:
(Print a String Backward) Write a recursive function stringReverse that takes a character array as an argument, prints it back to front and returns nothing. The function should stop processing and return when the terminating null character of the string is encountered. You should take input from a user (asking for a word to reverse) and output the reversed statement. You will lose points if you do not take a recursive approach.

Sample Program Run:
Please enter a word you would like to reverse: dog
god
------------------------------------- />

#include <stdio.h>

//function prototype
void stringReverse(char word[20], int i);

int main(){
    char word[20] = {0}; // init char array
    printf("Please enter a word you would like to reverse:");
    scanf("%20s", word);
    stringReverse(word, 20);
}

void stringReverse(char word[20], int i){
    // print last letter of char array and recursively call on function until end of array
    printf("%c", word[i]);
    if(i > 0) {
     stringReverse(word, i - 1);
    }
}
