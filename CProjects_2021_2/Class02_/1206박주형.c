#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct _tile {
	int value;
	int hidden;				//hidden => 0, open => 1
}tile;

void CreateMine(tile map[21][21], int NumOfMine);			//지뢰 랜덤 생성 함수
void PrintArr(tile arr[][21]);
int CheckLevel(char* str);						//난이도 체크 함수
void MapSetting(tile map[][21]);				//전체 맵 셋팅 함수(지뢰 수 표시)
int MapSetting1(tile map[][21]);				//(1, 1) 셋팅 함수
int MapSetting2(tile map[][21]);				//(1, 20)셋팅 함수
int MapSetting3(tile map[][21]);				//(20, 1)셋팅 함수
int MapSetting4(tile map[][21]);				//(20, 20)셋팅 함수
int MapSetLine1(tile map[][21], int x);			//(1, x)셋팅 함수
int MapSetLine2(tile map[][21], int y);			//(y, 20)셋팅 함수
int MapSetLine3(tile map[][21], int x);			//(20, x)셋팅 함수
int MapSetLine4(tile map[][21], int y);			//(y, 1)셋팅 함수
int MapSetAll(tile map[][21], int x, int y);		//나머지 부분 셋팅 함수
int CheckEnd(tile map[][21], int NumofMine);

int main() {

	srand(time(NULL));
	char str[50];
	int mine = 0, mode = 1;
	int x, y;
	int endcheck = 0;
	tile map[21][21] = { 0 };
	for (int i = 1; i < 21; i++) {
		(map[i][0]).value = i;
		(map[i][0]).hidden = 1;
		(map[0][i]).value = i;
		(map[0][i]).hidden = 1;
	}

	printf("지뢰찾기 프로그램\n\n");
	printf("원하는 모드를 선택해 주십시오 1: 지뢰 개수 설정 모드, 2: 빠른 난이도 선택 모드\n");
	scanf("%d", &mode);
	while (1) {
		if (mode < 1 || mode > 2) {
			printf("잘못된 입력입니다. 다시 입력해 주십시오\n");
			scanf("%d", &mode);
			continue;
		}
		else {
			break;
		}
	}

	if (mode == 1) {
		printf("지뢰 개수를 선택해 주세요(30개 ~ 100개)\n");
		scanf("%d", &mine);
		while (1) {
			if (mine < 30 || mine > 100) {
				printf("잘못된 입력입니다. 다시 입력해 주십시오\n");
				scanf("%d", &mine);
				continue;
			}
			else {
				break;
			}
		}
	}
	else if (mode == 2) {
		printf("난이도를 선택해 주세요\n초급:30개, 중급:50개, 고급: 70개\n");
		scanf("%s", str);
		mine = CheckLevel(str);
	}
	CreateMine(map, mine);
	MapSetting(map);

	while (endcheck == 0) {
		PrintArr(map);
		printf("터트릴 좌표를 입력해 주세요(x, y), (단, x, y의 범위: 1이상 20이하)\n포기하시려면 -1,-1을 입력하세요\n");
		scanf("%d, %d", &x, &y);
		if (x == -1 && y == -1) {
			for (int i = 1; i < 21; i++) {
				for (int j = 1; j < 21; j++) {
					(map[i][j]).hidden = 1;
				}
			}
			printf("\n폭탄들의 위치입니다.(9:지뢰)\n\n");
			PrintArr(map);
			return 0;
		}
		else if (x < 1 || x > 20 || y < 1 || y > 20) {
			printf("잘못된 입력입니다. 다시 입력해 주십시오\n\n");
			continue;
		}
		else if ((map[y][x]).hidden == 1) {
			printf("이미 선택하신 좌표입니다. 다른 좌표를 입력해 주십시오\n\n");
		}
		else {
			if ((map[y][x]).value == 9) {
				printf("그곳은 지뢰였습니다. Game Over(9:지뢰)\n\n");
				for (int i = 1; i < 21; i++) {
					for (int j = 1; j < 21; j++) {
						(map[i][j]).hidden = 1;
					}
				}
				PrintArr(map);
				return 0;
			}
			else {
				(map[y][x]).hidden = 1;
				continue;
			}
		}
		endcheck = CheckEnd(map, mine);
	}
	printf("축하합니다! 지뢰 찾기에 성공하셨습니다!");
	return 0;
}

void CreateMine(tile map[21][21], int NumOfMine) {
	int x, y;
	for (int i = 0; i < NumOfMine; i++) {
		x = rand() % 20 + 1;
		y = rand() % 20 + 1;
		if ((map[y][x]).value == 0) {
			(map[y][x]).value = 9;
		}
		else {
			i--;
			continue;
		}
	}
}

void PrintArr(tile arr[][21]) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (i == 0 && j == 0) {
				printf("  ");
				continue;
			}
			else {
				if ((arr[i][j]).hidden == 1) {
					printf("%2d", (arr[i][j]).value);
					continue;
				}
				else {
					printf("□");
				}
			}
		}
		printf("\n");
	}
}
int CheckLevel(char* str) {
	if (strcmp(str, "초급") == 1) {
		return 30;
	}
	else if (strcmp(str, "중급") == 1) {
		return 50;
	}
	else if (strcmp(str, "고급") == 1) {
		return 70;
	}
	else {
		exit(0);
	}
}

