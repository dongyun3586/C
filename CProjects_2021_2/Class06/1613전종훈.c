#include<stdio.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include <conio.h> 
#define level 3;//이 값을 변환시켜서 컴퓨터의 확률을 바꿔서 난이도를 조절할수 있습니다.
#define point 5;//이 값으로 초기 포인트를 얼마나 줄지를 고를수 있습니다.
void person1(int x, int y, char* name);//007빵에서 으악하는 모션을 구현하는 함수입니다.
void eakm(int p, int c1, int c2, int c3);//누가 으악을 하는지 중간에 분류하는 함수입니다.
int timeget(char* c, float time) {
	clock_t start = clock();
	while (1)
	{
		if (kbhit())
		{
			scanf("%s", c);
			return 0;
		}
		if ((clock() - start) / CLOCKS_PER_SEC > time)
			return -1;
	}
}//인터넷에서 가져와서 약간 수정한 함수로 일정한 시간안에 입력을 받는 함수입니다. 시간안에 정상적으로 입력받으면 0이 반환되고 아니면 -1이 반환됩니다.//위의 으악 모션을 누가 할지 입력받아서 으악을 해야하는 사람을 분류하는 함수입니다.
void eak(int tem, int* p, int* c1, int* c2, int* c3);//빵이 누구한테 갔는지를 입력받아서 확률에 따라 컴퓨터가 으악을 하는지 아니면 안하는지를 결정하고 플레이어가 으악을 하는지 안하는지 시간안에 입력받습니다.
void arrow(int num);//현재 007빵에서 누구한테 화살표가 가있는지를 화면에서 보여주는 함수입니다.
void display1();//초기에 점수판을 만들고 등의 기본적인 화면을 구성하는 함수입니다.
void person(int x, int y, char* name);//사람모양의 말을 그려주는 함수입니다.
void gotoxy(int x, int y) {
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//인터넷에서 가져온걸로 지정한 xy좌표로 커서를 이동시켜줍니다.

void color(int a, int b) {
	int i = a + b * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i); //a는 글자의 색깔이고 b는 배경색으로 인터넷에 있는 색깔 표를 보고 입력한뒤 실행하면 이 함수 뒤의 글자들의 색이 변합니다.
}//인터넷에서 가져와서 약간 변환시킨걸로 배경색과 글자색을 바꿔줍니다.
void poi(int x, int y) {
	gotoxy(57, 25);
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 50; i++) {
			printf("  ");
		}
		gotoxy(57, 25 + j);
	}//말위에 이미 존재하는 폭탄 아이콘을 지우고
	gotoxy(x - 1, y - 2);
	color(4, 0);
	printf("   ■   ");
	gotoxy(x - 1, y - 1);
	printf("   ■   ");
	gotoxy(x - 1, y);
	printf("◁□□▷");
	gotoxy(x - 1, y + 1);
	printf("◁□□▷");
	gotoxy(x - 1, y + 2);
	printf("  ▽▽  ");//좌표에 폭탄 아이콘을 그려줍니다.
	color(15, 0);
}//arrow함수로 화면에 007빵 총알이 있는 위치를 표시해야하는데 표시하는 아이콘을 그려주는 함수입니다.
void damage(int x, int y, char* c) {
	color(12, 0);//빨간색으로 바꿔서
	person(x, y, c);//사람을 다시 그리고
	Sleep(500);//있다가
	color(15, 0);//원래색으로
	person(x, y, c);//사람을 다시 그립니다.
}//게임에서 져서 포인트가 깎이면 사람역할을 하는 말이 빨갛게 깜빡이게 하는 역할입니다.
void start1(int* r);//게임을 정하는 사람을 정하는 랜덤뽑기 함수입니다.
void choice(int* r);//사람이 게임을 정하는 경우 어떤게임을 할지 물어보는 역할입니다.
void start2(int* r);//컴퓨터가 게임을 선택할경우 뭘 선택했는지 랜덤뽑기하는 함수입니다.
int game();//위의 3함수를 조합하여서 만든 함수로 게임을 시작할때 게임을 정하는 과정인 함수입니다.
void number(int a, int b, int c);//원하는 숫자를 원하는 좌표에 그려주는 함수입니다.
void zzsnum(int num) {
	if (num == 4) {//이번 총알이 첫번째 0임을 나타냅니다.
		number(0, 50, 15);
	}
	if (num == 3) {//이번총알이 두번째 0임을 나타냅니다.
		number(0, 55, 15);
	}
	if (num == 2) {//이번총알이 7
		number(7, 60, 15);
	}
	if (num == 1) {//이번에 빵이라는 것을 나타내줍니다.

		gotoxy(66 - 1, 17 - 2);
		color(4, 0);
		printf("   ■   ");
		gotoxy(66 - 1, 17 - 1);
		printf("   ■   ");
		gotoxy(66 - 1, 17);
		printf("◁□□▷");
		gotoxy(66 - 1, 17 + 1);
		printf("◁□□▷");
		gotoxy(66 - 1, 17 + 2);
		printf("  ▽▽  ");
		color(15, 0);
	}
}//007빵에서 이번에 가르켜서 전달된 총알이 몇번째 총알인지 알려주는 것을 표현하였습니다.


