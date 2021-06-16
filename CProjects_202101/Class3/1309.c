#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Betgame(int arr[], int item[], int r, int bet);
int Itemeffect(int item, int q);

int main() {
	int money = 10000;
	int Stat[5];
	int ItemPrice[5] = { 5000,5000, 5000, 5000, 10000 };
	int ItemQuantity[5];
	int ItemEffect[5] = { 0,0,0,0,0 };
	int AnswerArr[20];
	srand(time(NULL));
	while (money > 0 && money < 100000) {
		int input = 0;
		int bet = 0;
		int ratio = 0;
		int k = 0;
		printf("\n\n���� ���ӿ� ���� ������, ȯ���մϴ�!\n ���� ���� ���̳ʽ��� �ǰų�, 10������ ä��� ������ ����˴ϴ�.\n�������� ���÷��� 1, �������� ���÷��� 2�� �����ּ���!\nȤ�� ���� �� �ް� �����Ű���? �׷��ٸ� 3�� �����ּ���!");
		scanf("%d", &input);
		if (input == 1) {
			printf("\n ���� ���� ���� %d���Դϴ�.\n\n���Ͻô� ��ǰ ��ȣ�� ���� �ݾ��� ����� �Բ� �����ּ���.\n1:�ִ� 200%% ����, �ִ� 200%% �̵�\n2:�ִ� 150%% ����, �ִ� 150%% �̵�\n3:�ִ� 100%% ����, �ִ� 100%% �̵�\n4:�ִ� 50%% ����, �ִ� 50%% �̵�\n\n", money);
			scanf("%d %d", &input, &bet);
			if (input > 0 && input < 5) {
				ratio = 250 - 50 * input;
				k = Betgame(Stat, ItemEffect, ratio, bet);
				money = money + k;
			}
			else {
				printf("\n�Ǹ��Դϴ�. ������ �峭���� ���ϽôٴϿ�. ����� ��� ���� �������� �����ϰ� ������ ���������մϴ�. ��2~");
				return (0);
			}
		}
		else if (input == 2) {
			int quantity = 0;
			int itemInput = 0;
			printf("\n������ ���� ���� ȯ���մϴ�!\n������ ����ְ� ���ִ� ������ ��õ�� ������ ȯ���Դϴ�!\n������ ���� ������ �� �����ϰ� ���� �������� ��ȣ�� ������ ����� �Բ� �����ּ���.\n\n");
			printf("1:���� ���� Ȯ���� 5%% �����ִ� ������. �ϳ��� %d��.\n2:���� ���� Ȯ���� 5%% �����ִ� ������. �ϳ��� %d��.\n3:���� ���� Ȯ���� -5%%~15%% �����ִ� ������. �ϳ��� %d��.\n4:���� ���� Ȯ���� -5%%~15%% �����ִ� ������. �ϳ��� %d��.\n5:5�� ������ ��� ��ǰ�� ������ 1000�� �����ִ� ������. �ϳ��� %d��.\n\n���� ���� ��:%d��\n\n", ItemPrice[0], ItemPrice[1], ItemPrice[2], ItemPrice[3], ItemPrice[4], money);
			scanf("%d %d", &itemInput, &quantity);
			if (itemInput < 6 && itemInput>0) {
				int temp = 0;
				money = money - quantity * ItemPrice[itemInput - 1];
				ItemQuantity[itemInput - 1] += quantity;
				temp = Itemeffect(itemInput, quantity);
				ItemEffect[itemInput - 1] += temp;
				if (itemInput == 5) {
					for (int i = 0; i < 4; i++) {
						ItemPrice[i] = ItemPrice[i] - temp;
					}
				}
			}
			else {
				printf("�Ǹ��Դϴ�. ������ �峭���� ���ϽôٴϿ�. ����� ��� ���� �������� �����ϰ� ������ ���������մϴ�. ��2~");
				return (0);
			}
		}
		else if (input == 3) {
			int k = 0;
			k = rand() % 2 + 1;
			switch (k) {
			case 1:
				int count = 0;
				for (int i = 0; i < 20; i++) {
					AnswerArr[i] = rand() % 5 + 1;
				}
				printf("\n���� ��� ���� �̴ϰ���, ��� ���ӿ� ���� ���� ȯ���մϴ�!\n�� ������ ��ǻ�Ͱ� �̸� ���ص� 1���� 5������ ���ڸ� �� ���ߴ� �����Դϴ�!\n �� 20ȸ ����ǰ�, ����� ���� ������ ���� ����մϴ�!\n\n");
				for (int i = 0; i < 20; i++) {
					int ans = 0;
					printf("%d��° ���� �����ϱ��?(1~5�� �ڿ����Դϴ�)", i + 1);
					scanf("%d", &ans);
					if (ans == AnswerArr[i]) {
						printf("�����Դϴ�!\n");
						count += 1;
					}
					else
						printf("Ʋ�Ƚ��ϴ�. ��:%d\n", AnswerArr[i]);
					printf("���� ����:%d\n\n", count);
				}
				printf("%d���� �����̱���! �����Ͻ� ��ſ��� %d���� �帮�ڽ��ϴ�!", count, 500 * count);
				money += 500 * count;
				break;
			case 2:
				int myNumber, computerNumber, a, b, c;
				float d;
				a = 0;
				b = 0;
				c = 0;
				d = 0;
				printf("\n���������� ���ӿ� ���� ���� ȯ���մϴ�!\n\n20�� ����Ǵ� �������������� �󸶸� ������� �� �ֳ���?\n\n");
				while (a + b + c < 20) {
					printf("1(����),2(����),3(��) �� �ϳ��� �Է��ϼ���: ");
					scanf("%d", &myNumber);
					srand(time(NULL));
					computerNumber = rand() % 3 + 1;
					printf("\n");
					if (myNumber == 3 || myNumber == 1 || myNumber == 2) {
						if (myNumber == computerNumber) {
							printf("�����ϴ�.\n");
							b = b + 1;//���º� ī��Ʈ
						}
						else if (myNumber - computerNumber == 1 || myNumber - computerNumber == -2) {
							printf("�̰���ϴ�!\n");
							a = a + 1;//�¸� ī��Ʈ
						}
						else if (myNumber - computerNumber == -1 || myNumber - computerNumber == 2) {
							printf("�����ϴ�\n");
							c = c + 1;//�й� ī��Ʈ
						}
						else {
							printf("����� �������� ���߽��ϴ�. 0,1,2�� ��Ȯ�� �Է��ߴ��� Ȯ�����ּ���.\n");
						}
					}
					else {
						printf("����� �������� ���߽��ϴ�. 0,1,2�� ��Ȯ�� �Է��ߴ��� Ȯ�����ּ���.\n");
					}
					d = a * 100 / (a + b + c);
					printf("���� ����:%d�� %d�� %d��\n���� �·�:%.06f %%\n\n", a, b, c, d);
				}
				printf("�����մϴ�! %d���� �ϼ̱���! ������� %f���� �帮�ڽ��ϴ�!", a, pow(2, a) * 10);
				money += pow(2, a) * 10;
				break;
			}

		}
		else {
			printf("�Ǹ��Դϴ�. ������ �峭���� ���ϽôٴϿ�. ����� ��� ���� �������� �����ϰ� ������ ���������մϴ�. ��2~");
			return (0);
		}
	}
	if (money <= 0) {
		int merong = 0;
		while (merong < 100) {
			printf("����� �Ļ��ϼ̽��ϴ�....�������������� �װ� �׳Ĥ�������\n");
			merong++;
		}
	}
	else if (money >= 100000) {
		int wow = 0;
		while (wow < 100) {
			printf("�̰� �̱��.... ����\n");
			wow++;
		}
	}
}
int Betgame(int arr[], int item[], int r, int bet)
{
	float win = 0;
	win = bet * ((item[0] + item[1] + item[2] + item[3] + r) - (rand() % (2 * r + item[0] - item[1] + item[2] - item[3]))) / 100;
	if (win >= 0) {
		printf("\n���ϵ帳�ϴ�! %f���� �����̾��!(�Ҽ��� �̸��� �������ϴ�.)\n", win);
	}
	else if (win < 0) {
		printf("\n����... %f���� �����̾��...\n", -1 * win);
	}
	return(win);
}
int Itemeffect(int item, int q) {
	switch (item) {
		int temp = 0;
		int sum = 0;
	case (1):
		temp = 5 * q;
		printf("�̵� Ȯ���� %d�ۼ�Ʈ �����Ͽ����ϴ�.", temp);
		return(temp);
		break;
	case (2):
		temp = 5 * q;
		printf("���� Ȯ���� %d�ۼ�Ʈ �����Ͽ����ϴ�.", temp);
		return(temp);
		break;
	case (3): {
		int temp1 = 0;
		int sum1 = 0;
		for (int i = 0; i < q; i++) {
			temp1 = 15 - (rand() % 20 + 1);
			sum1 += temp1;
		}
		printf("�̵� Ȯ���� %d�ۼ�Ʈ �����Ͽ����ϴ�.", sum1);
		return(sum1);
		break;
	}
	case (4): {
		int sum2 = 0;
		int temp2 = 0;
		for (int i = 0; i < q; i++) {
			temp2 = 15 - (rand() % 20 + 1);
			sum2 += temp2;
		}
		printf("���� Ȯ���� %d�ۼ�Ʈ �����Ͽ����ϴ�.", sum2);
		return(sum2);
		break;
	}
	case (5):
		temp = 1000 * q;
		return(temp);
		break;
	}
}




