#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a, b; // a:���̵�, b:���ӿ� ���� �� �׼�
	int x, y, z; // x, y, z:���ӿ��� �������� �����Ǵ� ����
	int answer; // answer:����� �Է��ϴ� ��
	int count = 0; // count:���� ����
	int c; //c:������ ǰ�� ��ȣ
	int m = 100, n = 200, k = 300, l = 9000; //�� ǰ����� ����
	int money = 0; //money:����ڰ� ������ ���� ���� ��
	// 1. ���� ����
	printf("�� ������ ����� ���� �ɰ� ���̵��� ���߽� ������ ���� ���� �ٽ� ������ �帮�� �����Դϴ�.\n");
	printf("�� ���̵����� �� 3������ �ֽ��ϴ�. �׷� �����ϰڽ��ϴ�.\n");

	// 2. ���̵� �Է�
	printf("���ϴ� ���̵��� �Է��ϼ���.\n1. ����\n2. ����\n3. �����\n");
	scanf("%d", &a);
	srand(time(NULL));

	// 3. ���� ���� �� ���� ������ ���޵� �ݾ� ���
	if (a == 1)
	{
		printf("�� ���ӿ� �󸶸� �����ðڽ��ϱ�?\n");
		scanf("%d", &b);
		printf("������ �����մϴ�.\n");
		printf("������ �ϳ��� �� ���߽Ŵٸ� 0��, 1���� ���߽Ŵٸ� %d��, 2���� ���߽Ŵٸ� %d��, ��� ���߽Ŵٸ� %d���� �帮�ڽ��ϴ�.\n", b, 2 * b, 3 * b);
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
			printf("%d. %d + %d = ", i + 1, x, y);
			scanf("%d", &answer);
			if (answer == x + y)
			{
				printf("�����Դϴ�.\n");
				count++;
			}
			else
			{
				printf("�����Դϴ�. ������ %d�Դϴ�.\n", x + y);
			}
		}
		printf("�� %d���� ���߼̽��ϴ�. ���޵� �ݾ��� %d���Դϴ�.\n", count, count * b);
		money = count * b;
	}
	else if (a == 2)
	{
		printf("�� ���ӿ� �󸶸� �����ðڽ��ϱ�?\n");
		scanf("%d", &b);
		printf("������ �����մϴ�.\n");
		printf("������ �ϳ��� �� ���߽Ŵٸ� 0��, 1���� ���߽Ŵٸ� %d��, 2���� ���߽Ŵٸ� %d��, ��� ���߽Ŵٸ� %d���� �帮�ڽ��ϴ�.\n", b, 4 * b, 6 * b);
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
			printf("%d. %d X %d = ", i + 1, x, y);
			scanf("%d", &answer);
			if (answer == x * y)
			{
				printf("�����Դϴ�.\n");
				count++;
			}
			else
			{
				printf("�����Դϴ�. ������ %d�Դϴ�.\n", x * y);
			}
		}


		printf("�� %d���� ���߼̽��ϴ�. ���޵� �ݾ��� %d���Դϴ�.\n", count, 2 * count * b);
		money = 2 * count * b;
	}
	else if (a == 3)
	{
		printf("�� ���ӿ� �󸶸� �����ðڽ��ϱ�?\n");
		scanf("%d", &b);
		printf("������ �����մϴ�.\n");
		printf("������ �ϳ��� �� ���߽Ŵٸ� 0��, 1���� ���߽Ŵٸ� %d��, 2���� ���߽Ŵٸ� %d��, ��� ���߽Ŵٸ� %d���� �帮�ڽ��ϴ�.\n", b, 6 * b, 9 * b);
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
			z = rand() % 100 + 1;
			printf("%d. (%d + %d) X %d = ", i + 1, x, y, z);
			scanf("%d", &answer);
			if (answer == (x + y) * z)
			{
				printf("�����Դϴ�.\n");
				count++;
			}
			else
			{
				printf("�����Դϴ�. ������ %d�Դϴ�.\n", (x + y) * z);
			}
		}
		printf("�� %d���� ���߼̽��ϴ�. ���޵� �ݾ��� %d���Դϴ�.\n", count, 3 * count * b);
		money = 3 * count * b;
	}
	else
	{
		printf("�Է��Ͻ� ���̵��� ���� ���̵��Դϴ�.");
		return 0;
	}

	// 4. ���� �� ������ ��ǰ ǰ�� ��ȣ �Է�
	printf("�����ϼ̽��ϴ�. ��� ������ �� �����̽��ϴ�.\n");
	printf("������ �ݾ����� � ��ǰ�� �����Ͻðڽ��ϱ�?\n");
	printf("1. ��-%d��\n2. ����-%d��\n3. ���찳-%d��\n4. ���콺-%d��\n", m, n, k, l);
	scanf("%d", &c);
	if (c == 1)
	{
		if (money >= m)
		{
			printf("���Ű� �����մϴ�. ���� �ݾ��� %d���Դϴ�.\n", money - m);
		}
		else
		{
			printf("�����Ͻ� �� �����ϴ�.\n");
		}
	}
	else if (c == 2)
	{
		if (money >= n)
		{
			printf("���Ű� �����մϴ�. ���� �ݾ��� %d���Դϴ�.\n", money - n);
		}
		else
		{
			printf("�����Ͻ� �� �����ϴ�.\n");
		}
	}
	else if (c == 3)
	{
		if (money >= k)
		{
			printf("���Ű� �����մϴ�. ���� �ݾ��� %d���Դϴ�.", money - k);
		}
		else
		{
			printf("�����Ͻ� �� �����ϴ�.\n");
		}
	}
	else if (c == 4)
	{
		if (money >= l)
		{
			printf("���Ű� �����մϴ�. ���� �ݾ��� %d���Դϴ�.\n", money - l);
		}
		else
		{
			printf("�����Ͻ� �� �����ϴ�.\n");
		}
	}
	else
	{
		printf("�ش����� �ʴ� ��ȣ�Դϴ�.\n");
	}
}