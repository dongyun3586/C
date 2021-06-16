#include<stdio.h>
#include<stdlib.h>
#include<time.h>//srand(time(NULL))
#include<windows.h>//Sleep 함수 사용 (시간 지연)
#include<process.h>//쓰레드 사용을 가능하게 하는 헤더파일
// scanf때문에 뜨는 경고가 신경쓰여서 다 scanf_s로 바꿔주었다.

/*쓰레드란?
쉽게말해, 2개의 함수를 동시에 실행시키는 것*/

int graphfirst(int r);//첫번째 그래프 출력
int graph(int r, int fr);//두번째 부터의 그래프 출력
void textcolor(int color_number);//막대 색

int M1 = 1, M2 = 2;

void* Thread_ms(void* fr) {		//매수를 담당하는 쓰레드
	int ms;
	scanf_s("%d", &ms);
	if (ms == 1)
		M1 = (int)fr;
}
void* Thread_md(void* fr) {		//매도를 담당하는 쓰레드
	int md;
	scanf_s("%d", &md);
	if (md == 2)
		M2 = (int)fr;
}
void* Thread_mo(void* r) {		//돈 계산을 담당하는 쓰레드
	int mo, money = 1000, nmoney = 0;
	float rate = 0;
	scanf_s("%d", &mo);
	if (mo == 3) {
		nmoney = ((M2 - M1) * money / M1) + money;
		rate = (float)(nmoney * 100 / money);
		money = nmoney;
		printf("현재 잔고: %d, 상승률(%): %.1f %\n", money, rate);
	}
}

int main() {//main에서는 그래프 함수가 돌아가고, 쓰레드에서는 매수, 매도가 돌아간다..

	srand(time(NULL));//랜덤선언

	int r1, r, fr;//r1: 첫번째의 길이값, r: 두번째부터의 길이값, fr: 막대기 시작 전부터의 공백값
	r1 = rand() % 5 + 1;
	printf("******랜덤 주식게임******\n랜덤으로 그래프를 출력하고, 그에따른 가격을 정한다.");
	printf("세로로 그래프가 출력된다.\n1을 누르면 매수, 2를 누르면 매도, 3을 누르면 현황보기. 매도를 한뒤에 1을 한번 더 누르고 그 다음부터 매수를 시작하십시오.\n\n");
	printf("보유금액: %d\n", 1000);

	fr = graphfirst(r1);
	Sleep(1500);
	while (1) {
		r = r1 * (rand() % 5 + 1);
		fr = graph(r, fr);//fr을 그 전의 공백+-길이로 해주어야 다음 그래프가 전 그래프의 끝부터 시작한다.
		_beginthread(Thread_mo, 0, (void*)r);//돈계산
		_beginthread(Thread_md, 0, (void*)fr);//매도
		_beginthread(Thread_ms, 0, (void*)fr);//매수
		Sleep(1500);
	}
	return 0;
}

int graphfirst(int r) {		//첫번째 줄 그래프 출력
	r = r * (rand() % 5 + 1);
	if (r % 2 == 1) {
		textcolor(9);
		for (int i = 1; i <= 15; i++)//그래프가 너무 윈쪽에 치우친것 같아 15칸씩 오른칸으로 움직여줬음
			printf(" ");
		for (int i = 1; i <= 36; i++)
			printf(" ");
		for (int j = 1; j <= r; j++)
			printf("*");
		printf("\n");
		return (36 + r);
	}
	else {
		textcolor(12);
		for (int i = 1; i <= 15; i++)
			printf(" ");
		for (int i = 1; i <= (36 - r); i++)
			printf(" ");
		for (int j = 1; j <= r; j++)
			printf("*");
		printf("\n");
		return (36 - r);
	}
}

int graph(int r, int fr) {		//두번째 이상 줄의 그래프 출력
	if (r % 2 == 1 || fr - r < 0) { //r이 홀수일때는 시가 상승
		textcolor(9);
		for (int i = 1; i <= 15; i++)
			printf(" ");
		for (int i = 1; i <= fr; i++)
			printf(" ");
		for (int j = 1; j <= r; j++)
			printf("*");
		printf("\n");
		return (fr + r);
	}
	else
		textcolor(12); //짝수일때는 시가 하락.
	for (int i = 1; i <= 15; i++)
		printf(" ");
	for (int i = 1; i <= (fr - r); i++)
		printf(" ");
	for (int j = 1; j <= r; j++)
		printf("*");
	printf("\n");
	return (fr - r);
}

void textcolor(int color_number) {		//그래프 색
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}