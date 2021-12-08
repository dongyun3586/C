#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <mmsystem.h>

int loading(int Howmanyrepeat);		//로딩 횟수. 제작 과정에서는 0
void gotoxy(int x, int y);			//커서 이동함수
void say(char say[20], int n);		//n:millisecond 말을 하는 함수
void Division(int p);				//UI 줄 깔기
void PrintLogo();					//로고를 프린트합니다
void UIsetting(int* Nums[30], int* Acode[30], int* Bcode[30]);	//UI세팅을 총괄
void Assignment(int* Nums[30], int* Acode[30], int* Bcode[30]); //초기 코드를 랜덤으로 분배 (Joker 제외)
void MainMenu();					//메인메뉴를 보여줌
void GameStart();					//메인메뉴 - 게임시작시 알고리즘이 포함된 함수.
void GameRule();					//메인메뉴 - 게임방법을 보여줌
void PrintNum(char T, int N);				//코드의 숫자를 출력합니다.
void SortString(int* String);		//숫자를 순서대로 자동배열합니다. 
void PrintcodeA(int* Acode[30]);	//A의 코드를 출력합니다.
void PrintcodeB(int* Bcode[30]);	//B의 코드를 출력합니다.
int turn(char C, int n);		//두가지 기능. n=0이면 C의 턴이 맞는지 확인. n=1이면 turn을 전환
void Countdowningame(int n);	//카운트다운 - 초기코드 보여줌
void Countdowntochangeturn();	//카운트다운 - 턴 전환시
int Choose();
void PlusCode(int* Acode[30]);  //코드를 매 턴 추가해줌

char charidentification;		//turn 함수에서 사용. 누구의 턴인지 저장
int memory[100] = { 0 };

int main() {
	system("cls");
	gotoxy(46, 12);
	say("■□ Davinci Code ■□", 100); //０１２３４５６７８９
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
	printf("■ 게임 시작");
	gotoxy(53, 19);
	printf("□ 게임 방법");
	gotoxy(53, 22);
	printf("□ 게임 종료");
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
			case 1: gotoxy(53, 19); printf("□"); gotoxy(53, 22); printf("□"); gotoxy(53, 16); printf("■"); break;
			case 2: gotoxy(53, 16); printf("□"); gotoxy(53, 22); printf("□"); gotoxy(53, 19); printf("■"); break;
			case 3: gotoxy(53, 16); printf("□"); gotoxy(53, 19); printf("□"); gotoxy(53, 22); printf("■"); break;
			}
			gotoxy(99, 25);
		}
	}
}

void PrintLogo() {
	Sleep(200);
	system("cls");
	say("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", 0);
	say("■■■□□□□■■■□□□■■□■■□■□■□■■■□■■□□□■□■■■■■■□□□■■□□■■□□□■■□□□■■■\n", 0);
	say("■■■□■■□□■□■■■□■□■■□■□■□■■■□■□■■■■□■■■■■□■■■■□■■□■□■□□■□■■■■■\n", 0);
	say("■■■□■■■□■□■■■□■□■■□■□■□□■■□■□■■■■□■■■■■□■■■■□■■□■□■■□■□■■■■■\n", 0);
	say("■■■□■■■□■□■■■□■□■■□■□■□■□■□■□■■■■□■■■■■□■■■■□■■□■□■■□■□■■■■■\n", 0);
	say("■■■□■■■□■□■■■□■□■■□■□■□■□■□■□■■■■□■■■■■□■■■■□■■□■□■■□■□□□■■■\n", 0);
	say("■■■□■■■□■□□□□□■□■■□■□■□■■□□■□■■■■□■■■■■□■■■■□■■□■□■■□■□■■■■■\n", 0);
	say("■■■□■■■□■□■■■□■□■■□■□■□■■■□■□■■■■□■■■■■□■■■■□■■□■□■■□■□■■■■■\n", 0);
	say("■■■□■■■□■□■■■□■□■■□■□■□■■■□■□■■■■□■■■■■□■■■■□■■□■□■■□■□■■■■■\n", 0);
	say("■■■□■■□□■□■■■□■□■□■■□■□■■■□■□■■■■□■■■■■□■■■■□■■□■□■□□■□■■■■■\n", 0);
	say("■■■□□□□■■□■■■□■■□■■■□■□■■■□■■□□□■□■■■■■■□□□■■□□■■□□□■■□□□■■■\n", 0);
	say("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", 0);
	gotoxy(0, 0);
}

