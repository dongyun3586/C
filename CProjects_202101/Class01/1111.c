#include <stdio.h>
#include <stdlib.h>//srand(), rand()
#include <time.h>//time()
#include <windows.h>// 콘솔 창 글씨 색깔 변경(SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE))함수) 및 지연(Sleep()함수)이용을 위한 헤더파일

#pragma once
void printbar(int num);//"="num개 출력
void printenter(int num);//"(줄바꿈)" num개 출력
void printspace(int num);//" " num 개 출력
int ChooseEnemy(int num);//적이 죽거나 전투에서 도망쳤을 때, 다음 적 ID 출력
int myAttack(int arr[]);//플레이어의 공격력 반환
int enemyAttack(int num1, int num2);//적의 공격력 반환
int earnedXP(int num);//적을 죽였을 때 얻는 경험치 반환
int earnedGold(int num);//적을 죽였을 때 얻는 골드 반환
void settextcolor(unsigned short text, unsigned short back);//텍스트 색 변경
void printinventory1(int num, int arr[]);// 인벤토리 출력
void printinventory2weapon(int num, int arr1[], int arr2[]);//무기 상점에서 아이템 판매창을 (인벤토리에 있는 아아템 + 아이템 가격)으로 출력
void printinventory2armor(int num, int arr1[], int arr2[]);//방어구 상점에서 아이템 판매창을 (인벤토리에 있는 아아템 + 아이템 가격)으로 출력 
void PrintItemName(int num);//아이템의 ID를 입력하면 이름이 출력됨
int printweaponsellprice(int num, int arr[]);//무기의 판매가 출력
int printarmorsellprice(int num, int arr[]);//방어구의 판매가 출력
int addinventory(int arr[], int num);//inventory의 빈 공간에 num 입력
int deleteinventory(int arr2[], int num);//inventory의 num+1번째 값을 지우고, 그 뒤의 요소를 모두 한칸씩 앞으로 당김
int inventoryfull(int arr[]);//인벤토리가 가득 찼는지 판별해주는 함수, 가득핬으면 1, 빈 공간이 있으면 0 반환

