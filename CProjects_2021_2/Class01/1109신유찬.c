#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void graph(int* num[100]);//�׷��� �׸���
void calculator(int Calcul[60][60], int Calcul2[60][60], int num2);// ��� ����
void game();// ���� â ���
void gotoxy(int x, int y);//Ŀ�� ��ġ �̵�

void stat() {//������ ���
	for (int i = 20; i <= 70; i++) {
		for (int j = 5; j <= 20; j++) {
			if (i == 20 || i == 70 || j == 5 || j == 20) {
				gotoxy(i, j);
				printf("@");
			}
		}
	}
}

void start() {// ����ȭ�� ���
	printf("                                         ##                                              \n");

	printf("  #####    ####    ##        #####   ##  ##   ##        ####    ######    ####    #####   \n");

	printf(" ##  ##   ##  ##   ##       ##  ##   ##  ##   ##       ##  ##     ##     ##  ##   ##  ##  \n");


	printf(" ##       ######   ##       ##       ##  ##   ##       ######     ##     ##  ##   ##  ##  \n");


	printf(" ##       ##  ##   ##       ##       ##  ##   ##       ##  ##     ##     ##  ##   #####   \n");

	printf("  ######  ##  ##   ######    ######   ####    ######   ##  ##     ##      ####    ##  ##  \n");

	printf("              #                                            #       #                      \n");

}
int main() {
	int arr[100] = { 0, };// �׷����� ����� ���� ����
	int num[100] = { 0, };// �׷����� ����� ���ڸ� �Լ��� �ѱ�
	int n; // ������� �׷��� �׸���
	int Calcul[60][60] = { 0, };// ��� 1 �Է�
	int Calcul2[60][60] = { 0, };// ��� 2 �Է�
	int num2 = 0;//���簢����� ũ��

	while (1) { // �Էµ� ������ ���ѹݺ�

		// ����ȭ��, �� �� ����(1=�׷��� �׸���, 2=��� ���� , 3=�̴� ����)
		if (kbhit()) {

			char hi;
			hi = getch();
			switch (hi) {
			case '1':
				goto GRAPH;
				break;
			case '2':
				goto CALCUL;
				break;
			case '3':
				goto GAME;
			}

		}
		gotoxy(1, 1);
		start();
		gotoxy(1, 14);
		printf("������ ���Ͻô� ���α׷��� ��ȣ�� ��������");
		gotoxy(1, 16);
		printf("1.�׷��� �׸���");
		gotoxy(1, 18);
		printf("2.��� ����ϱ�");
		gotoxy(1, 20);
		printf("3.�̴ϰ���");





	}
GRAPH:// 1���� ������ �� ������ ���� �Է¹ް� graph�Լ� ����
	system("cls");
	printf("������ ������ �Է����ּ���\n");
	scanf("%d", &n);
	printf("���ڸ� �Է��� �ּ��� : ");
	printf("\n***�� ������ �󵵰� 50���� ���� �ʰ� �� ��***\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		num[arr[i] - 1]++;
	}
	graph(&num);
CALCUL://2���� ������ �� ����� ũ��� ��� 2���� �Է¹ް� calculator�Լ� ����
	system("cls");
	printf("����� ũ�⸦ �Է����ּ���\n");
	scanf("%d", &num2);
	system("cls");
	printf("ù ��° ����� �Է��ϼ���\n");
	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < num2; j++) {
			scanf("%d", &Calcul[i][j]);
		}
	}
	system("cls");
	printf("�� ��° ����� �Է��ϼ���\n");
	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < num2; j++) {
			scanf("%d", &Calcul2[i][j]);
		}
	}
	calculator(Calcul, Calcul2, num2);
	return 0;

GAME://3���� ������ �� game �Լ��� ����
	system("cls");
	game();
}

void gotoxy(int x, int y)//Ŀ�� ��ġ �̵� �Լ�

