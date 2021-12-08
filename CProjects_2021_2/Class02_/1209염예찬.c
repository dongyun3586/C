/*   �� ������ ���̵��� 1209 �������� ����س��� ���� �ƴ϶�� ����� �����ϴ�   */


//���� ��������� ���� �ڵ��� �������� ����
#include "snakeheader.h"

//��ǥ���� �����ϰ� �����ϱ� ���� ����ü ����
typedef struct {
    int x;
    int y;
}Point;

Point* snakebody;

int foodlocationx, foodlocationy; //food�� ��ǥ���� ���� 
int snakelength; //�����̸� ��� 
int speed; //���� �ӵ� (Sleep()�Լ� �ӿ� �־ �ӵ��� ����)
int score; //���� ����
int dir; //�̵����� ���� (direction)
int key; //�Է¹��� Ű ����

void startTitle(void);
void reset(void);
void drawmap(void);
void move(int dir);
int checkbodycrash(void);
void gameoverTitle(void);
void food(void);
int crashmap(void);
void printsnake(void);


int main(void) {

    CursorView(); //ĳ�� ������
    snakebody = (Point*)malloc(100 * sizeof(Point));

    startTitle();

    while (1) {
        if (_kbhit()) do {
            key = _getch();
        } while (key == 224); //Ű �Է¹���
        Sleep(speed);

        switch (key) { //�Է¹��� Ű�� �ľ��ϰ� ����  
        case LEFTKEY:
        case RIGHTKEY:
        case TOPKEY:
        case DOWNKEY:
            if ((dir == LEFTKEY && key != RIGHTKEY) || (dir == RIGHTKEY && key != LEFTKEY) || (dir == TOPKEY && key != DOWNKEY) || (dir == DOWNKEY && key != TOPKEY)) {//180ȸ���̵��� �����ϱ� ���� �ʿ� (�Ӹ��� ���ڱ� ���뿡 �浿�ϴ� ���� ������
                dir = key;
            }
            key = 0; // Ű���� �����ϴ� �Լ��� reset 
            break;
        }

        move(dir);
    }
}

void startTitle(void) {

    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ����

    drawmap();    //�� �׵θ��� �׸� 
    for (int i = MAPY + 1; i < MAPY + MAPHEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
        for (int j = MAPX + 1; j < MAPX + MAPWIDTH - 1; j++) gotoxy(j, i, "  ");
    }

    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 5, "   +--------------------------+");
    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 6, "   |       ������ũ ����      |");
    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 7, "   +--------------------------+");

    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 9, "       < PRESS ANY KEY >");

    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 11, "   () ��,��,��,�� : Move    ");
    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 12, "   () ESC : Quit              ");

    while (1) {
        if (_kbhit()) { //Ű�Է¹��� 
            key = _getch();
            if (key == 27) exit(0); // ESCŰ�� ���� 
            else break; //�ƴϸ� �׳� ��� ���� 
        }
        gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 9, "       < PRESS ANY KEY > ");
        Sleep(400);
        gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 9, "                            ");
        Sleep(400);

    }
    reset(); // ������ �ʱ�ȭ  
}

void reset(void) {
    int i;
    system("cls");
    drawmap(); //�� �׵θ��� �׸� 
    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� �������� (������ �ִ� Ű�� ���� ������ �������ڸ��� �̻��� �������� �귯���°��� ����)

    snakelength = 5; //�� ���� �ʱ�ȭ 
    score = 0; //���� �ʱ�ȭ 

    dir = LEFTKEY;
    speed = 100; // �ӵ��� 100���� �ʱ�ȭ (ȭ���� �����Ÿ��� �ӵ��� 0.1�ʷ� �⺻����)

    for (i = 0; i < snakelength; i++) {
        snakebody[i].x = MAPWIDTH / 2 + i;
        snakebody[i].y = MAPHEIGHT / 2;
        gotoxy(MAPX + snakebody[i].x, MAPY + snakebody[i].y, "��"); //�� ���� �׸�
    }
    gotoxy(MAPX + snakebody[0].x, MAPY + snakebody[0].y, "��"); //�� �Ӹ� �׸� (�Ӹ��� 1���̴�)
    food(); // food ����  
}

void drawmap(void) { //�� �׵θ� �׸��� �Լ� 
    int i, j;
    for (i = 0; i < MAPWIDTH; i++) {
        gotoxy(MAPX + i, MAPY, "��");
    }
    for (i = MAPY + 1; i < MAPY + MAPHEIGHT - 1; i++) {
        gotoxy(MAPX, i, "��");
        gotoxy(MAPX + MAPWIDTH - 1, i, "��");
    }
    for (i = 0; i < MAPWIDTH; i++) {
        gotoxy(MAPX + i, MAPY + MAPHEIGHT - 1, "��");
    }
}

