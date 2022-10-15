// 다음 프로그램은 factorial을 구하는 프로그램이다. f()함수의 본문으로 옳은 것은?
#include <stdio.h>

int f(int n)
{
  if (n == 1) return 1;
  return n * f(n - 1);
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d! = %d\n", n, f(n));
  return 0;
}