{

	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void graph(int* num[100]) {//graph�� �׷��ִ� �Լ�(gotoxy�̿�)
	while (1) {
		gotoxy(1, 1);
		for (int i = 0; i < 51; i++) {
			gotoxy(1, i);
			if (i == 0) {
				printf("Y");
			}
			else if (i % 2 == 0) {
				printf("%d", 50 - i);
			}
			else if (i == 50) {
				printf("����");
			}
			else
				printf("|");
		}
		for (int j = 1; j < 205; j++) {
			gotoxy(j, 50);
			if (j == 1) {
				printf("-");
			}
			if (j == 204) {
				printf("X");
			}
			else if ((j - 1) % 2 == 0) {
				if ((j - 1) % 20 == 0) {
					printf("%d", ((j - 1) / 20) - 1);
				}
				else
					printf("%d", ((j - 1) / 20));
				gotoxy(j + 2, 51);
				printf("%d", ((j - 1) / 2) % 10);
				if (j == 203) {
					gotoxy(j, 52);
					printf("0");
				}
			}
			else
				printf("-");
		}
		for (int i = 0; i < 100; i++) {
			int k = *(num + i);
			gotoxy((2 * i) + 5, 50 - k);
			if (k == 0) {

			}
			else

				printf("#");

		}
		// �׷��� �ȳ�
		gotoxy(210, 0);
		printf("x=����  ,  y=�󵵼�(��)");
		gotoxy(210, 1);
		printf("#=(x,y)");
		system("cls");
	}
}

void calculator(int Calcul[60][60], int Calcul2[60][60], int num2) { // ��� ��� �Է¹ް� ��� ����
	system("cls");
	char howto;
	while (1) { // ��� ��� ����
		rewind(stdin);
		printf("����� ��� ����� �������ּ���\n");
		printf("1.����\n2.����\n3.����\n");
		if (kbhit()) {
			howto = getch();
			break;
		}
		system("cls");
	}
	if (howto == '1') {//1������ �� ���� ����
		system("cls");
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				int t = *(Calcul[i] + j);
				int k = *(Calcul2[i] + j);
				*(Calcul[i] + j) = k + t;
			}
		}
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				printf("%d ", *(Calcul[i] + j));
			}
			printf("\n");
		}
	}
	if (howto == '2') {//2 ������ �� ���� ����
		system("cls");
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				int t = *(Calcul[i] + j);
				int k = *(Calcul2[i] + j);
				*(Calcul[i] + j) = t - k;
			}
		}
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				printf("%d ", *(Calcul[i] + j));
			}
			printf("\n");
		}
	}
	int gop[60][60] = { 0, }; // ������ ��� ��� ����
	if (howto == '3') {//3 ������ �� ���� ����

		int x;
		for (int i = 0; i < num2; i++)
		{
			for (int j = 0; j < num2; j++)
			{
				int x = 0;
				for (int k = 0; k < num2; k++)
				{
					x += Calcul[i][k] * Calcul2[k][j];
				}
				printf("%d ", x);
			}
			printf("\n");
		}
	}

}


void game() {//game�� ����
	int starttime = clock();//���۽ð�
	int init = clock();//�ð�

	int point = 0;
	char hi = 0;
	int x = 0, y = 0;
	int flag = 2;//����(�����¿�)
	gotoxy(21, 6);
	srand(time(NULL));
	int a;
A://������ġ
	a = rand() % 100 + 1;
	if (a < 21 || a>69) {
		goto A;
	}
	int b;
B://������ġ
	b = rand() % 100 + 1;
	if (b < 6 || b>19) {
		goto B;
	}


	while (1) {// ĳ���� �����̱�
		if (x < 20 || x>70 || y < 5 || y>20) {//������ ����� �� ����
			x = 21;
			y = 6;
		}

		if (x == a && y == b) {//������ �Ծ��� �� ���� �ø�
			point++;
			goto A;



		}

		if (point == 5) {//���� ���� ���� -> ���� 5��
			system("cls");
			printf("%d�ʸ��� �����ϼ̽��ϴ�!!!", (init / 1000) - (starttime / 1000));
			return 0;
		}
		gotoxy(0, 0);
		printf("���� : %d��\n", point);
		printf("%d��\n", (init / 1000) - (starttime / 1000));
		gotoxy(a, b);
		printf("��");
		system("cls");
		gotoxy(x, y);
		printf("��");
		stat();
		if (flag == 1) {//�ӵ� ����
			if (clock() - init > 30) {
				x--;
				init = clock();
			}
		}
		if (flag == 2) {
			if (clock() - init > 30) {
				x++;
				init = clock();
			}
		}
		if (flag == 3) {
			if (clock() - init > 50) {
				y--;
				init = clock();
			}
		}
		if (flag == 4) {
			if (clock() - init > 50) {
				y++;
				init = clock();
			}
		}
		if (_kbhit()) {//���� ����
			hi = _getch();
			switch (hi) {

			case 'a':
				flag = 1;
				break;

			case 'd':
				flag = 2;
				break;

			case 'w':
				flag = 3;
				break;

			case 's':
				flag = 4;
				break;

			case 'z':
				return 0;
			}



		}
	}

}

