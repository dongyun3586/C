#include<stdio.h>

typedef struct {
	char name[10];
	char ability[5][10];
	int info[5];
}card;

void printCardInfo(char* cardOwner, card* card) {
	printf("%s - %s\n", cardOwner, card->name);

	// 능력 명칭 출력
	for (int i = 0; i < 5; i++)
		printf("|%s", card->ability[i]);
	printf("|\n");

	// 능력 수치 출력
	for (int i = 0; i < 5; i++)
		printf("| %d ", card->info[i]);	// *((int*)card[1] + i)
	printf("|\n\n");
}

void swapCard(card** c1, card** c2) {
	card* temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

int main() {
	card A = { "유비", { "통솔", "무력", "지력", "정치", "매력" }, { 75, 73, 74, 78, 99 } };
	card B = { "조조", { "통솔", "무력", "지력", "정치", "매력" }, { 96, 72, 91, 94, 96 } };

	card* myCard = &A;
	card* comCard = &B;

	printCardInfo("플레이어 카드", myCard);
	printCardInfo("컴퓨터 카드", comCard);

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("플레이어 카드", myCard);
	printCardInfo("컴퓨터 카드", comCard);

	return 0;
}