#include<stdio.h>

int main_ex02_if() {
	int n;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	// if문 사용
	if (n < 0)
		n = -n;

	printf("절대값은 %d입니다. \n", n);
	
	return 0;
}