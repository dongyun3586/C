#include <stdio.h>
#include <stdlib.h>//srand(), rand()
#include <time.h>//time()
#include <windows.h>// �ܼ� â �۾� ���� ����(SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE))�Լ�) �� ����(Sleep()�Լ�)�̿��� ���� �������

#pragma once
void printbar(int num);//"="num�� ���
void printenter(int num);//"(�ٹٲ�)" num�� ���
void printspace(int num);//" " num �� ���
int ChooseEnemy(int num);//���� �װų� �������� �������� ��, ���� �� ID ���
int myAttack(int arr[]);//�÷��̾��� ���ݷ� ��ȯ
int enemyAttack(int num1, int num2);//���� ���ݷ� ��ȯ
int earnedXP(int num);//���� �׿��� �� ��� ����ġ ��ȯ
int earnedGold(int num);//���� �׿��� �� ��� ��� ��ȯ
void settextcolor(unsigned short text, unsigned short back);//�ؽ�Ʈ �� ����
void printinventory1(int num, int arr[]);// �κ��丮 ���
void printinventory2weapon(int num, int arr1[], int arr2[]);//���� �������� ������ �Ǹ�â�� (�κ��丮�� �ִ� �ƾ��� + ������ ����)���� ���
void printinventory2armor(int num, int arr1[], int arr2[]);//�� �������� ������ �Ǹ�â�� (�κ��丮�� �ִ� �ƾ��� + ������ ����)���� ��� 
void PrintItemName(int num);//�������� ID�� �Է��ϸ� �̸��� ��µ�
int printweaponsellprice(int num, int arr[]);//������ �ǸŰ� ���
int printarmorsellprice(int num, int arr[]);//���� �ǸŰ� ���
int addinventory(int arr[], int num);//inventory�� �� ������ num �Է�
int deleteinventory(int arr2[], int num);//inventory�� num+1��° ���� �����, �� ���� ��Ҹ� ��� ��ĭ�� ������ ���
int inventoryfull(int arr[]);//�κ��丮�� ���� á���� �Ǻ����ִ� �Լ�, �����E���� 1, �� ������ ������ 0 ��ȯ

