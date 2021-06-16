#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	//�츮 �� ģ���� 25���� �ڸ��� �������� �迭�ϱ�
	//�켱 7*7 �迭�� ������ ���� ���� �Ѻκ��� ��� 0���� �����Ѵ�.
	int student[7][7] = { 0,0,0,0,0,0,0,0,1,2,3,4,5,0,0,6,7,8,9,10,0,0,11,12,13,14,15,0,0,16,17,18,19,20,0,0,21,22,23,24,25,0 };
	//�켱 ���� �ڱ� ��ȣ�� �ش�.
	int y = 0, x = 0;

	srand(time(NULL));
	for (int i = 0; i < rand() % 100 + 1; i++)
	{
		int sum;//��� ���� �޾��� �����
		int m1 = rand() % 5 + 1;
		int n1 = rand() % 5 + 1;
		sum = student[m1][n1];
		int m2 = rand() % 5 + 1;
		int n2 = rand() % 5 + 1;
		student[m1][n1] = student[m2][n2];
		student[m2][n2] = sum;
		//�� �ڵ�� �������� 2���� ���� ������ �� ���� ���� �ٲ����ν� �����ش�.
	}
	for (y = 1; y < 6; y++)
	{
		for (x = 1; x < 6; x++)
		{
			printf("%02d ", student[y][x]);
		}
		printf("\n"); //7*7�� 5*5 �迭�� ���� ������ش�.
	}


	//25�� �� 2���� ��ȣ�� ��������.
	int a1 = rand() % 5 + 1;
	int a2 = rand() % 5 + 1;
	int b1 = rand() % 5 + 1;
	int b2 = rand() % 5 + 1;
	//�� ��ȣ�� ������ �ִ� ��ź�� ����
	int bombnumber[7][7] = { 0 };
	bombnumber[a1][b1] = 1;
	bombnumber[a2][b2] = 1;
	int total = 2; //��ü ��ź����
A:
	printf("\n");
	printf("���̵��� �����ϼ���\n\n");
	printf("����:12ȸ--> 1�� �Է��ϼ���\n\n");
	printf("����:9ȸ--> 2�� �Է��ϼ���\n\n");
	printf("�����:6ȸ--> 3�� �Է��ϼ���\n\n");

	int num;
	scanf("%d", &num);
	if (num < 1 || num>3)
	{
		printf("�ٽ� �Է����ּ���.\n");
		goto A;
	}
	int a, sum = 0;//a�� ������ �� ��ȣ, sum�� � �� ��ȣ�� �������� �� �����¿쿡 �ִ� ģ������ ������ �ִ� ��ź ������ ����

	if (num == 1)
	{
		int x1, y1;//������ ��ȣ�� �Է����� �� �� ��ȣ�� ���� x1, ���� y1���� ������.
		for (int i = 0; i < 12; i++)
		{
			if (total == 0)//�����ִ� ��ź�� 0���� �Ǹ� ��������
			{
				printf("��ź�� ��� ã�ҽ��ϴ�!");
				break;
			}

			printf("��ȣ�� �Է��ϼ���:");//y1,x1�� a�� ��� ��
			scanf("%d", &a);
			for (y = 1; y < 6; y++)
			{
				for (x = 1; x < 6; x++)
				{
					if (student[y][x] == a)
					{
						x1 = x;
						y1 = y;
					}
				}
			}
			printf("�� �л��� ������ �ִ� ��ź�� ����: %d\n", bombnumber[y1][x1]);//a���� �л��� ������ �ִ� ��ź����
			if (bombnumber[y1][x1] == 1)
			{
				total--;
				bombnumber[y1][x1] = 0;
			}

			sum = bombnumber[y1 - 1][x1] + bombnumber[y1 + 1][x1] + bombnumber[y1][x1 + 1] + bombnumber[y1][x1 - 1];
			printf("�� �л� �ֺ��� �����ϴ� ��ź�� ����:%d\n", sum);
		}
	}

	else if (num == 2)
	{
		int x1, y1;//������ ��ȣ�� �Է����� �� �� ��ȣ�� ���� x1, ���� y1���� ������.
		for (int i = 0; i < 9; i++)
		{
			if (total == 0)//�����ִ� ��ź�� 0���� �Ǹ� ��������
			{
				printf("��ź�� ��� ã�ҽ��ϴ�!");
				break;
			}

			printf("��ȣ�� �Է��ϼ���:");//y1,x1�� a�� ��� ��
			scanf("%d", &a);
			for (y = 1; y < 6; y++)
			{
				for (x = 1; x < 6; x++)
				{
					if (student[y][x] == a)
					{
						x1 = x;
						y1 = y;
					}
				}
			}
			printf("�� �л��� ������ �ִ� ��ź�� ����: %d\n", bombnumber[y1][x1]);//a���� �л��� ������ �ִ� ��ź����
			if (bombnumber[y1][x1] == 1)
				total--;
			sum = bombnumber[y1 - 1][x1] + bombnumber[y1 + 1][x1] + bombnumber[y1][x1 + 1] + bombnumber[y1][x1 - 1];
			printf("�� �л� �ֺ��� �����ϴ� ��ź�� ����:%d\n", sum);
			printf("\n");
		}
	}

	else if (num == 3)
	{
		int x1, y1;//������ ��ȣ�� �Է����� �� �� ��ȣ�� ���� x1, ���� y1���� ������.
		for (int i = 0; i < 6; i++)
		{
			if (total == 0)//�����ִ� ��ź�� 0���� �Ǹ� ��������
			{
				printf("��ź�� ��� ã�ҽ��ϴ�!");
				break;
			}

			printf("��ȣ�� �Է��ϼ���:");//y1,x1�� a�� ��� ��
			scanf("%d", &a);
			for (y = 1; y < 6; y++)
			{
				for (x = 1; x < 6; x++)
				{
					if (student[y][x] == a)
					{
						x1 = x;
						y1 = y;
					}
				}
			}
			printf("�� �л��� ������ �ִ� ��ź�� ����: %d\n", bombnumber[y1][x1]);//a���� �л��� ������ �ִ� ��ź����
			if (bombnumber[y1][x1] == 1)
				total--;
			sum = bombnumber[y1 - 1][x1] + bombnumber[y1 + 1][x1] + bombnumber[y1][x1 + 1] + bombnumber[y1][x1 - 1];
			printf("�� �л� �ֺ��� �����ϴ� ��ź�� ����:%d\n", sum);
		}
	}


}