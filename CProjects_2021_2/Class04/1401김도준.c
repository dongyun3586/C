#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>

typedef struct { // 주인공의 능력치 구조체
	int level;
	int exp;
	int money;
}player;

typedef struct { // 주인공이 사용하는 무기 구조체
	int attack;
	int level;
}wea;

typedef struct { // 상점에서 파는 무기 구조체
	int level;
	int price;
}item;

void Askname();
void Story();
void Tutorial();
void chooseweapon();
void hunt(player* a, wea* b);
void shop(player* a, wea* b, item* c);
void profile(player* a, wea* b);
void ending(player* a, wea* b, item* c);
void keep(player** a, wea** b, item** c);

char name[100];
char what;
int glory[100];

int main() {
	srand(time(NULL)); // 무작위 변수 생성위해 srand 함수 사용
	Askname(); // Askname함수 호출
	Story(); // Story함수 호출
	Tutorial(); // Tutorial함수 호출
	system("pause"); // 이어하기
	system("cls"); // 창에 떠있는 모든 글 지우기
	chooseweapon(); // chooseweapon함수 호출
	printf("모험을 떠날 모든 준비가 되었습니다! 이제 게임을 자유롭게 즐겨주십시오.\n");
	printf("--------------------------------------------------------------------------\n");
	player you = { 1,0,50 };
	wea atta = { 20, 1 };      // 기본적인 스탯 설정
	item equ = { 2, 100 };
	int go;
	int choice;
	for (int n = 3; n < 1000; n++) {
	bak1:
		if (you.level == 10 * n) { // 레벨이 30부터 10씩 증가할때마다 마왕 도전기회 얻음.
			printf("앗! 당신의 주위에서 무언가 수상한 기운이 느껴집니다...\n\n");
			Sleep(1500);
			printf("마왕이 등장했습니다!!\n\n");
			printf("마왕의 공격력은 500입니다.\n\n");
			printf("마왕과 싸우시겠습니까? ");
			scanf("%d", &choice); // 마왕과 싸울지 결정
			if (choice == 1) {
				if (atta.attack >= 500) { // 공격력이 마왕보다 높으면 승리
					printf("\n마왕을 무찌르는 데 성공했습니다!\n\n");
					you.exp += 100;
					you.money += 2000;
					ending(&you, &atta, &equ); // ending함수 호출
					printf("\n지금까지 저희 게임을 즐겨주셔서 감사합니다^_^");
					return 0;
				}
				else {
					printf("마왕의 힘은 너무나도 강력했습니다..\n"); // 패배하면 다시 돌아가서 레벨이 10 오를때까지 반복
					printf("언젠가 마왕이 다시 나타나기 전에 힘을 키워서 다시 도전해봅시다!\n\n");
					you.exp += 20;
					you.money -= 70;
					continue;
				}
			}
			else {
				continue;
			}
		}
		else {
			printf("\n무엇을 하시겠습니까? (3: 상점 4: 모험장 5: 프로필) ");
			scanf("%d", &go); // 무엇을 할지 입력
			if (go == 3) {
				shop(&you, &atta, &equ); // 3 입력받으면 shop 함수 호출, 상점으로 감
				goto bak1; // 다 끝나면 bak1으로 돌아가기
			}
			else if (go == 4) {
				hunt(&you, &atta); //4 입력받으면 hunt 함수 호출, 모험장으로 감
				if (you.level * 40 <= you.exp) { // 경험치가 레벨*40보다 높으면 자동으로 레벨업
					you.exp = you.exp - you.level * 40;
					you.level++;
				}
				goto bak1;
			}
			else if (go == 5) {
				profile(&you, &atta);//5입력받으면 profile 함수 호출, 프로필 볼 수 있음
				goto bak1;
			}
			else goto bak1;
		}
	}
}

void Askname() { //Askname 함수. 이름을 입력받아 name에 저장함.
	printf("당신의 이름은 무엇입니까? ");
	gets(name);
}

void Story() { //Story 함수. rpg의 기반이 될 기본 스토리를 알려줌.
	printf("-------------------------------------------------------------------------------------------\n");
	printf("%s님 안녕하세요.\n\n", name);
	Sleep(900);
	printf("지금 %s님이 계신 이 곳은 한국에서 멀리 떨어진 머나먼 땅, 듀크입니다.\n\n", name);
	Sleep(900);
	printf("먼 옛날, 이 땅에는 %s님과 같이 갑자기 나타난 한 사람이 있었습니다.\n\n", name);
	Sleep(900);
	printf("그는 자신을 '마왕'이라 부르기 시작했고, 이 세계에 혼란을 가져왔습니다.\n\n");
	Sleep(900);
	printf("그는 '몬스터'라고 불리는 존재를 만들어냈으며 그것들은 사람들을 공격하기 시작했습니다.\n\n");
	Sleep(900);
	printf("이젠 당신만이 저희의 희망입니다. 부디 마왕을 무찔러주세요! \n");
	printf("---------------------------------------------------------------\n");
}

