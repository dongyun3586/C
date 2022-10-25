#include<stdio.h>

void main() {
  int a, i, p = 1, b[32];
  printf("¼ö ÀÔ·Â : ");
  scanf("%d", &a);
  for (i = 0; a > 0; i++) {
    if (a & p)
      b[i] = 1;
    else b[i] = 0;
    a = a >> 1;
  }
  while (i > 0)
    printf("%d", b[--i]);
  printf("\n");
}