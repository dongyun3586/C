#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	//���⼭�� �� 3���� ������ m = ��ü �л���, a = ������, b = �������̴�.
	int m, a, b = 0;
	int sitnumber[100] = { 0 };
	printf("*** 1212 ������ ���� ������Ʈ ***\n");
	printf("*** �� ���α׷��� �л����� �Է��ϸ� �ڸ��� ��ġ���ִ� ���α׷��Դϴ�.***\n");
	printf("�л����� �Է��ϼ���.\n");
	printf("�л����� �ִ� 100������ �����մϴ�.\n");
	scanf("%d", &m);
	//�� �ؿ� �ִ� �Լ��� �л����� 100���� �Ѿ��� �� �ٽ� �л� ���� �Է��ϵ��� �ϴ� �ڵ��̴�.
	if (m > 100)
	{
		printf("�л����� �ִ� 100������ �����մϴ�.\n");
		printf("�ٽ� �Է����ֽʽÿ�.\n");
		scanf("%d", &m);
	}
	//�� �ؿ� �ִ� �ڵ�� �ڸ��� ���� �л��� ������ ���� �� �ٽ� �Է��ϰ� �ϴ� �ڵ��̴�.
	while (1)
	{
		printf("�ڸ��� ������ ���� �Է����ֽʽÿ� : ");
		scanf("%d", &a);
		printf("�ڸ��� ������ ���� �Է����ֽʽÿ� : ");
		scanf("%d", &b);
		if (a * b < m)
		{
			printf("�ڸ��� ���� �л������� �����ϴ�. �ٽ� �Է��� �ֽʽÿ�.\n");
		}
		else
		{
			break;
		}
	}
	//�迭 �ȿ� �л�����ŭ�� ���� �������� �迭, �ߺ��Ǵ� ���� ������ �ʵ��� �Ѵ�.
	//sitnumber�ȿ��ٰ� ���ڸ� �迭�Ѵ�. �̰��� ��ȣ�� �ȴ�. �л����� 100�� �̳��̹Ƿ� ũ�Ⱑ 100�� �迭�� ����
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		sitnumber[i] = rand() % m + 1;
		for (int j = 0; j < i; j++)
		{
			if (sitnumber[j] == sitnumber[i])
			{
				i--;
				break;
			}
		}
	}
	//�� ���� �ڵ忡�� �� ������ �ִ� �͵�Ͱ� ���� ���� ���´ٸ� Ƚ���� ���� �� �ٽ� ���ư��� �ϴ� ���̴�.
	//�̷��� ������� �Ѵٸ� ������ �κп����� �ȳ��� �Ѱ��� ���ڰ� ���� ������ ������ ���� ������ �ǹǷ� �ӵ��� �������� ������ ���� �� ����.
	//�������� ĭ�� ����� �� �ȿ� �迭�� �Ѵ�.
	printf("�ڸ�ǥ\n");
	printf("��");
	for (int l = 0; l < a - 1; l++)
	{
		printf("��������");
	}
	printf("��������\n");

	//������� ������ ��ġ�� ���
	//���⼭�� �������� ����Ѵ�.
	//���⼭ �̹� ������ �� ���� ����߰�, �ؿ����� �� ���� �� ����� ���̴�, 2���� �����Ѵ�.
	for (int j = 2; j < 2 * b + 1; j++)
	{
		//�����ٿ����� Ȧ���� ¦���ĸ� ���� �������� �������̳� ���ڸ� ���� �ڵ带 ���� ���̳ĸ� �����Ѵ�.
		if (j % 2 == 0)
		{
			for (int i = 1; i < 2 * a + 2; i++)
			{
				//���⼭�� ���������� %2�� ���� Ȧ����, ¦���ĸ� ���� �ű⿡ ���� ������ �Ǵ� ���ڸ� �������� �����Ѵ�
				if (i % 2 == 1)
				{
					printf("��");
				}
				else
				{
					if ((j / 2 - 1) * a + i / 2 - 1 < m)
					{
						printf(" %2d", sitnumber[(j / 2 - 1) * a + i / 2 - 1]);
					}
					//���⼭ if���� ����ϴ� ������ ���� �ڸ����� ��ġ�� �л����� �Ѿ��� ���, ������� �ʱ� ���ؼ��̴�.
					else
					{
						printf("   ");
					}
				}
			}
			printf("\n");
		}
		else
		{
			printf("��");
			for (int i = 1; i < a; i++)
			{
				printf("��������");
			}
			printf("��������\n");
		}
	}

	//���⼭�� �� �Ʒ����� ������ ����Ѵ�.

	printf("��");
	for (int l = 0; l < a - 1; l++)
	{
		printf("��������");
	}
	printf("��������\n");
	return 0;
}