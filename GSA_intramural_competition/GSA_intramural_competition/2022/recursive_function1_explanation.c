#include <stdio.h>

#define END_NUM 2
sum = 0;

int f(int n) {
  printf("f(%d)", n);
  if (n > END_NUM) return;
  printf("%d ", n); sum += n;
  f(n + 1);
  printf("%d ", n); sum += n;
  f(n + 1);
  printf("%d ", n); sum += n;
}

int main() {
  f(1);
  printf("\n%d\n", sum);
  return 0;
}