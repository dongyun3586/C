#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <mmsystem.h>

int loading(int Howmanyrepeat);		//�ε� Ƚ��. ���� ���������� 0
void gotoxy(int x, int y);			//Ŀ�� �̵��Լ�
void say(char say[20], int n);		//n:millisecond ���� �ϴ� �Լ�
void Division(int p);				//UI �� ���
void PrintLogo();					//�ΰ� ����Ʈ�մϴ�
void UIsetting(int* Nums[30], int* Acode[30], int* Bcode[30]);	//UI������ �Ѱ�
void Assignment(int* Nums[30], int* Acode[30], int* Bcode[30]); //�ʱ� �ڵ带 �������� �й� (Joker ����)
void MainMenu();					//���θ޴��� ������
void GameStart();					//���θ޴� - ���ӽ��۽� �˰����� ���Ե� �Լ�.
void GameRule();					//���θ޴� - ���ӹ���� ������
void PrintNum(char T, int N);				//�ڵ��� ���ڸ� ����մϴ�.
void SortString(int* String);		//���ڸ� ������� �ڵ��迭�մϴ�. 
void PrintcodeA(int* Acode[30]);	//A�� �ڵ带 ����մϴ�.
void PrintcodeB(int* Bcode[30]);	//B�� �ڵ带 ����մϴ�.
int turn(char C, int n);		//�ΰ��� ���. n=0�̸� C�� ���� �´��� Ȯ��. n=1�̸� turn�� ��ȯ
void Countdowningame(int n);	//ī��Ʈ�ٿ� - �ʱ��ڵ� ������
void Countdowntochangeturn();	//ī��Ʈ�ٿ� - �� ��ȯ��
int Choose();
void PlusCode(int* Acode[30]);  //�ڵ带 �� �� �߰�����

char charidentification;		//turn �Լ����� ���. ������ ������ ����
int memory[100] = { 0 };

int main() {
	system("cls");
	gotoxy(46, 12);
	say("��� Davinci Code ���", 100); //��������������������
	Sleep(200);
	gotoxy(0, 0);
	MainMenu();
}

void gotoxy(int x, int y) {
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolehandle, pos);
}

int loading(int Howmanyrepeat) {
	int Pause = 1;
	printf("waiting");
	while (Pause < Howmanyrepeat + 1) {
		for (int i = 0; i < 3; i++) {
			Sleep(600);
			printf(".");
		}
		Pause++;
		gotoxy(7, 0);
		printf("   ");
		gotoxy(7, 0);
	}
	gotoxy(0, 0);
	printf("SUCCESS!");
}

void say(char say[20], int n) {
	for (int i = 0; say[i] != '\0'; i++) {
		printf("%c", say[i]);
		Sleep(n);
	}
}

void MainMenu() {
	char keypress;
	int gamestart = 0;
	char loca;
	system("cls");
	PrintLogo();
	gotoxy(53, 16);
	printf("�� ���� ����");
	gotoxy(53, 19);
	printf("�� ���� ���");
	gotoxy(53, 22);
	printf("�� ���� ����");
	gotoxy(99, 25);
	int plc = 1;

	while (gamestart == 0) {
		if (_kbhit()) {
			keypress = _getch();
			switch (keypress) {
			case 'w':
				if (plc == 1) {
					plc = 3;
				}
				else {
					plc--;
				}
				break;
			case 's':
				if (plc == 3) {
					plc = 1;
				}
				else {
					plc++;
				}
				break;
			case '\r':
				if (plc == 1) {
					GameStart();
					return;
				}
				else if (plc == 2) {
					GameRule();
					return;
				}
				else {
					return 0;
				}
				break;
			}
			gotoxy(99, 25);
			printf("      ");
			switch (plc) {
			case 1: gotoxy(53, 19); printf("��"); gotoxy(53, 22); printf("��"); gotoxy(53, 16); printf("��"); break;
			case 2: gotoxy(53, 16); printf("��"); gotoxy(53, 22); printf("��"); gotoxy(53, 19); printf("��"); break;
			case 3: gotoxy(53, 16); printf("��"); gotoxy(53, 19); printf("��"); gotoxy(53, 22); printf("��"); break;
			}
			gotoxy(99, 25);
		}
	}
}

