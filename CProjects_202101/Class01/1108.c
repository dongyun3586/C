#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void printarr(int(*arr)[5], int a, int b);
int ifwin(int(*arr)[5], int a, int b, int(*arr2));
int ifwinhorizontal(int(*arr)[5], int i, int j);
int ifwinvertical(int(*arr)[5], int i, int j);
int ifavailable(int(*arr)[5]);
int main()
{
	srand(time(NULL));
	int arr[5][5] = { 0 }; int c = 0, d = 0;
	int winarr[2] = { 0 };
	for (int i = 0; c == 0; i++) {
		int a = rand() % 5;
		int b = rand() % 5;
		while (arr[a][b] != 0)
		{
			a = rand() % 5;
			b = rand() % 5;
		}
		arr[a][b] = 1;
		printarr(arr, 5, 5);
		c = ifwin(arr, 5, 5, winarr);
		if (c != 0 || ifavailable(arr[5]))
			break;
		int p, q;
		scanf("%d %d", &p, &q);
		while (arr[p - 1][q - 1] != 0)
		{
			printf("이미 차지한 공간! 다시.");
			scanf("%d %d", &p, &q);
		}
		arr[p - 1][q - 1] = 2;
		printarr(arr, 5, 5);
		c = ifwin(arr, 5, 5, winarr);
		if (c != 0 || ifavailable(arr[5]))
			break;
	}
	if (ifavailable(arr[5]))
		printf("더이상 안돼.");
	else if (c == 1)
	{
		printf("사목 끝! 승부 결정!");
		if (arr[winarr[0]][winarr[1]] == 1)
			printf("컴퓨터 승");
		else
			printf("네가 이겼다");
	}


}
void printarr(int(*arr)[5], int a, int b)   // 매개변수를 포인터로 만든 뒤 가로 크기 지정
{
	for (int j = 0; j < b; j++)
	{
		for (int i = 0; i < a; i++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int ifwin(int(*arr)[5], int a, int b, int(*arr2))
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				if (ifwinhorizontal(arr, i, j)) //가로 방향
				{
					arr2[0] = i, arr2[1] = j;
					return 1;

				}
				return 0;
			}
			else if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				if (ifwinvertical(arr, i, j))//세로 방향
				{
					arr2[0] = i, arr2[1] = j;
					return 1;

				}
				return 0;
			}

		}
	}
	return 0;
}
int ifwinhorizontal(int(*arr)[5], int i, int j)
{

	if (arr[i][j] == arr[i + 3][j])
		return 1;
	return 0;

}
int ifwinvertical(int(*arr)[5], int i, int j)
{

	if (arr[i][j] == arr[i][j + 3])
		return 1;

	return 0;

}
int ifavailable(int(*arr)[5])
{
	int* ptr = arr;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == 0)
				return 0;
		}
	}
	return 1;
}