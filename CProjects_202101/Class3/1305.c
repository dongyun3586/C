#include <stdio.h>

void ProcessOfPurchasing(int a);
void ProcessOfCalculating();
void	ProcessOfSaving();


long long int price, a = 0;

int main()
{

	while (price <= 30000)
	{
		printf("�ȳ��ϼ���. ���ְ��а� �����Դϴ�. ���Ÿ� ���Ѵٸ� 1, ��Ҹ� ���Ѵٸ� 2�� �����ּ���\n");
		scanf_s("%ld", &a);
		ProcessOfPurchasing(a);
		if (a == 1)
		{

			ProcessOfCalculating();
			ProcessOfSaving();
		}

	}




	return 0;
}




void ProcessOfPurchasing(int a)
{
	long long int  b = 0, c = 0, d = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, count1 = 0, count2 = 0, count3 = 0, m = 0;



	if (a == 1)
	{

		printf("�����ϰ� ���� ������ ������ �Է��ϼ���.\n");
		printf("1. ���̽�ũ��  2. ����\n");
		scanf_s("%ld", &b);

		if (b == 1)
		{
			printf("���̽�ũ���� 3������ �ֽ��ϴ�.\n�����ϼ���.");
			printf("1. ������̽�ũ��(800��) 2. �ܾ��̽�ũ��(1200��) 3. ��Ÿ(1500��)\n");
			scanf_s("%ld", &c);

			if (c == 1)
			{
				printf("������̽�ũ���� �����ϼ̽��ϴ�.\n��� �����Ͻ� �ǰ���? ");
				scanf_s("%ld", &cnt1);
				price += (800 * cnt1);
			}

			if (c == 2)
			{
				printf("�ܾ��̽�ũ���� �����ϼ̽��ϴ�.\n��� �����Ͻ� �ǰ���? ");
				scanf_s("%ld", &cnt2);
				price += (1200 * cnt2);
			}

			if (c == 3)
			{
				printf("��Ÿ���� ��, ��Ű��, �ؾ�θ��ڰ� �ֽ��ϴ�.\n��� �����Ͻ� �ǰ���? ");
				scanf_s("%ld", &cnt3);
				price += (1500 * cnt3);
			}

		}
		if (b == 2)
		{
			printf("���ῡ�� 3���� ������ �ֽ��ϴ�.\n�����ϼ���");
			printf("1. ĵ����(800��) 2. ������(1200��) 3. ��Ʈ������(1500��)\n");
			scanf_s("%ld", &d);

			if (d == 1)
			{
				printf("ĵ���Ḧ �����ϼ̽��ϴ�.\n��� �����Ͻ� �ǰ���?");
				scanf_s("%ld", &count1);
				price += (800 * count1);
			}

			if (d == 2)
			{
				printf("�����Ḧ �����ϼ̽��ϴ�.\n��� �����Ͻ� �ǰ���?");
				scanf_s("%ld", &count2);
				price += (1200 * count2);
			}

			if (d == 3)
			{
				printf("��Ʈ�����Ḧ �����ϼ̽��ϴ�.\n��� �����Ͻ� �ǰ���?");
				scanf_s("%ld", &count3);
				price += (1500 * count3);
			}
		}

	}

	else
	{
		printf("�����մϴ�. �� ������.\n");
	}

}

void ProcessOfCalculating()
{
	int pay = 0, money;

	printf_s("�� ������ %d�� �Դϴ�. \n", price);
	printf("�󸶸� ���� �ǰ���? ");
	scanf_s("%ld", &pay);

	money = pay - price;

	printf("�Ž������� %d���Դϴ�.\n\n", money);

	printf("10000�� %d��\n\n", money / 10000);

	money = money % 10000;

	printf("5õ�� %d��\n\n", money / 5000);

	money = money % 5000;

	printf("1000�� %d��\n\n", money / 1000);

	money = money % 1000;

	printf("500�� %d��\n\n", money / 500);

	money = money % 500;

	printf("100�� %d��\n\n", money / 100);


}


void	ProcessOfSaving()
{
	int a = 0, n = 0, savingprice;

	printf("������ �� ��ȣ�� ������ ��ó���? �ִٸ� 1, ���ٸ� 0�� �����ּ���.\n");
	scanf_s("%ld", &a);

	if (a == 1)
	{
		printf("��ȣ�� �����ּ���. ");
		scanf_s("%ld", &n);
		savingprice = price / 10;
		printf("\n%d�� �����Ǽ̽��ϴ�. �ǿ�����.\n\n", savingprice);
	}

	if (a == 0)
	{
		printf("������ ��ȣ�� ������ּ���. ������ ��ȣ�� �� �б޿��� �ο��� ��ȣ�Դϴ�. ex --> 21ooo");
	}

}

