#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h> //함수 kbhit()을 쓰기위해
#include <windows.h> //함수 GetTickCount()를 쓰기위해

/* 함수 GetTickCount()는 현재 시간을 반환하는 함수입니다. 2번째 게임인 반응속도 테스트에서 계속해서 특정 시간을 저장해야하기 때문에 사용하였습니다. -사용방법은 인터넷에서 참고했습니다.
함수 kbhit()은 입력을 했을때 엔터를 누르지 않고도 바로 실행되기위해 버퍼에 값이 있으면 참(1)을 반환하는 함수를 사용했습니다. -사용방법은 인터넷에서 참고했습니다.-
					   이 두 함수 사용법을 제외한 나머지 2번게임의 코드는 전부 제가 작성하였습니다.*/

void RSP(int num); //가위바위보 함수 선언
void UpDown(int num); //업다운 게임 함수 선언

int main() {
	srand(time(NULL)); //난수
	int gameNum; //게임의 번호
	int renum; //게임이 끝난후 실행을 위한 변수
	int gameCount = 0; //총 게임 몇번?
	int timeStart, timeEnd;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("                        ★★★ 1408의 미니게임기 ★★★\n\n");
	printf("미니게임기의 게임으로는 이것들이 있어요!   1. 신명나는 가위바위보,  2. 광속의 반응속도 테스트,  3. 뽀록터지는 업다운게임\n\n");
	timeStart = GetTickCount64();
start:
	printf("\n무슨 게임을 플레이하고 싶으신가요?: ");
	scanf("%d", &gameNum);
	while (gameNum < 1 || gameNum>3) {
		printf("\n제대로 된 숫자를 입력해주세요: ");
		scanf("%d", &gameNum);
	}
	if (gameNum == 1) {
		int RSPnum; //가위바위보 플레이 횟수
	again1:
		printf("\n                '신명나는 가위바위보' 게임을 시작합니다!!\n\n");
		printf("'신명나는 가위바위보' 게임에서는  주먹:1, 가위:2, 보:3 라 입력해주시면 됩니다!");
		printf("\n\n가위바위보를 몇번 플레이 하실 건가요?: ");
		scanf("%d", &RSPnum);
		RSP(RSPnum);
		gameCount++;
		printf("\n\n                           ★★★★★게임이 끝났습니다!★★★★★\n\n다시 이 게임을 플레이 하시려면 1번, 다른 게임을 플레이 하시려면 2번, 미니게임을 종료하려면 3번을 누르세요: ");
		scanf("%d", &renum);
		while (renum < 1 || renum>3) {
			printf("\n제대로 된 숫자를 입력해주세요: ");
			scanf("%d", &renum);
		}
		if (renum == 1) goto again1;
		else if (renum == 2) goto start;
		else if (renum == 3) goto end;
	}
	else if (gameNum == 2) { //반응속도 테스트 코드
		int time1, time2;
		int randomTime;
	again2:
		printf("반응속도 테스트를 시작합니다 벽돌이 나오면 아무 키나 누르세요!");
		_sleep(1000);
		time1 = GetTickCount64();
		randomTime = rand() % 4000 + 400;
	regame:
		while (1)
		{
			if (GetTickCount64() - time1 >= randomTime) {
				printf("\n■■■■■■■■\n■■■■■■■■\n■■■■■■■■\n■■■■■■■■\n■■■■■■■■\n■■■■■■■■\n■■■■■■■■\n■■■■■■■■");
				time2 = GetTickCount64();
				break;
			}
		}
		while (1) {
			if (kbhit())
			{
				printf("\n\n당신의 반응속도는 %.2f입니다.", (float)(GetTickCount64() - time2) / 1000);
				break;
			}
		}
		gameCount++;
		printf("\n\n                           ★★★★★게임이 끝났습니다!★★★★★\n\n다시 이 게임을 플레이 하시려면 1번, 다른 게임을 플레이 하시려면 2번, 미니게임을 종료하려면 3번을 누르세요: ");
		scanf("%d", &renum);
		while (renum < 1 || renum>3) {
			printf("\n제대로 된 숫자를 입력해주세요: ");
			scanf("%d", &renum);
		}
		if (renum == 1) goto again2;
		else if (renum == 2) goto start;
		else if (renum == 3) goto end;
	}
	else if (gameNum == 3) {
		int level; //게임 난이도
	again3:
		printf("\n               '뽀록터지는 업다운게임' 을 시작합니다!!\n\n");
		printf("'뽀록터지는 업다운게임'은 난이도를 지정할 수 있습니다. 단계를 정해주세요 1, 2, 3: ");
		scanf("%d", &level);
		UpDown(level);
		gameCount++;
		printf("\n\n                           ★★★★★게임이 끝났습니다!★★★★★\n\n다시 이 게임을 플레이 하시려면 1번, 다른 게임을 플레이 하시려면 2번, 미니게임을 종료하려면 3번을 누르세요: ");
		scanf("%d", &renum);
		while (renum < 1 || renum>3) {
			printf("\n제대로 된 숫자를 입력해주세요: ");
			scanf("%d", &renum);
		}
		if (renum == 1) goto again3;
		else if (renum == 2) goto start;
		else if (renum == 3) goto end;
	}
end:
	timeEnd = GetTickCount64();
	printf("\n이용해줘서 감사합니다!  당신은 총 %d번의 게임을 플레이하였으며 총 %d초 동안 이용하셨습니다.\n", gameCount, (timeEnd - timeStart) / 1000);

	return 0;
}

