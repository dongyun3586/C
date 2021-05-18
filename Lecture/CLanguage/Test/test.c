#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int ans, recept, count = 0;
	srand(time(NULL));
	ans = rand() % 100 + 1;
	printf("*** 1학년 6반 17번 한지민 ***\n1~100사이의 숫자를  추측하는 게임입니다.\n");
	printf("\n");
	printf("정답: %d\n", ans);
	printf("\n");

	do
	{
		printf("정답은?: ");
		scanf("%d", &recept);
		if (recept != ans)
		{
			if (recept > ans)
			{
				printf("틀렸습니다. %d 보다 작습니다.\n", recept);
			}
			else
			{
				printf("틀렸습니다. %d 보다 큽니다.\n", recept);
			}
		}
		else
		{
			printf("정답입니다.\n");
		}
		count++;
	} while (recept != ans);
	printf("\n");
	printf("%d번 만에 맞혔습니다.\n", count);


	return 0;
}