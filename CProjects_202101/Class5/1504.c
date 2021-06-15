#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char name[2][10 + 1];								// ��������(� �Լ������� ��� ����)
int arr[6][7] = { 0 };
char new[7] = { 0 };//�� �迭�� �ε����� 1�� ���� ���� �������� �� ��ȣ�̴�. 
void print();
int check();

int main()
{
	int n;
	printf("��հ� �ų��� 4�� ������ӿ� ���� ���� ȯ���մϴ�.\n");
	printf("4�� ��������� ���� 7ĭ,���� 6ĭ�� ���� ���� ������� �׾ƿø��� �����Դϴ�.\n�÷��̾� 1�� ������ ���� �����ϴ� ������ �� �����ּ���.\n");
	printf("���� 4���� ����� ����� �����Դϴ�.\n\n");
	printf("�����ϱ� 1.ģ�� 2��� ����  2.�׸��ϱ�  ");
	scanf("%d", &n);

	while (n != 1 && n != 2)
	{
		printf("�ٽ� �������ּ��� ");
		scanf("%d", &n);
	}

	if (n == 1)
	{
		int a, b, i, j, count = 0;
		printf("�÷��̾� 1�� �̸�: ");
		scanf("%s", name[0]);						//&name[0][0]�� ���� �ǹ�  %s�� ���ڿ��� �ǹ��Ѵ�.
		printf("�÷��̾� 2�� �̸�: ");
		scanf("%s", name[1]);

		while (1)
		{
			if (count == 42)//count�� 42�� ���� ������ �������� 42ĭ�̱� �����̴�.
			{
				printf("\n���º��Դϴ�. �����ϼ̽��ϴ�.\n ");
				return 0;
			}
			printf("\n%s��(��) ��(1~7)�� �������ּ��� ", name[0]);
			scanf("%d", &a);
			count++;
			i = 5 - new[a - 1];//�Ʒ��������� �׿��� �ϹǷ�
			arr[i][a - 1] = 1;
			print();
			if (check())
			{
				printf("\n%s�� �¸��Ͽ����ϴ�. �̿����ּż� �����մϴ�.\n", name[0]);
				break;
			}
			new[a - 1] += 1;

			printf("\n%s�� ��(1~7)�� �������ּ��� ", name[1]);
			scanf("%d", &b);
			count++;
			j = 5 - new[b - 1];
			arr[j][b - 1] = 2;
			print();
			if (check())
			{
				printf("\n%s�� �¸��Ͽ����ϴ�.�̿����ּż� �����մϴ�.\n", name[1]);
				break;
			}
			new[b - 1] += 1;


		}
	}
	else
	{
		printf("\n\n������ �������ϴ�. �̿����ּż� �����մϴ�.\n");
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
			if (arr[5 - f][e] == 1 && arr[4 - f][e + 1] == 1 && arr[3 - f][e + 2] == 1 && arr[2 - f][e + 3] == 1)//������ ���� ���� �밢��
			{
				return 1;
			}
			else if (arr[5 - f][6 - e] == 1 && arr[4 - f][5 - e] == 1 && arr[3 - f][4 - e] == 1 && arr[2 - f][3 - e] == 1)//���� ���� ���� �밢��
			{
				return 1;
			}
		}
	}

	for (g = 0; g < 4; g++)
	{
		for (h = 0; h < 6; h++)
		{
			if (arr[h][g] == 1 && arr[h][g + 1] == 1 && arr[h][g + 2] == 1 && arr[h][g + 3] == 1)//����
			{
				return 1;
			}
		}

	}
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 7; l++)
		{
			if (arr[k][l] == 1 && arr[k + 1][l] == 1 && arr[k + 2][l] == 1 && arr[k + 3][l] == 1)//����
			{
				return 1;
			}
		}
	}
	return 0;

}
