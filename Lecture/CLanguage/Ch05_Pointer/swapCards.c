#include<stdio.h>

void printCardInfo(char* cardOwner, void** card) {
	printf("%s - %s\n", cardOwner, (char*)*card);	// (char*)card[0]
	printf("|���|����|����|��ġ|�ŷ�|\n");
	for (int i = 0; i < 5; i++)
		printf("| %d ", *((int*)*(card + 1) + i));	// *((int*)card[1] + i)
	printf("\n");
}

void swapCard(void** c1, void** c2) {
	void* temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

int main() {
	char nameA[10] = "General 1", nameB[10] = "General 2";
	int infoA[5] = { 1,3,5,7,9 }, infoB[5] = { 2,4,6,8,10 };

	void* LDY[2] = { nameA, infoA };	// void* �ڷ��� 2�� ũ�� �迭
	void* COM[2] = { nameB, infoB };

	void* myCard = LDY;
	void* comCard = COM;

	printCardInfo("�� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("�� ī��", myCard);
	printCardInfo("��ǻ�� ī��", comCard);

	return 0;
}