#define _CRT_SECURE_NO_WARNINGS
#define MAXPLAYER 300

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Player {
	char name[20];//선수들의 이름을 저장하기 위한 배열 
	int goal;//선수들의 골 수  
	int price;//선수들의 가격 
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
		printf("Error! 다시 시도해 주십시오!");
	}
	char ch;
	int n = 0;
	int cnt = 0;
	printf("안녕하세요 사용자님! 선수 정보를 입력하려 오셨나요? y/n");
	scanf("%c", &ch);
	if (ch == 'n') {
		printf("저희 페이지에 방문해 주셔 감사합니다!또 오세요!");
		return 0;
	}
	else if (ch == 'y') {
		printf("정렬하고 싶은 선수 수를 입력해주세요");
	}
	scanf("%d", &n);
	rewind(stdin);
	if (n > MAXPLAYER) {
		printf("잘못 입력하셨습니다.다시 입력해 주세요");
	}
	printf("선수 정보를 입력해주세요:");
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
	printf("보고 싶은 기능들을 선택해 주세요\n1:선수 명단(알파벳순) 2:선수 득점 순위 3:선수 몸값 순위 (종료=-1)");
	scanf("%d", &cnt);
	return cnt;
}