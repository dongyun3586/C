#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("문자 하나를 입력하시오: ");
	scanf("%c", &ch);

	if (ch >= '0' && ch<='9')
		printf("%c는 대문자 입니다. \n", ch);

	return 0;
}