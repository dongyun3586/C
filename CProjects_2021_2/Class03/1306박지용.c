#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define BOARD_X 11 //������ ũ�� 
#define BOARD_Y 23 
#define BOARDMOVE_X 3 //������ ��ġ
#define BOARDMOVE_Y 1  

#define STAT_X BOARDMOVE_X+BOARD_X+1 //����â ��ġ

int GOAL_Y; //GOAL ��ġ
int LEVEL_Y; //LEVEL ��ġ
int SCORE_Y; //���� ��ġ

int blocks[7][4][4][4] = {//���� 4*4�� ���� ��ǥ�� ǥ�����ְ� ���� 4�� ȸ����Ų ��ϵ� 7�� ����� ���� 7��
{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},
 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},
 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
};

int blocktype; //����� ��������
int rotation; //����� �� �� ȸ���ߴ���
int nextblocktype; //���� ����� ��������
int main_board[BOARD_Y][BOARD_X]; //�������� ���������Ÿ��� �� ���� ���ؼ� �� ȭ��� ���� ȭ���� ���غ���
int main_cpy[BOARD_Y][BOARD_X]; //������ ���� ������ �Ʒ��� �� ������

int block_xcoordinate, block_ycoordinate;//����� ���� ��ġ
int key; //Ű����� �Է¹��� Ű���� ���� 

int speed;
int level;
int level_goal;
int cnt; //������ �� ��
int score;
int last_score = 0;
int best_score = 0;

int new_block_key = 0; //���ο� ���� �ʿ��� ���
int crush_key = 0; //���� �̵����� ����� �浹������ ��� 
int levelup_key = 0; //������ Ŭ������ ���
int spacebar_key = 0; //�����̽��ٸ� ���� ���

void lobby();                                 //���ӽ���ȭ�� 
void reset();                                 //���� ��� ����
void reset_main();                            //������ ���� ����
void reset_main_cpy();
void draw_map();                              //������ �׸��� �Լ� 
void draw_main();                             //�������� �׸� 
void new_block();                             //��� ����
void check_key();                             //�Է� �Լ�(���ӿ����� ����)
void drop_block();                            //�����̽��ٸ� ���� ���
int check_crush(int block_xcoordinate, int block_ycoordinate, int rotation);    //��Ͽ� �浹�ϸ� 0 ��ȯ
void move(int dir);                         //��� �����̱�
void check_fullline();                            //���� ����á���� Ȯ��
void check_levelup();                        //������ 
void check_gameover();                       //���� ���� Ȯ��

