//클릭을 하도록 하려면 콘솔창에서 위에 창을 우클릭하고 옵션에서 빠른 편집 모드와 삽입 모드를 해제해줍니다.
//그리고 숫자들을 마우스 클릭으로 선택할때 마우스를 누른채로 다른 좌표로 넘어가면 바로 새로운 클릭으로 인식되어서 이점을 조심하여 클릭해주세요!

#include<stdio.h>
#include<windows.h>
#include<math.h>
#define c1	7		//이 숫자를 고쳐서 글자색을 바꿀수 있습니다.
#define c2 0 //이 숫자를 고쳐서 배경색을 고를수 있습니다.

INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

INPUT_RECORD rec;
DWORD        dwNOER;

HANDLE COUT = 0;    // 콘솔 출력 장치
	   // 콘솔 입력 장치

float sol(float a, float b, int c);//입력한결과를 계산해주는 함수
void unzero();//미지수가 0개일때 실행하는 함수
void unone(int n);//미지수가 1개일때 실행하는 함수
void display();//초기 화면출력 함수
void xy();//프로그래밍을 할때 좌표를 알기 위해 좌표축을 띄우는 함수(제작할때 사용)
void number(int a, int b, int c);//해당하는 숫자를 해당 좌표에 출력하는 함수
int unknown(int x, int y);//미지수개수 물어보는 함수
int numbers(int a, int b, int c);//10 이상의 숫자를 출력하는 함수로 음수도 출력가능
int many(int x, int y); //연산을 몇번할지를 물어보는 함수
float numpad(); //숫자키보드를 화면에 띄우고 숫자를 입력받는 함수
int error(); //오류가 난 경우 모든 화면을 지우고 에러남을 알려주는 함수
float numpad2(); //연산에서 연산자를 입력받는 함수
void snum(int a, int x, int y); //연산자를 출력하는 함수
int OXpad(); //계산을 할지 말지를 물어보는 기능에서 OX를 입력받는 함수
void OX(int a, int x, int y); //화면에 OX를 띄우는 함수


void gotoxy(int x, int y);//커서를 좌표에 해당하는 위치로 이동시키는 함수
void color(int a, int b);//문자의 색과 배경색을 바꾸는 함수
int be_input();
int get_input(WORD* vkey, COORD* pos);
void click(int* x, int* y);// 이 함수들은 클릭을 하고 좌표를 따오는 함수로 인터넷에서 가져왔습니다.


int main() {

	display(); //화면을 띄우고

	int un = unknown(38, 20); //미지수 개수를 물어보고
	switch (un) {
	case 0: unzero(); //0개인 경우
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
		printf("■");
	printf("\n");
	for (int i = 0; i < 119; i++)
		printf("■");
	for (int i = 0; i < 61; i++) {
		printf("\n■■");
		printf("  ");
		for (int i = 0; i < 114; i++)
			printf("  ");
		printf("■■");
	}
	printf("\n");
	for (int i = 0; i < 119; i++)
		printf("■");
	printf("\n");
	for (int i = 0; i < 119; i++)
		printf("■");
	gotoxy(0, 51);
	for (int i = 0; i < 119; i++)
		printf("■");
	gotoxy(0, 50);
	for (int i = 0; i < 119; i++)
		printf("■");
	//이렇게 반복문으로 좌표의 위치에 네모를 출력하여 계산기의 기본적인 틀을 출력한다

}

void gotoxy(int x, int y) {
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//xy값을 받아서 그 위치로 커서를 움직이는 함수
}

void color(int a, int b) {
	int i = a + b * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i); //a는 글자의 색깔이고 b는 배경색으로 인터넷에 있는 색깔 표를 보고 입력한뒤 실행하면 이 함수 뒤의 글자들의 색이 변합니다.
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
	}//만들때 xy좌표를 직접세기엔 너무 많아서 xy좌표를 바로 알수 있도록 만든 제작할때만 사용하는 함수입니다
}

