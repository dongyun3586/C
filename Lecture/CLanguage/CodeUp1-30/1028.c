//정수 1개를 입력받아 그대로 출력해보자.
//(단, 입력되는 정수의 범위는 0 ~4,294,967,295 이다.)

#include<stdio.h>

int main_1028(void) {
	unsigned int n;
	scanf("%u", &n);
	printf("%u", n);

	return 0;
}