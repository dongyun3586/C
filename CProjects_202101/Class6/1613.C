//Ŭ���� �ϵ��� �Ϸ��� �ܼ�â���� ���� â�� ��Ŭ���ϰ� �ɼǿ��� ���� ���� ���� ���� ��带 �������ݴϴ�.
//�׸��� ���ڵ��� ���콺 Ŭ������ �����Ҷ� ���콺�� ����ä�� �ٸ� ��ǥ�� �Ѿ�� �ٷ� ���ο� Ŭ������ �νĵǾ ������ �����Ͽ� Ŭ�����ּ���!

#include<stdio.h>
#include<windows.h>
#include<math.h>
#define c1	7		//�� ���ڸ� ���ļ� ���ڻ��� �ٲܼ� �ֽ��ϴ�.
#define c2 0 //�� ���ڸ� ���ļ� ������ ������ �ֽ��ϴ�.

INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

INPUT_RECORD rec;
DWORD        dwNOER;

HANDLE COUT = 0;    // �ܼ� ��� ��ġ
	   // �ܼ� �Է� ��ġ

float sol(float a, float b, int c);//�Է��Ѱ���� ������ִ� �Լ�
void unzero();//�������� 0���϶� �����ϴ� �Լ�
void unone(int n);//�������� 1���϶� �����ϴ� �Լ�
void display();//�ʱ� ȭ����� �Լ�
void xy();//���α׷����� �Ҷ� ��ǥ�� �˱� ���� ��ǥ���� ���� �Լ�(�����Ҷ� ���)
void number(int a, int b, int c);//�ش��ϴ� ���ڸ� �ش� ��ǥ�� ����ϴ� �Լ�
int unknown(int x, int y);//���������� ����� �Լ�
int numbers(int a, int b, int c);//10 �̻��� ���ڸ� ����ϴ� �Լ��� ������ ��°���
int many(int x, int y); //������ ��������� ����� �Լ�
float numpad(); //����Ű���带 ȭ�鿡 ���� ���ڸ� �Է¹޴� �Լ�
int error(); //������ �� ��� ��� ȭ���� ����� �������� �˷��ִ� �Լ�
float numpad2(); //���꿡�� �����ڸ� �Է¹޴� �Լ�
void snum(int a, int x, int y); //�����ڸ� ����ϴ� �Լ�
int OXpad(); //����� ���� ������ ����� ��ɿ��� OX�� �Է¹޴� �Լ�
void OX(int a, int x, int y); //ȭ�鿡 OX�� ���� �Լ�


void gotoxy(int x, int y);//Ŀ���� ��ǥ�� �ش��ϴ� ��ġ�� �̵���Ű�� �Լ�
void color(int a, int b);//������ ���� ������ �ٲٴ� �Լ�
int be_input();
int get_input(WORD* vkey, COORD* pos);
void click(int* x, int* y);// �� �Լ����� Ŭ���� �ϰ� ��ǥ�� ������ �Լ��� ���ͳݿ��� �����Խ��ϴ�.


int main() {

	display(); //ȭ���� ����

	int un = unknown(38, 20); //������ ������ �����
	switch (un) {
	case 0: unzero(); //0���� ���
		break;
	default: unone(un);
		break;
	}
	return 0;


}

void display() {

	system("mode con cols=2000 lines=1080");
	color(c1, c2);
	for (int i = 0; i < 119; i++)
		printf("��");
	printf("\n");
	for (int i = 0; i < 119; i++)
		printf("��");
	for (int i = 0; i < 61; i++) {
		printf("\n���");
		printf("  ");
		for (int i = 0; i < 114; i++)
			printf("  ");
		printf("���");
	}
	printf("\n");
	for (int i = 0; i < 119; i++)
		printf("��");
	printf("\n");
	for (int i = 0; i < 119; i++)
		printf("��");
	gotoxy(0, 51);
	for (int i = 0; i < 119; i++)
		printf("��");
	gotoxy(0, 50);
	for (int i = 0; i < 119; i++)
		printf("��");
	//�̷��� �ݺ������� ��ǥ�� ��ġ�� �׸� ����Ͽ� ������ �⺻���� Ʋ�� ����Ѵ�

}

