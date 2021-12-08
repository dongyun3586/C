#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct _tile {
	int value;
	int hidden;				//hidden => 0, open => 1
}tile;

void CreateMine(tile map[21][21], int NumOfMine);			//���� ���� ���� �Լ�
void PrintArr(tile arr[][21]);
int CheckLevel(char* str);						//���̵� üũ �Լ�
void MapSetting(tile map[][21]);				//��ü �� ���� �Լ�(���� �� ǥ��)
int MapSetting1(tile map[][21]);				//(1, 1) ���� �Լ�
int MapSetting2(tile map[][21]);				//(1, 20)���� �Լ�
int MapSetting3(tile map[][21]);				//(20, 1)���� �Լ�
int MapSetting4(tile map[][21]);				//(20, 20)���� �Լ�
int MapSetLine1(tile map[][21], int x);			//(1, x)���� �Լ�
int MapSetLine2(tile map[][21], int y);			//(y, 20)���� �Լ�
int MapSetLine3(tile map[][21], int x);			//(20, x)���� �Լ�
int MapSetLine4(tile map[][21], int y);			//(y, 1)���� �Լ�
int MapSetAll(tile map[][21], int x, int y);		//������ �κ� ���� �Լ�
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

	printf("����ã�� ���α׷�\n\n");
	printf("���ϴ� ��带 ������ �ֽʽÿ� 1: ���� ���� ���� ���, 2: ���� ���̵� ���� ���\n");
	scanf("%d", &mode);
	while (1) {
		if (mode < 1 || mode > 2) {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ֽʽÿ�\n");
			scanf("%d", &mode);
			continue;
		}
		else {
			break;
		}
	}

	if (mode == 1) {
		printf("���� ������ ������ �ּ���(30�� ~ 100��)\n");
		scanf("%d", &mine);
		while (1) {
			if (mine < 30 || mine > 100) {
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ֽʽÿ�\n");
				scanf("%d", &mine);
				continue;
			}
			else {
				break;
			}
		}
	}
	else if (mode == 2) {
		printf("���̵��� ������ �ּ���\n�ʱ�:30��, �߱�:50��, ���: 70��\n");
		scanf("%s", str);
		mine = CheckLevel(str);
	}
	CreateMine(map, mine);
	MapSetting(map);

	while (endcheck == 0) {
		PrintArr(map);
		printf("��Ʈ�� ��ǥ�� �Է��� �ּ���(x, y), (��, x, y�� ����: 1�̻� 20����)\n�����Ͻ÷��� -1,-1�� �Է��ϼ���\n");
		scanf("%d, %d", &x, &y);
		if (x == -1 && y == -1) {
			for (int i = 1; i < 21; i++) {
				for (int j = 1; j < 21; j++) {
					(map[i][j]).hidden = 1;
				}
			}
			printf("\n��ź���� ��ġ�Դϴ�.(9:����)\n\n");
			PrintArr(map);
			return 0;
		}
		else if (x < 1 || x > 20 || y < 1 || y > 20) {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ֽʽÿ�\n\n");
			continue;
		}
		else if ((map[y][x]).hidden == 1) {
			printf("�̹� �����Ͻ� ��ǥ�Դϴ�. �ٸ� ��ǥ�� �Է��� �ֽʽÿ�\n\n");
		}
		else {
			if ((map[y][x]).value == 9) {
				printf("�װ��� ���ڿ����ϴ�. Game Over(9:����)\n\n");
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
	printf("�����մϴ�! ���� ã�⿡ �����ϼ̽��ϴ�!");
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
					printf("��");
				}
			}
		}
		printf("\n");
	}
}
int CheckLevel(char* str) {
	if (strcmp(str, "�ʱ�") == 1) {
		return 30;
	}
	else if (strcmp(str, "�߱�") == 1) {
		return 50;
	}
	else if (strcmp(str, "���") == 1) {
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