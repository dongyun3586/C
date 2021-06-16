#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int BettingProgram(int a);
int CheckBlackJack(int a, int b);
int CheckAce(int a);
int StartGame(int a, int b, int c, int d, int e);
int EvenMoney(int a, int d, int e);
int Split(int a, int b, int c, int d, int e);
int Surrender(int a);
int Insurance(int a, int b, int c, int d, int e);
int PlayGame(int a, int b, int c, int d, int e);
int Dealer(int a, int phap, int dhap);
int NotDoubleBet(int a, int e, int dhap, int phap, int j, int k);
int card[] = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
int main() {
	srand(time(NULL));
	int c1, c2;
	float point = 50;
	int d1, d2;
	int a;//베팅금액
	while (1) {
		system("cls");
		printf("\n** 블랙잭 ** \n");
		printf("$ 현재 당신의 포인트 $ = %.0f\n", point);//포인트가 0이 되면 패배, 100이 되면 승리
		Sleep(2000);
		a = BettingProgram(a);
		point = point + StartGame(a, c1, c2, d1, d2);
	}
}
int BettingProgram(int a) {                         //플레이어가 포인트를 베팅하는 함수
	system("cls");
	printf("얼마를 베팅하시겠습니까?\n");
	scanf("%d", &a);
	while (1) {
		int flg = 0;
		if (a % 2 != 0)
		{
			printf("베팅금액은 2의 배수여야 합니다.\n");
			printf("얼마를 베팅하시겠습니까?\n");
			scanf("%d", &a);
			return a;
		}
		else break;
	}
	while (1) {
		if (a >= 1 && a <= 10)
		{
			break;
		}
		else
		{
			printf("베팅금액은 2보다 크고 10보다 작아야 합니다.\n");
			printf("얼마를 베팅하시겠습니까?\n");
			scanf("%d", &a);
			return a;
		}
	}
}
int CheckBlackJack(int a, int b) {       //블랙잭인지 확인하는 함수
	if (a == 1 && b == 10)
		return 1;
	else if (a == 10 && b == 1)
		return 1;
	else return 0;
}

