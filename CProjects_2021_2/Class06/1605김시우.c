#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//프로그램에 사용되는 함수를 지정
void gotoxy(int x, int y); // 좌표 지정 함수
int Userinterface_start(double* money); // 인터페이스의 출력을 담당하는(스타트 UI) 함수
void playground(void);//경마 경기를 실행하는 함수


int main(void) // 메인함수 : 계획대로라면 여러 게임으로 연결하는 함수들이 들어차있을 계획이었으나 시간문제로 경마만 만들게 되었다.
{
	int money = 10; // 초기 코인 설정
	int take = 0;

	while (1) // 계속해서 반복되도록 설정
	{
		Userinterface_start(&money); // 스타팅 인터페이스 출력

		playground(&money); // 경마 게임 시작

		system("cls"); // 게임 종료 후 화면 클리어

		printf("게임을 계속하시려면 1을, 그만두시려면 2를 입력하세요.\n선택 : "); // 게임의 지속 여부를 묻는 질문 : 끝이 안나는 것을 방지했다.
		scanf("%d", take);

		if (take == 1) // 1이면 계속, 아니면 그만
		{
			continue;
		}
		else
		{
			break;
		}
	}

	return 0;
}

void playground(int* money) // 경마를 플레이하는 함수 부분
{
	int horse_num, number, i, k; // 말들의 숫자, 등수 등의 판정에 사용될 변수들
	int max = 0, count = 0, rank[17] = { 0 }; // 등수 판정에 사용되는 변수들
	int horse[17] = { 0 }; // 말들의 최대 숫자에 맞추어 만든 일차원 배열
	int race;
	char horse_name[17][15]; // 최대 숫자에 맞추어 칸의 개수를 만들었으며 말의 이름을 저장
	int reroading = 0; // 자잘자잘한 변수들...
	int yeah = 0;
	int first = 13232;

	clock_t start; // 말이 도착했을 때 도착에 걸리는 시간을 표시하려고 만든 부분 (경기 중에도 경과시간이 표시)
	clock_t end;

	double unnamed;

	srand(time(NULL)); // 말들의 진행 정도가 랜덤이어야 하므로 만들어진 부분

	printf("");
	system("pause"); // 메인 함수에서 인터페이스를 호출 시킨 이후의 상황에서 바로 다음으로 넘어가지 않고, 사용자의 선택시에만 넘어가도록 pause를 사용하였다.

	system("cls"); // 화면(인터페이스 부분) 클리어

	printf("\n\n\n------------ 경마 ------------\n\n");// 경마 게임을 진행
	printf("  1등마의 번호를 맞추면 코인이 3배!\n\n"); // 우승시 혜택 안내

	printf("경주할 말의 숫자를 입력해주세요. (최대 17)"); // 경주할 말의 숫자 지정
	scanf("%d", &horse_num);

	printf("1등이 될 것으로 예측하는 말의 번호를 입력해주세요. : "); // 우승할 것으로 예상하는 말의 번호 지정
	scanf("%d", &yeah);

	printf("%d마리 말의 이름을 입력해주세요. (최대 한글 3자)", horse_num); // 말 각각의 이름을 부여
	printf("\n");

	for (i = 0; i < horse_num; i++) // 위의 안내에 따라 각각 말의 이름을 배열에 집어넣는 과정
	{
		printf("%d 번 말의 이름 : ", i + 1);
		scanf("%s", horse_name[i]);
	}

	system("cls"); // 안내 페이지를 출력해둔 위의 내용을 지우고 경기로 진입

	printf("\n\n");
	printf("START 1         10         20        30        40 도착   등수 / 시간(초)\n"); // 경기장을 출력
	printf("------------------------------------------------------------------------\n");
	gotoxy(55, 1);
	printf("소요시간 : ");

	for (i = 0; i < horse_num; i++) // 말의 수에 맞춰 말을 경기장 왼쪽 끝에 세로로 겹치지 않도록 출력 (대기 위치 출력)
	{
		gotoxy(1, 5 + i * 2);
		printf("%s:]", horse_name[i]);
	}

	printf("\n\n");
	printf("아무 키를 눌러 경주를 시작합니다."); // 경기 시작 안내
	printf("\n");
	getch();// 아무 입력이나 들어오면 시작

	start = clock(); // 아까 지정해둔 시간 함수 시작 포인트
	while (count != horse_num) // count 즉 결승점에 도착한 말들의 수가 경기를 하는 말들의 수와 같지 않을 때 반복
	{
		number = rand() % horse_num; // number 에서 말의 수에 넘지 않는 랜덤 값이 들어가도록 배열
		if (rank[number] != 0) // 아직 결승선에 도달하지 못한 말의 배열에서의 값은 0인데 들어간 말은 값이 달라지므로 만약 해당 번호의 말이 이미 도착했다면 다른 말을 다시 랜덤으로 선택한다.
			continue;

		race = rand() % 5 + 1; // 랜덤한 만큼 앞으로 이동할 수 있도록 랜덤 값을 race변수에 받아준다.

		horse[number] = horse[number] + race; // 배열을 이용해서 말의 위치를 판단하므로 현재 말의 번호에 해당하는 배열에 이동한 만큼의 값을 더해준다.

		Sleep(300);//0.3초간 정지

		if (horse[number] > 39) // 이제 도착한 말을 판정하는 부분(이미 도착한 말은 while문의 시작에서 continue코드로 가기에 이 코드를 실행하지 않는다.)
		{
			horse[number] = 40; // 위에서 race를 더한 값이 39를 넘는다면 40(종결점)에 도착한 것으로 배열에 값을 대입한다.
			if (!rank[number]) // 경기에서의 등수나 걸린 시간 등을 표현하는 부분
			{
				count++; // 종결점(결승점)에 들어온 말들의 수를 체크하는 변수이다.
				rank[number] = count; // 등수를 입력받는 배열

				if (count == 1) // 일등을 예측했는지 여부를 판단하기 위한 코드
				{
					first = horse[number];
				}

				gotoxy(10, 5 + number * 2); // 말을 정확한 위치에 출력
				for (k = 0; k < horse[number]; k++) // 출력 이후 이전 출력 내용을 지움
					printf(" ");

				if (horse[number]) // 종료된 말을 고정된 위치에 출력
					printf("]%d", horse[number]);
				gotoxy(55, 5 + number * 2); // 종료된 말을 표시하는 위치

				printf("   %d등   ", count); // 등수 출력

				end = clock(); // 현재 흐른 시간 값

				unnamed = (double)(end - start) / CLK_TCK; // CLK_TCK란 초단위 클럭(프로그램을 처리하는 것에 걸리는 시간) unnamed에 말의 경기에 걸리는 시간을 입력해 준 것이다.
				printf("%6.3f초", unnamed); // 걸린 시간 출력

			}
		}

		else //말의 위치가 39를 넘어 종료되지 않았을 때
		{
			gotoxy(10, 5 + number * 2); // 그대로 말의 좌표를 바꾸어준다.
			for (k = 0; k < horse[number]; k++) // 말의 현재 위치 전까지는 모두 비운다.
				printf(" ");
			if (horse[number]) // 말의 좌표에서 말을 출력
				printf(">%d", horse[number]);
		}

		gotoxy(62, 1); // 출력 화면의 우측 상단에 현재 흐른 시간 위치시킨다.
		end = clock(); // 이 두줄로 현재까지 흐른 시간을 판단한다.
		unnamed = (double)(end - start) / CLK_TCK;
		printf("%6.3f초", unnamed); // 현재까지 흐른 시간을 출력한다.

	}

	gotoxy(1, 20);
	printf("게임 종료\n");// 게임 종료 안내

	int coini; // 현재 코인 보유 현황 출력을 위한 변수

	if (yeah = first) // 1위를 예측 해내었을 때
	{
		printf("\n 예상 적중! \n 축하드립니다 코인 3배의 기적을 이뤄내셨군요! (coin * 3)\n\n"); // 축하메시지
		*money *= 3; // 현재 코인에 3배 한다.
		coini = *money;
	}

	printf("coin 현황 : %6d coin", coini); //코인 보유 현황 제시

	printf("\n 7초 뒤 시작화면으로 돌아갑니다."); // 경기 종료 및 안내 메시지 출력 이후 게임의 재시작 경고
	Sleep(7000); // 7초간 코드 정지

	return 0;

}

void gotoxy(int x, int y) // 좌표를 지정해줄 때 쓰이는 함수 (좌표 지정)
{
	COORD pos = { x,y };
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int Userinterface_start(int* money) // 스타트 인터페이스 출력 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 이 프로그램의 글자 색을 초록색으로 바꾸도록 글자색을 지정

	int coini; // 머니의 주소에 들어있는 값을 받을 변수 (쉽게 사용하도록 변수에 값을 받았다.)

	coini = *money; // 머니의 값을 받아옴

	printf("\n------------ THE GAME -------------\n\n"); // 인터페이스 출력부
	printf("\n     ■□■□■□■□■□■□   ");
	printf("\n     □■□■□■□■□■□■   ");
	printf("\n  --- PRESS ANY KEY TO START --");
	printf("\n     ■□■□■□■□■□■□   ");
	printf("\n     □■□■□■□■□■□■   ");
	printf("\n\n    - 보유코인 : %6d coin -", coini);
	printf("\n\n");
	printf("         < 게임 리스트 >\n");
	printf("            1. 경마\n");
	printf("           2. 미개발\n");
	printf("\n(경마 구현하는데 너무 많은 시간을 써버리고 말았습니다.)");

	printf("\n\n");

	return; //메인 함수로 되돌아감
}