void gotoxy(int x, int y) {
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//xy���� �޾Ƽ� �� ��ġ�� Ŀ���� �����̴� �Լ�
}

void color(int a, int b) {
	int i = a + b * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i); //a�� ������ �����̰� b�� �������� ���ͳݿ� �ִ� ���� ǥ�� ���� �Է��ѵ� �����ϸ� �� �Լ� ���� ���ڵ��� ���� ���մϴ�.
}

void xy() {
	system("mode con cols=240 lines=1080");
	gotoxy(0, 0);
	int a;
	for (int i = 0; i < 118; i++) {
		color(i % 15 + 1, 0);
		a = i % 100;
		printf("%2d", a);
	}
	for (int i = 1; i < 65; i++) {
		color(i % 15 + 1, 0);
		a = i % 100;
		printf("\n%2d", a);
	}//���鶧 xy��ǥ�� �������⿣ �ʹ� ���Ƽ� xy��ǥ�� �ٷ� �˼� �ֵ��� ���� �����Ҷ��� ����ϴ� �Լ��Դϴ�
}

void number(int a, int b, int c) {
	switch (a) {//a�� ����� �Լ��� �ް� b�� c�� ���� xy���� �޾Ƽ� �� ��ġ�� a�� ����Ѵ�.
	case 0:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("��  ��");
		gotoxy(b, c + 3);
		printf("��  ��");
		gotoxy(b, c + 4);
		printf("����");
		break;

	case 1:
		gotoxy(b, c);
		printf("  ��  ");
		gotoxy(b, c + 1);
		printf("  ��  ");
		gotoxy(b, c + 2);
		printf("  ��  ");
		gotoxy(b, c + 3);
		printf("  ��  ");
		gotoxy(b, c + 4);
		printf("  ��  ");
		break;

	case 2:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("    ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("��    ");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 3:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("    ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 4:
		gotoxy(b, c);
		printf("��  ��");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("    ��");
		break;
	case 5:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��    ");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 6:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��    ");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("��  ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 7:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("��  ��");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("    ��");
		break;
	case 8:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("��  ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	case 9:
		gotoxy(b, c);
		printf("����");
		gotoxy(b, c + 1);
		printf("��  ��");
		gotoxy(b, c + 2);
		printf("����");
		gotoxy(b, c + 3);
		printf("    ��");
		gotoxy(b, c + 4);
		printf("����");
		break;
	}
}

float sol(float a, float b, int c) {//a�� ����� ù��° ��, b�� ����� 2��° ���� �Է� �ް� ������ ���� �ƽ�Ű�ڵ� ������ �޾� ����ϰ� �� ���� ��ȯ�Ѵ�
	switch (c) {
	case '+': a += b;
		break;
	case '-': a -= b;
		break;
	case '*': a *= b;
		break;
	case '/':a = a / b;
		break;
	case '^': a = (float)pow(a, b);
		break;
	case '!': a = (float)pow(a, 1 / b);
		break;
	}
	return a;
}

void unzero() {
	int num;
	num = many(39, 20);//������ ��� ���� ����� �� ���� num�� �����մϴ�
	gotoxy(44, 20);
	printf("�����    ��    ��    ���  ��   ����   ��");	gotoxy(44, 21);
	printf("      ��   ���   ��   ��  �� ��       �� ���");	gotoxy(44, 22);
	printf("   ��    ��    �� ��    ���  ��   ����   ��");	gotoxy(44, 23);
	printf(" ����           ��          ��   ��     ���");	gotoxy(44, 24);
	printf("   ��     �����       ��  ��    ����   ��");	gotoxy(44, 25);
	printf(" ��  ��         ��       ��  ��      ����� ");	gotoxy(44, 26);
	printf("   ��           ��       ����            �� ");// ������ �Է��϶�� ������ְ�
	int d;
	float a, b;
	a = numpad();//�������� �����Ƿ� ó�� ���� numpad�Լ��� �Է� �޾� a�� ����
	for (int i = 0; i < num; i++) {
		d = numpad2();//�����ڸ� �Է¹޾� d�� �־��ְ�
		b = numpad();//����� �ι�° ���� numpad�Լ��� �Է¹޾� b�� ����
		a = sol(a, b, d);// �տ��� �Է¹��� ������ ����Ͽ� a�� �ٽ� ����
	}// �� ������ ������ �� ������ ������ n�� �ݺ��Ѵ�.
	numbers((int)a, 20, 20);//������ ����� ���� �ش� ��ǥ�� ������ش�
	return;
}

void unone(int n) {
	int num, n2;
	num = many(32, 20);
	gotoxy(44, 20);
	printf("�����    ��    ��    ���  ��   ����   ��");	gotoxy(44, 21);
	printf("      ��   ���   ��   ��  �� ��       �� ���");	gotoxy(44, 22);
	printf("   ��    ��    �� ��    ���  ��   ����   ��");	gotoxy(44, 23);
	printf(" ����           ��          ��   ��     ���");	gotoxy(44, 24);
	printf("  ���    �����       ��  ��    ����   ��");	gotoxy(44, 25);
	printf(" ��  ��         ��       ��  ��       �����");	gotoxy(44, 26);
	printf("  ���          ��       ����             ��");//��������� unzero�� ����
	float num2[100] = { 0 };//����� ���� �Է¹��� �迭
	char what[100] = { 0 };//�����ڸ� �������� �迭
	float mis;//���������� ������ ����
	float ans2;//��� ���� ������ ����
	for (int j = 0; j < n - 1; j++) {
		what[j] = numpad2();//������ �� ���� ���� �Է¾��� �����ڸ� �޾ƾ� �ϴ� Ƚ����ŭ �ް�
		snum(what[j], 40, 40);//���� �Է¹��� ���� ��� ǥ���� �ݴϴ�.
		Sleep(500);
		gotoxy(40, 40);
		printf("          ");
		gotoxy(40, 41);
		printf("          ");
		gotoxy(40, 42);
		printf("          ");
		gotoxy(40, 43);
		printf("          ");
		gotoxy(40, 44);
		printf("          ");
		gotoxy(40, 45);
		printf("          ");

	}

	for (int i = 0; i < num; i++) {
		what[i + n - 1] = numpad2();//�����ڸ� what�迭�� i��° �ڸ��� �������ݴϴ�
		num2[i + n - 1] = numpad();//���ڸ� num2�迭�� i��° �ڸ��� �����մϴ�.
	}//����Ƚ����ŭ �ݺ��� �ݴϴ�.
	gotoxy(44, 20);
	printf("                                              ");	gotoxy(44, 21);
	printf("                                              ");	gotoxy(44, 22);
	printf("                                              ");	gotoxy(44, 23);
	printf("                                              ");	gotoxy(44, 24);
	printf("                                              ");	gotoxy(44, 25);
	printf("                                              ");	gotoxy(44, 26);
	printf("                                              ");//�����Է��̶�� ���� ȭ�鿡�� �����ݴϴ�

	int p = 0;
	number(0, 6, 4);//ù��° �������� ǥ���� �ְ�
	for (int i = 0; i < num + n - 1; i++) {
		snum(what[i], 10 + 5 * i + 4 * p, 4);
		p += numbers(num2[i], 16 + 5 * i + 4 * p, 4);//���ĵ��� ����� �ݴϴ�. �̶� ���ڰ� 2�ڸ� ���ϼ��� 3�ڸ� ���� ���� �����Ƿ� numbers���� ��ȯ�ϴ� ���� �ڸ����� �̿��Ͽ� ��ǥ�� ���� �ݴϴ�.
	}
	while (1) {
		char ans = OXpad();//�Լ� OXpad�� �̿��Ͽ� ����ڰ� O�� �����ߴ��� X�� �����ߴ��� �Է¹޾� ������ �ݴϴ�.
		if (ans == 'O') {//���� O�� ���
			gotoxy(40, 40);
			printf("                                                   "); gotoxy(40, 41);
			printf("                                                   "); gotoxy(40, 42);
			printf("                                                   "); gotoxy(40, 43);
			printf("                                                   "); gotoxy(40, 44);
			printf("                                                   "); gotoxy(40, 45);
			printf("                                                   ");//ó���� �ƴҰ�� ���ڸ��� �� ��갪�� ��µǾ����� �� �̹Ƿ� �����ݴϴ�.
			p = 0;
			mis = numpad();//������ ���� numpad�� �Է¹޽��ϴ�.
			p = numbers(mis, 8, 10);//ù��° ������ ���� ������ְ�
			int m = 0;
			for (int k = 0; k < n - 1; k++) {
				num2[k] = numpad();//���� ������������ �Է�, ������ݴϴ�.
				if (k == 0)
					m = 11;
				m += 4 + 3 * p;
				p = numbers(num2[k], m, 10);
			}
			Sleep(500);
			gotoxy(8, 10);
			printf("                                                                                                                                                                             ");
			gotoxy(8, 11);
			printf("                                                                                                                                                                             ");
			gotoxy(8, 12);
			printf("                                                                                                                                                                             ");
			gotoxy(8, 13);
			printf("                                                                                                                                                                             ");
			gotoxy(8, 14);
			printf("                                                                                                                                                                             ");//������ ������ ��µǾ��ִ°��� �����ݴϴ�.

			ans2 = mis;
			for (int i = 0; i < num + n - 1; i++) {
				ans2 = sol(ans2, num2[i], what[i]);
			}//����Ƚ����ŭ ����� �ݺ��Ͽ� �������ش�.
			numbers(ans2, 40, 40);//�� ���� ������ݴϴ�.
		}
		else if (ans == 'X')
			break;//X�� �Է��� ��� �Լ��� �������ݴϴ�.
	}
}

int unknown(int x, int y) {
	gotoxy(x, y);
	printf("            ��              ��      ��            ���            ��  ��"); gotoxy(x, y + 1);
	printf("  �����  ��  ������  ��    ��  ��        ��    ��  ������  ��"); gotoxy(x, y + 2);
	printf("  ��    ��  ��      ��      ��  ��      ��  ��      ��        ��  ����"); gotoxy(x, y + 3);
	printf("  ��    ��  ��    ��  ��    ��  ������         ��       ��    ����"); gotoxy(x, y + 4);
	printf("  �����  ��  ��      ��  ��      ��      ��            ��      ��  ��"); gotoxy(x, y + 5);
	printf("            ��              ��      ��             ��             ��  ��");//������������ ������� ����մϴ�
	int un;//������ ������ ������ ����
	while (1) {
		un = numpad();//������ ���� ����
		if (un >= 10)
			error();
		else
			break;
	}
	gotoxy(x + 24, y);
	for (int i = 0; i < 6; i++) {
		printf("        ");
		gotoxy(x + 24, y + i);//����ǥ �ڸ��� �����
	}
	number(un, x + 24, y + 1);//����ǥ �ڸ��� ���ڸ� ���
	Sleep(1000);//���ڸ� �Է¹����� ǥ���ϱ� ���� 1�� ���
	gotoxy(x, y);
	printf("                                                                        "); gotoxy(x, y + 1);
	printf("                                                                        "); gotoxy(x, y + 2);
	printf("                                                                        "); gotoxy(x, y + 3);
	printf("                                                                        "); gotoxy(x, y + 4);
	printf("                                                                        "); gotoxy(x, y + 5);
	printf("                                                                        ");
	return un;//���ڵ� �����ѵ� ������ ���� ��ȯ
}

int be_input()
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int get_input(WORD* vkey, COORD* pos)
{
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType) {
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;

			return MOUSE_EVENT;
		}
		break;

	}

	//    FlushConsoleInputBuffer(CIN);
	return 0;
}

