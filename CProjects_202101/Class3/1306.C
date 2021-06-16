#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>
#include<windows.h> // 콘솔창을 지우기 위해서 필요
#include<time.h> //난수 생성과 시간 측정을 위해 필요
#include<stdlib.h>//난수 생성을 위해 필요
#include<conio.h>//문자 입력을 위해 필요
struct player {    //플레이어의 정보를 담을 구조체
	char name[100];
	double health;
	double nowhealth;
	long long int ad;
	long long int ap;
	long long int gold;
	long long int armor;
	long long int piheup;
	char class[20];
};
struct monster {   //몬스터의 정보를 담을 구조체
	char name[100];
	double health;
	double maxhealth;
	int armor;
	int ad;
	int money;
	int faint;
};
void openarena(int* round, struct player* player);          //전투장 함수
void opentooltip(struct player* player);                     //상태창 함수
void openmarket(struct player* player);                     //상점 함수
struct monster sponemonster(int round);                   //몬스터를 랜덤으로 생성하는 함수0
void openroby(struct player* player, int round);          //로비 함수
int main() {
	system("title rpg게임");                               //cmd창의 이름을 rpg게임으로 바꾸어줌
	system("color F0");                                   //실제 게임처럼 하기 위해서 흰색 바탕에 검은색 글씨로 변경
	system("mode con:cols=200 lines=60");                     //크기가 작은 cmd창이면 출력이 안보이거나 줄내림이 일어날 수 있어서 크기 조정
	srand(time(NULL));                    //rand()를 쓰기위함
	printf("\n\n                                                        당신의 영어 이름을 입력해주세요(20자 이내):");   //플레이어의 이름을 입력받음
	char name[100];                     //이름을 받을 배열
	struct player player;                  //플레이어 변수 생성
	scanf("%s", &name);
	strcpy(player.name, name);              //입력받은 이름을 player구조체로 복사
	system("cls");                    //cmd창 클리어
	int round = 0;
	int stage = 0;                     //몇라운드인지 알려주는 변수
	while (1) {                         //잘못된 키를 입력하면 무한반복
		system("cls");
		printf("\n\n                                                       (장난하지 말고 있는 거 중에 제대로 고르세요)\n\n");
		printf("                                                   [당신의 직업을 선택하세요(a키:전사, b키:마법사, c키:탱커, d키:수호기사]");
		char class = getch();
		if (class == 'a') {
			player.ad = 5;
			player.health = 100;
			player.ap = 0;
			player.armor = 1;
			strcpy(player.class, "전사");
			break;
		}
		if (class == 'b') {
			player.ad = 1;
			player.health = 100;
			player.ap = 0;
			player.armor = 0;
			strcpy(player.class, "마법사");
			break;
		}
		if (class == 'c') {
			player.ad = 2;
			player.health = 500;
			player.ap = 0;
			player.armor = 2;
			strcpy(player.class, "탱커");
			break;
		}
		if (class == 'd') {
			player.ad = 2;
			player.health = 200;
			player.ap = 0;
			player.armor = 5;
			strcpy(player.class, "수호기사");
			break;                                   //선택한 직업에 맞게 초기화
		}
	}
	system("cls");                                                                       //스토리 진행
	printf("\n                                          계속하려면 아무 키나 클릭하세요\n\n\n\n");
	printf("                                          [ 안녕하세요 %s님! ]", player.name);
	char trash = getch();
	system("cls");
	printf("\n                                          계속하려면 아무 키나 클릭하세요\n\n\n\n");
	printf("                                          [ 재밌는 rpg 게임에 오신 것을 환영해요! ]\n\n\n");
	trash = getch();
	system("cls");
	printf("\n                                          계속하려면 아무 키나 클릭하세요\n\n\n\n");
	printf("                                          [ 이 게임은 기본적으로 상태창, 전투장, 상점 기능을 제공해요 ]\n\n\n");
	trash = getch();
	system("cls");
	printf("\n                                          계속하려면 아무 키나 클릭하세요\n\n\n\n");
	printf("                                          [ 그러면 이제 게임을 즐기러 가볼까요~ ]\n");
	trash = getch();

	player.gold = 500;
	player.piheup = 0;
	while (1) {
		system("cls");                          //입력받은 키에 따라 이동
		openroby(&player, round);
		char key = getch();
		if (key == 'k') {
			openmarket(&player);
		}
		if (key == 't') {
			opentooltip(&player);
		}
		if (key == 'x') {
			openarena(&round, &player);
		}
		if (key == 'r') {
			round = 0;
		}
	}
}
struct monster sponemonster(int round) {       //몬스터를 생성하는 함수
	struct monster monster;
	srand(time(NULL));
	int monsternum = rand() % 5;                    //랜덤하게 몬스터가 구성됨
	switch (monsternum) {
	case 0:
		monster.ad = 5 + round / 5;
		monster.armor = 0 + round / 10;
		monster.health = 200 + 5 * (double)round;
		monster.maxhealth = 200 + 5 * (double)round;
		monster.money = 20 + round;
		strcpy(monster.name, "균형잡힌 기사");
		break;
	case 1:
		monster.ad = 2 + round * 2 / 5;
		monster.armor = 3 + round * 3 / 20;
		monster.health = 400 + 10 * (double)round;
		monster.maxhealth = 400 + 10 * (double)round;
		monster.money = 20 + round;
		strcpy(monster.name, "체력돼지");
		break;
	case 2:
		monster.ad = 2 + round * 2 / 5;
		monster.armor = 5 + round / 5;
		monster.health = 100 + 5 * (double)round / 2;
		monster.maxhealth = 100 + 5 * (double)round / 2;
		monster.money = 20 + round;
		strcpy(monster.name, "단단한 아르마딜로");
		break;
	case 3:
		monster.ad = 15 + 3 * round / 5;
		monster.armor = 0 + round / 20;
		monster.health = 100 + 5 * (double)round / 2;
		monster.maxhealth = 100 + 5 * (double)round / 2;
		monster.money = 20 + round;
		strcpy(monster.name, "죽창부대");
		break;
	case 4:
		monster.ad = 5 + round / 5;
		monster.armor = 1 + round / 20;
		monster.health = 100 + 5 * (double)round / 2;
		monster.maxhealth = 100 + 5 * (double)round / 2;
		monster.money = 100 + 5 * round;
		strcpy(monster.name, "돈많은 고블린");
		break;
	}
	if (round % 10 == 0) {                    //라운드가 10인 경우 강한 보스몹이 됨
		monster.ad *= 3;
		monster.health *= 10;
		monster.maxhealth *= 10;
		monster.money *= 5;
	}
	return monster;
}

