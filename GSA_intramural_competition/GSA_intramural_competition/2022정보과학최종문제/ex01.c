#include <stdio.h>
int func1(int);
int func2(int);

int main()
{
  int a = 0, b = 1, count;
  for (count = 1; count <= 5; count++)
  {
    b += func1(a + 1) + 1;
    printf("%d ", b);
  }
}

int func1(int a)
{
  int b;
  int func2(int b);
  b = func2(a + 1) + 1;
  return b;
}
int func2(int a)
{
  return a + 1;
}