void click(int* x, int* y) {
	DWORD mode;
	WORD key;
	COORD pos;

	int event;        // ���콺 �̺�Ʈ�� �̿�
			// ���콺�� y��ǥ �����

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���콺 Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				*x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
				*y = pos.Y;
				break;
			}
		}
	}
}

float numpad() {
	int posx, posy;
	for (int i = 1; i <= 12; i++) {
		posx = i * 9, posy = 50;
		gotoxy(posx, posy);
		for (int i = 0; i < 15; i++) {
			printf("��");
			gotoxy(posx, posy + i);
		}
		gotoxy(posx + 2, posy + 3);
		printf("            ");
		gotoxy(posx + 2, posy + 8);
		printf("            ");
		gotoxy(posx + 2, posy + 4);
		printf("            ");
		gotoxy(posx + 2, posy + 5);
		printf("            ");
		gotoxy(posx + 2, posy + 6);
		printf("            ");
		gotoxy(posx + 2, posy + 7);
		printf("            ");//�����ڰ� ��µǾ����� ���� �����Ƿ� �ʱ�ȭ
		number(i - 1, posx + 2, posy + 3);
		gotoxy(99 + 2, 50 + 3);
		printf("          ��");
		gotoxy(99 + 2, 50 + 4);
		printf("  ��      ��");
		gotoxy(99 + 2, 50 + 5);
		printf("�������");
		gotoxy(99 + 2, 50 + 6);
		printf("  ��        ");//�����ڸ��� ���� ��� ���

		gotoxy(109, 53);
		printf("      ���      ");
		gotoxy(109, 54);
		printf("   ��      ��    ");
		gotoxy(109, 55);
		printf("  ��        ��  ");
		gotoxy(109, 56);
		printf("����       �� ");
		gotoxy(109, 57);
		printf("  ��         �� ");
		gotoxy(109, 58);
		printf("            ��  ");
		gotoxy(109, 59);
		printf("    ��    ��    ");
		gotoxy(109, 60);
		printf("      ���      ");//�ʱ�ȭ �� ��ȣ ���
	}
	int num[7];
	DWORD mode;
	WORD key;
	COORD pos;
	int x;
	int y;
	int event;        // ���콺 �̺�Ʈ�� �̿�
	int n = 0;

	for (int j = 0; j < 7; j++) {
		num[j] = -1;
	}//���ڸ� �Է¹������ 

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���콺 Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
				y = pos.Y;
				for (int i = 0; i <= 9; i++) {
					if (y <= 62 && y >= 52) {
						if (x <= 35 - 18 && x >= 2) {
							return -5;//�������� �����ϸ� -5�� ��ȯ�Ѵ�
						}
						if (x <= 35 + 18 * i && x >= 20 + 18 * i) {
							gotoxy(2 + n, 49);
							num[n] = i;

							n++;
							printf("%d", i);//���ڸ� �����ϸ� �� ���ڷ� �������� �۰� ǥ��
						}

					}
				}if (y <= 62 && y >= 52) {
					if (x <= 215 && x >= 200) {
						gotoxy(2, 49);
						printf("             ");
						break;
					}//���͸� ������ ���ڸ� ǥ���Ѱ��� ����� �ݺ������� Ż���Ѵ�
				}
				if (y <= 62 && y >= 52) {
					if (x >= 218 && x <= 233) {
						gotoxy(2, 49);
						printf("             ");
						n = 0;
						for (int j = 0; j < 7; j++) {
							num[j] = -1;
						}
					}
				}//�ʱ�ȭ ��ư�� ������ ���� �ʱ�ȭ
				if (n == 7) {
					error();
					gotoxy(2, 49);
					printf("             ");
					n = 0;
					for (int j = 0; j < 7; j++) {
						num[j] = -1;
					}
				}

			}
		}

	}int a = 7; int number = 0;
	for (int i = 0; i < 7; i++) {
		if (num[i] < 0) {
			a = i - 1;
			for (int k = 0; k <= a; k++)
				number += num[k] * (int)pow(10, a - k);
			gotoxy(2, 52);
			printf("              ");
			return (float)number;
		}
	}//���� ���� �ڸ� ���ڰ� 0�ΰ�� ���ܽ�Ų��


	if (num[0] == 0) {
		if (num[1] == 0) {
			if (num[2] == 0) {
				if (num[3] == 0) {
					if (num[4] == 0) {
						if (num[5] == 0) {
							if (num[6] == 0) {
								a = 0;
							}
							a = 1;
						}
						a = 2;
					}
					a = 3;
				}
				a = 4;
			}
			a = 5;
		}
		a = 6;
	}//�ڸ����� ã�� ����
	for (int k = 0; k < a; k++) {
		number += num[6 - k] * (int)pow(10, k);
	}//���ڷ� �ٽ� ����


	gotoxy(2, 52);
	printf("              ");
	return (float)number;//��ȯ
}

