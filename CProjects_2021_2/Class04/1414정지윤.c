#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define Max_Board 10
typedef struct {
    int row;
    int col;
}loct;

// _______________인터넷에서 가져온 함수들_________________________

HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치

int be_input()
{
    INPUT_RECORD input_record;
    DWORD input_count = 0;
    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    return input_count;
}

int get_input(WORD* vkey, COORD* pos)
{
    INPUT_RECORD input_record;
    DWORD input_count;

    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch (input_record.EventType) {
    case MOUSE_EVENT:
        if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
            CONSOLE_SCREEN_BUFFER_INFO csbi;

            GetConsoleScreenBufferInfo(COUT, &csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;

            return MOUSE_EVENT;
        }
        break;
    default:
        break;
    }

    return 0;
}

void gotoxy(int x, int y)      // 좌표 보내기 gotoxy
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

COORD clicked;  //playgame에서 사용할 좌표를 click함수에서 넘기기 위해서 전역변수 선언

// 인터넷의 코드를 가져와 원하는 영역의 입력이 있었는지 알수 있는 함수로 바꿈
int click(int xi, int yi, int xf, int yf) {
    DWORD mode;
    WORD key;
    COORD pos;

    int event;        // 마우스 이벤트에 이용

    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // 마우스 활성화
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

    while (1) {
        if (be_input())
        {
            MOUSE_EVENT;
            if (get_input(&key, &pos) != 0)
            {
                clicked.X = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
                clicked.Y = pos.Y;
                if (clicked.X >= xi && clicked.X <= xf && clicked.Y >= yi && clicked.Y <= yf) {
                    return 1;
                }
                else return 0;
            }
        }
    }
    return 0;
}

//마우스 입출력시 시스템 함수를 사용하면 안되므로 사용자 정의 함수 사용
void clearconsole() {
    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 100 * 100, Coor, &dw); // 콘솔창 화면을 지운다.
    gotoxy(0, 0);
}
//____________________________________________________________________________

void printBoard(int(*board)[Max_Board]) {
    for (int i = 0; i < Max_Board; i++) {
        for (int j = 0; j < Max_Board; j++) {
            if (board[i][j] == 1)printf("○");
            else if (board[i][j] == 2)printf("●");
            else if (board[i][j] == 3)printf("│ ");
            else if (board[i][j] == 4)printf("──");
            else if (board[i][j] == 7)printf("┼ ");
            else if (board[i][j] == 10)printf("┐ ");
            else if (board[i][j] == 11)printf("┌ ");
            else if (board[i][j] == 12)printf("└ ");
            else if (board[i][j] == 13)printf("┘ ");
            else printf("■");
        }
        printf("\n");
    }
}

//루프를 만들 때 만들어질 길에 ○ ● ┐┌ └ ┘가 있는지 확인하는 함수
int finecheck(int(*board)[Max_Board], loct l1, loct l2, int z) {
    if (l1.col < l2.col) {
        for (int i = l1.col + 1; i < l2.col; i++) {
            if (i < z)
                if (board[l1.row][i] == 1 || board[l1.row][i] == 2 || board[l1.row][i] >= 10)
                    return 0;
            if (i > z)
                if (board[l2.row][i] == 1 || board[l2.row][i] == 2 || board[l2.row][i] >= 10)
                    return 0;
            if (i == z)
                if (board[l1.row][z] == 1 || board[l1.row][z] == 2 || board[l1.row][z] >= 10 || board[l2.row][i] == 1 || board[l2.row][i] == 2 || board[l2.row][i] >= 10)
                    return 0;
        }
    }
    else {
        for (int i = l2.col + 1; i < l1.col; i++) {
            if (i < z)
                if (board[l1.row][i] == 1 || board[l1.row][i] == 2 || board[l1.row][i] >= 10)
                    return 0;
            if (i > z)
                if (board[l2.row][i] == 1 || board[l2.row][i] == 2 || board[l2.row][i] >= 10)
                    return 0;
            if (i == z)
                if (board[l1.row][z] == 1 || board[l1.row][z] == 2 || board[l1.row][z] >= 10 || board[l2.row][i] == 1 || board[l2.row][i] == 2 || board[l2.row][i] >= 10)
                    return 0;
        }
    }

    if (l1.row < l2.row) {
        for (int i = l1.row + 1; i < l2.row; i++) {
            if (board[i][z] == 1 || board[i][z] == 2 || board[i][z] >= 10)
                return 0;
        }
    }
    else {
        for (int i = l2.row + 1; i < l1.row; i++) {
            if (board[i][z] == 1 || board[i][z] == 2 || board[i][z] >= 10)
                return 0;
        }
    }
    return 1;
}

