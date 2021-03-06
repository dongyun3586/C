//실수 1개를 입력받아 그대로 출력해보자.
//(단, 입력되는 실수의 범위는 + -1.7 * 10 - 308 ~+ -1.7 * 10308 이다.)

#include<stdio.h>

int main_1029(void) {
	double d;
	scanf("%lf", &d); // double(long float) 형식으로 입력
	printf("%.11lf", d);

	return 0;
}