#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<wchar.h>
#include<locale.h>
#include<windows.h>
wchar_t shape[4] = { L'��',L'��',L'��',L'��' }; // ī�带 ����� �� ���� ���
char* player[4] = { "user","com1","com2","com3" }; // ������ ����� �� ���� ���ڿ� �迭
int k = 0, n = 0, dir = 1; //k�� ����,n�� �� ���� �������� ��(user+com),dir ���� ���ư��� ����
typedef struct {//ī�� �� ��
	int num;//ī�� ���� 1 = A, 11 = K, 12 = Q, 13 = J // ī���� ��
	wchar_t shape; // ī���� ���
}Card;
typedef struct {//ī�� �ٷ���
	Card* card; //ī���
	int count; //ī���� ����
}CardPack;
Card PickCard(CardPack* card, int i) {//�̰��� �ϴ� ������ ī�带 �̰� CardPack ������
	Card pick = card->card[i];//���� ī��
	for (int j = i; j < (card->count) - 1; j++)
		card->card[j] = card->card[j + 1];
	(card->count)--;
	return pick;
}
void PrintCard(Card* card, int i) { // ������ �ִ� ī��� ���
	printf("\n");
	for (int j = 0; j < i; j++)	wprintf(L"|%c  | ", (card + j)->shape);
	printf("\n");
	for (int j = 0; j < i; j++)	printf("|    | ");
	printf("\n");
	for (int j = 0; j < i; j++) {
		if ((card + j)->num == 1) {
			wprintf(L"|   A| ");
		}
		else if ((card + j)->num == 11) {
			wprintf(L"|   K| ");
		}
		else if ((card + j)->num == 12) {
			wprintf(L"|   Q| ");
		}
		else if ((card + j)->num == 13) {
			wprintf(L"|   J| ");
		}
		else {
			printf("|  %2d| ", (card + j)->num);
		}
	}printf("\n");
}
void Check(Card gameCard, CardPack card, int* Can, int* countCan, int j) { //gameCard�� ������ �� card���� �� �� �ִ� ī���� �迭 ����,Can �� �� �ִ� ī�� �迭,count �� �� �ִ� ī�� ��,j com���� user���� üũ�ϱ� ���� ����
	if (j)	printf("\n�� �� �ִ� ī��\n"); //j�� ���� com���� user���� üũ
	*countCan = 0;//�ʱ�ȭ
	for (int i = 0; i < 19; i++) { //�ʱ�ȭ
		Can[i] = 0;
	}
	for (int i = 0; i < card.count; i++) {//�� �� �迭�� ������ ī���� ���� ��� +�迭�� �ֱ�
		if (gameCard.num == card.card[i].num || gameCard.shape == card.card[i].shape) {
			if (j)	printf("%d�� ", i + 1);
			Can[*countCan] = i;
			++* countCan;
		}
	}if (j)	printf("\n");
}
void Game(Card* gameCard, CardPack* play, CardPack* card) {//���� ����
	char i = 0;
	Sleep(1000); //delay 1��
	printf("\n----------------------%s---------------------\n", player[k]);//���� �������� ���
	printf("���� ī�� : %d��", play->count);//���� ī�� ���
	int Can[19] = { 0 }; //�� �� �ִ� ī���� ������ ���� �迭
	int countCan = 0; //�� �� �ִ� ī���� ������ ���� ����
	if (!k) {//user���� �ƴ��� �Ǵ�, k = 0�̸� user�� ���� �ȳ� �ڵ� ����
		printf("\ngameCard\n");
		PrintCard(gameCard, 1);
		printf("\nyour Card\n");
		PrintCard(play->card, play->count);
	}
	Check(*gameCard, *play, Can, &countCan, !k);//�� �� �ִ� ī�� üũ
	if (countCan == 0) {//�� �� �ִ� ī�尡 ������ ����
		printf("\n�� �� �ִ� ī�尡 �����ϴ�.\nī�带 �����ɴϴ�.");
		if (!k) {
			rewind(stdin);
			getchar(i);
			Sleep(1000); // enter ������ 1�� delay �� ����
		}
		play->card[play->count] = PickCard(card, rand() % (card->count));//��ü ī�忡�� �������� ī�� �� �� ������
		if (!k) { // user�� �� �ȳ�
			printf("\n������ ī��");
			PrintCard(play->card + play->count, 1);
		}
		--(card->count);
		++(play->count);
	}
	else {//�� ī�尡 ������
		int choose;
		int j = 0;
		if (!k) {
			printf("�� ī�带 �����ϼ���");
			while (1) {//�� �� �ִ� ī�� ������ ������ �� ī�� �Է�
				scanf("%d", &choose);
				for (int i = 0; i < countCan; i++) {
					if (choose == Can[i] + 1) {
						j = 1;
						break;
					}
				}if (j) {
					break;
				}
				else {
					printf("\n�� �� �ִ� ī�带 �������ּ���.");
				}
			}
		}
		card->card[card->count] = *gameCard;//������ �ִ� gameCard ��ü card ī��������
		++card->count;
		if (k)	*gameCard = PickCard(play, Can[rand() % countCan]); // com�̸� �������� gameCard��
		else    *gameCard = PickCard(play, choose - 1);//user�� ������ ī�� gameCard��
		switch (gameCard->num) {//K,Q,J���� Ư�� ī�� ��ɵ�
		case(11):
			k -= dir;
			break;
		case(12):
			dir = -dir;
			break;
		case(13):
			k += dir;
			break;
		default:
			break;
		}

	}
	printf("\ngameCard\n");
	PrintCard(gameCard, 1);//���� gameCard ���
	k += dir; // ���� �Ѿ��
	if (k < 0)	k += n;
	if (k / n != 0)	k = k % n;
}
int main() {
	setlocale(LC_ALL, "");//�����ڵ带 ����ϱ� ���� ��ġ ����
	printf("�� ���� ��ǻ�Ϳ� �÷����Ͻðڽ��ϱ�?(�ִ� 3��)\n");
	while (1) {
		scanf("%d", &n);//�÷����� com �� �Է�
		if (n >= 4 || n <= 0)	printf("�ִ� 3������ �����մϴ�. �ٽ� �Է����ּ���.\n");
		else   break;
	}
	n++;//user �߰�
	Card gameCard;//���ӿ��� ���� �ִ� ī��
	CardPack card;//��ü ī�� ����
	CardPack* play_ = malloc(sizeof(CardPack) * n);//�ʿ��� player ����ŭ ī�� ���� �޸� �Ҵ�
	card.card = malloc(sizeof(Card) * 52); // card�� ī�� 52�� �޸� �Ҵ�
	card.count = 0;//�ʱ�ȭ
	for (int i = 0; i < n; i++) {//player �� ī�� �޸� �Ҵ� �� �ʱ�ȭ
		play_[i].card = malloc(sizeof(Card) * 19);
		play_[i].count = 0;
	}
	int win = 0, end = 0; // win �̱� ���,end ������ ���� ����
	for (int i = 0; i < 4; i++) { // card�� ��Ŀ�� �� ��ī�� ��üī�� �ֱ�
		for (int j = 1; j <= 13; j++) {
			card.card[card.count].num = j;
			card.card[card.count].shape = shape[i];
			card.count++;
		}
	}
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {//card ����
		int r = rand() % 52;
		Card temp = card.card[i];
		card.card[i] = card.card[r];
		card.card[r] = temp;
	}
	gameCard = PickCard(&card, rand() % card.count);//�������� ī�� �� �� gameCard��
	for (int i = 0; i < n; i++) {//�÷��̾� ī�� 7�徿 �й�
		for (int j = 0; j < 7; j++) {
			play_[i].card[play_[i].count] = PickCard(&card, rand() % card.count);
			play_[i].count++;
		}
	}
	printf("������ �����մϴ�.\n");//����
	while (!end) {//end = 1�� ������ ����
		Game(&gameCard, &play_[k], &card);//���� ����
		for (int i = 0; i < n; i++) {//ī�� ������ 0�� �� player�� �ִ� �� ����
			if (play_[i].count == 0) {
				win = i; // ����
				end = 1; // ����
			}
		}

	}
	if (win == 0) {//user�� �����̸�
		printf("�¸��ϼ̽��ϴ�.");
	}
	else {
		printf("�й��ϼ̽��ϴ�.");
	}
}