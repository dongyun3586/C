#include <stdio.h>

int myStrlen(const char* str);

void main()
{
	char str[] = "Hello world";
	//printf("문자열을 입력 : ");
	//gets(str);
	//fgets(str, 100, stdin);
	printf("%s의 문자열 길이 : %d\n", str, myStrlen(str));
}

int myStrlen(const char* str)
{
#pragma region for문 사용
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
#pragma endregion

#pragma region while문 사용
	/*int count = 0;
	while (*str++ != '\0')
		count++;
	return count;*/
#pragma endregion

#pragma region 포인터 변수 사용
	/*char* p = str;
	while (*p++);
	return p - str - 1;*/
#pragma endregion
}
