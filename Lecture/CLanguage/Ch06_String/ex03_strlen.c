#include <stdio.h>

int myStrlen(const char* str);

void main()
{
	char str[] = "Hello world";
	//printf("���ڿ��� �Է� : ");
	//gets(str);
	//fgets(str, 100, stdin);
	printf("%s�� ���ڿ� ���� : %d\n", str, myStrlen(str));
}

int myStrlen(const char* str)
{
#pragma region for�� ���
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
#pragma endregion

#pragma region while�� ���
	/*int count = 0;
	while (*str++ != '\0')
		count++;
	return count;*/
#pragma endregion

#pragma region ������ ���� ���
	/*char* p = str;
	while (*p++);
	return p - str - 1;*/
#pragma endregion
}