int main() {
#pragma region 1. ����, �迭 ����
	srand(time(NULL));
	char name[] = { 0 };
	int stats[10] = { 50, 0, 0, 2, 1, 0, 100, 50, 1, 12 };//hp, ��������, ���ݻ���, ���, ����, ���� xp, ���, HP����, ������ ������ ID, ������ ���� ID
	int enemy[8][4] = { 20, 3, 6, 0, 30, 6, 14, 2, 50, 15, 35, 5, 40, 20, 40, 3, 80, 24, 45, 10, 100, 30, 60, 15, 120, 44, 75, 15, 300, 70, 110, 30 }; //hp, ��������, ���ݻ���, ���
	int inventory[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };//�ι��� ��Һ��� 11��° ��Ұ� �κ��丮�� 1~10��° �������� ID
	int weapons[11][4] = { 1, 3, 1, 1, 3, 6, 12, 6, 5, 9, 30, 15, 8, 13, 50, 25, 12, 18, 90, 45, 20, 31, 130, 65, 26, 38, 180, 90, 32, 45, 260, 130, 38, 58, 360, 180, 55, 76, 500, 250, 60, 100, 800, 400 };//��������, ���ݻ���, �ǸŰ�, �ż���
	int armors[9][3] = { 2, 10, 5, 5, 32, 16, 9, 44, 22, 13, 80, 40, 17, 140, 70, 23, 180, 90, 30, 340, 170, 40, 600, 300, 54, 800, 400 };// DEF �ǸŰ� �ż���
	int myattack, level = stats[4], enemyHP = 0, enemyattackLow, enemyattackHigh, enemyattack, enemydefense, earnXP, earnGold, itemID, dealtdmg, recievedmg, enemytype, inbattleflag = 0, numberinventory, choice, buyweapon, sellweapon, lookitem, equipedweapon = 1, equipedarmor = 12, buyarmor, sellarmor, NextMove;
	int levelxplimit[] = { 10, 30, 60, 100, 150, 210, 280, 360, 450, 550, 660, 780, 910, 1050 };//���� ������ �Ǳ� ���� XP
#pragma endregion
	SetConsoleTitle(TEXT("C-GAME by 1111 ������"));//�ܼ�â �̸� ����
	system("mode con cols=60 lines=34");//�ܼ�â ũ�⸦ ���� 60ĭ, ���� 34ĭ���� ����
#pragma region ���� ����ȭ��
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
	printf("[����]\n �� ������ ���ڸ� �Է��� ���� �ൿ�� ���� ������� ����˴ϴ�. ���� ��� ������ ���� ���Ⱑ ���� ���:\n\n [1]�ൿ1 [2]�ൿ2 [3]�ൿ3 [4]�ൿ4 \n\n Ű����� 1, 2, 3, 4 �� �ϳ��� ���� �ൿ�� �����ϸ� �˴ϴ�.\n\n HP�� 0�� �Ǹ� ���ӿ����˴ϴ�.\n\n�� �ڼ��� ������ �ΰ��� ������ �������ּ���.\n\n[1] Ȯ��\n\n");
	printbar(56);
	printf("\n\n");
	scanf("%d", &choice);
	system("mode con cols=51 lines=31");//�ܼ�â ũ�� ����(���� 60 ���� 30 -> ���� 51 ���� 31)
	while (1) {
#pragma region �� ���� �ڵ�
		if (enemyHP == 0) {
			enemytype = ChooseEnemy(level);//�� ���� ����
			enemyHP = enemy[enemytype][0];//�� HP ����
			enemyattackLow = enemy[enemytype][1];//�� ���� ���� ����
			enemyattackHigh = enemy[enemytype][2];//�� ���� ���� ����
			enemydefense = enemy[enemytype][3];//�� ���� ����
		}
#pragma endregion
		//���� �׾��� ���, ���ο� �� ����
#pragma region ���� ���� �迭 ��� ������Ʈ
		 // �÷��̾� HP ������Ʈ
		stats[1] = weapons[equipedweapon - 1][0];//�÷��̾� �ּ� ���ݷ�
		stats[2] = weapons[equipedweapon - 1][1];//�÷��̾� �ִ� ���ݷ�
		stats[3] = armors[equipedarmor - 12][0];//�÷��̾� ����
		stats[4] = level;// �÷��̾� ���� ������Ʈ
		//�÷��̾� XP ������Ʈ
		//�÷��̾� Gold ������Ʈ
		stats[7] = level * 50;//�÷��̾� HP ���� ������Ʈ
		stats[8] = equipedweapon;//�÷��̾� ���� ���� ������Ʈ
#pragma endregion
		//stats[]�� ��� ������Ʈ
		numberinventory = sizeof(inventory) / sizeof(int);
#pragma region ���� �ൿ �Է� �ڵ�
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
		//�÷��̾�� �Է� ����
		switch (NextMove) {
		case 1: {
			Sleep(500);
			int deletenter = 0;
			inbattleflag = 1;
			printenter(10);
			printbar(51);
#pragma region "~~~�� �����ߴ�" �޼��� ��� �ڵ�
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
#pragma region �� ���� ���, �÷��̾��� HP Loss ���, ���ӿ��� �ڵ�
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
			}//�÷��̾� HP�� 0�� �� ��� ���ӿ��� �޼��� ��� �� ���α׷� ����
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
#pragma region �÷��̾� ���� ���, ���� HP Loss ���, ���� �̽� �ڵ�
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
#pragma region �� óġ�� �޼���, ���� XP, Gold ���
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
			//���� hp�� 0�� �Ǹ�, �¸��޼��� ���
#pragma region ������ �ڵ�
			if (stats[5] >= levelxplimit[level - 1]) {
				level++;
				settextcolor(2, 0);
				printf("\nYou leveled up!\nYour Max HP increased and you're fully healed!\n");
				settextcolor(15, 0);
				stats[0] = stats[7] + 50;
				deletenter += 3;
			}
#pragma endregion
			//�� XP�� ���� ���� ���ѿ� ���޽� ������
			printbar(51);
			printenter(12 - deletenter);
			break;
		}
			  //�������� �� �޼��� ���
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
			  //�������� �� �޼��� ��� �� �� �ʱ�ȭ
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
			  //ġ��
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
			  //����
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
#pragma region ���� �Ǹ� ��� ��� �ڵ�
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
			  //���� ����
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
#pragma region �� �Ǹ� ��� ��� �ڵ�
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
			  //�� ����
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
			  // �κ��丮
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
			  // ����
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
// �������� ID�� �Է¹�����, ���� �̸� ���
int ChooseEnemy(int num) {
	int enemynum;
	if (num <= 7)
		enemynum = rand() % num;
	else
		enemynum = rand() % 8;
	return enemynum;
}
// ���� ���� ����
int myAttack(int arr[]) {
	int attack = rand() % ((arr[2] - arr[1]) + 1) + arr[1];
	return attack;
}
// �÷��̾��� ���ݷ� ����
int enemyAttack(int num1, int num2) {
	int i, attack;
	attack = rand() % ((num2 - num1) + 1) + num1;
	return attack;
}
// �� ���ݷ� ����
void printbar(int num) {
	for (int i = 1; i <= num; i++)
		printf("=");
}
// "=" num�� ���
int earnedXP(int num) {
	int XP = ((rand() % 4) + 1) * (num + 1);
	return XP;
}
// �� óġ�� ��� XP ����
void printenter(int num) {
	for (int i = 1; i <= num; i++)
		printf("\n");
}
// "(�ٹٲ�)" num�� ���
void settextcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
// �ؽ�Ʈ �� ����
int earnedGold(int num) {
	int Gold = rand() % (10 * (num + 1)) + ((num + 1) * (num + 1));
	return Gold;
}
// �� óġ�� ���� ��� ����
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
// 7�� �Է��� �� �κ��丮 ���
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
// ����������� ��� �Ǹ��� ���� �κ��丮 ���
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
// �� �������� ��� �Ǹ��� ���� �κ��丮 ���
int printweaponsellprice(int num, int arr[]) {
	if (num >= 12) {
		printf("Unsellable");
		return 0;
	}
	int nth = (4 * num) - 1;
	printf("%d", arr[nth]);
	return 1;
}
// ������ ������ID�� �Է¹�����, ������ �ǸŰ� ���(�÷��̾� �ǸŽ�)
int printarmorsellprice(int num, int arr[]) {
	if (num >= 1 && num < 12) {
		printf("Unsellable");
		return 0;
	}
	int nth = (3 * (num - 11)) - 1;
	printf("%d", arr[nth]);
	return 1;
}
// ���� ������ ID�� �Է¹�����, ���� �ǸŰ� ���(�÷��̾� �ǸŽ�)
int inventoryfull(int arr1[]) {
	for (int i = 1; i <= 11; i++) {
		if (arr1[i] == 0)
			return 0;
	}
	return 1;
}
// �κ��丮�� �� ������ ������ 0, ������ 1 ��ȯ
int addinventory(int arr[], int num) {
	int ID = num + 1;
	for (int i = 1; i <= 11; i++) {
		if (arr[i] == 0) {
			arr[i] = ID;
			return 0;
		}
	}
}
// �κ��丮 �迭�� ������� ���� �������� ID �Է�
int deleteinventory(int arr2[], int num) {
	int nth = num;
	for (int i = nth; i <= 9; i++)
		arr2[i] = arr2[i + 1];
	arr2[10] = 0;
}
// �κ��丮�� num ��° �������� �κ��丮���� ������
void printspace(int num) {
	for (int i = 1; i <= num; i++)
		printf(" ");
}
// " " num�� ���