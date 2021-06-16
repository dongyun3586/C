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
		printf("\n\n베팅 게임에 오신 여러분, 환영합니다!\n 가진 돈이 마이너스가 되거나, 10만원을 채우면 게임이 종료됩니다.\n게임으로 가시려면 1, 상점으로 가시려면 2를 눌러주세요!\n혹시 돈을 더 받고 싶으신가요? 그렇다면 3을 눌러주세요!");
		scanf("%d", &input);
		if (input == 1) {
			printf("\n 현재 가진 돈은 %d원입니다.\n\n원하시는 상품 번호와 베팅 금액을 띄어쓰기와 함께 적어주세요.\n1:최대 200%% 손해, 최대 200%% 이득\n2:최대 150%% 손해, 최대 150%% 이득\n3:최대 100%% 손해, 최대 100%% 이득\n4:최대 50%% 손해, 최대 50%% 이득\n\n", money);
			scanf("%d %d", &input, &bet);
			if (input > 0 && input < 5) {
				ratio = 250 - 50 * input;
				k = Betgame(Stat, ItemEffect, ratio, bet);
				money = money + k;
			}
			else {
				printf("\n실망입니다. 게임을 장난으로 임하시다니요. 당신의 모든 돈과 아이템을 삭제하고 게임을 강제종료합니다. ㅃ2~");
				return (0);
			}
		}
		else if (input == 2) {
			int quantity = 0;
			int itemInput = 0;
			printf("\n상점에 오신 것을 환영합니다!\n게임을 재미있게 해주는 아이템 추천은 언제나 환영입니다!\n다음과 같은 아이템 중 구매하고 싶은 아이템을 번호와 수량을 띄어쓰기와 함께 적어주세요.\n\n");
			printf("1:돈을 얻을 확률을 5%% 높여주는 아이템. 하나에 %d원.\n2:돈을 잃을 확률을 5%% 낮춰주는 아이템. 하나에 %d원.\n3:돈을 얻을 확률을 -5%%~15%% 높여주는 아이템. 하나에 %d원.\n4:돈을 잃을 확률을 -5%%~15%% 낮춰주는 아이템. 하나에 %d원.\n5:5를 제외한 모든 상품의 가격을 1000원 낮춰주는 아이템. 하나에 %d원.\n\n현재 가진 돈:%d원\n\n", ItemPrice[0], ItemPrice[1], ItemPrice[2], ItemPrice[3], ItemPrice[4], money);
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
				printf("실망입니다. 게임을 장난으로 임하시다니요. 당신의 모든 돈과 아이템을 삭제하고 게임을 강제종료합니다. ㅃ2~");
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
				printf("\n돈을 얻기 위한 미니게임, 찍신 게임에 오신 것을 환영합니다!\n이 게임은 컴퓨터가 미리 정해둔 1부터 5까지의 숫자를 찍어서 맞추는 게임입니다!\n 총 20회 진행되고, 상금은 맞춘 숫자의 수에 비례합니다!\n\n");
				for (int i = 0; i < 20; i++) {
					int ans = 0;
					printf("%d번째 수는 무엇일까요?(1~5의 자연수입니다)", i + 1);
					scanf("%d", &ans);
					if (ans == AnswerArr[i]) {
						printf("정답입니다!\n");
						count += 1;
					}
					else
						printf("틀렸습니다. 답:%d\n", AnswerArr[i]);
					printf("현재 점수:%d\n\n", count);
				}
				printf("%d점을 얻으셨군요! 수고하신 당신에게 %d원을 드리겠습니다!", count, 500 * count);
				money += 500 * count;
				break;
			case 2:
				int myNumber, computerNumber, a, b, c;
				float d;
				a = 0;
				b = 0;
				c = 0;
				d = 0;
				printf("\n가위바위보 게임에 오신 것을 환영합니다!\n\n20번 진행되는 가위바위보에서 얼마를 벌어나가실 수 있나요?\n\n");
				while (a + b + c < 20) {
					printf("1(가위),2(바위),3(보) 중 하나를 입력하세요: ");
					scanf("%d", &myNumber);
					srand(time(NULL));
					computerNumber = rand() % 3 + 1;
					printf("\n");
					if (myNumber == 3 || myNumber == 1 || myNumber == 2) {
						if (myNumber == computerNumber) {
							printf("비겼습니다.\n");
							b = b + 1;//무승부 카운트
						}
						else if (myNumber - computerNumber == 1 || myNumber - computerNumber == -2) {
							printf("이겼습니다!\n");
							a = a + 1;//승리 카운트
						}
						else if (myNumber - computerNumber == -1 || myNumber - computerNumber == 2) {
							printf("졌습니다\n");
							c = c + 1;//패배 카운트
						}
						else {
							printf("결과를 수집하지 못했습니다. 0,1,2를 정확히 입력했는지 확인해주세요.\n");
						}
					}
					else {
						printf("결과를 수집하지 못했습니다. 0,1,2를 정확히 입력했는지 확인해주세요.\n");
					}
					d = a * 100 / (a + b + c);
					printf("현재 전적:%d승 %d무 %d패\n현재 승률:%.06f %%\n\n", a, b, c, d);
				}
				printf("축하합니다! %d승을 하셨군요! 상금으로 %f원을 드리겠습니다!", a, pow(2, a) * 10);
				money += pow(2, a) * 10;
				break;
			}

		}
		else {
			printf("실망입니다. 게임을 장난으로 임하시다니요. 당신의 모든 돈과 아이템을 삭제하고 게임을 강제종료합니다. ㅃ2~");
			return (0);
		}
	}
	if (money <= 0) {
		int merong = 0;
		while (merong < 100) {
			printf("당신은 파산하셨습니다....ㅋㅋㅋㅋㅋㅋㅋ 그걸 죽냐ㅋㅋㅋㅋ\n");
			merong++;
		}
	}
	else if (money >= 100000) {
		int wow = 0;
		while (wow < 100) {
			printf("이걸 이기네.... ㅊㅋ\n");
			wow++;
		}
	}
}
int Betgame(int arr[], int item[], int r, int bet)
{
	float win = 0;
	win = bet * ((item[0] + item[1] + item[2] + item[3] + r) - (rand() % (2 * r + item[0] - item[1] + item[2] - item[3]))) / 100;
	if (win >= 0) {
		printf("\n축하드립니다! %f원을 얻으셨어요!(소숫점 미만은 버려집니다.)\n", win);
	}
	else if (win < 0) {
		printf("\n저런... %f원을 잃으셨어요...\n", -1 * win);
	}
	return(win);
}
int Itemeffect(int item, int q) {
	switch (item) {
		int temp = 0;
		int sum = 0;
	case (1):
		temp = 5 * q;
		printf("이득 확률이 %d퍼센트 증가하였습니다.", temp);
		return(temp);
		break;
	case (2):
		temp = 5 * q;
		printf("손해 확률이 %d퍼센트 감소하였습니다.", temp);
		return(temp);
		break;
	case (3): {
		int temp1 = 0;
		int sum1 = 0;
		for (int i = 0; i < q; i++) {
			temp1 = 15 - (rand() % 20 + 1);
			sum1 += temp1;
		}
		printf("이득 확률이 %d퍼센트 증가하였습니다.", sum1);
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
		printf("손해 확률이 %d퍼센트 감소하였습니다.", sum2);
		return(sum2);
		break;
	}
	case (5):
		temp = 1000 * q;
		return(temp);
		break;
	}
}