void gotoxy(int x, int y) { //gotoxy�Լ�(���ͳ� ����) 
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
int main() {
    int i;
    CursorView(FALSE);
    srand((unsigned)time(NULL));
    lobby();
    reset();

    while (1) {
        for (i = 0; i < 10; i++) {
            check_key();
            draw_main();
            Sleep(speed);
            if (crush_key && check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 0) Sleep(200);
            //����� ������� �� �� ���� �� ���� 
            if (spacebar_key == 1) {
                spacebar_key = 0;
                break;
            }
        }
        drop_block();
        check_levelup();
        check_gameover();
        if (new_block_key == 1) new_block();
    }
}

void lobby() {

    gotoxy(15, 4); printf("  ������  �����  ������  �����  ����  �����  "); Sleep(200);
    gotoxy(15, 5); printf("      ��      ��            ��      ��    ��    ��    ��        "); Sleep(200);
    gotoxy(15, 6); printf("      ��      �����      ��      �����    ��    �����  "); Sleep(200);
    gotoxy(15, 7); printf("      ��      ��            ��      ����      ��          ��  "); Sleep(200);
    gotoxy(15, 8); printf("      ��      �����      ��      ��    ��  ����  �����  "); Sleep(200);
    gotoxy(23, 12); printf("< �����Ϸ��� �ƹ� Ű�� Ŭ���ϼ��� >"); Sleep(200);
    gotoxy(29, 15); printf("< Ű ���� >"); Sleep(200);
    gotoxy(23, 17); printf("[     ��, �� : �� �¿� �̵�     ]"); Sleep(200);
    gotoxy(23, 18); printf("[       �� : �� ȸ����Ű��      ]"); Sleep(200);
    gotoxy(23, 19); printf("[      �� : �� �� ĭ ������     ]"); Sleep(200);
    gotoxy(23, 20); printf("[ �����̽��� : �� ������ ������ ]"); Sleep(200);

    getch();

}

void reset() {

    FILE* file = fopen("score.txt", "rt");
    if (file == 0) { best_score = 0; } //������ ���ٸ� �ְ������� 0�� ���� 
    else {
        fscanf(file, "%d", &best_score); // ������ ������ �ְ������� �ҷ��� 
        fclose(file); //���� ���� 
    }

    level = 1;
    score = 0;
    level_goal = 1000;
    key = 0;
    crush_key = 0;
    cnt = 0;
    speed = 100;

    system("cls");
    reset_main();
    draw_map();
    draw_main();

    nextblocktype = rand() % 7;
    new_block();

}

void reset_main() {
    for (int i = 0; i < BOARD_Y; i++) { // ������ �ʱ�ȭ  
        for (int j = 0; j < BOARD_X; j++) {
            main_board[i][j] = 0;
            main_cpy[i][j] = 100;
        }
    }
    for (int i = 1; i < BOARD_X; i++) { //õ��
        main_board[3][i] = -1;
    }
    for (int i = 1; i < BOARD_Y - 1; i++) { //��
        main_board[i][0] = 1;
        main_board[i][BOARD_X - 1] = 1;
    }
    for (int i = 0; i < BOARD_X; i++) { //�ٴ� 
        main_board[BOARD_Y - 1][i] = 1;
    }
}

void reset_main_cpy() {
    int i, j;

    for (i = 0; i < BOARD_Y; i++) {         //�����ǿ� ���ӿ� ������ �ʴ� ���ڸ� ���� 
        for (j = 0; j < BOARD_X; j++) {  //�̴� main_board�� ���� ���ڰ� ���� �ϱ� ���� 
            main_cpy[i][j] = 100;
        }
    }
}

void draw_map() {
    int y = 3;
    gotoxy(STAT_X, LEVEL_Y = y); printf(" LEVEL : %5d", level);
    gotoxy(STAT_X, GOAL_Y = y + 1); printf(" GOAL  : %5d", 10 - cnt);
    gotoxy(STAT_X, y + 2); printf("���� ���� ��� ���� ");
    gotoxy(STAT_X, y + 3); printf("��             �� ");
    gotoxy(STAT_X, y + 4); printf("��             �� ");
    gotoxy(STAT_X, y + 5); printf("��             �� ");
    gotoxy(STAT_X, y + 6); printf("��             �� ");
    gotoxy(STAT_X, y + 7); printf("������������������������������ ");
    gotoxy(STAT_X, y + 8); printf(" ���� ���� :");
    gotoxy(STAT_X, SCORE_Y = y + 9); printf("        %6d", score);
    gotoxy(STAT_X, y + 10); printf(" ���� ���� :");
    gotoxy(STAT_X, y + 11); printf("        %6d", last_score);
    gotoxy(STAT_X, y + 12); printf(" �ְ� ���� :");
    gotoxy(STAT_X, y + 13); printf("        %6d", best_score);
    gotoxy(STAT_X, y + 15); printf("  ��   : �� ������        �����̽��� : ������ ������");
    gotoxy(STAT_X, y + 16); printf("��  �� : �¿� �̵�  ");
    gotoxy(STAT_X, y + 17); printf("  ��   : ��ĭ ������     ");
}

void draw_main() {
    int i, j;

    for (j = 1; j < BOARD_X - 1; j++) { //���� �ִ� õ�� �ٽ� �׸��� 
        if (main_board[3][j] == 0) main_board[3][j] = -1;
    }
    for (i = 0; i < BOARD_Y; i++) {
        for (j = 0; j < BOARD_X; j++) {
            if (main_cpy[i][j] != main_board[i][j]) { //�� �κи� ���(�ٲ� �κ�)
                gotoxy(BOARDMOVE_X + j, BOARDMOVE_Y + i);
                switch (main_board[i][j]) {
                case 0: //��ĭ 
                    printf("  ");
                    break;
                case -1: //õ�� 
                    printf(". ");
                    break;
                case 1: //��
                    printf("��");
                    break;
                case 2: //�ٴڿ� �� �� 
                    printf("��");
                    break;
                case -2: //�����̰��ִ� �� 
                    printf("��");
                    break;
                }
            }
        }
    }
    for (i = 0; i < BOARD_Y; i++) { //main_cpy�� ����  
        for (j = 0; j < BOARD_X; j++) {
            main_cpy[i][j] = main_board[i][j];
        }
    }
}
void new_block() {
    int i, j;

    block_xcoordinate = (BOARD_X / 2) - 1;
    block_ycoordinate = 0;
    blocktype = nextblocktype;
    nextblocktype = rand() % 7;
    rotation = 0;

    new_block_key = 0; //���� ������ �ʿ� ����

    for (i = 0; i < 4; i++) {   //����
        for (j = 0; j < 4; j++) {
            if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = -2;
        }
    }
    for (i = 1; i < 3; i++) { //����â�� ������� ���
        for (j = 0; j < 4; j++) {
            if (blocks[nextblocktype][0][i][j] == 1) {
                gotoxy(STAT_X + 2 + j, i + 6);
                printf("��");
            }
            else {
                gotoxy(STAT_X + 2 + j, i + 6);
                printf("  ");
            }
        }
    }
}

void check_key() {
    key = 0;

    if (kbhit()) {
        key = getch();
        if (key == 224) { //����Ű�� Ű���� �ι�����
            do { key = getch(); } while (key == 224);//������� �� ó�� 
            switch (key) {
            case 75:
                if (check_crush(block_xcoordinate - 1, block_ycoordinate, rotation) == 1) move(75);
                break;                            //�������� �� �� ������ �̵�
            case 77:
                if (check_crush(block_xcoordinate + 1, block_ycoordinate, rotation) == 1) move(77);
                break;
            case 80:
                if (check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 1) move(80);
                break;
            case 72:
                if (check_crush(block_xcoordinate, block_ycoordinate, (rotation + 1) % 4) == 1) move(72);
                //ȸ���� �� ������ ȸ��
                else if (crush_key == 1 && check_crush(block_xcoordinate, block_ycoordinate - 1, (rotation + 1) % 4) == 1) move(100);
            }                    //��� ������(�� ĭ �� ȸ��) ����
        }
        else { //�����̽���  
            spacebar_key = 1;
            while (crush_key == 0) { //�ٴڿ� ���������� �̵���Ŵ 
                drop_block();
                gotoxy(STAT_X, SCORE_Y); printf("        %6d", score); //���� ǥ��  
            }
        }
        while (kbhit()) getch();
    }
}

void drop_block() {
    int i, j;

    if (crush_key && check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 1) crush_key = 0;
    if (crush_key && check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 0) { //�ε��� ���
        for (i = 0; i < BOARD_Y; i++) { //�� ���� 
            for (j = 0; j < BOARD_X; j++) {
                if (main_board[i][j] == -2) main_board[i][j] = 2;
            }
        }
        crush_key = 0;
        check_fullline();
        new_block_key = 1;
        return;
    }
    if (check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 1) move(80);
    if (check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 0) crush_key++; //������ �̵��� �ε��� ���̴�
}

int check_crush(int block_xcoordinate, int block_ycoordinate, int rotation) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (blocks[blocktype][rotation][i][j] == 1 && main_board[block_ycoordinate + i][block_xcoordinate + j] > 0) return 0;
        }
    }
    return 1;
};

