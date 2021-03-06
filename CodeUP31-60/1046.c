//정수 3개를 입력받아 합과 평균을 출력해보자.
//단, -2147483648 ~+ 2147483647

#include<stdio.h>

int main_1046(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", a + b + c);
	printf("%.1f\n",(a+b+c)/(float)3);

	return 0;
}