#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma region
void startorexplaingame(); // 게임 설명, 시작
int randomcard(int cards[], int card[]); // 카드 무작위로 배열
int printrandomcard(int card[]); // ◆, ♠, ♣, ♥, A, K, Q, J 등 카드의 모양을 카드 번호에 따라 알맞게 출력
int printnowcard(); // 플레이어가 낸 카드에 따라 알맞은 모양과 숫자 출력
#pragma endregion

int main() {
	srand(time(NULL));
	int card[52] = { 101,102,103,104,105,106,107,108,109,110,111,112,113,201,202,203,204,205,206,207,208,209,210,211,212,213,301,302,303,304,305,306,307,308,309,310,311,312,313,401,402,403,404,405,406,407,408,409,410,411,412,413 }; // 섞기 전 전체 카드 목록
	int cards[52]; // 섞을 카드
	int cardnum_player = 0, count = 0, now; // 각각 플레이어 카드, 사용한 카드의 개수, 현재 나와 있는 카드를 나타냄
	int i, j, tmp, put, check = 0; // 각각 for문에 사용, 매개 변수, 제출할 카드의 번호, ?
	int playercard[20] = { 0 }; // 플레이어 카드 배열(크기는 임의로 설정함)
	startorexplaingame(); // 게임 설명, 시작
	randomcard(cards, card); // 카드 무작위로 배열
	now = cards[count++]; // 참조?
	for (i = 0; i < 5; i++) {
		playercard[i] = cards[count++];
		cardnum_player++;
	} // 처음에 플레이어에게 카드를 5장 나눠줌
	while (1) { // return 0할 때까지 무한히 반복
		check = 0;
		printnowcard(playercard, now); // 플레이어 카드 5장과 현재 나와 있는 카드 1장 출력
		printf("\n몇 번째 카드를 내시겠습니까?(기권 99): ");
		scanf("%d", &put);
		if (put == 99) {
			printf("\n\n\n\n\n\n기권!\n카드가 %d장 남은 상태로 끝났습니다.\n\n\n\n", cardnum_player);
			return 0;
		}
		if ((playercard[put - 1] % 100 != now % 100) && (playercard[put - 1] / 100 != now / 100)) { // 조건에 맞지 않는 카드를 낸 경우
			printf("\n낼 수 없는 카드입니다.\n");
			check = 1; //
			continue;
		}
		if ((playercard[put - 1] % 100 == now % 100) || (playercard[put - 1] / 100 == now / 100)) { // 조건에 맞는 카드를 낸 경우
			now = playercard[put - 1]; // 현재 나와 있는 카드를 방금 낸 카드로 변경
			playercard[put - 1] = 0; // 낸 카드 빼기
			cardnum_player--; // 플레이어의 카드 개수 1만큼 감소
			for (int i = cardnum_player; i <= put + 1; i++) { // 남은 카드 재배열
				playercard[i - 1] = playercard[i];
				playercard[put] = 0;
			}
			playercard[put] = 0;
		}
		if (cardnum_player == 0) { // 남은 카드 개수가 0일 때
			printf("승리!\n축하합니다. 모든 카드를 다 내서 승리하였습니다.");
			return 0;
		}
	}
	printnowcard(playercard, now);
}

void startorexplaingame() { // 게임 설명, 시작
	int start;
	printf("***One Card Game***\n시작하려면 아무 숫자나 누르십시오.\n게임 설명을 보고 시작하려면 1을 누르십시오.\n");
	scanf("%d", &start);
	switch (start) {
	case(1):
		printf("One Card Game은 트럼프 카드로 하는 게임입니다. 한 사람당 5장의 카드를 받은 뒤, 노출되어 있는 카드와 모양이나 숫자가 같은 카드만 낼 수 있습니다. 자신이 가지고 있는 모든 카드를 내면 이기게 됩니다.\n");
	default:
		printf("게임을 시작합니다.\n");
	}
}

int randomcard(int cards[], int card[]) { // card[] --> cards[]로 카드 무작위로 배열?
	srand(time(NULL));
	int i, j, random, check = 0;
	for (i = 0; i < 52; i++) { // 52번 반복
		while (1) {
			random = rand() % 52;
			for (j = 0; j < i; j++) { // i번 반복
				if (cards[j] == card[random]) {
					check = 1;
					break;
				}
			}
			if (check == 0) {
				cards[i] = card[random];
				break;
			}
			check = 0;
		}
	}
}

int printrandomcard(int card[]) { // 무작위 난수가 들어있는 배열 card[]에서 카드 번호에 따라 ◆, ♠, ♣, ♥, A, K, Q, J 등 카드의 모양을 알맞게 출력
	int i;
	printf("\n플레이어 카드 목록 | 나와 있는 카드(1개)\n");
	for (i = 0; i < 5; i++) { // 5번 반복
		switch (card[i] / 100) { // 각 카드에 따라 문양 표시
		case 1:
			printf(" ◆");
			break;
		case 2:
			printf(" ♠");
			break;
		case 3:
			printf(" ♣");
			break;
		case 4:
			printf(" ♥");
		}
		if (card[i] % 100 <= 10 && card[i] % 100 > 1) // 각 카드에 따라 숫자 또는 알파벳 표시
			printf(" %d ", card[i] % 100);
		else if (card[i] % 100 == 1)
			printf("A");
		else if (card[i] % 100 == 13)
			printf("K");
		else if (card[i] % 100 == 12)
			printf("Q");
		else if (card[i] % 100 == 11)
			printf("J");
	}
}

int printnowcard(int playercard, int now) {
	printrandomcard(playercard); // 카드 목록을 보여줌
	switch (now / 100) { // 현재 카드에 따라 문양 표시
	case 1:
		printf(" ◆");
		break;
	case 2:
		printf(" ♠");
		break;
	case 3:
		printf(" ♣");
		break;
	case 4:
		printf(" ♥");
	}
	if (now % 100 <= 10 && now % 100 > 1) // 현재 카드에 따라 숫자 또는 알파벳 표시
		printf(" %2d", now % 100);
	else if (now % 100 == 1)
		printf("A ");
	else if (now % 100 == 13)
		printf("K ");
	else if (now % 100 == 12)
		printf("Q ");
	else if (now % 100 == 11)
		printf("J ");
}