void game1(int* p, int* s1, int* s2, int* s3);//눈치게임을 실행하는 함수입니다.
void game2(int* p, int* s1, int* s2, int* s3);//007빵을 실행하는 함수입니다.
void comsel(int* c1, int* c2, int* c3, int s1, int s2, int s3);//눈치게임에서 각각의 컴퓨터가 숫자를 부른건지 안 부른건지 고르는 랜덤함수입니다.
void zzs(int* x);//007빵에서 총알을 누구에게 전달할지 고르는 함수입니다.
void clear();//왼쪽의 글자가 나오는 부분을 모두 지워주는 함수입니다.
typedef struct tim {
	int sec;
	int min;
	int hour;
}tm;//게임과정을 기록해서 텍스트파일로 내보낼건데 이때 시간을 기록하기위해 구조체를 하나 만들었습니다.
void main() {
	FILE* fp = fopen("score.txt", "w");//score.txt를 쓰기모드로 엽니다.
	time_t ti = time(NULL);//ti에 현재시간을 저장하고 
	tm* tim = localtime(&ti);//tim에 저장합니다.
	display1();//초기화면을 띄우고
	int scorep = point;
	int score1 = point;
	int score2 = point;
	int score3 = point;//초기 점수를 줍니다.
	fprintf(fp, "%2d h:%2d m:%2d s     %d %d %d %d\n", tim->hour, tim->min, tim->sec, scorep, score1, score2, score3);//메모장에 현재 점수 기록
	printf("    게임시작\n"); int s;
	do {
		clear();//글자창을 지워주고
		Sleep(1000);
		gotoxy(0, 0);
		s = game();//게임을 정해줍니다.
		switch (s) {
		case 1:game1(&scorep, &score1, &score2, &score3);//1이면 눈치게임
			break;
		case 2: game2(&scorep, &score1, &score2, &score3);//2이면 007빵을 실행합니다.
			poi(66, 17);//poi속의 말위의 아이콘 지우는 코드를 써주고
			for (int i = 50; i < 69; i++) {
				for (int j = 15; j < 21; j++) {
					gotoxy(i, j);
					printf("  ");
				}
			}//007빵의 표시용 글자들을 지워줍니다.
			break;
		}
		ti = time(NULL);
		tim = localtime(&ti);//현재시간을 저장하고
		fprintf(fp, "%2d h:%2d m:%2d s     %d %d %d %d\n", tim->hour, tim->min, tim->sec, scorep, score1, score2, score3);//또 메모장에 점수를 기록한다.

		number(scorep, 93, 2);
		number(score1, 93 + 6, 2);
		number(score2, 93 + 2 * 6, 2);
		number(score3, 93 + 3 * 6, 2);//점수판을 고칩니다.
	} while (scorep != 0 && score1 != 0 && score2 != 0 && score3 != 0);//뭐라도 0이 되면 끝납니다.
	fprintf(fp, "종료\n\n");//메모장에 끝남을 기록합니다.
}


