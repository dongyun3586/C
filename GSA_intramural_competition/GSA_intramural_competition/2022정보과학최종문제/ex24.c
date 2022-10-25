#include <stdio.h>
#define END_NUM 2
sum = 0;

int f(int n) {
  if (n > END_NUM) return;
  sum += n;
  f(n + 1);
  sum += n;
  f(n + 1);
  sum += n;
}

void main() {
  f(1);
  printf("%d\n", sum);
}