void Tutorial() { //tutorial 함수. 게임에 대한 설명과 기본 조작법 안내
	printf("지금부터 게임에 대해 간단한 설명을 해드리겠습니다.\n\n");
	Sleep(900);
	printf("지금 이 곳에는 다양한 몬스터들이 나타나고 있습니다.\n\n");
	Sleep(900);
	printf("몬스터들을 잡아서 돈을 벌고 경험치를 얻으세요!\n\n");
	Sleep(900);
	printf("벌은 돈을 사용해서 무기를 업그레이드할 수 있습니다.\n\n");
	Sleep(900);
	printf("'yes'는 1번, 'no'는 2번키를 눌러주세요.\n\n");
	Sleep(900);
	printf("그럼 즐겁게 플레이해주시길 바라겠습니다!\n\n");
	printf("-----------------------------------------------------------------\n");
}

void chooseweapon() { //chooseweapon 함수. 주인공이 사용할 무기를 결정
	int num1 = 0;
	printf("%s님이 사용할 무기를 선택해주세요. 모든 무기의 능력치는 같습니다.\n\n", name);
	printf("검: 1, 활: 2, 마법봉: 3 (1,2,3 이외의 문자나 숫자는 입력하지 말아주세요.) ");
back:
	scanf("%d", &what); //어떤 것 사용할지 결정
	if (what == 1 || what == 2 || what == 3) {
		printf("\n이 무기로 결정하시겠습니까? ");
		scanf("%d", &num1); //그 무기가 맞는지 다시 한 번 확인
		if (num1 != 1) {
			printf("\n어떤 무기로 하시겠습니까? ");// 무기를 다시 입력받으러 호출
			goto back;
		}
		switch (what) {
		case 1: // 1 입력 받으면 검사
			printf("\n%s님의 직업은 검사입니다!\n\n", name);
			system("pause");
			system("cls");
			break;
		case 2: // 2 입력 받으면 궁수
			printf("\n%s님의 직업은 궁수입니다!\n\n", name);
			system("pause");
			system("cls");
			break;
		case 3: // 3 입력 받으면 마법사
			printf("\n%s님의 직업은 마법사입니다!\n\n", name);
			system("pause");
			system("cls");
			break;
		}
	}
	else
		goto back;
}

void shop(player* a, wea* b, item* c) { //shop 함수. 주인공의 무기를 업그레이드.
	int m = 0;
	printf("\n%s님이 현재 가지고 있는 잔여 금액은 %d원입니다.\n\n", name, a->money); // 현재 잔액을 표시
	printf("가지고 계신 무기의 레벨은 %d입니다.", b->level);// 현재 무기 레벨 표시
	printf("무기를 %d 레벨로 업그레이드 하는 데 드는 비용은 %d원입니다.\n\n", c->level, c->price); // 무기 업그레이드 비용을 표시
	if (a->money >= c->price) { // 현재 잔액>= 무기 업그레이드 비용일 때만 업그레이드 가능
		printf("무기를 업그레이드 하시겠습니까? ");
		scanf("%d", &m);
		if (m == 1) {
			printf("\n업그레이드에 성공했습니다.\n\n");
			(a->money) = (a->money) - (c->price); //잔액에서 비용만큼 차감
			b->level += 1;
			b->attack += 10;
			c->level += 1;
			c->price += 100;
			printf("%s님의 무기의 레벨은 %d입니다. 공격력이 %d로 올랐습니다.\n\n", name, b->level, b->attack);
			system("pause");
			system("cls");
			return;
		}
		else
			return;
	}
	else {
		printf("업그레이드할 수 없습니다.\n\n"); // 잔액<업그레이드 비용 일시에는 업그레이드 불가.
		return;
	}
}