int checkbodycrash(void) {
    int flag = 0;
    for (int i = 1; i < snakelength; i++) {
        if (snakebody[0].x == snakebody[i].x && snakebody[0].y == snakebody[i].y) {
            flag = 1;
        }
    }
    return flag;
}

int crashmap(void) {
    int flag = 0;
    if (snakebody[0].x == 0 || snakebody[0].x == MAPWIDTH - 1 || snakebody[0].y == 0 || snakebody[0].y == MAPHEIGHT - 1) { //���� �浹���� ��� 
        flag = 1;
    }
    return flag;
}

void printsnake(void) {
    int i;
    gotoxy(MAPX + snakebody[snakelength - 1].x, MAPY + snakebody[snakelength - 1].y, "  "); //���� �������� ���� 
    for (i = snakelength - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
        snakebody[i].x = snakebody[i - 1].x;
        snakebody[i].y = snakebody[i - 1].y;
    }
    gotoxy(MAPX + snakebody[0].x, MAPY + snakebody[0].y, "��"); //�Ӹ��� �ִ����� �������� ��ħ 
    if (dir == LEFTKEY) --snakebody[0].x; //���⿡ ���� ���ο� �Ӹ���ǥ([0].,y[0])���� ���� 
    if (dir == RIGHTKEY) ++snakebody[0].x;
    if (dir == TOPKEY) --snakebody[0].y;
    if (dir == DOWNKEY) ++snakebody[0].y;
    gotoxy(MAPX + snakebody[i].x, MAPY + snakebody[i].y, "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 
}

void move(int dir) {
    int i;
    if (snakebody[0].x == foodlocationx && snakebody[0].y == foodlocationy) { //food�� �浹���� ��� 
        score += 10; //���� ���� 
        food(); //���ο� food �߰� 
        snakelength++; //�������� 
        snakebody[snakelength - 1].x = snakebody[snakelength - 2].x; //���θ��� ���뿡 �� �Է� 
        snakebody[snakelength - 1].y = snakebody[snakelength - 2].y;
    }
    if (crashmap() == 1) { //���� �浹���� ��� 
        gameoverTitle();
        return;
    }

    if (checkbodycrash() == 1) { //���� �浹���� ���
        gameoverTitle();
        return;
    }

    printsnake();
}

void gameoverTitle(void) { //�������� �Լ� 
    system("cls");
    gotoxy(MAPX + (MAPWIDTH / 2) - 6, MAPY + 7, "  ���� ����\n                    ���� : ");
    printf("%d", score);
    gotoxy(MAPX + (MAPWIDTH / 2) - 9, MAPY + 12, " �ƹ� Ű�� ������ ������ �ٽ� ���۵˴ϴ�... ");
    Sleep(500);
    while (_kbhit()) _getch(); //Ű�� ���������� ��ٸ��� ����
    key = _getch();
    startTitle();
}

void food(void) {

    int flag = 0;//food�� �� ������ǥ�� ���� ���
    gotoxy(MAPX, MAPY + MAPHEIGHT, " YOUR SCORE: "); //����ǥ�� 
    printf("%d", score);
    while (1) {
        flag = 0;
        srand((unsigned)time(NULL)); //����ǥ���� 
        foodlocationx = (rand() % (MAPWIDTH - 2)) + 1;
        foodlocationy = (rand() % (MAPHEIGHT - 2)) + 1;
        for (int i = 0; i < snakelength; i++) { //food�� �� ����� ��ġ���� Ȯ���ϴ� ����
            if (foodlocationx == snakebody[i].x && foodlocationy == snakebody[i].y) {
                flag = 1; //��ġ�� flag�� ���� ����
                break;
            }
        }
        if (flag == 1) {
            continue; //������ ��� while���� �ٽ� ���� 
        }
        int randnum = rand() % 100 + 1;
        if (randnum > 0 && randnum <= 70) {
            gotoxy(MAPX + foodlocationx, MAPY + foodlocationy, "��"); //�Ȱ����� ��� ��ǥ���� food�� ��� 
            speed -= 3; //�ӵ� 3 ����
            break;
        }
        if (randnum > 70 && randnum <= 95) {
            gotoxy(MAPX + foodlocationx, MAPY + foodlocationy, "��"); //�Ȱ����� ��� ��ǥ���� food�� ��� 
            speed -= 5; //�ӵ� 5 ����
            break;
        }
        if (randnum > 95 && randnum <= 100) {
            gotoxy(MAPX + foodlocationx, MAPY + foodlocationy, "��"); //�Ȱ����� ��� ��ǥ���� food�� ��� 
            speed += 10; //�ӵ� ����
            break;
        }
    }
}