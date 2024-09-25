#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> //used for fork()
#include <sys/wait.h> //used for fork()

bool numchecker(char *);
void printreminder(char *);
int setsleepinterval(char *, int **);

int main(int argc, char **argv) {
  char remindrequest[50];
  int num = 0;
  if (argc < 1) { //if  no arguments entered, exit
    printf("Error!\n");
    exit(1);
  }
  else if (argc > 1) {
    //printf("Going into command line args!\n");
    //printf("Number of arguments: %d\n", argc);
    char * first = *(argv + 1);
    //printf("First argument: %s\n", first);
    if (!numchecker(first)) {
      printf("First argument entered is not a number! Error!\n"); //checking if 1st argument entered is valid
      exit(1);
    }
    else {
      bool is_digit = true;
      int index = 1;
      int counter = 1;
      while (numchecker(*(argv + counter))) {
        counter++;
      }
      int string_len = argc - counter;
      //printf("String is: %d\n", string_len);
      //printf("Counter is at (index starting at 0): %d\n", counter);
      char *reminder = (char *)malloc(string_len * sizeof(char));
      if (reminder == NULL) {
        printf("Malloc error for making space for reminder string!\n");
        exit(1);
      }
      reminder[0] = '\0'; //ensuring reminder does not have junk values
      int length = 0;
      for (int i = counter; i < argc; i++) {
        strcat(reminder, *(argv + i));
        if (i != argc - 1) {
          strcat(reminder, " ");
        }
      }
      //printf("Reminder: %s\n", reminder);
      //printf("Got here\n");
      int str_sleepint = 0;
      int sleepcount = 0;
      int iteration = 0;
      while ((numchecker(*(argv + index))) && (index < counter)) {
        //printf("Iteration number %d\n", iteration++);
        str_sleepint = atoi(*(argv + index)); //atoi converts string to int
        sleep(str_sleepint);
        printreminder(reminder);
        //printf("\n%s\n", reminder);
        index++; //everything from 0 to index are numbers, not string characters
      }

    }
  }
  else {
    //printf("Not in command-line args! Checking local args now!\n");
    while (1) {
      pid_t k;
      int status;
      char remindrequest[50];
      bool valid = false;
      while (!valid) { //loops until valid input found
        remindrequest[0] = '\0';
        valid = true;
        printf("specify reminder: ");
        char c;
        int i = 0;
        int len = 0;
        while (((c = getchar()) != '\n') && (c != EOF)) {
          if (len > 49) {
            printf("Input too large! Try again!\n");
            while (c = getchar()) { //reading through userinput again
              if ((c == '\n') || (c == EOF)) { //ensuring input is valid
                break;
              }
            }
            valid = false;
            break;
          }
          remindrequest[i++] = c;
          len++;
        }
        if (valid) {
          remindrequest[i] = '\0';
        }
      }
    //printf("Found valid input!\n");
      k = fork();
      if (k == 0) {
      //Inside child process
        int counter = 0;
        char nums[strlen(remindrequest)];
      //printf("Length of string: %ld\n", strlen(remindrequest));
        for (int i  = 0; i < sizeof(remindrequest); i++) {
          if (isdigit(remindrequest[i]) || (remindrequest[i] == ' ')) {
          //printf("%c", remindrequest[i]);
            nums[i] = remindrequest[i];
            counter++;
          }
          else {
            break;
          }
      }
      nums[counter] = '\0';
      //making array for only string portion of user input:
      char stringrequest[strlen(remindrequest) - counter + 1];
      stringrequest[0] = '\0';
      for (int i = 0; i < (strlen(remindrequest) - counter); i++) {
        //printf("Inside string request array!\n");
        stringrequest[i] = remindrequest[counter + i];
      }
      stringrequest[strlen(remindrequest) - counter] = '\0';
      //printf("String request: %s\n", stringrequest);
      int *sleepinterval;
      int num_intervals = setsleepinterval(remindrequest, &sleepinterval);
      //printf("Number of sleep intervals requested by the user: %d\n", num_sleepintervals);
      for (int i = 0; i < num_intervals; i++) {
        //printf("%d\n", sleepinterval[i]);
        sleep(sleepinterval[i]);
        printreminder(stringrequest);
      }
      free(sleepinterval);
      exit(0);

    } //with command-line arguments: process them all, and then finish
    //without command-line arguments: concurrent reminders (30 long + 1 2 3 quick)
    else {
       //no code required here, infinite loop runs if using user input and not command-line arguments
    }
  }
  }

}

