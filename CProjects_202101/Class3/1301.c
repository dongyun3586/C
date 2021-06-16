#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int score = 0;//����
int life = 3;//�����ִ� ���
int upx = 40, upy = 10;//�������� ��ġ
int star[20][4] = { 0 };//�� ���� ���� �迭, star[n][0]���� ���� x��ǥ, star[n][1]���� ���� y��ǥ, star[n][2]���� ���� ��µǴ��� ����, star[n][3]���� �� ���� ��µǱ� �����ϰ� ���� ���� �ð�
int dif = 5;    //���̵� ������ ����, �� ������ŭ �ֿܼ� ���� ��µ�


void gotoxy(int x, int y);  //Ŀ���� x,y�� �̵���Ű�� �Լ�
void frame();   //�׵θ��� ����ϴ� �Լ�
void eraseCursor();     //�������� ����� �Լ�
void cursor();  //�������� ����ϴ� �Լ�
void starset(int n); //n��° ��(star �迭�� n��°)�� �ٸ� ���� �ߺ����� �ʴ� ������ ��ġ�� �����ϴ� �Լ�
void pstar();   //���� ������ ��ġ�� ����ϴ� �Լ�
void shot();    //sŰ�� ������ �� ������ ��ġ�� ���� �ִ��� Ȯ���ϰ� ������ �ø��� �Լ�
void check();   //���� ��µǰ� 10���̻� �������� Ȯ���ؼ� life�� ��� �Լ�
void text();    //score�� life�� ����ϴ� �Լ�

int main() {
	srand(time(NULL));
	int key = 0;
	int t = 0;   //�ð��� �������� ���̵��� �ø��� ���� �ð��� �����ϴ� ����
	printf("***1�г� 3�� 1�� ������ C ������Ʈ***\n\n");
	printf("~�����̽� ����~\n");
	printf("����� ���ּ��� �����ϴ� �������̴�. ���ּ��� ���� ���ƿ��� ����� ��� ������.\n��� ������ �ٰ����� ������ ���ϴ� ������ ��� ���ֵ��� ����. \n�� �� �̻� ��� �ε����� �Ǹ� ������ ����ȴ�.\n\n");
	printf("���۹�� : �����¿� ȭ��ǥ ��ư���� ����, sŰ�� �߻�\n�ƹ� ��ư�̳� ������ ����");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);	//���� ���� ��µǴ� ������ ���� ������ �ٲٴ� �Լ�, ���ͳ��� �����߽��ϴ�.
	printf("\n\n���� ������ ������ ����� �ֿܼ��� ���� �����ϰ� ��µ˴ϴ�.��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	getch();    //����(char��) �ϳ��� �Է¹޴� �Լ�, Ű����� ���ڸ� �Է��ϸ� �������� �Ѿ��. ���ͳ��� �����߽��ϴ�.
	system("cls");  //�ֿܼ� ��µ� ���� ��� ����� �Լ�, ���ͳ��� �����߽��ϴ�.
	frame();
	for (int i = 0; i < dif; i++)
		starset(i);     //������ ���۵Ǹ� �⺻������ �� 5���� ��ġ�� ����
	while (1) {
		while (kbhit() == 0) {      //kbhit() Ű���尡 ���ȴ����� Ȯ���ϴ� �Լ�, Ű���� ������ ������ �� 1�� ��ȯ�Ѵ�.
			pstar();
			cursor();
			Sleep(10);      //�Ű�����(�и���)��ŭ �����ϴ� �Լ�, �� 0.01�ʾ� �����.(������ �ٸ� �ڵ���� ���� �ӵ������� ���� �����δ� �̺��� �����ɸ���.)
			for (int i = 0; i < 20; i++)
				if (star[i][2])
					star[i][3] ++;    //���� ��µǰ��ִ� ������ ��µ� �ð��� 0.01�ʿ� 1�� �ø���.()
			t++;      //0.01�ʸ��� 0.01�� �ð��� ���.
			check();        //���߿��� ��µǰ� ���� 10���̻� ���� ���� �ִ��� Ȯ���Ͽ� ���� ���ְ� life�� ��´�.
			text();         //������ ����, ���� life, ���� ���̵��� ���
			if (t >= 2000) {
				t = 0;
				if (dif < 20)
					dif++;
			}       //20�ʸ��� ���̵��� 1�� �ø���. �ְ� ���̵��� 20���� ����
			for (int i = 0; i < dif; i++)
				starset(i);         //���̵���ŭ�� ���� ��ġ�� �����Ѵ�.
			if (life <= 0)
				break;
		}
		while (1) {
			if (life <= 0)
				break;
			key = getch();  //����ڷκ��� �Է¹��� ���ڸ� key������ ����
			switch (key) {  //key ���� ���� �����¿� �̵�, Ȥ�� ������ ��ġ�� �� Ȯ�� �� ���������� �Ѵ�.
			case 72:   //�� ȭ��ǥ �Է�
				if (upy > 4) {
					eraseCursor();
					upy--;
				}
				break;
			case 75:    //���� ȭ��ǥ �Է�
				if (upx > 7) {
					eraseCursor();
					upx--;
				}
				break;
			case 77:    //������ ȭ��ǥ �Է�
				if (upx < 74) {
					eraseCursor();
					upx++;
				}
				break;
			case 80:    //�Ʒ��� ȭ��ǥ �Է�
				if (upy < 24) {
					eraseCursor();
					upy++;
				}
				break;
			case 83:    //s �Է�
			case 115:   //S �Է�
				shot();

			default:
				break;
			}
			pstar();
			cursor();
			text();
			for (int i = 0; i < dif; i++)
				starset(i);
			break;
		}
		if (life <= 0)
			break;      //����� 0������ ��� Ż��
	}
	system("cls");
	gotoxy(0, 0);
	printf("\nGAME OVER!!\n\n");
	printf("���� ���� : %d\n���� ���� ���̵�:%d\n������ �����Ϸ��� eŰ�� ��������", score, dif);      //�ֿܼ� ���� ����� ����Ѵ�.
	while (key != 'e' && key != 'E')
		key = getch();
	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//�� �Լ��� ���ͳ��� �����Ͽ� ��������ϴ�. windows.h��������� �Լ��� ����� x, y��ġ�� Ŀ���� �̵���Ű�� �Լ�


void frame() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255);
	gotoxy(4, 2);
	for (int i = 0; i < 37; i++)//���� �׵θ� ���
		printf("--");
	gotoxy(4, 26);
	for (int i = 0; i < 37; i++)//�Ʒ��� �׵θ� ���
		printf("--");
	for (int i = 3; i <= 25; i++) {
		gotoxy(4, i);//���� �׵θ� ���
		printf("--");
		gotoxy(76, i);//������ �׵θ� ���
		printf("--");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void text() {
	gotoxy(85, 2);
	printf("SCORE : %d", score);    //���� ������ ���
	gotoxy(85, 3);
	printf("LIFE : ");
	for (int i = 0; i < life; i++)  //���� ���� ����� 0������� ���
		printf("O ");
	gotoxy(85, 4);
	printf("DIFFICULTY : %d", dif);     //������ ���̵��� ���
}

void eraseCursor() {
	gotoxy(upx - 1, upy - 1);
	printf("   ");
	gotoxy(upx - 1, upy);
	printf(" ");
	gotoxy(upx + 1, upy);
	printf(" ");
	gotoxy(upx - 1, upy + 1);
	printf("   ");

}

void cursor() {
	gotoxy(upx - 1, upy - 1);
	printf("%c%c%c", 1, 22, 2);
	gotoxy(upx - 1, upy);
	printf("%c", 25);
	gotoxy(upx + 1, upy);
	printf("%c", 23);
	gotoxy(upx - 1, upy + 1);
	printf("%c%c%c", 3, 21, 4);
}

void starset(int n) {
	if (star[n][2] == 0) {
		star[n][0] = rand() % 68 + 7;   //�������� �̵������� x������ ���� x��ǥ�� ����
		star[n][1] = rand() % 21 + 4;   // �������� �̵������� y������ ���� y��ǥ�� ����
		star[n][2] = 1;
		for (int i = 0; i < 20; i++) {
			if (star[i][0] == star[n][0] && star[i][1] == star[n][1])
				starset(n);     //Ȥ�� ���� ��ġ�� ������ �� ��ġ�� ��ġ�� ��� �� ��ġ ���� �Լ��� ��ȣ��
		}
	}
}


void pstar() {
	for (int i = 0; i < 20; i++) {
		if (star[i][2]) {       //���� �ش� ��ȣ�� ���� ��µǴ��� Ȯ��
			gotoxy(star[i][0], star[i][1]);
			if (star[i][3] >= 800)        //�ش� ���� ��µǰ� 8���̻� ������� ���������� ���
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("*");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
}

void shot() {
	for (int i = 0; i < 20; i++) {
		if (star[i][0] == upx && star[i][1] == upy) {       //���� ������ ��ġ�� ��ġ�ϴ� ���� �ִ��� Ȯ��
			gotoxy(upx, upy);
			printf(" ");
			score++;            //���� ����� ������ �ø�
			star[i][0] = 0;
			star[i][1] = 0;
			star[i][2] = 0;
			star[i][3] = 0;        //�ش� ���� �����ؼ� �������ִ� ������ �ʱ�ȭ
			starset(i);             //�ش� ���� ��ġ�� �ٽ� �����ϰ� ����
		}
	}
}

void check() {
	for (int i = 0; i < 20; i++)
		if (star[i][2])         //���� ��µǴ� ���� ���� Ȯ��
			if (star[i][3] >= 1000) {     //��µǰ��� 10���̻� ���� ���� Ȯ��
				gotoxy(star[i][0], star[i][1]);
				printf(" ");            //���� ����
				gotoxy(90 + 2 * life, 3);
				printf("  ");
				life = life - 1;        //�����ִ� life�� �Ѱ� ����
				star[i][0] = 0;
				star[i][1] = 0;
				star[i][2] = 0;
				star[i][3] = 0;        //�ش� ���� �����ؼ� �������ִ� ������ �ʱ�ȭ
				starset(i);            //�ش� ���� ��ġ�� �ٽ� �����ϰ� ����
			}
}
