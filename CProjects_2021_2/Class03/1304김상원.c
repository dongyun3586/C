#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <Windows.h>
// window.h �� Windows.h �� �ܼ�â �󿡼� ��ȭ�� �ֱ����� �̿�. �ð������� ���󺯰�
//conio.h �� ���ڸ� �Է¹޴� ����� ���� ����Ͽ���. 
#define MAXX 189 // �ִ� ���� ĭ ��
#define MAXY 49  // �ִ� ���� �� �� (��üȭ�����)

#define PASSWORD 31415926535 // �����ص� ��й�ȣ (�ڵ峻 ���X)

char ScreenArr[MAXY][MAXX] = { 0 };  // ȭ�鿡 ��Ÿ�� �� ĭ�鿡 ���� �迭
int PWflg = 0; // ��й�ȣ �Է� �� ��й�ȣ�� �´��� Ʋ���� ���� ��Ÿ���� ����
char BS[100] = { 0 }; // ���� ������ �Է¹ް� ���⿵�� ȭ�� ����� ���� �����صδ� �迭
int TorUflg = 0; // DNA ���� RNA���� ���¸� ��Ÿ���� ����

//ȭ�� �� �ʱ�ȭ �Լ�
void FirstSet() {
	for (int y = 0; y < MAXY; y++) {
		for (int x = 0; x < MAXX; x++) {
			ScreenArr[y][x] = '\0';
		}
	}
	for (int y = 0; y < MAXY; y++) {
		for (int x = 0; x < MAXX; x++) {
			ScreenArr[y][x] = ' ';
		}
	}
}

//�߰� �������� ȭ�� ��ü�� = �� ���� ä����Լ�
void Set() {
	for (int y = 0; y < MAXY; y++) {
		for (int x = 0; x < MAXX; x++) {
			ScreenArr[y][x] = '=';
		}
	}
}

// ��й�ȣ ������ ���� �����ϴ� �Լ�. ��й�ȣ ���� �������.
char Password[] = "31415926535";

//���ϴ� ������ ���ڿ��� �� ���ڿ��� ���� ��ǥ�� �Է��ϸ� �� �������� ���ڿ��� ȭ��(ScreenArr �迭)���� �ű�� �Լ�
void ChangeScreen(char Strprt[], int x, int y);

// ȭ��(ScreenArr �迭) �� ����ϴ� �Լ�.
void ShowScreen();

//����ڷκ��� ���ڸ� �Է� �޾� �̸� x,y ��ǥ���� ȭ������ �ű�� �Լ�. b������ �����, x������ �Է�����
void GetScreen(int x, int y);

//����ڰ� �Է��� ��й�ȣ�� ������ ��й�ȣ�� ������ Ȯ���ϴ� �Լ�. Ʋ���ٸ� �ٽ� �Է��ϵ��� ��.
int CheckPassword();

//���� �Լ����� ����� �α��� ���� �Լ�
void LogIn();

// RNA ���� DNA������ �����ϴ� �Լ�. �� ���θ� TorUflg ������ �����Ͽ� �ٸ� �Լ����� flg�� Ȱ��. r �Ǵ� d�� ���� ���� �� x�� ���� Ȯ��.
void CheckWhatToDo();

// ���⼭���� �Է¹ޱ� �� �Է��ش޶�� �����ϴ� �Լ�. 
void GetCode(int flg);

//���⼭���� �Է¹޴� �Լ�. A,T,U,G,C�� �Է¹��� �� �ִ�(������ �Է��ص� �ν� X). b�� ���� ����� x���� �Ϸ�.
void GetBasePair(int x, int y, int flg);

//�ε�ȭ��
void SayIWillMakeIt();

//���⿵�� ���ȭ���� Ʋ�� ���ߴ� �Լ�. �ٻ��� ũ�⸦ �� �� �ֵ��� ���ִ� Ư�� ���� �ٻ��� ����� ���⼭ �ʱ⼳�����ش�.
void ElectrophoresisStatus();

// BS[]�� ��� �Է¹��� ���⼭���� ������ ȭ�鿡 �� �ٻ��� ������ ���⿡ ���� �ٸ� �ٷ� ȭ�鿡 ��Ÿ�� �ش�.
void ChangeElectrophoresisStatus();

//���â���� a�� ������ ���ο� �۾� ���� ����
void DoItAgain();


int main() {
	FirstSet();
	LogIn();
	Sleep(1000); // �ܺζ��̺귯��
GO: // �ݺ� ��������
	CheckWhatToDo();
	GetCode(TorUflg);
	SayIWillMakeIt();
	ElectrophoresisStatus();
	ChangeElectrophoresisStatus();
	DoItAgain();
	goto GO;  // �ݺ��� ���� goto ���
	return 0;
}

