#include<stdio.h>
#include<string.h>
int main()
{
	int money;
	printf("���� ����� ������ �ִ� �ݾ��� �Է��Ͻÿ�:");
	scanf_s("%d", &money);
	printf("<ġŲ��>\n");
	char* chicken[6] = { "[1 ���� �����߳�]", "[2 ���� ���]", "[3 ���� �����̵�]", "[4 ���� ����]", "[5 �ϸ� ���Ұ���]", "[6 �ϸ� ����]" }; //ġŲ�� ��ȣ�� �̸��� �����ϴ� ������ �迭
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", chicken[i]);
		printf("3000��\n");
	}
	for (int i = 4; i < 6; i++)
	{
		printf("%s ", chicken[i]);
		printf("4000��\n");
	} //ġŲ�� �̸��� ������ ���
	printf("[7 �� �̻� ���� �� ��]\n");
	int chickennum;
	int chickenbuy[10] = { 0 }; //������ ������ ���� ������ ġŲ�� ��ȣ�� �����ϴ� �Լ�. ù ��° ������ ġŲ�� ���� ���Ķ�� chickenbuy[0]=4�� ��.
	if (money >= 3000)
	{
		for (int i = 0; i < 10; i++)
		{
			printf("�����ϰ� ���� ġŲ�� ��ȣ�� �Է��Ͻÿ�:");
			scanf_s("%d", &chickennum);
			if (chickennum == 1 || chickennum == 2 || chickennum == 3 || chickennum == 4)
			{
				money = money - 3000;
				chickenbuy[i] = chickennum;
			}
			if (chickennum == 5 || chickennum == 6)
			{
				money = money - 4000;
				chickenbuy[i] = chickennum;
			}
			if (chickennum == 7 || money < 3000)break;
		}
	}//�����ϰ� ���� ġŲ�� ��ȣ�� �Է��ϸ� chickenbuy�� �̸� ����
	printf("<���̽�ũ����>\n");
	char* icecream[5] = { "[1 ������]", "[2 ������]", "[3 �举��]", "[4 �޷γ�]", "[5 ������]" }; //���̽�ũ���� ��ȣ�� �̸��� �����ϴ� ������ �迭
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", icecream[i]);
		printf("1200�� \n");
	}
	for (int i = 3; i < 5; i++)
	{
		printf("%s", icecream[i]);
		printf("800�� \n");
	}//���̽�ũ���� �̸��� ������ ���

	printf("[6 �� �̻� ���� �� ��]\n");
	int j = 0;
	int icecreambuy[10] = { 0 };
	while (j == 0)
	{
		int icecreamnum;

		printf("�����ϰ� ���� ���̽�ũ���� ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%d", &icecreamnum);
		switch (icecreamnum)
		{
		case 1:
			icecreambuy[0]++;
			money = money - 1200;
			break;
		case 2:
			icecreambuy[1]++;
			money = money - 1200;
			break;
		case 3:
			icecreambuy[2]++;
			money = money - 1200;
			break;
		case 4:
			icecreambuy[3]++;
			money = money - 800;
			break;
		case 5:
			icecreambuy[4]++;
			money = money - 800;
			break;
		case 6:
			j = 1;
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�\n");
			break;
		}
	}//ġŲ���� �ٸ� ��Ŀ����. 1�� ���̽�ũ���� ������ Ƚ���� icecreambuy[0]�� �����.

	printf("<������>\n");
	int i = 1;
	int candynum;
	int candybuy[10] = { 0 };

	char* candy[5] = { "[1 ������]", "[2 ���޴���]", "[3 ���̹���]", "[4 �ϸ���]" }; //ĵ���� ��ȣ�� �̸��� �����ϴ� ������ �迭
	printf("%s ", candy[0]);
	printf("800�� \n");
	printf("%s", candy[1]);
	printf("600�� \n");
	for (int i = 2; i < 4; i++)
	{
		printf("%s", candy[i]);
		printf("200�� \n");
	}//ĵ���� �̸��� ������ ���
	printf("[5 �� �̻� ���� �� ��]\n");
	while (i == 1)
	{
		printf("�����ϰ� ���� ������ ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%d", &candynum);
		switch (candynum)
		{
		case 1:
			candybuy[0]++;
			money = money - 800;
			break;
		case 2:
			candybuy[1]++;
			money = money - 600;
			break;
		case 3:
			candybuy[2]++;
			money = money - 200;
			break;
		case 4:
			candybuy[3]++;
			money = money - 200;
			break;
		case 5:
			i = 0;
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�\n");
			break;
		}
	}//������ ĵ���� ������ ���ŵ� Ƚ���� candybuy�迭�� ����
	printf("<������>\n"); //������ ���
	printrecipe(chickenbuy, icecreambuy, candybuy, chicken, icecream, candy);
	printf("����� ġŲ���� %dĮ�θ�, ���̽�ũ������ %dĮ�θ�, ĵ��� %d Į�θ��� �����Ͽ� �� %d Į�θ��� �����ϼ̽��ϴ�\n", calculatechicken(chickenbuy), calculateicecream(icecreambuy), calculatecandy(candybuy), calculatechicken(chickenbuy) + calculateicecream(icecreambuy) + calculatecandy(candybuy));
	printf("���� ���� %d�� �Դϴ�", money);
}
int calculatechicken(int* chickenbuy)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (chickenbuy[i] == 1)count1++;
		if (chickenbuy[i] == 2)count2++;
		if (chickenbuy[i] == 3)count3++;
		if (chickenbuy[i] == 4)count4++;
		if (chickenbuy[i] == 5)count5++;
		if (chickenbuy[i] == 6)count6++;
	}
	return count1 * 405 + count2 * 485 + count3 * 465 + count4 * 505 + count5 * 600 + count6 * 600;
}//������ ġŲ ���� ��� �Լ�
int calculateicecream(int* icecreambuy)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (icecreambuy[i] == 1)count1++;
		if (icecreambuy[i] == 2)count2++;
		if (icecreambuy[i] == 3)count3++;
		if (icecreambuy[i] == 4)count4++;
		if (icecreambuy[i] == 5)count5++;
	}
	return 265 * count1 + 255 * count2 + 240 * count3 + 165 * count4 + 120 * count5;
}//������ ���̽�ũ�� ���� ��� �Լ�
int calculatecandy(int* candybuy) {

	return 175 * candybuy[0] + 125 * candybuy[1] + 200 * candybuy[2] + 50 * candybuy[3];
}//������ ĵ�� ���� ��� �Լ�
int printrecipe(int* chickenbuy, int* icecreambuy, int* candybuy, char** chicken, char** icecream, char** candy)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (chickenbuy[i] == 1)count1++;
		if (chickenbuy[i] == 2)count2++;
		if (chickenbuy[i] == 3)count3++;
		if (chickenbuy[i] == 4)count4++;
		if (chickenbuy[i] == 5)count5++;
		if (chickenbuy[i] == 6)count6++;
	}
	int count[6] = { count1, count2, count3, count4, count5, count6 };
	for (int i = 0; i < 6; i++)
	{
		if (count[i] != 0)
		{
			printf("%s %d�� \n", chicken[i], count[i]);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (icecreambuy[i] != 0)
		{
			printf("%s %d�� \n", icecream[i], icecreambuy[i]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (candybuy[i] != 0)
		{
			printf("%s %d�� \n", candy[i], candybuy[i]);
		}
	}
	return 0;
}//������ ��� �Լ