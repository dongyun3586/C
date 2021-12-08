#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#pragma region ����ü ���ǿ� �Լ� ����

typedef struct {        //����� ����ü
    int score;          //����
    int chk[15];        //�� üĿ�� ��ġ�� ���, 1~24 : �ش� ��ġ, 0/25:���� ��, -1 : ��� ����
} player;

player pl[2];       //index�� 0�̸� �� 1�̸� ��

typedef struct {          //������ ����ü
    int num;              //�ش� ĭ�� �ִ� üĿ ��
    int clr;              //�ش� ĭ�� �ִ� üĿ �� �۴� 0, �ܴ� 1, �� ���� -1
} board;
board brd[25] = { 0 };


void gotoxy(int x, int y);      //x, y�� Ŀ���� �̵���Ű�� �Լ�
void rule();                    //��Ģ ����ȭ�� ����Լ�
void start();                   //����ȭ�� ����Լ�
void frame();                   //������ ����Լ�
void prtchk(int pos, int num, int clr);                  //�ش� ��ġ�� üĿ ��� �Լ�, clr�� -1�� ��� ���� ���
void result(int rslt);            //�¸� ���� �� ���ȭ�� ����Լ�
void wincheck(int* clr);                        //��� ���θ� �����ϰ� ��쿡 ���� ������ �ִ� �Լ�  
void boff(int* clr, int dice);                //üĿ�� ������� ��Ű�� �Լ�
void mvchk(int* clr, int dice);               //üĿ�� �̵���Ű�� �Լ�   
void turn(int* clr);    //���� �ֻ��� ������ üĿ �̵� �Լ�
void play();                    //���� �����Լ�    
#pragma endregion

