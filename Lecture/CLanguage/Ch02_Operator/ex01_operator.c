#include<stdio.h>

int main_ex01_operator(void) {
	int a = 9, b = 2;
	printf("%d + %d = %d \n", a, b, a + b);
	printf("%d - %d = %d \n", a, b, a - b);
	printf("%d * %d = %d \n", a, b, a * b);
	printf("%d / %d = %d \n", a, b, a / b);
	printf("%d / %d�� ������ = %d \n", a, b, a % b);
	return 0;
}