void number(int a, int b, int c) {
	switch (a) {//a에 출력할 함수를 받고 b와 c가 각각 xy값을 받아서 그 위치에 a를 출력한다.
	case 0:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("■  ■");
		gotoxy(b, c + 2);
		printf("■  ■");
		gotoxy(b, c + 3);
		printf("■  ■");
		gotoxy(b, c + 4);
		printf("■■■");
		break;

	case 1:
		gotoxy(b, c);
		printf("  ■  ");
		gotoxy(b, c + 1);
		printf("  ■  ");
		gotoxy(b, c + 2);
		printf("  ■  ");
		gotoxy(b, c + 3);
		printf("  ■  ");
		gotoxy(b, c + 4);
		printf("  ■  ");
		break;

	case 2:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("    ■");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("■    ");
		gotoxy(b, c + 4);
		printf("■■■");
		break;
	case 3:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("    ■");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("    ■");
		gotoxy(b, c + 4);
		printf("■■■");
		break;
	case 4:
		gotoxy(b, c);
		printf("■  ■");
		gotoxy(b, c + 1);
		printf("■  ■");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("    ■");
		gotoxy(b, c + 4);
		printf("    ■");
		break;
	case 5:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("■    ");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("    ■");
		gotoxy(b, c + 4);
		printf("■■■");
		break;
	case 6:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("■    ");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("■  ■");
		gotoxy(b, c + 4);
		printf("■■■");
		break;
	case 7:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("■  ■");
		gotoxy(b, c + 2);
		printf("■  ■");
		gotoxy(b, c + 3);
		printf("    ■");
		gotoxy(b, c + 4);
		printf("    ■");
		break;
	case 8:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("■  ■");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("■  ■");
		gotoxy(b, c + 4);
		printf("■■■");
		break;
	case 9:
		gotoxy(b, c);
		printf("■■■");
		gotoxy(b, c + 1);
		printf("■  ■");
		gotoxy(b, c + 2);
		printf("■■■");
		gotoxy(b, c + 3);
		printf("    ■");
		gotoxy(b, c + 4);
		printf("■■■");
		break;
	}
}

float sol(float a, float b, int c) {//a에 계산할 첫번째 값, b에 계산할 2번째 값을 입력 받고 연산자 값을 아스키코드 값으로 받아 계산하고 그 값을 반환한다
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
	num = many(39, 20);//연산을 몇번 할지 물어보고 그 값을 num에 저장합니다
	gotoxy(44, 20);
	printf("■■■■    ■    ■    ■■  ■   ■■■   ■");	gotoxy(44, 21);
	printf("      ■   ■■   ■   ■  ■ ■       ■ ■■");	gotoxy(44, 22);
	printf("   ■    ■    ■ ■    ■■  ■   ■■■   ■");	gotoxy(44, 23);
	printf(" ■■■           ■          ■   ■     ■■");	gotoxy(44, 24);
	printf("   ■     ■■■■       ■  ■    ■■■   ■");	gotoxy(44, 25);
	printf(" ■  ■         ■       ■  ■      ■■■■ ");	gotoxy(44, 26);
	printf("   ■           ■       ■■■            ■ ");// 공식을 입력하라고 출력해주고
	int d;
	float a, b;
	a = numpad();//미지수가 없으므로 처음 값을 numpad함수로 입력 받아 a에 저장
	for (int i = 0; i < num; i++) {
		d = numpad2();//연산자를 입력받아 d에 넣어주고
		b = numpad();//계산할 두번째 값을 numpad함수로 입력받아 b에 저장
		a = sol(a, b, d);// 앞에서 입력받은 값들을 계산하여 a에 다시 저장
	}// 이 과정을 연산을 몇 번한지 저장한 n번 반복한다.
	numbers((int)a, 20, 20);//끝까지 계산한 값을 해당 좌표에 출력해준다
	return;
}