int CheckAce(int a) {                   //에이스가 있는지 확인하는 함수
	if (a == 1)
		return 1;
	else return 0;
}
int StartGame(int a, int b, int c, int d, int e) {
	int f;//플레이어의 대답 받는 변수
	b = card[rand() % 52];//플레이어 첫번째 카드
	c = card[rand() % 52];//플레이어 두번째 카드
	d = card[rand() % 52];//상대방 첫번째 카드
	e = card[rand() % 52];//상대방 두번째 카드
	if (CheckAce(b))
		printf("당신의 첫번째 카드는 에이스입니다.\n");
	else printf("당신의 첫번째 카드는 %d입니다.\n", b);
	if (CheckAce(c))
		printf("당신의 두번째 카드는 에이스입니다.\n");
	else printf("당신의 두번째 카드는 %d입니다.\n", c);
	if (CheckAce(d))
		printf("상대의 첫번째 카드는 에이스입니다.\n");
	else printf("상대의 첫번째 카드는 %d입니다.\n", d);
	if (CheckBlackJack(b, c))
	{
		if (CheckAce(d))//블랙잭인데 상대가 에이스 이므로 이븐 머니
			return EvenMoney(a, d, e);
		else {
			printf("블랙잭입니다. 베팅 금액의 1.5배를 받습니다.\n");
			Sleep(1000);
			return a * 3 / 2;
		}
	}
	else//블랙잭 아닐때
	{
		if (b == c)//카드 두장이 같을때
		{
			printf("스플릿 하시겠습니까?(예=1,아니요=0)");
			scanf("%d", &f);
			if (f)
			{
				return Split(a, b, c, d, e);
			}
		}
		else
		{
			printf("서렌더 하시겠습니까?(예=1,아니요=0)");
			scanf("%d", &f);
			if (f)
			{
				return Surrender(a);
			}
			else
			{
				if (CheckAce(d))
				{
					printf("인셔런스 하시겠습니까?(예=1,아니요=0)");
					scanf("%d", &f);
					if (f)
						return Insurance(a, b, c, d, e);
					else
					{
						if (e == 10)
						{
							printf("상대가 블랙잭 입니다. 베팅한 돈을 잃습니다.\n");
							Sleep(1000);
							return -a;
						}
						else
							return PlayGame(a, b, c, d, e);
					}
				}
				else
				{
					return PlayGame(a, b, c, d, e);
				}
			}
		}
	}
}
int Split(int a, int b, int c, int d, int e)
{
	int f, g, h;
	int i, j;
	printf("스플릿 하셨습니다.\n");
	f = card[rand() % 52];
	g = card[rand() % 52];
	printf("첫번째 덱은 %d,%d입니다.", b, f);
	if (CheckBlackJack(b, f))
	{
		if (CheckAce(d))//블랙잭인데 상대가 에이스 이므로 이븐 머니
			i = EvenMoney(a, d, e);
		else
		{
			printf("첫번째 덱이 블랙잭입니다. 베팅 금액의 1.5배를 받습니다.\n");
			Sleep(1000);
			i = a * 1.5;
		}
	}
	printf("두번째 덱은 %d,%d입니다.", c, g);
	if (CheckBlackJack(c, g))
	{
		if (CheckAce(d))
			i = EvenMoney(a, d, e);
		else
		{
			printf("두번째 덱이 블랙잭입니다. 베팅 금액의 1.5배를 받습니다.\n");
			Sleep(1000);
			j = a * 1.5;
		}
	}
	else
	{
		int phap1 = b + f;
		int phap2 = c + g;
		int dhap = d + e;
		int z;//대답받는 변수
		int g, h, i, j, k;
		printf("첫번째 덱을 더블벳 하시겠습니까?(예=1,아니요=0)");
		scanf("%d", &z);
		if (z)
		{
			g = card[rand() % 52];
			printf("당신의 세번째 카드는 %d입니다.\n", g);
			Sleep(1000);
			phap1 += g;
			if (phap1 > 21)
			{
				printf("합이 21이 넘었습니다. 베팅한 돈의 2배를 잃습니다.\n");
				Sleep(1000);
				i = -2 * a;
			}
			printf("두번째 덱을 더블벳 하시겠습니까?(예=1,아니요=0)");
			scanf("%d", &z);
			if (z)
			{
				h = card[rand() % 52];
				printf("당신의 세번째 카드는 %d입니다.\n", g);
				Sleep(1000);
				phap2 += h;
				if (phap2 > 21)
				{
					printf("합이 21이 넘었습니다. 베팅한 돈의 2배를 잃습니다.\n");
					Sleep(1000);
					i = -2 * a;
				}
				else
				{
					printf("상대의 차례입니다.\n");
					printf("상대의 두번째 카드는 %d였습니다.\n", e);
					printf("상대 카드의 합=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16) return 2 * (Dealer(a, phap1, dhap) + Dealer(a, phap2, dhap));
					else
					{
						j = card[rand() % 52];
						dhap += j;
						printf("상대의 세번째 카드는 %d입니다.\n", j);
						printf("상대카드의 합=%d\n", dhap);
						Sleep(1000);
						if (dhap > 16) return 2 * (Dealer(a, phap1, dhap) + Dealer(a, phap2, dhap));
						else
						{
							k = card[rand() % 52];
							dhap += k;
							printf("상대의 네번째 카드는 %d입니다.\n", k);
							printf("상대카드의 합=%d\n", dhap);
							Sleep(1000);
							if (dhap > 16) return 2 * (Dealer(a, phap1, dhap) + Dealer(a, phap2, dhap));
							else
							{
								printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
								Sleep(1000);
								i = 2 * a;
							}
						}
					}
				}
			}
			else
			{
				printf("힛 or 스탠드(힛=1,스탠드=0)");
				scanf("%d", &z);
				if (z)
				{
					g = card[rand() % 52];
					printf("당신의 세번째 카드는 %d입니다.\n", g);
					Sleep(1000);
					phap1 += g;
					if (phap1 > 21)
					{
						printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
						Sleep(1000);
						return -a;
					}
					else
					{
						printf("힛 or 스탠드(힛=1,스탠드=0)");
						scanf("%d", &z);
						if (z)
						{
							h = card[rand() % 52];
							printf("당신의 네번째 카드는 %d입니다.\n", h);
							Sleep(1000);
							phap1 += h;
							if (phap1 > 21)
							{
								printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
								Sleep(1000);
								return -a;
							}
							else
							{
								printf("힛 or 스탠드(힛=1,스탠드=0)");
								scanf("%d", &z);
								if (z)
								{
									i = card[rand() % 52];
									printf("당신의 다섯번째 카드는 %d입니다.\n", i);
									Sleep(1000);
									phap1 += i;
									if (phap1 > 21)
									{
										printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
										Sleep(1000);
										return -a;
									}
									else
									{
										printf("다섯번째 카드를 받았습니다.\n당신이 이겼습니다.\n베팅한 돈을 받습니다.");
										Sleep(1000);
										return a;
									}
								}
							}
						}
					}
					printf("첫번째 덱의 카드의 합=%d\n", phap1);
					Sleep(1000);
				}
				else
				{
					printf("두번째 덱\n");
					printf("힛 or 스탠드(힛=1,스탠드=0)");
					scanf("%d", &z);
					if (z)
					{
						g = card[rand() % 52];
						printf("당신의 세번째 카드는 %d입니다.\n", g);
						Sleep(1000);
						phap2 += g;
						if (phap2 > 21)
						{
							printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
							Sleep(1000);
							return -a;
						}
						else
						{
							printf("힛 or 스탠드(힛=1,스탠드=0)");
							scanf("%d", &z);
							if (z)
							{
								h = card[rand() % 52];
								printf("당신의 네번째 카드는 %d입니다.\n", h);
								Sleep(1000);
								phap2 += h;
								if (phap2 > 21)
								{
									printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
									Sleep(1000);
									return -a;
								}
								else
								{
									printf("힛 or 스탠드(힛=1,스탠드=0)");
									scanf("%d", &z);
									if (z)
									{
										i = card[rand() % 52];
										printf("당신의 다섯번째 카드는 %d입니다.\n", i);
										Sleep(1000);
										phap2 += i;
										if (phap2 > 21)
										{
											printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
											Sleep(1000);
											return -a;
										}
										else
										{
											printf("다섯번째 카드를 받았습니다.\n당신이 이겼습니다.\n베팅한 돈을 받습니다.");
											Sleep(1000);
											return a;
										}
									}
									else
									{
										printf("두번째 덱의 카드의 합=%d\n", phap2);
										printf("상대의 차례입니다.\n");
										printf("상대의 두번째 카드는 %d였습니다.\n", e);
										printf("상대 카드의 합=%d\n", dhap);
										if (dhap > 16)
										{
											i = Dealer(a, phap1, dhap);
											j = Dealer(a, phap2, dhap);
										}
										else
										{
											j = card[rand() % 52];
											dhap += j;
											printf("상대의 세번째 카드는 %d입니다.\n", j);
											printf("상대카드의 합=%d\n", dhap);
											if (dhap > 16)
											{
												i = Dealer(a, phap1, dhap);
												j = Dealer(a, phap2, dhap);
											}
											else
											{
												k = card[rand() % 52];
												dhap += k;
												printf("상대의 네번째 카드는 %d입니다.\n", k);
												printf("상대카드의 합=%d\n", dhap);
												Sleep(1000);
												if (dhap > 16)
												{
													i = Dealer(a, phap1, dhap);
													j = Dealer(a, phap2, dhap);
												}
												else
												{
													printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
													Sleep(1000);
													i = a;
												}
											}
										}
									}
								}
							}
							else
							{
								printf("두번째 덱의 카드의 합=%d\n", phap2);
								printf("상대의 차례입니다.\n");
								printf("상대의 두번째 카드는 %d였습니다.\n", e);
								printf("상대 카드의 합=%d\n", dhap);
								if (dhap > 16)
								{
									i = Dealer(a, phap1, dhap);
									j = Dealer(a, phap2, dhap);
								}
								else
								{
									j = card[rand() % 52];
									dhap += j;
									printf("상대의 세번째 카드는 %d입니다.\n", j);
									printf("상대카드의 합=%d\n", dhap);
									Sleep(1000);
									if (dhap > 16)
									{
										i = Dealer(a, phap1, dhap);
										j = Dealer(a, phap2, dhap);
									}
									else
									{
										k = card[rand() % 52];
										dhap += k;
										printf("상대의 네번째 카드는 %d입니다.\n", k);
										printf("상대카드의 합=%d\n", dhap);
										Sleep(1000);
										if (dhap > 16)
										{
											i = Dealer(a, phap1, dhap);
											j = Dealer(a, phap2, dhap);
										}
										else
										{
											printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
											Sleep(1000);
											i = a;
										}
									}
								}
							}
						}
					}
					else
					{
						printf("두번째 덱의 카드의 합=%d\n", phap2);
						printf("상대의 차례입니다.\n");
						printf("상대의 두번째 카드는 %d였습니다.\n", e);
						printf("상대 카드의 합=%d\n", dhap);
						if (dhap > 16)
						{
							i = Dealer(a, phap1, dhap);
							j = Dealer(a, phap2, dhap);
						}
						else
						{
							j = card[rand() % 52];
							dhap += j;
							printf("상대의 세번째 카드는 %d입니다.\n", j);
							printf("상대카드의 합=%d\n", dhap);
							Sleep(1000);
							if (dhap > 16)
							{
								i = Dealer(a, phap1, dhap);
								j = Dealer(a, phap2, dhap);
							}
							else
							{
								k = card[rand() % 52];
								dhap += k;
								printf("상대의 네번째 카드는 %d입니다.\n", k);
								printf("상대카드의 합=%d\n", dhap);
								Sleep(1000);
								if (dhap > 16)
								{
									i = Dealer(a, phap1, dhap);
									j = Dealer(a, phap2, dhap);
								}
								else
								{
									printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
									Sleep(1000);
									i = a;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			printf("두번째 덱의 카드의 합=%d\n", phap2);
			printf("상대의 차례입니다.\n");
			printf("상대의 두번째 카드는 %d였습니다.\n", e);
			printf("상대 카드의 합=%d\n", dhap);
			if (dhap > 16)
			{
				i = Dealer(a, phap1, dhap);
				j = Dealer(a, phap2, dhap);
			}
			else
			{
				j = card[rand() % 52];
				dhap += j;
				printf("상대의 세번째 카드는 %d입니다.\n", j);
				printf("상대카드의 합=%d\n", dhap);
				Sleep(1000);
				if (dhap > 16)
				{
					i = Dealer(a, phap1, dhap);
					j = Dealer(a, phap2, dhap);
				}
				else
				{
					k = card[rand() % 52];
					dhap += k;
					printf("상대의 네번째 카드는 %d입니다.\n", k);
					printf("상대카드의 합=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16)
					{
						i = Dealer(a, phap1, dhap);
						j = Dealer(a, phap2, dhap);
					}
					else
					{
						printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
						Sleep(1000);
						i = a;
					}
				}
			}
		}
	}
	return i + j;
}
int EvenMoney(int a, int d, int e)
{
	int b;
	printf("이븐 머니 하시겠습니까?(예=1,아니요=0)");
	scanf("%d", &b);
	if (b)
		if (CheckBlackJack(d, e))
		{
			Sleep(1000);
			return 0;
		}
		else
		{
			Sleep(1000);
			return a * 1.5;
		}
	else
	{
		Sleep(1000);
		return a;
	}
}
int Surrender(int a)
{
	Sleep(1000);
	return -a / 2;
}
int Insurance(int a, int b, int c, int d, int e)
{
	if (CheckBlackJack(d, e))
	{
		Sleep(1000);
		return 0;
	}
	else
	{
		Sleep(1000);
		return PlayGame(a, b, c, d, e) - a / 2;
	}
}
int PlayGame(int a, int b, int c, int d, int e)
{
	int phap = b + c;
	int dhap = d + e;
	int f;//대답받는 변수
	int g, h, i, j, k;
	printf("더블벳 하시겠습니까?(예=1,아니요=0)");
	scanf("%d", &f);
	if (f)
	{
		g = card[rand() % 52];
		printf("당신의 세번째 카드는 %d입니다.\n", g);
		Sleep(1000);
		phap += g;
		if (phap > 21)
		{
			printf("합이 21이 넘었습니다. 베팅한 돈의 2배를 잃습니다.\n");
			Sleep(1000);
			return -2 * a;
		}
		else
		{
			printf("상대의 차례입니다.\n");
			printf("상대의 두번째 카드는 %d였습니다.\n", e);
			printf("상대 카드의 합=%d\n", dhap);
			Sleep(1000);
			if (dhap > 16) return 2 * Dealer(a, phap, dhap);
			else
			{
				j = card[rand() % 52];
				dhap += j;
				printf("상대의 세번째 카드는 %d입니다.\n", j);
				printf("상대카드의 합=%d\n", dhap);
				Sleep(1000);
				if (dhap > 16) return 2 * Dealer(a, phap, dhap);
				else
				{
					k = card[rand() % 52];
					dhap += k;
					printf("상대의 네번째 카드는 %d입니다.\n", k);
					printf("상대카드의 합=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16) return 2 * Dealer(a, phap, dhap);
					else
					{
						printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
						Sleep(1000);
						return 2 * a;
					}
				}
			}
		}
	}
	else
	{
		printf("힛 or 스탠드(힛=1,스탠드=0)");
		scanf("%d", &f);
		if (f)
		{
			g = card[rand() % 52];
			printf("당신의 세번째 카드는 %d입니다.\n", g);
			phap += g;
			Sleep(1000);
			if (phap > 21)
			{
				printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
				Sleep(1000);
				return -a;
			}
			else
			{
				printf("힛 or 스탠드(힛=1,스탠드=0)");
				scanf("%d", &f);
				if (f)
				{
					h = card[rand() % 52];
					printf("당신의 네번째 카드는 %d입니다.\n", h);
					Sleep(1000);
					phap += h;
					if (phap > 21)
					{
						printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
						Sleep(1000);
						return -a;
					}
					else
					{
						printf("힛 or 스탠드(힛=1,스탠드=0)");
						scanf("%d", &f);
						if (f)
						{
							i = card[rand() % 52];
							printf("당신의 다섯번째 카드는 %d입니다.\n", i);
							Sleep(1000);
							phap += i;
							if (phap > 21)
							{
								printf("합이 21이 넘었습니다. 베팅한 돈을 잃습니다.\n");
								Sleep(1000);
								return -a;
							}
							else
							{
								printf("다섯번째 카드를 받았습니다.\n당신이 이겼습니다.\n베팅한 돈을 받습니다.");
								Sleep(1000);
								return a;
							}
						}
						else
						{
							printf("상대의 차례입니다.\n");
							printf("상대의 두번째 카드는 %d였습니다.\n", e);
							printf("상대 카드의 합=%d\n", dhap);
							Sleep(1000);
							if (dhap > 16) return Dealer(a, phap, dhap);
							else
							{
								return NotDoubleBet(a, e, dhap, phap, j, k);
							}
						}
					}
				}
				else
				{
					printf("상대의 차례입니다.\n");
					printf("상대의 두번째 카드는 %d였습니다.\n", e);
					printf("상대 카드의 합=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16) return Dealer(a, phap, dhap);
					else
					{
						return NotDoubleBet(a, e, dhap, phap, j, k);
					}
				}
			}
		}
		else
		{
			printf("상대의 차례입니다.\n");
			printf("상대의 두번째 카드는 %d였습니다.\n", e);
			printf("상대 카드의 합=%d\n", dhap);
			Sleep(1000);
			if (dhap > 16) return Dealer(a, phap, dhap);
			else
			{
				return NotDoubleBet(a, e, dhap, phap, j, k);
			}
		}
	}
}
int Dealer(int a, int phap, int dhap)
{
	if (dhap > 21)
	{
		printf("상대가 21보다 큽니다. 이겼습니다.\n");
		return a;
	}
	else if (phap > dhap)
	{
		printf("이겼습니다. 베팅한 돈을 얻습니다.\n");
		Sleep(1000);
		return a;
	}
	else if (phap == dhap)
	{
		printf("비겼습니다.\n");
		Sleep(1000);
		return 0;
	}
	else
	{
		printf("졌습니다. 베팅한 돈을 잃습니다.\n");
		Sleep(1000);
		return -a;
	}
}
int NotDoubleBet(int a, int e, int dhap, int phap, int j, int k)
{
	printf("상대의 차례입니다.\n");
	printf("상대의 두번째 카드는 %d였습니다.\n", e);
	printf("상대 카드의 합=%d\n", dhap);
	Sleep(1000);
	if (dhap > 16) return Dealer(a, phap, dhap);
	else
	{
		j = card[rand() % 52];
		dhap += j;
		printf("상대의 세번째 카드는 %d입니다.\n", j);
		printf("상대카드의 합=%d\n", dhap);
		Sleep(1000);
		if (dhap > 16) return Dealer(a, phap, dhap);
		else
		{
			k = card[rand() % 52];
			dhap += k;
			printf("상대의 네번째 카드는 %d입니다.\n", k);
			printf("상대카드의 합=%d\n", dhap);
			Sleep(1000);
			if (dhap > 16) return Dealer(a, phap, dhap);
			else
			{
				printf("상대가 5번째 카드를 뽑아야 합니다.\n당신이 이겼습니다.");
				return a;
			}
		}
	}
}
