#include<stdio.h>

int main_ex05_classification() {

	char ch;

	scanf("%c", &ch);

	if(ch>='A' && ch<='Z')
		printf("대문자 입니다.\n");
	else if(ch>='a' && ch<='z')
		printf("소문자 입니다.\n");
	else if(ch >= '0' && ch <= '9')
		printf("숫자 입니다.\n");
	else
		printf("영문자나 숫자가 아닙니다.\n");

	return 0;
}