#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define BOARD_X 11 //게임판 크기 
#define BOARD_Y 23 
#define BOARDMOVE_X 3 //게임판 위치
#define BOARDMOVE_Y 1  

#define STAT_X BOARDMOVE_X+BOARD_X+1 //상태창 위치

int GOAL_Y; //GOAL 위치
int LEVEL_Y; //LEVEL 위치
int SCORE_Y; //점수 위치

int blocks[7][4][4][4] = {//뒤의 4*4가 블럭의 좌표를 표현해주고 앞의 4는 회전시킨 블록들 7은 블록의 종류 7개
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

int blocktype; //블록이 무엇인지
int rotation; //블록이 몇 번 회전했는지
int nextblocktype; //다음 블록이 무엇인지
int main_board[BOARD_Y][BOARD_X]; //게임판이 깜빡깜빡거리는 걸 막기 위해서 전 화면과 나중 화면을 비교해본다
int main_cpy[BOARD_Y][BOARD_X]; //위에가 실제 게임판 아래가 비교 게임판

int block_xcoordinate, block_ycoordinate;//블록의 현재 위치
int key; //키보드로 입력받은 키값을 저장 

int speed;
int level;
int level_goal;
int cnt; //제거한 줄 수
int score;
int last_score = 0;
int best_score = 0;

int new_block_key = 0; //새로운 블럭이 필요한 경우
int crush_key = 0; //현재 이동중인 블록이 충돌상태인 경우 
int levelup_key = 0; //레벨을 클리어한 경우
int spacebar_key = 0; //스페이스바를 누른 경우

void lobby();                                 //게임시작화면 
void reset();                                 //전판 기록 삭제
void reset_main();                            //게임판 내용 삭제
void reset_main_cpy();
void draw_map();                              //게임판 그리는 함수 
void draw_main();                             //게임판을 그림 
void new_block();                             //블록 생성
void check_key();                             //입력 함수(게임용으로 만든)
void drop_block();                            //스페이스바를 누를 경우
int check_crush(int block_xcoordinate, int block_ycoordinate, int rotation);    //블록에 충돌하면 0 반환
void move(int dir);                         //블록 움직이기
void check_fullline();                            //줄이 가득찼는지 확인
void check_levelup();                        //레벨업 
void check_gameover();                       //게임 종료 확인

void gotoxy(int x, int y) { //gotoxy함수(인터넷 참고) 
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
            //블록이 닿았으면 좀 더 돌릴 수 있음 
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

    gotoxy(15, 4); printf("  ■■■■■  ■■■■  ■■■■■  ■■■■  ■■■  ■■■■  "); Sleep(200);
    gotoxy(15, 5); printf("      ■      ■            ■      ■    ■    ■    ■        "); Sleep(200);
    gotoxy(15, 6); printf("      ■      ■■■■      ■      ■■■■    ■    ■■■■  "); Sleep(200);
    gotoxy(15, 7); printf("      ■      ■            ■      ■■■      ■          ■  "); Sleep(200);
    gotoxy(15, 8); printf("      ■      ■■■■      ■      ■    ■  ■■■  ■■■■  "); Sleep(200);
    gotoxy(23, 12); printf("< 시작하려면 아무 키나 클릭하세요 >"); Sleep(200);
    gotoxy(29, 15); printf("< 키 설명 >"); Sleep(200);
    gotoxy(23, 17); printf("[     ◀, ▶ : 블럭 좌우 이동     ]"); Sleep(200);
    gotoxy(23, 18); printf("[       ▲ : 블럭 회전시키기      ]"); Sleep(200);
    gotoxy(23, 19); printf("[      ▼ : 블럭 한 칸 내리기     ]"); Sleep(200);
    gotoxy(23, 20); printf("[ 스페이스바 : 블럭 끝까지 내리기 ]"); Sleep(200);

    getch();

}

void reset() {

    FILE* file = fopen("score.txt", "rt");
    if (file == 0) { best_score = 0; } //파일이 없다면 최고점수에 0을 넣음 
    else {
        fscanf(file, "%d", &best_score); // 파일이 열리면 최고점수를 불러옴 
        fclose(file); //파일 닫음 
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
    for (int i = 0; i < BOARD_Y; i++) { // 게임판 초기화  
        for (int j = 0; j < BOARD_X; j++) {
            main_board[i][j] = 0;
            main_cpy[i][j] = 100;
        }
    }
    for (int i = 1; i < BOARD_X; i++) { //천장
        main_board[3][i] = -1;
    }
    for (int i = 1; i < BOARD_Y - 1; i++) { //벽
        main_board[i][0] = 1;
        main_board[i][BOARD_X - 1] = 1;
    }
    for (int i = 0; i < BOARD_X; i++) { //바닥 
        main_board[BOARD_Y - 1][i] = 1;
    }
}

void reset_main_cpy() {
    int i, j;

    for (i = 0; i < BOARD_Y; i++) {         //게임판에 게임에 사용되지 않는 숫자를 넣음 
        for (j = 0; j < BOARD_X; j++) {  //이는 main_board와 같은 숫자가 없게 하기 위함 
            main_cpy[i][j] = 100;
        }
    }
}

void draw_map() {
    int y = 3;
    gotoxy(STAT_X, LEVEL_Y = y); printf(" LEVEL : %5d", level);
    gotoxy(STAT_X, GOAL_Y = y + 1); printf(" GOAL  : %5d", 10 - cnt);
    gotoxy(STAT_X, y + 2); printf("┌─ 다음 블록 ─┐ ");
    gotoxy(STAT_X, y + 3); printf("│             │ ");
    gotoxy(STAT_X, y + 4); printf("│             │ ");
    gotoxy(STAT_X, y + 5); printf("│             │ ");
    gotoxy(STAT_X, y + 6); printf("│             │ ");
    gotoxy(STAT_X, y + 7); printf("└─────────────┘ ");
    gotoxy(STAT_X, y + 8); printf(" 현재 점수 :");
    gotoxy(STAT_X, SCORE_Y = y + 9); printf("        %6d", score);
    gotoxy(STAT_X, y + 10); printf(" 지난 점수 :");
    gotoxy(STAT_X, y + 11); printf("        %6d", last_score);
    gotoxy(STAT_X, y + 12); printf(" 최고 점수 :");
    gotoxy(STAT_X, y + 13); printf("        %6d", best_score);
    gotoxy(STAT_X, y + 15); printf("  ▲   : 블럭 돌리기        스페이스바 : 끝까지 내리기");
    gotoxy(STAT_X, y + 16); printf("◀  ▶ : 좌우 이동  ");
    gotoxy(STAT_X, y + 17); printf("  ▼   : 한칸 내리기     ");
}

void draw_main() {
    int i, j;

    for (j = 1; j < BOARD_X - 1; j++) { //블럭이 있던 천장 다시 그리기 
        if (main_board[3][j] == 0) main_board[3][j] = -1;
    }
    for (i = 0; i < BOARD_Y; i++) {
        for (j = 0; j < BOARD_X; j++) {
            if (main_cpy[i][j] != main_board[i][j]) { //블럭 부분만 출력(바뀐 부분)
                gotoxy(BOARDMOVE_X + j, BOARDMOVE_Y + i);
                switch (main_board[i][j]) {
                case 0: //빈칸 
                    printf("  ");
                    break;
                case -1: //천장 
                    printf(". ");
                    break;
                case 1: //벽
                    printf("▩");
                    break;
                case 2: //바닥에 깔린 블럭 
                    printf("■");
                    break;
                case -2: //움직이고있는 블럭 
                    printf("□");
                    break;
                }
            }
        }
    }
    for (i = 0; i < BOARD_Y; i++) { //main_cpy에 복사  
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

    new_block_key = 0; //이제 생성할 필요 없음

    for (i = 0; i < 4; i++) {   //생성
        for (j = 0; j < 4; j++) {
            if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = -2;
        }
    }
    for (i = 1; i < 3; i++) { //상태창에 다음블록 출력
        for (j = 0; j < 4; j++) {
            if (blocks[nextblocktype][0][i][j] == 1) {
                gotoxy(STAT_X + 2 + j, i + 6);
                printf("■");
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
        if (key == 224) { //방향키는 키값이 두번들어옴
            do { key = getch(); } while (key == 224);//쓸모없는 값 처리 
            switch (key) {
            case 75:
                if (check_crush(block_xcoordinate - 1, block_ycoordinate, rotation) == 1) move(75);
                break;                            //왼쪽으로 갈 수 있으면 이동
            case 77:
                if (check_crush(block_xcoordinate + 1, block_ycoordinate, rotation) == 1) move(77);
                break;
            case 80:
                if (check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 1) move(80);
                break;
            case 72:
                if (check_crush(block_xcoordinate, block_ycoordinate, (rotation + 1) % 4) == 1) move(72);
                //회전할 수 있으면 회전
                else if (crush_key == 1 && check_crush(block_xcoordinate, block_ycoordinate - 1, (rotation + 1) % 4) == 1) move(100);
            }                    //블록 굴리기(한 칸 위 회전) 구현
        }
        else { //스페이스바  
            spacebar_key = 1;
            while (crush_key == 0) { //바닥에 닿을때까지 이동시킴 
                drop_block();
                gotoxy(STAT_X, SCORE_Y); printf("        %6d", score); //점수 표시  
            }
        }
        while (kbhit()) getch();
    }
}

void drop_block() {
    int i, j;

    if (crush_key && check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 1) crush_key = 0;
    if (crush_key && check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 0) { //부딪힐 경우
        for (i = 0; i < BOARD_Y; i++) { //블럭 고정 
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
    if (check_crush(block_xcoordinate, block_ycoordinate + 1, rotation) == 0) crush_key++; //밑으로 이동이 부딪힌 것이다
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
    case 75: //왼쪽방향 
        for (i = 0; i < 4; i++) { //현재좌표의 블럭을 지움 
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        for (i = 0; i < 4; i++) { //왼쪽으로 한칸가서 active block을 찍음 
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j - 1] = -2;
            }
        }
        block_xcoordinate--; //좌표값 이동 
        break;

    case 77:    //오른쪽 방향. 왼쪽방향이랑 같은 원리로 동작 
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

    case 80:    //아래쪽 방향. 왼쪽방향이랑 같은 원리로 동작
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

    case 72: //키보드 위쪽 눌렀을때 회전시킴. 
        for (i = 0; i < 4; i++) { //현재좌표의 블럭을 지움  
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = 0;
            }
        }
        rotation = (rotation + 1) % 4; //회전값을 1증가시킴(3에서 4가 되는 경우는 0으로 되돌림) 
        for (i = 0; i < 4; i++) { //회전된 블록을 찍음 
            for (j = 0; j < 4; j++) {
                if (blocks[blocktype][rotation][i][j] == 1) main_board[block_ycoordinate + i][block_xcoordinate + j] = -2;
            }
        }
        break;

    case 100: //블록이 구르는 기능
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

    int block_amount; //한줄의 블록갯수
    int combo = 0; //한 번에 지운 줄 수

    for (i = BOARD_Y - 2; i > 3;) {
        block_amount = 0;
        for (j = 1; j < BOARD_X - 1; j++) {
            if (main_board[i][j] > 0) block_amount++;
        }
        if (block_amount == BOARD_X - 2) {
            if (levelup_key == 0) { //레벨업이 아닐 때에만
                score += 100 * level; //점수추가 
                cnt++; //지운 줄 갯수 카운트 증가 
                combo++; //콤보수 증가  
            }
            for (k = i; k > 1; k--) { //윗줄을 한칸씩 모두 내림(윗줄이 천장이 아닌 경우에만) 
                for (l = 1; l < BOARD_X - 1; l++) {
                    if (main_board[k - 1][l] != -1) main_board[k][l] = main_board[k - 1][l];
                    if (main_board[k - 1][l] == -1) main_board[k][l] = 0;//천장은 안 내림
                }
            }
        }
        else i--;
    }
    if (combo) {
        if (combo > 1) {
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + block_ycoordinate - 1); printf(" ★★★★★★", combo);
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + block_ycoordinate - 2); printf(" ★%d COMBO!★", combo);
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + block_ycoordinate - 3); printf(" ★★★★★★", combo);
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

    if (cnt >= 10) { //레벨당 10줄
        draw_main();
        levelup_key = 1; //레벨업 처리 해야함 
        level += 1; //레벨을 1 올림 
        cnt = 0; //지운 줄수 초기화   

        for (i = 0; i < 4; i++) {
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + 4);
            printf("             ");
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 2, BOARDMOVE_Y + 6);
            printf("             ");
            Sleep(200);

            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 3, BOARDMOVE_Y + 4);
            printf("★LEVEL UP!★");
            gotoxy(BOARDMOVE_X + (BOARD_X / 2) - 2, BOARDMOVE_Y + 6);
            printf("★SPEED UP!★");
            Sleep(200);
        }
        reset_main_cpy(); //텍스트를 지우기 위해 main_cpy을 초기화.

        for (i = BOARD_Y - 2; i > BOARD_Y - 2 - (level - 1); i--) { //레벨업보상으로 각 레벨-1의 수만큼 아랫쪽 줄을 지워줌 
            for (j = 1; j < BOARD_X - 1; j++) {
                main_board[i][j] = 2; // 줄을 블록으로 모두 채우고 
                gotoxy(BOARDMOVE_X + j, BOARDMOVE_Y + i);
                printf("▣");
                Sleep(10);
            }
        }
        Sleep(300);
        check_fullline();
        switch (level) { //레벨별로 속도를 조절해줌. 
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

        gotoxy(STAT_X, LEVEL_Y); printf(" LEVEL : %5d", level); //레벨표시 
        gotoxy(STAT_X, GOAL_Y); printf(" GOAL  : %5d", 10 - cnt); // 레벨목표 표시 

    }
}

void check_gameover() {
    int i;

    int x = 5;
    int y = 5;

    for (i = 1; i < BOARD_X - 2; i++) {
        if (main_board[3][i] > 0) {
            system("cls");
            gotoxy(8, 4); printf("  ■■■■■  ■■■■■  ■■■■■  ■■■■    ■■■■■  ■      ■  ■■■■  ■■■■"); Sleep(200);
            gotoxy(8, 5); printf("  ■          ■      ■  ■  ■  ■  ■          ■      ■  ■      ■  ■        ■    ■"); Sleep(200);
            gotoxy(8, 6); printf("  ■  ■■■  ■■■■■  ■  ■  ■  ■■■■    ■      ■  ■      ■  ■■■■  ■■■■   "); Sleep(200);
            gotoxy(8, 7); printf("  ■      ■  ■      ■  ■  ■  ■  ■          ■      ■  ■      ■  ■        ■■■  "); Sleep(200);
            gotoxy(8, 8); printf("  ■■■■■  ■      ■  ■  ■  ■  ■■■■    ■■■■■  ■■■■■  ■■■■  ■    ■   "); Sleep(200);
            gotoxy(25, 12); printf("YOUR SCORE: %6d", score);
            gotoxy(25, 17); printf("다시 시작하려면 아무 키나 클릭하세요");
            last_score = score;

            if (score > best_score) {
                FILE* file = fopen("score.txt", "wt");

                gotoxy(25, 11); printf("  ★★★ BEST SCORE! ★★★     ");
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