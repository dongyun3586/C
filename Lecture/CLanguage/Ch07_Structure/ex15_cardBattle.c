#include<stdio.h>

typedef struct {
	char name[10];
	int info[5];
}card;

void printCardInfo(char* cardOwner, card* card);
void swapCard(card** c1, card** c2);
void cardBattle(void** myCard, void** comCard);

int main() {
	card A = { "����", { 75, 73, 74, 78, 99 } };
	card B = { "����", { 96, 72, 91, 94, 96 } };

	card* myCard = &A;
	card* comCard = &B;

	printCardInfo("�÷��̾� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	cardBattle(myCard, comCard);

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("�÷��̾� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	cardBattle(myCard, comCard);

	return 0;
}

void printCardInfo(char* cardOwner, card* card) {
	printf("%s - %s\n", cardOwner, card->name);	// (char*)card[0]
	printf("|���|����|����|��ġ|�ŷ�|\n");
	for (int i = 0; i < 5; i++)
		printf("| %d ", card->info[i]);	// *((int*)card[1] + i)
	printf("|\n\n");
}

void swapCard(card** c1, card** c2) {
	card* temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void cardBattle(card* myCard, card* comCard) {
	int sumA = 0, sumB = 0;
	for (int i = 0; i < 5; i++) {
		sumA += myCard->info[i];
		sumB += comCard->info[i];
	}
	printf("************* ī�� ��Ʋ *************\n");
	printf("����� ī�� ���� vs ��ǻ�� ī�� ����\n");
	printf("             %d vs %d\n", sumA, sumB);
	if (sumA > sumB)
		printf("======> ����� �̰���ϴ�.\n");
	else
		printf("======> ��ǻ�Ͱ� �̰���ϴ�.\n");
}