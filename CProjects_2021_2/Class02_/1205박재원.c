#define _CRT_SECURE_NO_WARNINGS
#define MAXPLAYER 300

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Player {
	char name[20];//�������� �̸��� �����ϱ� ���� �迭 
	int goal;//�������� �� ��  
	int price;//�������� ���� 
};
typedef struct Player Player;

int interface(void);
void playerbyalpha(Player info[MAXPLAYER], int num);
void playerbygoal(Player info[MAXPLAYER], int num);
void playerbyprice(Player info[MAXPLAYER], int num);
void swap(Player* a, Player* b);

int main() {
	Player* p1 = (Player*)malloc(sizeof(Player) * MAXPLAYER);
	if (p1 == NULL) {
		printf("Error! �ٽ� �õ��� �ֽʽÿ�!");
	}
	char ch;
	int n = 0;
	int cnt = 0;
	printf("�ȳ��ϼ��� ����ڴ�! ���� ������ �Է��Ϸ� ���̳���? y/n");
	scanf("%c", &ch);
	if (ch == 'n') {
		printf("���� �������� �湮�� �ּ� �����մϴ�!�� ������!");
		return 0;
	}
	else if (ch == 'y') {
		printf("�����ϰ� ���� ���� ���� �Է����ּ���");
	}
	scanf("%d", &n);
	rewind(stdin);
	if (n > MAXPLAYER) {
		printf("�߸� �Է��ϼ̽��ϴ�.�ٽ� �Է��� �ּ���");
	}
	printf("���� ������ �Է����ּ���:");
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", p1[i].name, &p1[i].goal, &p1[i].price);
		rewind(stdin);
	}
	if (interface() == 1) {
		playerbyalpha(p1, n);
	}
	else if (interface() == 2) {
		playerbygoal(p1, n);
	}
	else if (interface() == 3) {
		playerbyprice(p1, n);
	}
	else if (interface() == -1) {
		return 0;
		free(p1);
	}
}

void playerbyalpha(Player info[MAXPLAYER], int num) {
	printf("----------------------------------------\n");
	char temp[20] = { 0 };
	if (num > 1) {
		for (int i = 0; i < num; i++) {
			for (int j = i; j < num; j++) {
				if (strcmp(info[j - 1].name, info[j].name) > 0) {
					strcpy(temp, info[j - 1].name);
					strcpy(info[j - 1].name, info[j].name);
					strcpy(info[j].name, temp);
				}
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d  ", i + 1);
		printf("%s", info[i].name);
		printf("\n");
	}
	printf("----------------------------------------");
}

void playerbygoal(Player info[MAXPLAYER], int num) {
	printf("----------------------------------------\n");
	Player temp = { 0, };
	if (num > 1) {
		for (int i = 0; i < num; i++) {
			for (int j = i; j < num; j++) {
				if (info[j - 1].goal < info[j].goal) {
					swap(&info[j - 1], &info[j]);
				}
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d  ", i + 1);
		printf("%s", info[i].name);
		printf("\n");
	}
	printf("----------------------------------------");
}

void playerbyprice(Player info[MAXPLAYER], int num) {
	printf("----------------------------------------\n");
	if (num > 1) {
		for (int i = 0; i < num; i++) {
			for (int j = i; j < num; j++) {
				if (info[j - 1].price < info[j].price) {
					swap(&info[j - 1], &info[j]);
				}
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d  ", i + 1);
		printf("%s", info[i].name);
		printf("\n");
	}
	printf("----------------------------------------");
}

void swap(Player* a, Player* b) {
	Player temp = *a;
	*a = *b;
	*b = temp;
}

int interface(void) {
	int cnt = 0;
	printf("���� ���� ��ɵ��� ������ �ּ���\n1:���� ���(���ĺ���) 2:���� ���� ���� 3:���� ���� ���� (����=-1)");
	scanf("%d", &cnt);
	return cnt;
}