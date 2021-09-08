#include <stdio.h>
#include <string.h>

void inputString(char strArr[][50], int n);
void bubbleSortString(char(*str)[50], int n);
void printString(char(*str)[50], int n);

int main()
{
	char name[25][50] = { '\0' };
	int n;

	printf("*** 문자열 Bubble Sort ***\n");
	printf("정렬할 문자열 개수는? ");
	scanf("%d", &n);
	rewind(stdin);

	// 문자열을 n개 입력 받음
	inputString(name, n);

	printf("\n*** 문자열 정렬 전 ***\n");
	printString(name, n);

	printf("\n*** 문자열 정렬 처리 ***\n");
	bubbleSortString(name, n);

	printf("\n*** 문자열 정렬 후 ***\n");
	printString(name, n);

	return 0;
}

void inputString(char strArr[][50], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 문자열 입력: ", i + 1);
		gets(strArr[i]);
	}
}

void bubbleSortString(char(*str)[50], int n) {
	char temp[50];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
		}
		printString(str, n);
	}
}

void printString(char strArr[][50], int n) {
	for (int i = 0; i <= n; i++)
		printf("%s ", strArr[i]);
	printf("\n");
}