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
	int a;//���ñݾ�
	while (1) {
		system("cls");
		printf("\n** ���� ** \n");
		printf("$ ���� ����� ����Ʈ $ = %.0f\n", point);//����Ʈ�� 0�� �Ǹ� �й�, 100�� �Ǹ� �¸�
		Sleep(2000);
		a = BettingProgram(a);
		point = point + StartGame(a, c1, c2, d1, d2);
	}
}
int BettingProgram(int a) {                         //�÷��̾ ����Ʈ�� �����ϴ� �Լ�
	system("cls");
	printf("�󸶸� �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &a);
	while (1) {
		int flg = 0;
		if (a % 2 != 0)
		{
			printf("���ñݾ��� 2�� ������� �մϴ�.\n");
			printf("�󸶸� �����Ͻðڽ��ϱ�?\n");
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
			printf("���ñݾ��� 2���� ũ�� 10���� �۾ƾ� �մϴ�.\n");
			printf("�󸶸� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &a);
			return a;
		}
	}
}
int CheckBlackJack(int a, int b) {       //�������� Ȯ���ϴ� �Լ�
	if (a == 1 && b == 10)
		return 1;
	else if (a == 10 && b == 1)
		return 1;
	else return 0;
}

int CheckAce(int a) {                   //���̽��� �ִ��� Ȯ���ϴ� �Լ�
	if (a == 1)
		return 1;
	else return 0;
}
int StartGame(int a, int b, int c, int d, int e) {
	int f;//�÷��̾��� ��� �޴� ����
	b = card[rand() % 52];//�÷��̾� ù��° ī��
	c = card[rand() % 52];//�÷��̾� �ι�° ī��
	d = card[rand() % 52];//���� ù��° ī��
	e = card[rand() % 52];//���� �ι�° ī��
	if (CheckAce(b))
		printf("����� ù��° ī��� ���̽��Դϴ�.\n");
	else printf("����� ù��° ī��� %d�Դϴ�.\n", b);
	if (CheckAce(c))
		printf("����� �ι�° ī��� ���̽��Դϴ�.\n");
	else printf("����� �ι�° ī��� %d�Դϴ�.\n", c);
	if (CheckAce(d))
		printf("����� ù��° ī��� ���̽��Դϴ�.\n");
	else printf("����� ù��° ī��� %d�Դϴ�.\n", d);
	if (CheckBlackJack(b, c))
	{
		if (CheckAce(d))//�����ε� ��밡 ���̽� �̹Ƿ� �̺� �Ӵ�
			return EvenMoney(a, d, e);
		else {
			printf("�����Դϴ�. ���� �ݾ��� 1.5�踦 �޽��ϴ�.\n");
			Sleep(1000);
			return a * 3 / 2;
		}
	}
	else//���� �ƴҶ�
	{
		if (b == c)//ī�� ������ ������
		{
			printf("���ø� �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
			scanf("%d", &f);
			if (f)
			{
				return Split(a, b, c, d, e);
			}
		}
		else
		{
			printf("������ �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
			scanf("%d", &f);
			if (f)
			{
				return Surrender(a);
			}
			else
			{
				if (CheckAce(d))
				{
					printf("�μŷ��� �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
					scanf("%d", &f);
					if (f)
						return Insurance(a, b, c, d, e);
					else
					{
						if (e == 10)
						{
							printf("��밡 ���� �Դϴ�. ������ ���� �ҽ��ϴ�.\n");
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
	printf("���ø� �ϼ̽��ϴ�.\n");
	f = card[rand() % 52];
	g = card[rand() % 52];
	printf("ù��° ���� %d,%d�Դϴ�.", b, f);
	if (CheckBlackJack(b, f))
	{
		if (CheckAce(d))//�����ε� ��밡 ���̽� �̹Ƿ� �̺� �Ӵ�
			i = EvenMoney(a, d, e);
		else
		{
			printf("ù��° ���� �����Դϴ�. ���� �ݾ��� 1.5�踦 �޽��ϴ�.\n");
			Sleep(1000);
			i = a * 1.5;
		}
	}
	printf("�ι�° ���� %d,%d�Դϴ�.", c, g);
	if (CheckBlackJack(c, g))
	{
		if (CheckAce(d))
			i = EvenMoney(a, d, e);
		else
		{
			printf("�ι�° ���� �����Դϴ�. ���� �ݾ��� 1.5�踦 �޽��ϴ�.\n");
			Sleep(1000);
			j = a * 1.5;
		}
	}
	else
	{
		int phap1 = b + f;
		int phap2 = c + g;
		int dhap = d + e;
		int z;//���޴� ����
		int g, h, i, j, k;
		printf("ù��° ���� ���� �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
		scanf("%d", &z);
		if (z)
		{
			g = card[rand() % 52];
			printf("����� ����° ī��� %d�Դϴ�.\n", g);
			Sleep(1000);
			phap1 += g;
			if (phap1 > 21)
			{
				printf("���� 21�� �Ѿ����ϴ�. ������ ���� 2�踦 �ҽ��ϴ�.\n");
				Sleep(1000);
				i = -2 * a;
			}
			printf("�ι�° ���� ���� �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
			scanf("%d", &z);
			if (z)
			{
				h = card[rand() % 52];
				printf("����� ����° ī��� %d�Դϴ�.\n", g);
				Sleep(1000);
				phap2 += h;
				if (phap2 > 21)
				{
					printf("���� 21�� �Ѿ����ϴ�. ������ ���� 2�踦 �ҽ��ϴ�.\n");
					Sleep(1000);
					i = -2 * a;
				}
				else
				{
					printf("����� �����Դϴ�.\n");
					printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
					printf("��� ī���� ��=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16) return 2 * (Dealer(a, phap1, dhap) + Dealer(a, phap2, dhap));
					else
					{
						j = card[rand() % 52];
						dhap += j;
						printf("����� ����° ī��� %d�Դϴ�.\n", j);
						printf("���ī���� ��=%d\n", dhap);
						Sleep(1000);
						if (dhap > 16) return 2 * (Dealer(a, phap1, dhap) + Dealer(a, phap2, dhap));
						else
						{
							k = card[rand() % 52];
							dhap += k;
							printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
							printf("���ī���� ��=%d\n", dhap);
							Sleep(1000);
							if (dhap > 16) return 2 * (Dealer(a, phap1, dhap) + Dealer(a, phap2, dhap));
							else
							{
								printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
								Sleep(1000);
								i = 2 * a;
							}
						}
					}
				}
			}
			else
			{
				printf("�� or ���ĵ�(��=1,���ĵ�=0)");
				scanf("%d", &z);
				if (z)
				{
					g = card[rand() % 52];
					printf("����� ����° ī��� %d�Դϴ�.\n", g);
					Sleep(1000);
					phap1 += g;
					if (phap1 > 21)
					{
						printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
						Sleep(1000);
						return -a;
					}
					else
					{
						printf("�� or ���ĵ�(��=1,���ĵ�=0)");
						scanf("%d", &z);
						if (z)
						{
							h = card[rand() % 52];
							printf("����� �׹�° ī��� %d�Դϴ�.\n", h);
							Sleep(1000);
							phap1 += h;
							if (phap1 > 21)
							{
								printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
								Sleep(1000);
								return -a;
							}
							else
							{
								printf("�� or ���ĵ�(��=1,���ĵ�=0)");
								scanf("%d", &z);
								if (z)
								{
									i = card[rand() % 52];
									printf("����� �ټ���° ī��� %d�Դϴ�.\n", i);
									Sleep(1000);
									phap1 += i;
									if (phap1 > 21)
									{
										printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
										Sleep(1000);
										return -a;
									}
									else
									{
										printf("�ټ���° ī�带 �޾ҽ��ϴ�.\n����� �̰���ϴ�.\n������ ���� �޽��ϴ�.");
										Sleep(1000);
										return a;
									}
								}
							}
						}
					}
					printf("ù��° ���� ī���� ��=%d\n", phap1);
					Sleep(1000);
				}
				else
				{
					printf("�ι�° ��\n");
					printf("�� or ���ĵ�(��=1,���ĵ�=0)");
					scanf("%d", &z);
					if (z)
					{
						g = card[rand() % 52];
						printf("����� ����° ī��� %d�Դϴ�.\n", g);
						Sleep(1000);
						phap2 += g;
						if (phap2 > 21)
						{
							printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
							Sleep(1000);
							return -a;
						}
						else
						{
							printf("�� or ���ĵ�(��=1,���ĵ�=0)");
							scanf("%d", &z);
							if (z)
							{
								h = card[rand() % 52];
								printf("����� �׹�° ī��� %d�Դϴ�.\n", h);
								Sleep(1000);
								phap2 += h;
								if (phap2 > 21)
								{
									printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
									Sleep(1000);
									return -a;
								}
								else
								{
									printf("�� or ���ĵ�(��=1,���ĵ�=0)");
									scanf("%d", &z);
									if (z)
									{
										i = card[rand() % 52];
										printf("����� �ټ���° ī��� %d�Դϴ�.\n", i);
										Sleep(1000);
										phap2 += i;
										if (phap2 > 21)
										{
											printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
											Sleep(1000);
											return -a;
										}
										else
										{
											printf("�ټ���° ī�带 �޾ҽ��ϴ�.\n����� �̰���ϴ�.\n������ ���� �޽��ϴ�.");
											Sleep(1000);
											return a;
										}
									}
									else
									{
										printf("�ι�° ���� ī���� ��=%d\n", phap2);
										printf("����� �����Դϴ�.\n");
										printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
										printf("��� ī���� ��=%d\n", dhap);
										if (dhap > 16)
										{
											i = Dealer(a, phap1, dhap);
											j = Dealer(a, phap2, dhap);
										}
										else
										{
											j = card[rand() % 52];
											dhap += j;
											printf("����� ����° ī��� %d�Դϴ�.\n", j);
											printf("���ī���� ��=%d\n", dhap);
											if (dhap > 16)
											{
												i = Dealer(a, phap1, dhap);
												j = Dealer(a, phap2, dhap);
											}
											else
											{
												k = card[rand() % 52];
												dhap += k;
												printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
												printf("���ī���� ��=%d\n", dhap);
												Sleep(1000);
												if (dhap > 16)
												{
													i = Dealer(a, phap1, dhap);
													j = Dealer(a, phap2, dhap);
												}
												else
												{
													printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
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
								printf("�ι�° ���� ī���� ��=%d\n", phap2);
								printf("����� �����Դϴ�.\n");
								printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
								printf("��� ī���� ��=%d\n", dhap);
								if (dhap > 16)
								{
									i = Dealer(a, phap1, dhap);
									j = Dealer(a, phap2, dhap);
								}
								else
								{
									j = card[rand() % 52];
									dhap += j;
									printf("����� ����° ī��� %d�Դϴ�.\n", j);
									printf("���ī���� ��=%d\n", dhap);
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
										printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
										printf("���ī���� ��=%d\n", dhap);
										Sleep(1000);
										if (dhap > 16)
										{
											i = Dealer(a, phap1, dhap);
											j = Dealer(a, phap2, dhap);
										}
										else
										{
											printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
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
						printf("�ι�° ���� ī���� ��=%d\n", phap2);
						printf("����� �����Դϴ�.\n");
						printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
						printf("��� ī���� ��=%d\n", dhap);
						if (dhap > 16)
						{
							i = Dealer(a, phap1, dhap);
							j = Dealer(a, phap2, dhap);
						}
						else
						{
							j = card[rand() % 52];
							dhap += j;
							printf("����� ����° ī��� %d�Դϴ�.\n", j);
							printf("���ī���� ��=%d\n", dhap);
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
								printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
								printf("���ī���� ��=%d\n", dhap);
								Sleep(1000);
								if (dhap > 16)
								{
									i = Dealer(a, phap1, dhap);
									j = Dealer(a, phap2, dhap);
								}
								else
								{
									printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
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
			printf("�ι�° ���� ī���� ��=%d\n", phap2);
			printf("����� �����Դϴ�.\n");
			printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
			printf("��� ī���� ��=%d\n", dhap);
			if (dhap > 16)
			{
				i = Dealer(a, phap1, dhap);
				j = Dealer(a, phap2, dhap);
			}
			else
			{
				j = card[rand() % 52];
				dhap += j;
				printf("����� ����° ī��� %d�Դϴ�.\n", j);
				printf("���ī���� ��=%d\n", dhap);
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
					printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
					printf("���ī���� ��=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16)
					{
						i = Dealer(a, phap1, dhap);
						j = Dealer(a, phap2, dhap);
					}
					else
					{
						printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
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
	printf("�̺� �Ӵ� �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
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
	int f;//���޴� ����
	int g, h, i, j, k;
	printf("���� �Ͻðڽ��ϱ�?(��=1,�ƴϿ�=0)");
	scanf("%d", &f);
	if (f)
	{
		g = card[rand() % 52];
		printf("����� ����° ī��� %d�Դϴ�.\n", g);
		Sleep(1000);
		phap += g;
		if (phap > 21)
		{
			printf("���� 21�� �Ѿ����ϴ�. ������ ���� 2�踦 �ҽ��ϴ�.\n");
			Sleep(1000);
			return -2 * a;
		}
		else
		{
			printf("����� �����Դϴ�.\n");
			printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
			printf("��� ī���� ��=%d\n", dhap);
			Sleep(1000);
			if (dhap > 16) return 2 * Dealer(a, phap, dhap);
			else
			{
				j = card[rand() % 52];
				dhap += j;
				printf("����� ����° ī��� %d�Դϴ�.\n", j);
				printf("���ī���� ��=%d\n", dhap);
				Sleep(1000);
				if (dhap > 16) return 2 * Dealer(a, phap, dhap);
				else
				{
					k = card[rand() % 52];
					dhap += k;
					printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
					printf("���ī���� ��=%d\n", dhap);
					Sleep(1000);
					if (dhap > 16) return 2 * Dealer(a, phap, dhap);
					else
					{
						printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
						Sleep(1000);
						return 2 * a;
					}
				}
			}
		}
	}
	else
	{
		printf("�� or ���ĵ�(��=1,���ĵ�=0)");
		scanf("%d", &f);
		if (f)
		{
			g = card[rand() % 52];
			printf("����� ����° ī��� %d�Դϴ�.\n", g);
			phap += g;
			Sleep(1000);
			if (phap > 21)
			{
				printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
				Sleep(1000);
				return -a;
			}
			else
			{
				printf("�� or ���ĵ�(��=1,���ĵ�=0)");
				scanf("%d", &f);
				if (f)
				{
					h = card[rand() % 52];
					printf("����� �׹�° ī��� %d�Դϴ�.\n", h);
					Sleep(1000);
					phap += h;
					if (phap > 21)
					{
						printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
						Sleep(1000);
						return -a;
					}
					else
					{
						printf("�� or ���ĵ�(��=1,���ĵ�=0)");
						scanf("%d", &f);
						if (f)
						{
							i = card[rand() % 52];
							printf("����� �ټ���° ī��� %d�Դϴ�.\n", i);
							Sleep(1000);
							phap += i;
							if (phap > 21)
							{
								printf("���� 21�� �Ѿ����ϴ�. ������ ���� �ҽ��ϴ�.\n");
								Sleep(1000);
								return -a;
							}
							else
							{
								printf("�ټ���° ī�带 �޾ҽ��ϴ�.\n����� �̰���ϴ�.\n������ ���� �޽��ϴ�.");
								Sleep(1000);
								return a;
							}
						}
						else
						{
							printf("����� �����Դϴ�.\n");
							printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
							printf("��� ī���� ��=%d\n", dhap);
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
					printf("����� �����Դϴ�.\n");
					printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
					printf("��� ī���� ��=%d\n", dhap);
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
			printf("����� �����Դϴ�.\n");
			printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
			printf("��� ī���� ��=%d\n", dhap);
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
		printf("��밡 21���� Ů�ϴ�. �̰���ϴ�.\n");
		return a;
	}
	else if (phap > dhap)
	{
		printf("�̰���ϴ�. ������ ���� ����ϴ�.\n");
		Sleep(1000);
		return a;
	}
	else if (phap == dhap)
	{
		printf("�����ϴ�.\n");
		Sleep(1000);
		return 0;
	}
	else
	{
		printf("�����ϴ�. ������ ���� �ҽ��ϴ�.\n");
		Sleep(1000);
		return -a;
	}
}
int NotDoubleBet(int a, int e, int dhap, int phap, int j, int k)
{
	printf("����� �����Դϴ�.\n");
	printf("����� �ι�° ī��� %d�����ϴ�.\n", e);
	printf("��� ī���� ��=%d\n", dhap);
	Sleep(1000);
	if (dhap > 16) return Dealer(a, phap, dhap);
	else
	{
		j = card[rand() % 52];
		dhap += j;
		printf("����� ����° ī��� %d�Դϴ�.\n", j);
		printf("���ī���� ��=%d\n", dhap);
		Sleep(1000);
		if (dhap > 16) return Dealer(a, phap, dhap);
		else
		{
			k = card[rand() % 52];
			dhap += k;
			printf("����� �׹�° ī��� %d�Դϴ�.\n", k);
			printf("���ī���� ��=%d\n", dhap);
			Sleep(1000);
			if (dhap > 16) return Dealer(a, phap, dhap);
			else
			{
				printf("��밡 5��° ī�带 �̾ƾ� �մϴ�.\n����� �̰���ϴ�.");
				return a;
			}
		}
	}
}