int numbers(int a, int b, int c) {
	int n = 1, num, num1 = a;
	int m = 0;

	if (a < 0) {
		a = -a;
		m = 3;
		gotoxy(b, c + 2);
		printf("���  ");//������ ��� ���̳ʽ��� ����ϰ� ���ڸ� ����� �ݴϴ�.
	}
	while (1) {
		if (num1 / 10 == 0)
			break;
		else {
			num1 /= 10;
			n++;
		}
	}
	for (int i = 1; i <= n; i++) {
		num = a / (int)pow(10, n - i);
		number(num, b + 3 * i - 3 + m, c);
		a %= (int)pow(10, n - i);
	}
	return n;//number�� �̿��Ͽ� 10�̻��� ���� ����ϴ� �Լ�
}

int many(int x, int y) {
	gotoxy(x, y);
	printf("           ��       ��     ��           ��             ���                      ������   ��  ��"); gotoxy(x, y + 1);
	printf("  ���   ���     ��  ��   ��         ��  ��     ��  ��    ��                           ��    ��  ��"); gotoxy(x, y + 2);
	printf("��    ��   ��   ��      �� ����   ��      ��            ��                           ��     ����"); gotoxy(x, y + 3);
	printf("  ���   ���              ��      �������         ��                            ��      ��  ��"); gotoxy(x, y + 4);
	printf("      ��              ��   ��           ��       ��                                  ��       ��  ��"); gotoxy(x, y + 5);
	printf("      �����        ������        ��              ��                          ��        ��  ��"); gotoxy(x, y + 6);
	int un;
	gotoxy(x + 26, y + 1);
	un = numpad();
	gotoxy(x + 26, y);
	for (int i = 0; i < 7; i++) {
		printf("        ");
		gotoxy(x + 26, y + i);
	}
	numbers(un, x + 28, y + 1);
	Sleep(1000);
	gotoxy(x, y);
	printf("                                                                                                    "); gotoxy(x, y + 1);
	printf("                                                                                                    "); gotoxy(x, y + 2);
	printf("                                                                                                    "); gotoxy(x, y + 3);
	printf("                                                                                                    "); gotoxy(x, y + 4);
	printf("                                                                                                    "); gotoxy(x, y + 5);
	printf("                                                                                                    "); gotoxy(x, y + 6);
	printf("                                                                                                    ");//������ ���� ����� �Ͱ� ����մϴ�.
	return un;
}

