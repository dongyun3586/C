#include <stdio.h>
#include <stdlib.h>

void main(void) {
  char str[3][4] = { "abc", "def", "ghi" };
  char** p;
  char* mid[3];
  for (int i = 0; i < 3; i++)
    mid[i] = str[i];
  p = mid;
  printf("%s\n", *(p + 1));
  printf("%c\n", **(p + 1));
  printf("%c\n", *(*(p + 1) + 1));
}