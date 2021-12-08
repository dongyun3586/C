#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <Windows.h>
// window.h 와 Windows.h 는 콘솔창 상에서 변화를 주기위해 이용. 시간지연과 색상변경
//conio.h 는 글자를 입력받는 기능을 위해 사용하였다. 
#define MAXX 189 // 최대 가로 칸 수
#define MAXY 49  // 최대 세로 줄 수 (전체화면기준)

#define PASSWORD 31415926535 // 설정해둔 비밀번호 (코드내 사용X)

char ScreenArr[MAXY][MAXX] = { 0 };  // 화면에 나타날 각 칸들에 대한 배열
int PWflg = 0; // 비밀번호 입력 시 비밀번호가 맞는지 틀린지 상태 나타내는 변수
char BS[100] = { 0 }; // 염기 서열을 입력받고 전기영동 화면 출력을 위해 저장해두는 배열
int TorUflg = 0; // DNA 인지 RNA인지 상태를 나타내는 변수

//화면 값 초기화 함수
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

//중간 과정에서 화면 전체를 = 로 가득 채우는함수
void Set() {
	for (int y = 0; y < MAXY; y++) {
		for (int x = 0; x < MAXX; x++) {
			ScreenArr[y][x] = '=';
		}
	}
}

// 비밀번호 대조를 위해 존재하는 함수. 비밀번호 값을 담고있음.
char Password[] = "31415926535";

//원하는 내용의 문자열과 그 문자열의 시작 좌표를 입력하면 그 지점부터 문자열을 화면(ScreenArr 배열)으로 옮기는 함수
void ChangeScreen(char Strprt[], int x, int y);

// 화면(ScreenArr 배열) 을 출력하는 함수.
void ShowScreen();

//사용자로부터 문자를 입력 받아 이를 x,y 좌표부터 화면으로 옮기는 함수. b누를시 지우기, x누를시 입력종료
void GetScreen(int x, int y);

//사용자가 입력한 비밀번호와 설정된 비밀번호가 같은지 확인하는 함수. 틀리다면 다시 입력하도록 함.
int CheckPassword();

//위의 함수들을 묶어둔 로그인 과정 함수
void LogIn();

// RNA 인지 DNA인지를 설정하는 함수. 그 여부를 TorUflg 변수에 전달하여 다른 함수들이 flg로 활용. r 또는 d를 눌러 설정 후 x를 눌러 확인.
void CheckWhatToDo();

// 염기서열을 입력받기 전 입력해달라고 고지하는 함수. 
void GetCode(int flg);

//염기서열을 입력받는 함수. A,T,U,G,C로 입력받을 수 있다(나머진 입력해도 인식 X). b를 눌러 지우고 x눌러 완료.
void GetBasePair(int x, int y, int flg);

//로딩화면
void SayIWillMakeIt();

//전기영동 결과화면의 틀을 갖추는 함수. 핵산의 크기를 알 수 있도록 해주는 특정 기준 핵산의 결과는 여기서 초기설정해준다.
void ElectrophoresisStatus();

// BS[]에 담긴 입력받은 염기서열을 읽으며 화면에 각 핵산의 종결자 염기에 따라 다른 줄로 화면에 나타내 준다.
void ChangeElectrophoresisStatus();

//출력창에서 a를 누르면 새로운 작업 시작 가능
void DoItAgain();


int main() {
	FirstSet();
	LogIn();
	Sleep(1000); // 외부라이브러리
GO: // 반복 시작지점
	CheckWhatToDo();
	GetCode(TorUflg);
	SayIWillMakeIt();
	ElectrophoresisStatus();
	ChangeElectrophoresisStatus();
	DoItAgain();
	goto GO;  // 반복을 위해 goto 사용
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
	int i = 0, checker = 0; // i는 입력된 암호의 자릿수 조사, checker는 일치한 숫자의 개수조사
	for (i = 0; ScreenArr[27][89 + i] != ' '; i++) {
		if (Password[i] == ScreenArr[27][89 + i]) {
			checker++;
		}
	}
	if (checker == 11 && i == checker) { return 1; } // i와 checker값이 같고(자릿수 일치) i가 11(11자리 모두 맞음) 일 경우 비밀번호 맞다는 판정
	else { return 0; }

	//이 코드는 31415926535 라는 비밀번호에 특수화되어 짜여진 코드이다. 
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
		int Get = _getch();  // 외부라이브러리
		if (Get == 'x') { break; }
		char UnderBar_d[] = "        ===";
		if (Get == 'r') { ChangeScreen(UnderBar, 89, 28); flg = 0; }
		else if (Get == 'd') { ChangeScreen(UnderBar_d, 89, 28); flg = 1; }
		ShowScreen();
	}
	TorUflg = flg;  // 전역변수 TorUflg 에 0 또는 1을 넘겨 수행할 작업의 종류를 다른 함수에 전달
}
struct EnterCode {
	char EnterCode[35];
};
// 두 종류의 작업에 대한 안내문을 편하게 생성하기 위해 문자열만 있는 구조체 사용

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
		char Get = _getch(); // 별도의 conio.h 헤더파일에 있는 함수. 입력된 문자 한 개를 출력하지 않고 그 값을 변수로 넘긴다.  // 외부라이브러리
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
				// 입력된 염기에 따라 다른 상황의 switch-case문
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
	char(*ptr)[15] = Load;  // 포인터를 이용해 Load를 이동
	char Clear25[] = "                               "; //출력되어 있는 로딩문을 지우기 위한 문자열
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

//전기영동 결과 출력 시 실제와 유사한 색으로 출력하기 위해 별도의 헤더 파일에서 함수와 값 사용
void ShowScreen2() {
	system("cls");  // 외부라이브러리
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * 3 + 5); // 2진수로 8칸 중 앞의 네 칸, 뒤의 네 칸을 따로 읽어 색상을 결정한다. 앞의 네 칸의 수는 배경색, 뒤의 네 칸은 글자색을 결정한다.  // 외부라이브러리
	for (int y = 0; y < 121; y++) {
		for (int x = 0; x < 189; x++) {
			if (x < 78) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * 7 + 1);  // 외부라이브러리
			}
			printf("%c", Electrophoresis[y][x]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 외부라이브러리
		}
	}
}
// 9~16 , 22~29 , 35~42 , 48~55 , 61~68 (Line이 위치할 칸을 메모해 둔 것)
char Line[] = "========="; // 이동한 입자를 나타내는 선
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

	// 형태를 맞추기 위한 코드들이므로 중요하지 않다.(수작업으로 맞추고 계산해서 모양만 냈다.)
	ShowScreen2();
}
// 새로운 작업을 위해 BS 문자열을 초기화하는 함수
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

			//이전 작업에서 변화된 모든 변수,문자열 초기화
			break;
		}
	}
}