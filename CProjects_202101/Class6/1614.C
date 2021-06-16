#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a, b; // a:난이도, b:게임에 걸을 돈 액수
	int x, y, z; // x, y, z:게임에서 랜덤으로 제공되는 난수
	int answer; // answer:사람이 입력하는 답
	int count = 0; // count:맞춘 개수
	int c; //c:구매할 품목 번호
	int m = 100, n = 200, k = 300, l = 9000; //각 품목들의 가격
	int money = 0; //money:사용자가 게임을 통해 벌은 돈
	// 1. 게임 설명
	printf("이 게임은 당신이 돈을 걸고 난이도와 맞추신 개수에 따라 돈을 다시 지급해 드리는 게임입니다.\n");
	printf("한 난이도에는 총 3문제가 있습니다. 그럼 시작하겠습니다.\n");

	// 2. 난이도 입력
	printf("원하는 난이도를 입력하세요.\n1. 쉬움\n2. 보통\n3. 어려움\n");
	scanf("%d", &a);
	srand(time(NULL));

	// 3. 게임 실행 및 맟춘 개수와 지급된 금액 출력
	if (a == 1)
	{
		printf("이 게임에 얼마를 걸으시겠습니까?\n");
		scanf("%d", &b);
		printf("게임을 시작합니다.\n");
		printf("문제를 하나도 못 맞추신다면 0원, 1개를 맞추신다면 %d원, 2개를 맞추신다면 %d원, 모두 맞추신다면 %d원을 드리겠습니다.\n", b, 2 * b, 3 * b);
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
			printf("%d. %d + %d = ", i + 1, x, y);
			scanf("%d", &answer);
			if (answer == x + y)
			{
				printf("정답입니다.\n");
				count++;
			}
			else
			{
				printf("오답입니다. 정답은 %d입니다.\n", x + y);
			}
		}
		printf("총 %d개를 맞추셨습니다. 지급된 금액은 %d원입니다.\n", count, count * b);
		money = count * b;
	}
	else if (a == 2)
	{
		printf("이 게임에 얼마를 걸으시겠습니까?\n");
		scanf("%d", &b);
		printf("게임을 시작합니다.\n");
		printf("문제를 하나도 못 맞추신다면 0원, 1개를 맞추신다면 %d원, 2개를 맞추신다면 %d원, 모두 맞추신다면 %d원을 드리겠습니다.\n", b, 4 * b, 6 * b);
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
			printf("%d. %d X %d = ", i + 1, x, y);
			scanf("%d", &answer);
			if (answer == x * y)
			{
				printf("정답입니다.\n");
				count++;
			}
			else
			{
				printf("오답입니다. 정답은 %d입니다.\n", x * y);
			}
		}


		printf("총 %d개를 맞추셨습니다. 지급된 금액은 %d원입니다.\n", count, 2 * count * b);
		money = 2 * count * b;
	}
	else if (a == 3)
	{
		printf("이 게임에 얼마를 걸으시겠습니까?\n");
		scanf("%d", &b);
		printf("게임을 시작합니다.\n");
		printf("문제를 하나도 못 맞추신다면 0원, 1개를 맞추신다면 %d원, 2개를 맞추신다면 %d원, 모두 맞추신다면 %d원을 드리겠습니다.\n", b, 6 * b, 9 * b);
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
			z = rand() % 100 + 1;
			printf("%d. (%d + %d) X %d = ", i + 1, x, y, z);
			scanf("%d", &answer);
			if (answer == (x + y) * z)
			{
				printf("정답입니다.\n");
				count++;
			}
			else
			{
				printf("오답입니다. 정답은 %d입니다.\n", (x + y) * z);
			}
		}
		printf("총 %d개를 맞추셨습니다. 지급된 금액은 %d원입니다.\n", count, 3 * count * b);
		money = 3 * count * b;
	}
	else
	{
		printf("입력하신 난이도는 없는 난이도입니다.");
		return 0;
	}

	// 4. 게임 후 구매할 상품 품목 번호 입력
	printf("수고하셨습니다. 모든 게임을 다 끝내셨습니다.\n");
	printf("벌으신 금액으로 어떤 상품을 구매하시겠습니까?\n");
	printf("1. 물-%d원\n2. 연필-%d원\n3. 지우개-%d원\n4. 마우스-%d원\n", m, n, k, l);
	scanf("%d", &c);
	if (c == 1)
	{
		if (money >= m)
		{
			printf("구매가 가능합니다. 남은 금액은 %d원입니다.\n", money - m);
		}
		else
		{
			printf("구매하실 수 없습니다.\n");
		}
	}
	else if (c == 2)
	{
		if (money >= n)
		{
			printf("구매가 가능합니다. 남은 금액은 %d원입니다.\n", money - n);
		}
		else
		{
			printf("구매하실 수 없습니다.\n");
		}
	}
	else if (c == 3)
	{
		if (money >= k)
		{
			printf("구매가 가능합니다. 남은 금액은 %d원입니다.", money - k);
		}
		else
		{
			printf("구매하실 수 없습니다.\n");
		}
	}
	else if (c == 4)
	{
		if (money >= l)
		{
			printf("구매가 가능합니다. 남은 금액은 %d원입니다.\n", money - l);
		}
		else
		{
			printf("구매하실 수 없습니다.\n");
		}
	}
	else
	{
		printf("해당하지 않는 번호입니다.\n");
	}
}