int main() {
#pragma region 1. 변수, 배열 설정
	srand(time(NULL));
	char name[] = { 0 };
	int stats[10] = { 50, 0, 0, 2, 1, 0, 100, 50, 1, 12 };//hp, 공격하한, 공격상한, 방어, 레벨, 현재 xp, 골드, HP상한, 장착된 무기의 ID, 장착한 방어구의 ID
	int enemy[8][4] = { 20, 3, 6, 0, 30, 6, 14, 2, 50, 15, 35, 5, 40, 20, 40, 3, 80, 24, 45, 10, 100, 30, 60, 15, 120, 44, 75, 15, 300, 70, 110, 30 }; //hp, 공격하한, 공격상한, 방어
	int inventory[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };//두번쨰 요소부터 11번째 요소가 인벤토리의 1~10번째 아이템의 ID
	int weapons[11][4] = { 1, 3, 1, 1, 3, 6, 12, 6, 5, 9, 30, 15, 8, 13, 50, 25, 12, 18, 90, 45, 20, 31, 130, 65, 26, 38, 180, 90, 32, 45, 260, 130, 38, 58, 360, 180, 55, 76, 500, 250, 60, 100, 800, 400 };//공격하한, 공격상한, 판매가, 매수가
	int armors[9][3] = { 2, 10, 5, 5, 32, 16, 9, 44, 22, 13, 80, 40, 17, 140, 70, 23, 180, 90, 30, 340, 170, 40, 600, 300, 54, 800, 400 };// DEF 판매가 매수가
	int myattack, level = stats[4], enemyHP = 0, enemyattackLow, enemyattackHigh, enemyattack, enemydefense, earnXP, earnGold, itemID, dealtdmg, recievedmg, enemytype, inbattleflag = 0, numberinventory, choice, buyweapon, sellweapon, lookitem, equipedweapon = 1, equipedarmor = 12, buyarmor, sellarmor, NextMove;
	int levelxplimit[] = { 10, 30, 60, 100, 150, 210, 280, 360, 450, 550, 660, 780, 910, 1050 };//다음 레벨이 되기 위한 XP
#pragma endregion
	SetConsoleTitle(TEXT("C-GAME by 1111 윤가온"));//콘솔창 이름 변경
	system("mode con cols=60 lines=34");//콘솔창 크기를 가로 60칸, 세로 34칸으로 변경
#pragma region 게임 시작화면
	printf(" ");
	printbar(57);
	printf("\n");
	printf("   ######           ######      ###    ##     ## ########\n");
	printf("  ##    ##         ##    ##    ## ##   ###   ### ##      \n");
	printf("  ##               ##         ##   ##  #### #### ##      \n");
	printf("  ##       ####### ##   #### ##     ## ## ### ## ######  \n");
	printf("  ##               ##    ##  ######### ##     ## ##      \n");
	printf("  ##    ##         ##    ##  ##     ## ##     ## ##      \n");
	printf("   ######           ######   ##     ## ##     ## ########\n");
	printf(" ");
	printbar(57);
	printenter(3);
	printspace(17);
	printf("Press [1] to start\n\n");
	scanf("%d", &choice);
#pragma endregion
	printf("\n");
	printf("Enter Player Name: ");
	scanf("%s", &name);
	printf("\n");
	printbar(56);
	printf("\n");
	printspace(24);
	printf("[도움말]\n 이 게임은 숫자를 입력해 다음 행동을 고르는 방식으로 진행됩니다. 예를 들어 다음과 같은 보기가 떴을 경우:\n\n [1]행동1 [2]행동2 [3]행동3 [4]행동4 \n\n 키보드로 1, 2, 3, 4 중 하나를 눌러 행동을 선택하면 됩니다.\n\n HP가 0이 되면 게임오버됩니다.\n\n더 자세한 설명은 인게임 도움말을 참고해주세요.\n\n[1] 확인\n\n");
	printbar(56);
	printf("\n\n");
	scanf("%d", &choice);
	system("mode con cols=51 lines=31");//콘솔창 크기 변경(가로 60 세로 30 -> 가로 51 세로 31)
	while (1) {
#pragma region 적 결정 코드
		if (enemyHP == 0) {
			enemytype = ChooseEnemy(level);//적 종류 설정
			enemyHP = enemy[enemytype][0];//적 HP 설정
			enemyattackLow = enemy[enemytype][1];//적 공격 하한 설정
			enemyattackHigh = enemy[enemytype][2];//적 공격 상한 설정
			enemydefense = enemy[enemytype][3];//적 방어력 설정
		}
#pragma endregion
		//적이 죽었을 경우, 새로운 적 결정
#pragma region 스탯 저장 배열 요소 업데이트
		 // 플레이어 HP 업데이트
		stats[1] = weapons[equipedweapon - 1][0];//플레이어 최소 공격력
		stats[2] = weapons[equipedweapon - 1][1];//플레이어 최대 공격력
		stats[3] = armors[equipedarmor - 12][0];//플레이어 방어력
		stats[4] = level;// 플레이어 레벨 업데이트
		//플레이어 XP 업데이트
		//플레이어 Gold 업데이트
		stats[7] = level * 50;//플레이어 HP 상한 업데이트
		stats[8] = equipedweapon;//플레이어 장착 무기 업데이트
#pragma endregion
		//stats[]의 요소 업데이트
		numberinventory = sizeof(inventory) / sizeof(int);
#pragma region 다음 행동 입력 코드
		Sleep(1500);
		printbar(51);
		printf("\nEnter your next move\n\n [1]");
		settextcolor(4, 0);
		printf(" Attack");
		settextcolor(15, 0);
		printf(" [2]");
		settextcolor(9, 0);
		printf(" Run");
		settextcolor(15, 0);
		printf(" [3]");
		settextcolor(2, 0);
		printf(" Heal");
		settextcolor(15, 0);
		printf(" [4]");
		settextcolor(13, 0);
		printf(" Stats");
		settextcolor(15, 0);
		printf("\n [5]");
		settextcolor(14, 0);
		printf(" Weapon Shop");
		settextcolor(15, 0);
		printf(" [6]");
		settextcolor(14, 0);
		printf(" Armor Shop");
		settextcolor(15, 0);
		printf(" \n [7] Inventory [0] Help\n");
		printbar(51);
		printf("\n");
		scanf("%d", &NextMove);
#pragma endregion
		//플레이어에게 입력 묻기
		switch (NextMove) {
		case 1: {
			Sleep(500);
			int deletenter = 0;
			inbattleflag = 1;
			printenter(10);
			printbar(51);
#pragma region "~~~가 공격했다" 메세지 출력 코드
			switch (enemytype) {
			case 0:
				printf("\nBaby Shroom attacked!\n");
				break;
			case 1:
				printf("\nShroom attacked!\n");
				break;
			case 2:
				printf("\nElder Shroom attacked!\n");
				break;
			case 3:
				printf("\nBoar attacked!\n");
				break;
			case 4:
				printf("\nCursed Scarecrow attacked!\n");
				break;
			case 5:
				printf("\nRubee attacked!\n");
				break;
			case 6:
				printf("\nBaby Yeti attacked!\n");
				break;
			case 7:
				printf("\nGuardian attacked!\n");
				break;
			}
#pragma endregion
#pragma region 적 공격 계산, 플레이어의 HP Loss 출력, 게임오버 코드
			enemyattack = enemyAttack(enemyattackLow, enemyattackHigh);
			recievedmg = enemyattack - stats[3];
			if (recievedmg <= 0)
				recievedmg = 0;
			stats[0] -= recievedmg;
			if (stats[0] <= 0) {
				recievedmg += stats[0];
				stats[0] = 0;
				settextcolor(4, 0);
				printf("You lost %d HP.\n", recievedmg);
				printf("HP: [%d/%d]\n", stats[0], stats[7]);
				printf("\nYou Died\n\nGame Over\n\n");
				settextcolor(15, 0);
				printbar(51);
				printenter(14);
				return 0;
			}//플레이어 HP가 0이 될 경우 게임오버 메세지 출력 후 프로그램 종료
			if (recievedmg == 0) {
				printf("You dodged!\n");
				printf("HP: [%d/%d]\n", stats[0], stats[7]);
			}
			else {
				settextcolor(12, 0);
				printf("You lost %d HP.\n", recievedmg);
				settextcolor(15, 0);
				printf("HP: [%d/%d]\n", stats[0], stats[7]);
			}
#pragma endregion
#pragma region 플레이어 공격 계산, 적의 HP Loss 출력, 공격 미스 코드
			myattack = myAttack(stats);
			printf("\nYou attacked.\n");
			dealtdmg = myattack - enemydefense;
			if (dealtdmg <= 0)
				dealtdmg = 0;
			enemyHP -= dealtdmg;
			if (enemyHP <= 0) {
				dealtdmg += enemyHP;
				enemyHP = 0;
			}
			if (dealtdmg == 0)
				printf("\nAttack missed!\n");
			else {
				settextcolor(2, 0);
				printf("\nEnemy lost %d hp.\n", dealtdmg);
				settextcolor(15, 0);
			}
			printf("Enenmy HP: [%d/%d]\n", enemyHP, enemy[enemytype][0]);
#pragma endregion
#pragma region 적 처치시 메세지, 얻은 XP, Gold 출력
			if (enemyHP == 0) {
				earnXP = earnedXP(enemytype);
				earnGold = earnedGold(enemytype);
				settextcolor(2, 0);
				printf("Enemy defeated!\n");
				printf("You earned %d XP!\n", earnXP);
				settextcolor(14, 0);
				printf("You earned %d Gold!\n", earnGold);
				settextcolor(15, 0);
				stats[5] += earnXP;
				stats[6] += earnGold;
				inbattleflag = 0;
				deletenter += 3;
			}
#pragma endregion
			//적의 hp가 0이 되면, 승리메세지 출력
#pragma region 레벨업 코드
			if (stats[5] >= levelxplimit[level - 1]) {
				level++;
				settextcolor(2, 0);
				printf("\nYou leveled up!\nYour Max HP increased and you're fully healed!\n");
				settextcolor(15, 0);
				stats[0] = stats[7] + 50;
				deletenter += 3;
			}
#pragma endregion
			//내 XP가 현재 레벨 상한에 도달시 레벨업
			printbar(51);
			printenter(12 - deletenter);
			break;
		}
			  //공격했을 때 메세지 출력
		case 2: {
			Sleep(500);
			printenter(10);
			printbar(51);
			if (inbattleflag)
				printf("\n\nYou ran away.\n\n");
			else
				printf("\n\nYou're not in a battle.\n\n");
			printbar(51);
			printenter(17);
			enemyHP = 0, inbattleflag = 0;
			break;
		}
			  //도망쳤을 때 메세지 출력 및 적 초기화
		case 3: {
			Sleep(500);
			printenter(10);
			printbar(51);
			if (stats[0] == stats[7])
				printf("\n\nYou are already full HP.\n\n");
			else {
				printf("\n\nYou fully healed yourself.\n\n");
				stats[0] = stats[7];
			}
			printbar(51);
			printenter(17);
			break;
		}
			  //치유
		case 4: {
			Sleep(500);
			printenter(10);
			printbar(22);
			printf("[Stats]");
			printbar(22);
			printf("\n HP: [%d/%d]\n Attack: %d-%d\n Defense: %d\n Level: %d\n XP: [%d/%d]\n Gold: %d\n Weapon: ", stats[0], stats[7], stats[1], stats[2], stats[3], stats[4], stats[5], levelxplimit[level - 1], stats[6]);
			PrintItemName(equipedweapon);
			printf("\n Armor: ");
			PrintItemName(equipedarmor);
			printf("\n");
			printbar(51);
			printenter(14);
			break;
		}
			  //스탯
		case 5: {
			Sleep(500);
			printenter(11);
			printbar(19);
			printf("[Weapon Shop]");
			printbar(19);
			printf("\n Merchant - Hello! Welcome to the weapon shop!\n            How can I help you?\n\n\n [1] Buy [2] Sell [3] Exit Shop\n");
			printbar(51);
			printf("\n");
			printenter(20);
			scanf("%d", &choice);
			switch (choice) {// [1] Buy [2] Sell [3] Exit Shop
			case 1: {
				while (1) {
#pragma region 무기 판매 목록 출력 코드
					Sleep(500);
					printf("\n");
					printbar(19);
					printf("[Weapon Shop]");
					printbar(19);
					for (int i = 1; i <= (sizeof(weapons) / sizeof(int) / 4); i++) {
						printf("\n[%d] ", i);
						PrintItemName(i);
						printf(" - ");
						settextcolor(4, 0);
						printf("ATK");
						settextcolor(15, 0);
						printf(" : %d - %d", weapons[i - 1][0], weapons[i - 1][1]);
						settextcolor(14, 0);
						printf(" Price:% d Gold", weapons[i - 1][2]);
						settextcolor(15, 0);
						printf("\n");
					}
					printf("\n[0] Exit Shop\n");
					settextcolor(6, 0);
					printf("\nGold : % d\n", stats[6]);
					settextcolor(15, 0);
					printbar(51);
#pragma endregion
					printf("\nChoose an item.\n\n");
					scanf("%d", &choice);
					Sleep(500);
					printenter(4);
					if (choice == 0) {
						printenter(20);
						printbar(19);
						printf("[Weapon Shop]");
						printbar(19);
						printf("\n\n Merchant - Goodbye!\n\n");
						printbar(51);
						printenter(17);
						break;
					}
					buyweapon = choice - 1;
					printenter(20);
					printbar(51);
					printf("\n[%d] ", choice);
					PrintItemName(choice);
					printf(" - ");
					settextcolor(4, 0);
					printf("ATK");
					settextcolor(15, 0);
					printf(" : %d - %d", weapons[buyweapon][0], weapons[buyweapon][1]);
					settextcolor(14, 0);
					printf(" Price:% d Gold", weapons[buyweapon][2]);
					settextcolor(15, 0);
					printf("\n Do you want to buy this item?\n\n [1] Yes [2] No\n");
					printbar(51);
					printf("\n");
					scanf("%d", &choice);
					printf("\n\n");
					Sleep(500);
					if (choice == 1) {
						if (inventoryfull(inventory)) {
							printenter(23);
							printbar(19);
							printf("[Weapon Shop]");
							printbar(19);
							printf("\n\nYour inventory is full!\n\n");
							printbar(51);
							printf("\n");
							Sleep(1500);
						}
						else if (stats[6] < weapons[buyweapon][2]) {
							printbar(51);
							printf("\n\nYou don't have enough money.\n\n");
							printbar(51);
							Sleep(1500);
							printf("\n");
						}
						else {
							printbar(51);
							printf("\n\n Item successfully purchased!\n\n");
							printbar(51);
							printf("\n");
							Sleep(1500);
							addinventory(inventory, buyweapon);
							stats[6] -= weapons[buyweapon][2];
						}
					}
				}
				break;
			}// [1] Buy End
			case 2: {
				while (1) {
					Sleep(1000);
					printf("\n\n");
					printbar(51);
					printf("\n\nWhat do you want to sell?\n\n");
					printbar(51);
					printf("\n");
					printinventory2weapon(numberinventory, inventory, weapons);
					printf("[0] Exit\n");
					settextcolor(6, 0);
					printf("Gold: %d\n", stats[6]);
					settextcolor(15, 0);
					printbar(51);
					printenter(11);
					scanf("%d", &choice);
					if (choice == 0) {
						Sleep(1000);
						printenter(20);
						printbar(19);
						printf("[Weapon Shop]");
						printbar(19);
						printf("\n\n Merchant - Goodbye!\n\n");
						printbar(51);
						printenter(17);
						break;
					}
					if (choice >= 11)
						continue;
					sellweapon = choice;
					if (inventory[sellweapon] == 0) {
						Sleep(1000);
						printenter(24);
						printbar(51);
						printf("\n\nYou can't sell that!\n\n[1] Ok\n");
						printbar(51);
						printf("\n");
						scanf("%d", &choice);
					}
					else if (inventory[sellweapon] >= 12) {
						Sleep(1000);
						printenter(25);
						printbar(19);
						printf("[Weapon Shop]");
						printbar(19);
						printf("\n\nI don't buy such things.\n\n");
						printbar(51);
						printf("\n");
						Sleep(2000);
						printenter(5);
					}
					else {
						Sleep(1000);
						printenter(25);
						printbar(51);
						printf("\nDo you really want to sell ");
						PrintItemName(inventory[sellweapon]);
						printf("?\n\n [1] Yes [2] No\n");
						printbar(51);
						printf("\n");
						scanf("%d", &choice);
						if (choice == 1) {
							Sleep(1000);
							printbar(51);
							printf("\n\n Item sold!\n\n");
							printbar(51);
							stats[6] += weapons[inventory[sellweapon] - 1][3];
							deleteinventory(inventory, sellweapon);
						}
					}
				}
				break;
			}//[2] Sell End
			case 3: {
				Sleep(1000);
				printenter(20);
				printbar(19);
				printf("[Weaopn Shop]");
				printbar(19);
				printf("\n\n Merchant - Goodbye!\n\n");
				printbar(51);
				printenter(17);
				break;
			}//[3] Exit shop End
			default:
				break;
			}
			break;
		}
			  //무기 상점
		case 6: {
			Sleep(1000);
			printenter(11);
			printbar(19);
			printf("[Armor Shop]");
			printbar(20);
			printf("\n Merchant - Hello! Welcome to the armor shop!\n            How can I help you?\n\n\n [1] Buy [2] Sell [3] Exit Shop\n");
			printbar(51);
			printf("\n");
			printenter(20);
			scanf("%d", &choice);
			switch (choice) {// [1] Buy [2] Sell [3] Exit Shop
			case 1: {
				while (1) {
#pragma region 방어구 판매 목록 출력 코드
					Sleep(1000);
					printenter(10);
					printbar(19);
					printf("[Armor Shop]");
					printbar(20);
					for (int i = 1; i <= (sizeof(armors) / sizeof(int) / 3); i++) {
						printf("\n[%d] ", i);
						PrintItemName(i + 11);
						printf(" - ");
						settextcolor(9, 0);
						printf("DEF");
						settextcolor(15, 0);
						printf(" : %d", armors[i - 1][0]);
						settextcolor(14, 0);
						printf(" Price:% d Gold", armors[i - 1][1]);
						settextcolor(15, 0);
						printf("\n");
					}
					printf("\n[0] Exit Shop\n");
					settextcolor(6, 0);
					printf("\nGold : % d\n", stats[6]);
					settextcolor(15, 0);
					printbar(51);
#pragma endregion
					printf("\nChoose an item.\n\n");
					scanf("%d", &choice);
					Sleep(1000);
					printenter(4);
					if (choice == 0) {
						printenter(20);
						printbar(19);
						printf("[Armor Shop]");
						printbar(20);
						printf("\n\n Merchant - Goodbye!\n\n");
						printbar(51);
						printenter(17);
						break;
					}
					buyarmor = choice - 1;
					printenter(20);
					printbar(51);
					printf("\n[%d] ", choice);
					PrintItemName(choice + 11);
					printf(" - ");
					settextcolor(9, 0);
					printf("DEF");
					settextcolor(15, 0);
					printf(" : %d", armors[buyarmor][0]);
					settextcolor(14, 0);
					printf(" Price:% d Gold", armors[buyarmor][1]);
					settextcolor(15, 0);
					printf("\n Do you want to buy this item?\n\n [1] Yes [2] No\n");
					printbar(51);
					printf("\n");
					scanf("%d", &choice);
					printf("\n\n");
					Sleep(1000);
					if (choice == 1) {
						if (inventoryfull(inventory)) {
							printenter(21);
							printbar(19);
							printf("[Armor Shop]");
							printbar(20);
							printf("\n\nYour inventory is full!\n\n [1] Ok\n");
							printbar(51);
							printf("\n");
							scanf("%d", &choice);
						}
						else if (stats[6] < armors[buyarmor][1]) {
							printbar(51);
							printf("\n\nYou don't have enough money.\n\n [1] Ok\n\n");
							printbar(51);
							printf("\n");
							Sleep(1500);
						}
						else {
							printbar(51);
							printf("\n\n Item successfully purchased!\n\n");
							printbar(51);
							printf("\n");
							Sleep(1500);
							addinventory(inventory, buyarmor + 11);
							stats[6] -= armors[buyarmor][1];
						}
					}
				}
				break;
			}// [1] Buy End
			case 2: {
				while (1) {
					Sleep(1000);
					printf("\n\n");
					printbar(51);
					printf("\n\nWhat do you want to sell?\n\n");
					printbar(51);
					printf("\n\n");
					printinventory2armor(numberinventory, inventory, armors);
					printf("[0] Exit\n");
					settextcolor(6, 0);
					printf("Gold: %d\n", stats[6]);
					settextcolor(15, 0);
					printbar(51);
					printenter(11);
					scanf("%d", &choice);
					if (choice == 0) {
						Sleep(1000);
						printenter(20);
						printbar(19);
						printf("[Armor Shop]");
						printbar(20);
						printf("\n\n Merchant - Goodbye!\n\n");
						printbar(51);
						printenter(17);
						break;
					}
					sellarmor = choice;
					if (inventory[sellarmor] == 0) {
						Sleep(1000);
						printenter(24);
						printbar(51);
						printf("\n\nYou can't sell that!\n\n[1] Ok\n");
						printbar(51);
						printf("\n");
						scanf("%d", &choice);
					}
					else if (0 < inventory[sellarmor] && inventory[sellarmor] < 12) {
						Sleep(1000);
						printenter(20);
						printbar(19);
						printf("[Armor Shop]");
						printbar(20);
						printf("\n\nI don't buy such things.\n\n");
						printbar(51);
						printf("\n");
						Sleep(2000);
						printenter(5);
					}
					else {
						Sleep(1000);
						printenter(25);
						printbar(51);
						printf("\nDo you really want to sell ");
						PrintItemName(inventory[sellarmor]);
						printf("?\n\n [1] Yes [2] No\n");
						printbar(51);
						printf("\n");
						scanf("%d", &choice);
						if (choice == 1) {
							Sleep(1000);
							printbar(51);
							printf("\n\n Item sold!\n\n");
							printbar(51);
							stats[6] += armors[(inventory[sellarmor]) - 12][2];
							deleteinventory(inventory, sellarmor);
						}
					}
				}
				break;
			}//[2] Sell End
			case 3: {
				Sleep(1000);
				printenter(20);
				printbar(19);
				printf("[Armor Shop]");
				printbar(20);
				printf("\n\n Merchant - Goodbye!\n\n");
				printbar(51);
				printenter(17);
				break;
			}//[3] Exit shop End
			default:
				break;
			}
			break;
		}
			  //방어구 상점
		case 7: {
			while (1) {
				Sleep(1000);
				printenter(10);
				printbar(20);
				printf("[Inventory]");
				printbar(20);
				printf("\n");
				printinventory1(numberinventory, inventory);
				printf("\n[0] Close Inventory\n\n Enter number to choose an item\n");
				printbar(51);
				printenter(11);
				scanf("%d", &choice);
				if (choice == 0) {
					printenter(30);
					break;
				}
				lookitem = choice;
				Sleep(1000);
				printenter(25);
				printbar(51);
				printf("\n\n ");
				if (inventory[lookitem] == 0) {
					printf("You don't have any items!\n\n");
					printbar(51);
					printenter(6);
					Sleep(2000);
					printenter(25);
					continue;
				}
				if (inventory[lookitem] < 12) {
					PrintItemName(inventory[lookitem]);
					printf(" - ");
					settextcolor(4, 0);
					printf("ATK");
					settextcolor(15, 0);
					printf(": %d - %d\n\n[1] Equip [2] Cancel\n", weapons[inventory[lookitem] - 1][0], weapons[inventory[lookitem] - 1][1]);
					printbar(51);
					scanf("%d", &choice);
					Sleep(1000);
					if (choice == 1) {
						int willequipweapon = inventory[lookitem];
						deleteinventory(inventory, lookitem);
						addinventory(inventory, equipedweapon - 1);
						equipedweapon = willequipweapon;
						printbar(51);
						printf("\n\n");
						PrintItemName(equipedweapon);
						printf(" equipped!\n\n");
						printbar(51);
						printf("\n");
					}
				}
				else {
					PrintItemName(inventory[lookitem]);
					printf(" - ");
					settextcolor(9, 0);
					printf("DEF");
					settextcolor(15, 0);
					printf(": %d\n\n[1] Equip [2] Cancel\n", armors[inventory[lookitem] - 12][0]);
					printbar(51);
					scanf("%d", &choice);
					Sleep(500);
					if (choice == 1) {
						int willequiparmor = inventory[lookitem];
						deleteinventory(inventory, lookitem);
						addinventory(inventory, equipedarmor - 1);
						equipedarmor = willequiparmor;
						printbar(51);
						printf("\n\n");
						PrintItemName(equipedarmor);
						printf(" equipped!\n\n");
						printbar(51);
						printf("\n");
					}
				}
			}
			break;
		}
			  // 인벤토리
		case 0: {
			printenter(5);
			printbar(22);
			printf("[Help]");
			printbar(23);
			printf("\n\nAttack: During battle, attacks enemy.\nRun: Run away from current battle.\nHeal: Heals yourself.\nStats: Shows your stats.\nWepon Shop/Armor Shop: Opens a shop tab to buy and sell items.\nInventory: Opens inventory. You can equip your weapons and armors.\nHelp: Shows you this message.\n\n");
			printbar(51);
			printenter(10);
			break;
		}
			  // 도움말
		default: {
			printenter(50);
			break;
		}
		}
	}
}

