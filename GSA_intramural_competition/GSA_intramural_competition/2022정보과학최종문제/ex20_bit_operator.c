#include<stdio.h>
void main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int sum, carry;
  while (b != 0) {
    sum = a ^ b;
    carry = (a & b) << 1;
    a = sum;
    b = carry;
  }
  printf("%d", a);
}