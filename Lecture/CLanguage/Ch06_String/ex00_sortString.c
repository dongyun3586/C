#include <stdio.h>
#include <string.h>

void main()
{
	char str[100], ch;
	int i, j, l;

	printf("문자열 입력 : ");
	fgets(str, sizeof str, stdin);
	l = strlen(str);

	/* sorting process */
	for (i = 1; i < l; i++)
		for (j = 0; j < l - i; j++)
			if (str[j] > str[j + 1])
			{
				ch = str[j];
				str[j] = str[j + 1];
				str[j + 1] = ch;
			}

	printf("정렬된 문자열 %s\n", str);
}