int error() {
	int x = 49;


	for (int i = 0; i < 3; i++) {
		color(15, c2);
		gotoxy(x, 26);
		printf("���� ���� ���� ���� ����"); gotoxy(x, 27);
		printf("��     ��  �� ��  �� ��  �� ��  ��"); gotoxy(x, 28);
		printf("���� ���   ���   ��  �� ���  "); gotoxy(x, 29);
		printf("��     ��  �� ��  �� ��  �� ��  ��"); gotoxy(x, 30);
		printf("���� ��  �� ��  �� ���� ��  ��");
		Sleep(300);
		color(4, c2);
		gotoxy(x, 26);
		printf("���� ���� ���� ���� ����"); gotoxy(x, 27);
		printf("��     ��  �� ��  �� ��  �� ��  ��"); gotoxy(x, 28);
		printf("���� ���   ���   ��  �� ���  "); gotoxy(x, 29);
		printf("��     ��  �� ��  �� ��  �� ��  ��"); gotoxy(x, 30);
		printf("���� ��  �� ��  �� ���� ��  ��");//������ ����� �Ͼ���̾��ٰ� �������̵��� ������ �ݴϴ�.
		Sleep(300);

	}
	gotoxy(x, 26);
	printf("                                  "); gotoxy(x, 27);
	printf("                                  "); gotoxy(x, 28);
	printf("                                  "); gotoxy(x, 29);
	printf("                                  "); gotoxy(x, 30);
	printf("                                  ");//�����ݴϴ�.
	color(c1, c2);
}

