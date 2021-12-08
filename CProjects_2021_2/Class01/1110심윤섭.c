#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MARBLE 20

void explain();//���� ����
void game();//���� ����
void printmarble(int marble, char* owner);//���� ��Ȳ ���
int betting(int mar1, int mar2);//���� ����
void check(int choose, int x, int bet, int* mar1, int* mar2, char* player);
int randommarble(int mar1, int mar2);
void end(int* mymar, int* commar);

int main()
{
	explain();
	game();
	return 0;
}

void explain()
{
	printf("�ۡ��\n");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(400);
	printf("��¡�� ����");
	Sleep(400);
	system("cls");
	printf("<������>\n");
	Sleep(1000);
	printf("���� �ָӴϸ� �ϳ��� �޾� �ֽñ� �ٶ��ϴ�.\n");
	Sleep(1000);
	printf("������ �ָӴϿ� ������ ������ ��� �ֽ��ϴ�.\n");
	Sleep(1000);
	printf("������ Ȯ���� �ּ���.\n");
	Sleep(3000);
	system("cls");
	printf("�׷����� �츮 ��κ��� �ξ����\n");
	Sleep(1500);
	printf("�����̶� ������ ���� ���� ģ�� ���̾�\n");
	Sleep(1500);
	printf("�� ��, �� �� ����\n");
	Sleep(3000);
	system("cls");
	printf("<������>\n");
	Sleep(1000);
	printf("�̹� ������ ���� �ڽ��� ������ ������\n");
	Sleep(1000);
	printf("���� �������� ���� �ִ� ¦�� ������ ����....\n");
	Sleep(3000);
	printf("�ϳ�, ���� : ????\n");
	Sleep(3000);
	printf("����� ���� �� ���� ��� ������ ����� �¸��մϴ�.\n");
	Sleep(3000);
	printf("�ϳ�, ���� : �׷�....\n");
	Sleep(1000);
	printf("�ϳ�, ���� : �츮 �� �Ѹ��� �״� �ž�.....?\n");
	Sleep(3000);
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	system("cls");
}

void game()
{
	srand(time(NULL));
	int mymar = MARBLE / 2;//�� ����
	int commar = MARBLE / 2;//��ǻ�� ����
	int choose = 0;
	while (1)
	{
		//������
		printf("<�� ����>\n\n");
		printmarble(mymar, "��");
		printmarble(commar, "����");
		int bet = betting(mymar, commar);//���� ������ ����
		int x = rand() % (commar + 1);//Ȧ¦ �� ���� ���� 0~���� ����
		Sleep(1000);
		printf("\n���� �տ� �ִ� ������ Ȧ������ ¦������ ���߼���\n");
		Sleep(1000);
		printf("Ȧ���� 1, ¦���� 0�� �Է��ϼ���\n");
		scanf("%d", &choose);
		while (choose != 1 && choose != 0)
		{
			printf("�ٽ� �Է��ϼ���\n");
			scanf("%d", &choose);
		}
		Sleep(2000);
		printmarble(x, "���� �տ� �ִ�");
		check(choose, x, bet, &mymar, &commar, "");
		Sleep(3000);
		system("cls");
		if (mymar == 0 || commar <= 1)//��������
			break;
		//��� ����
		printf("<��� ����>\n\n");
		printmarble(mymar, "��");
		printmarble(commar, "����");
		printf("�տ� ��� ������ ������ �Է��ϼ���\n");
		scanf("%d", &x);
		printmarble(x, "�� �տ� �ִ�");
		Sleep(2000);
		bet = randommarble(mymar, commar);//���� ����
		choose = rand() % 2;
		if (choose % 2 == 1)
			printf("������ Ȧ�� �����ϼ̽��ϴ�.\n\n");
		else
			printf("������ ¦�� �����ϼ̽��ϴ�.\n\n");
		Sleep(1000);
		check(choose, x, bet, &commar, &mymar, "������ ");
		Sleep(1000);
		printf("������ %d���� �����ϼ̽��ϴ�.\n", bet);
		Sleep(3000);
		system("cls");
		if (mymar == 0 || commar <= 1)//��������
			break;
	}
	end(&mymar, &commar);
}

void printmarble(int marble, char* owner)
{
	printf("%s ����\n", owner);
	for (int i = 1; i <= marble; i++)
		printf("�� ");
	if (marble == 0)
		printf("X");
	printf("\n\n");
}

int betting(int mar1, int mar2)
{
	int bet = 0;
	printf("������ ������ ������ �Է��ϼ���\n");
	scanf("%d", &bet);
	while (bet > mar1 || bet > mar2)
	{
		printf("������ ������ �ʹ� �����ϴ�. �ٽ� �Է��ϼ���.\n");
		scanf("%d", &bet);
	}
	return bet;
}

void check(int choose, int x, int bet, int* mar1, int* mar2, char* player)
{
	Sleep(1000);
	if (x % 2 == 1)
		printf("����� Ȧ �Դϴ�.\n");
	else
		printf("����� ¦ �Դϴ�.\n");
	Sleep(1000);
	if (choose == x % 2)
	{
		printf("%s���߼̽��ϴ�.\n", player);
		(*mar1) += bet;
		(*mar2) -= bet;
	}
	else
	{
		printf("%sƲ���̽��ϴ�.\n", player);
		(*mar1) -= bet;
		(*mar2) += bet;
	}
}

int randommarble(int mar1, int mar2)
{
	srand(time(NULL));
	int min;
	if (mar1 < mar2)
		min = mar1;
	else
		min = mar2;
	return rand() % (min + 1);
}

void end(int* mymar, int* commar)
{
	system("cls");
	int temp;
	if (*mymar == 0)
	{
		printf("�츮�� ����ݾ�.....");
		Sleep(1500);
		printf("���п� ��ſ���\n");
		Sleep(1500);
		printf("�ڳװ� ���� ���� �ö󰡰�...\n");
		Sleep(1500);
		printf("�� ����....");
		Sleep(1500);
		printf("�ڳװ� ����\n\n");
		Sleep(3000);
		temp = *mymar;
		*mymar = *commar;
		*commar = temp;
	}
	else if (*commar <= 1)
	{
		printf("�츮�� ����ݾ�.....");
		Sleep(1500);
		printf("���п� ��ſ���\n");
		Sleep(1500);
		printf("���� ����....");
		Sleep(1500);
		printf("�ڳװ� ����\n\n");
		Sleep(3000);
		*mymar = MARBLE;
		*commar = 0;
	}
	printf("���� ���\n");
	printmarble(*mymar, "��");
	printmarble(*commar, "����");
	Sleep(1000);
	printf("\n456�� ���� ���� ����\n");
	Sleep(3000);
	system("cls");
	printf("��ŵ� ���ӿ� �����Ͻðڽ��ϱ�?\n");
	Sleep(3000);
	system("cls");
	printf("�ۡ��\n010-7288-4122\n");
}