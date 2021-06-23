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
	printf("****주의사항:계수와 계수는 ,로 구분해주세요****\n");
	printf("1단계. 다항식의 미분 \n원하는 문제의 개수를 입력\n");
	scanf("%d", &repeat);
	for (int i = 0; i < repeat; i++)
	{
		int random = rand() % 4 + 1;
		if (random == 1)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			printf("계수가 %d,%d인 일차식을 미분한 것의 계수를 입력하시오\n", a, b);
			scanf("%d", &ua);
			if (ua == a)
			{
				printf("정답입니다\n");
				count++;
			}
			else
				printf("땡! 정답은 %d입니다\n", a);
		}
		if (random == 2)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			c = rand() % 10 + 1;
			printf("계수가 %d, %d, %d인 이차식을 미분한 것의 계수를 구하시오\n", a, b, c);
			scanf("%d, %d", &ua, &ub);
			if (ua == 2 * a && ub == b)
			{
				printf("정답입니다\n");
				count++;
			}
			else
				printf("땡! 정답은 %d, %d입니다\n", 2 * a, b);
		}
		if (random == 3)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			c = rand() % 10 + 1;
			d = rand() % 10 + 1;
			printf("계수가 %d, %d, %d, %d인 삼차식을 미분한 것의 계수를 구하시오\n", a, b, c, d);
			scanf("%d,%d,%d", &ua, &ub, &uc);
			if (ua == 3 * a && ub == 2 * b && uc == c)
			{
				printf("정답입니다\n");
				count++;
			}
			else
				printf("땡! 정답은 %d, %d, %d입니다\n", 3 * a, 2 * b, c);
		}
		if (random == 4)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			c = rand() % 10 + 1;
			d = rand() % 10 + 1;
			e = rand() % 10 + 1;
			printf("계수가 %d, %d, %d, %d, %d인 사차식을 미분한 것의 계수를 구하시오\n", a, b, c, d, e);
			scanf("%d, %d, %d, %d", &ua, &ub, &uc, &ud);
			if (ua == 4 * a && ub == 3 * b && uc == 2 * c && ud == d)
			{
				printf("정답입니다\n");
				count++;
			}
			else
				printf("땡! 정답은 %d, %d, %d, %d입니다\n", 4 * a, 3 * b, 2 * c, d);
		}
	}
	printf("1단계 맞은개수: %d\n", count);
	printf("2단계. 다항식의 적분\n 원하는 문제의 개수를 입력\n");
	scanf("%d", &repeat);
	count = 0;
	for (int i = 0; i < repeat; i++)
	{
		int random = rand() % 4 + 1;
		if (random == 1)
		{
			a = rand() % 5 + 1;
			printf("%d를 적분한 식의 계수를 입력하시오. 적분 상수는 0으로 한다\n", a);
			scanf("%d", &ua);
			if (ua == a)
			{
				printf("정답입니다\n");
				count++;
			}
			else printf("땡!정답은 %d입니다.\n", a);
		}
		if (random == 2)
		{
			a = 2 * (rand() % 5) + 2;
			b = 1 * (rand() % 5) + 1;
			printf("계수가 %d, %d인 일차식을 적분한 식의 계수를 입력하시오. 적분 상수는 0으로 한다\n", a, b);
			scanf("%d, %d", &ua, &ub);
			if (ua == a / 2 && ub == b)
			{
				printf("정답입니다");
				count++;
			}
			else printf("땡! 정답은 %d, %d입니다.\n", a / 2, b);
		}
		if (random == 3)
		{
			a = 3 * (rand() % 5) + 3;
			b = 2 * (rand() % 5) + 2;
			c = rand() % 5 + 1;
			printf("계수가 %d, %d, %d인 이차식을 적분한 식의 계수를 입력하시오. 적분 상수는 0으로 한다\n", a, b, c);
			scanf("%d, %d, %d", &ua, &ub, &uc);
			if (ua == a / 3 && ub == b / 2 && uc == c)
			{
				printf("정답입니다\n");
				count++;
			}
			else printf("땡! 정답은 %d, %d, %d입니다. \n", a / 3, b / 2, c);
		}
		if (random == 4)
		{
			a = 4 * (rand() % 3 + 1);
			b = 3 * (rand() % 3 + 1);
			c = 2 * (rand() % 3 + 1);
			d = 5 % rand() + 1;
			printf("계수가 %d, %d, %d, %d인 삼차식을 적분한 식의 계수를 입력하시오. 적분 상수는 0으로 한다\n", a, b, d, c);
			scanf("%d, %d, %d, %d", &ua, &ub, &uc, &ud);
			if (ua == a / 4 && ub == b / 3 && uc == c / 2 && ud == d)
			{
				printf("정답입니다\n");
				count++;
			}
			else printf("땡! 정답은 %d, %d, %d, %d입니다. \n", a / 4, b / 3, c / 2, d);
		}
	}
	printf("2단계 맞은 개수: %d", count);
	return 0;
}
v