#include<stdio.h>

typedef struct {
	char name[10];
	char ability[5][10];
	int info[5];
}card;

void printCardInfo(char* cardOwner, card* card) {
	printf("%s - %s\n", cardOwner, card->name);

	// �ɷ� ��Ī ���
	for (int i = 0; i < 5; i++)
		printf("|%s", card->ability[i]);
	printf("|\n");

	// �ɷ� ��ġ ���
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
	card A = { "����", { "���", "����", "����", "��ġ", "�ŷ�" }, { 75, 73, 74, 78, 99 } };
	card B = { "����", { "���", "����", "����", "��ġ", "�ŷ�" }, { 96, 72, 91, 94, 96 } };

	card* myCard = &A;
	card* comCard = &B;

	printCardInfo("�÷��̾� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("�÷��̾� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	return 0;
}