void game1(int* p, int* s1, int* s2, int* s3) {
	int r = 1, number = 1;
	int numbers[4] = { 0 };
	int i, c1, c2, c3;
	int now = 0;
	int now1 = 0, now2 = 0, now3 = 0;
	gotoxy(1, 1);
	while (1) {
		printf("\n%d번째\n", r);//몇번쨰 턴인지 표시
		i = 0;
		while (now == 0) {//내가 아직 번호를 못부른 경우에만 계속 플레이어의 입력을 받는다.
			scanf("%d", &i);
			if (i == 0 || i == 1)
				break;//0또는 1을 플레이어에게 입력받는다.
		}
		comsel(&c1, &c2, &c3, now1, now2, now3);//컴퓨터의 선택을 입력받고
		printf("%d %d %d %d \n\n", i, c1, c2, c3);//출력한다.
		if (i + c1 + c2 + c3 > 1) {//누구라도 동시에 1을 선택하여서 합이 1을 넘으면
			number = -1;//중복 선택으로 끝남을 표시한다.
			break;//끝낸다.
		}
		else {//한명만 선택한 경우
			if (i == 1) {//내가 1이면 0번 자리에 숫자를 넣어준다. 그리고 number를 올려준다.
				numbers[0] = number;
				now = 1;//앞으로 플레이어의 입력을 안받게한다.
				number++;//한명이 통과함을 보여준다.
			}
			if (c1 == 1) {//컴퓨터1이 통과한경우
				numbers[1] = number;
				number++;
				now1 = 1;//컴퓨터 1이 통과하여서 앞으로 숫자를 부를 필요가 없음을 보인다.
			}
			if (c2 == 1) {//컴퓨터2 통과
				numbers[2] = number;
				number++;
				now2 = 1;
			}
			if (c3 == 1) {//컴퓨터 3 통과
				numbers[3] = number;
				number++;
				now3 = 1;
			}
		}
		r++;//턴의 수를 올려서 다으턴으로 간다.
		if (number == 4 || number == -1)break;//모두 숫자를 불렀거나 중복선택이 일어난 경우 턴을 종료시키고 점수계산으로 간다.
		Sleep(500);
	}
	if (number == -1) {//중복선택인경우
		if (i == 1) {//내가 숫자를 불렀을때 중복선택이면
			(*p)--;//점수 깎고
			damage(56, 33, "PLAYER");//깜빡인다.
		}
		if (c1 == 1) {
			(*s1)--;
			damage(71, 33, "COM1");
		}
		if (c2 == 1) {
			(*s2)--;
			damage(86, 33, "COM2");
		}
		if (c3 == 1) {
			(*s3)--;
			damage(101, 33, "COM3");
		}//나머지도 동일
	}
	if (number == 4) {//3명이 숫자를 부른경우
		if (numbers[0] == 0) {
			(*p)--;
			damage(56, 33, "PLAYER");

		}
		if (numbers[1] == 0) {
			(*s1)--;
			damage(71, 33, "COM1");

		}
		if (numbers[2] == 0) {
			(*s2)--;
			damage(86, 33, "COM2");

		}
		if (numbers[3] == 0) {
			(*s3)--;
			damage(101, 33, "COM3");
			//숫자를 안불러서 자신의 자리의 숫자가 아직 0이면 점수를 깎는다.
		}
	}
}
void comsel(int* c1, int* c2, int* c3, int s1, int s2, int s3) {
	int d1, d2, d3;
	srand(time(NULL));
	d1 = rand() % level + 1;
	d2 = rand() % level + 1;
	d3 = rand() % level + 1;//랜덤으로 숫자를 저장한다.
	if (d1 == 1)*c1 = 1;//d1이 1이면 c1에 1을 저장한다.
	else *c1 = 0;//아니면 0을 저장한다.
	if (d2 == 1)*c2 = 1;
	else *c2 = 0;
	if (d3 == 1)*c3 = 1;
	else *c3 = 0;
	if (s1 == 1)*c1 = 0;//하지만 s1이 1 즉 컴퓨터1이 숫자를 이미 불러서 부를 필요가 없으면 다시 0으로 바꿔준다.
	if (s2 == 1)*c2 = 0;
	if (s3 == 1)*c3 = 0;
}
void game2(int* p, int* s1, int* s2, int* s3) {
	int num;
	int eak0 = 0, eak1 = 0, eak2 = 0, eak3 = 0;
	int what = 1;
	int end = 0;
	int tem;
	while (1) {
		num = 4;
		clear();
		for (int i = 50; i < 69; i++) {
			for (int j = 15; j < 21; j++) {
				gotoxy(i, j);
				printf("  ");
			}
		}//기존에 출력된것을 지워주고
		gotoxy(1, 1);
		while (1) {
			zzs(&tem);//누구한테 총알을 전달했는지 고르고
			arrow(tem);//표시하고
			gotoxy(1, 1);
			zzsnum(num);//몇번째 총알인지 표시하고
			num--;//다음총알로 넘어간다.
			if (num == 0)break;//마지막이면 라운드를 종료한다.
			Sleep(700);
		}
		eak(tem, &eak0, &eak1, &eak2, &eak3);//으악을 했는지 안했는지 입력받고
		eakm(eak0, eak1, eak2, eak3);//표시해주고
		end = 0;
		switch (tem) {
		case 0:
			if (eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (!eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (!eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		case 1:
			if (!eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (!eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		case 2:
			if (eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (!eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (!eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		case 3:
			if (!eak0) {
				end = 1;
				(*p)--;
				damage(56, 33, "PLAYER");
			}
			if (eak1) {
				end = 1;
				(*s1)--;
				damage(71, 33, "COM1");
			}
			if (!eak2) {
				end = 1;
				(*s2)--;
				damage(86, 33, "COM2");
			}
			if (eak3) {
				end = 1;
				(*s3)--;
				damage(101, 33, "COM3");
			}
			break;
		}//으악을 해야하는 사람이 하고 안해야하는 사람이 안했는지 판단하고 잘못되었으면 점수를 깎는다. 잘못됙 경우가 있으면 end가 1이 된다. 모두 올바를 경우 end가 그대로 0이어서 다시 실행하게 된다.
		if (end)return;//잘못된 경우가 있으면 종료한다.
	}
}
void eak(int tem, int* p, int* c1, int* c2, int* c3) {
	int num1, num2;
	char ans[20] = "kkk";
	char eak[20] = "eak";
	if (tem == 0)//만약 마지막 총알이 플레이어에게 있으면
		num1 = 1; num2 = 3;//컴퓨터1과 컴퓨터3이 으악을 해야한다.
	if (tem == 1)
		num1 = 0; num2 = 2;
	if (tem == 2)
		num1 = 1; num2 = 3;
	if (tem == 3)
		num1 = 0; num2 = 2;//나머지도 동일
	gotoxy(1, 6);
	timeget(ans, 0.25);//내가 으악을 하는지 안하는지 시간안에 입력받고
	gotoxy(1, 6);
	printf("                ");
	if (strcmp(ans, eak) == 0)//내가 친 글자가 eak인지 아닌지 확인한다.
		*p = 1;
	else
		*p = 0;
	if (num1 == 1) {
		srand(time(NULL));
		*c1 = rand() % 10;//확률적으로 컴퓨터가 으악을 한다.
	}
	else {
		srand(time(NULL));
		*c1 = rand() % 10;
		if (*c1 == 0)
			*c1 = 1;
		else
			*c1 = 0;
	}

	if (num2 == 2) {
		srand(time(NULL));
		*c2 = rand() % 10;
		*c3 = rand() % 10;
		if (*c3 == 0)
			*c3 = 1;
		else
			*c3 = 0;
	}
	if (num2 == 3) {
		srand(time(NULL));
		*c2 = rand() % 10;
		*c3 = rand() % 10;
		if (*c2 == 0)
			*c2 = 1;
		else
			*c2 = 0;
	}//모두 상황마다 확률적으로 으악을 한다.
}
void arrow(int num) {
	switch (num) {
	case 0: poi(59, 28);
		break;
	case 1:
		poi(74, 28);
		break;
	case 2:
		poi(89, 28);
		break;
	case 3:
		poi(104, 28);
		break;
	}//총알이 있는 사람 위에 폭탄 아이콘을 띄운다.
	person(56, 33, "PLAYER");
	person(71, 33, "COM1");
	person(86, 33, "COM2");
	person(101, 33, "COM3");
}
void eakm(int p, int c1, int c2, int c3) {
	if (p)
		person1(56, 33, "PLAYER");
	if (c1)
		person1(71, 33, "COM1");
	if (c2)
		person1(86, 33, "COM2");
	if (c3)
		person1(101, 33, "COM3");//으악한 사람은 말에 손이 생겼다가 사라진다.
}
void zzs(int* x) {
	if (*x == 0) {
		gotoxy(1, 5);
		scanf("%d", x);
		gotoxy(1, 5);
		printf("                     ");
		gotoxy(1, 4);
		printf("%d에게 넘겼습니다.", *x);//내가 골라서 총알을 넘긴다.
	}
	else {
		gotoxy(1, 4);
		srand(time(NULL));
		*x = rand() % 4;
		printf("%d에게 넘겼습니다.", *x);
	}//컴퓨터가 랜덤으로 총알을 넘긴다.
}
int game() {

	srand(time(NULL));
	int r;
	start1(&r);//처음 누가 게임을 고를 지 고르고
	if (r > 0) {
		start2(&r);//컴퓨터가 걸리면 랜덤으로 고른다.
		Sleep(500);
	}
	else choice(&r);//내가 골라야 하면 입력받는다.

	for (int i = 0; i < 65; i++) {
		gotoxy(0, i);
		for (int j = 0; j < 39; j++)
			printf("  ");//글자창을 지워준다.
	}
	return r;
}
void start1(int* r) {
	int i = rand() % 100 + 1;
	if (i <= 25) {
		printf("    내가 걸림\n");
		*r = 0;
	}//25%확률로 내가 걸리고
	else {
		srand(time(NULL));
		int x = rand() % 3 + 1;
		printf("    COM%d가 걸림\n", x);
		*r = x;//나머지 확률로 컴퓨터가 걸린다.
		Sleep(300);
	}
}
void start2(int* r) {
	*r = rand() % 2 + 1;
	switch (*r) {
	case 1: printf("    눈치게임\n");//컴퓨터가 걸릴 겨우 50%확률로 눈치게임 또는 007빵을 고른다.
		break;
	case 2: printf("    007\n");
		break;
	}
	Sleep(1000);
}
void choice(int* r) {
	scanf("%d", r);
	switch (*r) {
	case 1: printf("    눈치게임\n");
		break;
	case 2: printf("    007\n");
		break;//플레이어가 걸리면 게임을 선택한다.
	}
	Sleep(1000);
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
void display1() {
	gotoxy(116, 0);//25,0~9
	for (int i = 0; i < 25; i++) {
		gotoxy(91 + i, 0);
		printf("■");
		gotoxy(91 + i, 8);
		printf("■");
		gotoxy(91 + i, 10);
		printf("■");//점수판 출력
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 5; j++) {
			gotoxy(91 + j * 6, i);
			printf("■");
		}//점수판 세로줄 출력
	}
	int p = point;;
	for (int i = 0; i < 4; i++) {
		number(p, 93 + i * 6, 2);
	}//점수를 출력한다.
	gotoxy(93, 9);
	printf("PLAYER");
	gotoxy(99, 9);
	printf("COM1");
	gotoxy(105, 9);
	printf("COM2");
	gotoxy(111, 9);
	printf("COM3");//점수판의 이름을 출력한다.

	person(56, 33, "PLAYER");
	person(71, 33, "COM1");
	person(86, 33, "COM2");
	person(101, 33, "COM3");//말을 출력한다.
	for (int i = 0; i < 65; i++) {
		gotoxy(40, i);
		printf("■");
	}//글자가 나오는 칸을 나누는 선을 그린다.
	gotoxy(0, 0);
}
void person(int x, int y, char* name) {
	gotoxy(x, y);
	printf("■");
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 8; i++) {
			gotoxy(x + i, y + j);
			printf("■");
		}
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3 - j; i++) {
			gotoxy(x + i, y + 7 + j);
			printf("  ");
			gotoxy(x + 7 - i, y + 7 + j);
			printf("  ");
		}
	}
	for (int i = 0; i < 4; i++) {
		gotoxy(x - 1, y + 12 + i);
		printf("■");
		gotoxy(x + 8, y + 12 + i);
		printf("■");
	}
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 1 + i, y + 13);
		printf("  ");
	}
	gotoxy(x + 2, y + 13);
	printf("%s", name);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			gotoxy(x + 1 + i, y + 2 + j);
			printf("  ");
		}
	}
	gotoxy(x + 2, y + 2);
	printf("■");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			gotoxy(x + 5 + i, y + 2 + j);
			printf("  ");
		}
	}
	gotoxy(x + 5, y + 2);
	printf("■");
	gotoxy(100, 30);
}//사람을 표현하는 말을 그려줍니다.
void clear() {
	for (int i = 0; i < 65; i++) {
		for (int j = 0; j < 40; j++) {
			gotoxy(j, i);
			printf("  ");
		}
	}
	gotoxy(0, 0);
}//글자가 나오는 칸을 지워준다.
void person1(int x, int y, char* name) {
	person(x, y, name);
	for (int i = 0; i < 6; i++) {
		gotoxy(x - 2, y + 3 + i);
		printf("■");
	}
	gotoxy(x - 1, y + 9);
	printf("■");
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 9, y + 3 + i);
		printf("■");
	}
	gotoxy(x + 8, y + 9);
	printf("■");
	Sleep(300);
	for (int i = 0; i < 6; i++) {
		gotoxy(x - 2, y + 3 + i);
		printf("  ");
	}
	gotoxy(x - 1, y + 9);
	printf("  ");
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 9, y + 3 + i);
		printf("  ");
	}
	gotoxy(x + 8, y + 9);
	printf("  ");//팔을 말에 그렸다가 원래로 돌아온다.

}