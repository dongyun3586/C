#include<stdio.h>

void printCardInfo(char* cardOwner, void** card);
void swapCard(void** c1, void** c2);

int main() {
	char nameA[10] = "����", nameB[10] = "����";
	int infoA[5] = { 75, 73, 74, 78, 99 }, infoB[5] = { 96, 72, 91, 94, 96 };

	void* cardA[2] = { nameA, infoA };
	void* cardB[2] = { nameB, infoB };

	void* myCard = cardA;
	void* comCard = cardB;

	printCardInfo("�÷��̾� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("�÷��̾� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	return 0;
}

void printCardInfo(char* cardOwner, void** card) {
	printf("<%s> - %s\n", cardOwner, (char*)*card);	// (char*)card[0]
	printf("|���|����|����|��ġ|�ŷ�|\n");
	for (int i = 0; i < 5; i++)
		printf("| %d ", *((int*)*(card + 1) + i));	// *((int*)card[1] + i)
	printf("|\n");
}

void swapCard(void** c1, void** c2) {
	void* temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}