#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void)
{
	srand(time(NULL));
	int a, b, c, d, e = 0;
	int ua, ub, uc, ud, ue = 0;
	int repeat;
	int count = 0;
	printf("****���ǻ���:����� ����� ,�� �������ּ���****\n");
	printf("1�ܰ�. ���׽��� �̺� \n���ϴ� ������ ������ �Է�\n");
	scanf("%d", &repeat);
	for (int i = 0; i < repeat; i++)
	{
		int random = rand() % 4 + 1;
		if (random == 1)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			printf("����� %d,%d�� �������� �̺��� ���� ����� �Է��Ͻÿ�\n", a, b);
			scanf("%d", &ua);
			if (ua == a)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else
				printf("��! ������ %d�Դϴ�\n", a);
		}
		if (random == 2)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			c = rand() % 10 + 1;
			printf("����� %d, %d, %d�� �������� �̺��� ���� ����� ���Ͻÿ�\n", a, b, c);
			scanf("%d, %d", &ua, &ub);
			if (ua == 2 * a && ub == b)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else
				printf("��! ������ %d, %d�Դϴ�\n", 2 * a, b);
		}
		if (random == 3)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			c = rand() % 10 + 1;
			d = rand() % 10 + 1;
			printf("����� %d, %d, %d, %d�� �������� �̺��� ���� ����� ���Ͻÿ�\n", a, b, c, d);
			scanf("%d,%d,%d", &ua, &ub, &uc);
			if (ua == 3 * a && ub == 2 * b && uc == c)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else
				printf("��! ������ %d, %d, %d�Դϴ�\n", 3 * a, 2 * b, c);
		}
		if (random == 4)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			c = rand() % 10 + 1;
			d = rand() % 10 + 1;
			e = rand() % 10 + 1;
			printf("����� %d, %d, %d, %d, %d�� �������� �̺��� ���� ����� ���Ͻÿ�\n", a, b, c, d, e);
			scanf("%d, %d, %d, %d", &ua, &ub, &uc, &ud);
			if (ua == 4 * a && ub == 3 * b && uc == 2 * c && ud == d)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else
				printf("��! ������ %d, %d, %d, %d�Դϴ�\n", 4 * a, 3 * b, 2 * c, d);
		}
	}
	printf("1�ܰ� ��������: %d\n", count);
	printf("2�ܰ�. ���׽��� ����\n ���ϴ� ������ ������ �Է�\n");
	scanf("%d", &repeat);
	count = 0;
	for (int i = 0; i < repeat; i++)
	{
		int random = rand() % 4 + 1;
		if (random == 1)
		{
			a = rand() % 5 + 1;
			printf("%d�� ������ ���� ����� �Է��Ͻÿ�. ���� ����� 0���� �Ѵ�\n", a);
			scanf("%d", &ua);
			if (ua == a)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else printf("��!������ %d�Դϴ�.\n", a);
		}
		if (random == 2)
		{
			a = 2 * (rand() % 5) + 2;
			b = 1 * (rand() % 5) + 1;
			printf("����� %d, %d�� �������� ������ ���� ����� �Է��Ͻÿ�. ���� ����� 0���� �Ѵ�\n", a, b);
			scanf("%d, %d", &ua, &ub);
			if (ua == a / 2 && ub == b)
			{
				printf("�����Դϴ�");
				count++;
			}
			else printf("��! ������ %d, %d�Դϴ�.\n", a / 2, b);
		}
		if (random == 3)
		{
			a = 3 * (rand() % 5) + 3;
			b = 2 * (rand() % 5) + 2;
			c = rand() % 5 + 1;
			printf("����� %d, %d, %d�� �������� ������ ���� ����� �Է��Ͻÿ�. ���� ����� 0���� �Ѵ�\n", a, b, c);
			scanf("%d, %d, %d", &ua, &ub, &uc);
			if (ua == a / 3 && ub == b / 2 && uc == c)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else printf("��! ������ %d, %d, %d�Դϴ�. \n", a / 3, b / 2, c);
		}
		if (random == 4)
		{
			a = 4 * (rand() % 3 + 1);
			b = 3 * (rand() % 3 + 1);
			c = 2 * (rand() % 3 + 1);
			d = 5 % rand() + 1;
			printf("����� %d, %d, %d, %d�� �������� ������ ���� ����� �Է��Ͻÿ�. ���� ����� 0���� �Ѵ�\n", a, b, d, c);
			scanf("%d, %d, %d, %d", &ua, &ub, &uc, &ud);
			if (ua == a / 4 && ub == b / 3 && uc == c / 2 && ud == d)
			{
				printf("�����Դϴ�\n");
				count++;
			}
			else printf("��! ������ %d, %d, %d, %d�Դϴ�. \n", a / 4, b / 3, c / 2, d);
		}
	}
	printf("2�ܰ� ���� ����: %d", count);
	return 0;
}
v