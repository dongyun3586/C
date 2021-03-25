// (연습문제5) 문자분류 (ex05_classification.c)

#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("문자를 하나 입력하시오: ");
	scanf("%c", &ch);

	if (ch >= '0')
		printf("%d는 A보다 크다\n", ch);

	return 0;
}