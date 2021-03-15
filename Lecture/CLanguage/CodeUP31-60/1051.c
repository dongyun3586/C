//두 정수(a, b)를 입력받아
//b가 a보다 크거나 같으면 1을, 그렇지 않으면 0을 출력하는 프로그램을 작성해보자.

#include<stdio.h>

int main_1051(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (b >= a)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);

	return 0;
}