// ���� ���α׷��� factorial�� ���ϴ� ���α׷��̴�. f()�Լ��� �������� ���� ����?
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

