#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int score = 0; // 점수
int board[4][4] = { // 게임판
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};

void draw(void); // 보드 그리는 함수
void new_num(void); // 보드에 2나 4를 새로 생성하는 함수
void check_game_over(void); // 게임오버인지 체크

main() {
    int i, j, r; //for문
    int key; // 입력 key 값
    int act; // key입력 후 변화 저장

    new_num(); // 새 숫자 제작
    new_num(); // 2개의 새 숫자
    draw(); // 게임판을 그림

    while (1) {
        key = getch(); //key 입력을 받음
        if (key == 0xE0 || key == 0) { //방향키의 경우 key 입력시 0xE0+키값이 두개 전달됨
            key = getch(); // 처음 0xE0 제외, 2번째 key 값 보고 판단

            switch (key) { // switch-case 문 : case는 LEFT, RIGHT, UP, DOWN 4개
            case LEFT: //1번 경우 (왼쪽 화살표)
                for (i = 0, act = 0; i < 4; i++) { //모든 행 검사
                    for (j = 1; j <= 3; j++) { // 1~3열 검사
                        for (r = j; r > 0; r--) { //j를 r에 저장하고 끝으로 밀어버림
                            if (board[i][r] == 0 || board[i][r] > 10000) break; //수가 0이거나 10000초과 시 break
                            if (board[i][r - 1] != 0 && board[i][r - 1] != board[i][r]) break; //왼쪽값이 0이 아니고 해당 블록과 다른 경우 break;
                            if (board[i][r - 1] == 0) board[i][r - 1] = board[i][r];    //자기 왼쪽값이 0인경우 자기값 복사
                            else if (board[i][r] == board[i][r - 1]) { //자기 왼쪽값과 동일한 경우에
                                board[i][r - 1] *= 2; //그 값을 2배로 (더하면 2의 거듭제곱이 됨)
                                board[i][r - 1] += 10000; // 임시 +10000, 함수 끝부분에 다시 값을 감소시킴
                                score += 2 * (board[i][r]); //점수를 증가
                            }
                            board[i][r] = 0;     //없앤 블록을 0으로 저장
                            act++; // action이 있음을 알림(get_key 함수 종료시 판단됨)
                        }
                    }
                }
                break;

            case RIGHT: //2번 경우 (오른쪽 화살표) 1번과 좌우 전환 상태 (r-1 을 r+1 로)
                for (i = 0, act = 0; i < 4; i++) { //모든 행 검사
                    for (j = 2; j >= 0; j--) { // 2~0열 검사
                        for (r = j; r < 3; r++) {
                            if (board[i][r] == 0 || board[i][r] > 10000) break;
                            if (board[i][r + 1] != 0 && board[i][r + 1] != board[i][r]) break;
                            if (board[i][r + 1] == 0) board[i][r + 1] = board[i][r];
                            else if (board[i][r] == board[i][r + 1]) {
                                board[i][r + 1] *= 2;
                                board[i][r + 1] += 10000;
                                score += 2 * (board[i][r]);
                            }
                            board[i][r] = 0;
                            act++;
                        }
                    }
                }
                break;

            case UP: //3번 경우 (위쪽 화살표) 1번과 행열 전환 상태 (r-1을 j 앞으로)
                for (j = 0, act = 0; j < 4; j++) { //모든 열 검사
                    for (i = 1; i <= 3; i++) { // 1~3행 검사
                        for (r = i; r > 0; r--) {
                            if (board[r][j] == 0 || board[r][j] > 10000) break;
                            if (board[r - 1][j] != 0 && board[r - 1][j] != board[r][j]) break;
                            if (board[r - 1][j] == 0) board[r - 1][j] = board[r][j];
                            else if (board[r][j] == board[r - 1][j]) {
                                board[r - 1][j] *= 2;
                                board[r - 1][j] += 10000;
                                score += 2 * (board[r][j]);
                            }
                            board[r][j] = 0;
                            act++;
                        }
                    }
                }
                break;

            case DOWN:  //4번 경우 (아래쪽 화살표) 3번과 상하 전환 상태 (앞에 있는 r-1을 r+1로)
                for (j = 0, act = 0; j < 4; j++) { //모든 열 검사
                    for (i = 2; i >= 0; i--) { // 2~0행 검사
                        for (r = i; r < 3; r++) {
                            if (board[r][j] == 0 || board[r][j] > 10000) break;
                            if (board[r + 1][j] != 0 && board[r + 1][j] != board[r][j]) break;
                            if (board[r + 1][j] == 0) board[r + 1][j] = board[r][j];
                            else if (board[r][j] == board[r + 1][j]) {
                                board[r + 1][j] *= 2;
                                board[r + 1][j] += 10000;
                                score += 2 * (board[r][j]);
                            }
                            board[r][j] = 0;
                            act++;
                        }
                    }
                }
                break;

            }
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (board[i][j] > 10000)
                    board[i][j] -= 10000; //아까 더한 10000을 뺌
            }
        }

        if (act > 0) { //act신호가 있었던 경우에만 (끝나면)
            new_num(); //새로운 숫자를 하나 생성
            draw(); //게임판을 새로 그림
            check_game_over(); //게임 오버를 체크
        }
    }
}

void draw(void) { // 점수판 그리기 4x4로
    int i, j;

    system("cls");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (board[i][j] == 0) printf("    ."); // 숫자 0이면 점처리
            else printf("%5d", board[i][j]); // 일정 간격 생성
        }
        printf("\n");
    }
    printf("\n");
    printf("Score : %d \n", score); //점수판, 보드 아래에 있음
}

void new_num(void) { // 2나 4 제작, 매 클릭마다
    int i, j;
    int cnt;
    int* p0[16] = { 0 };

    for (i = 0, cnt = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            if (board[i][j] == 0) {
                p0[cnt] = &board[i][j];
                cnt++;
            }
    }

    *p0[rand() % (cnt)] = (rand() % 100 < 80) ? 2 : 4; //2를 만들 확률 80%, 4를 만들 확률 20% : 2를 더 많이 만들도록 함
}

void check_game_over(void) { //게임오버인지 체크
    int i, j;

    for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (board[i][j] == 0) return;
    for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) return;
    for (i = 0; i < 3; i++) if (board[i][3] == board[i + 1][3]) return;
    for (j = 0; j < 3; j++) if (board[3][j] == board[3][j + 1]) return;

    printf("Game Over..");
    exit(0);
}