//루프를 만드는 함수
void makeLoop(int input, int(*board)[Max_Board]) {
    int z[10];
    for (int q = 0; q < input; q++) {
        loct l1, l2;
    restart:
        while (1) {
            l1.row = rand() % 10;
            l2.row = rand() % 10;
            l1.col = rand() % 10;
            l2.col = rand() % 10;
            if (!(l1.row == l2.row && l1.col == l2.col) && !(board[l1.row][l1.col] != 0 || board[l2.row][l2.col] != 0)) break;
        }

        if (l1.col > l2.col) { loct tmp = l1; l1 = l2; l2 = tmp; }
        board[l1.row][l1.col] = 1;
        board[l2.row][l2.col] = 2;

        int x = 0, letsesc = 1;
        while (1) {
            if (l1.col == l2.col) { z[q] = l1.col; }
            else z[q] = rand() % (l2.col - l1.col) + l1.col;
            for (int i = 0; i < q; i++) {
                if (z[q] == z[i]) {
                    letsesc = 0;
                    break;
                }
            }
            if (finecheck(board, l1, l2, z[q]) && letsesc) break;
            x++;
            if (x > 100) {
                board[l1.row][l1.col] = 0;
                board[l2.row][l2.col] = 0;
                goto restart;
            }
            //이동할 경로에 1또는 2가 있는지 혹은 다른 것이 있는지 확인
        }
        //1과 2사이를 잇는 줄을 만들어내기 위해 |은 3, ㅡ은 4로 표시, 굽어지는 곳은 10 또는 11로 표시
        // ㅡ 넣기
        int test = l1.row;
        for (int i = l1.col + 1; i < l2.col; i++) {
            if (i >= z[q])test = l2.row;
            if (board[test][i] == 3) {
                board[test][i] = 7;
                continue;
            }
            board[test][i] = 4;
        }

        // | 넣기
        int rowbig, rowsmal, upcorner, dwcorner;
        if (l1.row > l2.row) { rowbig = l1.row;	rowsmal = l2.row; upcorner = 11; dwcorner = 13; }
        else { rowbig = l2.row;	rowsmal = l1.row; upcorner = 10; dwcorner = 12; }

        for (int i = rowsmal; i <= rowbig; i++) {
            if (l1.row == l2.row) break;
            if (i == rowsmal && (board[i][z[q]] != 1 && board[i][z[q]] != 2)) {
                board[i][z[q]] = upcorner;
                continue;
            }
            else if (i == rowbig && (board[i][z[q]] != 1 && board[i][z[q]] != 2)) {
                board[i][z[q]] = dwcorner;
                continue;
            }
            if (board[i][z[q]] == 1 || board[i][z[q]] == 2) continue;
            if (board[i][z[q]] == 4) {
                board[i][z[q]] = 7;
                continue;
            }
            board[i][z[q]] = 3;
        }
    }
}

//게임이 끝났는지 확인해 주는 함수
int endcheck(int(*board)[Max_Board], int(*playerboard)[Max_Board]) {
    int check = 1;
    for (int i = 0; i < Max_Board * Max_Board; i++) {
        if (*(*board + i) != *(*playerboard + i)) check = 0;
    }
    if (check)return 1;
    else return 0;
}

//블록을 돌릴때 사용하는 함수
int turnBlock(int block) {
    if (block == 0 || block == 1 || block == 2 || block == 7)return block;
    else if (block == 3) return 4;
    else if (block == 4) return 3;
    else if (block == 13 || block == 11 || block == 12)return block - 1;
    else if (block == 10) return 13;
    else return -1;
}

//만들어진 루프를 섞어주는 함수
void mix(int const(*board)[Max_Board], int(*playerboard)[Max_Board]) {
    int turn;
    for (int i = 0; i < Max_Board * Max_Board; i++) {
        *(*playerboard + i) = *(*board + i);
        turn = rand() % 4;
        for (int j = 1; j <= turn; j++) {
            *(*playerboard + i) = turnBlock(*(*playerboard + i));
        }
    }
    if (endcheck(board, playerboard))mix(board, playerboard);       // 무작위로 섞었는데 처음과 같은 경우 바뀌지 않은 경우 다시 섞기
}

