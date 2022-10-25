#include <stdio.h>
void main(void) {
  int array[] = { 0,0,1,1,1 };
  int* p = array;

  while (!*p++);
  printf("%ld\n", p - array);
}