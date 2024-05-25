/*  --------------------------------
-- Assignment Description --
Write a program that collects university class schedules from the user and writes them to a file named "schedule.txt". 
Each entry in the schedule should include the class name, days of the week the class meets, the start time, the end time, and the number of credits for the class. 
------------------------------------- />

#include <stdio.h>
#include <string.h>


int main(){
    FILE *cfPtr = NULL;         //file pointer

    char className[40];    // class name
    char daysOfWeek[7];    // days of the week
    char startTime[8];      // store start time as char array
    char endTime[8];        // store end time as char array
    int numOfCredits;       // number of credits for class


    //open file if exists, exit program if not
    if ((cfPtr = fopen("schedule.txt", "w")) == NULL) {
        puts("File could not be opened");
    }   else {
        puts("Enter EOF to end input.");
        printf("%s", "Example: Ctrl + D");
        printf("\nPress enter to begin");
        
        // print each class to file as new line
        while (fgets(className, sizeof(className), stdin) != NULL) {
            
            // If user enters EOF, break out of the loop
            if (strcmp(className, "EOF") == 0) {
                break;
            }

            // get the classname
            printf("\nEnter the class name.");
            fgets(className, sizeof(className), stdin);
            className[strlen(className) - 1] = '\0';  // Remove newline character            

            // get the days of the week
            printf("\nEnter the letters for days  of the week.");
            fgets(daysOfWeek, sizeof(daysOfWeek), stdin);
            daysOfWeek[strlen(daysOfWeek) - 1] = '\0';  // Remove newline character


             // get the start time
            printf("Enter the start time (format: HH:MMAM): ");
            fgets(startTime, sizeof(startTime), stdin);
            startTime[strlen(startTime) - 1] = '\0';  // Remove newline character

             // get the end time
            printf("Enter the end time (format: HH:MMAM): ");
            scanf("%s", endTime); // Read until whitespace
            endTime[strlen(endTime) - 1] = '\0';  // Remove newline character

            // get the number of credits
            printf("Enter the number of credits: ");
            scanf("%d", &numOfCredits);
            getchar();  // Consume newline character from input buffer

            // Write to file
            fprintf(cfPtr, "%s %s %8s %8s %d\n", className, daysOfWeek, startTime, endTime, numOfCredits);
            
            // prompt for next class or to end
            puts("Type enter to add a class");
            puts("Enter EOF to end input.");

        }
        fclose(cfPtr); //close the file
    }
}
