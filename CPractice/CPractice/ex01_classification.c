#include<stdio.h>

int main() {
	// 변수 선언
	char ch;

	// 입력 받기
	printf("문자 하나를 입력하시오. ");
	scanf("%c", &ch);

	// 처리 및 출력
	if (ch >= 'A' && ch <= 'Z')
		printf("%c는 대문자 입니다.\n", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c는 소문자 입니다.\n", ch);
	else if (ch >= '0' && ch <= '9')
		printf("%c는 숫자 입니다.\n", ch);
	else
		printf("%c는 영문자나 숫자가 아닙니다.\n", ch);


	return 0;
}