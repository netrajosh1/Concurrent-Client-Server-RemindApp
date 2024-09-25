#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int setsleepinterval(char *remindrequest, int **interval) {
  int counter = 0;
  char nums[strlen(remindrequest)];
  //printf("Length of string: %ld\n", strlen(remindrequest));
  for (int i  = 0; i < strlen(remindrequest); i++) {
    if (isdigit(remindrequest[i]) || (remindrequest[i] == ' ')) {
      //printf("%c", remindrequest[i]);
      nums[i] = remindrequest[i]; //only populates nums[i] with either digits or spaces
      counter++; //counter stops at first letter
    }
    else {
      break;
    }
  }
  nums[counter] = '\0';
  //printf("\nLength of non-string chars: %d\n", counter);
  //making array for only string portion of user input:
  char stringrequest[strlen(remindrequest) - counter + 1];
  stringrequest[0] = '\0';
  for (int i = 0; i < (strlen(remindrequest) - counter); i++) {
    //printf("Inside string request array!\n");
    stringrequest[i] = remindrequest[counter + i]; //populates char[] containing just the string entered by user, not the numbers
  }
  stringrequest[strlen(remindrequest) - counter] = '\0';
  //printf("String request: %s\n", stringrequest);
  //printf("Nums arr before split: %s\n", nums);
  int index = 0;
  int afterstrtok[counter];
  afterstrtok[0] = '\0';
  char *nums_split = strtok(nums, " ");
  while (nums_split != NULL) {
    afterstrtok[index++]  = atoi(nums_split);
    //printf("Nums arr after split: %s\n", nums_split);
    nums_split = strtok(NULL, " "); 
  }
  afterstrtok[index] = '\0';
  //printf("Size of num intervals: %d\n", index);
  *interval = (int *) malloc(index * sizeof(int));
  if (interval == NULL) {
    printf("Error mallocing space to sleep interval!\n");
    exit(1);
  }
  for (int i = 0; i < index; i++) {
    (*interval)[i] = afterstrtok[i]; //populates *interval with numbers entered
    //printf("Check: %d, ", (*interval)[i]);
  }

  return index; //returns the number of intervals
}
