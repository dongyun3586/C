#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
	int length, freq = 0, flag;
	int strLen, searchLen;
	char str[100] = "The string where the word the present more then once.";
	char search[100] = "";

	printf("문자열에서 단어 빈도수 구하기\n");
	printf("문자열 : %s\n", str);
	printf("찾을 단어 입력 : ");
	gets(search);

	strLen = strlen(str);
	searchLen = strlen(search);

	for (int i = 0; i <= strLen - searchLen; i++) {
		for (int j = i; j < i + searchLen; j++) {
			flag = 1;
			if (tolower(str[j]) != tolower(search[j - i])) {
				flag = 0;
				break;
			}
		}
		if (flag == 1 && (str[i + searchLen] == ' ' || str[i + searchLen] == '\0'))
			freq++;
	}

	printf("\'%s\' 빈도수 : %d\n", search, freq);
}