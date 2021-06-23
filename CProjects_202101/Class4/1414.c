#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int makerandomnumber(int arr[]);
void playgame(int ball[], int hint);

int main() {
	int n = 0, count = 0, hint = 1;
	system("mode con: cols=70 lines=300");

restart:
	printf("\t\t\t   *숫자야구*\n\n");
	printf("\t1. game rule & game set	 2. game start	3. game end\n");
	int ball[5] = { 0 };
	scanf("%d", &n);
	switch (n) {
	case 1:
		printf("--------------------------game rule explain---------------------------\n");
		printf("1. 게임이 시작되면 5자리의 겹치지 않는 수를 입력합니다.\n");
		printf("\n2. 5자리의 입력된 수 중 문제로 제시된 숫자와 겹치는 수가 있으면 ball, \n입력된수와 자리가 모두 맞다면 strike라고 알려줄것입니다.\n");
		printf("\n\n예시로 답이 71982 일때 당신이 입력한 수가 12345라면 2 ball 0 strike,\n 95680이라면 1 ball 1 strike라고 알려줄것입니다.");
		printf("\n\n3. 알려준 개수를 통해 정답을 추리하세요!");
		printf("\n\n4. 45 round까지도 답을 맞추지 못하면 게임이 종료될수 있습니다. 어렵다면 힌트를 제공해 드립니다!\n\n");
		printf("\n\n5. 매 라운드마다 점수가 뜰 것입니다. 이 점수는 스트라이크 하나마다\n 100점, 볼 하나마다 10점으로 카운트 됩니다. \n 최종 점수가 500에 가까울수록 좋겠죠?\n");
		printf("----------------------------------------------------------------------\n");
		system("pause");

		// 힌트 설정 바꾸기, 만약 1을 거치지 않는다면 그냥 힌트 사용
		printf("\n\n힌트 기능을 사용하시겠습니까? \n힌트 사용한다면 1을 입력, 사용 안할 경우 1은 제외한 아무숫자나 입력\n\t\t");
		scanf("%d", &hint);
		if (hint == 1) printf("\n힌트를 사용합니다.\n");
		else printf("\n힌트를 사용하지 않습니다.\n");

		printf("\n\t\t5초후에 시작화면으로 돌아갑니다.");
		_sleep(5000);
		system("cls");
		goto restart;
	case 2:
		printf("game start\n");
		makerandomnumber(ball);
		playgame(ball, hint);
		system("cls");
		goto restart;
	case 3:
		printf("game end");
		break;
	}
}

//겹치지 않는 5자리 수 만들기
int makerandomnumber(int ball[]) {
	srand(time(NULL));
	int stk = 0, chk[11] = { 0 };
	while (stk < 5) {
		int tmp = rand() % 9 + 1;
		if (chk[tmp])continue;
		ball[stk++] = tmp;
		chk[tmp] = 1;
	}
	return ball;
}


//게임을 플레이 하는 함수
void playgame(int ball[], int hint) {
	int ROUND = 0, score = 0;
	system("cls");
	printf("게임을 시작합니다.");
	int e[45] = { 0 }, playball[45][5] = { 0 }, strike[45] = { 0 }, bal[45] = { 0 };
	//e는 입력받은 수를 그대로 저장해 두는 용도, playball은 한자리씩 끊어서 저장, [45]는 몇 라운드인지,[5]는 입력받은수 끊어서 저장
	//strike[45]와 ball[45] 는 각 라운드마다의 스트라이크와 볼 값을 저장함

	while (1) {
		int a, c, count = 0;
		ROUND++;
		printf("\n\n\t\tround %d", ROUND);
	input:
		while (1) {		//입력받아 5자리수인지 확인
			printf("\n\t맞추세요: ");
			scanf("%d", &a);
			c = a;
			count = 0;
			while (c > 0) {
				c /= 10;
				count++;
			}
			if (count == 5) break;
			else printf("\t5자리 수를 입력하세요.\n");
		}
		e[ROUND - 1] = a;
		//playball배열에 한자리씩 저장
		for (int i = 0; i <= 4; i++) {
			playball[ROUND - 1][4 - i] = (a % 10);
			a /= 10;
		}

		//겹치는 자리수 있는지 확인
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				if (playball[ROUND - 1][i] == playball[ROUND - 1][j]) {
					printf("\t겹치지 않는 수를 입력하세요. \n");
					goto input;
				}
			}
		}

		for (int i = 0; i < ROUND - 1; i++) {
			if (e[ROUND - 1] == e[i]) {
				printf(" 이전 라운드에서 입력했던 수입니다.");
				goto input;
			}
		}



		//스트라이크, 볼 개수 세서 라운드에 해당하는 배열에 저장
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				if (ball[i] == playball[ROUND - 1][j]) {
					if (i == j) {
						score += 100;
						strike[ROUND - 1]++;
					}
					else {
						bal[ROUND - 1]++;
						score += 10;
					}
				}
			}
		}
		// 출력
		printf("\t%d ball %d strike\n \t\tscore :%d \n", bal[ROUND - 1], strike[ROUND - 1], score);
		system("pause");

		int p;
		printf("게임을 계속하시겠습니까? 종료 하시려면 1, 계속하시려면 아무 숫자나 눌러주세요.");
		scanf("%d", &p);		// 중간에 멈추기
		if (p == 1) {		//종료 전 점수 출력
			printf("score : %d\n", score);
			system("pause");
			break;
		}

		system("cls");
		for (int i = 1; i <= ROUND; i++) {
			printf("round %d   %d     %d strike %d ball\n", i, e[i - 1], strike[i - 1], bal[i - 1]);
		}
		//콘솔창에 간단히 뜨도록 정리

		/*
					게임 종료 조건과 힌트
			5자리를 모두 맞추면 (스트라이크 5개이면) 종료
			10라운드마다 한번씩 힌트 제공
			앞자리수 부터 한자리씩 알려줌
			45라운드까지 했음에도 답을 맞추지 못하면 게임종료
		*/

		if (strike[ROUND - 1] == 5) {   //5자리 모두 맞추어 종료, 종료시 점수 출력
			system("cls");
			printf("\n\n\n\n\n\n\n\t\t\tHOMERUN\n\n\n\n\n\n\n\n\t\tscore : %d", score);
			_sleep(5000);
			break;
		}
		if ((ROUND == 10 || ROUND == 20 || ROUND == 30 || ROUND == 40) && hint == 1) {
			//힌트 출력, 힌트 설정에서 힌트값을 바꾸어 힌트 사용 안 할 수 있음
			printf("\n\t\thint : %d번째 자릿수는 %d입니다.", ROUND / 10, ball[(ROUND / 10) - 1]);
		}
		if (ROUND == 45) {
			//45라운드까지 못맞출시 종료
			system("cls");
			printf("\n\n\n\n\t\t\t게임 실패.... 당신은 바보인가요...");
			printf("\n\n\n\n\n\t\t\t\tscore: %d", score);
			_sleep(5000);
			break;
		}
	}
}