#include <windows.h>
void PrintItemName(int num) {
	int ID = num;
	switch (ID) {
	case 1:
		printf("Stick");
		break;
	case 2:
		printf("Wooden Club");
		break;
	case 3:
		printf("Pitchfork");
		break;
	case 4:
		printf("Rusty Sword");
		break;
	case 5:
		printf("Bronze Mace");
		break;
	case 6:
		printf("Tomahawk");
		break;
	case 7:
		printf("Iron Sword");
		break;
	case 8:
		printf("Steel Sword");
		break;
	case 9:
		printf("Royal Fang");
		break;
	case 10:
		printf("Bronze Scythe");
		break;
	case 11:
		printf("Steel War Axe");
		break;
	case 12:
		printf("Leather Tunic");
		break;
	case 13:
		printf("Rusty Armor");
		break;
	case 14:
		printf("Bronze Armor");
		break;
	case 15:
		printf("Iron Armor");
		break;
	case 16:
		printf("Thorns Armor");
		break;
	case 17:
		printf("Steel Armor");
		break;
	case 18:
		printf("Arachnid Armor");
		break;
	case 19:
		printf("Nightstrider Armor");
		break;
	case 20:
		printf("Duneplate Cuirass");
		break;
	default:
		break;
	}
}
// 아이템의 ID를 입력받으면, 영문 이름 출력
int ChooseEnemy(int num) {
	int enemynum;
	if (num <= 7)
		enemynum = rand() % num;
	else
		enemynum = rand() % 8;
	return enemynum;
}
// 적의 종류 결정
int myAttack(int arr[]) {
	int attack = rand() % ((arr[2] - arr[1]) + 1) + arr[1];
	return attack;
}
// 플레이어의 공격력 결정
int enemyAttack(int num1, int num2) {
	int i, attack;
	attack = rand() % ((num2 - num1) + 1) + num1;
	return attack;
}
// 적 공격력 결정
void printbar(int num) {
	for (int i = 1; i <= num; i++)
		printf("=");
}
// "=" num개 출력
int earnedXP(int num) {
	int XP = ((rand() % 4) + 1) * (num + 1);
	return XP;
}
// 적 처치시 얻는 XP 결정
void printenter(int num) {
	for (int i = 1; i <= num; i++)
		printf("\n");
}
// "(줄바꿈)" num개 출력
void settextcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
// 텍스트 색 변경
int earnedGold(int num) {
	int Gold = rand() % (10 * (num + 1)) + ((num + 1) * (num + 1));
	return Gold;
}
// 적 처치시 얻은 골드 결정
void printinventory1(int num, int arr[]) {
	int invsize = num;
	for (int i = 1; i < invsize; i++) {
		printf("[%d] ", i);
		if (arr[i] == 0)
			printf("(empty)\n");
		else {
			PrintItemName(arr[i]);
			printf("\n");
		}
	}
	if (invsize == 1)
		printf("(empty)");
}
// 7을 입력할 때 인벤토리 출력
void printinventory2weapon(int num, int arr1[], int arr2[]) {
	int invsize = num, a;
	for (int i = 1; i < invsize; i++) {
		printf("[%d]", i);
		if (arr1[i] == 0)
			printf("(empty)\n");
		else {
			PrintItemName(arr1[i]);
			printf(" - Price: ");
			settextcolor(14, 0);
			a = printweaponsellprice(arr1[i], arr2);
			if (a == 1)
				printf(" Gold");
			settextcolor(15, 0);
			printf("\n");
		}
	}
	if (invsize == 1)
		printf("(empty)");
}
// 무기상점에서 장비 판매할 때의 인벤토리 출력
void printinventory2armor(int num, int arr1[], int arr2[]) {
	int invsize = num, a;
	for (int i = 1; i < invsize; i++) {
		printf("[%d]", i);
		if (arr1[i] == 0)
			printf("(empty)\n");
		else {
			PrintItemName(arr1[i]);
			printf(" - Price: ");
			settextcolor(14, 0);
			a = printarmorsellprice(arr1[i], arr2);
			if (a == 1)
				printf(" Gold");
			settextcolor(15, 0);
			printf("\n");
		}
	}
	if (invsize == 1)
		printf("(empty)");
}
// 방어구 상점에서 장비 판매할 때의 인벤토리 출력
int printweaponsellprice(int num, int arr[]) {
	if (num >= 12) {
		printf("Unsellable");
		return 0;
	}
	int nth = (4 * num) - 1;
	printf("%d", arr[nth]);
	return 1;
}
// 무기의 아이템ID를 입력받으면, 무기의 판매가 출력(플레이어 판매시)
int printarmorsellprice(int num, int arr[]) {
	if (num >= 1 && num < 12) {
		printf("Unsellable");
		return 0;
	}
	int nth = (3 * (num - 11)) - 1;
	printf("%d", arr[nth]);
	return 1;
}
// 방어구의 아이템 ID를 입력받으면, 방어구의 판매가 출력(플레이어 판매시)
int inventoryfull(int arr1[]) {
	for (int i = 1; i <= 11; i++) {
		if (arr1[i] == 0)
			return 0;
	}
	return 1;
}
// 인벤토리에 빈 공간이 있으면 0, 없으면 1 반환
int addinventory(int arr[], int num) {
	int ID = num + 1;
	for (int i = 1; i <= 11; i++) {
		if (arr[i] == 0) {
			arr[i] = ID;
			return 0;
		}
	}
}
// 인벤토리 배열의 빈공간에 얻은 아이템의 ID 입력
int deleteinventory(int arr2[], int num) {
	int nth = num;
	for (int i = nth; i <= 9; i++)
		arr2[i] = arr2[i + 1];
	arr2[10] = 0;
}
// 인벤토리의 num 번째 아이템을 인벤토리에서 제거함
void printspace(int num) {
	for (int i = 1; i <= num; i++)
		printf(" ");
}
// " " num개 출력