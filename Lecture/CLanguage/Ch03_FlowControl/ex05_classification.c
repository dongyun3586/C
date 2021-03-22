#include<stdio.h>

int main_ex05_classification() {
	char ch;

	printf("문자 하나를 입력하시오: ");
	scanf("%c", &ch);

	if (ch >= 65 && ch <= 90)
		printf("%c는 대문자입니다. \n", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c는 소문자입니다. \n", ch);
	else if (ch >= '0' && ch <= '9')
		printf("%c는 숫자입니다. \n", ch);
	else
		printf("%c는 알파벳이나 숫자가 아닙니다. \n", ch);

	return 0;
}