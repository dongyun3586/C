#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MARBLE 20

void explain();//게임 설명
void game();//게임 진행
void printmarble(int marble, char* owner);//구슬 현황 출력
int betting(int mar1, int mar2);//구슬 베팅
void check(int choose, int x, int bet, int* mar1, int* mar2, char* player);
int randommarble(int mar1, int mar2);
void end(int* mymar, int* commar);

int main()
{
	explain();
	game();
	return 0;
}

void explain()
{
	printf("○△□\n");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(400);
	printf("오징어 게임");
	Sleep(400);
	system("cls");
	printf("<진행요원>\n");
	Sleep(1000);
	printf("이제 주머니를 하나씩 받아 주시기 바랍니다.\n");
	Sleep(1000);
	printf("각자의 주머니에 열개의 구슬이 들어 있습니다.\n");
	Sleep(1000);
	printf("개수를 확인해 주세요.\n");
	Sleep(3000);
	system("cls");
	printf("그려면은 우리 깐부부터 맺어야지\n");
	Sleep(1500);
	printf("구슬이랑 딱지랑 같이 쓰는 친구 말이야\n");
	Sleep(1500);
	printf("네 거, 내 거 없이\n");
	Sleep(3000);
	system("cls");
	printf("<진행요원>\n");
	Sleep(1000);
	printf("이번 게임은 각자 자신의 구슬을 가지고\n");
	Sleep(1000);
	printf("지금 여러분의 옆에 있는 짝과 시합을 별여....\n");
	Sleep(3000);
	printf("일남, 지훈 : ????\n");
	Sleep(3000);
	printf("상대의 구슬 열 개를 모두 따내는 사람이 승리합니다.\n");
	Sleep(3000);
	printf("일남, 지훈 : 그럼....\n");
	Sleep(1000);
	printf("일남, 지훈 : 우리 중 한명은 죽는 거야.....?\n");
	Sleep(3000);
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	system("cls");
}

void game()
{
	srand(time(NULL));
	int mymar = MARBLE / 2;//내 구슬
	int commar = MARBLE / 2;//컴퓨터 구슬
	int choose = 0;
	while (1)
	{
		//내차례
		printf("<내 차례>\n\n");
		printmarble(mymar, "내");
		printmarble(commar, "상대방");
		int bet = betting(mymar, commar);//내가 베팅한 구슬
		int x = rand() % (commar + 1);//홀짝 할 구슬 개수 0~보유 구슬
		Sleep(1000);
		printf("\n상대방 손에 있는 구슬이 홀수일지 짝수일지 맞추세요\n");
		Sleep(1000);
		printf("홀수면 1, 짝수면 0을 입력하세요\n");
		scanf("%d", &choose);
		while (choose != 1 && choose != 0)
		{
			printf("다시 입력하세요\n");
			scanf("%d", &choose);
		}
		Sleep(2000);
		printmarble(x, "상대방 손에 있는");
		check(choose, x, bet, &mymar, &commar, "");
		Sleep(3000);
		system("cls");
		if (mymar == 0 || commar <= 1)//종료조건
			break;
		//상대 차례
		printf("<상대 차례>\n\n");
		printmarble(mymar, "내");
		printmarble(commar, "상대방");
		printf("손에 쥐실 구슬의 개수를 입력하세요\n");
		scanf("%d", &x);
		printmarble(x, "내 손에 있는");
		Sleep(2000);
		bet = randommarble(mymar, commar);//상대방 베팅
		choose = rand() % 2;
		if (choose % 2 == 1)
			printf("상대방은 홀을 선택하셨습니다.\n\n");
		else
			printf("상대방은 짝을 선택하셨습니다.\n\n");
		Sleep(1000);
		check(choose, x, bet, &commar, &mymar, "상대방이 ");
		Sleep(1000);
		printf("상대방은 %d개를 베팅하셨습니다.\n", bet);
		Sleep(3000);
		system("cls");
		if (mymar == 0 || commar <= 1)//종료조건
			break;
	}
	end(&mymar, &commar);
}

void printmarble(int marble, char* owner)
{
	printf("%s 구슬\n", owner);
	for (int i = 1; i <= marble; i++)
		printf("● ");
	if (marble == 0)
		printf("X");
	printf("\n\n");
}

int betting(int mar1, int mar2)
{
	int bet = 0;
	printf("베팅할 구슬의 개수를 입력하세요\n");
	scanf("%d", &bet);
	while (bet > mar1 || bet > mar2)
	{
		printf("베팅한 구슬이 너무 많습니다. 다시 입력하세요.\n");
		scanf("%d", &bet);
	}
	return bet;
}

void check(int choose, int x, int bet, int* mar1, int* mar2, char* player)
{
	Sleep(1000);
	if (x % 2 == 1)
		printf("결과는 홀 입니다.\n");
	else
		printf("결과는 짝 입니다.\n");
	Sleep(1000);
	if (choose == x % 2)
	{
		printf("%s맞추셨습니다.\n", player);
		(*mar1) += bet;
		(*mar2) -= bet;
	}
	else
	{
		printf("%s틀리셨습니다.\n", player);
		(*mar1) -= bet;
		(*mar2) += bet;
	}
}

int randommarble(int mar1, int mar2)
{
	srand(time(NULL));
	int min;
	if (mar1 < mar2)
		min = mar1;
	else
		min = mar2;
	return rand() % (min + 1);
}

void end(int* mymar, int* commar)
{
	system("cls");
	int temp;
	if (*mymar == 0)
	{
		printf("우리는 깐부잖아.....");
		Sleep(1500);
		printf("덕분에 즐거웠어\n");
		Sleep(1500);
		printf("자네가 다음 게임 올라가게...\n");
		Sleep(1500);
		printf("이 구슬....");
		Sleep(1500);
		printf("자네가 가져\n\n");
		Sleep(3000);
		temp = *mymar;
		*mymar = *commar;
		*commar = temp;
	}
	else if (*commar <= 1)
	{
		printf("우리는 깐부잖아.....");
		Sleep(1500);
		printf("덕분에 즐거웠어\n");
		Sleep(1500);
		printf("남은 구슬....");
		Sleep(1500);
		printf("자네가 가져\n\n");
		Sleep(3000);
		*mymar = MARBLE;
		*commar = 0;
	}
	printf("최종 결과\n");
	printmarble(*mymar, "내");
	printmarble(*commar, "상대방");
	Sleep(1000);
	printf("\n456번 다음 라운드 진출\n");
	Sleep(3000);
	system("cls");
	printf("당신도 게임에 참가하시겠습니까?\n");
	Sleep(3000);
	system("cls");
	printf("○△□\n010-7288-4122\n");
}