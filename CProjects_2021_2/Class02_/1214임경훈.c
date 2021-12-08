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

	printf("상대 정글이름, 우리정글 이름을 입력하세요.(Graves: 1, Elise: 2, Leesin: 3, Nidalee: 4, Poppy: 5 중): ");
	scanf("%d %d", &ourname.name, &enemyname.name);
	printf("자신의 팀이 블루팀, 레드팀중 무엇인지 입력하세요 (블루팀: 1, 레드팀: 2)");
	scanf("%d", &home);
	printf("시간을 입력하세요.(ex:1분 30초: 130): ");
	scanf("%d", &time);

	printf("(1: 블루, 2: 늑대, 3: 두꺼비, 4: 칼날부리,\n 5: 레드, 6: 돌거북, 7: 윗바위게, 8: 아랫바위게)\n");

	printf("우리팀은 ");
	printfjungleinfo(ourname, time, 3 - home);
	printf("상대팀은 ");
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
		printf("블루 몬스터쪽에 있습니다\n");
	else if (s.position == 3)
		printf("레드 몬스터쪽에 있습니다\n");
	else if (s.position == 2)
		printf("블루몬스터, 두꺼비, 늑대 쪽에 있습니다\n");
	else if (s.position == 4)
		printf("레드몬스터, 칼날부리, 바위게 쪽에 있습니다\n");
	else if (s.position == 5)
		printf("윗바위게에 있습니다\n");
	else if (s.position == 6)
		printf("아랫바위게에 있습니다\n");
}