void PrintLogo() {
	Sleep(200);
	system("cls");
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	say("�������������������������������������������������������������\n", 0);
	gotoxy(0, 0);
}

void GameRule() {
	int keypress;
	system("cls");
	say("�������������������������������������������������������������\n\n", 0);
	say("�� ������ ���۹��� W, A, S, D, Enter ���Դϴ�. ��������? \n\n", 0);
	say("�Ϲ������� ���� ���۹��� W, A, S, D�� ������� ��, ����, �Ʒ�, �������Դϴ�. \n\n", 0);
	say("�÷��̾� 2�� ���� ���۹����� �����մϴ�.\n\n", 0);
	say("ó�� ���ʿ��� �÷��̾� 1��, ������ �÷��̾� 2�� ���ʷ� �ڽ��� �и� Ȯ���մϴ�.\n\n", 0);
	say("��Ŀ ī��� �ڽ��� �����ְ���� ��ġ�� �������� �� �ֽ��ϴ�. \n\n", 0);
	say("�ڽ��� ���� �Ǹ� �ϳ��� �ڵ带 ��������, ����� �ڵ带 �߸��� ��ȸ�� ����ϴ�.\n\n", 0);
	say("������� ����� �и� ������ �˴ϴ�. �̶� ������ �����ǰ�,���Ѵٸ� �ѹ� �� �� �� �ֽ��ϴ�.\n\n", 0);
	say("�����ؼ� Ʋ���ԵǸ� �ڽ��� �ڵ� �ϳ��� �����ؾ��մϴ�.\n\n", 0);
	say("�ڵ尡 ��� �����Ǹ� �й��մϴ�.\n\n", 0);
	say("Press Enter to go mainmenu...", 0);
	say("\n\n�������������������������������������������������������������\n", 0);
	while (1) {
		keypress = _getch();
		switch (keypress) {
		case '\r':
			system("cls");
			MainMenu();
			return;
		}
	}
}