int MapSetting1(tile map[][21]) {
	int cnt = 0;
	if ((map[2][1]).value == 9) {
		cnt++;
	}
	if ((map[1][2]).value == 9) {
		cnt++;
	}
	if (map[2][2].value == 9) {
		cnt++;
	}
	return cnt;
}

int MapSetting2(tile map[][21]) {
	int cnt = 0;
	if ((map[1][19]).value == 9) {
		cnt++;
	}
	if ((map[2][19]).value == 9) {
		cnt++;
	}
	if ((map[2][20]).value == 9) {
		cnt++;
	}
	return cnt;
}

int MapSetting3(tile map[][21]) {
	int cnt = 0;
	if ((map[19][1]).value == 9) {
		cnt++;
	}
	if (map[19][2].value == 9) {
		cnt++;
	}
	if (map[20][2].value == 9) {
		cnt++;
	}
	return cnt;
}

int MapSetting4(tile map[][21]) {
	int cnt = 0;
	if ((map[19][19]).value == 9) {
		cnt++;
	}
	if (map[19][20].value == 9) {
		cnt++;
	}
	if (map[20][19].value == 9) {
		cnt++;
	}
	return cnt;
}

int MapSetLine1(tile map[][21], int x) {
	int count = 0;
	if ((map[1][x - 1]).value == 9) {
		count++;
	}
	if ((map[2][x - 1]).value == 9) {
		count++;
	}
	if ((map[2][x]).value == 9) {
		count++;
	}
	if ((map[2][x + 1]).value == 9) {
		count++;
	}
	if ((map[1][x + 1]).value == 9) {
		count++;
	}
	return count;
}

int MapSetLine2(tile map[][21], int y) {
	int count = 0;
	if ((map[y - 1][20]).value == 9) {
		count++;
	}
	if ((map[y - 1][19]).value == 9) {
		count++;
	}
	if ((map[y][19]).value == 9) {
		count++;
	}
	if ((map[y + 1][19]).value == 9) {
		count++;
	}
	if ((map[y + 1][20]).value == 9) {
		count++;
	}
	return count;
}

int MapSetLine3(tile map[][21], int x) {
	int count = 0;
	if ((map[20][x - 1]).value == 9) {
		count++;
	}
	if ((map[19][x - 1]).value == 9) {
		count++;
	}
	if ((map[19][x]).value == 9) {
		count++;
	}
	if ((map[19][x + 1]).value == 9) {
		count++;
	}
	if ((map[20][x + 1]).value == 9) {
		count++;
	}
	return count;
}

int MapSetLine4(tile map[][21], int y) {
	int count = 0;
	if ((map[y - 1][1]).value == 9) {
		count++;
	}
	if ((map[y - 1][2]).value == 9) {
		count++;
	}
	if ((map[y][2]).value == 9) {
		count++;
	}
	if ((map[y + 1][2]).value == 9) {
		count++;
	}
	if ((map[y + 1][1]).value == 9) {
		count++;
	}
	return count;
}

int MapSetAll(tile map[][21], int x, int y) {
	int cnt = 0;
	if (map[y - 1][x - 1].value == 9) {
		cnt++;
	}
	if (map[y - 1][x].value == 9) {
		cnt++;
	}
	if (map[y - 1][x + 1].value == 9) {
		cnt++;
	}
	if (map[y][x + 1].value == 9) {
		cnt++;
	}
	if (map[y + 1][x + 1].value == 9) {
		cnt++;
	}
	if (map[y + 1][x].value == 9) {
		cnt++;
	}
	if (map[y + 1][x - 1].value == 9) {
		cnt++;
	}
	if (map[y][x - 1].value == 9) {
		cnt++;
	}
	return cnt;
}

void MapSetting(tile map[][21]) {
	if ((map[1][1]).value != 9) {
		(map[1][1]).value = MapSetting1(map);
	}
	if ((map[1][20]).value != 9) {
		(map[1][20]).value = MapSetting2(map);
	}
	if ((map[20][1]).value != 9) {
		(map[20][1]).value = MapSetting3(map);
	}
	if ((map[20][20]).value != 9) {
		(map[20][20]).value = MapSetting4(map);
	}

	for (int i = 2; i < 20; i++) {
		if ((map[1][i]).value != 9) {
			(map[1][i]).value = MapSetLine1(map, i);
		}
		if ((map[i][20]).value != 9) {
			(map[i][20]).value = MapSetLine2(map, i);
		}
		if ((map[20][i]).value != 9) {
			(map[20][i]).value = MapSetLine3(map, i);
		}
		if ((map[i][1]).value != 9) {
			(map[i][1]).value = MapSetLine4(map, i);
		}
	}
	for (int i = 2; i < 20; i++) {
		for (int j = 2; j < 20; j++) {
			if (map[i][j].value != 9) {
				map[i][j].value = MapSetAll(map, j, i);
			}
		}
	}
}
int CheckEnd(tile map[][21], int NumofMine) {
	int count = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			if (map[i][j].hidden == 1) {
				count++;
			}
		}
	}
	if (count == 20 * 20 - NumofMine) {
		return 1;
	}
	else {
		return 0;
	}
}