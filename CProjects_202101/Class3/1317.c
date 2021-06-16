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
	printf("윷놀이를 시작하겠습니까?\n");
	printf("게임을 진행하고 싶으시면 1번을 눌러주세요 : ");
	scanf("%d", &a);
	if (a == 1)
	{
		printf("\n컴퓨터와 함께하는 윷놀이 게임에 오신 것을 환영합니다.\n");
		printf("먼저 순서를 정하도록 하겠습니다. 순서 정하기 버튼은 2번 입니다. : ");
		scanf("%d", &b);
		s = rand() % 2 + 1;
		k = rand() % 16 + 1;
		if (b == 2)
		{
			soonsu(s);
		}
		printf("\n그럼 지금부터 본격적으로 윷놀이를 시작하도록 하겠습니다.\n");
		while (1)
		{
			if (s == 1)
			{
				printf("\n 유저님 먼저 윷을 던져 주세요. 윷을 던지는 버튼은 7번 입니다.");
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
				printf("\n 컴퓨터 먼저 진행하도록 하겠습니다. ");
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
		printf("\n 유저 먼저 시작\n");
	}

	if (s == 2)
	{
		printf("\n 컴퓨터 먼저 시작\n");
	}

}

int yut(int k, int s)
{
	if (s == 1)
	{
		int move;
		if (k == 1 || k == 2 || k == 3 || k == 4)
		{
			printf("\n나온 값 : 도\n");
			move = 1;
			return gagi(move);
		}

		if (k == 5 || k == 6 || k == 7 || k == 8 || k == 9 || k == 10)
		{
			printf("\n나온 값 : 개\n");
			move = 2;
			return gagi(move);
		}

		if (k == 11 || k == 12 || k == 13 || k == 14)
		{
			printf("\n나온 값 : 걸\n");
			move = 3;
			return gagi(move);
		}

		if (k == 15)
		{
			printf("\n나온 값 : 윷\n");
			move = 4;
			return gagi(move);
		}

		if (k == 16)
		{
			printf("\n나온 값 : 모\n");
			move = 5;
			return gagi(move);
		}
	}

	if (s == 2)
	{
		int move;
		if (k == 1 || k == 2 || k == 3 || k == 4)
		{
			printf("\n나온 값 : 도\n");
			move = 1;
			return gagi2(move);
		}

		if (k == 5 || k == 6 || k == 7 || k == 8 || k == 9 || k == 10)
		{
			printf("\n나온 값 : 개\n");
			move = 2;
			return gagi2(move);
		}

		if (k == 11 || k == 12 || k == 13 || k == 14)
		{
			printf("\n나온 값 : 걸\n");
			move = 3;
			return gagi2(move);
		}

		if (k == 15)
		{
			printf("\n나온 값 : 윷\n");
			move = 4;
			return gagi2(move);
		}

		if (k == 16)
		{
			printf("\n나온 값 : 모\n");
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
			printf("당신이 승리했습니다.");
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
			printf("아쉽게, 컴퓨터가 승리했습니다.\n\n");
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