void move(int dir) {
    int i, j;

    switch (dir) {
    case 75: //���ʹ��� 
        for (i = 0; i < 4; i++) { //������ǥ�� ���� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) { //�������� ��ĭ���� active block�� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j - 1] = -2;
            }
        }
        block_xcoordinate--; //��ǥ�� �̵� 
        break;

    case 77:    //������ ����. ���ʹ����̶� ���� ������ ���� 
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j + 1] = -2;
            }
        }
        block_xcoordinate++;
        break;

    case 80:    //�Ʒ��� ����. ���ʹ����̶� ���� ������ ����
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i + 1][block_xcoordinate + j] = -2;
            }
        }
        block_ycoordinate++;
        break;

    case 72: //Ű���� ���� �������� ȸ����Ŵ. 
        for (i = 0; i < 4; i++) { //������ǥ�� ���� ����  
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        rotation = (rotation + 1) % 4; //ȸ������ 1������Ŵ(3���� 4�� �Ǵ� ���� 0���� �ǵ���) 
        for (i = 0; i < 4; i++) { //ȸ���� ����� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = -2;
            }
        }
        break;

    case 100: //����� ������ ���
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        rotation = (rotation + 1) % 4;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i - 1][block_xcoordinate + j] = -2;
            }
        }
        block_ycoordinate--;
        break;
    }
}

