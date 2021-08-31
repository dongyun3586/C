#include<stdio.h>

void printCardInfo(char* cardOwner, void** card);
void swapCard(void** c1, void** c2);
void cardBattle(void** myCard, void** comCard);

int main() {
	char nameA[10] = "유비", nameB[10] = "조조";
	int infoA[5] = { 75, 73, 74, 78, 99 }, infoB[5] = { 96, 72, 91, 94, 96 };

	void* cardA[2] = { nameA, infoA };
	void* cardB[2] = { nameB, infoB };
	void* myCard = cardA;
	void* comCard = cardB;

	printCardInfo("플레이어 카드", myCard);
	printCardInfo("컴퓨터 카드", comCard);

	cardBattle(myCard, comCard);

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("플레이어 카드", myCard);
	printCardInfo("컴퓨터 카드", comCard);

	cardBattle(myCard, comCard);

	return 0;
}

void printCardInfo(char* cardOwner, void** card) {
	printf("%s - %s\n", cardOwner, (char*)*card);	// (char*)card[0]
	printf("|통솔|무력|지력|정치|매력|\n");
	for (int i = 0; i < 5; i++)
		printf("| %d ", *((int*)*(card + 1) + i));	// *((int*)card[1] + i)
	printf("|\n\n");
}

void swapCard(void** c1, void** c2) {
	void* temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void cardBattle(void** myCard, void** comCard) {
	int sumA = 0, sumB = 0;
	for (int i = 0; i < 5; i++) {
		sumA += *((int*)*(myCard + 1) + i);
		sumB += *((int*)*(comCard + 1) + i);
	}
	printf("************* 카드 배틀 *************\n");
	if (sumA > sumB)
		printf("당신의 카드 점수(%d) vs 컴퓨터 카드 점수(%d)로 승리하였습니다.\n", sumA, sumB);
	else
		printf("당신의 카드 점수(%d) vs 컴퓨터 카드 점수(%d)로 패배하였습니다.\n", sumA, sumB);
}