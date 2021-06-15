#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_DAY 100

typedef struct AnniversaryDay
{
	char dayname[20];
	int year;
	int month;
	int day;
}day;

long totalday(int y, int m, int d);

int main(void)
{
	day AnniDay[MAX_DAY];

	int i = 0, total1 = 0, total2 = 0, daynumber = 0, restday = 0;
	int Dy1 = 0, Dm1 = 0, Dd1 = 0;     //������� ��¥�� ����
	int Dy2 = 0, Dm2 = 0, Dd2 = 0;     //������ �Ǵ� ������ ��¥�� ����
	int importantday[365] = { 0 };
	char wantdayName[20] = { 0 };
	char dayname[365][100] = { 0 };  //������� �̸��� �����ϴ� ���ڿ� �̴�. 

	printf("�� ���α׷��� �ڽ��� �߿��� ���̳� ������� �Է��ϰ�, \n������� ��¥�� �� ���� �� ���� ����Ͽ� ����� �ִ� ���α׷� �Դϴ�.\n");
	printf("�Է��� ������� ������ �Է��ϼ��� :");
	scanf("%d", &daynumber);

	for (i = 1; i <= daynumber; i++)  //������� �Է¹޴´�.
	{
		printf("\n������� ��¥�� ������� �̸��� �Է��ϼ��� (ex) 2021 1 1 ���� :");
		scanf("%d %d %d %s", &AnniDay[i].year, &AnniDay[i].month, &AnniDay[i].day, AnniDay[i].dayname);
	}

	for (i = 1; i <= daynumber; i++)
	{
		printf("%d %d %d %s \n", AnniDay[i].year, AnniDay[i].month, AnniDay[i].day, AnniDay[i].dayname);
	}

	printf("������ ��¥�� �Է��ϼ��� (ex) 2021 6 1 :");
	scanf("%d %d %d", &Dy2, &Dm2, &Dd2);

	while (true)
	{
		int y, m, d;
		printf("���ϴ� ������� �̸��� �Է��ϼ��� (�����Ϸ��� \"����\"�� �Է��ϼ���) :");
		scanf("%s", wantdayName);

		if (!strcmp(wantdayName, "����"))     // �� ���ڿ��� ������ ��
		{
			printf("\n�����մϴ�.");
			break;
		}
		else
		{
			bool bFindOK = false;

			for (i = 1; i <= daynumber; i++)
			{
				if (!strcmp(wantdayName, AnniDay[i].dayname))
				{
					total1 = totalday(AnniDay[i].year, AnniDay[i].month, AnniDay[i].day);
					total2 = totalday(Dy2, Dm2, Dd2);
					if (total1 > total2)
					{
						printf("%d�� ���ҽ��ϴ�.\n", total1 - total2);
					}
					if (total1 == total2)
					{
						printf("�����Դϴ�!\n");
					}
					if (total1 < total2)
					{
						printf("%d�� �������ϴ�.\n", total2 - total1);
					}
					bFindOK = true;
				}
			}
			if (bFindOK == false)
			{
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
			}
		}
	}
}

int totalday(int y, int m, int d)
{
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0, j = 0;
	for (j = 0; j < sizeof(months) / sizeof(int); j++)
	{
		sum += months[j];   // sum�� �迭�� ��Ҹ� ���ؼ� �ٽ� sum�� ����
	}  //���� ��� �Ǵ� �κ�           ->�迭�� ũ�⸦ ����Ѵ�.

	int total = 0;

	total = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{
		months[2]++;       //������ �ش� 2���� �Ϸ縦 �߰�! 28��->29��
	}
	for (j = 0; j < m - 1; j++)
	{
		total += months[j];
	}

	total += d;
	return total;
}