void hunt(player* a, wea* b) { //hunt 함수. 몬스터가 출현하고 전투가 가능함.
	int n = rand() % 700 + 1; // 몬스터의 출현확률 랜덤으로 설정하기 위해 rand함수 사용. 1~700의 값 반환
	int ch = 0;
	if (1 <= n && n <= 50) {
		printf("\n아무것도 발견하지 못했습니다....\n\n");
		Sleep(250);
		system("cls");
		a->exp += 3;
		return;
	}
	else if (51 <= n && n <= 240) {
		printf("\n슬라임이 나타났습니다! 슬라임의 공격력은 15입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 15) { // 몬스터에게서 이기려면 공격력이 몬스터 이상이어야함.
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 8; //몬스터에게서 이기면 돈과 경험치를 줌.
				a->money += 30;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 3;//몬스터에게서 패배하면 경험치는 얻지만 돈을 잃음.
				a->money -= 5;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
	else if (241 <= n && n <= 400) {
		printf("\n고블린이 나타났습니다! 고블린의 공격력은 40입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 40) {
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 15;
				a->money += 50;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 5;
				a->money -= 10;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
	else if (401 <= n && n <= 500) {
		printf("\n좀비가 나타났습니다! 좀비의 공격력은 60입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 60) {
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 30;
				a->money += 80;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 10;
				a->money -= 20;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
	else if (501 <= n && n <= 580) {
		printf("\n흙의 골렘이 나타났습니다! 흙의 골렘의 공격력은 100입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 100) {
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 50;
				a->money += 100;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 15;
				a->money -= 30;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
	else if (581 <= n && n <= 640) {
		printf("\n드라큘라가 나타났습니다! 드라큘라의 공격력은 125입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 125) {
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 70;
				a->money += 150;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 100;
				a->money -= 200;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
	else if (641 <= n && n <= 680) {
		printf("\n늑대인간이 나타났습니다! 늑대인간의 공격력은 150입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 150) {
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 75;
				a->money += 150;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 20;
				a->money -= 80;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
	else if (681 <= n && n <= 700) {
		printf("\n드래곤이 나타났습니다! 드래곤의 공격력은 200입니다.\n\n");
		printf("싸우시겠습니까? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 200) {
				printf("\n승리했습니다!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 100;
				a->money += 500;
				return;
			}
			else {
				printf("패배했습니다..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 50;
				a->money -= 80;
				return;
			}
		}
		else {
			system("cls");
			return;
		}
	}
}

void profile(player* a, wea* b) { //profile 함수. 주인공의 현재 스탯을 출력함.
	printf("이름: %s \n", name);
	printf("레벨: %d, 경험치: %d, 보유 골드: %d\n", a->level, a->exp, a->money);
	if (what == 1) printf("무기: 검, 레벨: %d, 공격력: %d\n\n", b->level, b->attack);
	else if (what == 2) printf("무기: 활, 공격력: %d\n\n", b->attack);
	else if (what == 3) printf("무기: 마법봉, 공격력: %d\n\n", b->attack);
	return;
}

void ending(player* a, wea* b, item* c) { //ending 함수. 마왕을 물리쳤을 때 게임을 끝낼 것인지를 결정.
	int A = &a, B = &b, C = &c; // keep 함수에 구조체 값 보내기 위해 주소값을 값으로 가지는 변수 설정.
	int abc;
	printf("%s님 저희 세계에 평화를 되찾아주셔서 감사합니다.\n\n", name);
	printf("비록 마왕은 사라졌지만 이 세계에는 아직도 마왕이 만들어낸 몬스터들이 저희를 위협하고 있습니다.\n\n");
	printf("다시 한 번 저희 세계를 위해 힘써주시겠어요? ");
	scanf("%d", &abc);
	if (abc == 1) {
		keep(A, B, C); //이어하기 위해 keep 함수 호출
		return;
	}
	else
		return;
}

void keep(player** a, wea** b, item** c) { //keep 함수. 게임을 이어서 진행할 것인지를 결정.
	int go;
	//int A = *a, B = *b, C = *c;
	//int AA = *A, BB = *B, CC = *C;
	player* A = *a, AA = *A;
	wea* B = *b, BB = *B;
	item* C = *c, CC = *C;
	while ((*a)->level < 100) { //100 레벨이 될때까지 반복
	bak3:
		printf("\n무엇을 하시겠습니까? (3: 상점 4: 모험장 5: 프로필) ");
		scanf("%d", &go);
		if (go == 3) {
			shop(&AA, &BB, &CC);
			goto bak3;
		}
		else if (go == 4) {
			hunt(&AA, &BB);
			if ((*a)->level * 40 <= (*a)->exp) {
				(*a)->level++;
				(*a)->exp = (*a)->exp - (*a)->level * 40;
			}
			goto bak3;
		}
		else if (go == 5) {
			profile(&AA, &BB);
			goto bak3;
		}
		else goto bak3;
	}
	printf("%s님이 레벨 100에 도달하였습니다! 축하드립니다.\n\n", name); //100레벨이 되면 명예의 전당에 이름이 등록된 후 게임 종료
	Sleep(500);
	printf("그 기념으로 %s님의 이름을 명예의 전당에 등록하도록 하겠습니다.\n\n", name);
	for (int i = 0; i < sizeof(name); i++) {
		glory[i] = name[i];
	}
	return;
}