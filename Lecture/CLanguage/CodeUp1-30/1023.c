//실수 1개를 입력받아 정수 부분과 실수 부분으로 나누어 출력한다.

#include<stdio.h>

int main_1023(void) {
	int a, b;
	scanf("%d.%d", &a, &b);
	printf("%d\n%d", a, b);

	return 0;
}