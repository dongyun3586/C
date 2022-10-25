#include <stdio.h>
#define SQUARE(x)(x*x)
void main() {
  int a, b = 3;
  a = SQUARE(b + 2);
  printf("%d\n", a);
}