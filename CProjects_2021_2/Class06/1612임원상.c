#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <MMSystem.h>
#pragma comment(lib,"Winmm.lib")

struct tile {
	int time;//입력해야하는 시간
	int ER;//ErrorRange
	int num;//띄울 hit의 개수
};

struct tile tilestr[10000]; //tile의 정보를 저장할 배열

char musicRoute[100];// 음악의 경로를 저장할 문자열

void Gmap();// get map

int Gtypt();//get typing time

int main() {
	int a = 0;
	Gmap();
	if (Gtypt()) {
		printf("   88888888      88              888888888888      88888888      8888888888      88  \n");
		printf(" 88        88    88              88              88        88    88        88    88  \n");
		printf(" 88              88              88              88        88    88        88    88  \n");
		printf(" 88              88              888888888888    888888888888    8888888888      88  \n");
		printf(" 88              88              88              88        88    88        88    88  \n");
		printf(" 88        88    88              88              88        88    88        88        \n");
		printf("   88888888      888888888888    888888888888    88        88    88        88    88  \n");//성공 알리기

	}
	else {
		printf("     88        88   88888888888   88  88   \n");
		printf("    8888       88     88   88     88  88   \n");
		printf("   88  88      88     88   88     88  88   \n");
		printf("  88    88     88     88   88     88  88   \n");
		printf("  88    88     88     88   88     88  88   \n");
		printf("         88888888   88888888888   888888   \n");
		printf("               88                 88  88   \n");
		printf("         88888888                 88  88   \n");
		printf("         88                       88  88   \n");
		printf("         88888888                 88  88   \n");//실패 알리기
		printf("다시하겠습니까? 다시하려면 1, 끝내려면 1이외의 입력을 하세요");//게임 실행여부 조사
		scanf("%d", &a);
	}
	if (a == 1)
		main();//게임 재실행
	return 0;
}

void Gmap() {
	printf("노래의 경로를 입력하시오(단,역슬래쉬는 두번 써줘야함)\n");
	rewind(stdin);//버퍼에서 enter 지우기
	gets(musicRoute, stdin);//노래의 경로를 입력받기
	int a = 0;
	int cl, ER, num;
	Sleep(100);
	system("cls");//100ms동안 기다렸다가 콘솔창 초기화
	while (1) {
		printf("맵을 입력하시오\n");
		printf("cl ER num\n");
		scanf("%d %d %d", &cl, &ER, &num);// 맵의 정보 입력받기
		(*(tilestr + a)).time = cl;
		(*(tilestr + a)).ER = ER;
		(*(tilestr + a)).num = num;//구조체 배열을 간접창조하여 구조체 배열에 맵의 정보 입력
		a++;
		if (cl == 0 && ER == 0 && num == 0) {//맵 입력 종결 조건
			system("cls");
			break;
		}
		system("cls");//콘솔창 초기화
	}
}

int Gtypt() {
	int a = 0;//타일 정보를 가진 구조체 배열의 원소의 차례를 지정하는 변수
	int b = 0;//계속되는 시간 기록할 변수
	int c = 0;//시작시간 기록할 변수
	printf("    33333333    \n");
	printf("  33        33  \n");
	printf("            33  \n");
	printf("    33333333    \n");
	printf("            33  \n");
	printf("  33        33  \n");
	printf("    33333333    \n");//3입력
	Sleep(1000);//1초대기
	system("cls");//콘솔창 초기화
	printf("    22222222    \n");
	printf("  22        22  \n");
	printf("            22  \n");
	printf("        2222    \n");
	printf("    2222        \n");
	printf("  22            \n");
	printf("  222222222222  \n");//2입력
	Sleep(1000);//1초대기
	system("cls");//콘솔창 초기화
	printf("       11       \n");
	printf("      111       \n");
	printf("     1111       \n");
	printf("    11 11       \n");
	printf("       11       \n");
	printf("       11       \n");
	printf("       11       \n");
	printf("    11111111    \n");//1입력
	Sleep(1000);//1초대기
	system("cls");//콘솔창 초기화
	sndPlaySoundA(musicRoute, SND_ASYNC | SND_NODEFAULT);//노래 재생
	c = clock();//시작시간 입력
	while (1) {
		b = clock();//현재시간 입력
		if (b - c >= tilestr[a].time - tilestr[a].ER && b - c <= tilestr[a].time + tilestr[a].ER) {
			for (int i = 0; i < tilestr[a].num; i++)
				printf("hit");
			system("cls");
		}//입력해야하는 시간에 hit을 띄우기
		if (_kbhit()) {
			if (tilestr[a].time == 0 && tilestr[a].ER == 0) {
				return 1;// 성공하였을 시 성공 반환( 성공은 1, 실패는 0)
			}
			_getch();//_kbhit()값초기화
			if (b - c > tilestr[a].time + tilestr[a].ER) {
				PlaySound(NULL, 0, 0);
				return 0;// 실패하였을 시 노래 중단 및 실패 반환
			}
			else if (b - c >= tilestr[a].time - tilestr[a].ER)
				a++;// 진행중일시 a의 값을 올려 다음 입력을 받을 수 있도록 하기
		}
	}
}