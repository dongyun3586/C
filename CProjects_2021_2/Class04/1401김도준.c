#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>

typedef struct { // ���ΰ��� �ɷ�ġ ����ü
	int level;
	int exp;
	int money;
}player;

typedef struct { // ���ΰ��� ����ϴ� ���� ����ü
	int attack;
	int level;
}wea;

typedef struct { // �������� �Ĵ� ���� ����ü
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
	srand(time(NULL)); // ������ ���� �������� srand �Լ� ���
	Askname(); // Askname�Լ� ȣ��
	Story(); // Story�Լ� ȣ��
	Tutorial(); // Tutorial�Լ� ȣ��
	system("pause"); // �̾��ϱ�
	system("cls"); // â�� ���ִ� ��� �� �����
	chooseweapon(); // chooseweapon�Լ� ȣ��
	printf("������ ���� ��� �غ� �Ǿ����ϴ�! ���� ������ �����Ӱ� ����ֽʽÿ�.\n");
	printf("--------------------------------------------------------------------------\n");
	player you = { 1,0,50 };
	wea atta = { 20, 1 };      // �⺻���� ���� ����
	item equ = { 2, 100 };
	int go;
	int choice;
	for (int n = 3; n < 1000; n++) {
	bak1:
		if (you.level == 10 * n) { // ������ 30���� 10�� �����Ҷ����� ���� ������ȸ ����.
			printf("��! ����� �������� ���� ������ ����� �������ϴ�...\n\n");
			Sleep(1500);
			printf("������ �����߽��ϴ�!!\n\n");
			printf("������ ���ݷ��� 500�Դϴ�.\n\n");
			printf("���հ� �ο�ðڽ��ϱ�? ");
			scanf("%d", &choice); // ���հ� �ο��� ����
			if (choice == 1) {
				if (atta.attack >= 500) { // ���ݷ��� ���պ��� ������ �¸�
					printf("\n������ ����� �� �����߽��ϴ�!\n\n");
					you.exp += 100;
					you.money += 2000;
					ending(&you, &atta, &equ); // ending�Լ� ȣ��
					printf("\n���ݱ��� ���� ������ ����ּż� �����մϴ�^_^");
					return 0;
				}
				else {
					printf("������ ���� �ʹ����� �����߽��ϴ�..\n"); // �й��ϸ� �ٽ� ���ư��� ������ 10 ���������� �ݺ�
					printf("������ ������ �ٽ� ��Ÿ���� ���� ���� Ű���� �ٽ� �����غ��ô�!\n\n");
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
			printf("\n������ �Ͻðڽ��ϱ�? (3: ���� 4: ������ 5: ������) ");
			scanf("%d", &go); // ������ ���� �Է�
			if (go == 3) {
				shop(&you, &atta, &equ); // 3 �Է¹����� shop �Լ� ȣ��, �������� ��
				goto bak1; // �� ������ bak1���� ���ư���
			}
			else if (go == 4) {
				hunt(&you, &atta); //4 �Է¹����� hunt �Լ� ȣ��, ���������� ��
				if (you.level * 40 <= you.exp) { // ����ġ�� ����*40���� ������ �ڵ����� ������
					you.exp = you.exp - you.level * 40;
					you.level++;
				}
				goto bak1;
			}
			else if (go == 5) {
				profile(&you, &atta);//5�Է¹����� profile �Լ� ȣ��, ������ �� �� ����
				goto bak1;
			}
			else goto bak1;
		}
	}
}

void Askname() { //Askname �Լ�. �̸��� �Է¹޾� name�� ������.
	printf("����� �̸��� �����Դϱ�? ");
	gets(name);
}

void Story() { //Story �Լ�. rpg�� ����� �� �⺻ ���丮�� �˷���.
	printf("-------------------------------------------------------------------------------------------\n");
	printf("%s�� �ȳ��ϼ���.\n\n", name);
	Sleep(900);
	printf("���� %s���� ��� �� ���� �ѱ����� �ָ� ������ �ӳ��� ��, ��ũ�Դϴ�.\n\n", name);
	Sleep(900);
	printf("�� ����, �� ������ %s�԰� ���� ���ڱ� ��Ÿ�� �� ����� �־����ϴ�.\n\n", name);
	Sleep(900);
	printf("�״� �ڽ��� '����'�̶� �θ��� �����߰�, �� ���迡 ȥ���� �����Խ��ϴ�.\n\n");
	Sleep(900);
	printf("�״� '����'��� �Ҹ��� ���縦 ���������� �װ͵��� ������� �����ϱ� �����߽��ϴ�.\n\n");
	Sleep(900);
	printf("���� ��Ÿ��� ������ ����Դϴ�. �ε� ������ �����ּ���! \n");
	printf("---------------------------------------------------------------\n");
}

void Tutorial() { //tutorial �Լ�. ���ӿ� ���� ����� �⺻ ���۹� �ȳ�
	printf("���ݺ��� ���ӿ� ���� ������ ������ �ص帮�ڽ��ϴ�.\n\n");
	Sleep(900);
	printf("���� �� ������ �پ��� ���͵��� ��Ÿ���� �ֽ��ϴ�.\n\n");
	Sleep(900);
	printf("���͵��� ��Ƽ� ���� ���� ����ġ�� ��������!\n\n");
	Sleep(900);
	printf("���� ���� ����ؼ� ���⸦ ���׷��̵��� �� �ֽ��ϴ�.\n\n");
	Sleep(900);
	printf("'yes'�� 1��, 'no'�� 2��Ű�� �����ּ���.\n\n");
	Sleep(900);
	printf("�׷� ��̰� �÷������ֽñ� �ٶ�ڽ��ϴ�!\n\n");
	printf("-----------------------------------------------------------------\n");
}

void chooseweapon() { //chooseweapon �Լ�. ���ΰ��� ����� ���⸦ ����
	int num1 = 0;
	printf("%s���� ����� ���⸦ �������ּ���. ��� ������ �ɷ�ġ�� �����ϴ�.\n\n", name);
	printf("��: 1, Ȱ: 2, ������: 3 (1,2,3 �̿��� ���ڳ� ���ڴ� �Է����� �����ּ���.) ");
back:
	scanf("%d", &what); //� �� ������� ����
	if (what == 1 || what == 2 || what == 3) {
		printf("\n�� ����� �����Ͻðڽ��ϱ�? ");
		scanf("%d", &num1); //�� ���Ⱑ �´��� �ٽ� �� �� Ȯ��
		if (num1 != 1) {
			printf("\n� ����� �Ͻðڽ��ϱ�? ");// ���⸦ �ٽ� �Է¹����� ȣ��
			goto back;
		}
		switch (what) {
		case 1: // 1 �Է� ������ �˻�
			printf("\n%s���� ������ �˻��Դϴ�!\n\n", name);
			system("pause");
			system("cls");
			break;
		case 2: // 2 �Է� ������ �ü�
			printf("\n%s���� ������ �ü��Դϴ�!\n\n", name);
			system("pause");
			system("cls");
			break;
		case 3: // 3 �Է� ������ ������
			printf("\n%s���� ������ �������Դϴ�!\n\n", name);
			system("pause");
			system("cls");
			break;
		}
	}
	else
		goto back;
}

void shop(player* a, wea* b, item* c) { //shop �Լ�. ���ΰ��� ���⸦ ���׷��̵�.
	int m = 0;
	printf("\n%s���� ���� ������ �ִ� �ܿ� �ݾ��� %d���Դϴ�.\n\n", name, a->money); // ���� �ܾ��� ǥ��
	printf("������ ��� ������ ������ %d�Դϴ�.", b->level);// ���� ���� ���� ǥ��
	printf("���⸦ %d ������ ���׷��̵� �ϴ� �� ��� ����� %d���Դϴ�.\n\n", c->level, c->price); // ���� ���׷��̵� ����� ǥ��
	if (a->money >= c->price) { // ���� �ܾ�>= ���� ���׷��̵� ����� ���� ���׷��̵� ����
		printf("���⸦ ���׷��̵� �Ͻðڽ��ϱ�? ");
		scanf("%d", &m);
		if (m == 1) {
			printf("\n���׷��̵忡 �����߽��ϴ�.\n\n");
			(a->money) = (a->money) - (c->price); //�ܾ׿��� ��븸ŭ ����
			b->level += 1;
			b->attack += 10;
			c->level += 1;
			c->price += 100;
			printf("%s���� ������ ������ %d�Դϴ�. ���ݷ��� %d�� �ö����ϴ�.\n\n", name, b->level, b->attack);
			system("pause");
			system("cls");
			return;
		}
		else
			return;
	}
	else {
		printf("���׷��̵��� �� �����ϴ�.\n\n"); // �ܾ�<���׷��̵� ��� �Ͻÿ��� ���׷��̵� �Ұ�.
		return;
	}
}

void hunt(player* a, wea* b) { //hunt �Լ�. ���Ͱ� �����ϰ� ������ ������.
	int n = rand() % 700 + 1; // ������ ����Ȯ�� �������� �����ϱ� ���� rand�Լ� ���. 1~700�� �� ��ȯ
	int ch = 0;
	if (1 <= n && n <= 50) {
		printf("\n�ƹ��͵� �߰����� ���߽��ϴ�....\n\n");
		Sleep(250);
		system("cls");
		a->exp += 3;
		return;
	}
	else if (51 <= n && n <= 240) {
		printf("\n�������� ��Ÿ�����ϴ�! �������� ���ݷ��� 15�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 15) { // ���Ϳ��Լ� �̱���� ���ݷ��� ���� �̻��̾����.
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 8; //���Ϳ��Լ� �̱�� ���� ����ġ�� ��.
				a->money += 30;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
				Sleep(250);
				system("cls");
				a->exp += 3;//���Ϳ��Լ� �й��ϸ� ����ġ�� ������ ���� ����.
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
		printf("\n����� ��Ÿ�����ϴ�! ����� ���ݷ��� 40�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 40) {
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 15;
				a->money += 50;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
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
		printf("\n���� ��Ÿ�����ϴ�! ������ ���ݷ��� 60�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 60) {
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 30;
				a->money += 80;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
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
		printf("\n���� ���� ��Ÿ�����ϴ�! ���� ���� ���ݷ��� 100�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 100) {
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 50;
				a->money += 100;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
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
		printf("\n���ŧ�� ��Ÿ�����ϴ�! ���ŧ���� ���ݷ��� 125�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 125) {
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 70;
				a->money += 150;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
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
		printf("\n�����ΰ��� ��Ÿ�����ϴ�! �����ΰ��� ���ݷ��� 150�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 150) {
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 75;
				a->money += 150;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
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
		printf("\n�巡���� ��Ÿ�����ϴ�! �巡���� ���ݷ��� 200�Դϴ�.\n\n");
		printf("�ο�ðڽ��ϱ�? ");
		scanf("%d", &ch);
		if (ch == 1) {
			if (b->attack >= 200) {
				printf("\n�¸��߽��ϴ�!\n\n");
				Sleep(250);
				system("cls");
				a->exp += 100;
				a->money += 500;
				return;
			}
			else {
				printf("�й��߽��ϴ�..\n\n");
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

void profile(player* a, wea* b) { //profile �Լ�. ���ΰ��� ���� ������ �����.
	printf("�̸�: %s \n", name);
	printf("����: %d, ����ġ: %d, ���� ���: %d\n", a->level, a->exp, a->money);
	if (what == 1) printf("����: ��, ����: %d, ���ݷ�: %d\n\n", b->level, b->attack);
	else if (what == 2) printf("����: Ȱ, ���ݷ�: %d\n\n", b->attack);
	else if (what == 3) printf("����: ������, ���ݷ�: %d\n\n", b->attack);
	return;
}

void ending(player* a, wea* b, item* c) { //ending �Լ�. ������ �������� �� ������ ���� �������� ����.
	int A = &a, B = &b, C = &c; // keep �Լ��� ����ü �� ������ ���� �ּҰ��� ������ ������ ���� ����.
	int abc;
	printf("%s�� ���� ���迡 ��ȭ�� ��ã���ּż� �����մϴ�.\n\n", name);
	printf("��� ������ ��������� �� ���迡�� ������ ������ ���� ���͵��� ���� �����ϰ� �ֽ��ϴ�.\n\n");
	printf("�ٽ� �� �� ���� ���踦 ���� �����ֽðھ��? ");
	scanf("%d", &abc);
	if (abc == 1) {
		keep(A, B, C); //�̾��ϱ� ���� keep �Լ� ȣ��
		return;
	}
	else
		return;
}

void keep(player** a, wea** b, item** c) { //keep �Լ�. ������ �̾ ������ �������� ����.
	int go;
	//int A = *a, B = *b, C = *c;
	//int AA = *A, BB = *B, CC = *C;
	player* A = *a, AA = *A;
	wea* B = *b, BB = *B;
	item* C = *c, CC = *C;
	while ((*a)->level < 100) { //100 ������ �ɶ����� �ݺ�
	bak3:
		printf("\n������ �Ͻðڽ��ϱ�? (3: ���� 4: ������ 5: ������) ");
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
	printf("%s���� ���� 100�� �����Ͽ����ϴ�! ���ϵ帳�ϴ�.\n\n", name); //100������ �Ǹ� ���� ���翡 �̸��� ��ϵ� �� ���� ����
	Sleep(500);
	printf("�� ������� %s���� �̸��� ���� ���翡 ����ϵ��� �ϰڽ��ϴ�.\n\n", name);
	for (int i = 0; i < sizeof(name); i++) {
		glory[i] = name[i];
	}
	return;
}