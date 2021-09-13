#include <stdio.h>
#include <string.h>

void main()
{
	char str[80] = "This is a test string.";
	char search[20];
	int c1 = 0, c2 = 0, flag;

	printf("기본 문자열에 주어진 부분 문자열이 존재하는지 확인 :\n");
	printf("기본 문자열 : %s\n", str);

	printf("검색할 부분 문자열 입력 : ");
	fgets(search, sizeof search, stdin);

	/*while (str[c1] != '\0')
		c1++;
	c1--;

	while (search[c2] != '\0')
		c2++;
	c2--;*/
	c1 = strlen(str);
	c2 = strlen(search);
	c2--;

	for (int i = 0; i <= c1 - c2; i++)
	{
		for (int j = i; j < i + c2; j++)
		{
			flag = 1;
			if (str[j] != search[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (flag == 1)
		printf("문자열이 있습니다. \n\n");
	else
		printf("문자열이 없습니다. \n\n");
}