void unone(int n) {
	int num, n2;
	num = many(32, 20);
	gotoxy(44, 20);
	printf("■■■■    ■    ■    ■■  ■   ■■■   ■");	gotoxy(44, 21);
	printf("      ■   ■■   ■   ■  ■ ■       ■ ■■");	gotoxy(44, 22);
	printf("   ■    ■    ■ ■    ■■  ■   ■■■   ■");	gotoxy(44, 23);
	printf(" ■■■           ■          ■   ■     ■■");	gotoxy(44, 24);
	printf("  ■■    ■■■■       ■  ■    ■■■   ■");	gotoxy(44, 25);
	printf(" ■  ■         ■       ■  ■       ■■■■");	gotoxy(44, 26);
	printf("  ■■          ■       ■■■             ■");//여기까지는 unzero와 동일
	float num2[100] = { 0 };//계산할 값을 입력받을 배열
	char what[100] = { 0 };//연산자를 저장해줄 배열
	float mis;//미지수값을 저장할 변수
	float ans2;//계산 값을 저장할 변수
	for (int j = 0; j < n - 1; j++) {
		what[j] = numpad2();//미지수 가 들어가서 숫자 입력없이 연산자만 받아야 하는 횟수만큼 받고
		snum(what[j], 40, 40);//각각 입력받은 값을 잠시 표시해 줍니다.
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
		what[i + n - 1] = numpad2();//연산자를 what배열의 i번째 자리에 저장해줍니다
		num2[i + n - 1] = numpad();//숫자를 num2배열의 i번째 자리에 저장합니다.
	}//연산횟수만큼 반복해 줍니다.
	gotoxy(44, 20);
	printf("                                              ");	gotoxy(44, 21);
	printf("                                              ");	gotoxy(44, 22);
	printf("                                              ");	gotoxy(44, 23);
	printf("                                              ");	gotoxy(44, 24);
	printf("                                              ");	gotoxy(44, 25);
	printf("                                              ");	gotoxy(44, 26);
	printf("                                              ");//공식입력이라는 글을 화면에서 지워줍니다

	int p = 0;
	number(0, 6, 4);//첫번째 미지수를 표시해 주고
	for (int i = 0; i < num + n - 1; i++) {
		snum(what[i], 10 + 5 * i + 4 * p, 4);
		p += numbers(num2[i], 16 + 5 * i + 4 * p, 4);//공식들을 출력해 줍니다. 이때 숫자가 2자리 수일수도 3자리 수일 수도 있으므로 numbers에서 반환하는 숫자 자리수를 이용하여 좌표를 정해 줍니다.
	}
	while (1) {
		char ans = OXpad();//함수 OXpad를 이용하여 사용자가 O를 선택했는지 X를 선택했는지 입력받아 저장해 줍니다.
		if (ans == 'O') {//만약 O일 경우
			gotoxy(40, 40);
			printf("                                                   "); gotoxy(40, 41);
			printf("                                                   "); gotoxy(40, 42);
			printf("                                                   "); gotoxy(40, 43);
			printf("                                                   "); gotoxy(40, 44);
			printf("                                                   "); gotoxy(40, 45);
			printf("                                                   ");//처음이 아닐경우 이자리에 전 계산값이 출력되어있을 것 이므로 지워줍니다.
			p = 0;
			mis = numpad();//미지수 값을 numpad로 입력받습니다.
			p = numbers(mis, 8, 10);//첫번째 미지수 값을 출력해주고
			int m = 0;
			for (int k = 0; k < n - 1; k++) {
				num2[k] = numpad();//남은 미지수값들을 입력, 출력해줍니다.
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
			printf("                                                                                                                                                                             ");//미지수 값들이 출력되어있는것을 지워줍니다.

			ans2 = mis;
			for (int i = 0; i < num + n - 1; i++) {
				ans2 = sol(ans2, num2[i], what[i]);
			}//연산횟수만큼 계산을 반복하여 저장해준다.
			numbers(ans2, 40, 40);//그 값을 출력해줍니다.
		}
		else if (ans == 'X')
			break;//X를 입력할 경우 함수를 종료해줍니다.
	}
}

int unknown(int x, int y) {
	gotoxy(x, y);
	printf("            ■              ■      ■            ■■            ■  ■"); gotoxy(x, y + 1);
	printf("  ■■■■  ■  ■■■■■  ■    ■  ■        ■    ■  ■■■■■  ■"); gotoxy(x, y + 2);
	printf("  ■    ■  ■      ■      ■  ■      ■  ■      ■        ■  ■■■"); gotoxy(x, y + 3);
	printf("  ■    ■  ■    ■  ■    ■  ■■■■■         ■       ■    ■■■"); gotoxy(x, y + 4);
	printf("  ■■■■  ■  ■      ■  ■      ■      ■            ■      ■  ■"); gotoxy(x, y + 5);
	printf("            ■              ■      ■             ■             ■  ■");//미지수개수를 물어보도록 출력합니다
	int un;//미지수 개수를 저장할 변수
	while (1) {
		un = numpad();//미지수 개수 저장
		if (un >= 10)
			error();
		else
			break;
	}
	gotoxy(x + 24, y);
	for (int i = 0; i < 6; i++) {
		printf("        ");
		gotoxy(x + 24, y + i);//물음표 자리를 지운다
	}
	number(un, x + 24, y + 1);//물음표 자리에 숫자를 출력
	Sleep(1000);//숫자를 입력받음을 표시하기 위해 1초 대기
	gotoxy(x, y);
	printf("                                                                        "); gotoxy(x, y + 1);
	printf("                                                                        "); gotoxy(x, y + 2);
	printf("                                                                        "); gotoxy(x, y + 3);
	printf("                                                                        "); gotoxy(x, y + 4);
	printf("                                                                        "); gotoxy(x, y + 5);
	printf("                                                                        ");
	return un;//글자들 삭제한뒤 미지수 개수 반환
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

	int event;        // 마우스 이벤트에 이용
			// 마우스의 y좌표 저장소

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				*x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
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
			printf("■");
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
		printf("            ");//연산자가 출력되어있을 수도 있으므로 초기화
		number(i - 1, posx + 2, posy + 3);
		gotoxy(99 + 2, 50 + 3);
		printf("          ■");
		gotoxy(99 + 2, 50 + 4);
		printf("  ■      ■");
		gotoxy(99 + 2, 50 + 5);
		printf("■■■■■■");
		gotoxy(99 + 2, 50 + 6);
		printf("  ■        ");//엔터자리에 엔터 모양 출력

		gotoxy(109, 53);
		printf("      ■■      ");
		gotoxy(109, 54);
		printf("   ■      ■    ");
		gotoxy(109, 55);
		printf("  ■        ■  ");
		gotoxy(109, 56);
		printf("■■■       ■ ");
		gotoxy(109, 57);
		printf("  ■         ■ ");
		gotoxy(109, 58);
		printf("            ■  ");
		gotoxy(109, 59);
		printf("    ■    ■    ");
		gotoxy(109, 60);
		printf("      ■■      ");//초기화 할 기호 출력
	}
	int num[7];
	DWORD mode;
	WORD key;
	COORD pos;
	int x;
	int y;
	int event;        // 마우스 이벤트에 이용
	int n = 0;

	for (int j = 0; j < 7; j++) {
		num[j] = -1;
	}//숫자를 입력받을경우 

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				y = pos.Y;
				for (int i = 0; i <= 9; i++) {
					if (y <= 62 && y >= 52) {
						if (x <= 35 - 18 && x >= 2) {
							return -5;//미지수를 선택하면 -5를 반환한다
						}
						if (x <= 35 + 18 * i && x >= 20 + 18 * i) {
							gotoxy(2 + n, 49);
							num[n] = i;

							n++;
							printf("%d", i);//숫자를 선택하면 이 숫자로 선택할지 작게 표시
						}

					}
				}if (y <= 62 && y >= 52) {
					if (x <= 215 && x >= 200) {
						gotoxy(2, 49);
						printf("             ");
						break;
					}//엔터를 누르면 숫자를 표시한곳을 지우고 반복문에서 탈출한다
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
				}//초기화 버튼을 누르면 숫자 초기화
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
	}//가장 높은 자리 숫자가 0인경우 제외시킨다


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
	}//자릿수를 찾아 저장
	for (int k = 0; k < a; k++) {
		number += num[6 - k] * (int)pow(10, k);
	}//숫자로 다시 만듬


	gotoxy(2, 52);
	printf("              ");
	return (float)number;//반환
}