void check_fullline() {
    int i, j, k, l;

    int block_amount; //������ ��ϰ���
    int combo = 0; //�� ���� ���� �� ��

    for (i = BOARD_Y - 2; i > 3;) {
        block_amount = 0;
        for (j = 1; j < BOARD_X - 1; j++) {
            if (main_board[i][j] > 0) block_amount++;
        }
        if (block_amount == BOARD_X - 2) {
            if (levelup_key == 0) { //�������� �ƴ� ������
                score += 100 * level; //�����߰� 
                cnt++; //���� �� ���� ī��Ʈ ���� 
                combo++; //�޺��� ����  
            }
            for (k = i; k > 1; k--) { //������ ��ĭ�� ��� ����(������ õ���� �ƴ� ��쿡��) 
                for (l = 1; l < BOARD_X - 1; l++) {
                    if (main_board[k - 1][l] != -1) main_board[k][l] = main_board[k - 1][l];
                    if (main_board[k - 1][l] == -1) main_board[k][l] = 0;//õ���� �� ����
                }
            }
        }
        else i--;
    }
    if (combo) {
        if (combo > 1) {
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + block_ycoordinate - 1); printf(" �ڡڡڡڡڡ�", combo);
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + block_ycoordinate - 2); printf(" ��%d COMBO!��", combo);
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + block_ycoordinate - 3); printf(" �ڡڡڡڡڡ�", combo);
            Sleep(500);
            score += (combo * level * 100);
            reset_main_cpy();
        }
        gotoxy(STAT_X, GOAL_Y);
        if (cnt <= 10) {
            printf(" GOAL  : %5d", 10 - cnt);
        }
        else {
            printf(" GOAL  : %5d", 0);
        }
        gotoxy(STAT_X, SCORE_Y); printf("        %6d", score);
    }
}

void check_levelup() {
    int i, j;

    if (cnt >= 10) { //������ 10��
        draw_main();
        levelup_key = 1; //������ ó�� �ؾ��� 
        level += 1; //������ 1 �ø� 
        cnt = 0; //���� �ټ� �ʱ�ȭ   

        for (i = 0; i < 4; i++) {
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + 4);
            printf("             ");
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 2, BOARDMOVE_Y + 6);
            printf("             ");
            Sleep(200);

            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + 4);
            printf("��LEVEL UP!��");
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 2, BOARDMOVE_Y + 6);
            printf("��SPEED UP!��");
            Sleep(200);
        }
        reset_main_cpy(); //�ؽ�Ʈ�� ����� ���� main_cpy�� �ʱ�ȭ.

        for (i = BOARD_Y - 2; i > BOARD_Y - 2 - (level - 1); i--) { //�������������� �� ����-1�� ����ŭ �Ʒ��� ���� ������ 
            for (j = 1; j < BOARD_X - 1; j++) {
                main_board[i][j] = 2; // ���� ������� ��� ä��� 
                gotoxy(BOARDMOVE_X + j, BOARDMOVE_Y + i);
                printf("��");
                Sleep(10);
            }
        }
        Sleep(300);
        check_fullline();
        switch (level) { //�������� �ӵ��� ��������. 
        case 2:
            speed = 60;
            break;
        case 3:
            speed = 50;
            break;
        case 4:
            speed = 40;
            break;
        case 5:
            speed = 30;
            break;
        case 6:
            speed = 15;
            break;
        case 7:
            speed = 10;
            break;
        case 8:
            speed = 5;
            break;
        case 9:
            speed = 2;
            break;
        case 10:
            speed = 1;
            break;
        }
        levelup_key = 0;

        gotoxy(STAT_X, LEVEL_Y); printf(" LEVEL : %5d", level); //����ǥ�� 
        gotoxy(STAT_X, GOAL_Y); printf(" GOAL  : %5d", 10 - cnt); // ������ǥ ǥ�� 

    }
}

void check_gameover() {
    int i;

    int x = 5;
    int y = 5;

    for (i = 1; i < BOARD_X - 2; i++) {
        if (main_board[3][i] > 0) {
            system("cls");
            gotoxy(8, 4); printf("  ������  ������  ������  �����    ������  ��      ��  �����  �����"); Sleep(200);
            gotoxy(8, 5); printf("  ��          ��      ��  ��  ��  ��  ��          ��      ��  ��      ��  ��        ��    ��"); Sleep(200);
            gotoxy(8, 6); printf("  ��  ����  ������  ��  ��  ��  �����    ��      ��  ��      ��  �����  �����   "); Sleep(200);
            gotoxy(8, 7); printf("  ��      ��  ��      ��  ��  ��  ��  ��          ��      ��  ��      ��  ��        ����  "); Sleep(200);
            gotoxy(8, 8); printf("  ������  ��      ��  ��  ��  ��  �����    ������  ������  �����  ��    ��   "); Sleep(200);
            gotoxy(25, 12); printf("YOUR SCORE: %6d", score);
            gotoxy(25, 17); printf("�ٽ� �����Ϸ��� �ƹ� Ű�� Ŭ���ϼ���");
            last_score = score;

            if (score > best_score) {
                FILE* file = fopen("score.txt", "wt");

                gotoxy(25, 11); printf("  �ڡڡ� BEST SCORE! �ڡڡ�     ");
                fprintf(file, "%d", score);
                fclose(file);
            }
            Sleep(1000);
            while (kbhit()) getch();
            key = getch();
            reset();
        }
    }
}