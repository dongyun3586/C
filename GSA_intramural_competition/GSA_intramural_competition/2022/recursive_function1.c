// 다음 프로그램의 출력 결과는 무엇인가?
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

int main() {
  f(1);
  printf("%d\n", sum);
  return 0;
}