void ChangeScreen(char Strprt[], int x, int y) {
	int i = 0;
	while (Strprt[i] != '\0') {
		ScreenArr[y][x] = Strprt[i];
		x++; i++;
	}
}
void GetScreen(int x, int y) {
	while (1) {
		char Get = _getch();
		if (Get == 'x') { break; }
		else if (Get == 'b') { x -= 1; ScreenArr[y][x] = ' '; }
		else {
			ScreenArr[y][x] = Get;
			x++;
		}
		ShowScreen();
	}
}
void ShowScreen() {
	system("cls");
	for (int y = 0; y < MAXY; y++) {
		for (int x = 0; x < MAXX; x++) {
			printf("%c", ScreenArr[y][x]);
		}
	}
}
int CheckPassword() {
	int i = 0, checker = 0; // i�� �Էµ� ��ȣ�� �ڸ��� ����, checker�� ��ġ�� ������ ��������
	for (i = 0; ScreenArr[27][89 + i] != ' '; i++) {
		if (Password[i] == ScreenArr[27][89 + i]) {
			checker++;
		}
	}
	if (checker == 11 && i == checker) { return 1; } // i�� checker���� ����(�ڸ��� ��ġ) i�� 11(11�ڸ� ��� ����) �� ��� ��й�ȣ �´ٴ� ����
	else { return 0; }

	//�� �ڵ�� 31415926535 ��� ��й�ȣ�� Ư��ȭ�Ǿ� ¥���� �ڵ��̴�. 
}
void LogIn() {
	if (PWflg == 0) {
		char FirstInfo[] = "Please enter password";
		ChangeScreen(FirstInfo, 84, 25);
	}
	else {
		char Nope[] = "Nope !  please enter password again";
		FirstSet();
		ChangeScreen(Nope, 77, 25);
	}
	ShowScreen();

	GetScreen(89, 27);
	if (CheckPassword()) { Set(); ShowScreen(); }
	else
	{
		PWflg = 1;
		LogIn();
	}
}
void CheckWhatToDo() {
	FirstSet();
	char AskWhatToDo[] = "Choose Task To Do";
	ChangeScreen(AskWhatToDo, 86, 25);
	char RNADNA[] = "RNA     DNA";
	ChangeScreen(RNADNA, 89, 27);
	char UnderBar[] = "===        ";
	ChangeScreen(UnderBar, 89, 28);
	ShowScreen();
	int flg = 0;
	while (1) {
		int Get = _getch();  // �ܺζ��̺귯��
		if (Get == 'x') { break; }
		char UnderBar_d[] = "        ===";
		if (Get == 'r') { ChangeScreen(UnderBar, 89, 28); flg = 0; }
		else if (Get == 'd') { ChangeScreen(UnderBar_d, 89, 28); flg = 1; }
		ShowScreen();
	}
	TorUflg = flg;  // �������� TorUflg �� 0 �Ǵ� 1�� �Ѱ� ������ �۾��� ������ �ٸ� �Լ��� ����
}
struct EnterCode {
	char EnterCode[35];
};
// �� ������ �۾��� ���� �ȳ����� ���ϰ� �����ϱ� ���� ���ڿ��� �ִ� ����ü ���

void GetCode(int flg) {
	FirstSet();
	struct EnterCode R;
	struct EnterCode D;
	strcpy(R.EnterCode, "please enter RNA base consequence");
	strcpy(D.EnterCode, "please enter DNA base consequence");
	if (flg == 0) { ChangeScreen(R.EnterCode, 78, 25); }
	else if (flg == 1) { ChangeScreen(D.EnterCode, 78, 25); }
	char warn[] = "(Maximum = 100bp)";
	ChangeScreen(warn, 86, 26);
	ShowScreen();
	GetBasePair(45, 28, flg);
}
void GetBasePair(int x, int y, int flg) {
	int i = 0;
	while (1) {
		char Get = _getch(); // ������ conio.h ������Ͽ� �ִ� �Լ�. �Էµ� ���� �� ���� ������� �ʰ� �� ���� ������ �ѱ��.  // �ܺζ��̺귯��
		if (Get == 'x') { break; }
		else if (Get == 'b') { i -= 1;  ScreenArr[y][x + i] = ' '; BS[i] = '\0'; }
		else if (flg == 1) {
			switch (Get) {
			case 'A':
				BS[i] = 'A'; ScreenArr[y][x + i] = BS[i]; i++; break;
			case 'T':
				BS[i] = 'T'; ScreenArr[y][x + i] = BS[i]; i++; break;
			case 'G':
				BS[i] = 'G'; ScreenArr[y][x + i] = BS[i]; i++; break;
			case 'C':
				BS[i] = 'C'; ScreenArr[y][x + i] = BS[i]; i++; break;
			default:
				break;
				// �Էµ� ���⿡ ���� �ٸ� ��Ȳ�� switch-case��
			}
		}
		else if (flg == 0) {
			switch (Get) {
			case 'A':
				BS[i] = 'A'; ScreenArr[y][x + i] = BS[i]; i++; break;
			case 'U':
				BS[i] = 'U'; ScreenArr[y][x + i] = BS[i]; i++; break;
			case 'G':
				BS[i] = 'G'; ScreenArr[y][x + i] = BS[i]; i++; break;
			case 'C':
				BS[i] = 'C'; ScreenArr[y][x + i] = BS[i]; i++; break;
			default:
				break;
			}
		}
		ShowScreen();
	}
}
void SayIWillMakeIt() {
	char Load[4][15] = { "Loading..." , "Loading.." , "Loading." , "Loading" };
	char(*ptr)[15] = Load;  // �����͸� �̿��� Load�� �̵�
	char Clear25[] = "                               "; //��µǾ� �ִ� �ε����� ����� ���� ���ڿ�
	FirstSet();
	ChangeScreen(BS, (189 - strlen(BS)) / 2, 26);
	int k = 2;
	while (k) {
		for (int i = 0; i < 4; i++) {
			Sleep(500);
			ChangeScreen(Clear25, 79, 25);
			ChangeScreen(ptr[i], (189 - strlen(ptr[i])) / 2, 25);
			ShowScreen();
		}
		k--;
	}
}
char Electrophoresis[151][189] = { 0 };
void Secondset() {
	for (int y = 0; y < 150; y++) {
		for (int x = 0; x < 189; x++) {
			if (x == 188) {
				Electrophoresis[y][x] = '\n';
			}
			else
				Electrophoresis[y][x] = ' ';
		}
	}
}

