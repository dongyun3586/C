#include<stdio.h>

int main_ex05_classification() {

	char ch;
	scanf("%c", &ch);

	if (ch >= '0' && ch<='9')
		printf("%c는 숫자입니다.", ch);

	return 0;
}