void GameStart() {
	int Nums[30], Acode[30], Bcode[30], End = 0, swip = 0, lengthA = 0, lengthB = 0;
	system("cls");
	gotoxy(51, 5);
	say("�� �� Ȯ �� - A", 20);
	Countdowntochangeturn();
	Division(1);
	UIsetting(Nums, Acode, Bcode);
	Assignment(Nums, Acode, Bcode);

	//������� ����
	SortString(Acode);
	SortString(Bcode);

	turn('A', 1);			//A�� ������ ��ȯ
	PrintcodeA(Acode);		//�ڵ� ���
	PrintcodeB(Bcode);
	Countdowningame(3);

	system("cls");
	gotoxy(51, 5);
	say("�� �� Ȯ �� - B", 20);
	Countdowntochangeturn();
	Division(1);
	UIsetting(Nums, Acode, Bcode);

	turn('B', 1);			//B�� ������ ��ȯ
	PrintcodeA(Acode);		//�ڵ� ���
	PrintcodeB(Bcode);
	Countdowningame(3);

	int Pointflag = 0; //ù�Ͽ��� PlusCode�Լ��� ������� �ʵ��� �ϴ� ����

	while (End == 0) {
		if (swip % 2 == 0) {	//A
			system("cls");
			gotoxy(52, 5);
			say(" T U R N - A", 20);
			Countdowntochangeturn();
			Division(1);
			UIsetting(Nums, Acode, Bcode);

			turn('A', 1);			//A�� ������ ��ȯ
			if (Pointflag != 0) {
				PlusCode(Acode);
			}

			PrintcodeA(Acode);		//�ڵ� ���
			PrintcodeB(Bcode);

			if (Choose() == 1) { //����
				int n, num, chn, check = 0, Nonecode = 0;
				gotoxy(1, 23); printf("                                          ");
				gotoxy(1, 24); printf("                                          ");
				gotoxy(1, 25); printf("                                          ");
				gotoxy(1, 27);
				printf("������ :");
				for (int i = 0; i < 30; i++) {
					if (memory[i] == 1) {
						if (i >= 13) {
							i = i - 13;
							printf(" w");
							printf("%d", i);
							i = i + 13;
						}
						else {
							printf(" b");
							printf("%d", i);
						}
						Nonecode = 1;
					}
				}
				printf(" �ڵ�");
				if (Nonecode == 0) {
					printf(" ����");
				}
				gotoxy(1, 23);
				say("������ �����ϼ̽��ϴ�.", 10);
				while (1) {
					lengthB = 0;
					gotoxy(1, 24);
					printf("                                          ");
					gotoxy(1, 24);
					say("���° �ڵ带 �����մϱ�? : ", 10);
					for (int i = 0; Bcode[i] != 33; i++) {
						lengthB++;
					}
					scanf("%d", &n);
					if (n > lengthB) {		//�̹� ������ �ڵ��̰ų� ���� �ڵ�
						gotoxy(1, 25);
						say("!!! �̹� �����Ǿ��ų� ���� �ڵ��Դϴ� !!! ", 10);
					}
					else {
						if (memory[Bcode[n - 1]] == 1) {		//�̹� ������ �ڵ��̰ų� ���� �ڵ�
							gotoxy(1, 25);
							say("!!! �̹� �����Ǿ��ų� ���� �ڵ��Դϴ� !!! ", 10);
						}
						else { break; }
					}
				}

				gotoxy(1, 25);
				printf("                                          ");
				gotoxy(1, 25);
				say("�ڵ�� ���ϱ��? : ", 10);
				scanf("%d", &num);
				if (Bcode[n - 1] == num || Bcode[n - 1] == num + 13) {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("������ �����ϼ̽��ϴ�! :D", 10);
					memory[Bcode[n - 1]] = 1;
					Sleep(500);

					//�ٽ� ���ñ��� ��
				}
				else {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("������ �����ϼ̽��ϴ� :( ", 10);

					for (int i = 0; Acode[i] != 33; i++) {
						lengthA++;
					}

					while (check == 0) {
						gotoxy(1, 24);
						printf("                                          ");
						gotoxy(1, 24);
						say("�ڽ��� �ڵ� �ϳ��� �����ؾ��մϴ�... ������ �ڵ� : ", 10);
						scanf("%d", &chn);
						if (memory[Acode[chn - 1]] == 1 || chn > lengthA) {		//�̹� ������ �ڵ��̰ų� ���� �ڵ�
							gotoxy(1, 25);
							printf("                                          ");
							gotoxy(1, 25);
							say("!!! �̹� �����Ǿ��ų� ���� �ڵ��Դϴ� !!! ", 10);
						}
						else {
							memory[Acode[chn - 1]] = 1;
							check = 1;
						}
					}
					Pointflag = 1;
					swip++;
				}
			}
			else { //�� �ѱ��
				Pointflag = 1;
				swip++;
			}
		}

		else {			//B
			system("cls");
			gotoxy(52, 5);
			say(" T U R N - B", 20);
			Countdowntochangeturn();
			Division(1);
			UIsetting(Nums, Acode, Bcode);

			turn('B', 1);			//B�� ������ ��ȯ

			if (Pointflag != 0) {
				PlusCode(Bcode);
			}
			PrintcodeA(Acode);		//�ڵ� ���
			PrintcodeB(Bcode);

			if (Choose() == 1) { //����
				int n, num, chn, check = 0, Nonecode = 0;
				gotoxy(1, 23); printf("                                          ");
				gotoxy(1, 24); printf("                                          ");
				gotoxy(1, 25); printf("                                          ");
				gotoxy(1, 27);
				printf("������ :");
				for (int i = 0; i < 30; i++) {
					if (memory[i] == 1) {
						if (i >= 13) {
							i = i - 13;
							printf(" w");
							printf("%d", i);
							i = i + 13;
						}
						else {
							printf(" b");
							printf("%d", i);
						}
						Nonecode = 1;
					}
				}
				printf(" �ڵ�");
				if (Nonecode == 0) {
					printf(" ����");
				}
				gotoxy(1, 23);
				say("������ �����ϼ̽��ϴ�.", 10);
				while (1) {
					lengthA = 0;
					gotoxy(1, 24);
					printf("                                          ");
					gotoxy(1, 24);
					say("���° �ڵ带 �����մϱ�? : ", 10);
					for (int i = 0; Acode[i] != 33; i++) {
						lengthA++;
					}
					scanf("%d", &n);
					if (memory[Acode[n - 1]] == 1 || n > lengthA) {		//�̹� ������ �ڵ��̰ų� ���� �ڵ�
						gotoxy(1, 25);
						say("!!! �̹� �����Ǿ��ų� ���� �ڵ��Դϴ� !!! ", 10);
					}
					else { break; }
				}

				gotoxy(1, 25);
				printf("                                          ");
				gotoxy(1, 25);
				say("�ڵ�� ���ϱ��? : ", 10);
				scanf("%d", &num);
				if (Acode[n - 1] == num || Acode[n - 1] == num + 13) {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("������ �����ϼ̽��ϴ�! :D", 10);
					memory[Acode[n - 1]] = 1;
					Sleep(500);

					//�ٽ� ���ñ��� ��
				}
				else {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("������ �����ϼ̽��ϴ� :( ", 10);

					for (int i = 0; Bcode[i] != 33; i++) {
						lengthB++;
					}

					while (check == 0) {
						gotoxy(1, 24);
						printf("                                          ");
						gotoxy(1, 24);
						say("�ڽ��� �ڵ� �ϳ��� �����ؾ��մϴ�... ������ �ڵ� : ", 10);
						scanf("%d", &chn);
						if (memory[Bcode[chn - 1]] == 1 || chn > lengthB) {		//�̹� ������ �ڵ��̰ų� ���� �ڵ�
							gotoxy(1, 25);
							printf("                                          ");
							gotoxy(1, 25);
							say("!!! �̹� �����Ǿ��ų� ���� �ڵ��Դϴ� !!! ", 10);
						}
						else {
							memory[Bcode[chn - 1]] = 1;
							check = 1;
						}
					}
					swip++;
				}
			}
			else { //�� �ѱ��
				swip++;
			}
		}
	}
}

