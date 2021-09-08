#include <stdio.h>
#include <string.h>

int ascendCompare(char a, char b);
int descendCompare(char a, char b);
void sortCharacterInASCII(char* str, int(*fp)(char, char));

void main()
{
	char strArr[100], ch;

	printf("문자열 입력 : ");
	gets(strArr);

	printf("정렬 방법 선택(오름차순=a, 내림차순=d) : ");
	char choice = getchar();
	if (choice == 'a')
		sortCharacterInASCII(strArr, ascendCompare);
	else if (choice == 'd')
		sortCharacterInASCII(strArr, descendCompare);
	else
		printf("잘못된 입력입니다.\n");

	printf("정렬된 문자열 %s\n", strArr);
}

void sortCharacterInASCII(char* str, int(*fp)(char, char)) {
	int length = strlen(str);
	char temp;
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < length - i; j++) {
			if (fp(str[j], str[j + 1]) == 1)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

int ascendCompare(char a, char b) {
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}

int descendCompare(char a, char b) {
	if (a < b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}