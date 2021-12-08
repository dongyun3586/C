#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define Max_Board 10
typedef struct {
    int row;
    int col;
}loct;

// _______________���ͳݿ��� ������ �Լ���_________________________

HANDLE COUT = 0;    // �ܼ� ��� ��ġ
HANDLE CIN = 0;        // �ܼ� �Է� ��ġ

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

void gotoxy(int x, int y)      // ��ǥ ������ gotoxy
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

COORD clicked;  //playgame���� ����� ��ǥ�� click�Լ����� �ѱ�� ���ؼ� �������� ����

// ���ͳ��� �ڵ带 ������ ���ϴ� ������ �Է��� �־����� �˼� �ִ� �Լ��� �ٲ�
int click(int xi, int yi, int xf, int yf) {
    DWORD mode;
    WORD key;
    COORD pos;

    int event;        // ���콺 �̺�Ʈ�� �̿�

    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���콺 Ȱ��ȭ
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

    while (1) {
        if (be_input())
        {
            MOUSE_EVENT;
            if (get_input(&key, &pos) != 0)
            {
                clicked.X = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
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

//���콺 ����½� �ý��� �Լ��� ����ϸ� �ȵǹǷ� ����� ���� �Լ� ���
void clearconsole() {
    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 100 * 100, Coor, &dw); // �ܼ�â ȭ���� �����.
    gotoxy(0, 0);
}
//____________________________________________________________________________

void printBoard(int(*board)[Max_Board]) {
    for (int i = 0; i < Max_Board; i++) {
        for (int j = 0; j < Max_Board; j++) {
            if (board[i][j] == 1)printf("��");
            else if (board[i][j] == 2)printf("��");
            else if (board[i][j] == 3)printf("�� ");
            else if (board[i][j] == 4)printf("����");
            else if (board[i][j] == 7)printf("�� ");
            else if (board[i][j] == 10)printf("�� ");
            else if (board[i][j] == 11)printf("�� ");
            else if (board[i][j] == 12)printf("�� ");
            else if (board[i][j] == 13)printf("�� ");
            else printf("��");
        }
        printf("\n");
    }
}

//������ ���� �� ������� �濡 �� �� ���� �� ���� �ִ��� Ȯ���ϴ� �Լ�
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

//������ ����� �Լ�
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
            //�̵��� ��ο� 1�Ǵ� 2�� �ִ��� Ȥ�� �ٸ� ���� �ִ��� Ȯ��
        }
        //1�� 2���̸� �մ� ���� ������ ���� |�� 3, ���� 4�� ǥ��, �������� ���� 10 �Ǵ� 11�� ǥ��
        // �� �ֱ�
        int test = l1.row;
        for (int i = l1.col + 1; i < l2.col; i++) {
            if (i >= z[q])test = l2.row;
            if (board[test][i] == 3) {
                board[test][i] = 7;
                continue;
            }
            board[test][i] = 4;
        }

        // | �ֱ�
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

//������ �������� Ȯ���� �ִ� �Լ�
int endcheck(int(*board)[Max_Board], int(*playerboard)[Max_Board]) {
    int check = 1;
    for (int i = 0; i < Max_Board * Max_Board; i++) {
        if (*(*board + i) != *(*playerboard + i)) check = 0;
    }
    if (check)return 1;
    else return 0;
}

//����� ������ ����ϴ� �Լ�
int turnBlock(int block) {
    if (block == 0 || block == 1 || block == 2 || block == 7)return block;
    else if (block == 3) return 4;
    else if (block == 4) return 3;
    else if (block == 13 || block == 11 || block == 12)return block - 1;
    else if (block == 10) return 13;
    else return -1;
}

//������� ������ �����ִ� �Լ�
void mix(int const(*board)[Max_Board], int(*playerboard)[Max_Board]) {
    int turn;
    for (int i = 0; i < Max_Board * Max_Board; i++) {
        *(*playerboard + i) = *(*board + i);
        turn = rand() % 4;
        for (int j = 1; j <= turn; j++) {
            *(*playerboard + i) = turnBlock(*(*playerboard + i));
        }
    }
    if (endcheck(board, playerboard))mix(board, playerboard);       // �������� �����µ� ó���� ���� ��� �ٲ��� ���� ��� �ٽ� ����
}

int playgame() {
    int board[Max_Board][Max_Board] = { 0, };
    int playerboard[Max_Board][Max_Board] = { 0, };
    int level;

input:
    gotoxy(10, 5);
    printf("1 ~ 5 ���̵��� ������ �ּ��� : ");
    scanf("%d", &level);
    if (level > 5 || level < 1) {
        printf("�ٽ� �Է��� �ּ���. ");
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
        gotoxy(26, 3); printf("�� end");
        if (click(23, 0, 50, 10)) break;
    }

    if (end) {
        gotoxy(30, 5); printf("end!!");
    }
    else {
        return 0;
    }

    while (1) {
        gotoxy(25, 11); printf("�ƹ����� Ŭ���ϼ���\n");
        if (click(0, 0, 50, 30)) {
            break;
        }
    }
    return 0;
}

void gamerule() {
    printf("������ �����ϸ� 10*10���尡 �־����ϴ�.\n");
    Sleep(1000);
    printf("�۰� �� ����� ������ �̾������� �������\n");
    printf("���� ��� ĭ�� �����ֽø� �˴ϴ�\n\n");
    Sleep(2000);


    printf("���θ� �ϴ� �ʹ� ������?\n");
    Sleep(1000);
    printf("�׷��ٸ� ���� �����帮�ڽ��ϴ�.\n");
    Sleep(3000);

    gotoxy(3, 6); printf("������\n");
    gotoxy(3, 7); printf("��ۦ����� ��\n");
    gotoxy(3, 8); printf("���ᦢ ��\n");
    gotoxy(3, 9); printf("���ᦢ ��\n");
    gotoxy(3, 10); printf("����ܡ�\n");

    printf("�� ���� ���尡 �ֽ��ϴ�. \n");
    Sleep(1000);
    printf("�̷��� ����� ������ �־����� �� ĭ�� Ŭ���Ͽ�\n");
    printf("�׸��� ���� �̾��� ������� ����� �ֽø� �˴ϴ�. \n");
    Sleep(1500);
    printf("�Ʒ� ������ (����, ����) = (2,3)�� Ŭ���ϼ���");
    gotoxy(2, 15); printf("  0 1 2 3 4\n");
    gotoxy(2, 16); printf("0������\n");
    gotoxy(2, 17); printf("1��ۦ����� ��\n");
    gotoxy(2, 18); printf("2���ᦡ����\n");
    gotoxy(2, 19); printf("3���ᦢ ��\n");
    gotoxy(2, 20); printf("4����ܡ�\n");
    while (1) {
        if (click(9, 18, 10, 18)) {
            gotoxy(9, 18); printf("�� ");
            break;
        }
    }
    gotoxy(0, 21); printf("���ϼ̽��ϴ�!\n");
    Sleep(2000);
    printf("�׷� ���� ������ ������ �����? \n");
    Sleep(1000);
    while (1) {
        gotoxy(20, 25); printf("�ƹ����� Ŭ���ϼ���\n");
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

        gotoxy(5, 1); printf("��          ����      ����    ����  ");
        gotoxy(5, 2); printf("��        ��      ��  ��      ��  ��    ��");
        gotoxy(5, 3); printf("��        ��      ��  ��      ��  ����  ");
        gotoxy(5, 4); printf("��        ��      ��  ��      ��  ��      ");
        gotoxy(5, 5); printf("�����    ����      ����    ��      ");

        gotoxy(16, 7);    printf("�� start game");
        gotoxy(16, 10);    printf("�� game rule");
        gotoxy(16, 13);    printf("�� game end");

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
