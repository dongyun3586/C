#include <stdio.h>
void main(void) {
  int i = (1, 2) * (4, 5, 7);
  return printf("%d", i);
}