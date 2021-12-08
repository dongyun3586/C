#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DELAY 30000

#define true 1

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}/*인터넷에서 퍼온 함수입니다. (x, y)로 출력 좌표를 이동시켜주는 함수입니다. */


int main__() {
	srand(time(NULL));//뉴트리아의 좌표를 무작위로 생성해주기 위해서 난수 생성
	time_t new_time = 0, old_time = 0; // 시간이 제한시간을 넘어가게 되면 멈춰주기 위해 변수 생성

	int money = 0;	// 받은 포상금
	int level = 0;	// 게임 레벨
	char flag;		// 게임 시작하기
	GotoXY(85, 20);
	printf("  뉴트리아 척살하기\n                                                                                  Press X to start the game:  ");
	scanf("%c", &flag);

	if (flag == 'X') {
		system("cls");
	}
	else {
		return 0;
	}

	char notflag;
	/*여기부터는 게임의 스토리를 위한 printf문 반복.*/
	char yourname[10];
	printf("당신의 이름은? 이름을 입력하세요.");
	scanf("%s", &yourname);
	system("cls");


	printf("애인 : %s! 이 기사 봤어? 요즘 우리나라에서 외래종이 많이 설친다는데...\n", yourname);
	Sleep(1000);
	printf("애인 : 우와, 심지어 뉴트리아는 잡으면 돈도 준대!\n");
	Sleep(1000);
	printf("애인 : 나 요즘 돈이 좀 부족하긴 한데... \n");
	Sleep(1000);
	printf("애인 : %s 네가 돈 좀 벌어다줄래? 내 애인이면 그 정도는 해야지.\n", yourname);
	Sleep(1000);
	system("cls");

	printf("큰일났다! 환경을 끔찍이도 생각하는 짠돌이 애인이 뉴트리아 척살을 요구했다!\n");
	Sleep(1000);
	printf("방법은 하나밖에 없다. 뉴트리아를 척살하자!\n척살을 진행할 난이도를 입력하세요. (1~4)");
	getchar();
	scanf("%c", &notflag);


	if (notflag == '1') { //난이도 1
		level = 1;
		system("cls");
	}
	else if (notflag == '2') {//난이도 2
		level = 2;
		system("cls");
	}
	else if (notflag == '3') {//난이도 3
		level = 3;
		system("cls");
	}
	else if (notflag == '4') {//난이도 4
		level = 4;
		system("cls");
	}
	else {
		return 0;
	}
	/*참고로 난이도는 각각 뉴트리아가 퍼진 영역의 넓이를 의미.
	4가 가장 넓은 범위이며 1이 가장 좁은 범위.*/


	/* 난수로 뉴트리아 위치 만들어서 그 위치에 닿으면 포상금 추가하기*/
	int x = 0, y = 0;
	old_time = clock();
	char Hey = 0;
	int* ddx[15], ddy[15];
	for (int i = 0; i < 15; i++) {
		*(ddx + i) = rand() % 40 * level;
		*(ddy + i) = rand() % 10 * level;

		GotoXY(ddx[i], ddy[i]);
		printf("d"); //뉴트리아 위치 표시

	}
	while (true) {
		new_time = clock();    // 현재 시간 
		GotoXY(0, 1);
		printf("%2d", 30 - (new_time - old_time) / 1000);
		if (difftime(new_time, old_time) > DELAY) {    // 시간 초과 검사; 시간이 30초를 넘으면 자동으로 게임 중단
			system("cls");
			printf("애인이 %d만원의 돈을 받고는 행복해합니다!", money);
			Sleep(3000); // 바로 종료하게 되면 연속으로 치던 타자로 인해 점수를 확인도 못 하고 콘솔창이 닫히는 불상사 발생
			return 0; // 게임 종료
		}


		GotoXY(x, y);			// 처음 x와 y의 값은 0이기 때문에 원점 시작
		printf("0");			// 우리가 뉴트리아를 잡을 커서를 출력
		if (kbhit()) {			// 키보드가 입력이 되면?
			GotoXY(x, y);		// 원래 있던 곳의 좌표에서 
			printf("  ");		// 공백이 출력된 후
			Hey = getch();		// 입력된 키보드의 값을 Hey라는 변수에 저장하고 아래의 switch case문에서 
			switch (Hey) {		// 키보드의 값에 따라 상황을 나눠줌
			case 'w':
				if (y == 0) {	// w가 입력이 되면 위로 한 칸을 이동, 하지만 원래 y좌표가 0이던 상태에선 
					break;		// 더 이상 위로 가지 못하기 때문에 오류가 생김
				}				// 그렇기 때문에 y가 0일 때와 0이 아닐 때로 나눠서 코드 짜주기
				else {
					y--;
					break;
				}
			case 'a':			// 왼쪽으로 한 칸을 이동하는 a도 마찬가지.
				if (x == 0) {
					break;
				}
				else {
					x--;
					break;
				}
			case 's':			// 좌표의 값을 감소시켜주는 게 아닌 s와 d는 아무 상관 없음.
				y++;
				break;
			case 'd':
				x++;
				break;
			case 'p':			// 언제든지 게임을 중단하고 싶다면 p를 누르기. 게임 점수와 함께 게임이 중단됨.
				system("cls");
				printf("애인이 %d만원의 돈을 받고는 행복해합니다!", money);
				Sleep(3000); // 마찬가지로 바로 꺼지는 오류 방지
				return 0;

			}
			for (int i = 0; i < 15; i++) {
				if (x == ddx[i] && y == ddy[i]) {	// 만약 현재 위치가 뉴트리아 위치와 동일할 시에는? ->
					GotoXY(ddx[i], ddy[i]);			// 뉴트리아가 표시되는 위치에 가서
					printf("  ");					// 공백을 출력해 뉴트리아를 지워주고
					ddx[i] = 200;					// 뉴트리아의 위치에 닿으면 점수가 올라가기 때문에 불상사를 막아주기 위해
					ddy[i] = 200;					// 커서가 절대 갈 일이 없는 곳으로 좌표를 이동시켜줌
					money += 3;						// 그리고 포상금 30000원!
					GotoXY(0, 0);					// 돈을 받았음을 표시해줌
					printf("%d", money);
				}
			}
			Sleep(1);			// sleep 없이 해두면 움직이는 감도는 좋지만 뭔가 불안해 있으나마나 한 시간 간격을 둠
		}


	}


	return 0;
}
