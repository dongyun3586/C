#include<stdio.h>

int main() {
	char str[12] = "";

	printf("문자열 입력 : ");
	gets(str);					// '\n'은 제거되고, 문자열의 마지막에 NULL문자 '\0'이 추가된다.
	printf("%s\n", str);
	puts(str);					// 출력 할 때 NULL 문자('\0')를 '\n'으로 변경한다.

	printf("문자열 입력 : ");
	fgets(str, 12, stdin);		// 개행 문자까지 포함된다.
	puts(str);
	printf("%s\n", str);

	return 0;
}