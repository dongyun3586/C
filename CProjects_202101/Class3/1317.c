#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

int yut(int k, int s);
int soonsu(int s);
int gagi(int move);
int k;
int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
int x, y, p, q;
int gagi2(int move);
int printer(int Arr[6][6]);

int main()
{
	int Arr[6][6] = { 0 };
	int k, s, a, b, c;
	srand(time(NULL));
	printf("�����̸� �����ϰڽ��ϱ�?\n");
	printf("������ �����ϰ� �����ø� 1���� �����ּ��� : ");
	scanf("%d", &a);
	if (a == 1)
	{
		printf("\n��ǻ�Ϳ� �Բ��ϴ� ������ ���ӿ� ���� ���� ȯ���մϴ�.\n");
		printf("���� ������ ���ϵ��� �ϰڽ��ϴ�. ���� ���ϱ� ��ư�� 2�� �Դϴ�. : ");
		scanf("%d", &b);
		s = rand() % 2 + 1;
		k = rand() % 16 + 1;
		if (b == 2)
		{
			soonsu(s);
		}
		printf("\n�׷� ���ݺ��� ���������� �����̸� �����ϵ��� �ϰڽ��ϴ�.\n");
		while (1)
		{
			if (s == 1)
			{
				printf("\n ������ ���� ���� ���� �ּ���. ���� ������ ��ư�� 7�� �Դϴ�.");
				scanf("%d", &c);
				if (c == 7)
				{
					yut(k, s);
					s = 2;
					k = rand() % 16 + 1;

				}
			}

			if (s == 2)
			{
				printf("\n ��ǻ�� ���� �����ϵ��� �ϰڽ��ϴ�. ");
				{
					yut(k, s);
					s = 1;
					k = rand() % 16 + 1;
				}

			}
		}
	}
}

int soonsu(int s)
{
	if (s == 1)
	{
		printf("\n ���� ���� ����\n");
	}

	if (s == 2)
	{
		printf("\n ��ǻ�� ���� ����\n");
	}

}

int yut(int k, int s)
{
	if (s == 1)
	{
		int move;
		if (k == 1 || k == 2 || k == 3 || k == 4)
		{
			printf("\n���� �� : ��\n");
			move = 1;
			return gagi(move);
		}

		if (k == 5 || k == 6 || k == 7 || k == 8 || k == 9 || k == 10)
		{
			printf("\n���� �� : ��\n");
			move = 2;
			return gagi(move);
		}

		if (k == 11 || k == 12 || k == 13 || k == 14)
		{
			printf("\n���� �� : ��\n");
			move = 3;
			return gagi(move);
		}

		if (k == 15)
		{
			printf("\n���� �� : ��\n");
			move = 4;
			return gagi(move);
		}

		if (k == 16)
		{
			printf("\n���� �� : ��\n");
			move = 5;
			return gagi(move);
		}
	}

	if (s == 2)
	{
		int move;
		if (k == 1 || k == 2 || k == 3 || k == 4)
		{
			printf("\n���� �� : ��\n");
			move = 1;
			return gagi2(move);
		}

		if (k == 5 || k == 6 || k == 7 || k == 8 || k == 9 || k == 10)
		{
			printf("\n���� �� : ��\n");
			move = 2;
			return gagi2(move);
		}

		if (k == 11 || k == 12 || k == 13 || k == 14)
		{
			printf("\n���� �� : ��\n");
			move = 3;
			return gagi2(move);
		}

		if (k == 15)
		{
			printf("\n���� �� : ��\n");
			move = 4;
			return gagi2(move);
		}

		if (k == 16)
		{
			printf("\n���� �� : ��\n");
			move = 5;
			return gagi2(move);
		}
	}
}

int gagi(int move)
{
	int Arr[6][6];
	int Flag = 0;
	if (sum1 == 0 && (sum2 + move) <= 5)
	{
		sum2 += move;
	}

	else if (sum1 == 0 && sum2 + move > 5)
	{
		sum3 = sum2 + move - 5;
		sum2 = 5;
		sum1 = sum3;
	}

	else if (sum2 == 5 && sum1 + move <= 5)
	{
		sum1 = sum1 + move;
	}

	else if (sum2 == 5 && sum1 + move > 5)
	{
		sum3 = 10 - (sum1 + move);
		sum2 = sum3;
		sum1 = 5;
	}

	else if (sum1 == 5 && sum2 - move > 0)
	{
		sum1 = 5;
		sum2 -= move;
	}

	else if (sum1 == 5 && sum2 - move >= 0)
	{
		sum1 = 5;
		sum2 -= move;
	}

	else if (sum1 == 5 && sum2 - move < 0)
	{
		sum2 = 0;
		sum1 = 5 + (sum2 - move);
	}

	else if (sum2 == 0 && sum1 > 0)
	{
		sum2 = 0;
		sum1 = sum1 - move;
		if (sum1 <= 0)
		{
			printf("����� �¸��߽��ϴ�.");
		}
	}

	x = sum1;
	y = sum2;
	return printer(Arr[6][6], x, y, p, q);
	return sum1, sum2;
}

int gagi2(int move)
{
	int Arr[6][6];
	int Flag = 0;

	if (sum4 == 0 && (sum5 + move) <= 5)
	{
		sum5 += move;
	}

	else if (sum4 == 0 && sum5 + move > 5)
	{
		sum6 = sum5 + move - 5;
		sum5 = 5;
		sum4 = sum6;
	}

	else if (sum5 == 5 && sum4 + move <= 5)
	{
		sum4 = sum4 + move;
	}

	else if (sum5 == 5 && sum4 + move > 5)
	{
		sum6 = 10 - (sum4 + move);
		sum5 = sum6;
		sum4 = 5;
	}

	else if (sum4 == 5 && sum5 - move >= 0)
	{
		sum4 = 5;
		sum5 -= move;
	}

	else if (sum4 == 5 && sum5 - move < 0)
	{
		sum5 = 0;
		sum4 = 5 + (sum5 - move);
	}

	else if (sum5 == 0 && sum4 >= 0)
	{
		sum5 = 0;
		sum4 = sum4 - move;
		if (sum4 <= 0)
		{
			printf("�ƽ���, ��ǻ�Ͱ� �¸��߽��ϴ�.\n\n");
		}
	}
	p = sum4;
	q = sum5;
	return printer(Arr, x, y, p, q);
	return sum4, sum5;
}

int printer(int Arr[6][6])
{

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Arr[i][j] = 64;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		Arr[0][i] = 42;
		Arr[5][i] = 42;
		Arr[i][0] = 42;
		Arr[i][5] = 42;
	}

	Arr[sum1][sum2] = 97;
	Arr[sum4][sum5] = 98;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%c", Arr[i][j]);
		}
		printf("\n");
	}
}