int numbers(int a, int b, int c) {
	int n = 1, num, num1 = a;
	int m = 0;

	if (a < 0) {
		a = -a;
		m = 3;
		gotoxy(b, c + 2);
		printf("■■  ");//음수인 경우 마이너스를 출력하고 숫자를 출력해 줍니다.
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
	return n;//number를 이용하여 10이상의 수를 출력하는 함수
}

int many(int x, int y) {
	gotoxy(x, y);
	printf("           ■       ■     ■           ■             ■■                      ■■■■■   ■  ■"); gotoxy(x, y + 1);
	printf("  ■■   ■■     ■  ■   ■         ■  ■     ■  ■    ■                           ■    ■  ■"); gotoxy(x, y + 2);
	printf("■    ■   ■   ■      ■ ■■■   ■      ■            ■                           ■     ■■■"); gotoxy(x, y + 3);
	printf("  ■■   ■■              ■      ■■■■■■         ■                            ■      ■  ■"); gotoxy(x, y + 4);
	printf("      ■              ■   ■           ■       ■                                  ■       ■  ■"); gotoxy(x, y + 5);
	printf("      ■■■■        ■■■■■        ■              ■                          ■        ■  ■"); gotoxy(x, y + 6);
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
	printf("                                                                                                    ");//미지수 개수 물어보는 것과 비슷합니다.
	return un;
}

int error() {
	int x = 49;


	for (int i = 0; i < 3; i++) {
		color(15, c2);
		gotoxy(x, 26);
		printf("■■■ ■■■ ■■■ ■■■ ■■■"); gotoxy(x, 27);
		printf("■     ■  ■ ■  ■ ■  ■ ■  ■"); gotoxy(x, 28);
		printf("■■■ ■■   ■■   ■  ■ ■■  "); gotoxy(x, 29);
		printf("■     ■  ■ ■  ■ ■  ■ ■  ■"); gotoxy(x, 30);
		printf("■■■ ■  ■ ■  ■ ■■■ ■  ■");
		Sleep(300);
		color(4, c2);
		gotoxy(x, 26);
		printf("■■■ ■■■ ■■■ ■■■ ■■■"); gotoxy(x, 27);
		printf("■     ■  ■ ■  ■ ■  ■ ■  ■"); gotoxy(x, 28);
		printf("■■■ ■■   ■■   ■  ■ ■■  "); gotoxy(x, 29);
		printf("■     ■  ■ ■  ■ ■  ■ ■  ■"); gotoxy(x, 30);
		printf("■■■ ■  ■ ■  ■ ■■■ ■  ■");//에러가 난경우 하얀색이었다가 빨간색이도록 깜빡여 줍니다.
		Sleep(300);

	}
	gotoxy(x, 26);
	printf("                                  "); gotoxy(x, 27);
	printf("                                  "); gotoxy(x, 28);
	printf("                                  "); gotoxy(x, 29);
	printf("                                  "); gotoxy(x, 30);
	printf("                                  ");//지워줍니다.
	color(c1, c2);
}

float numpad2() {
	int posx, posy;
	for (int i = 1; i <= 12; i++) {
		posx = i * 9, posy = 50;
		gotoxy(posx, posy);
		for (int i = 0; i < 15; i++) {
			printf("■");
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
		case 11:break;//숫자들이 키보드에 적혀있는것을 지워주고 연산자들을 키보드에 출력해줍니다.
		case 12: break;

		}


	}
	DWORD mode;
	WORD key;
	COORD pos;
	int x;
	int y;
	int event;        // 마우스 이벤트에 이용
	int n = 0;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);


	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
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

						}//각자리마다 클릭된 기호들을 반환해줍니다.


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
		printf("    ■    "); gotoxy(posx + 2, posy + 4);
		printf("    ■    "); gotoxy(posx + 2, posy + 5);
		printf("■■■■■"); gotoxy(posx + 2, posy + 6);
		printf("    ■    "); gotoxy(posx + 2, posy + 7);
		printf("    ■    ");
		break;
	case '-':
		gotoxy(posx + 2, posy + 3);
		printf("          "); gotoxy(posx + 2, posy + 4);
		printf("          "); gotoxy(posx + 2, posy + 5);
		printf("■■■■■"); gotoxy(posx + 2, posy + 6);
		printf("          "); gotoxy(posx + 2, posy + 7);
		printf("          ");
		break;
	case '*':
		gotoxy(posx + 2, posy + 3);
		printf("■      ■"); gotoxy(posx + 2, posy + 4);
		printf("  ■  ■  "); gotoxy(posx + 2, posy + 5);
		printf("    ■    "); gotoxy(posx + 2, posy + 6);
		printf("  ■  ■  "); gotoxy(posx + 2, posy + 7);
		printf("■      ■");
		break;
	case '/':
		gotoxy(posx + 2, posy + 3);
		printf("    ■    "); gotoxy(posx + 2, posy + 4);
		printf("          "); gotoxy(posx + 2, posy + 5);
		printf("■■■■■"); gotoxy(posx + 2, posy + 6);
		printf("          "); gotoxy(posx + 2, posy + 7);
		printf("    ■    ");
		break;
	case '^':
		gotoxy(posx + 2, posy + 3);
		printf("          "); gotoxy(posx + 2, posy + 4);
		printf("    ■    "); gotoxy(posx + 2, posy + 5);
		printf("  ■  ■  "); gotoxy(posx + 2, posy + 6);
		printf("■      ■"); gotoxy(posx + 2, posy + 7);
		printf("          ");
		break;
	case '!':
		gotoxy(posx + 2, posy + 3);
		printf("    ■■■  "); gotoxy(posx + 2, posy + 4);
		printf("  ■        "); gotoxy(posx + 2, posy + 5);
		printf("  ■        "); gotoxy(posx + 2, posy + 6);
		printf("■■        "); gotoxy(posx + 2, posy + 7);
		printf("  ■        ");
		break;//연산자들을 출력해주는 함수입니다.
	}
}

