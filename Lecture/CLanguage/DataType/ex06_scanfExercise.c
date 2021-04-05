#include <stdio.h>

int main_ex06_scanfExercise()
{
	int a, b, temp;

	printf("정수 두 개를 입력하시오: ");
	scanf_s("%d %d", &a, &b);

	printf("a=%d, b=%d\n", a, b);
	// 두 변수의 값 교환하여 저장
	temp = a;
	a = b;
	b = temp;
	printf("a=%d, b=%d\n", a, b);
}