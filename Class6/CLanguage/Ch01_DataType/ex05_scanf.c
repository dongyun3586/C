#include <stdio.h>
int main()
{
	int x, y, sum;

	printf("정수 두 개를 입력하시오: ");
	scanf("%d %d", &x, &y);

	sum = x + y;
	printf("두 수의 합: %d", sum);
}