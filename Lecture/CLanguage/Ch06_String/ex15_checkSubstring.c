#include <stdio.h>
#include <string.h>

void main()
{
	char str[80] = "This is a test string.";
	char search[20];
	int c1 = 0, c2 = 0, flag;

	printf("�⺻ ���ڿ��� �־��� �κ� ���ڿ��� �����ϴ��� Ȯ�� :\n");
	printf("�⺻ ���ڿ� : %s\n", str);

	printf("�˻��� �κ� ���ڿ� �Է� : ");
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
		printf("���ڿ��� �ֽ��ϴ�. \n\n");
	else
		printf("���ڿ��� �����ϴ�. \n\n");
}