float numpad2() {
	int posx, posy;
	for (int i = 1; i <= 12; i++) {
		posx = i * 9, posy = 50;
		gotoxy(posx, posy);
		for (int i = 0; i < 15; i++) {
			printf("��");
			gotoxy(posx, posy + i);

		}
		switch (i) {
		case 1:
			snum('+', posx + 2, posy + 3);
			break;
		case 2:
			snum('-', posx + 2, posy + 3);
			break;
		case 3:
			snum('*', posx + 2, posy + 3);

			break;
		case 4:
			snum('/', posx + 2, posy + 3);
			break;
		case 5:
			snum('^', posx + 2, posy + 3);
			break;
		case 6:
			snum('!', posx + 2, posy + 3);
			break;
		default:
			gotoxy(posx + 2, posy + 3);
			printf("        "); gotoxy(posx + 2, posy + 4);
			printf("           "); gotoxy(posx + 2, posy + 5);
			printf("        "); gotoxy(posx + 2, posy + 6);
			printf("          "); gotoxy(posx + 2, posy + 7);
			printf("        ");
			break;
		case 11:break;//���ڵ��� Ű���忡 �����ִ°��� �����ְ� �����ڵ��� Ű���忡 ������ݴϴ�.
		case 12: break;

		}


	}
	DWORD mode;
	WORD key;
	COORD pos;
	int x;
	int y;
	int event;        // ���콺 �̺�Ʈ�� �̿�
	int n = 0;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���콺 Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);


	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
				y = pos.Y;
				for (int i = 0; i <= 9; i++) {
					if (y <= 62 && y >= 52) {
						if (x <= 35 + 18 * i && x >= 20 + 18 * i) {
							switch (i) {
							case 0: return(float)'+';
							case 1: return  (float)'-';
							case 2: return (float)'*';
							case 3: return  (float)'/';
							case 4: return (float)'^';
							case 5: return (float)'!';
							}

						}//���ڸ����� Ŭ���� ��ȣ���� ��ȯ���ݴϴ�.


					}

				}
			}
		}
	}

}

