#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int makerandomnumber(int arr[]);
void playgame(int ball[], int hint);

int main() {
	int n = 0, count = 0, hint = 1;
	system("mode con: cols=70 lines=300");

restart:
	printf("\t\t\t   *���ھ߱�*\n\n");
	printf("\t1. game rule & game set	 2. game start	3. game end\n");
	int ball[5] = { 0 };
	scanf("%d", &n);
	switch (n) {
	case 1:
		printf("--------------------------game rule explain---------------------------\n");
		printf("1. ������ ���۵Ǹ� 5�ڸ��� ��ġ�� �ʴ� ���� �Է��մϴ�.\n");
		printf("\n2. 5�ڸ��� �Էµ� �� �� ������ ���õ� ���ڿ� ��ġ�� ���� ������ ball, \n�Էµȼ��� �ڸ��� ��� �´ٸ� strike��� �˷��ٰ��Դϴ�.\n");
		printf("\n\n���÷� ���� 71982 �϶� ����� �Է��� ���� 12345��� 2 ball 0 strike,\n 95680�̶�� 1 ball 1 strike��� �˷��ٰ��Դϴ�.");
		printf("\n\n3. �˷��� ������ ���� ������ �߸��ϼ���!");
		printf("\n\n4. 45 round������ ���� ������ ���ϸ� ������ ����ɼ� �ֽ��ϴ�. ��ƴٸ� ��Ʈ�� ������ �帳�ϴ�!\n\n");
		printf("\n\n5. �� ���帶�� ������ �� ���Դϴ�. �� ������ ��Ʈ����ũ �ϳ�����\n 100��, �� �ϳ����� 10������ ī��Ʈ �˴ϴ�. \n ���� ������ 500�� �������� ������?\n");
		printf("----------------------------------------------------------------------\n");
		system("pause");

		// ��Ʈ ���� �ٲٱ�, ���� 1�� ��ġ�� �ʴ´ٸ� �׳� ��Ʈ ���
		printf("\n\n��Ʈ ����� ����Ͻðڽ��ϱ�? \n��Ʈ ����Ѵٸ� 1�� �Է�, ��� ���� ��� 1�� ������ �ƹ����ڳ� �Է�\n\t\t");
		scanf("%d", &hint);
		if (hint == 1) printf("\n��Ʈ�� ����մϴ�.\n");
		else printf("\n��Ʈ�� ������� �ʽ��ϴ�.\n");

		printf("\n\t\t5���Ŀ� ����ȭ������ ���ư��ϴ�.");
		_sleep(5000);
		system("cls");
		goto restart;
	case 2:
		printf("game start\n");
		makerandomnumber(ball);
		playgame(ball, hint);
		system("cls");
		goto restart;
	case 3:
		printf("game end");
		break;
	}
}

//��ġ�� �ʴ� 5�ڸ� �� �����
int makerandomnumber(int ball[]) {
	srand(time(NULL));
	int stk = 0, chk[11] = { 0 };
	while (stk < 5) {
		int tmp = rand() % 9 + 1;
		if (chk[tmp])continue;
		ball[stk++] = tmp;
		chk[tmp] = 1;
	}
	return ball;
}


//������ �÷��� �ϴ� �Լ�
void playgame(int ball[], int hint) {
	int ROUND = 0, score = 0;
	system("cls");
	printf("������ �����մϴ�.");
	int e[45] = { 0 }, playball[45][5] = { 0 }, strike[45] = { 0 }, bal[45] = { 0 };
	//e�� �Է¹��� ���� �״�� ������ �δ� �뵵, playball�� ���ڸ��� ��� ����, [45]�� �� ��������,[5]�� �Է¹����� ��� ����
	//strike[45]�� ball[45] �� �� ���帶���� ��Ʈ����ũ�� �� ���� ������

	while (1) {
		int a, c, count = 0;
		ROUND++;
		printf("\n\n\t\tround %d", ROUND);
	input:
		while (1) {		//�Է¹޾� 5�ڸ������� Ȯ��
			printf("\n\t���߼���: ");
			scanf("%d", &a);
			c = a;
			count = 0;
			while (c > 0) {
				c /= 10;
				count++;
			}
			if (count == 5) break;
			else printf("\t5�ڸ� ���� �Է��ϼ���.\n");
		}
		e[ROUND - 1] = a;
		//playball�迭�� ���ڸ��� ����
		for (int i = 0; i <= 4; i++) {
			playball[ROUND - 1][4 - i] = (a % 10);
			a /= 10;
		}

		//��ġ�� �ڸ��� �ִ��� Ȯ��
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				if (playball[ROUND - 1][i] == playball[ROUND - 1][j]) {
					printf("\t��ġ�� �ʴ� ���� �Է��ϼ���. \n");
					goto input;
				}
			}
		}

		for (int i = 0; i < ROUND - 1; i++) {
			if (e[ROUND - 1] == e[i]) {
				printf(" ���� ���忡�� �Է��ߴ� ���Դϴ�.");
				goto input;
			}
		}



		//��Ʈ����ũ, �� ���� ���� ���忡 �ش��ϴ� �迭�� ����
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				if (ball[i] == playball[ROUND - 1][j]) {
					if (i == j) {
						score += 100;
						strike[ROUND - 1]++;
					}
					else {
						bal[ROUND - 1]++;
						score += 10;
					}
				}
			}
		}
		// ���
		printf("\t%d ball %d strike\n \t\tscore :%d \n", bal[ROUND - 1], strike[ROUND - 1], score);
		system("pause");

		int p;
		printf("������ ����Ͻðڽ��ϱ�? ���� �Ͻ÷��� 1, ����Ͻ÷��� �ƹ� ���ڳ� �����ּ���.");
		scanf("%d", &p);		// �߰��� ���߱�
		if (p == 1) {		//���� �� ���� ���
			printf("score : %d\n", score);
			system("pause");
			break;
		}

		system("cls");
		for (int i = 1; i <= ROUND; i++) {
			printf("round %d   %d     %d strike %d ball\n", i, e[i - 1], strike[i - 1], bal[i - 1]);
		}
		//�ܼ�â�� ������ �ߵ��� ����

		/*
					���� ���� ���ǰ� ��Ʈ
			5�ڸ��� ��� ���߸� (��Ʈ����ũ 5���̸�) ����
			10���帶�� �ѹ��� ��Ʈ ����
			���ڸ��� ���� ���ڸ��� �˷���
			45������� �������� ���� ������ ���ϸ� ��������
		*/

		if (strike[ROUND - 1] == 5) {   //5�ڸ� ��� ���߾� ����, ����� ���� ���
			system("cls");
			printf("\n\n\n\n\n\n\n\t\t\tHOMERUN\n\n\n\n\n\n\n\n\t\tscore : %d", score);
			_sleep(5000);
			break;
		}
		if ((ROUND == 10 || ROUND == 20 || ROUND == 30 || ROUND == 40) && hint == 1) {
			//��Ʈ ���, ��Ʈ �������� ��Ʈ���� �ٲپ� ��Ʈ ��� �� �� �� ����
			printf("\n\t\thint : %d��° �ڸ����� %d�Դϴ�.", ROUND / 10, ball[(ROUND / 10) - 1]);
		}
		if (ROUND == 45) {
			//45������� ������� ����
			system("cls");
			printf("\n\n\n\n\t\t\t���� ����.... ����� �ٺ��ΰ���...");
			printf("\n\n\n\n\n\t\t\t\tscore: %d", score);
			_sleep(5000);
			break;
		}
	}
}