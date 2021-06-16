#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int score = 0;//점수
int life = 3;//남아있는 목숨
int upx = 40, upy = 10;//조준점의 위치
int star[20][4] = { 0 };//각 별에 대한 배열, star[n][0]에는 별의 x좌표, star[n][1]에는 별의 y좌표, star[n][2]에는 별이 출력되는지 여부, star[n][3]에는 각 별이 출력되기 시작하고 나서 지난 시간
int dif = 5;    //난이도 조절용 변수, 이 변수만큼 콘솔에 별이 출력됨


void gotoxy(int x, int y);  //커서를 x,y로 이동시키는 함수
void frame();   //테두리를 출력하는 함수
void eraseCursor();     //조준점을 지우는 함수
void cursor();  //조준점을 출력하는 함수
void starset(int n); //n번째 별(star 배열의 n번째)을 다른 별과 중복되지 않는 랜덤한 위치에 지정하는 함수
void pstar();   //별을 지정된 위치에 출력하는 함수
void shot();    //s키가 눌렸을 때 조준점 위치에 별이 있는지 확인하고 점수를 올리는 함수
void check();   //별이 출력되고 10초이상 지났는지 확인해서 life를 깎는 함수
void text();    //score와 life를 출력하는 함수

int main() {
	srand(time(NULL));
	int key = 0;
	int t = 0;   //시간이 지날수록 난이도를 올리기 위해 시간을 저장하는 변수
	printf("***1학년 3반 1번 곽나영 C 프로젝트***\n\n");
	printf("~스페이스 슈터~\n");
	printf("당신은 우주선을 조종하는 조종사이다. 우주선을 향해 날아오는 운석들을 쏘아 없애자.\n운석이 가까이 다가오면 빨갛게 변하니 빠르게 쏘아 없애도록 하자. \n세 번 이상 운석에 부딪히게 되면 게임이 종료된다.\n\n");
	printf("조작방법 : 상하좌우 화살표 버튼으로 조준, s키로 발사\n아무 버튼이나 눌러서 시작");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);	//값에 따라서 출력되는 문자의 색과 배경색을 바꾸는 함수, 인터넷을 참조했습니다.
	printf("\n\n※이 게임은 검은색 배경의 콘솔에서 가장 적절하게 출력됩니다.※");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	getch();    //문자(char형) 하나를 입력받는 함수, 키보드로 문자를 입력하면 다음으로 넘어간다. 인터넷을 참조했습니다.
	system("cls");  //콘솔에 출력된 것을 모두 지우는 함수, 인터넷을 참조했습니다.
	frame();
	for (int i = 0; i < dif; i++)
		starset(i);     //게임이 시작되면 기본적으로 별 5개의 위치를 지정
	while (1) {
		while (kbhit() == 0) {      //kbhit() 키보드가 눌렸는지를 확인하는 함수, 키보드 자판을 눌렀을 때 1을 반환한다.
			pstar();
			cursor();
			Sleep(10);      //매개변수(밀리초)만큼 정지하는 함수, 즉 0.01초씩 멈춘다.(하지만 다른 코드들의 실행 속도등으로 인해 실제로는 이보다 오래걸린다.)
			for (int i = 0; i < 20; i++)
				if (star[i][2])
					star[i][3] ++;    //현재 출력되고있는 별들이 출력된 시간을 0.01초에 1씩 올린다.()
			t++;      //0.01초마다 0.01씩 시간을 잰다.
			check();        //별중에서 출력되고 나서 10초이상 지난 별이 있는지 확인하여 별을 없애고 life를 깎는다.
			text();         //현재의 점수, 남은 life, 현재 난이도를 출력
			if (t >= 2000) {
				t = 0;
				if (dif < 20)
					dif++;
			}       //20초마다 난이도를 1씩 올린다. 최고 난이도는 20으로 설정
			for (int i = 0; i < dif; i++)
				starset(i);         //난이도만큼의 별의 위치를 지정한다.
			if (life <= 0)
				break;
		}
		while (1) {
			if (life <= 0)
				break;
			key = getch();  //사용자로부터 입력받은 문자를 key변수에 저장
			switch (key) {  //key 값에 따라 상하좌우 이동, 혹은 조준점 위치의 별 확인 및 점수조절을 한다.
			case 72:   //위 화살표 입력
				if (upy > 4) {
					eraseCursor();
					upy--;
				}
				break;
			case 75:    //왼쪽 화살표 입력
				if (upx > 7) {
					eraseCursor();
					upx--;
				}
				break;
			case 77:    //오른쪽 화살표 입력
				if (upx < 74) {
					eraseCursor();
					upx++;
				}
				break;
			case 80:    //아래쪽 화살표 입력
				if (upy < 24) {
					eraseCursor();
					upy++;
				}
				break;
			case 83:    //s 입력
			case 115:   //S 입력
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
			break;      //목숨이 0이하인 경우 탈출
	}
	system("cls");
	gotoxy(0, 0);
	printf("\nGAME OVER!!\n\n");
	printf("최종 점수 : %d\n최종 도달 난이도:%d\n게임을 종료하려면 e키를 누르세요", score, dif);      //콘솔에 게임 결과를 출력한다.
	while (key != 'e' && key != 'E')
		key = getch();
	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//이 함수는 인터넷을 참고하여 만들었습니다. windows.h헤더파일의 함수를 사용해 x, y위치로 커서를 이동시키는 함수


void frame() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255);
	gotoxy(4, 2);
	for (int i = 0; i < 37; i++)//위쪽 테두리 출력
		printf("--");
	gotoxy(4, 26);
	for (int i = 0; i < 37; i++)//아래쪽 테두리 출력
		printf("--");
	for (int i = 3; i <= 25; i++) {
		gotoxy(4, i);//왼쪽 테두리 출력
		printf("--");
		gotoxy(76, i);//오른쪽 테두리 출력
		printf("--");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void text() {
	gotoxy(85, 2);
	printf("SCORE : %d", score);    //현재 점수를 출력
	gotoxy(85, 3);
	printf("LIFE : ");
	for (int i = 0; i < life; i++)  //현재 남은 목숨을 0모양으로 출력
		printf("O ");
	gotoxy(85, 4);
	printf("DIFFICULTY : %d", dif);     //현재의 난이도를 출력
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
		star[n][0] = rand() % 68 + 7;   //조준점이 이동가능한 x범위에 별의 x좌표를 지정
		star[n][1] = rand() % 21 + 4;   // 조준점이 이동가능한 y범위에 별의 y좌표를 지정
		star[n][2] = 1;
		for (int i = 0; i < 20; i++) {
			if (star[i][0] == star[n][0] && star[i][1] == star[n][1])
				starset(n);     //혹시 별의 위치가 기존의 별 위치와 겹치는 경우 별 위치 지정 함수를 재호출
		}
	}
}


void pstar() {
	for (int i = 0; i < 20; i++) {
		if (star[i][2]) {       //현재 해당 번호의 별이 출력되는지 확인
			gotoxy(star[i][0], star[i][1]);
			if (star[i][3] >= 800)        //해당 별이 출력되고 8초이상 지난경우 빨간색으로 출력
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
		if (star[i][0] == upx && star[i][1] == upy) {       //현재 조준점 위치와 일치하는 별이 있는지 확인
			gotoxy(upx, upy);
			printf(" ");
			score++;            //별을 지우고 점수를 올림
			star[i][0] = 0;
			star[i][1] = 0;
			star[i][2] = 0;
			star[i][3] = 0;        //해당 별과 관련해서 정해져있던 값들을 초기화
			starset(i);             //해당 별의 위치를 다시 랜덤하게 지정
		}
	}
}

void check() {
	for (int i = 0; i < 20; i++)
		if (star[i][2])         //현재 출력되는 중인 별을 확인
			if (star[i][3] >= 1000) {     //출력되고나서 10초이상 지난 별을 확인
				gotoxy(star[i][0], star[i][1]);
				printf(" ");            //별을 지움
				gotoxy(90 + 2 * life, 3);
				printf("  ");
				life = life - 1;        //남아있는 life를 한개 지움
				star[i][0] = 0;
				star[i][1] = 0;
				star[i][2] = 0;
				star[i][3] = 0;        //해당 별과 관련해서 정해져있던 값들을 초기화
				starset(i);            //해당 별의 위치를 다시 랜덤하게 지정
			}
}