void snum(int a, int x, int y) {
	int posx = x - 2;
	int posy = y - 3;
	switch (a) {
	case '+':
		gotoxy(posx + 2, posy + 3);
		printf("    ��    "); gotoxy(posx + 2, posy + 4);
		printf("    ��    "); gotoxy(posx + 2, posy + 5);
		printf("������"); gotoxy(posx + 2, posy + 6);
		printf("    ��    "); gotoxy(posx + 2, posy + 7);
		printf("    ��    ");
		break;
	case '-':
		gotoxy(posx + 2, posy + 3);
		printf("          "); gotoxy(posx + 2, posy + 4);
		printf("          "); gotoxy(posx + 2, posy + 5);
		printf("������"); gotoxy(posx + 2, posy + 6);
		printf("          "); gotoxy(posx + 2, posy + 7);
		printf("          ");
		break;
	case '*':
		gotoxy(posx + 2, posy + 3);
		printf("��      ��"); gotoxy(posx + 2, posy + 4);
		printf("  ��  ��  "); gotoxy(posx + 2, posy + 5);
		printf("    ��    "); gotoxy(posx + 2, posy + 6);
		printf("  ��  ��  "); gotoxy(posx + 2, posy + 7);
		printf("��      ��");
		break;
	case '/':
		gotoxy(posx + 2, posy + 3);
		printf("    ��    "); gotoxy(posx + 2, posy + 4);
		printf("          "); gotoxy(posx + 2, posy + 5);
		printf("������"); gotoxy(posx + 2, posy + 6);
		printf("          "); gotoxy(posx + 2, posy + 7);
		printf("    ��    ");
		break;
	case '^':
		gotoxy(posx + 2, posy + 3);
		printf("          "); gotoxy(posx + 2, posy + 4);
		printf("    ��    "); gotoxy(posx + 2, posy + 5);
		printf("  ��  ��  "); gotoxy(posx + 2, posy + 6);
		printf("��      ��"); gotoxy(posx + 2, posy + 7);
		printf("          ");
		break;
	case '!':
		gotoxy(posx + 2, posy + 3);
		printf("    ����  "); gotoxy(posx + 2, posy + 4);
		printf("  ��        "); gotoxy(posx + 2, posy + 5);
		printf("  ��        "); gotoxy(posx + 2, posy + 6);
		printf("���        "); gotoxy(posx + 2, posy + 7);
		printf("  ��        ");
		break;//�����ڵ��� ������ִ� �Լ��Դϴ�.
	}
}

