//정수 2개를 입력받아 합을 출력하는 프로그램을 작성해보자.
//(단, 입력되는 정수는 - 1,073,741,824 ~1,073,741,824 이다.)

//INT_MAX:   2,147,483,647
//INT_MIN : -2,147,483,648

#include<stdio.h>

int main_1038(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	printf("%ld", a + b);

	return 0;
}