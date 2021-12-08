#include<stdio.h>

typedef struct {
	int state[19][19];
}State;

void print_state(State state) { //현재 상태를 표시 흑돌이 놓였는 '○'경우에는 표시를, 백돌이 놓여있는 경우에는 '●'표시를 한다.
	printf("\n■■■■■■■■■■■■■■■■■■■■■\n"); //경계를 표시
	for (int i = 0; i < 19; i++) {
		printf("■");
		for (int j = 0; j < 19; j++) {
			if ((state.state)[i][j] == 1) //백돌(1)이 놓여있는 경우
				printf("○");
			else if ((state.state)[i][j] == 2) //흑돌(2)이 놓여있는 경우
				printf("●");
			else //아무 도도 놓여있지 않은 경우
				printf("  ");
		}printf("■\n");
	}printf("■■■■■■■■■■■■■■■■■■■■■\n\n"); //경계를 표시
	return;
}
int determinent(State state) { //흑 또는 백이 5줄이 완성이 되었는 가를 판별
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if ((state.state)[i][j] == 1) { //백의 오목 완성 여부를 판별
				if ((state.state)[i + 1][j] == 1 && (state.state)[i + 2][j] == 1 && (state.state)[i + 3][j] == 1 && (state.state)[i + 4][j] == 1) { //가로로 놓인 것을 판별
					printf("********************!!!백 승!!!********************");
					return 0;
				}
				else if ((state.state)[i][j + 1] == 1 && (state.state)[i][j + 2] == 1 && (state.state)[i][j + 3] == 1 && (state.state)[i][j + 4] == 1) { //세로로  놓인 것을 판별
					printf("********************!!!백 승!!!********************");
					return 0;
				}
				else if ((state.state)[i - 1][j + 1] == 1 && (state.state)[i - 2][j + 2] == 1 && (state.state)[i - 3][j + 3] == 1 && (state.state)[i - 4][j + 4] == 1) { //오른쪽 위 대각선으로 놓인 것을 판별
					printf("********************!!!백 승!!!********************");
					return 0;
				}
				else if ((state.state)[i + 1][j + 1] == 1 && (state.state)[i + 2][j + 2] == 1 && (state.state)[i + 3][j + 3] == 1 && (state.state)[i + 4][j + 4] == 1) { //오른쪽 아래 대각선으로 놓인 것을 판별
					printf("********************!!!백 승!!!********************");
					return 0;
				}
			}
			else if ((state.state)[i][j] == 2) { //흑의 오목 완성 여부를 판별
				if ((state.state)[i + 1][j] == 2 && (state.state)[i + 2][j] == 2 && (state.state)[i + 3][j] == 2 && (state.state)[i + 4][j] == 2) { //가로로 놓인 것을 판별
					printf("********************!!!흑 승!!!********************");
					return 0;
				}
				else if ((state.state)[i][j + 1] == 2 && (state.state)[i][j + 2] == 2 && (state.state)[i][j + 3] == 2 && (state.state)[i][j + 4] == 2) { //세로로  놓인 것을 판별
					printf("********************!!!흑 승!!!********************");
					return 0;
				}
				else if ((state.state)[i - 1][j + 1] == 2 && (state.state)[i - 2][j + 2] == 2 && (state.state)[i - 3][j + 3] == 2 && (state.state)[i - 4][j + 4] == 2) { //오른쪽 위 대각선으로 놓인 것을 판별
					printf("********************!!!흑 승!!!********************");
					return 0;
				}
				else if ((state.state)[i + 1][j + 1] == 2 && (state.state)[i + 2][j + 2] == 2 && (state.state)[i + 3][j + 3] == 2 && (state.state)[i + 4][j + 4] == 2) { //오른쪽 아래 대각선으로 놓인 것을 판별
					printf("********************!!!흑 승!!!********************");
					return 0;
				}
			}
		}
	}return 1;
}

int main() {
	int x = 0, y = 0, s = 0, g = 0; // (x,y)는 돌을 놓는 위치를 저장하는 변수, s는 흑이 놓을지 백이 놓을지를 저장하는 변수, g는 오목이 완성 되었는지를 판단하는 변수
	State state;

	for (int i = 0; i < 19; i++) { //state를 초기화
		for (int j = 0; j < 19; j++)
			(state.state)[i][j] = 0;
	}

	while (1) {
		if (s == 0) {
			printf("흑(x, y) : ");
			scanf("%d %d", &x, &y);

			if ((state.state)[x][y] == 0) //선택한 위치에 흑돌을 놓는다
				(state.state)[x][y] = 2;
			else { //같은 위치에 둔 경우를 제외
				printf("중복해서 둘 수 없습니다!\n");
				continue;
			}
			s = 1; //다음 돌을 백돌으로
		}
		else if (s == 1) {
			printf("백(x, y) : ");
			scanf("%d %d", &x, &y);

			if ((state.state)[x][y] == 0)//선택한 위치에 흑돌을 놓는다
				(state.state)[x][y] = 1;
			else { //같은 위치에 둔 경우를 제외
				printf("중복해서 둘 수 없습니다!\n");
				continue;
			}
			s = 0; //다음 돌을 흑돌으로
		}
		print_state(state); //현재 돌들이 놓인 상태를 표시
		g = determinent(state); //오목 완성 여부를 판별
		if (g == 0)
			break; //오목이 완성되면 while문 밖으로 나가기
	}
}