int OXpad() {
	int posx, posy;
	for (int i = 1; i <= 12; i++) {
		posx = i * 9, posy = 50;
		gotoxy(posx, posy);
		for (int i = 0; i < 15; i++) {
			printf("��");
			gotoxy(posx, posy + i);

		}
		switch (i) {
		case 1:
			OX('+', posx + 2, posy + 3);
			break;
		case 2:
			OX('-', posx + 2, posy + 3);
			break;
		default:
			gotoxy(posx + 2, posy + 3);
			printf("        "); gotoxy(posx + 2, posy + 4);
			printf("           "); gotoxy(posx + 2, posy + 5);
			printf("        "); gotoxy(posx + 2, posy + 6);
			printf("          "); gotoxy(posx + 2, posy + 7);
			printf("        ");
			break;
		case 11:break;//Ű���忡 ���� ������ �����ְ� �����ڵ��� ������ݴϴ�.
		case 12: break;
		}
	}
	DWORD mode;
	WORD key;
	COORD pos;
	int x;
	int y;
	int event;        // ���콺 �̺�Ʈ�� �̿�
	int n = 0;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���콺 Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);


	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
				y = pos.Y;
				for (int i = 0; i <= 9; i++) {
					if (y <= 62 && y >= 52) {
						if (x <= 35 + 18 * i && x >= 20 + 18 * i) {
							switch (i) {
							case 0: return(float)'O';
							case 1: return  (float)'X';
							}//�� �ڸ� ������ ��ȯ���ݴϴ�.

						}


					}

				}
			}
		}
	}
}

void OX(int a, int x, int y) {
	int posx = x - 2;
	int posy = y - 3;
	switch (a) {
	case '+':
		gotoxy(posx + 2, posy + 3);
		printf("   ���   "); gotoxy(posx + 2, posy + 4);
		printf(" ��    �� "); gotoxy(posx + 2, posy + 5);
		printf("��      ��"); gotoxy(posx + 2, posy + 6);
		printf(" ��    �� "); gotoxy(posx + 2, posy + 7);
		printf("   ���   ");
		break;
	case '-':
		gotoxy(posx + 2, posy + 3);
		printf("��      ��"); gotoxy(posx + 2, posy + 4);
		printf("  ��  ��  "); gotoxy(posx + 2, posy + 5);
		printf("    ��    "); gotoxy(posx + 2, posy + 6);
		printf("  ��  ��  "); gotoxy(posx + 2, posy + 7);
		printf("��      ��");
		break;//���ڸ��� OX������ ��ȯ���ݴϴ�.
	}
}