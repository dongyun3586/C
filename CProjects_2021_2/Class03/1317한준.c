#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculator(int* R2, int* R3, int* SecredtW, int* n);
int main()
{
	int a;
	printf("�ȳ��ϼ���. 1�г� 3�� 17�� �����Դϴ�.");
	printf("\n ���ݺ��� ��Ʈ���� �긴�� ���� ��� ���� ���α׷��� �����ϵ��� �ϰڽ��ϴ�.\n");
	printf("\n ��Ʈ���� �긴���� ���� ������ ������ ���Ͻø� 1�� \n ��Ʈ���� �긴 ���迡 ����� �����ϰ� �����ø� 2���� �����ּ���.");
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
			printf("\n ������ �� �� ����Ͻ� ���� ���� ���� �Է����ּ���. :  ");
			scanf("%d", &arr[i]);
			printf("\n�������� �־��� R1, �� ���װ��� �˰� �ִ� ������ ���� ��(R1)�� 1000�� �Դϴ�.\n");
			printf("\n������ ������ ���� �� �ִ� ������ ���װ��� 200��, 400��, 600��, 800��, 1000�� �Դϴ�.");
			int R1 = 1000;
			printf("\n���� ������ ���̺�� �� �� �� �Դϱ�?   ");
			scanf("%d", &c);
			printf(" :     ");
			scanf("%d", &d);
			R2 = arr[i] * c / (c + d);
			R3 = arr[i] * d / (c + d);
			printf("\n���� ���� ���� ���� �� �̿��Ͽ� ���� ���� ����� ��� �Դϴ�. R2 = %d\n", R2);
			printf("\n���� ���� ���� ���� �� �̿��Ͽ� ���� ���� ����� ��� �Դϴ�. R3 = %d\n", R3);
			key = calculator(&R2, &R3, &SecretW, &n);
			if (key == 1)
			{
				printf("\n ���迡 �����ϼ̽��ϴ�.\n");
				printf("�������װ��� %d �����ϴ�.", SecretW);
				return 0;

			}

			else if (key == 0)
			{
				printf("\n ���迡 ���� �ϼ̽��ϴ�.\n");
				if (n > SecretW)
				{
					float percentage;
					percentage = (n - SecretW);
					printf("\n �������� %f�Դϴ�.", percentage / SecretW * 100);
					printf("\n\n %d", SecretW);
				}
				else if (n < SecretW)
				{
					float percentage1;
					percentage1 = (SecretW - n);
					printf("\n �������� %f�Դϴ�.", percentage1 / SecretW * 100);
					printf("\n\n %d", SecretW);
				}
				printf("\n �ٽ� ���迡 �����Ͻñ� �ٶ��ϴ�.");
			}

			else if (key == 2)
			{
				printf("\n ���迡 �����ϼ̽��ϴ�. \n");
				printf("\n ���� ��ü ���׿� ���� ��Ȯ�� ���װ��� ������ �ʾҽ��ϴ�.\n");
				printf("\n ���� ������ ���װ��� %d �Դϴ�.\n", SecretW);
				return 0;
			}
		}
	}

	else
	{
		printf("\nó������ �ٽ� �������ּ���\n");
		return 0;
	}
}

int calculator(int* R2, int* R3, int* SecretW, int* n)
{
	printf("\n����� �����ϵ��� �ϰڽ��ϴ�.\n");
	printf("\n�ֽ��� �긴�� ���Ŀ� ���� R1 * R3 = R2 * R4�� �����մϴ�.");
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