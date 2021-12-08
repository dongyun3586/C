#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculator(int* R2, int* R3, int* SecredtW, int* n);
int main()
{
	int a;
	printf("안녕하세요. 1학년 3반 17번 한준입니다.");
	printf("\n 지금부터 휘트스톤 브릿지 실험 결과 도출 프로그램을 시작하도록 하겠습니다.\n");
	printf("\n 휘트스톤 브릿지에 관한 간단한 설명을 원하시면 1번 \n 휘트스톤 브릿 실험에 결과를 도출하고 싶으시면 2번을 눌러주세요.");
	scanf("%d", &a);

	if (a == 2)
	{
		srand(time(NULL));
		int count = 100;
		int c;
		int d;
		int R2;
		int R3;
		int key;
		int arr[100];
		int SecretW;
		int joehang = (rand() % 9 + 1);

		if (joehang % 2 == 1)
		{
			SecretW = (joehang + 1) * 100;
		}
		else
		{
			SecretW = joehang * 100;
		}

		for (int i = 0; i < 100; i++)
		{
			int n = 0;
			printf("\n 실험을 할 때 사용하신 도선 저항 값을 입력해주세요. :  ");
			scanf("%d", &arr[i]);
			printf("\n문제에서 주어진 R1, 즉 저항값을 알고 있는 저항의 저항 값(R1)은 1000옴 입니다.\n");
			printf("\n미지의 저항이 가질 수 있는 미지의 저항값은 200옴, 400옴, 600옴, 800옴, 1000옴 입니다.");
			int R1 = 1000;
			printf("\n도선 저항의 길이비는 몇 대 몇 입니까?   ");
			scanf("%d", &c);
			printf(" :     ");
			scanf("%d", &d);
			R2 = arr[i] * c / (c + d);
			R3 = arr[i] * d / (c + d);
			printf("\n도선 저항 값과 길이 비를 이용하여 저항 값을 계산한 결과 입니다. R2 = %d\n", R2);
			printf("\n도선 저항 값과 길이 비를 이용하여 저항 값을 계산한 결과 입니다. R3 = %d\n", R3);
			key = calculator(&R2, &R3, &SecretW, &n);
			if (key == 1)
			{
				printf("\n 실험에 성공하셨습니다.\n");
				printf("가변저항값은 %d 였습니다.", SecretW);
				return 0;

			}

			else if (key == 0)
			{
				printf("\n 실험에 실패 하셨습니다.\n");
				if (n > SecretW)
				{
					float percentage;
					percentage = (n - SecretW);
					printf("\n 오차율은 %f입니다.", percentage / SecretW * 100);
					printf("\n\n %d", SecretW);
				}
				else if (n < SecretW)
				{
					float percentage1;
					percentage1 = (SecretW - n);
					printf("\n 오차율은 %f입니다.", percentage1 / SecretW * 100);
					printf("\n\n %d", SecretW);
				}
				printf("\n 다시 실험에 도전하시길 바랍니다.");
			}

			else if (key == 2)
			{
				printf("\n 실험에 성공하셨습니다. \n");
				printf("\n 도선 자체 저항에 의해 정확한 저항값은 나오지 않았습니다.\n");
				printf("\n 실제 저항의 저항값은 %d 입니다.\n", SecretW);
				return 0;
			}
		}
	}

	else
	{
		printf("\n처음부터 다시 시작해주세요\n");
		return 0;
	}
}

int calculator(int* R2, int* R3, int* SecretW, int* n)
{
	printf("\n계산을 시작하도록 하겠습니다.\n");
	printf("\n휘스톤 브릿지 공식에 의해 R1 * R3 = R2 * R4를 만족합니다.");
	printf("\n%d * %d = %d * x\n", 1000, *R3, *R2);
	printf("\n x = %d", 1000 * *R3 / *R2);
	*n = 1000 * *R3 / *R2;
	if (*n == *SecretW)
	{
		return 1;
	}

	else if (*n - *SecretW <= 10 && *n - *SecretW >= -10)
	{
		return 2;
	}

	else
	{
		return 0;
	}
}