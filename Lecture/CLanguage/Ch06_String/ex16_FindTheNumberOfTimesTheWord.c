#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
	int length, freq = 0, flag;
	int strLen, searchLen;
	char str[100] = "The stering where the word the present more then onces";
	char search[100] = "";

	printf("���ڿ����� �ܾ� �󵵼� ���ϱ�\n");
	printf("���ڿ� : %s\n", str);
	printf("ã�� �ܾ� �Է� : ");
	fgets(search, sizeof(str), stdin);

	strLen = strlen(str);
	searchLen = strlen(search) - 1;

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

	printf("\'%s\' �󵵼� : %d\n\n", search, freq);
}