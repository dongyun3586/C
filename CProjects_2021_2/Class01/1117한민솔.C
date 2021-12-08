#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
	int ModeNumber = 0;
	printf("홀짝게임을 시작합니다.\n");
	printf("당신은 두 가지 모드를 플레이하실 수 있습니다.\n");
	printf("원하시는 모드에 따라 버튼을 눌러주세요.\n\n\n");
	printf("1인 모드는 1, 2인 모드는 0을 입력해주세요.\n");
	scanf_s("%d", &ModeNumber);
	if (ModeNumber == 1)
		ComputerMode();
	if (ModeNumber == 0)
		VsMode();
}

int ComputerMode() {
	int username = 0, remainder = 0, number = 0;
	int userscore = 0;
	int playingnumber = 0;

	printf("\n\n\n\n컴퓨터와의 게임 모드입니다.\n");
	printf("게임 횟수를 입력하세요.\n");
	scanf_s("%d", &playingnumber);
	printf("사용자의 별명을 입력하세요. 1부터 456까지의 수만 가능합니다.\n");
	scanf_s("%d", &username);
	if (username > 456 || username < 1) {
		printf("다시 입력해주세요.\n");
	}
	if (1 < username < 456) {
		printf("게임을 진행하겠습니다.\n");
	}
	if (username == 1 || username == 456) {
		printf("게임을 진행하겠습니다.\n");
	}
	do {
		printf("홀수라고 예상할 경우 1을, 짝수라고 예상할 경우 0을 적으세요.\n");
		scanf_s("%d", &remainder);
		srand(time(NULL));
		number = rand() % 1000 + 1;
		printf("\n\n\n\n난수 : %d\n", number);
		playingnumber--;

		if (number % 2 == remainder) {
			printf("승리하셨습니다.\n");
			userscore++;
		}
		else {
			printf("패배하셨습니다.\n");
			userscore--;
		}

	} while (playingnumber != 0)
		; printf("최종 점수 %d입니다.", userscore);
}

int VsMode() {
	int username1 = 0, username2 = 0;
	int playingnumber2 = 0;
	int remainder2 = 0;
	int userscore1 = 0, userscore2 = 0;
	int quiz1 = 0, quiz2 = 0;
	int useranswer1 = 0, useranswer2 = 0;

	printf("사용자 두 명의 홀짝게임입니다.\n");
	printf("사용자1의 이름을 입력하세요. 1부터 456까지의 수만 가능합니다.\n");
	scanf_s("%d", &username1);
	if (username1 > 456 && username1 < 1) {
		printf("다시 입력해주세요.\n");
	}
	if (1 < username1 < 456) {
		printf("입력되었습니다.\n");
	}
	if (username1 == 1 || username1 == 456) {
		printf("입력되었습니다.\n");
	}
	printf("\n\n\n사용자2의 이름을 입력하세요. 1부터 456까지의 수만 가능합니다.\n");
	scanf_s("%d", &username2);
	if (username2 > 456 || username2 < 1) {
		printf("다시 입력해주세요.\n");
	}
	if (1 < username2 < 456) {
		printf("입력되었습니다.\n");
	}
	if (username2 == 1 || username2 == 456) {
		printf("입력되었습니다.\n");
	}
	printf("\n\n\n게임 횟수를 입력하세요.\n");
	scanf_s("&d", &playingnumber2);

	for (int i = playingnumber2; i > 0; i--) {
		printf("사용자1은 사용자2에게 낼 수를 입력하세요.\n");
		scanf_s("%d", &quiz1);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n사용자2는 홀수라면 1, 짝수라면 0를 입력하세요.");
		scanf_s("%d", &useranswer2);
		if (quiz1 % 2 == useranswer2) {
			userscore2++;
			printf("\n축하드립니다. 사용자2의 득점입니다.\n");
		}
		else {
			userscore1++;
			printf("\n축하드립니다. 사용자1의 득점입니다.\n");
		}

		printf("\n\n\n\n사용자2는 사용자1에게 낼 수를 입력하세요.\n");
		scanf_s("%d", &quiz2);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n사용자1은 홀수라면 1, 짝수라면 0을 입력하세요.");
		scanf_s("%d", &useranswer1);
		if (quiz2 % 2 == useranswer1) {
			userscore1++;
			printf("\n축하드립니다. 사용자1의 득점입니다.\n");
		}
		else {
			userscore2++;
			printf("\n축하드립니다. 사용자2의 득점입니다.\n");
		}
	}

	printf("최종 점수 %d, %d입니다.", userscore1, userscore2);
}