void Countdowningame(int n) {
	gotoxy(50, 26);
	printf("���� �ð� : ");
	for (int i = n; i > 0; i--) {
		gotoxy(63, 26);
		printf("%d", i);
		Sleep(1000);
		gotoxy(63, 26);
		printf("   ");
	}
}

void Countdowntochangeturn() {
	gotoxy(54, 12);
	say("R E A D Y", 20);
	for (int i = 3; i > 0; i--) {
		gotoxy(58, 14);
		printf("%d", i);
		Sleep(1000);
		gotoxy(58, 14);
		printf("   ");
	}
}

void Division(int p) {
	system("cls");
	for (int n = 116; n >= 0; n--) {
		gotoxy(n, 22);
		printf("��");
		Sleep(10);
	}
}

void UIsetting(int* Nums[30], int* Acode[30], int* Bcode[30]) {

	gotoxy(0, 0);
	printf(" Player 1");
	gotoxy(0, 11);
	printf(" Player 2");
}

//���� 0 1 2 3 4 5 6 7 8 9 10 11 -
//    (0 1 2 3 4 5 6 7 8 9 10 11 12)
//�Ͼ� 0 1 2 3 4 5 6 7 8 9 10 11 -
//    (13 14 15 16 17 18 19 20 21 22 23 24 25)

int NumRemainder[30] = { 0 };
//NumRemainder - �̹� ���� �ڵ� (���� �ڵ�)�� ������Ŵ (value�� 99���� ����) ���� 99�̸� ������� ����

void Assignment(int* Nums[30], int* Acode[30], int* Bcode[30]) {
	for (int i = 0; i < 26; i++) {
		if (i == 12 || i == 25) {
			Nums[i] = 12;	//JOKER. 12�̸� --�� �������� ��.
		}
		else {
			Nums[i] = i % 13;
		}
	}

	srand(time(NULL));
	for (int i = 0; i < 4; i++) { //A������ �ڵ�
		int flag = 0;
		int order = rand() % 26;  //order ������ 0~ 25 ������ȣ ��
		int value = Nums[order]; //value ������ȣ�� �ش��ϴ� ��ȣ

		if (NumRemainder[order] != 99 && order != 12 && order != 25) {
			Acode[i] = order;
			NumRemainder[order] = 99;	//NumRemainder���� ����� �ڵ� ���ִ� �۾�
		}
		else {
			i--;
		}
	}
	for (int i = 0; i < 4; i++) { //B������ �ڵ�
		int flag = 0;
		int order = rand() % 26;  //order ������ 0~ 25 ������ȣ ��
		int value = Nums[order]; //valude ������ȣ�� �ش��ϴ� ��ȣ

		if (NumRemainder[order] != 99 && order != 12 && order != 25) {
			Bcode[i] = order;
			NumRemainder[order] = 99;	//NumRemainder���� ����� �ڵ� ���ִ� �۾�
		}
		else {
			i--;
		}
	}
	Acode[4] = 33; //���ҿ� 0�� �־� Null�� �迭 ���̸� �����ϱ� �����. 33���� ��ü
	Bcode[4] = 33;

	//A�� �ڵ�� B�� �ڵ� ���� �Ϸ�. 
}

