// (연습문제5) 문자분류 (ex05_classification.c)

#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("문자 하나 입력: ");
	scanf("%c", &ch);
	
	if (ch >= '0' && ch <= '9')
		printf("%c는 숫자입니다. \n", ch);

}