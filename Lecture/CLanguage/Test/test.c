#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int n = 0, jungdap = 0, count = 0;

	printf("*** 1�г� 1�� 2�� ������ ***\n1~100������ ���ڸ� �����ϴ� �����Դϴ�.\n\n");
	srand(time(NULL));
	jungdap = rand() % 100 + 1;

	printf("���� : %d\n\n", jungdap);

	while (1)
	{
		printf("������?: ");
		scanf("%d", &n);

		if (n != jungdap)
		{
			printf("Ʋ�Ƚ��ϴ�. ");
			if (n > jungdap)
			{
				printf("%d���� �۽��ϴ�. \n", n);
			}
			else if (n < jungdap)
			{
				printf("%d���� Ů�ϴ�. \n", n);
			}
			count++;
		}
		if (n == jungdap)
		{
			printf("�����Դϴ�. \n\n");
			count++;
			break;
		}
	}
	printf("%d�� ���� �������ϴ�. ", count);

	return 0;
}