void PrintcodeA(int* Acode[30]) {
	int i = 0;
	int length = 0;
	for (int i = 0; Acode[i] != 33; i++) {
		length++;
	}

	for (int X = 0; X < length; X++) {
		gotoxy(6 * X, 3);
		if (Acode[i] <= 12) {
			printf("   ");
			printf("���");
			gotoxy(6 * X, 4);
			printf("   ");
			PrintNum('A', Acode[i]);
			gotoxy(6 * X, 5);
			printf("   ");
			printf("���");
			i++;
		}
		else {
			printf("   ");
			printf("���");
			gotoxy(6 * X, 4);
			printf("   ");
			PrintNum('A', Acode[i]);
			gotoxy(6 * X, 5);
			printf("   ");
			printf("���");
			i++;
		}
	}
}

void PrintcodeB(int* Bcode[30]) {
	int i = 0;
	int length = 0;

	for (int i = 0; Bcode[i] != 33; i++) {
		length++;
	}

	for (int X = 0; X < length; X++) {
		gotoxy(6 * X, 14);
		if (Bcode[i] <= 12) {
			printf("   ");
			printf("���");
			gotoxy(6 * X, 15);
			printf("   ");
			PrintNum('B', Bcode[i]);
			gotoxy(6 * X, 16);
			printf("   ");
			printf("���");
			i++;
		}
		else {
			printf("   ");
			printf("���");
			gotoxy(6 * X, 15);
			printf("   ");
			PrintNum('B', Bcode[i]);
			gotoxy(6 * X, 16);
			printf("   ");
			printf("���");
			i++;
		}
	}
}

void SortString(int* String) { //0~25�� ������ȣ�� ����ִ� ����
	//���� 0 1 2 3 4 5 6 7 8 9 10 11 -
	//    (0 1 2 3 4 5 6 7 8 9 10 11 12)
	//�Ͼ� 0 1 2 3 4 5 6 7 8 9 10 11 -
	//    (13 14 15 16 17 18 19 20 21 22 23 24 25)
	int length = 0;
	for (int i = 0; String[i] != 33; i++) {
		length++;
	}
	//gotoxy(50,20);
	//printf("%d", length); ���̰� ����� �����Ǵ��� Ȯ�� �ܰ�

	for (int i = 0; String[i] != 33; i++) {
		for (int j = i + 1; String[j] != 33; j++) {
			if (String[i] % 13 > String[j] % 13) { //���ڰ� �ٸ� ���
				if (String[i] != 12 && String[i] != 25 && String[j] != 12 && String[j] != 25) { //Joker�� Sorting ���� ����
					int temp = String[i];
					String[i] = String[j];
					String[j] = temp;
					//printf("	---%d ", temp);	//Sorting�� ����� �Ǿ����� Ȯ�� �ܰ�
				}
			}
			else if (String[i] % 13 == String[j] % 13) { //���ڰ� ���� ���
				if (String[i] > String[j]) {
					if (String[i] != 12 && String[i] != 25 && String[j] != 12 && String[j] != 25) { //Joker�� Sorting ���� ����
						int temp = String[i];
						String[i] = String[j];
						String[j] = temp;
						//printf("	+++%d ", temp); //Sorting�� ����� �Ǿ����� Ȯ�� �ܰ�
					}
				}
			}
		}
	}
}

