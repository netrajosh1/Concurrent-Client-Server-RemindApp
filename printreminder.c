#include <stdio.h>

void printreminder(char * toprint) {
  printf("\n%s", toprint); //prints out message
  printf("\nspecify reminder: "); //reprints prompt
  fflush(stdout); //flushes out buffer
}