int main()
{
    srand(time(NULL));
    start();

    return 0;
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void rule() {
    int key;
    system("cls");
#pragma region ����
    printf("�鰳���� �� ���� �ֻ������� ���� ����ŭ üĿ(��,��)�� �̵���Ű�� �����Դϴ�.\n");
    printf("���� 24���� 1��, ���� 1���� 24�� �̵��մϴ�.\n");
    printf("���� ��� �ֻ����� 4, 6�� ���Դٸ� �� üĿ�� 4��ŭ �̵���Ű�� �� �� üĿ(4��ŭ �̵��� �Ͱ� ���Ƶ� �ǰ� �޶� ��)�� 6��ŭ �̵���ŵ�ϴ�.\n");
    printf("�ֻ������� ���� ���ڰ� 2�� ���´ٸ� �ش� ���� �ֻ��� 4����ŭ �̵��� �� �ֽ��ϴ�.\n");
    printf("�̶� �̵��Ϸ��� ĭ�� ����� üĿ�� �� �� �ִٸ� �� üĿ�� ���� �� �ְ�, ����� üĿ�� 2���̻� �ִٸ� �ش�ĭ���� �̵��� �� �����ϴ�.\n");
    printf("üĿ�� 24��ĭ(��üĿ�� 1��ĭ)�� �Ѿ�� ��� ������� �ϸ�, ��� üĿ�� ��� ���� ��Ű�� �¸��մϴ�.\n");
    printf("��� ������ ��� üĿ�� Ȩ����(���� ��� 1~6��ĭ, ���� ��� 19~24��ĭ)�� �Ű��������� �� �� �ֽ��ϴ�.\n");
    printf("����Ű�� �Է��Ͽ� ����ȭ������ ���� �� �ֽ��ϴ�.");
#pragma endregion
    while (1) {
        key = getch();
        if (key == 13)
            return;
    }
}

void start() {
    char a = 1; //����ȭ�鿡�� ���� ���õ� ��ư ǥ��
    char key;   //�Էµ� ��ư ���
    while (1) {
        system("cls");
        gotoxy(0, 0);
#pragma region ����ȭ�� ���
        gotoxy(30, 4);
        printf("C �鰳��");
        gotoxy(29, 6);
        printf(">�����ϱ�");
        gotoxy(30, 7);
        printf("�÷��� ���");
        gotoxy(30, 8);
        printf("�׸��ϱ�");
#pragma endregion
        while (1) {
            key = getch();
            if (key == '\n')
                break;
            //�� �Ʒ� ��ư���� �̵�, ����Ű �Է����� ����
            //down 80, up 72, left 75, right 77, enter 13
            if (key == 72) {
                if (a > 1) {
                    gotoxy(29, 5 + a);
                    printf(" ");
                    a--;
                    gotoxy(29, 5 + a);
                    printf(">");
                }
            }
            else if (key == 80) {
                if (a < 3) {
                    gotoxy(29, 5 + a);
                    printf(" ");
                    a++;
                    gotoxy(29, 5 + a);
                    printf(">");
                }
            }
            else if (key == 13) {
                system("cls");
                gotoxy(0, 0);
                switch (a) {
                case 1:
                    play();
                    break;
                case 2:
                    rule();
                    break;
                case 3:
                    system("cls");
                    exit(1);
                }
                a = 1;
                break;
            }
        }
    }
}

void frame() {
    gotoxy(0, 0);
    printf("��������������������������������������������������������������������������\n");
    printf("��13��14��15��16��17��18��19��20��21��22��23��24��\n");
    printf("��������������������������������������������������������������������������\n");
    printf("���ܦ�  ��  ��  ���ۦ�  ���ۦ�  ��  ��  ��  ���ܦ�\n");          //y�� 3
    printf("���ܦ�  ��  ��  ���ۦ�  ���ۦ�  ��  ��  ��  ���ܦ�\n");
    printf("���ܦ�  ��  ��  ���ۦ�  ���ۦ�  ��  ��  ��  ��  ��\n");
    printf("���ܦ�  ��  ��  ��  ��  ���ۦ�  ��  ��  ��  ��  ��\n");
    printf("���ܦ�  ��  ��  ��  ��  ���ۦ�  ��  ��  ��  ��  ��\n");
    printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
    printf("���ۦ�  ��  ��  ��  ��  ���ܦ�  ��  ��  ��  ��  ��\n");
    printf("���ۦ�  ��  ��  ��  ��  ���ܦ�  ��  ��  ��  ��  ��\n");
    printf("���ۦ�  ��  ��  ���ܦ�  ���ܦ�  ��  ��  ��  ��  ��\n");
    printf("���ۦ�  ��  ��  ���ܦ�  ���ܦ�  ��  ��  ��  ���ۦ�\n");
    printf("���ۦ�  ��  ��  ���ܦ�  ���ܦ�  ��  ��  ��  ���ۦ�\n");          //y�� 14     
    printf("��������������������������������������������������������������������������\n");
    printf("��12��11��10�� 9�� 8�� 7�� 6�� 5�� 4�� 3�� 2�� 1��\n");
    printf("��������������������������������������������������������������������������");
}

void prtchk(int pos, int num, int clr) {
    if (num > 5)
        return;
    if (pos > 12) {
        gotoxy(3 * (pos - 12) - 2, 2 + num);
        switch (clr) {
        case -1:
            printf("  ");
            break;
        case 0:
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        }
    }
    else {
        gotoxy(3 * (12 - pos) + 1, 14 - num);
        switch (clr) {
        case -1:
            printf("  ");
            break;
        case 0:
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        }
    }
    return;
}

void result(int rslt) {
    system("cls");
    printf("���� ���\n");
    int flag = 1;
    for (int i = 0; i < 15; i++)
        if (pl[1].chk[i] > 0) {
            flag = 0;
            break;
        }
    if (flag)
        printf("2�� �����(��)��");
    else
        printf("1�� �����(��)��");
    switch (rslt) {
    case 1:
        printf("�̱۰������� 1�� ȹ���Ͽ����ϴ�.\n");
        break;
    case 2:
        printf("�������� 2�� ȹ���Ͽ����ϴ�.\n");
        break;
    case 3:
        printf("�鰳������ 3�� ȹ���Ͽ����ϴ�.\n");
        break;
    }
    pl[flag].score += rslt;
    printf("���� ���� �� %d : �� %d\n����Ű�� ������ ��� �ϰų� �齺���̽��ٷ� ������ �����մϴ�.", pl[1].score, pl[0].score);
    int key = 0;
    while (1) {
        key = getch();
        if (key == 13)
            exit(1);
        else if (key == 8)
            return;
    }

}

void wincheck(int* clr) {
    int flag = 1;
    for (int i = 0; i < 15; i++)
        if (pl[*clr].chk[i] != -1) {
            flag = 0;
            break;
        }
    if (!flag)
        return;
    int isgmn = 1;      //����(������ �Ѱ��� ������� ���� ���Ѱ��)���� Ȯ���ϴ� ����
    int isbgm = 0;      //�鰳��(���տ��� ������ ���� üĿ�� �ְų�, ������ Ȩ���忡 ���� üĿ�� �ִ� ���)���� Ȯ���ϴ� ����
    for (int i = 0; i < 15; i++) {
        if (pl[!*clr].chk[i] == 0 || pl[!*clr].chk[i] == 25) {
            isgmn = 0;
            break;
        }
        else if (pl[!*clr].chk[i] == -1)
            isbgm = 1;
        if (*clr) {
            if (pl[!*clr].chk[i] > 0 && pl[!*clr].chk[i] < 7)
                isbgm = 1;
        }
        else {
            if (pl[!*clr].chk[i] > 17 && pl[!*clr].chk[i] < 25)
                isbgm = 1;
        }
    }
    *clr = isgmn ? (isbgm ? -3 : -2) : -1;     //��쿡 ���� ������ ������ �ؼ� iswin����(����clr����)�� �����Ѵ�. ���򱸺����� 0, 1�� ����ϱ� ������ ���� ���� ������.
    return;
}

void boff(int* clr, int dice) {
    int flag = 1;
    int able[25] = { 0 };
    if (*clr)
        for (int i = 0; i < 15; i++) {
            if (pl[*clr].chk[i] > 0 && pl[*clr].chk[i] - dice < 1)
                able[pl[*clr].chk[i]]++;
        }
    else
        for (int i = 0; i < 15; i++)
            if (pl[*clr].chk[i] > 0 && pl[*clr].chk[i] + dice > 24)
                able[pl[*clr].chk[i]]++;

    for (int i = 1; i < 25; i++)
        if (able[i]) {
            if (flag) {
                gotoxy(0, 19);
                printf("                                                               \n                                                                    ");
                gotoxy(0, 19);
                printf("��� ���� ������ üĿ : ");
                flag = 0;
            }
            printf("%d��ĭ %d��, ", i, able[i]);
        }
    if (flag) {         //�̵���ų �� �ִ� üĿ�� ���� ������� ������ üĿ�� ���� ���
        gotoxy(0, 19);
        printf("                                                               \n                                                                    ");
        gotoxy(0, 19);
        printf("�̵���ų �� �ִ� üĿ�� �����ϴ�! 3�� �� ���� ��뿡�� �ѱ�ϴ�.");
        Sleep(3000);
        return;
    }
    printf("\n�̵���ų üĿ�� �ִ� ĭ�� �Է��� �ּ��� : ");
    int sel;
    while (1) {
        scanf("%d", &sel);
        if (able[sel])
            break;
        gotoxy(0, 20);
        printf("���� �߸��Ǿ����ϴ�. �̵������� üĿ�� �ִ� ĭ�� �Է��� �ּ��� : ");
    }
    for (int i = 0;; i++) {
        if (pl[*clr].chk[i] == sel) {
            prtchk(sel, brd[sel].num, -1);
            brd[sel].num--;
            if (!brd[sel].num)
                brd[sel].clr = -1;
            pl[*clr].chk[i] = -1;
        }
        else {
            prtchk(sel, brd[sel].num, -1);
            brd[sel].num--;
            if (!brd[sel].num)
                brd[sel].clr = -1;
            pl[*clr].chk[i] = -1;
        }
        wincheck(*clr);
        break;
    }
    return;
}

void mvchk(int* clr, int dice) {
    int able[25] = { 0 };
    if (*clr)
        for (int i = 0; i < 15; i++) {
            if (pl[*clr].chk[i] > dice && !(brd[i - dice].num > 1 && !brd[i - dice].clr))
                able[pl[*clr].chk[i]]++;
        }
    else
        for (int i = 0; i < 15; i++) {
            if (pl[*clr].chk[i] < 25 - dice && !(brd[i + dice].num > 1 && brd[i + dice].clr))
                able[pl[*clr].chk[i]]++;
        }
    int flag = 1;
    for (int i = 0; i < 25; i++)
        if (able[i]) {
            if (flag) {
                gotoxy(0, 19);
                printf("                                                               \n                                                                    ");
                gotoxy(0, 19);
                printf("%d��ŭ �̵� ������ üĿ : ", dice);
                flag = 0;
            }
            printf("%d��ĭ %d��, ", i, able[i]);
        }
    if (flag) {
        boff(clr, dice);
        return;
    }
    printf("\n�̵���ų üĿ�� �ִ� ĭ�� �Է��� �ּ��� : ");
    int sel;
    while (1) {
        scanf("%d", &sel);
        if (able[sel])
            break;
        gotoxy(0, 20);
        printf("���� �߸��Ǿ����ϴ�. �̵������� üĿ�� �ִ� ĭ�� �Է��� �ּ��� : ");
    }
    for (int i = 0;; i++) {
#pragma region ���üĿ �̵����
        if (pl[*clr].chk[i] == sel) {
            if (*clr) {
                if (brd[sel - dice].num > 0 && !brd[sel - dice].clr) {  //�̵��ϴ� ĭ�� ��� üĿ�� �ִ� ���
                    for (int j = 0;; j++) {
                        if (pl[!*clr].chk[j] == sel - dice) {
                            pl[!*clr].chk[j] = 0;
                            prtchk(sel, able[sel], -1);
                            brd[sel].num--;
                            prtchk(sel - dice, 1, 1);
                            brd[sel - dice].clr = *clr;

                            break;
                        }
                    }
                }
                else {      //�̵��ϴ� ĭ�� ��� üĿ�� ���� ���
                    prtchk(sel, brd[sel].num, -1);
                    brd[sel].num--;
                    brd[sel - dice].num++;
                    brd[sel - dice].clr = *clr;
                    prtchk(sel - dice, brd[sel - dice].num, 1);
                }
                pl[*clr].chk[i] -= dice;
            }
#pragma endregion
#pragma region ������ üĿ �̵����
            else {
                if (brd[sel + dice].num > 0 && !brd[sel + dice].clr) {
                    for (int j = 0;; j++) {
                        if (pl[!*clr].chk[j] == sel + dice) {
                            pl[!*clr].chk[j] = 25;
                            prtchk(sel, able[sel], -1);
                            brd[sel].num--;
                            if (!brd[sel].num)
                                brd[sel].clr = -1;
                            prtchk(sel + dice, 1, 1);
                            brd[sel + dice].clr = *clr;
                            break;
                        }
                    }
                }
                else {
                    prtchk(sel, brd[sel].num, -1);
                    brd[sel].num--;
                    if (!brd[sel].num)
                        brd[sel].clr = -1;
                    brd[sel + dice].num++;
                    brd[sel + dice].clr = *clr;
                    prtchk(sel + dice, brd[sel + dice].num, 0);
                }
                pl[*clr].chk[i] += dice;
            }
#pragma endregion

            break;
        }
    }
}

void turn(int* clr) {
    gotoxy(0, 17);
    printf("                   \n                                                               \n                                                               \n                                                                 ");
    gotoxy(0, 17);
    printf("%d�� �����(", *clr + 1);
    if (*clr)
        printf("��");
    else
        printf("��");
    printf(")�� ����\n");
    int d1, d2;
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
    printf("���� �ֻ��� ��:%d, %d\n", d1, d2);
    if (d1 == d2)
        for (int i = 0; i < 4; i++) {
            mvchk(clr, d1);
        }
    else {
        mvchk(clr, d1);
        mvchk(clr, d2);
    }
}

void play() {
    frame();
    pl[0].score = 0;
    pl[1].score = 0;    //���� �ʱ�ȭ
    while (1) {         //������ ������ �����ϱ� ���� �ݺ���
#pragma region ����� üĿ ��ġ �ʱ�ȭ
        //����ġ �ʱ�ȭ
        for (int j = 0; j < 2; j++)
            pl[0].chk[j] = 1;
        for (int j = 2; j < 7; j++)
            pl[0].chk[j] = 12;
        for (int j = 7; j < 10; j++)
            pl[0].chk[j] = 17;
        for (int j = 10; j < 15; j++)
            pl[0].chk[j] = 19;
        //����ġ �ʱ�ȭ
        for (int j = 0; j < 2; j++)
            pl[1].chk[j] = 24;
        for (int j = 2; j < 7; j++)
            pl[1].chk[j] = 13;
        for (int j = 7; j < 10; j++)
            pl[1].chk[j] = 8;
        for (int j = 10; j < 15; j++)
            pl[1].chk[j] = 6;
#pragma endregion
#pragma region ������ �ʱ�ȭ
        for (int i = 0; i < 25; i++)
            brd[i].clr = -1;
        brd[1].num = 2;
        brd[1].clr = 0;
        brd[6].num = 5;
        brd[6].clr = 1;
        brd[8].num = 3;
        brd[8].clr = 1;
        brd[12].num = 5;
        brd[12].clr = 0;
        brd[13].num = 5;
        brd[13].clr = 1;
        brd[17].num = 3;
        brd[17].clr = 0;
        brd[19].num = 5;
        brd[19].clr = 0;
        brd[24].num = 2;
        brd[24].clr = 1;
#pragma endregion
        int iswin = rand() % 2;
        while (iswin > -1) {
            iswin = !iswin;
            turn(&iswin);
        }
        result(-iswin);
    }
    return;
}

