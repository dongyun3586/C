#include <stdio.h>
#include <string.h>

int main()
{
	char name[25][50] = { '\0' };
	int n, i, j;

	printf("*** 문자열 Bubble Sort ***\n");
	printf("정렬할 문자열 개수는? ");
	scanf("%d", &n);
	rewind(stdin);

	for (i = 0; i < n; i++)
	{
		printf("%d번째 문자열 입력: ", i + 1);
		fgets(name[i], sizeof(name), stdin);
		//gets(name[i]);
		rewind(stdin);
	}

	/*Logic Bubble Sort*/
	char temp[25];
	for (i = 1; i <= n; i++)
		for (j = 0; j <= n - i; j++)
			if (strcmp(name[j], name[j + 1]) > 0)
			{
				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);
			}

	printf("\n*** 문자열 정렬 후 ***\n");
	for (i = 0; i <= n; i++)
		printf("%s", name[i]);

	return 0;
}