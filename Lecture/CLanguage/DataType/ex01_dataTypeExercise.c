#include<stdio.h>

int main(void) {
	// 온도 저장
	signed char temperature;
	temperature = -2;
	temperature = 200;
	printf("%d\n", temperature);

	// 나이 저장
	unsigned char age;
	age = 52;
	printf("%d\n", age);

	// 금액 저장
	int money;
	money = 70000000;
	printf("%d\n", money);

	// 큰 정수 저장
	int time_seconds;
	time_seconds = 2453100624;
	printf("%d\n", time_seconds);

	return 0;
}