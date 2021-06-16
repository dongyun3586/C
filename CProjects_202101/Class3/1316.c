#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma region
void startorexplaingame(); // ���� ����, ����
int randomcard(int cards[], int card[]); // ī�� �������� �迭
int printrandomcard(int card[]); // ��, ��, ��, ��, A, K, Q, J �� ī���� ����� ī�� ��ȣ�� ���� �˸°� ���
int printnowcard(); // �÷��̾ �� ī�忡 ���� �˸��� ���� ���� ���
#pragma endregion

int main() {
	srand(time(NULL));
	int card[52] = { 101,102,103,104,105,106,107,108,109,110,111,112,113,201,202,203,204,205,206,207,208,209,210,211,212,213,301,302,303,304,305,306,307,308,309,310,311,312,313,401,402,403,404,405,406,407,408,409,410,411,412,413 }; // ���� �� ��ü ī�� ���
	int cards[52]; // ���� ī��
	int cardnum_player = 0, count = 0, now; // ���� �÷��̾� ī��, ����� ī���� ����, ���� ���� �ִ� ī�带 ��Ÿ��
	int i, j, tmp, put, check = 0; // ���� for���� ���, �Ű� ����, ������ ī���� ��ȣ, ?
	int playercard[20] = { 0 }; // �÷��̾� ī�� �迭(ũ��� ���Ƿ� ������)
	startorexplaingame(); // ���� ����, ����
	randomcard(cards, card); // ī�� �������� �迭
	now = cards[count++]; // ����?
	for (i = 0; i < 5; i++) {
		playercard[i] = cards[count++];
		cardnum_player++;
	} // ó���� �÷��̾�� ī�带 5�� ������
	while (1) { // return 0�� ������ ������ �ݺ�
		check = 0;
		printnowcard(playercard, now); // �÷��̾� ī�� 5��� ���� ���� �ִ� ī�� 1�� ���
		printf("\n�� ��° ī�带 ���ðڽ��ϱ�?(��� 99): ");
		scanf("%d", &put);
		if (put == 99) {
			printf("\n\n\n\n\n\n���!\nī�尡 %d�� ���� ���·� �������ϴ�.\n\n\n\n", cardnum_player);
			return 0;
		}
		if ((playercard[put - 1] % 100 != now % 100) && (playercard[put - 1] / 100 != now / 100)) { // ���ǿ� ���� �ʴ� ī�带 �� ���
			printf("\n�� �� ���� ī���Դϴ�.\n");
			check = 1; //
			continue;
		}
		if ((playercard[put - 1] % 100 == now % 100) || (playercard[put - 1] / 100 == now / 100)) { // ���ǿ� �´� ī�带 �� ���
			now = playercard[put - 1]; // ���� ���� �ִ� ī�带 ��� �� ī��� ����
			playercard[put - 1] = 0; // �� ī�� ����
			cardnum_player--; // �÷��̾��� ī�� ���� 1��ŭ ����
			for (int i = cardnum_player; i <= put + 1; i++) { // ���� ī�� ��迭
				playercard[i - 1] = playercard[i];
				playercard[put] = 0;
			}
			playercard[put] = 0;
		}
		if (cardnum_player == 0) { // ���� ī�� ������ 0�� ��
			printf("�¸�!\n�����մϴ�. ��� ī�带 �� ���� �¸��Ͽ����ϴ�.");
			return 0;
		}
	}
	printnowcard(playercard, now);
}

void startorexplaingame() { // ���� ����, ����
	int start;
	printf("***One Card Game***\n�����Ϸ��� �ƹ� ���ڳ� �����ʽÿ�.\n���� ������ ���� �����Ϸ��� 1�� �����ʽÿ�.\n");
	scanf("%d", &start);
	switch (start) {
	case(1):
		printf("One Card Game�� Ʈ���� ī��� �ϴ� �����Դϴ�. �� ����� 5���� ī�带 ���� ��, ����Ǿ� �ִ� ī��� ����̳� ���ڰ� ���� ī�常 �� �� �ֽ��ϴ�. �ڽ��� ������ �ִ� ��� ī�带 ���� �̱�� �˴ϴ�.\n");
	default:
		printf("������ �����մϴ�.\n");
	}
}

int randomcard(int cards[], int card[]) { // card[] --> cards[]�� ī�� �������� �迭?
	srand(time(NULL));
	int i, j, random, check = 0;
	for (i = 0; i < 52; i++) { // 52�� �ݺ�
		while (1) {
			random = rand() % 52;
			for (j = 0; j < i; j++) { // i�� �ݺ�
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

int printrandomcard(int card[]) { // ������ ������ ����ִ� �迭 card[]���� ī�� ��ȣ�� ���� ��, ��, ��, ��, A, K, Q, J �� ī���� ����� �˸°� ���
	int i;
	printf("\n�÷��̾� ī�� ��� | ���� �ִ� ī��(1��)\n");
	for (i = 0; i < 5; i++) { // 5�� �ݺ�
		switch (card[i] / 100) { // �� ī�忡 ���� ���� ǥ��
		case 1:
			printf(" ��");
			break;
		case 2:
			printf(" ��");
			break;
		case 3:
			printf(" ��");
			break;
		case 4:
			printf(" ��");
		}
		if (card[i] % 100 <= 10 && card[i] % 100 > 1) // �� ī�忡 ���� ���� �Ǵ� ���ĺ� ǥ��
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
	printrandomcard(playercard); // ī�� ����� ������
	switch (now / 100) { // ���� ī�忡 ���� ���� ǥ��
	case 1:
		printf(" ��");
		break;
	case 2:
		printf(" ��");
		break;
	case 3:
		printf(" ��");
		break;
	case 4:
		printf(" ��");
	}
	if (now % 100 <= 10 && now % 100 > 1) // ���� ī�忡 ���� ���� �Ǵ� ���ĺ� ǥ��
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