int turn(char Playersign, int n) { //�ΰ��� ���. n=0�̸� C�� ���� �´��� Ȯ��. n=1�̸� turn�� ��ȯ. Playersign�� A(Player 1) Ȥ�� B(Player 2)
	if (n == 0) {
		if (Playersign == charidentification) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (n == 1) {
		charidentification = Playersign;
	}
}

void PlusCode(int* code[30]) { //A�� B�� �ڵ忡 ���� ���ο� �ڵ� �߰���
	int Nums[30];

	int length = 0;
	for (int i = 0; code[i] != 33; i++) {
		length++;
	}

	if (length > 12) {
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (i == 12 || i == 25) {
			Nums[i] = 12;	//JOKER. 12�̸� --�� �������� ��.
		}
		else {
			Nums[i] = i % 13;
		}
	}

	srand(time(NULL));
	while (1) {
		int order = rand() % 26;  //order ������ 0~ 25 ������ȣ ��
		int value = Nums[order];

		if (NumRemainder[order] != 99) {
			int length = 0;
			for (int i = 0; code[i] != 33; i++) {
				length++;
			}

			if (order != 12 && order != 25) { //Joker �ƴ�
				code[length] = order;
				code[length + 1] = 33;
				NumRemainder[order] = 99;
				SortString(code);
			}
			else {
				gotoxy(1, 23); printf("                                ");
				gotoxy(1, 24); printf("                                ");
				gotoxy(1, 25); printf("                                ");
				gotoxy(1, 23);
				say("Joker Code�� ������ϴ�!", 10);
				gotoxy(1, 24);
				say("���° �ڵ�� �߰��ұ��? :", 10);
				int n;
				scanf("%d", &n);
				for (int j = length; j >= n - 1; j--) {
					code[j + 1] = code[j];
					code[length + 1] = 33;
				}
				code[n - 1] = order;
				NumRemainder[order] = 99;
			}
			return;
		}
	}
}

void PrintNum(char Playersign, int N) { //���� �� �߾ӿ� ���ڸ� ��ġ��Ű�� ���ؼ� �����ڵ� ����ǥ���� ������ ���ڸ� ������ ���.
	int* string;

	string = memory;
	if (turn(Playersign, 0) && string[N] == 0) {
		printf(" ? ");
		return;
	}

	switch (N % 13) {
	case 0:
		printf(" ��");
		break;
	case 1:
		printf(" ��");
		break;
	case 2:
		printf(" ��");
		break;
	case 3:
		printf(" ��");
		break;
	case 4:
		printf(" ��");
		break;
	case 5:
		printf(" ��");
		break;
	case 6:
		printf(" ��");
		break;
	case 7:
		printf(" ��");
		break;
	case 8:
		printf(" ��");
		break;
	case 9:
		printf(" ��");
		break;
	case 10:
		printf(" 10");
		break;
	case 11:
		printf(" 11");
		break;
	case 12:
		printf(" --");
		break;
	}

	return;
}

int Choose() {
	int n = 0, plc = 1; char keypress;
	gotoxy(50, 27);
	printf("�� ����");
	gotoxy(58, 27);
	printf("�� �� �ѱ��");
	gotoxy(99, 25);

	while (n == 0) {
		if (_kbhit()) {
			keypress = _getch();
			switch (keypress) {
			case 'a':
				if (plc == 1) {
					plc = 2;
				}
				else {
					plc = 1;
				}
				break;
			case 'd':
				if (plc == 1) {
					plc = 2;
				}
				else {
					plc = 1;
				}
				break;
			case '\r':
				if (plc == 1) { //����
					gotoxy(50, 27); printf("                        ");
					return 1;
				}
				else { //�� �ѱ��
					gotoxy(50, 27); printf("                        ");
					return 0;
				}
				break;
			}
			gotoxy(99, 25);
			printf("      ");
			switch (plc) {
			case 1: gotoxy(58, 27); printf("��"); gotoxy(50, 27); printf("��"); break;
			case 2: gotoxy(50, 27); printf("��"); gotoxy(58, 27); printf("��"); break;
			}
			gotoxy(99, 25);
		}
	}
}

//���״� ���� �����ϴ�! 100ȸ�� �Ѵ� ����Ƚ���� �����մϴ�
// 
//		  ^ ^  _________  /
//		=(^.^=)_________)/
//		  /  /        |  |
// 
// ���� : 1103 ����
// �ڵ� ���� : 829�� (�ּ� ����)