//���⿵�� ��� ��� �� ������ ������ ������ ����ϱ� ���� ������ ��� ���Ͽ��� �Լ��� �� ���
void ShowScreen2() {
	system("cls");  // �ܺζ��̺귯��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * 3 + 5); // 2������ 8ĭ �� ���� �� ĭ, ���� �� ĭ�� ���� �о� ������ �����Ѵ�. ���� �� ĭ�� ���� ����, ���� �� ĭ�� ���ڻ��� �����Ѵ�.  // �ܺζ��̺귯��
	for (int y = 0; y < 121; y++) {
		for (int x = 0; x < 189; x++) {
			if (x < 78) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * 7 + 1);  // �ܺζ��̺귯��
			}
			printf("%c", Electrophoresis[y][x]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ܺζ��̺귯��
		}
	}
}
// 9~16 , 22~29 , 35~42 , 48~55 , 61~68 (Line�� ��ġ�� ĭ�� �޸��� �� ��)
char Line[] = "========="; // �̵��� ���ڸ� ��Ÿ���� ��
void ChangeStatus(char Strprt[], int x, int y, int k) {
	int i = 0;
	while (Strprt[i] != '\0') {
		Electrophoresis[y - k][x + i] = Strprt[i];
		i++;
	}
}
void ElectrophoresisStatus() {
	FirstSet();
	Secondset();
	for (int H = 8; H < 118; H++) {
		for (int i = 0; i < 6; i++) {
			Electrophoresis[H][i] = 'H';
		}
		for (int i = 72; i < 78; i++) {
			Electrophoresis[H][i] = 'H';
		}
	}
	for (int Z = 8; Z < 118; Z += 109) {
		for (int i = 6; i < 72; i++) {
			Electrophoresis[Z][i] = '=';
		}
	}
	for (int z = 5; z < 8; z++) {
		for (int i = 0; i < 78; i++) {
			Electrophoresis[z][i] = '=';
		}
	}
	for (int z = 118; z < 121; z++) {
		for (int i = 0; i < 78; i++) {
			Electrophoresis[z][i] = '=';
		}
	}

	for (int Z = 17; Z < 117; Z += 10) {
		ChangeStatus(Line, 9, Z, 0);
	}
}
void ChangeElectrophoresisStatus() {
	int i = 0;
	while (1) {
		if (strlen(BS) == i) { break; }
		switch (BS[i]) {
		case 'A':
			ChangeStatus(Line, 22, 115, i); Electrophoresis[5][25] = 'A'; break;
		case 'T':
			ChangeStatus(Line, 35, 115, i); Electrophoresis[5][38] = 'T'; break;
		case 'U':
			ChangeStatus(Line, 35, 115, i); Electrophoresis[5][38] = 'U'; break;
		case 'G':
			ChangeStatus(Line, 48, 115, i); Electrophoresis[5][51] = 'G'; break;
		case 'C':
			ChangeStatus(Line, 61, 115, i); Electrophoresis[5][64] = 'C'; break;
		}
		i++;
	}

	// ���¸� ���߱� ���� �ڵ���̹Ƿ� �߿����� �ʴ�.(���۾����� ���߰� ����ؼ� ��縸 �´�.)
	ShowScreen2();
}
// ���ο� �۾��� ���� BS ���ڿ��� �ʱ�ȭ�ϴ� �Լ�
void ClearBS() {
	for (int i = 0; i < 100; i++) {
		BS[i] = '\0';
	}
}
void DoItAgain() {
	while (1) {
		char Get = _getch();
		if (Get == 'a') {
			system("cls");
			FirstSet();
			PWflg = 0;
			TorUflg = 0;
			Secondset();
			ClearBS();

			//���� �۾����� ��ȭ�� ��� ����,���ڿ� �ʱ�ȭ
			break;
		}
	}
}