//가위바위보 함수 정의
void RSP(int num) {
	int comnum; //컴퓨터가 내는것, comnum==1: 주먹, comnum==2: 가위, comnum==3: 보
	int mynum; //내가 내는것 
	int count = 0; //이긴 횟수 세는 변수

	for (int i = 1; i <= num; i++) {
		comnum = rand() % 3 + 1;
		printf("\n\n무엇을 내실건가요?: ");
		scanf("%d", &mynum);
		while (mynum < 1 || mynum>3) {
			printf("다시 입력해주세요: ");
			scanf("%d", &mynum);
		}
		if (mynum == 1) {
			switch (comnum) {
			case 1:
				printf("컴퓨터: 주먹\n당신: 주먹\n비겼다.");
				break;
			case 2:
				printf("컴퓨터: 가위\n당신: 주먹\n이겼다!");
				count++;
				break;
			case 3:
				printf("컴퓨터: 보\n당신: 주먹\n졌다 ㅠ");
				break;
			}
		}
		else if (mynum == 2) {
			switch (comnum) {
			case 2:
				printf("컴퓨터: 가위\n당신: 가위\n비겼다.");
				break;
			case 3:
				printf("컴퓨터: 보\n당신: 가위\n이겼다!");
				count++;
				break;
			case 1:
				printf("컴퓨터: 주먹\n당신: 가위\n졌다 ㅠ");
				break;
			}
		}
		else if (mynum == 3) {
			switch (comnum) {
			case 3:
				printf("컴퓨터: 보\n당신: 보\n비겼다\n");
				break;
			case 1:
				printf("컴퓨터: 주먹\n당신: 보\n이겼다!");
				count++;
				break;
			case 2:
				printf("컴퓨터 가위\n당신: 보\n졌다 ㅠ");
				break;
			}
		}
	}
	printf("\n\n당신은 %d번 중 %d번 이기셨습니다.", num, count);
}



//업다운 게임 함수 정의
void UpDown(int num) {
	srand(time(NULL));
	int max, n;
	int m = 0, chance, count = 0;
	if (num == 1) {
		max = 50;
		n = rand() % max + 1;
		chance = 6;
		printf("1단계로 설정 되었습니다.\n");
		_sleep(1000);
		printf("업다운게임을 시작합니다!");
	}
	else if (num == 2) {
		max = 100;
		n = rand() % max + 1;
		chance = 5;
		printf("2단계로 설정 되었습니다.\n");
		_sleep(1000);
		printf("업다운게임을 시작합니다!");
	}
	else if (num == 3) {
		max = 500;
		n = rand() % max + 1;
		chance = 7;
		printf("3단계로 설정 되었습니다.\n");
		_sleep(1000);
		printf("업다운게임을 시작합니다!");
	}
	else {
		max = 2000;
		n = rand() % max + 1;
		chance = 7;
		printf("오호? 당신은 난이도에 없는 숫자를 입력하셨습니다.\n");
		_sleep(2000);
		printf("극악의 난이도의 업다운게임이 시작됩니다.");
	}

	printf("\n\n1부터 %d 사이의 수를 추측하는 게임입니다!", max);
	while (n != m) {
		printf("\n\n정답은?: ");
		scanf("%d", &m);
		if (n > m) {
			printf("틀렸습니다. %d 보다 큽니다.", m);
		}
		else if (n < m) {
			printf("틀렸습니다. %d 보다 작습니다.", m);
		}
		if (n == m) break;
		chance--;
		count++;
		printf("\n\n남은 기회: %d번", chance);
		if (chance == 0) {
			printf("\n실패했습니다. 정답은 %d이었습니다.", n);
			goto ending;
		}
	}
	printf("\n정답입니다.\n\n%d번 만에 맞혔습니다.", count);
ending:
	printf("끝났당");
}
