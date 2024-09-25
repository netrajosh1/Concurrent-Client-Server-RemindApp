#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
//helper function that ensures numbers entered as input are valid (including multidigit numbers)
bool numchecker(char * numstr) {
  int i = 0;
  if (numstr[i] == '-') { //checks if negative number
    i = 1;
    printf("negative numbers not allowed!\n");
    exit(1);
  }
  while (numstr[i] != 0) {
    if (!isdigit(numstr[i])) { //if number isn't a digit, false returned
      return false;
    }
    i++;
  }
  return true;
}