int playgame() {
    int board[Max_Board][Max_Board] = { 0, };
    int playerboard[Max_Board][Max_Board] = { 0, };
    int level;

input:
    gotoxy(10, 5);
    printf("1 ~ 5 난이도를 선택해 주세요 : ");
    scanf("%d", &level);
    if (level > 5 || level < 1) {
        printf("다시 입력해 주세요. ");
        goto input;
    }

    clearconsole();
    makeLoop(level, board);

    mix(board, playerboard);

    printBoard(playerboard);

    int end = 0;
    while (1) {
        if (click(0, 0, 20, 10)) {
            playerboard[clicked.Y][(clicked.X / 2)] = turnBlock(playerboard[clicked.Y][(clicked.X / 2)]);

            clearconsole();
            printBoard(playerboard);
            if (endcheck(board, playerboard)) {
                end = 1;
                break;
            }
        }
        gotoxy(26, 3); printf("● end");
        if (click(23, 0, 50, 10)) break;
    }

    if (end) {
        gotoxy(30, 5); printf("end!!");
    }
    else {
        return 0;
    }

    while (1) {
        gotoxy(25, 11); printf("아무데나 클릭하세요\n");
        if (click(0, 0, 50, 30)) {
            break;
        }
    }
    return 0;
}

void gamerule() {
    printf("게임을 시작하면 10*10보드가 주어집니다.\n");
    Sleep(1000);
    printf("○과 ● 모양의 도형이 이어지도록 막대들을\n");
    printf("돌려 모든 칸을 맞춰주시면 됩니다\n\n");
    Sleep(2000);


    printf("말로만 하니 너무 어려운가요?\n");
    Sleep(1000);
    printf("그렇다면 직접 보여드리겠습니다.\n");
    Sleep(3000);

    gotoxy(3, 6); printf("■■■■■\n");
    gotoxy(3, 7); printf("■○──┐ ■\n");
    gotoxy(3, 8); printf("■■■│ ■\n");
    gotoxy(3, 9); printf("■■■│ ■\n");
    gotoxy(3, 10); printf("■■■●■\n");

    printf("자 여기 보드가 있습니다. \n");
    Sleep(1000);
    printf("이러한 모양이 섞여서 주어지면 각 칸을 클릭하여\n");
    printf("그림과 같이 이어진 모양으로 만들어 주시면 됩니다. \n");
    Sleep(1500);
    printf("아래 보드의 (세로, 가로) = (2,3)를 클릭하세요");
    gotoxy(2, 15); printf("  0 1 2 3 4\n");
    gotoxy(2, 16); printf("0■■■■■\n");
    gotoxy(2, 17); printf("1■○──┐ ■\n");
    gotoxy(2, 18); printf("2■■■──■\n");
    gotoxy(2, 19); printf("3■■■│ ■\n");
    gotoxy(2, 20); printf("4■■■●■\n");
    while (1) {
        if (click(9, 18, 10, 18)) {
            gotoxy(9, 18); printf("│ ");
            break;
        }
    }
    gotoxy(0, 21); printf("잘하셨습니다!\n");
    Sleep(2000);
    printf("그럼 이제 게임을 시작해 볼까요? \n");
    Sleep(1000);
    while (1) {
        gotoxy(20, 25); printf("아무데나 클릭하세요\n");
        if (click(0, 0, 50, 100)) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    system("mode con cols=50 lines=30");

    while (1) {
        clearconsole();

        gotoxy(5, 1); printf("■          ■■■      ■■■    ■■■  ");
        gotoxy(5, 2); printf("■        ■      ■  ■      ■  ■    ■");
        gotoxy(5, 3); printf("■        ■      ■  ■      ■  ■■■  ");
        gotoxy(5, 4); printf("■        ■      ■  ■      ■  ■      ");
        gotoxy(5, 5); printf("■■■■    ■■■      ■■■    ■      ");

        gotoxy(16, 7);    printf("▶ start game");
        gotoxy(16, 10);    printf("▶ game rule");
        gotoxy(16, 13);    printf("▶ game end");

        if (click(16, 7, 30, 7)) {
            clearconsole();
            playgame();
            Sleep(5000);
            continue;
        }
        if (click(16, 10, 30, 10)) {
            clearconsole();
            gamerule();
            clearconsole();
            continue;
        }
        if (click(16, 13, 30, 13)) {
            clearconsole();
            printf("end");
            break;
        }
    }
}
