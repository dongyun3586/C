#include <stdio.h>
#include <string.h>

void main()
{
	char str[80] = "This is a test string.";
	char search[20];
	int c1 = 0, c2 = 0, flag;

	printf("���ڿ��� �־��� �κ� ���ڿ��� �����ϴ��� Ȯ�� :\n");
	printf("���ڿ� : %s\n", str);

	printf("�˻��� �κ� ���ڿ� �Է� : ");
	gets(search);

	c1 = strlen(str);
	c2 = strlen(search);

	for (int i = 0; i <= c1 - c2; i++)
	{
		flag = 1;
		for (int j = i; j < i + c2; j++)
		{
			if (str[j] != search[j - i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) break;
	}

	if (flag == 1)
		printf("%s ���ڿ��� ã�ҽ��ϴ�. \n", search);
	else
		printf("%s ���ڿ��� �����ϴ�. \n", search);
}