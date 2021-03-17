#include<stdio.h>

int main_ex06_scanfExercise() {
	int a, b;
	printf("정수 두 개를 입력하시오: ");
	scanf("%d %d", &a, &b);
	printf("a=%d, b=%d\n", a, b);

	// a와 b값을 서로 교환
	printf("a=%d, b=%d\n", a, b);
	return 0;
}