void openarena(int* round, struct player* player)
{
	clock_t firstperiodSkillQ = 0;
	clock_t firstperiodSkillW = 0;
	clock_t firstperiodSkillE = 0;
	clock_t firstperiodSkillR = 0;
	clock_t firstperiodSkillRE = 0;
	clock_t firstperiodFainted = 0;
	clock_t lastTimeQ = -30000;
	clock_t lastTimeW = -30000;
	clock_t lastTimeE = -30000;
	clock_t lastTimeR = -30000;
	long long int RTmpArmor = player->armor;
	long long int RTmpAd = player->ad;
	long long int WTmpPiheup = player->piheup;
	int skillQ = 0;
	int skillW = 0;
	int skillE = 0;
	int skillR = 0;
	int skillRQ = 0;
	int skillRE = 0;
	int fainted = 0;
	while (1) {
		struct monster monster = sponemonster(*round + 1);
		int TmpMonsterAd = monster.ad;
		clock_t firstperiodMonsterattack = clock();
		while (monster.health > 0) {
			system("cls");
			if (*round % 10 + 1 == 10) {
				printf("주의: 보스가 출현합니다.\n");
				system("color 42");
			}
			printf("기본공격은 스페이스바, 스킬은 q,w,e,궁극기는 r을 눌러서 사용하세요, 로비로 돌아가려면 x키를 누르세요\n\n");
			printf("%d스테이지 %d라운드\n\n\n\n\n", *round / 10, *round % 10 + 1);
			printf("                                                                                    몬스터 이름:%s", monster.name);
			if (fainted) {
				printf("(기절함)");                              //기절했다면 기절함으로 표기
			}
			printf("\n당신의 체력:%.0lf                                                                      몬스터의 체력:%.0lf\n\n", player->nowhealth, monster.health);
			int playerhealthratio = player->nowhealth / player->health * 20;         //체력의 비율에 맞추어서 체력바를 표기
			printf("[");
			for (int i = 0; i < playerhealthratio; i++) {
				printf("=");
			}
			for (int i = 0; i < 20 - playerhealthratio; i++) {
				printf(" ");
			}
			printf("]");
			printf("                                                              ");
			int monsterhealthratio = monster.health / monster.maxhealth * 20;
			printf("[");
			for (int i = 0; i < monsterhealthratio; i++) {
				printf("=");
			}
			for (int i = 0; i < 20 - monsterhealthratio; i++) {
				printf(" ");
			}
			printf("]\n");
			if (!strcmp(player->class, "전사")) {                                                    //스킬별로 가장 최근에 사용했던 시간이 쿨타임보다 길다면 사용할 수 있다고 출력
				if (clock() - lastTimeQ < 3000) {
					printf("q스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeQ) / 1000 + 1);
				}
				else printf("q스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeW < 10000) {
					printf("w스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeW) / 1000 + 1);
				}
				else printf("w스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeE < 5000) {
					printf("e스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeE) / 1000 + 1);
				}
				else printf("e스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeR < 30000) {
					printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
				}
				else printf("r스킬을 사용할 수 있습니다.\n");
			}
			if (!strcmp(player->class, "마법사")) {
				if (clock() - lastTimeQ < 5000) {
					printf("q스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeQ) / 1000 + 1);
				}
				else printf("q스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeW < 3000) {
					printf("w스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeW) / 1000 + 1);
				}
				else printf("w스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeE < 15000) {
					printf("e스킬이 %d초 남았습니다.\n", (15000 - clock() + lastTimeE) / 1000 + 1);
				}
				else printf("e스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeR < 30000) {
					printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
				}
				else printf("r스킬을 사용할 수 있습니다.\n");
			}
			if (!strcmp(player->class, "탱커")) {
				if (clock() - lastTimeQ < 2000) {
					printf("q스킬이 %d초 남았습니다.\n", (2000 - clock() + lastTimeQ) / 1000 + 1);
				}
				else printf("q스킬을 사용할 수 있습니다.\n");
				printf("w스킬은 패시브 스킬입니다.\n");
				if (clock() - lastTimeE < 4000) {
					printf("e스킬이 %d초 남았습니다.\n", (4000 - clock() + lastTimeE) / 1000 + 1);
				}
				else printf("e스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeR < 30000) {
					printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
				}
				else printf("r스킬을 사용할 수 있습니다.\n");
			}
			if (!strcmp(player->class, "수호기사")) {
				if (clock() - lastTimeQ < 7000) {
					printf("q스킬이 %d초 남았습니다.\n", (7000 - clock() + lastTimeQ) / 1000 + 1);
				}
				else printf("q스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeW < 5000) {
					printf("w스킬이 %d초 남았습니다.\n", (50000 - clock() + lastTimeW) / 1000 + 1);
				}
				else printf("w스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeE < 10000) {
					printf("e스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeE) / 1000 + 1);
				}
				else printf("e스킬을 사용할 수 있습니다.\n");
				if (clock() - lastTimeR < 30000) {
					printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
				}
				else printf("r스킬을 사용할 수 있습니다.\n");
			}
			printf("                                                                                    몬스터의 방어력:%d\n", monster.armor);
			printf("                                                                                    몬스터의 공격력:%d\n", monster.ad);
			printf("                                                                                    처치시 골드:%d\n", monster.money);         //몬스터의 종류별로 다른 모습이 나옴
			if (!strcmp(monster.name, "균형잡힌 기사")) {
				printf("                    ┏─┓\n");
				printf("                    │ │\n");
				printf("                    │ │\n");

				printf("                   ┏┘ └┓\n");
				printf("                   │   │    \n");
				printf("                   │   │\n");
				printf("                  ┏┘   └┓\n");
				printf("                  │     │\n");
				printf("   ┏────────┓    ┏┘     └┓                                                             ┏──────┓           ┏──┓\n");
				printf("   │        │    └┓     ┏┘                                                            ┏┘      └┓          │  │ \n");
				printf("   │      ㅅ│     └─┓ ┏─┘                                                             │  │  │  │          │  │ \n");
				printf("   │        │     ┏─┴─┴─┓                                                             │  │  │  │          │  │\n");
				printf("   ├────────┤     └─┬─┬─┘                                                             │  │  │  │          │  │\n");
				printf("  ┏┘        └───────┼─┤                                                               ├────────┤          │  │\n");
				printf("  │                 │ │                                                          ┏────┘        └─────┓   ┏│  │┓ \n");
				printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘   │    │ \n");
				printf(" │          ┏┘                                                                      │  │       │  │      └─┬┬─┘     \n");
				printf(" │          │                                                                       │  │       │  └────────┼┘\n");
				printf(" │          │                                                                       │  │       ├───────────┘  \n");
				printf(" │          │                                                                       │  │       │  \n");
				printf(" ├─────┬────┤                                                                       └──┤       │        \n");
				printf(" │     │    │                                                                          │       │   \n");
				printf(" │     │    │                                                                          ├───────┤  \n");
				printf(" │    ┏┘    │                                                                          │       │\n");
				printf(" │    │    ┏┘                                                                          │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" └────┤    │                                                                           │   │   │\n");
				printf("      └────┘                                                                           │   │   │\n");
				printf("                                                                                       └───┴───┘\n");
			}
			else if (!strcmp(monster.name, "체력돼지")) {
				printf("                    ┏─┓\n");
				printf("                    │ │\n");
				printf("                    │ │\n");

				printf("                   ┏┘ └┓\n");
				printf("                   │   │    \n");
				printf("                   │   │\n");
				printf("                  ┏┘   └┓\n");
				printf("                  │     │\n");
				printf("   ┏────────┓    ┏┘     └┓                                                             ┏──────┓     \n");
				printf("   │        │    └┓     ┏┘                                                            ┏┘      └┓      \n");
				printf("   │      ㅅ│     └─┓ ┏─┘                                                             │  |   | │          \n");
				printf("   │        │     ┏─┴─┴─┓                                                             │ ┏─┬┬─┓ │      \n");
				printf("   ├────────┤     └─┬─┬─┘                                                             │ └────┘ │     \n");
				printf("  ┏┘        └───────┼─┤                                                               ├────────┤         \n");
				printf("  │                 │ │                                                          ┏────┘        └─────┓    \n");
				printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘  \n");
				printf(" │          ┏┘                                                                      │  │       │  │         \n");
				printf(" │          │                                                                       │  │       │  │\n");
				printf(" │          │                                                                       │  │       │  │  \n");
				printf(" │          │                                                                       │  │       │  │\n");
				printf(" ├─────┬────┤                                                                       └──┤       ├──┘        \n");
				printf(" │     │    │                                                                          │       │   \n");
				printf(" │     │    │                                                                          ├───────┤  \n");
				printf(" │    ┏┘    │                                                                          │       │\n");
				printf(" │    │    ┏┘                                                                          │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" └────┤    │                                                                           │   │   │\n");
				printf("      └────┘                                                                           │   │   │\n");
				printf("                                                                                       └───┴───┘\n");
			}
			else if (!strcmp(monster.name, "단단한 아르마딜로")) {
				printf("                    ┏─┓\n");
				printf("                    │ │\n");
				printf("                    │ │\n");
				printf("                   ┏┘ └┓\n");
				printf("                   │   │    \n");
				printf("                   │   │\n");
				printf("                  ┏┘   └┓\n");
				printf("                  │     │\n");
				printf("   ┏────────┓    ┏┘     └┓                                                \n");
				printf("   │        │    └┓     ┏┘                                                        \n");
				printf("   │      ㅅ│     └─┓ ┏─┘                                                        \n");
				printf("   │        │     ┏─┴─┴─┓                                                         \n");
				printf("   ├────────┤     └─┬─┬─┘                                                   \n");
				printf("  ┏┘        └───────┼─┤                                                   \n");
				printf("  │                 │ │                                                        \n");
				printf(" ┏┘     ─────┬──────┴─┘                                              \n");
				printf(" │          ┏┘                                                                      \n");
				printf(" │          │                                                      │││││││││││││││                \n");
				printf(" │          │                                                      │││││││││││││││             \n");
				printf(" │          │                                                      │││││││││││││││\n");
				printf(" ├─────┬────┤                                                    ┏─┘             └─┓\n");
				printf(" │     │    │                                                    │                 └─┓\n");
				printf(" │     │    │                                                   ┏┘                   └─┓\n");
				printf(" │    ┏┘    │                                                 ┏─┘   ㅅ                 └─┓\n");
				printf(" │    │    ┏┘                                                 └┓                       ┏─┘\n");
				printf(" │    │    │                                                   │                     ┏─┘\n");
				printf(" │    │    │                                                   └─┓                 ┏─┘\n");
				printf(" └────┤    │                                                     └───┓┏ ┓┏───┓┏──┓┏┘                     \n");
				printf("      └────┘                                                         ││ ││   ││  ││              \n");
				printf("                                                                     └┘ └┘   └┘  └┘              \n");
			}
			else if (!strcmp(monster.name, "죽창부대")) {
				printf("                    ┏─┓\n");
				printf("                    │ │\n");
				printf("                    │ │\n");
				printf("                   ┏┘ └┓\n");
				printf("                   │   │    \n");
				printf("                   │   │\n");
				printf("                  ┏┘   └┓\n");
				printf("                  │     │\n");
				printf("   ┏────────┓    ┏┘     └┓                                                             ┏──────┓            ││\n");
				printf("   │        │    └┓     ┏┘                                                            ┏┘      └┓          ┏┘└┓ \n");
				printf("   │      ㅅ│     └─┓ ┏─┘                                                             │ └┘  └┘ │          └┓┏┘ \n");
				printf("   │        │     ┏─┴─┴─┓                                                             │        │           ││\n");
				printf("   ├────────┤     └─┬─┬─┘                                                             │  ┏──┓  │           ││\n");
				printf("  ┏┘        └───────┼─┤                                                               ├────────┤           ││\n");
				printf("  │                 │ │                                                          ┏────┘        └─────┓     ││ \n");
				printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘     ││ \n");
				printf(" │          ┏┘                                                                      │  │       │  │        ││       \n");
				printf(" │          │                                                                       │  │       │  └────────┼┘\n");
				printf(" │          │                                                                       │  │       ├───────────┘  \n");
				printf(" │          │                                                                       │  │       │  \n");
				printf(" ├─────┬────┤                                                                       └──┤       │        \n");
				printf(" │     │    │                                                                          │       │   \n");
				printf(" │     │    │                                                                          ├───────┤  \n");
				printf(" │    ┏┘    │                                                                          │       │\n");
				printf(" │    │    ┏┘                                                                          │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" └────┤    │                                                                           │   │   │\n");
				printf("      └────┘                                                                           │   │   │\n");
				printf("                                                                                       └───┴───┘\n");
			}
			else if (!strcmp(monster.name, "돈많은 고블린")) {
				printf("                    ┏─┓\n");
				printf("                    │ │\n");
				printf("                    │ │\n");

				printf("                   ┏┘ └┓\n");
				printf("                   │   │    \n");
				printf("                   │   │\n");
				printf("                  ┏┘   └┓\n");
				printf("                  │     │\n");
				printf("   ┏────────┓    ┏┘     └┓                                                           ┏──┓    ┏──┓     \n");
				printf("   │        │    └┓     ┏┘                                                           └┓ └┓  ┏┘ ┏┘      \n");
				printf("   │      ㅅ│     └─┓ ┏─┘                                                             │  |   | │          \n");
				printf("   │        │     ┏─┴─┴─┓                                                             │        │      \n");
				printf("   ├────────┤     └─┬─┬─┘                                                             │  └──┘  │     \n");
				printf("  ┏┘        └───────┼─┤                                                               ├────────┤         \n");
				printf("  │                 │ │                                                          ┏────┘        └─────┓    \n");
				printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘  \n");
				printf(" │          ┏┘                                                                      │  │       │  └────────┓         \n");
				printf(" │          │                                                                       │  │       │           │\n");
				printf(" │          │                                                                       │  │       │ 돈주머니  │  \n");
				printf(" │          │                                                                       │  │       │           │\n");
				printf(" ├─────┬────┤                                                                       └──┤       ├───────────┘        \n");
				printf(" │     │    │                                                                          │       │   \n");
				printf(" │     │    │                                                                          ├───────┤  \n");
				printf(" │    ┏┘    │                                                                          │       │\n");
				printf(" │    │    ┏┘                                                                          │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" │    │    │                                                                           │   │   │\n");
				printf(" └────┤    │                                                                           │   │   │\n");
				printf("      └────┘                                                                           │   │   │\n");
				printf("                                                                                       └───┴───┘\n");
			}
			Sleep(30);
			clock_t secondperiodMonsterattack = clock();
			if (secondperiodMonsterattack - firstperiodMonsterattack > 3000) {            //만약 최근 몬스터의 공격으로부터 3초가 지났다면 몬스터가 공격함
				printf("공격당했습니다!\n");
				printf("받은 피해량 %.0lf\n", (double)monster.ad * (1 - (double)player->armor / ((double)player->armor + 100)));
				player->nowhealth -= (double)monster.ad * (1 - (double)player->armor / ((double)player->armor + 100));
				system("cls");
				if (*round % 10 + 1 == 10) {
					system("color 42");
				}
				printf("기본공격은 스페이스바, 스킬은 q,w,e,궁극기는 r을 눌러서 사용하세요, 로비로 돌아가려면 x키를 누르세요\n\n");
				printf("%d스테이지 %d라운드", *round / 10, *round % 10 + 1);
				if (*round % 10 + 1 == 10) printf("(보스 스테이지!)");
				printf("\n\n\n\n\n                                                                                    몬스터 이름:%s", monster.name);
				if (fainted) {
					printf("(기절함)");
				}
				printf("\n당신의 체력:%.0lf                                                                      몬스터의 체력:%.0lf\n\n", player->nowhealth, monster.health);
				int playerhealthratio = player->nowhealth / player->health * 20;
				printf("[");
				for (int i = 0; i < playerhealthratio; i++) {
					printf("=");
				}
				for (int i = 0; i < 20 - playerhealthratio; i++) {
					printf(" ");
				}
				printf("]");
				printf("                                                              ");
				int monsterhealthratio = monster.health / monster.maxhealth * 20;
				printf("[");
				for (int i = 0; i < monsterhealthratio; i++) {
					printf("=");
				}
				for (int i = 0; i < 20 - monsterhealthratio; i++) {
					printf(" ");
				}
				printf("]\n");
				if (!strcmp(player->class, "전사")) {
					if (clock() - lastTimeQ < 3000) {
						printf("q스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 10000) {
						printf("w스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 5000) {
						printf("e스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "마법사")) {
					if (clock() - lastTimeQ < 5000) {
						printf("q스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 3000) {
						printf("w스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 15000) {
						printf("e스킬이 %d초 남았습니다.\n", (15000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "탱커")) {
					if (clock() - lastTimeQ < 2000) {
						printf("q스킬이 %d초 남았습니다.\n", (2000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					printf("w스킬은 패시브 스킬입니다.\n");
					if (clock() - lastTimeE < 4000) {
						printf("e스킬이 %d초 남았습니다.\n", (4000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "수호기사")) {
					if (clock() - lastTimeQ < 7000) {
						printf("q스킬이 %d초 남았습니다.\n", (7000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 5000) {
						printf("w스킬이 %d초 남았습니다.\n", (50000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 10000) {
						printf("e스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				printf("                                                                                    몬스터의 방어력:%d\n", monster.armor);
				printf("                                                                                    몬스터의 공격력:%d\n", monster.ad);
				printf("                                                                                    처치시 골드:%d\n", monster.money);  //몬스터별로 출력이 다름(공격모션)
				if (!strcmp(monster.name, "균형잡힌 기사")) {
					printf("                    ┏─┓\n");
					printf("                    │ │\n");
					printf("                    │ │\n");

					printf("                   ┏┘ └┓\n");
					printf("                   │   │    \n");
					printf("                   │   │\n");
					printf("                  ┏┘   └┓\n");
					printf("                  │     │\n");
					printf("   ┏────────┓    ┏┘     └┓                                               ┏──────┓           \n");
					printf("   │        │    └┓     ┏┘                                              ┏┘      └┓           \n");
					printf("   │      ㅅ│     └─┓ ┏─┘                                               │  │  │  │           \n");
					printf("   │        │     ┏─┴─┴─┓                                               │  │  │  │          \n");
					printf("   ├────────┤     └─┬─┬─┘                                               │  │  │  │          \n");
					printf("  ┏┘        └───────┼─┤                                                 ├────────┤          \n");
					printf("  │                 │ │            ┏──────────────────┓ ┏─┓        ┏────┘        └─────┓    \n");
					printf(" ┏┘     ─────┬──────┴─┘      ┏─────┘                  ├┬┘ └┓       └──┬──┓       ┏──┬──┘    \n");
					printf(" │          ┏┘               └─────┓                  ├┴┓ ┏┘          │  │       │  │           \n");
					printf(" │          │                      └──────────────────┘ └─┘           │  │       │  │\n");
					printf(" │          │                                                         │  │       │  │  \n");
					printf(" │          │                                                         │  │       │  │\n");
					printf(" ├─────┬────┤                                                         └──┼───────┼──┘        \n");
					printf(" │     │    │                                                            │       │   \n");
					printf(" │     │    │                                                            ├───────┤  \n");
					printf(" │    ┏┘    │                                                            │       │\n");
					printf(" │    │    ┏┘                                                            │   │   │\n");
					printf(" │    │    │                                                             │   │   │\n");
					printf(" │    │    │                                                             │   │   │\n");
					printf(" └────┤    │                                                             │   │   │\n");
					printf("      └────┘                                                             │   │   │\n");
					printf("                                                                         └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "체력돼지")) {
					printf("                    ┏─┓\n");
					printf("                    │ │\n");
					printf("                    │ │\n");

					printf("                   ┏┘ └┓\n");
					printf("                   │   │    \n");
					printf("                   │   │\n");
					printf("                  ┏┘   └┓\n");
					printf("                  │     │\n");
					printf("   ┏────────┓    ┏┘     └┓                                         ┏──────┓     \n");
					printf("   │        │    └┓     ┏┘                                        ┏┘      └┓      \n");
					printf("   │      ㅅ│     └─┓ ┏─┘                                         │  |   | │          \n");
					printf("   │        │     ┏─┴─┴─┓                                         │ ┏─┬┬─┓ │      \n");
					printf("   ├────────┤     └─┬─┬─┘                                         │ └────┘ │     \n");
					printf("  ┏┘        └───────┼─┤                                           ├────────┤         \n");
					printf("  │                 │ │                                      ┏────┘        └─────┓    \n");
					printf(" ┏┘     ─────┬──────┴─┘                                      └──┬──┓       ┏──┬──┘  \n");
					printf(" │          ┏┘                                                  │  │       │  │         \n");
					printf(" │          │                                                   │  │       │  │\n");
					printf(" │          │                                                   │  │       │  │  \n");
					printf(" │          │                                                   │  │       │  │\n");
					printf(" ├─────┬────┤                                                   └──┤       ├──┘        \n");
					printf(" │     │    │                                                      │       │   \n");
					printf(" │     │    │                                                      ├───────┤  \n");
					printf(" │    ┏┘    │                                                      │       │\n");
					printf(" │    │    ┏┘                                                      │   │   │\n");
					printf(" │    │    │                                                       │   │   │\n");
					printf(" │    │    │                                                       │   │   │\n");
					printf(" └────┤    │                                                       │   │   │\n");
					printf("      └────┘                                                       │   │   │\n");
					printf("                                                                   └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "단단한 아르마딜로")) {
					printf("                    ┏─┓\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                   ┏┘ └┓\n");
					printf("                   │   │    \n");
					printf("                   │   │\n");
					printf("                  ┏┘   └┓\n");
					printf("                  │     │\n");
					printf("   ┏────────┓    ┏┘     └┓          ───                                      \n");
					printf("   │        │    └┓     ┏┘                ───                                        \n");
					printf("   │      ㅅ│     └─┓ ┏─┘                  ───                                      \n");
					printf("   │        │     ┏─┴─┴─┓               ───                                          \n");
					printf("   ├────────┤     └─┬─┬─┘       ───                                            \n");
					printf("  ┏┘        └───────┼─┤              ───                                     \n");
					printf("  │                 │ │                        ───                                \n");
					printf(" ┏┘     ─────┬──────┴─┘          ───                                    \n");
					printf(" │          ┏┘                             ───                                         \n");
					printf(" │          │                                   ───                                   \n");
					printf(" │          │                                                                   \n");
					printf(" │          │                                                      \n");
					printf(" ├─────┬────┤                                                    ┏─┘             └─┓\n");
					printf(" │     │    │                                                    │                 └─┓\n");
					printf(" │     │    │                                                   ┏┘                   └─┓\n");
					printf(" │    ┏┘    │                                                 ┏─┘   ㅅ                 └─┓\n");
					printf(" │    │    ┏┘                                                 └┓                       ┏─┘\n");
					printf(" │    │    │                                                   │                     ┏─┘\n");
					printf(" │    │    │                                                   └─┓                 ┏─┘\n");
					printf(" └────┤    │                                                     └───┓┏ ┓┏───┓┏──┓┏┘                     \n");
					printf("      └────┘                                                         ││ ││   ││  ││              \n");
					printf("                                                                     └┘ └┘   └┘  └┘              \n");
				}
				else if (!strcmp(monster.name, "죽창부대")) {
					printf("                    ┏─┓\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                   ┏┘ └┓\n");
					printf("                   │   │    \n");
					printf("                   │   │\n");
					printf("                  ┏┘   └┓\n");
					printf("                  │     │\n");
					printf("   ┏────────┓    ┏┘     └┓                                                             ┏──────┓            \n");
					printf("   │        │    └┓     ┏┘                                                            ┏┘      └┓           \n");
					printf("   │      ㅅ│     └─┓ ┏─┘                                                             │ └┘  └┘ │         \n");
					printf("   │        │     ┏─┴─┴─┓                                                             │        │        \n");
					printf("   ├────────┤     └─┬─┬─┘                                                             │  ┏──┓  │           \n");
					printf("  ┏┘        └───────┼─┤                                                               ├────────┤           \n");
					printf("  │                 │ │                                                          ┏────┘        └─────┓      \n");
					printf(" ┏┘     ─────┬──────┴─┘        <::::::::::::::::::{}xxx)=(?°                    └──┬──┓       ┏──┬──┘     \n");
					printf(" │          ┏┘                                                                      │  │       │  │               \n");
					printf(" │          │                                                                       │  │       │  │\n");
					printf(" │          │                                                                       │  │       │  │  \n");
					printf(" │          │                                                                       │  │       │  │  \n");
					printf(" ├─────┬────┤                                                                       └──┤       ├──┘        \n");
					printf(" │     │    │                                                                          │       │   \n");
					printf(" │     │    │                                                                          ├───────┤  \n");
					printf(" │    ┏┘    │                                                                          │       │\n");
					printf(" │    │    ┏┘                                                                          │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" └────┤    │                                                                           │   │   │\n");
					printf("      └────┘                                                                           │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "돈많은 고블린")) {
					printf("                    ┏─┓\n");
					printf("                    │ │\n");
					printf("                    │ │\n");

					printf("                   ┏┘ └┓\n");
					printf("                   │   │    \n");
					printf("                   │   │\n");
					printf("                  ┏┘   └┓\n");
					printf("                  │     │\n");
					printf("   ┏────────┓    ┏┘     └┓                                                           ┏──┓    ┏──┓     \n");
					printf("   │        │    └┓     ┏┘                                                           └┓ └┓  ┏┘ ┏┘      \n");
					printf("   │      ㅅ│     └─┓ ┏─┘                                                             │  |   | │          \n");
					printf("   │        │     ┏─┴─┴─┓                                                             │        │      \n");
					printf("   ├────────┤     └─┬─┬─┘       ┏─────────┓                                           │  └──┘  │     \n");
					printf("  ┏┘        └───────┼─┤         │         │                                           ├────────┤         \n");
					printf("  │                 │ │         │   동전  │                                      ┏────┘        └─────┓    \n");
					printf(" ┏┘     ─────┬──────┴─┘         │         │                                      └──┬──┓       ┏──┬──┘  \n");
					printf(" │          ┏┘                  │         │                                         │  │       │  └────────┓         \n");
					printf(" │          │                   └─────────┘                                         │  │       │           │\n");
					printf(" │          │                                                                       │  │       │ 돈주머니  │  \n");
					printf(" │          │                                                                       │  │       │           │\n");
					printf(" ├─────┬────┤                                                                       └──┤       ├───────────┘        \n");
					printf(" │     │    │                                                                          │       │   \n");
					printf(" │     │    │                                                                          ├───────┤  \n");
					printf(" │    ┏┘    │                                                                          │       │\n");
					printf(" │    │    ┏┘                                                                          │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" └────┤    │                                                                           │   │   │\n");
					printf("      └────┘                                                                           │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				firstperiodMonsterattack = secondperiodMonsterattack;
				Sleep(300);
			}
			char key = getch();
			if (key == ' ') {
				system("cls");
				double deal = (double)player->ad * (1 - (double)monster.armor / ((double)monster.armor + 100));
				printf("기본공격은 스페이스바, 스킬은 q,w,e,궁극기는 r을 눌러서 사용하세요, 로비로 돌아가려면 x키를 누르세요\n\n"); //플레이어가 기본 공격을 눌렀을 시
				printf("%d스테이지 %d라운드", *round / 10, *round % 10 + 1);
				if (*round % 10 + 1 == 10) printf("(보스 스테이지!)");
				printf("\n\n기본 공격을 하였습니다.\n");
				printf("가한 피해량:%lf", deal);
				monster.health -= deal;
				if (!strcmp(player->class, "탱커")) {
					monster.health -= player->health * (0.01 + 0.0001 * player->ap);
					printf("+%.0lf만큼의 피해량을 w스킬, 바미의 불씨로 더 가했습니다.\n", player->health * (0.01 + 0.0001 * player->ap));
				}
				printf("\n피흡량:%lf\n", deal * player->piheup / (player->piheup + 100));
				player->nowhealth += deal * player->piheup / (player->piheup + 100);
				printf("                                                                                    몬스터 이름:%s", monster.name);
				if (fainted) {
					printf("(기절함)");
				}
				printf("\n당신의 체력:%.0lf                                                                      몬스터의 체력:%.0lf\n\n", player->nowhealth, monster.health);
				int playerhealthratio = player->nowhealth / player->health * 20;
				printf("[");
				for (int i = 0; i < playerhealthratio; i++) {
					printf("=");
				}
				for (int i = 0; i < 20 - playerhealthratio; i++) {
					printf(" ");
				}
				printf("]");
				printf("                                                              ");
				int monsterhealthratio = monster.health / monster.maxhealth * 20;
				printf("[");
				for (int i = 0; i < monsterhealthratio; i++) {
					printf("=");
				}
				for (int i = 0; i < 20 - monsterhealthratio; i++) {
					printf(" ");
				}
				printf("]\n");
				if (!strcmp(player->class, "전사")) {
					if (clock() - lastTimeQ < 3000) {
						printf("q스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 10000) {
						printf("w스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 5000) {
						printf("e스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "마법사")) {
					if (clock() - lastTimeQ < 5000) {
						printf("q스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 3000) {
						printf("w스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 15000) {
						printf("e스킬이 %d초 남았습니다.\n", (15000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "탱커")) {
					if (clock() - lastTimeQ < 2000) {
						printf("q스킬이 %d초 남았습니다.\n", (2000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					printf("w스킬은 패시브 스킬입니다.\n");
					if (clock() - lastTimeE < 4000) {
						printf("e스킬이 %d초 남았습니다.\n", (4000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "수호기사")) {
					if (clock() - lastTimeQ < 7000) {
						printf("q스킬이 %d초 남았습니다.\n", (7000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 5000) {
						printf("w스킬이 %d초 남았습니다.\n", (50000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 10000) {
						printf("e스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				if (!strcmp(monster.name, "균형잡힌 기사")) {
					printf("                ┏────────┓                                                             ┏──────┓           \n");
					printf("                │        │                                                            ┏┘      └┓           \n");
					printf("                │      ㅅ│                                                            │  │  │  │           \n");
					printf("                │        │                                                            │  │  │  │          \n");
					printf("                ├────────┤                                                            │  │  │  │          \n");
					printf("               ┏┘        └───────┬─┓                                                  ├────────┤          \n");
					printf("               │                 │ │     ┏─┓ ┏──────────────────┓                ┏────┘        └─────┓    \n");
					printf("              ┏┘     ─────┬──────┴─┘    ┏┘ └┬┤                  └─────┓          └──┬──┓       ┏──┬──┘    \n");
					printf("              │          ┏┘             └┓ ┏┴┤                  ┏─────┘             │  │       │  │           \n");
					printf("              │          │               └─┘ └──────────────────┘                   │  │       │  │\n");
					printf("              │          │                                                          │  │       │  │  \n");
					printf("              │          │                                                          │  │       │  │\n");
					printf("              ├─────┬────┤                                                          └──┼───────┼──┘        \n");
					printf("              │     │    │                                                             │       │   \n");
					printf("              │     │    │                                                             ├───────┤  \n");
					printf("              │    ┏┘    │                                                             │       │\n");
					printf("              │    │    ┏┘                                                             │   │   │\n");
					printf("              │    │    │                                                              │   │   │\n");
					printf("              │    │    │                                                              │   │   │\n");
					printf("              └────┤    │                                                              │   │   │\n");
					printf("                   └────┘                                                              │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "체력돼지")) {
					printf("                ┏────────┓                                                                          ┏──────┓     \n");
					printf("                │        │                                                                         ┏┘      └┓      \n");
					printf("                │      ㅅ│                                                                         │  |   | │          \n");
					printf("                │        │                                                                         │ ┏─┬┬─┓ │      \n");
					printf("                ├────────┤                                                                         │ └────┘ │     \n");
					printf("               ┏┘        └───────┬─┓                                                               ├────────┤         \n");
					printf("               │                 │ │     ┏─┓ ┏──────────────────┓                             ┏────┘        └─────┓    \n");
					printf("              ┏┘     ─────┬──────┴─┘    ┏┘ └┬┤                  └─────┓                       └──┬──┓       ┏──┬──┘  \n");
					printf("              │          ┏┘             └┓ ┏┴┤                  ┏─────┘                          │  │       │  │\n");
					printf("              │          │               └─┘ └──────────────────┘                                │  │       │  │\n");
					printf("              │          │                                                                       │  │       │  │  \n");
					printf("              │          │                                                                       │  │       │  │\n");
					printf("              ├─────┬────┤                                                                       └──┤       ├──┘ \n");
					printf("              │     │    │                                                                          │       │   \n");
					printf("              │     │    │                                                                          ├───────┤  \n");
					printf("              │    ┏┘    │                                                                          │       │\n");
					printf("              │    │    ┏┘                                                                          │   │   │\n");
					printf("              │    │    │                                                                           │   │   │\n");
					printf("              │    │    │                                                                           │   │   │\n");
					printf("              └────┤    │                                                                           │   │   │\n");
					printf("                   └────┘                                                                           │   │   │\n");
					printf("                                                                                                    └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "단단한 아르마딜로")) {
					printf("                 ┏────────┓                                                             \n");
					printf("                 │        │                                                                     \n");
					printf("                 │      ㅅ│                                                                    \n");
					printf("                 │        │                                                                     \n");
					printf("                 ├────────┤                                                               \n");
					printf("               ┏┘        └───────┬─┓                                                   \n");
					printf("               │                 │ │     ┏─┓ ┏──────────────────┓    \n");
					printf("              ┏┘     ─────┬──────┴─┘    ┏┘ └┬┤                  └─────┓  \n");
					printf("              │          ┏┘             └┓ ┏┴┤                  ┏─────┘                                    \n");
					printf("              │          │               └─┘ └──────────────────┘          │││││││││││││││                \n");
					printf("              │          │                                                 │││││││││││││││             \n");
					printf("              │          │                                                 │││││││││││││││\n");
					printf("              ├─────┬────┤                                               ┏─┘             └─┓\n");
					printf("              │     │    │                                               │                 └─┓\n");
					printf("              │     │    │                                              ┏┘                   └─┓\n");
					printf("              │    ┏┘    │                                            ┏─┘   ㅅ                 └─┓\n");
					printf("              │    │    ┏┘                                            └┓                       ┏─┘\n");
					printf("              │    │    │                                              │                     ┏─┘\n");
					printf("              │    │    │                                              └─┓                 ┏─┘\n");
					printf("              └────┤    │                                                └───┓┏ ┓┏───┓┏──┓┏┘                     \n");
					printf("                   └────┘                                                    ││ ││   ││  ││              \n");
					printf("                                                                             └┘ └┘   └┘  └┘              \n");
				}
				else if (!strcmp(monster.name, "죽창부대")) {
					printf("             ┏────────┓                                                                ┏──────┓            ││\n");
					printf("             │        │                                                               ┏┘      └┓          ┏┘└┓ \n");
					printf("             │      ㅅ│                                                               │ └┘  └┘ │          └┓┏┘ \n");
					printf("             │        │                                                               │        │           ││\n");
					printf("             ├────────┤                                                               │  ┏──┓  │           ││\n");
					printf("            ┏┘        └───────┬─┓                                                     ├────────┤           ││\n");
					printf("            │                 │ │     ┏─┓ ┏──────────────────┓                   ┏────┘        └─────┓     ││ \n");
					printf("           ┏┘     ─────┬──────┴─┘    ┏┘ └┬┤                  └─────┓             └──┬──┓       ┏──┬──┘     ││ \n");
					printf("           │          ┏┘             └┓ ┏┴┤                  ┏─────┘                │  │       │  │        ││       \n");
					printf("           │          │               └─┘ └──────────────────┘                      │  │       │  └────────┼┘\n");
					printf("           │          │                                                             │  │       ├───────────┘  \n");
					printf("           │          │                                                             │  │       │  \n");
					printf("           ├─────┬────┤                                                             └──┤       │        \n");
					printf("           │     │    │                                                                │       │   \n");
					printf("           │     │    │                                                                ├───────┤  \n");
					printf("           │    ┏┘    │                                                                │       │\n");
					printf("           │    │    ┏┘                                                                │   │   │\n");
					printf("           │    │    │                                                                 │   │   │\n");
					printf("           │    │    │                                                                 │   │   │\n");
					printf("           └────┤    │                                                                 │   │   │\n");
					printf("                └────┘                                                                 │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "돈많은 고블린")) {
					printf("                ┏────────┓                                                           ┏──┓    ┏──┓     \n");
					printf("                │        │                                                           └┓ └┓  ┏┘ ┏┘      \n");
					printf("                │      ㅅ│                                                            │  |   | │          \n");
					printf("                │        │                                                            │        │      \n");
					printf("                ├────────┤                                                            │  └──┘  │     \n");
					printf("               ┏┘        └───────┬─┓     ┏─┓ ┏──────────────────┓                     ├────────┤         \n");
					printf("               │                 │ │    ┏┘ └┬┤                  └─────┓          ┏────┘        └─────┓    \n");
					printf("              ┏┘     ─────┬──────┴─┘    └┓ ┏┴┤                  ┏─────┘          └──┬──┓       ┏──┬──┘  \n");
					printf("              │          ┏┘              └─┘ └──────────────────┘                   │  │       │  └────────┓         \n");
					printf("              │          │                                                          │  │       │           │\n");
					printf("              │          │                                                          │  │       │ 돈주머니  │  \n");
					printf("              │          │                                                          │  │       │           │\n");
					printf("              ├─────┬────┤                                                          └──┤       ├───────────┘        \n");
					printf("              │     │    │                                                             │       │   \n");
					printf("              │     │    │                                                             ├───────┤  \n");
					printf("              │    ┏┘    │                                                             │       │\n");
					printf("              │    │    ┏┘                                                             │   │   │\n");
					printf("              │    │    │                                                              │   │   │\n");
					printf("              │    │    │                                                              │   │   │\n");
					printf("              └────┤    │                                                              │   │   │\n");
					printf("                   └────┘                                                              │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
			}
			clock_t secondperiodSkillQ = clock();
			clock_t secondperiodSkillW = clock();
			clock_t secondperiodSkillE = clock();
			clock_t secondperiodSkillR = clock();
			clock_t secondperiodSkillRE = clock();
			clock_t secondperiodFainted = clock();
			if (key != ' ') {                                                  //기본 공격을 누르지 않았다면 나가기나 스킬이었을 것이므로 지팡이를 사용하는 모션을 출력한다
				system("cls");
				if (*round % 10 + 1 == 10) {
					system("color 42");
				}
				printf("기본공격은 스페이스바, 스킬은 q,w,e,궁극기는 r을 눌러서 사용하세요, 로비로 돌아가려면 x키를 누르세요\n\n");
				printf("%d스테이지 %d라운드", *round / 10, *round % 10 + 1);
				if (*round % 10 + 1 == 10) printf("(보스 스테이지!)");
				printf("\n\n\n\n\n                                                                                   몬스터 이름:%s\n", monster.name);
				printf("당신의 체력:%.0lf                                                                      몬스터의 체력:%.0lf\n\n", player->nowhealth, monster.health);
				int playerhealthratio = player->nowhealth / player->health * 20;
				printf("[");
				for (int i = 0; i < playerhealthratio; i++) {
					printf("=");
				}
				for (int i = 0; i < 20 - playerhealthratio; i++) {
					printf(" ");
				}
				printf("]");
				printf("                                                              ");
				int monsterhealthratio = monster.health / monster.maxhealth * 20;
				printf("[");
				for (int i = 0; i < monsterhealthratio; i++) {
					printf("=");
				}
				for (int i = 0; i < 20 - monsterhealthratio; i++) {
					printf(" ");
				}
				printf("]\n");
				if (!strcmp(player->class, "전사")) {
					if (clock() - lastTimeQ < 3000) {
						printf("q스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 10000) {
						printf("w스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 5000) {
						printf("e스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "마법사")) {
					if (clock() - lastTimeQ < 5000) {
						printf("q스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 3000) {
						printf("w스킬이 %d초 남았습니다.\n", (3000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 15000) {
						printf("e스킬이 %d초 남았습니다.\n", (15000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "탱커")) {
					if (clock() - lastTimeQ < 2000) {
						printf("q스킬이 %d초 남았습니다.\n", (2000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					printf("w스킬은 패시브 스킬입니다.\n");
					if (clock() - lastTimeE < 4000) {
						printf("e스킬이 %d초 남았습니다.\n", (4000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				if (!strcmp(player->class, "수호기사")) {
					if (clock() - lastTimeQ < 7000) {
						printf("q스킬이 %d초 남았습니다.\n", (7000 - clock() + lastTimeQ) / 1000 + 1);
					}
					else printf("q스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeW < 5000) {
						printf("w스킬이 %d초 남았습니다.\n", (5000 - clock() + lastTimeW) / 1000 + 1);
					}
					else printf("w스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeE < 10000) {
						printf("e스킬이 %d초 남았습니다.\n", (10000 - clock() + lastTimeE) / 1000 + 1);
					}
					else printf("e스킬을 사용할 수 있습니다.\n");
					if (clock() - lastTimeR < 30000) {
						printf("r스킬이 %d초 남았습니다.\n", (30000 - clock() + lastTimeR) / 1000 + 1);
					}
					else printf("r스킬을 사용할 수 있습니다.\n");
				}
				printf("                                                                                    몬스터의 방어력:%d\n", monster.armor);
				printf("                                                                                    몬스터의 공격력:%d\n", monster.ad);
				printf("                                                                                    처치시 골드:%d\n", monster.money);
				if (!strcmp(monster.name, "균형잡힌 기사")) {
					printf("                   ┏───┓\n");
					printf("                   │   │\n");
					printf("                   └┬ ┬┘\n");
					printf("                    │ │\n");
					printf("                    │ │    \n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("   ┏────────┓       │ │                                                                ┏──────┓           ┏──┓\n");
					printf("   │        │       │ │                                                               ┏┘      └┓          │  │ \n");
					printf("   │      ㅅ│       │ │                                                               │  │  │  │          │  │ \n");
					printf("   │        │       │ │                                                               │  │  │  │          │  │\n");
					printf("   ├────────┤       │ │                                                               │  │  │  │          │  │\n");
					printf("  ┏┘        └───────┼─┤                                                               ├────────┤          │  │\n");
					printf("  │                 │ │                                                          ┏────┘        └─────┓   ┏│  │┓ \n");
					printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘   │    │ \n");
					printf(" │          ┏┘                                                                      │  │       │  │      └─┬┬─┘     \n");
					printf(" │          │                                                                       │  │       │  └────────┼┘\n");
					printf(" │          │                                                                       │  │       ├───────────┘  \n");
					printf(" │          │                                                                       │  │       │  \n");
					printf(" ├─────┬────┤                                                                       └──┤       │        \n");
					printf(" │     │    │                                                                          │       │   \n");
					printf(" │     │    │                                                                          ├───────┤  \n");
					printf(" │    ┏┘    │                                                                          │       │\n");
					printf(" │    │    ┏┘                                                                          │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" └────┤    │                                                                           │   │   │\n");
					printf("      └────┘                                                                           │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "체력돼지")) {
					printf("                   ┏───┓\n");
					printf("                   │   │\n");
					printf("                   └┬ ┬┘\n");
					printf("                    │ │\n");
					printf("                    │ │    \n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("   ┏────────┓       ┃ ┃                                                                ┏──────┓     \n");
					printf("   │        │       ┃ ┃                                                               ┏┘      └┓      \n");
					printf("   │      ㅅ│       ┃ ┃                                                               │  |   | │          \n");
					printf("   │        │       ┃ ┃                                                               │ ┏─┬┬─┓ │      \n");
					printf("   ├────────┤       ┃ ┃                                                               │ └────┘ │     \n");
					printf("  ┏┘        └───────┼─┤                                                               ├────────┤         \n");
					printf("  │                 │ │                                                          ┏────┘        └─────┓    \n");
					printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘  \n");
					printf(" │          ┏┘                                                                      │  │       │  │         \n");
					printf(" │          │                                                                       │  │       │  │\n");
					printf(" │          │                                                                       │  │       │  │  \n");
					printf(" │          │                                                                       │  │       │  │\n");
					printf(" ├─────┬────┤                                                                       └──┤       ├──┘        \n");
					printf(" │     │    │                                                                          │       │   \n");
					printf(" │     │    │                                                                          ├───────┤  \n");
					printf(" │    ┏┘    │                                                                          │       │\n");
					printf(" │    │    ┏┘                                                                          │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" └────┤    │                                                                           │   │   │\n");
					printf("      └────┘                                                                           │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "단단한 아르마딜로")) {
					printf("                   ┏───┓\n");
					printf("                   │   │\n");
					printf("                   └┬ ┬┘\n");
					printf("                    │ │\n");
					printf("                    │ │    \n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("   ┏────────┓       │ │                                                \n");
					printf("   │        │       │ │                                                           \n");
					printf("   │      ㅅ│       │ │                                                          \n");
					printf("   │        │       │ │                                                           \n");
					printf("   ├────────┤       │ │                                                     \n");
					printf("  ┏┘        └───────┼─┤                                                   \n");
					printf("  │                 │ │                                                        \n");
					printf(" ┏┘     ─────┬──────┴─┘                                              \n");
					printf(" │          ┏┘                                                                      \n");
					printf(" │          │                                                      │││││││││││││││                \n");
					printf(" │          │                                                      │││││││││││││││             \n");
					printf(" │          │                                                      │││││││││││││││\n");
					printf(" ├─────┬────┤                                                    ┏─┘             └─┓\n");
					printf(" │     │    │                                                    │                 └─┓\n");
					printf(" │     │    │                                                   ┏┘                   └─┓\n");
					printf(" │    ┏┘    │                                                 ┏─┘   ㅅ                 └─┓\n");
					printf(" │    │    ┏┘                                                 └┓                       ┏─┘\n");
					printf(" │    │    │                                                   │                     ┏─┘\n");
					printf(" │    │    │                                                   └─┓                 ┏─┘\n");
					printf(" └────┤    │                                                     └───┓┏ ┓┏───┓┏──┓┏┘                     \n");
					printf("      └────┘                                                         ││ ││   ││  ││              \n");
					printf("                                                                     └┘ └┘   └┘  └┘              \n");
				}
				else if (!strcmp(monster.name, "죽창부대")) {
					printf("                   ┏───┓\n");
					printf("                   │   │\n");
					printf("                   └┬ ┬┘\n");
					printf("                    │ │\n");
					printf("                    │ │    \n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("   ┏────────┓       │ │                                                                ┏──────┓            ││\n");
					printf("   │        │       │ │                                                               ┏┘      └┓          ┏┘└┓ \n");
					printf("   │      ㅅ│       │ │                                                               │ └┘  └┘ │          └┓┏┘ \n");
					printf("   │        │       │ │                                                               │        │           ││\n");
					printf("   ├────────┤       │ │                                                               │  ┏──┓  │           ││\n");
					printf("  ┏┘        └───────┼─┤                                                               ├────────┤           ││\n");
					printf("  │                 │ │                                                          ┏────┘        └─────┓     ││ \n");
					printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘     ││ \n");
					printf(" │          ┏┘                                                                      │  │       │  │        ││       \n");
					printf(" │          │                                                                       │  │       │  └────────┼┘\n");
					printf(" │          │                                                                       │  │       ├───────────┘  \n");
					printf(" │          │                                                                       │  │       │  \n");
					printf(" ├─────┬────┤                                                                       └──┤       │        \n");
					printf(" │     │    │                                                                          │       │   \n");
					printf(" │     │    │                                                                          ├───────┤  \n");
					printf(" │    ┏┘    │                                                                          │       │\n");
					printf(" │    │    ┏┘                                                                          │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" └────┤    │                                                                           │   │   │\n");
					printf("      └────┘                                                                           │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				else if (!strcmp(monster.name, "돈많은 고블린")) {
					printf("                   ┏───┓\n");
					printf("                   │   │\n");
					printf("                   └┬ ┬┘\n");
					printf("                    │ │\n");
					printf("                    │ │    \n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("                    │ │\n");
					printf("   ┏────────┓       │ │                                                              ┏──┓    ┏──┓     \n");
					printf("   │        │       │ │                                                              └┓ └┓  ┏┘ ┏┘      \n");
					printf("   │      ㅅ│       │ │                                                               │  |   | │          \n");
					printf("   │        │       │ │                                                               │        │      \n");
					printf("   ├────────┤       │ │                                                               │  └──┘  │     \n");
					printf("  ┏┘        └───────┼─┤                                                               ├────────┤         \n");
					printf("  │                 │ │                                                          ┏────┘        └─────┓    \n");
					printf(" ┏┘     ─────┬──────┴─┘                                                          └──┬──┓       ┏──┬──┘  \n");
					printf(" │          ┏┘                                                                      │  │       │  └────────┓         \n");
					printf(" │          │                                                                       │  │       │           │\n");
					printf(" │          │                                                                       │  │       │ 돈주머니  │  \n");
					printf(" │          │                                                                       │  │       │           │\n");
					printf(" ├─────┬────┤                                                                       └──┤       ├───────────┘        \n");
					printf(" │     │    │                                                                          │       │   \n");
					printf(" │     │    │                                                                          ├───────┤  \n");
					printf(" │    ┏┘    │                                                                          │       │\n");
					printf(" │    │    ┏┘                                                                          │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" │    │    │                                                                           │   │   │\n");
					printf(" └────┤    │                                                                           │   │   │\n");
					printf("      └────┘                                                                           │   │   │\n");
					printf("                                                                                       └───┴───┘\n");
				}
				if (!strcmp(player->class, "전사")) {
					if (key == 'q' && clock() - lastTimeQ < 3000) {                                                                      //스킬별로 구성한다
						printf("q스킬이 쿨타임입니다!\n");
					}
					else if (key == 'q') {
						printf("q스킬, 도끼 던지기를 사용했습니다.\n");
						printf("%.0lf의 물리 피해를 입혔습니다.\n", 100 * (1 + player->ap) * (1 - (double)monster.armor / ((double)monster.armor + 100)));
						monster.health -= 100 * (1 + player->ap) * (1 - (double)monster.armor / ((double)monster.armor + 100));
						lastTimeQ = clock();
					}
					if (key == 'w' && clock() - lastTimeW < 10000) {
						printf("w스킬이 쿨타임입니다!\n");
					}
					else if (key == 'w') {
						printf("w스킬, 피의 맛을 사용했습니다, 10초 동안 피흡량이 증가합니다.\n");                   //이런 지속되는 스킬의 경우 시작시간을 저장하고 몬스터의 공격과 똑같은 방법으로 스킬 사용으로부터 일정 시간이 지나면 원래 값으로 돌아가게 한다.
						firstperiodSkillW = clock();
						skillW = 1;
						player->piheup *= (2 * (1 + player->ap));
						lastTimeW = clock();
					}
					if (key == 'e' && clock() - lastTimeE < 5000) {
						printf("e스킬이 쿨타임입니다!\n");
					}
					else if (key == 'e') {
						printf("e스킬, 무모한 강타를 사용했습니다.\n");
						monster.health -= 100 * (1 + player->ap);
						printf("%lld의 고정 피해를 입혔습니다.\n", 100 * player->ap);
						lastTimeE = clock();
					}
					if (key == 'r' && clock() - lastTimeR < 30000) {
						printf("r스킬이 쿨타임입니다!\n");
					}
					else if (key == 'r') {
						lastTimeR = clock();
						printf("r스킬, 저돌맹진을 사용하였습니다, 10초동안 공격력과 방어력이 증가합니다.\n");
						firstperiodSkillR = clock();
						skillR = 1;
						player->ad *= 5 * (1 + player->ap);
						player->armor *= 5 * (1 + player->ap);
					}
				}
				if (!strcmp(player->class, "마법사")) {
					if (key == 'q' && clock() - lastTimeQ < 5000) {
						printf("q스킬이 쿨타임입니다!\n");
					}
					else if (key == 'q') {
						lastTimeQ = clock();
						printf("q스킬, 악의의 인장을 사용했습니다.\n");                                     //1회성이 아닌 2회성 스킬로 한번 사용하면 skillQ라는 변수를 1로바꾸어서 다음 스킬을 사용할 때 skillQ가 1이라면 추가 데미지가 들어가는 방식으로 구현
						printf("%lld의 피해를 입혔습니다.\n", 100 * (1 + player->ap));
						monster.health -= 100 * (1 + player->ap);
						printf("상대에게 표식이 남습니다.\n");
						if (skillQ == 1) {
							printf("악의의 인장이 터집니다.\n");
							printf("%lld의 피해를 입혔습니다.", 200 * (1 + player->ap));
							monster.health -= 200 * (1 + player->ap);
						}
						if (skillRQ == 1) {
							printf("악의의 인장(강화)이 터집니다.\n");
							printf("%lld의 피해를 입혔습니다.", 300 * (1 + player->ap));
							monster.health -= 300 * (1 + player->ap);
						}
						int skillQ = 1;
					}
					if (key == 'w' && clock() - lastTimeW < 3000) {
						printf("w스킬이 쿨타임입니다!\n");
					}
					else if (key == 'w') {
						lastTimeW = clock();
						printf("w스킬, 왜곡을 사용했습니다.\n");
						printf("%lld의 피해를 입혔습니다.", 150 * (1 + player->ap));
						monster.health -= 150 * (1 + player->ap);
						if (skillQ == 1) {
							printf("악의의 인장이 터집니다.\n");
							printf("%lld의 피해를 입혔습니다.", 200 * (1 + player->ap));
							monster.health -= 200 * (1 + player->ap);
						}
						if (skillRQ == 1) {
							printf("악의의 인장(강화)이 터집니다.\n");
							printf("%lld의 피해를 입혔습니다.", 300 * (1 + player->ap));
							monster.health -= 300 * (1 + player->ap);
						}
					}
					if (key == 'e' && clock() - lastTimeE < 15000) {
						printf("e스킬이 쿨타임입니다!\n");
					}
					else if (key == 'e') {
						lastTimeE = clock();
						printf("e스킬, 사슬 연결을 사용했습니다.\n");
						firstperiodSkillE = clock();
						skillE = 1;
						printf("%lld의 피해를 입혔습니다.", 100 * (1 + player->ap));
						monster.health -= 100 * (1 + player->ap);
						if (skillQ == 1) {
							printf("악의의 인장이 터집니다.\n");
							printf("%lld의 피해를 입혔습니다.", 200 * (1 + player->ap));
							monster.health -= 200 * (1 + player->ap);
						}
						if (skillRQ == 1) {
							printf("악의의 인장(강화)이 터집니다.\n");
							printf("%lld의 피해를 입혔습니다.", 300 * (1 + player->ap));
							monster.health -= 300 * (1 + player->ap);
						}
					}
					if (key == 'r' && clock() - lastTimeR < 30000) {
						printf("r스킬이 쿨타임입니다!\n");
					}
					else if (key == 'r') {
						lastTimeR = clock();
						printf("r스킬, 모방을 사용했습니다.\n");
						while (1) {
							printf("복제할 스킬을 입력하세요.\n");
							char copy = getch();
							if (copy == 'q') {
								printf("악의의 인장(강화)를 사용했습니다.\n");
								printf("%lld의 피해를 입혔습니다.\n", 200 * (1 + player->ap));
								monster.health -= 200 * (1 + player->ap);
								printf("몬스터에게 표식이 남습니다.\n");
								skillRQ = 1;
								break;
							}
							else if (copy == 'w') {
								printf("왜곡(강화)를 사용했습니다.\n");
								printf("%lld의 피해를 입혔습니다.\n", 200 * (1 + player->ap));
								monster.health -= 200 * (1 + player->ap);
								break;
							}
							else if (copy == 'e') {
								printf("e스킬, 사슬 연결(강화)을 사용했습니다.\n");
								firstperiodSkillRE = clock();
								skillRE = 1;
								printf("%lld의 피해를 입혔습니다.", 300 * (1 + player->ap));
								monster.health -= 300 * (1 + player->ap);
								break;
							}
							else printf("q, w, e 중에 하나를 입력하세요\n");
						}
						if (skillQ == 1) {
							printf("악의의 인장이 터집니다.\n");
							printf("%lld의 데미지를 입혔습니다.", 200 * (1 + player->ap));
							monster.health -= 200 * (1 + player->ap);
						}
						if (skillRQ == 1) {
							printf("악의의 인장(강화)이 터집니다.\n");
							printf("%lld의 데미지를 입혔습니다.", 300 * (1 + player->ap));
							monster.health -= 300 * (1 + player->ap);
						}
					}
					if (secondperiodSkillE - firstperiodSkillE > 3000 && skillE) {
						printf("사슬이 완성되었습니다!\n");
						printf("%lld의 피해를 입혔습니다.\n", 200 * (1 + player->ap));
						monster.health -= 200 * (1 + player->ap);
						printf("상대가 기절합니다.\n");
						firstperiodFainted = clock();
						fainted = 1;
						skillE = 0;
						monster.ad = 0;
					}
					if (secondperiodSkillRE - firstperiodSkillRE > 3000 && skillRE) {
						printf("사슬(강화)이 완성되었습니다!\n");
						printf("%lld의 피해를 입혔습니다.\n", 400 * (1 + player->ap));
						monster.health -= 400 * (1 + player->ap);
						printf("상대가 기절합니다.\n");
						firstperiodFainted = clock();
						fainted = 1;
						monster.ad = 0;
						skillRE = 0;
					}
				}
				if (!strcmp(player->class, "탱커")) {
					if (key == 'q' && clock() - lastTimeQ < 2000) {
						printf("q스킬이 쿨타임입니다!\n");
					}
					else if (key == 'q') {
						lastTimeQ = clock();
						printf("q스킬, 오염된 대형 식칼을 사용했습니다.\n");
						monster.health *= (0.9 - 0.0001 * player->ap);
						printf("%.0lf의 피해를 입혔습니다.\n", (0.9 - 0.0001 * player->ap) * monster.health);
					}
					if (key == 'e' && clock() - lastTimeE < 4000) {
						printf("e스킬이 쿨타임입니다!\n");
					}
					else if (key == 'e') {
						lastTimeE = clock();
						printf("e스킬, 피학증을 사용했습니다.\n");
						monster.health -= player->health * (0.5 + 0.01 * player->ap);
						printf("%.0lf의 피해를 입혔습니다.\n", (player->health - player->nowhealth) * (0.5 + 0.1 * player->ap));
					}
					if (key == 'r' && clock() - lastTimeR < 30000) {
						printf("r스킬이 쿨타임입니다!\n");
					}
					else if (key == 'r') {
						lastTimeR = clock();
						printf("r스킬, 워모그를 사용했습니다.\n");
						player->nowhealth += player->health * 0.5;
						printf("%.0lf만큼의 체력을 회복했습니다.", player->nowhealth += player->health * 0.5);
					}
				}
				if (!strcmp(player->class, "수호기사")) {
					if (key == 'q' && clock() - lastTimeQ < 7000) {
						printf("q스킬이 쿨타임입니다!\n");
					}
					else if (key == 'q') {
						lastTimeQ = clock();
						printf("q스킬, 머리가 띵!을 사용했습니다.\n");
						printf("상대가 기절합니다.\n");
						firstperiodFainted = clock();
						fainted = 1;
						monster.ad = 0;
					}
					if (key == 'w' && clock() - lastTimeW < 5000) {
						printf("w스킬이 쿨타임입니다!\n");
					}
					else if (key == 'w') {
						lastTimeW = clock();
						firstperiodSkillW = clock();
						printf("w스킬, 단단해지기!를 사용했습니다.\n");
						player->armor *= (3 + player->ap);
						skillW = 1;
					}
					if (key == 'e' && clock() - lastTimeE < 10000) {
						printf("e스킬이 쿨타임입니다!\n");
					}
					else if (key == 'e') {
						lastTimeE = clock();
						printf("e스킬, 자힐의를 사용했습니다.\n");
						player->nowhealth += 100 * (1 + player->ap);
					}
					if (key == 'r' && clock() - lastTimeR < 30000) {
						printf("r스킬이 쿨타임입니다!\n");
					}
					else if (key == 'r') {
						lastTimeR = clock();
						printf("r스킬, 신의 은총을 사용했습니다.\n");
						if (monster.ad < 10 * (0.01 * player->ap + 1)) monster.ad = 0;
						else monster.ad -= 10 * (0.01 * player->ap + 1);
					}
				}
				Sleep(300);
			}
			if (fainted && secondperiodFainted - firstperiodFainted > 3000) {           //기절을 표현하기 위해서 몬스터의 공격력을 0으로 바꿈 그리고 일정 시간이 지나면 돌아옴
				monster.ad = TmpMonsterAd;
				fainted = 0;
			}
			if (!strcmp(player->class, "전사")) {
				if (secondperiodSkillW - firstperiodSkillW > 10000 && skillW) {
					player->piheup = WTmpPiheup;
					skillW = 0;
				}
				if (secondperiodSkillR - firstperiodSkillR > 10000 && skillR) {
					player->ad = RTmpAd;
					player->armor = RTmpArmor;
					skillR = 0;
				}
			}
			if (!strcmp(player->class, "수호기사")) {
				if (secondperiodSkillW - firstperiodSkillW > 10000 && skillW) {
					player->armor = RTmpArmor;
					skillW = 0;
				}
			}
			if (key == 'x') {
				return 0;
			}
			if (player->nowhealth <= 0) {                           //체력이 0이거나 이보다 작을 경우 로비로 강제 소환
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				printf("당신은 죽었습니다\n");
				printf("3초 후 로비로 돌아갑니다.");
				player->ad = RTmpAd;
				player->armor = RTmpArmor;
				Sleep(3000);
				return 0;
			}
			while (1) {                                            //기본 공격키를 꾹누르고 있을 경우 알아서 공격되는 것을 막기 위함
				if (GetAsyncKeyState(0x20)) {
					Sleep(1);
				}
				else break;
			}
		}
		if (*round % 10 + 1 == 10) {
			system("color F0");
		}
		system("cls");
		printf("적을 처치했습니다!\n");
		printf("%d원을 벌었습니다!\n", monster.money);
		*round = *round + 1;
		player->gold += monster.money;
		Sleep(500);
	}
}
void opentooltip(struct player* player) {
	system("cls");
	printf("로비로 돌아가려면 아무 키나 입력하세요\n\n");
	printf("%s님의 직업:%s\n", player->name, player->class);
	printf("주의: 스킬의 피해량은 당신의 주문력에만 비례합니다.\n\n");
	if (!strcmp(player->class, "전사")) {
		printf("q스킬:도끼 던지기:적에게 일정량의 피해를 줍니다.\n\n");
		printf("w스킬:피의 맛:일정 시간 동안 적에게 가한 피해의 일부를 흡수합니다.\n\n");
		printf("e스킬:무모한 강타:적에게 방어력을 무시하는 고정피해를 줍니다.\n\n");
		printf("r스킬:저돌맹진:방어력과 공격력이 일시적으로 크게 증가합니다.\n\n");
		printf("q스킬의 쿨타임은 3초, w스킬의 쿨타임은 10초, e스킬의 쿨타임은 5초, 궁극기의 쿨타임은 30초입니다.\n\n");
	}
	if (!strcmp(player->class, "마법사")) {
		printf("q스킬:악의의 인장:적에게 일정량의 피해를 주고 다음 적중하는 스킬의 피해량이 증가합니다.\n\n");
		printf("w스킬:왜곡:적에게 피해를 주고 다음 공격을 회피합니다.\n\n");
		printf("e스킬:사슬 연결 상대에게 피해를 주고 상대를 기절시킵니다..\n\n");
		printf("r스킬:모방:q,w,e스킬 중에서 하나의 스킬을 강화해서 한 번 시전합니다\n\n");
		printf("q스킬의 쿨타임은 5초, w스킬의 쿨타임은 3초, e스킬의 쿨타임은 15초, 궁극기의 쿨타임은 30초입니다.\n\n");
	}
	if (!strcmp(player->class, "탱커")) {
		printf("q스킬:오염된 대형 식칼:적에게 체력에 비례한 피해를 줍니다.\n\n");
		printf("w스킬(패시브):바미의 불씨:상대에게 계속해서 피해를 줍니다.\n\n");
		printf("e스킬:피학증:잃은 체력에 비례한 피해를 줍니다.\n\n");
		printf("r스킬:워모그:체력을 회복합니다\n\n");
		printf("q스킬의 쿨타임은2초, w스킬은 패시브 스킬, e스킬의 쿨타임은 4초, 궁극기의 쿨타임은 30초입니다.\n\n");
	}
	if (!strcmp(player->class, "수호기사")) {
		printf("q스킬:머리가 띵!: 적을 기절시킵니다.\n\n");
		printf("w스킬:단단해지기!:일정 시간동안 방어력이 증가합니다.\n\n");
		printf("e스킬:자힐의:체력을 회복합니다.\n\n");
		printf("r스킬:쇄약:상대하고 있는 몬스터가 영구히 공격력이 감소합니다.\n\n");
		printf("q스킬의 쿨타임은 7초, w스킬의 쿨타임은 5초, e스킬의 쿨타임은 10초, 궁극기의 쿨타임은 30초입니다.\n\n");
	}
	printf("당신의 공격력:%lld\n", player->ad);
	printf("당신의 주문력:%lld\n", player->ap);
	printf("당신의 체력:%.0lf\n", player->health);
	printf("당신의 방어력:%lld\n", player->armor);
	printf("당신의 소지금:%lld\n", player->gold);
	printf("당신의 체력흡수:%lld\n", player->piheup);
	char key = getch();                                                                  //아무 키나 입력하면 함수가 종료됨
}
void openroby(struct player* player, int round) {
	player->nowhealth = player->health;
	printf("                           │                             [ %s님 안녕하세요! ]", player->name);              //플레이어가 입력한 이름의 길이가 다르므로 이에 맞추어 공백을 출력해서 틀의 모양이 어긋나지 않게함
	for (int i = 0; i < 73 - strlen(player->name); i++) {
		printf(" ");
	}
	printf("│\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           │                             [ rpg 게임에 오신 것을 환영합니다 ]                                                        ┃\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           │");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 241);
	printf("                             전투장[x키] {현재라운드:%d}", round + 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	int tmp = round;
	int jarisu = 0;                                              //현재 라운드가 변하므로 이 자릿수에 맞추어 공백을 출력해서 틀의 모양이 어긋나지 않게함
	if (tmp == 0) {
		jarisu = 1;
	}
	while (tmp != 0) {
		tmp /= 10;
		jarisu++;
	}
	for (int i = 0; i < 66 - jarisu; i++) {
		printf(" ");
	}
	printf("┃\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           ┃");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 242);
	printf("                             설명창[t키]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("                                                                                ┃\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           ┃");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 243);
	printf("                             상점[k키] ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("                                                                                 ┃\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           ┃");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	printf("                             1라운드로 돌아가기(돈과 스탯은 그대로 유지)[r키]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("                                           ┃\n");
	printf("                           │                                                                                                                        ┃\n");
	printf("                           └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘");
}
void openmarket(struct player* player) {
	if (player->gold < 10000) {
		while (1) {
			system("cls");
			printf("무너져가는 상점에 오신 것을 환영합니다!\n\n\n");
			printf("상점 주인:우리 가게에 오다니, 자네도 어지간히 거지구만\n\n\n");
			printf("당신의 소지금:%lld\n\n", player->gold);
			printf("a키를 눌러서 100원의 커튼을 구매해서 방어력을 올리세요\n\n");
			printf("b키를 눌러서 100원의 썩은 고기를 구매해서 체력을 올리세요\n\n");
			printf("c키를 눌러서 100원의 이쑤시개를 구매해서 공격력을 높이세요\n\n");
			printf("d키를 눌러서 100원의 깨진 유리구슬을 구매해서 주문력을 높이세요\n\n");
			printf("e키를 눌러서 100원의 개털을 구매해서 피흡량을 높이세요\n\n");
			printf("f키를 누르면 로비로 돌아갑니다\n\n");
			printf("10000원을 모으면 허름한 상점이 열립니다!");
			char buy = getch();
			if (player->gold < 100) {
				system("cls");
				printf("상점 주인: 어딜 그지가 사기를 치려고!, 당장 나가!!\n");
				printf("쫓겨났습니다");
				Sleep(3000);
				break;
			}
			if (buy == 'a') {
				player->gold -= 100;
				player->armor += 1;
			}
			if (buy == 'b') {
				player->gold -= 100;
				player->health += 50;
			}
			if (buy == 'c') {
				player->gold -= 100;
				player->ad += 1;
			}
			if (buy == 'd') {
				player->gold -= 100;
				player->ap += 1;
			}
			if (buy == 'e') {
				player->gold -= 100;
				player->piheup += 1;
			}
			if (buy == 'f') {
				return 0;
			}
		}
	}
	else if (player->gold < 1000000) {
		while (1) {
			system("cls");
			printf("허름한 상점에 오신 것을 환영합니다!\n\n\n");
			printf("상점 주인: 그래도 우리 가게가 저 옆에 폐허보단 훨씬 낫지, 허허허\n\n");
			printf("당신의 소지금:%lld\n\n", player->gold);
			printf("a키를 눌러서 10000원의 낡은 가죽을 구매해서 방어력을 올리세요\n\n");
			printf("b키를 눌러서 10000원의 신선한 당근을 구매해서 체력을 올리세요\n\n");
			printf("c키를 눌러서 10000원의 과도를 구매해서 공격력을 높이세요\n\n");
			printf("d키를 눌러서 10000원의 굴러다니는 지팡이를 구매해서 주문력을 높이세요\n\n");
			printf("e키를 눌러서 10000원의 흡혈의 낫을 구매해서 피흡량을 높이세요\n\n");
			printf("10000원을 모으면 평범한 상점이 열립니다!");
			char buy = getch();
			if (player->gold < 10000) {
				system("cls");
				printf("상점 주인: 어딜 그지가 사기를 치려고!, 당장 나가!!\n");
				printf("쫓겨났습니다");
				Sleep(3000);
				break;
			}
			if (buy == 'a') {
				player->gold -= 10000;
				player->armor += 120;
			}
			if (buy == 'b') {
				player->gold -= 10000;
				player->health += 6000;
			}
			if (buy == 'c') {
				player->gold -= 10000;
				player->ad += 120;
			}
			if (buy == 'd') {
				player->gold -= 10000;
				player->ap += 120;
			}
			if (buy == 'e') {
				player->gold -= 10000;
				player->piheup += 120;
			}
			if (buy == 'f') {
				return 0;
			}
		}
	}
	else if (player->gold < 100000000) {
		while (1) {
			system("cls");
			printf("평범한 상점에 오신 것을 환영합니다!\n\n\n");
			printf("어서오세요 손님\n\n");
			printf("당신의 소지금:%lld\n\n", player->gold);
			printf("a키를 눌러서 1000000원의 철제 갑옷을 구매해서 방어력을 올리세요\n\n");
			printf("b키를 눌러서 1000000원의 삼겹살을 구매해서 체력을 올리세요\n\n");
			printf("c키를 눌러서 1000000원의 장미칼을 구매해서 공격력을 높이세요\n\n");
			printf("d키를 눌러서 1000000원의 마법사의 지팡이를 구매해서 주문력을 높이세요\n\n");
			printf("e키를 눌러서 1000000원의 흡혈의 낫을 구매해서 피흡량을 높이세요\n\n");
			printf("10000원을 모으면 고급 상점이 열립니다!");
			char buy = getch();
			if (player->gold < 1000000) {
				system("cls");
				printf("상점 주인: 어딜 그지가 사기를 치려고!, 당장 나가!!\n");
				printf("쫓겨났습니다");
				Sleep(3000);
			}
			if (buy == 'a') {
				player->gold -= 1000000;
				player->armor += 14000;
			}
			if (buy == 'b') {
				player->gold -= 1000000;
				player->health += 100000;
			}
			if (buy == 'c') {
				player->gold -= 1000000;
				player->ad += 14000;
			}
			if (buy == 'd') {
				player->gold -= 1000000;
				player->ap += 14000;
			}
			if (buy == 'e') {
				player->gold -= 1000000;
				player->piheup += 14000;
			}
			if (buy == 'f') {
				return 0;
			}
		}
	}
	else if (player->gold < 10000000000) {
		while (1) {
			system("cls");
			printf("고급 상점에 오신 것을 환영합니다!\n\n\n");
			printf("안녕하세요, 고급 상점입니다. 무엇을 도와드릴까요\n\n");
			printf("당신의 소지금:%lld\n\n", player->gold);
			printf("a키를 눌러서 100000000원의 다이아몬드 흉갑을 구매해서 방어력을 올리세요\n\n");
			printf("b키를 눌러서 100000000원의 푸아그라를 구매해서 체력을 올리세요\n\n");
			printf("c키를 눌러서 100000000원의 아다만티움 검을 구매해서 공격력을 높이세요\n\n");
			printf("d키를 눌러서 100000000원의 현자의 로브를 구매해서 주문력을 높이세요\n\n");
			printf("e키를 눌러서 100000000원의 불멸의 철갑궁을 구매해서 피흡량을 높이세요\n\n");
			printf("10000000000원을 모으면 신의 창고가 열립니다!");
			char buy = getch();
			if (player->gold < 100000000) {
				system("cls");
				printf("상점 주인: 어딜 그지가 사기를 치려고!, 당장 나가!!\n");
				printf("쫓겨났습니다");
				Sleep(3000);
				break;
			}
			if (buy == 'a') {
				player->gold -= 100000000;
				player->armor += 1600000;
			}
			if (buy == 'b') {
				player->gold -= 100000000;
				player->health += 150000000;
			}
			if (buy == 'c') {
				player->gold -= 100000000;
				player->ad += 1600000;
			}
			if (buy == 'd') {
				player->gold -= 100000000;
				player->ap += 1600000;
			}
			if (buy == 'e') {
				player->gold -= 100000000;
				player->piheup += 1600000;
			}
			if (buy == 'f') {
				return 0;
			}
		}
	}
	else {
		while (1) {
			system("cls");
			printf("신의 창고에 오신 것을 환영합니다!\n\n\n");
			printf("여기까지 오는 친구라니 굉장하구만\n\n");
			printf("당신의 소지금:%lld\n", player->gold);
			printf("a키를 눌러서 10000000000원의 아테나의 방패를 구매해서 방어력을 올리세요\n\n");
			printf("b키를 눌러서 10000000000원의 넥타르를 구매해서 체력을 올리세요\n\n");
			printf("c키를 눌러서 10000000000원의 아레스의 검을 구매해서 공격력을 높이세요\n\n");
			printf("d키를 눌러서 10000000000원의 헤르메스의 지팡이를 구매해서 주문력을 높이세요\n\n");
			printf("e키를 눌러서 1000000000000원의 모든 것의 끝(엔딩)을 구매하세요\n\n");
			char buy = getch();
			if (player->gold < 10000000000) {
				system("cls");
				printf("상점 주인: 어딜 그지가 사기를 치려고!, 당장 나가!!\n");
				printf("쫓겨났습니다");
				Sleep(3000);
				break;
			}
			if (buy == 'a') {
				player->gold -= 10000000000;
				player->armor += 999900000;
			}
			if (buy == 'b') {
				player->gold -= 10000000000;
				player->health += 9999990000000;
			}
			if (buy == 'c') {
				player->gold -= 10000000000;
				player->ad += 9999900000;
			}
			if (buy == 'd') {
				player->gold -= 10000000000;
				player->ap += 9999900000;
			}
			if (buy == 'e') {
				player->gold -= 1000000000000;
				system("cls");
				printf("진행하려면 아무 키나 눌러주세요\n");
				char key = getch();
				printf("나는 그렇게 매우 강해졌고 돈도 많이 벌었기에 앞으로 행복할 줄로만 알았다.\n");
				key = getch();
				printf("그런데 갑자기 머리가 아파오더니....\n");
				key = getch();
				system("cls");
				printf("으으... 여긴 어디지?\n");
				key = getch();
				printf("알려드립니다. 현재 시각 7시 50분입니다. 학생 여러분은 기상하시길 바랍니다\n");
				key = getch();
				printf("어디긴 어디야 학교지\n");
				key = getch();
				printf("아 꿈이었네\n");
				key = getch();
				printf("게임을 즐겨주셔서 감사합니다.");
			}
			if (buy == 'f') {
				return 0;
			}
		}
	}
}