void GameRule() {
	int keypress;
	system("cls");
	say("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n", 0);
	say("이 게임의 조작법은 W, A, S, D, Enter 뿐입니다. 간단하죠? \n\n", 0);
	say("일반적으로 메인 조작법인 W, A, S, D는 순서대로 위, 왼쪽, 아래, 오른쪽입니다. \n\n", 0);
	say("플레이어 2도 같은 조작법으로 조작합니다.\n\n", 0);
	say("처음 차례에는 플레이어 1이, 다음은 플레이어 2가 차례로 자신의 패를 확인합니다.\n\n", 0);
	say("조커 카드는 자신이 끼워넣고싶은 위치에 끼워넣을 수 있습니다. \n\n", 0);
	say("자신의 턴이 되면 하나의 코드를 가져오며, 상대의 코드를 추리할 기회를 얻습니다.\n\n", 0);
	say("순서대로 상대의 패를 맞히게 됩니다. 이때 맞으면 공개되고,원한다면 한번 더 할 수 있습니다.\n\n", 0);
	say("선택해서 틀리게되면 자신의 코드 하나를 공개해야합니다.\n\n", 0);
	say("코드가 모두 공개되면 패배합니다.\n\n", 0);
	say("Press Enter to go mainmenu...", 0);
	say("\n\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", 0);
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
	say("코 드 확 인 - A", 20);
	Countdowntochangeturn();
	Division(1);
	UIsetting(Nums, Acode, Bcode);
	Assignment(Nums, Acode, Bcode);

	//순서대로 정렬
	SortString(Acode);
	SortString(Bcode);

	turn('A', 1);			//A의 턴으로 전환
	PrintcodeA(Acode);		//코드 출력
	PrintcodeB(Bcode);
	Countdowningame(3);

	system("cls");
	gotoxy(51, 5);
	say("코 드 확 인 - B", 20);
	Countdowntochangeturn();
	Division(1);
	UIsetting(Nums, Acode, Bcode);

	turn('B', 1);			//B의 턴으로 전환
	PrintcodeA(Acode);		//코드 출력
	PrintcodeB(Bcode);
	Countdowningame(3);

	int Pointflag = 0; //첫턴에는 PlusCode함수가 실행되지 않도록 하는 변수

	while (End == 0) {
		if (swip % 2 == 0) {	//A
			system("cls");
			gotoxy(52, 5);
			say(" T U R N - A", 20);
			Countdowntochangeturn();
			Division(1);
			UIsetting(Nums, Acode, Bcode);

			turn('A', 1);			//A의 턴으로 전환
			if (Pointflag != 0) {
				PlusCode(Acode);
			}

			PrintcodeA(Acode);		//코드 출력
			PrintcodeB(Bcode);

			if (Choose() == 1) { //추측
				int n, num, chn, check = 0, Nonecode = 0;
				gotoxy(1, 23); printf("                                          ");
				gotoxy(1, 24); printf("                                          ");
				gotoxy(1, 25); printf("                                          ");
				gotoxy(1, 27);
				printf("공개됨 :");
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
				printf(" 코드");
				if (Nonecode == 0) {
					printf(" 없음");
				}
				gotoxy(1, 23);
				say("추측을 선택하셨습니다.", 10);
				while (1) {
					lengthB = 0;
					gotoxy(1, 24);
					printf("                                          ");
					gotoxy(1, 24);
					say("몇번째 코드를 추측합니까? : ", 10);
					for (int i = 0; Bcode[i] != 33; i++) {
						lengthB++;
					}
					scanf("%d", &n);
					if (n > lengthB) {		//이미 공개된 코드이거나 없는 코드
						gotoxy(1, 25);
						say("!!! 이미 공개되었거나 없는 코드입니다 !!! ", 10);
					}
					else {
						if (memory[Bcode[n - 1]] == 1) {		//이미 공개된 코드이거나 없는 코드
							gotoxy(1, 25);
							say("!!! 이미 공개되었거나 없는 코드입니다 !!! ", 10);
						}
						else { break; }
					}
				}

				gotoxy(1, 25);
				printf("                                          ");
				gotoxy(1, 25);
				say("코드는 몇일까요? : ", 10);
				scanf("%d", &num);
				if (Bcode[n - 1] == num || Bcode[n - 1] == num + 13) {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("추측에 성공하셨습니다! :D", 10);
					memory[Bcode[n - 1]] = 1;
					Sleep(500);

					//다시 선택권을 줌
				}
				else {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("추측에 실패하셨습니다 :( ", 10);

					for (int i = 0; Acode[i] != 33; i++) {
						lengthA++;
					}

					while (check == 0) {
						gotoxy(1, 24);
						printf("                                          ");
						gotoxy(1, 24);
						say("자신의 코드 하나를 공개해야합니다... 공개할 코드 : ", 10);
						scanf("%d", &chn);
						if (memory[Acode[chn - 1]] == 1 || chn > lengthA) {		//이미 공개된 코드이거나 없는 코드
							gotoxy(1, 25);
							printf("                                          ");
							gotoxy(1, 25);
							say("!!! 이미 공개되었거나 없는 코드입니다 !!! ", 10);
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
			else { //턴 넘기기
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

			turn('B', 1);			//B의 턴으로 전환

			if (Pointflag != 0) {
				PlusCode(Bcode);
			}
			PrintcodeA(Acode);		//코드 출력
			PrintcodeB(Bcode);

			if (Choose() == 1) { //추측
				int n, num, chn, check = 0, Nonecode = 0;
				gotoxy(1, 23); printf("                                          ");
				gotoxy(1, 24); printf("                                          ");
				gotoxy(1, 25); printf("                                          ");
				gotoxy(1, 27);
				printf("공개됨 :");
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
				printf(" 코드");
				if (Nonecode == 0) {
					printf(" 없음");
				}
				gotoxy(1, 23);
				say("추측을 선택하셨습니다.", 10);
				while (1) {
					lengthA = 0;
					gotoxy(1, 24);
					printf("                                          ");
					gotoxy(1, 24);
					say("몇번째 코드를 추측합니까? : ", 10);
					for (int i = 0; Acode[i] != 33; i++) {
						lengthA++;
					}
					scanf("%d", &n);
					if (memory[Acode[n - 1]] == 1 || n > lengthA) {		//이미 공개된 코드이거나 없는 코드
						gotoxy(1, 25);
						say("!!! 이미 공개되었거나 없는 코드입니다 !!! ", 10);
					}
					else { break; }
				}

				gotoxy(1, 25);
				printf("                                          ");
				gotoxy(1, 25);
				say("코드는 몇일까요? : ", 10);
				scanf("%d", &num);
				if (Acode[n - 1] == num || Acode[n - 1] == num + 13) {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("추측에 성공하셨습니다! :D", 10);
					memory[Acode[n - 1]] = 1;
					Sleep(500);

					//다시 선택권을 줌
				}
				else {
					gotoxy(1, 23); printf("                                ");
					gotoxy(1, 24); printf("                                ");
					gotoxy(1, 25); printf("                                ");
					gotoxy(1, 23);
					say("추측에 실패하셨습니다 :( ", 10);

					for (int i = 0; Bcode[i] != 33; i++) {
						lengthB++;
					}

					while (check == 0) {
						gotoxy(1, 24);
						printf("                                          ");
						gotoxy(1, 24);
						say("자신의 코드 하나를 공개해야합니다... 공개할 코드 : ", 10);
						scanf("%d", &chn);
						if (memory[Bcode[chn - 1]] == 1 || chn > lengthB) {		//이미 공개된 코드이거나 없는 코드
							gotoxy(1, 25);
							printf("                                          ");
							gotoxy(1, 25);
							say("!!! 이미 공개되었거나 없는 코드입니다 !!! ", 10);
						}
						else {
							memory[Bcode[chn - 1]] = 1;
							check = 1;
						}
					}
					swip++;
				}
			}
			else { //턴 넘기기
				swip++;
			}
		}
	}
}

void Countdowningame(int n) {
	gotoxy(50, 26);
	printf("제한 시간 : ");
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
		printf("■");
		Sleep(10);
	}
}

void UIsetting(int* Nums[30], int* Acode[30], int* Bcode[30]) {

	gotoxy(0, 0);
	printf(" Player 1");
	gotoxy(0, 11);
	printf(" Player 2");
}

//검정 0 1 2 3 4 5 6 7 8 9 10 11 -
//    (0 1 2 3 4 5 6 7 8 9 10 11 12)
//하양 0 1 2 3 4 5 6 7 8 9 10 11 -
//    (13 14 15 16 17 18 19 20 21 22 23 24 25)

int NumRemainder[30] = { 0 };
//NumRemainder - 이미 사용된 코드 (뽑힌 코드)는 삭제시킴 (value를 99으로 만듦) 따라서 99이면 출력하지 말것

void Assignment(int* Nums[30], int* Acode[30], int* Bcode[30]) {
	for (int i = 0; i < 26; i++) {
		if (i == 12 || i == 25) {
			Nums[i] = 12;	//JOKER. 12이면 --를 출력해줘야 함.
		}
		else {
			Nums[i] = i % 13;
		}
	}

	srand(time(NULL));
	for (int i = 0; i < 4; i++) { //A유저의 코드
		int flag = 0;
		int order = rand() % 26;  //order 랜덤한 0~ 25 고유번호 값
		int value = Nums[order]; //value 고유번호에 해당하는 기호

		if (NumRemainder[order] != 99 && order != 12 && order != 25) {
			Acode[i] = order;
			NumRemainder[order] = 99;	//NumRemainder에서 사용한 코드 빼주는 작업
		}
		else {
			i--;
		}
	}
	for (int i = 0; i < 4; i++) { //B유저의 코드
		int flag = 0;
		int order = rand() % 26;  //order 랜덤한 0~ 25 고유번호 값
		int value = Nums[order]; //valude 고유번호에 해당하는 기호

		if (NumRemainder[order] != 99 && order != 12 && order != 25) {
			Bcode[i] = order;
			NumRemainder[order] = 99;	//NumRemainder에서 사용한 코드 빼주는 작업
		}
		else {
			i--;
		}
	}
	Acode[4] = 33; //원소에 0이 있어 Null로 배열 길이를 측정하기 어려움. 33으로 대체
	Bcode[4] = 33;

	//A의 코드와 B의 코드 저장 완료. 
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
			printf("□□");
			gotoxy(6 * X, 4);
			printf("   ");
			PrintNum('A', Acode[i]);
			gotoxy(6 * X, 5);
			printf("   ");
			printf("□□");
			i++;
		}
		else {
			printf("   ");
			printf("■■");
			gotoxy(6 * X, 4);
			printf("   ");
			PrintNum('A', Acode[i]);
			gotoxy(6 * X, 5);
			printf("   ");
			printf("■■");
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
			printf("□□");
			gotoxy(6 * X, 15);
			printf("   ");
			PrintNum('B', Bcode[i]);
			gotoxy(6 * X, 16);
			printf("   ");
			printf("□□");
			i++;
		}
		else {
			printf("   ");
			printf("■■");
			gotoxy(6 * X, 15);
			printf("   ");
			PrintNum('B', Bcode[i]);
			gotoxy(6 * X, 16);
			printf("   ");
			printf("■■");
			i++;
		}
	}
}

void SortString(int* String) { //0~25의 고유번호가 들어있는 상태
	//검정 0 1 2 3 4 5 6 7 8 9 10 11 -
	//    (0 1 2 3 4 5 6 7 8 9 10 11 12)
	//하양 0 1 2 3 4 5 6 7 8 9 10 11 -
	//    (13 14 15 16 17 18 19 20 21 22 23 24 25)
	int length = 0;
	for (int i = 0; String[i] != 33; i++) {
		length++;
	}
	//gotoxy(50,20);
	//printf("%d", length); 길이가 제대로 측정되는지 확인 단계

	for (int i = 0; String[i] != 33; i++) {
		for (int j = i + 1; String[j] != 33; j++) {
			if (String[i] % 13 > String[j] % 13) { //숫자가 다른 경우
				if (String[i] != 12 && String[i] != 25 && String[j] != 12 && String[j] != 25) { //Joker는 Sorting 에서 제외
					int temp = String[i];
					String[i] = String[j];
					String[j] = temp;
					//printf("	---%d ", temp);	//Sorting이 제대로 되었는지 확인 단계
				}
			}
			else if (String[i] % 13 == String[j] % 13) { //숫자가 같은 경우
				if (String[i] > String[j]) {
					if (String[i] != 12 && String[i] != 25 && String[j] != 12 && String[j] != 25) { //Joker는 Sorting 에서 제외
						int temp = String[i];
						String[i] = String[j];
						String[j] = temp;
						//printf("	+++%d ", temp); //Sorting이 제대로 되었는지 확인 단계
					}
				}
			}
		}
	}
}

int turn(char Playersign, int n) { //두가지 기능. n=0이면 C의 턴이 맞는지 확인. n=1이면 turn을 전환. Playersign은 A(Player 1) 혹은 B(Player 2)
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

void PlusCode(int* code[30]) { //A나 B의 코드에 매턴 새로운 코드 추가함
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
			Nums[i] = 12;	//JOKER. 12이면 --를 출력해줘야 함.
		}
		else {
			Nums[i] = i % 13;
		}
	}

	srand(time(NULL));
	while (1) {
		int order = rand() % 26;  //order 랜덤한 0~ 25 고유번호 값
		int value = Nums[order];

		if (NumRemainder[order] != 99) {
			int length = 0;
			for (int i = 0; code[i] != 33; i++) {
				length++;
			}

			if (order != 12 && order != 25) { //Joker 아님
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
				say("Joker Code를 얻었습니다!", 10);
				gotoxy(1, 24);
				say("몇번째 코드로 추가할까요? :", 10);
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

void PrintNum(char Playersign, int N) { //블럭의 정 중앙에 숫자를 위치시키기 위해서 유니코드 문자표에서 가져온 숫자를 별도로 출력.
	int* string;

	string = memory;
	if (turn(Playersign, 0) && string[N] == 0) {
		printf(" ? ");
		return;
	}

	switch (N % 13) {
	case 0:
		printf(" ０");
		break;
	case 1:
		printf(" １");
		break;
	case 2:
		printf(" ２");
		break;
	case 3:
		printf(" ３");
		break;
	case 4:
		printf(" ４");
		break;
	case 5:
		printf(" ５");
		break;
	case 6:
		printf(" ６");
		break;
	case 7:
		printf(" ７");
		break;
	case 8:
		printf(" ８");
		break;
	case 9:
		printf(" ９");
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
	printf("■ 추측");
	gotoxy(58, 27);
	printf("□ 턴 넘기기");
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
				if (plc == 1) { //추측
					gotoxy(50, 27); printf("                        ");
					return 1;
				}
				else { //턴 넘기기
					gotoxy(50, 27); printf("                        ");
					return 0;
				}
				break;
			}
			gotoxy(99, 25);
			printf("      ");
			switch (plc) {
			case 1: gotoxy(58, 27); printf("□"); gotoxy(50, 27); printf("■"); break;
			case 2: gotoxy(50, 27); printf("□"); gotoxy(58, 27); printf("■"); break;
			}
			gotoxy(99, 25);
		}
	}
}

//버그는 절대 없습니다! 100회가 넘는 실행횟수가 입증합니다
// 
//		  ^ ^  _________  /
//		=(^.^=)_________)/
//		  /  /        |  |
// 
// 제작 : 1103 고성윤
// 코드 길이 : 829줄 (주석 포함)