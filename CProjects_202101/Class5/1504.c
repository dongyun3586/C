#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char name[2][10 + 1];								// 전역변수(어떤 함수에서도 사용 가능)
int arr[6][7] = { 0 };
char new[7] = { 0 };//이 배열의 인덱스에 1을 더한 것은 빙고판의 줄 번호이다. 
void print();
int check();

int main()
{
	int n;
	printf("재밌고 신나는 4목 빙고게임에 오신 것을 환영합니다.\n");
	printf("4목 빙고게임은 가로 7칸,세로 6칸인 판을 세워 빙고알을 쌓아올리는 게임입니다.\n플레이어 1이 게임을 먼저 시작하니 순서를 잘 정해주세요.\n");
	printf("먼저 4목을 만드는 사람이 승자입니다.\n\n");
	printf("선택하기 1.친구 2명과 게임  2.그만하기  ");
	scanf("%d", &n);

	while (n != 1 && n != 2)
	{
		printf("다시 선택해주세요 ");
		scanf("%d", &n);
	}

	if (n == 1)
	{
		int a, b, i, j, count = 0;
		printf("플레이어 1의 이름: ");
		scanf("%s", name[0]);						//&name[0][0]과 같은 의미  %s는 문자열을 의미한다.
		printf("플레이어 2의 이름: ");
		scanf("%s", name[1]);

		while (1)
		{
			if (count == 42)//count가 42일 때인 이유는 빙고판이 42칸이기 때문이다.
			{
				printf("\n무승부입니다. 수고하셨습니다.\n ");
				return 0;
			}
			printf("\n%s는(은) 줄(1~7)을 선택해주세요 ", name[0]);
			scanf("%d", &a);
			count++;
			i = 5 - new[a - 1];//아래에서부터 쌓여야 하므로
			arr[i][a - 1] = 1;
			print();
			if (check())
			{
				printf("\n%s가 승리하였습니다. 이용해주셔서 감사합니다.\n", name[0]);
				break;
			}
			new[a - 1] += 1;

			printf("\n%s는 줄(1~7)을 선택해주세요 ", name[1]);
			scanf("%d", &b);
			count++;
			j = 5 - new[b - 1];
			arr[j][b - 1] = 2;
			print();
			if (check())
			{
				printf("\n%s가 승리하였습니다.이용해주셔서 감사합니다.\n", name[1]);
				break;
			}
			new[b - 1] += 1;


		}
	}
	else
	{
		printf("\n\n게임이 끝났습니다. 이용해주셔서 감사합니다.\n");
		return 0;
	}

}

void print()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[i][j] == 1)
			{
				printf(" O");
			}

			else if (arr[i][j] == 2)
			{
				printf(" X");
			}

			else
			{
				printf(" _");
			}

		}
		printf("\n");
	}
	printf("\n 1 2 3 4 5 6 7\n");
}

int check()
{
	int e, f, g, h, k;
	for (e = 0; e < 4; e++)
	{
		for (f = 0; f < 3; f++)
		{
			if (arr[5 - f][e] == 1 && arr[4 - f][e + 1] == 1 && arr[3 - f][e + 2] == 1 && arr[2 - f][e + 3] == 1)//오른쪽 위로 가는 대각선
			{
				return 1;
			}
			else if (arr[5 - f][6 - e] == 1 && arr[4 - f][5 - e] == 1 && arr[3 - f][4 - e] == 1 && arr[2 - f][3 - e] == 1)//왼쪽 위로 가는 대각선
			{
				return 1;
			}
		}
	}

	for (g = 0; g < 4; g++)
	{
		for (h = 0; h < 6; h++)
		{
			if (arr[h][g] == 1 && arr[h][g + 1] == 1 && arr[h][g + 2] == 1 && arr[h][g + 3] == 1)//수평
			{
				return 1;
			}
		}

	}
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 7; l++)
		{
			if (arr[k][l] == 1 && arr[k + 1][l] == 1 && arr[k + 2][l] == 1 && arr[k + 3][l] == 1)//수직
			{
				return 1;
			}
		}
	}
	return 0;

}
