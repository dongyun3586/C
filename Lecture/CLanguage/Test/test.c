#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int n = 0, jungdap = 0, count = 0;

	printf("*** 1학년 1반 2번 강은찬 ***\n1~100사이의 숫자를 추측하는 게임입니다.\n\n");
	srand(time(NULL));
	jungdap = rand() % 100 + 1;

	printf("정답 : %d\n\n", jungdap);

	while (1)
	{
		printf("정답은?: ");
		scanf("%d", &n);

		if (n != jungdap)
		{
			printf("틀렸습니다. ");
			if (n > jungdap)
			{
				printf("%d보다 작습니다. \n", n);
			}
			else if (n < jungdap)
			{
				printf("%d보다 큽니다. \n", n);
			}
			count++;
		}
		if (n == jungdap)
		{
			printf("정답입니다. \n\n");
			count++;
			break;
		}
	}
	printf("%d번 만에 맞혔습니다. ", count);

	return 0;
}
