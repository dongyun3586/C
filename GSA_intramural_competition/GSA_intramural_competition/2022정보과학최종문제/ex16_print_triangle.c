#include <stdio.h>
void main(void) {
  int i = 0, j = 0;
  int start = 0, end = 10;
  for (i = 0; i < 9; i++) {
    if (i < 10 / 2) {
      start = i, end--;
    }
    else {
      start--, end++;
    }

    for (j = start; j > 0; j--)
      printf(" ");
    for (j = start; j < end; j++)
      printf("*");
    printf("\n");
  }
}