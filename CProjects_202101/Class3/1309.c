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
		printf("\n\n今特 惟績拭 神重 食君歳, 発慎杯艦陥!\n 亜遭 儀戚 原戚格什亜 鞠暗蟹, 10幻据聖 辰酔檎 惟績戚 曽戟桔艦陥.\n惟績生稽 亜獣形檎 1, 雌繊生稽 亜獣形檎 2研 喚君爽室推!\n箸獣 儀聖 希 閤壱 粛生重亜推? 益係陥檎 3聖 喚君爽室推!");
		scanf("%d", &input);
		if (input == 1) {
			printf("\n 薄仙 亜遭 儀精 %d据脊艦陥.\n\n据馬獣澗 雌念 腰硲人 今特 榎衝聖 句嬢床奄人 敗臆 旋嬢爽室推.\n1:置企 200%% 謝背, 置企 200%% 戚究\n2:置企 150%% 謝背, 置企 150%% 戚究\n3:置企 100%% 謝背, 置企 100%% 戚究\n4:置企 50%% 謝背, 置企 50%% 戚究\n\n", money);
			scanf("%d %d", &input, &bet);
			if (input > 0 && input < 5) {
				ratio = 250 - 50 * input;
				k = Betgame(Stat, ItemEffect, ratio, bet);
				money = money + k;
			}
			else {
				printf("\n叔諺脊艦陥. 惟績聖 舌貝生稽 績馬獣陥艦推. 雁重税 乞窮 儀引 焼戚奴聖 肢薦馬壱 惟績聖 悪薦曽戟杯艦陥. こ2~");
				return (0);
			}
		}
		else if (input == 2) {
			int quantity = 0;
			int itemInput = 0;
			printf("\n雌繊拭 神重 依聖 発慎杯艦陥!\n惟績聖 仙耕赤惟 背爽澗 焼戚奴 蓄探精 情薦蟹 発慎脊艦陥!\n陥製引 旭精 焼戚奴 掻 姥古馬壱 粛精 焼戚奴聖 腰硲人 呪勲聖 句嬢床奄人 敗臆 旋嬢爽室推.\n\n");
			printf("1:儀聖 条聖 溌懸聖 5%% 株食爽澗 焼戚奴. 馬蟹拭 %d据.\n2:儀聖 籍聖 溌懸聖 5%% 碍仲爽澗 焼戚奴. 馬蟹拭 %d据.\n3:儀聖 条聖 溌懸聖 -5%%~15%% 株食爽澗 焼戚奴. 馬蟹拭 %d据.\n4:儀聖 籍聖 溌懸聖 -5%%~15%% 碍仲爽澗 焼戚奴. 馬蟹拭 %d据.\n5:5研 薦須廃 乞窮 雌念税 亜維聖 1000据 碍仲爽澗 焼戚奴. 馬蟹拭 %d据.\n\n薄仙 亜遭 儀:%d据\n\n", ItemPrice[0], ItemPrice[1], ItemPrice[2], ItemPrice[3], ItemPrice[4], money);
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
				printf("叔諺脊艦陥. 惟績聖 舌貝生稽 績馬獣陥艦推. 雁重税 乞窮 儀引 焼戚奴聖 肢薦馬壱 惟績聖 悪薦曽戟杯艦陥. こ2~");
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
				printf("\n儀聖 条奄 是廃 耕艦惟績, 啄重 惟績拭 神重 依聖 発慎杯艦陥!\n戚 惟績精 陳濃斗亜 耕軒 舛背黍 1採斗 5猿走税 収切研 啄嬢辞 限蓄澗 惟績脊艦陥!\n 恥 20噺 遭楳鞠壱, 雌榎精 限秩 収切税 呪拭 搾景杯艦陥!\n\n");
				for (int i = 0; i < 20; i++) {
					int ans = 0;
					printf("%d腰属 呪澗 巷譲析猿推?(1~5税 切尻呪脊艦陥)", i + 1);
					scanf("%d", &ans);
					if (ans == AnswerArr[i]) {
						printf("舛岩脊艦陥!\n");
						count += 1;
					}
					else
						printf("堂携柔艦陥. 岩:%d\n", AnswerArr[i]);
					printf("薄仙 繊呪:%d\n\n", count);
				}
				printf("%d繊聖 条生写浦推! 呪壱馬重 雁重拭惟 %d据聖 球軒畏柔艦陥!", count, 500 * count);
				money += 500 * count;
				break;
			case 2:
				int myNumber, computerNumber, a, b, c;
				float d;
				a = 0;
				b = 0;
				c = 0;
				d = 0;
				printf("\n亜是郊是左 惟績拭 神重 依聖 発慎杯艦陥!\n\n20腰 遭楳鞠澗 亜是郊是左拭辞 杖原研 忽嬢蟹亜叔 呪 赤蟹推?\n\n");
				while (a + b + c < 20) {
					printf("1(亜是),2(郊是),3(左) 掻 馬蟹研 脊径馬室推: ");
					scanf("%d", &myNumber);
					srand(time(NULL));
					computerNumber = rand() % 3 + 1;
					printf("\n");
					if (myNumber == 3 || myNumber == 1 || myNumber == 2) {
						if (myNumber == computerNumber) {
							printf("搾医柔艦陥.\n");
							b = b + 1;//巷渋採 朝錘闘
						}
						else if (myNumber - computerNumber == 1 || myNumber - computerNumber == -2) {
							printf("戚医柔艦陥!\n");
							a = a + 1;//渋軒 朝錘闘
						}
						else if (myNumber - computerNumber == -1 || myNumber - computerNumber == 2) {
							printf("然柔艦陥\n");
							c = c + 1;//鳶壕 朝錘闘
						}
						else {
							printf("衣引研 呪増馬走 公梅柔艦陥. 0,1,2研 舛溌備 脊径梅澗走 溌昔背爽室推.\n");
						}
					}
					else {
						printf("衣引研 呪増馬走 公梅柔艦陥. 0,1,2研 舛溌備 脊径梅澗走 溌昔背爽室推.\n");
					}
					d = a * 100 / (a + b + c);
					printf("薄仙 穿旋:%d渋 %d巷 %d鳶\n薄仙 渋懸:%.06f %%\n\n", a, b, c, d);
				}
				printf("逐馬杯艦陥! %d渋聖 馬写浦推! 雌榎生稽 %f据聖 球軒畏柔艦陥!", a, pow(2, a) * 10);
				money += pow(2, a) * 10;
				break;
			}

		}
		else {
			printf("叔諺脊艦陥. 惟績聖 舌貝生稽 績馬獣陥艦推. 雁重税 乞窮 儀引 焼戚奴聖 肢薦馬壱 惟績聖 悪薦曽戟杯艦陥. こ2~");
			return (0);
		}
	}
	if (money <= 0) {
		int merong = 0;
		while (merong < 100) {
			printf("雁重精 督至馬写柔艦陥....せせせせせせせ 益杏 宋劃せせせせ\n");
			merong++;
		}
	}
	else if (money >= 100000) {
		int wow = 0;
		while (wow < 100) {
			printf("戚杏 戚奄革.... ずせ\n");
			wow++;
		}
	}
}
int Betgame(int arr[], int item[], int r, int bet)
{
	float win = 0;
	win = bet * ((item[0] + item[1] + item[2] + item[3] + r) - (rand() % (2 * r + item[0] - item[1] + item[2] - item[3]))) / 100;
	if (win >= 0) {
		printf("\n逐馬球験艦陥! %f据聖 条生写嬢推!(社収繊 耕幻精 獄形増艦陥.)\n", win);
	}
	else if (win < 0) {
		printf("\n煽訓... %f据聖 籍生写嬢推...\n", -1 * win);
	}
	return(win);
}
int Itemeffect(int item, int q) {
	switch (item) {
		int temp = 0;
		int sum = 0;
	case (1):
		temp = 5 * q;
		printf("戚究 溌懸戚 %d遁湿闘 装亜馬心柔艦陥.", temp);
		return(temp);
		break;
	case (2):
		temp = 5 * q;
		printf("謝背 溌懸戚 %d遁湿闘 姶社馬心柔艦陥.", temp);
		return(temp);
		break;
	case (3): {
		int temp1 = 0;
		int sum1 = 0;
		for (int i = 0; i < q; i++) {
			temp1 = 15 - (rand() % 20 + 1);
			sum1 += temp1;
		}
		printf("戚究 溌懸戚 %d遁湿闘 装亜馬心柔艦陥.", sum1);
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
		printf("謝背 溌懸戚 %d遁湿闘 姶社馬心柔艦陥.", sum2);
		return(sum2);
		break;
	}
	case (5):
		temp = 1000 * q;
		return(temp);
		break;
	}
}




