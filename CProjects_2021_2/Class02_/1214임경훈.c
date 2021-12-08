#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	int name;
	int position;
}Jungle;

void printfjungleinfo(Jungle s, int time, int home);

int B = 1, Bs = 2, R = 3, Rs = 4, upc = 5, downc = 6;

Jungle Graves, Elise, Leesin, Nidalee, Poppy;

int main() {
	int time;
	int home;
	Jungle ourname = { 0 };
	Jungle enemyname = { 0 };

	Graves.name = 1;
	Elise.name = 2;
	Leesin.name = 3;
	Nidalee.name = 4;
	Poppy.name = 5;

	printf("��� �����̸�, �츮���� �̸��� �Է��ϼ���.(Graves: 1, Elise: 2, Leesin: 3, Nidalee: 4, Poppy: 5 ��): ");
	scanf("%d %d", &ourname.name, &enemyname.name);
	printf("�ڽ��� ���� �����, �������� �������� �Է��ϼ��� (�����: 1, ������: 2)");
	scanf("%d", &home);
	printf("�ð��� �Է��ϼ���.(ex:1�� 30��: 130): ");
	scanf("%d", &time);

	printf("(1: ���, 2: ����, 3: �β���, 4: Į���θ�,\n 5: ����, 6: ���ź�, 7: ��������, 8: �Ʒ�������)\n");

	printf("�츮���� ");
	printfjungleinfo(ourname, time, 3 - home);
	printf("������� ");
	printfjungleinfo(enemyname, time, home);

	return 0;
}

void printfjungleinfo(Jungle s, int time, int home) {
	if (time <= 130) {
		if (s.name == 1) {
			if (home == 1) {
				s.position = R;
			}
			if (home == 2) {
				s.position = B;
			}
		}
		else if (s.name == 2) {
			if (home == 1) {
				s.position = B;
			}
			if (home == 2) {
				s.position = R;
			}
		}
		else if (s.name == 3) {
			if (home == 1) {
				s.position = B;
			}
			if (home == 2) {
				s.position = R;
			}
		}
		else if (s.name == 4) {
			if (home == 1) {
				s.position = B;
			}
			if (home == 2) {
				s.position = R;
			}
		}
		else if (s.name == 5) {
			if (home == 1) {
				s.position = B;
			}
			if (home == 2) {
				s.position = R;
			}
		}
	}
	else if (130 <= time <= 215) {
		if (s.name == 1) {
			if (home == 1) {
				s.position = Rs;
			}
			if (home == 2) {
				s.position = Bs;
			}
		}
		else if (s.name == 2) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
		else if (s.name == 3) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
		else if (s.name == 4) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
		else if (s.name == 5) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
	}
	else if (215 <= time <= 300) {
		if (s.name == 1) {
			if (home == 1) {
				s.position = downc;
			}
			if (home == 2) {
				s.position = upc;
			}
		}
		else if (s.name == 2) {
			if (home == 1) {
				s.position = upc;
			}
			if (home == 2) {
				s.position = downc;
			}
		}
		else if (s.name == 3) {
			if (home == 1) {
				s.position = upc;
			}
			if (home == 2) {
				s.position = downc;
			}
		}
		else if (s.name == 4) {
			if (home == 1) {
				s.position = upc;
			}
			if (home == 2) {
				s.position = downc;
			}
		}
		else if (s.name == 5) {
			if (home == 1) {
				s.position = upc;
			}
			if (home == 2) {
				s.position = downc;
			}
		}
	}
	else if (300 <= time <= 345) {
		if (s.name == 1) {
			if (home == 1) {
				s.position = Rs;
			}
			if (home == 2) {
				s.position = Bs;
			}
		}
		else if (s.name == 2) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
		else if (s.name == 3) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
		else if (s.name == 4) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
		else if (s.name == 5) {
			if (home == 1) {
				s.position = Bs;
			}
			if (home == 2) {
				s.position = Rs;
			}
		}
	}
	if (s.position == 1)
		printf("��� �����ʿ� �ֽ��ϴ�\n");
	else if (s.position == 3)
		printf("���� �����ʿ� �ֽ��ϴ�\n");
	else if (s.position == 2)
		printf("������, �β���, ���� �ʿ� �ֽ��ϴ�\n");
	else if (s.position == 4)
		printf("�������, Į���θ�, ������ �ʿ� �ֽ��ϴ�\n");
	else if (s.position == 5)
		printf("�������Կ� �ֽ��ϴ�\n");
	else if (s.position == 6)
		printf("�Ʒ������Կ� �ֽ��ϴ�\n");
}