int OXpad() {
	int posx, posy;
	for (int i = 1; i <= 12; i++) {
		posx = i * 9, posy = 50;
		gotoxy(posx, posy);
		for (int i = 0; i < 15; i++) {
			printf("■");
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
		case 11:break;//키보드에 적힌 값들을 지워주고 연산자들을 출력해줍니다.
		case 12: break;
		}
	}
	DWORD mode;
	WORD key;
	COORD pos;
	int x;
	int y;
	int event;        // 마우스 이벤트에 이용
	int n = 0;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);


	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				y = pos.Y;
				for (int i = 0; i <= 9; i++) {
					if (y <= 62 && y >= 52) {
						if (x <= 35 + 18 * i && x >= 20 + 18 * i) {
							switch (i) {
							case 0: return(float)'O';
							case 1: return  (float)'X';
							}//각 자리 값들을 반환해줍니다.

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
		printf("   ■■   "); gotoxy(posx + 2, posy + 4);
		printf(" ■    ■ "); gotoxy(posx + 2, posy + 5);
		printf("■      ■"); gotoxy(posx + 2, posy + 6);
		printf(" ■    ■ "); gotoxy(posx + 2, posy + 7);
		printf("   ■■   ");
		break;
	case '-':
		gotoxy(posx + 2, posy + 3);
		printf("■      ■"); gotoxy(posx + 2, posy + 4);
		printf("  ■  ■  "); gotoxy(posx + 2, posy + 5);
		printf("    ■    "); gotoxy(posx + 2, posy + 6);
		printf("  ■  ■  "); gotoxy(posx + 2, posy + 7);
		printf("■      ■");
		break;//각자리에 OX값들을 반환해줍니다.
	}
}