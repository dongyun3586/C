#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void SizeWarning();
void CursorView(void);
void mainscreen(int* flag);
int cntletter = 0;
int letter_place[150][70] = { 0 };

//�̷� ����
int Rendertime = 1;
void GotoXY(int x, int y);
void createmaze(void);
void printsq(void);
void generateent(void);
int mazeallow(int x, int y);
int mazeline[60][60] = { 0 };
int genmazeX = 7;
int genmazeY = 3;
void fullfillr(int x, int y);
void fullfillc(int x, int y);
int movelog[2000] = { 0 };
int movelogstate = -1;
int usualstack = 0;
int logline = 0;
int surrounded(int x, int y);
int cnt = 0;
int checkprocess(int cnt);
void finishmaze(void);
int finX = 53;
int finY = 49;

//�̷� Ǯ��
int Movingtime = 1;
void solvemazemode(void);
int GetKeyDown(void);
int caricX = 7;
int caricY = 3;
void caricmove(void);
int movingallowed(int x, int y);
void printcaric(int x, int y);
void afterimagedeleter(int x, int y);
int mazesolved(void);
void timebar(double nowtime, double finaltime);
clock_t start = 0;
clock_t end = 0;
double timepassed;
void timerstart();
double timerend();
char conamicommand[11] = { 0 };
char keylog[20] = { 'a','a','a','a','a','a','a','a','a','a' };
int kln = 0;
void conamicommandsetting();
void conamicommandactive();
int  checkconamicommand();

void credit();
void wave(int x, int y);

int main() {
    srand(time(NULL));
    CursorView();
    int flag = 1;
    SizeWarning();
    mainscreen(&flag);
    if (flag != 1)
        return 0;
    system("cls");
    createmaze();
    solvemazemode();
}

void CursorView(void) {//Ŀ��(ĳ��) ����� �Լ�
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void GotoXY(int x, int y) {//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void SizeWarning() {
    GotoXY(55, 25);
    printf("��üȭ������ �����ϼ���!!");
    Sleep(5000);
    GotoXY(55, 25);
    printf("                                                        ");
}
void mainscreen(int* flag) {//���� ���� �� ����ȭ�� ǥ��
    GotoXY(55, 25);
    printf("Maze Generator");
    GotoXY(54, 27);
    printf("Start");
    GotoXY(61, 27);
    printf("Exit");
    GotoXY(53, 27);
    printf(">");
#pragma region ���ۼ������
    int infomaX = 75;//���� ���� ���
    int infomaY = 25;
    GotoXY(infomaX, infomaY);
    printf("����������");
    GotoXY(infomaX, infomaY + 1);
    printf("�� a ��");
    GotoXY(infomaX, infomaY + 2);
    printf("����������");
    GotoXY(infomaX, infomaY + 3);
    printf(" <--");
    GotoXY(infomaX + 3, infomaY);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 1);
    printf("�� d ��");
    GotoXY(infomaX + 3, infomaY + 2);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 3);
    printf(" -->");
    GotoXY(infomaX + 6, infomaY);
    printf("����������");
    GotoXY(infomaX + 6, infomaY + 1);
    printf("�� e ��");
    GotoXY(infomaX + 6, infomaY + 2);
    printf("����������");
    GotoXY(infomaX + 6, infomaY + 3);
    printf("enter");
#pragma endregion
    while (1) {//Start�� Exit�� ������ �� �ְ� ��
        int gkdf = GetKeyDown();
        if (gkdf == 'd') {
            GotoXY(53, 27);
            printf(" ");
            GotoXY(60, 27);
            printf(">");
            *flag = 0;
        }
        else if (gkdf == 'a') {
            GotoXY(60, 27);
            printf(" ");
            GotoXY(53, 27);
            printf(">");
            *flag = 1;
        }
        else if (gkdf == 'e') {
            break;
        }
    }

}

//void background() {
//    int x = 105, y = 50;
//    x = rand() % 105;
//    y = rand() % 50;
//    GotoXY(x, y);
//    int letter;
//    letter = rand() % 3;
//    if (cntletter <= 20) {
//        if (letter == 0)
//            printf("Maze");
//        else if (letter == 1)
//            printf("C");
//        else if (letter == 2)
//            printf("Generater");
//        cntletter += 1;
//        letter_place[x][y] = 1;
//    }
//    else {
//        while (1) {
//            int findx, findy;
//            findx = rand() % 105;
//            findy = rand() % 50;
//            if (letter_place[findx][findy] == 1) {
//                letter_place[findx][findy] = 0;
//                GotoXY(findx, findy);
//                printf("         ");
//                cntletter -= 1;
//                break;
//            }
//        }
//    }
//}

void createmaze(void) {//�̷� �����
    /*
    ���� ������ �����ؼ� 4���� �� ������ ��ġ�� �̵���
    ���� �� ���� ��� �����ִٸ� �̵� ������ ����� �迭�� �ݴ�� �о�� �ϳ��� ���ư�
    */
    printsq();//�̷��� �׵θ��� �簢�� ���
    int genderection = -1;//�������� ������ 4������ ����Ǵ� ���� ����
    GotoXY(genmazeX, genmazeY);//�̷� ������������ �̵�
    mazeline[genmazeX][genmazeY] = 1;//�̷��� ������ ����Ǵ� �迭 - ���� �κ��� 1�� ����
    int flag = 0;
    printf("��");
    while (1) {
        /*
                0
              3 P 1   ���� ��ġ�� �������� �ð�������� ���� ���� ������
                2
        */
        checkprocess(cnt);//�� 575���� ĭ �� ��� ä���������� ���μ��� �� ���·� ��Ÿ����
        GotoXY(60, 4);//������� ǥ�� �κ����� �̵�
        if (!surrounded(genmazeX, genmazeY))//���� ���� ��ġ�� �ѷ����� ���¶��
            printf("The way is blocked");//�����ٰ� ���
        else
            printf("Making                      ");//�� �������� ����� ���̶�� ǥ��
        if (surrounded(genmazeX, genmazeY) == 0) {//���� �����ٸ�
            int movement = -1;//������ ������ ������ �ҷ��� ������ ������ ��
            movement = movelog[movelogstate];//�̵� ������ �����ϴ� �迭�κ��� ���� ������ �̵� ������ �ҷ���
            movelogstate -= 1;//������ �̵� ��ġ�� ��ĭ ������ �̵� ��Ŵ
#pragma region �Դ� ��� ���ư���
            if (movement == 0) {
                genmazeY += 2;
            }
            else if (movement == 1) {
                genmazeX -= 2;
            }
            else if (movement == 2) {
                genmazeY -= 2;
            }
            else if (movement == 3) {
                genmazeX += 2;
            }
#pragma endregion
            //GotoXY(60, 5);
            //printf("Considering");
            //Sleep(Rendertime * 3);
            //GotoXY(60, 5);
            //printf("Suceed!     ");
        }
        if (cnt >= 575) {//�� ���� 575�� �� ä���� ������ 575�� �̻��̸� �̷��� ���� ��� �������ٰ� �����ϰ�
            GotoXY(60, 7);
            printf("Maze Renderd!!");//�̷ΰ� ��� ��������ٰ� ���
            break;
        }
#pragma region �̷� ����
        /*
        ���� �װ��� ������ ������ ������ rnad()�Լ��� ���� ���Ѵ�. �� �ڿ� �̷θ� �� ĭ�� ������ ���ڸ� ����� �̷� ����� �˰����� Recursive Backtracking�� ����Ѵ�.
        */
        genderection = rand() % 4;//���� ���ϱ�
        if (genderection == 0) {//���� 0(�� �����̶��)�̰�
            if (mazeallow(genmazeX, genmazeY - 2)) {//���� ��ġ���� ���� 2ĭ�� �̷��� ���� �ƴϸ�
                if (mazeline[genmazeX][genmazeY - 2] == 0) {//�̹� ���� ������� ���� �ƴ϶��
                    fullfillr(genmazeX, genmazeY - 2);//2ĭ ���� �簢���� ����ϰ�
                    fullfillc(genmazeX, genmazeY - 1);//������ġ�� 2ĭ �� �簢�� ���̿��� �ٸ� ����� �簢���� ����Ѵ�.
                    cnt += 1;//ä���� ������ ������ �Ѱ� �ø���
                    genmazeY -= 2;//�̷θ� �����ϴ� ������ ��ġ�� 2ĭ ���� �ٲ۵�
                    mazeline[genmazeX][genmazeY] = 1;//�� �κ��� ���̶�� �迭�� �����ϰ�
                    mazeline[genmazeX][genmazeY + 1] = 2;//�� ���̿� �ִ� �簢���� 2��� �����Ѵ�.(�������� ����)
                    movelogstate += 1;//���� ������ �� ���ư��� ���� �迭�� ������ �� ���� ������ ����� ���� 1�� �ø���
                    movelog[movelogstate] = 0;//������ ������ ����Ѵ�.
                    usualstack = 0;//������� �ʴ� ����
                }
            }
        }
        if (genderection == 1) {
            if (mazeallow(genmazeX + 2, genmazeY)) {
                if (mazeline[genmazeX + 2][genmazeY] == 0) {
                    fullfillr(genmazeX + 2, genmazeY);
                    fullfillc(genmazeX + 1, genmazeY);
                    cnt += 1;
                    genmazeX += 2;
                    mazeline[genmazeX][genmazeY] = 1;
                    mazeline[genmazeX - 1][genmazeY] = 2;
                    movelogstate += 1;
                    movelog[movelogstate] = 1;
                    usualstack = 0;
                }
            }
        }
        if (genderection == 2) {
            if (mazeallow(genmazeX, genmazeY + 2)) {
                if (mazeline[genmazeX][genmazeY + 2] == 0) {
                    fullfillr(genmazeX, genmazeY + 2);
                    fullfillc(genmazeX, genmazeY + 1);
                    cnt += 1;
                    genmazeY += 2;
                    mazeline[genmazeX][genmazeY] = 1;
                    mazeline[genmazeX][genmazeY - 1] = 2;
                    movelogstate += 1;
                    movelog[movelogstate] = 2;
                    usualstack = 0;
                }
            }
        }

        if (genderection == 3) {
            if (mazeallow(genmazeX - 2, genmazeY)) {
                if (mazeline[genmazeX - 2][genmazeY] == 0) {
                    fullfillr(genmazeX - 2, genmazeY);
                    fullfillc(genmazeX - 1, genmazeY);
                    cnt += 1;
                    genmazeX -= 2;
                    mazeline[genmazeX][genmazeY] = 1;
                    mazeline[genmazeX + 1][genmazeY] = 2;
                    movelogstate += 1;
                    movelog[movelogstate] = 3;
                    usualstack = 0;
                }
            }
        }
#pragma endregion
    }
    finishmaze();//�̷ΰ� ��� ��������� ���� ������ �κ��� ������ ����� �������� ���������� ����Ѵ�. ����, ���������� �����Ǿ��ִ�.
    GotoXY(60, 55);
}
void printsq(void) {//�̷��� �⺻���� Ʋ�� �簢���� ����ϴ� �Լ��̴�.
    for (int i = 1; i < 51; i++) {
        GotoXY(5, i);
        printf("��");
        mazeline[5][i] = 1;
        Sleep(Rendertime);
    }
    for (int i = 0; i < 51; i++) {
        GotoXY(i + 5, 51);
        printf("��");
        mazeline[i + 5][51] = 1;
        Sleep(Rendertime);
    }
    for (int i = 51; i > 0; i--) {
        GotoXY(55, i);
        printf("��");
        mazeline[55][i] = 1;
        Sleep(Rendertime);
    }
    for (int i = 50; i > 0; i--) {
        GotoXY(i + 5, 1);
        printf("��");
        mazeline[i + 5][1] = 1;
        Sleep(Rendertime);
    }
    GotoXY(0, 55);
}
void generateent(void) {//�׽�Ʈ�� �Լ�
    GotoXY(7, 0);
    printf("  ");
    Sleep(Rendertime);
    GotoXY(53, 51);
    printf("  ");
    Sleep(Rendertime);
    GotoXY(0, 55);
}

int mazeallow(int x, int y) {//�������� ������ ������ �̷��� �������� Ȯ���ϴ� �Լ�
    if (x >= 55 || x <= 6 || y <= 1 || y >= 51)
        return 0;
    else
        return 1;
}
void fullfillr(int x, int y) {//2ĭ ���ڷ� ������ �� ������ �ٲٴ� �������� ����ϴ� �Լ�
    GotoXY(x, y);
    printf("��");
    Sleep(Rendertime);
}
void fullfillc(int x, int y) {//void fullfillr�Լ��� ä���� ���� ���̸� ä�� ���� ����ǰ� �ϴ� �Լ�
    GotoXY(x, y);
    printf("��");
}
int surrounded(int x, int y) {//������ �������� �̵����� �� 4���� ��� �����ִ����� �˻��ϴ� �Լ�
    if (mazeline[x + 2][y] == 1 && mazeline[x - 2][y] == 1 && mazeline[x][y + 2] == 1 && mazeline[x][y - 2] == 1)
        return 0;
    else
        return 1;
}
int checkprocess(int cnt) {//�󸶳� �Ϸ�Ǿ������� ���μ��� �� �������� ǥ�����ִ� �Լ�
    //full : 575
    GotoXY(60, 3);
    if (0 <= cnt && cnt < 57.5)
        printf("[ ����������� ]");
    else if (57 <= cnt && cnt < 115)
        printf("[ ����������� ]");
    else if (115 <= cnt && cnt < 172)
        printf("[ ����������� ]");
    else if (172 <= cnt && cnt < 230)
        printf("[ ����������� ]");
    else if (230 <= cnt && cnt < 287)
        printf("[ ����������� ]");
    else if (287 <= cnt && cnt < 345)
        printf("[ ����������� ]");
    else if (345 <= cnt && cnt < 402)
        printf("[ ����������� ]");
    else if (402 <= cnt && cnt < 460)
        printf("[ ����������� ]");
    else if (460 <= cnt && cnt < 517)
        printf("[ ����������� ]");
    else if (517 <= cnt && cnt < 575)
        printf("[ ����������� ]");
    else if (cnt == 575)
        printf("[ ����������� ]");
}
void finishmaze(void) {//������� �̷��� ���� ������ �� �κ��� ����ϴ� �Լ�, ������ ������, ���������� ����Ѵ�.
    for (int rendery = 1; rendery < 52; rendery++) {
        for (int renderx = 5; renderx < 56; renderx++) {
            GotoXY(renderx, rendery);
            if (mazeline[renderx][rendery] != 0)
                printf("  ");
            else
                printf("��");
            Sleep(0);
        }
    }
    GotoXY(7, 3);
    printf("S");
    GotoXY(53, 49);
    printf("E");
    GotoXY(60, 9);
    printf("Maze Generate Finisd!!");
}

void solvemazemode(void) {//����ڰ� �̷θ� Ǯ�������ִ� �Լ�
#pragma region �������
    /*
    �̷θ� Ǯ �� �ɸ��͸� �̵���ų�� �ִ� ����� 2������ �ִ�.
    ù������ wasd�� �̿��ϴ� ������� ��ĭ�� �����δ�.
    �ι����� ijkl�� �̿��ϴ� ������� �������� ����� ���� ���κ����� �ٷ� �̵��� �� �ִ�.
    */
    int infomaX = 75;
    int infomaY = 30;
    GotoXY(infomaX + 3, infomaY - 3);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 1 - 3);
    printf("�� w ��");
    GotoXY(infomaX + 3, infomaY + 2 - 3);
    printf("����������");
    GotoXY(infomaX + 6, infomaY - 2);
    printf("��");
    GotoXY(infomaX, infomaY);
    printf("����������");
    GotoXY(infomaX, infomaY + 1);
    printf("�� a ��");
    GotoXY(infomaX, infomaY + 2);
    printf("����������");
    GotoXY(infomaX, infomaY + 3);
    printf(" <--");
    GotoXY(infomaX + 3, infomaY);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 1);
    printf("�� s ��");
    GotoXY(infomaX + 3, infomaY + 2);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 3);
    printf("  ��");
    GotoXY(infomaX + 6, infomaY);
    printf("����������");
    GotoXY(infomaX + 6, infomaY + 1);
    printf("�� d ��");
    GotoXY(infomaX + 6, infomaY + 2);
    printf("����������");
    GotoXY(infomaX + 6, infomaY + 3);
    printf(" -->");

    infomaX = 75;
    infomaY = 40;
    GotoXY(infomaX + 1, infomaY - 4);
    printf("Fast Movement");
    GotoXY(infomaX + 3, infomaY - 3);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 1 - 3);
    printf("�� i ��");
    GotoXY(infomaX + 3, infomaY + 2 - 3);
    printf("����������");
    GotoXY(infomaX + 6, infomaY - 2);
    printf("��");
    GotoXY(infomaX, infomaY);
    printf("����������");
    GotoXY(infomaX, infomaY + 1);
    printf("�� j ��");
    GotoXY(infomaX, infomaY + 2);
    printf("����������");
    GotoXY(infomaX, infomaY + 3);
    printf(" <--");
    GotoXY(infomaX + 3, infomaY);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 1);
    printf("�� k ��");
    GotoXY(infomaX + 3, infomaY + 2);
    printf("����������");
    GotoXY(infomaX + 3, infomaY + 3);
    printf("  ��");
    GotoXY(infomaX + 6, infomaY);
    printf("����������");
    GotoXY(infomaX + 6, infomaY + 1);
    printf("�� l ��");
    GotoXY(infomaX + 6, infomaY + 2);
    printf("����������");
    GotoXY(infomaX + 6, infomaY + 3);
    printf(" -->");

    infomaX = 90;
    infomaY = 30;
    GotoXY(infomaX, infomaY);
    printf("����������");
    GotoXY(infomaX, infomaY + 1);
    printf("�� 0 ��");
    GotoXY(infomaX, infomaY + 2);
    printf("����������");
    GotoXY(infomaX - 1, infomaY + 3);
    printf("Speed up");
    GotoXY(infomaX, infomaY + 4);
    printf("����������");
    GotoXY(infomaX, infomaY + 5);
    printf("�� 9 ��");
    GotoXY(infomaX, infomaY + 6);
    printf("����������");
    GotoXY(infomaX - 1, infomaY + 7);
    printf("Speed down");
#pragma endregion

    timerstart();//�̷θ� Ǫ�µ� �ɸ� �ð��� �����ϴ� Ÿ�̸Ӹ� ���۽�Ű�� �Լ� - ��Ȯ���� �Լ��� ȣ��� �ð��� ������ �����ϴ� ����̴�.
    while (1) {
        end = clock();//����ð��� end��� ������ ������
        timepassed = (double)(end - start) / CLOCKS_PER_SEC;//Ÿ�̸Ӱ� ���۵� �� �ð��� �󸶳� ���������� �� ������ ���� timepassed������ ����
        GotoXY(60, 15);
        printf("%0.3f", timepassed);//���� �ð��� ��� - �ð��� �Ҽ��� ��° �ڸ������� �����Ƿ� 0.3f�� ���
        //if ((int)timepassed % 30 == 29.999) {//�̷ΰ� 30�ʸ��� �ٲ���Ϸ��� ������ �� ���α׷��� ����� �˰��� Ư���� ���������� ������� �̷θ� Ǯ�� ���ؼ� ���� ���ư����ؼ� ���� �Ǿ���. ���� ���������� �� �κ��� �ƴ� ���κ��� ���� �ִ�.
        //    Rendertime = 0;
        //    for(int i=0;i<60;i++)
        //        for(int j=0;i<60;j++)
        //            mazeline[i][j] =  0 ;
        //    createmaze();
        //}
        caricmove();//ĳ���͸� �����̴� �Լ�
        if (mazesolved()) {//ĳ���Ͱ� ���������� �����ߴ��� Ȯ��
            GotoXY(63, 47);
            printf("success!! record : %0.3f", timepassed);//�����ߴٰ� ����ϰ� �󸶳� �ɷȴ��� �����
            break;
        }
    }
}
int GetKeyDown() {//� Ű�� ���ȴ��� ��ȯ�ϴ� �Լ� - ���͸� ġ�� �ʾƵ� �ٷ� ��ȯ��
    if (_kbhit() != 0)
        return _getch();
    return 0;
}
void conamicommandsetting() {
    conamicommand[0] = 'w';
    conamicommand[1] = 'w';
    conamicommand[2] = 's';
    conamicommand[3] = 's';
    conamicommand[4] = 'a';
    conamicommand[5] = 'd';
    conamicommand[6] = 'a';
    conamicommand[7] = 'd';
    conamicommand[8] = 'b';
    conamicommand[9] = 'a';
    conamicommand[10] = '\0';
}
void caricmove(void) {//�ɸ��Ͱ� �����̰� �ϴ� �Լ�
    conamicommandsetting();
    int gkd = GetKeyDown();//� Ű�� ���ȴ��� return ����
    if (gkd == 'a') {//aŰ : ����
        if (movingallowed(caricX - 1, caricY)) {//���� �ƴ��� Ȯ���ϰ�
            afterimagedeleter(caricX, caricY);//���� ��ġ�� �ִ� ĳ���͸� ����
            caricX -= 1;//�������� 1 �̵�
            printcaric(caricX, caricY);//ĳ������ ���� ��ġ ���
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 'a';
        //GotoXY(60, 25);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 's') {
        if (movingallowed(caricX, caricY + 1)) {
            afterimagedeleter(caricX, caricY);
            caricY += 1;
            printcaric(caricX, caricY);
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 's';
        //GotoXY(60, 26);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'd') {
        if (movingallowed(caricX + 1, caricY)) {
            afterimagedeleter(caricX, caricY);
            caricX += 1;
            printcaric(caricX, caricY);
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 'd';
        //GotoXY(60, 27);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'w') {
        if (movingallowed(caricX, caricY - 1)) {
            afterimagedeleter(caricX, caricY);
            caricY -= 1;
            printcaric(caricX, caricY);
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 'w';
        //GotoXY(60, 28);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'b') {
        strcpy(keylog, keylog + 1);
        keylog[9] = 'b';
        //GotoXY(60, 29);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'j') {
        int i = 0;
        for (i = 0; movingallowed(caricX - i, caricY); i++) {
            //�������
        }
        for (int j = 0; j < i - 1; j++) {
            caricX -= 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX + j, caricY);
            Sleep(Movingtime);
        }

    }
    else if (gkd == 'k') {
        int i = 0;
        for (i = 0; movingallowed(caricX, caricY + i); i++) {
            //�������
        }
        for (int j = 0; j < i - 1; j++) {
            caricY += 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX, caricY - j);
            Sleep(Movingtime);
        }
    }
    else if (gkd == 'l') {
        int i = 0;
        for (i = 0; movingallowed(caricX + i, caricY); i++) {
            //�������
        }
        for (int j = 0; j < i - 1; j++) {
            caricX += 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX - j, caricY);
            Sleep(Movingtime);
        }
    }
    else if (gkd == 'i') {
        int i = 0;
        for (i = 0; movingallowed(caricX, caricY - i); i++) {
            //�������
        }
        for (int j = 0; j < i - 1; j++) {
            caricY -= 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX, caricY + j);
            Sleep(Movingtime);
        }
    }
    else if (gkd == '9') {//ijklŰ�� �ִϸ��̼��� ������ �Ѵ�.
        if (Movingtime - 10 > 0) {
            Movingtime -= 10;
        }

    }
    else if (gkd == '0') {//ijklŰ�� �ִϸ��̼��� ������ �Ѵ�.
        Movingtime += 10;
    }
    /*
     else if (gkd == 'i') {//�� �ڵ尡 �����Ǳ� ���� �̵� �ڵ��̴�. �����϶��� ����� ����.
        int i = 0;
        for (i = 0; movingallowed(caricX, caricY - i); i++) {
            //�������
        }
        afterimagedeleter(caricX, caricY);
        caricY -= i-1;
        printcaric(caricX, caricY);
    }
    */
    else if (gkd == 'g') {//�׽�Ʈ�� Ű : �̷θ� ���ʿ���� �ٷ� ������������ �̵��ϴ� Ű�̴�.
        afterimagedeleter(caricX, caricY);
        caricX = finX;
        caricY = finY;
        printcaric(caricX, caricY);
    }
    //GotoXY(60,17);
    //printf("(%d , %d)        ", caricX, caricY);//�׽�Ʈ�� ĳ���� ��ġ ���

    GotoXY(60, 20);
    printf("%s                    ", keylog);
    GotoXY(60, 21);
    printf("%s", conamicommand);
    keylog[10] = '\0';
    checkconamicommand();

}

int  checkconamicommand() {
    if (!strcmp(conamicommand, keylog)) {
        conamicommandactive();
    }
    return 0;
}
void conamicommandactive() {
    int** randomblank;
    randomblank = (int**)malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++)
        randomblank[i] = (int*)malloc(sizeof(int) * 100);
    int randx, randy;
    for (int i = 0; i < 2601; i++) {
        randx = rand() % 51 + 5;
        randy = rand() % 51 + 1;
        if (randomblank[randx] + randy != 1) {
            randomblank[randx][randy] = 1;
            GotoXY(randx, randy);
            printf("��");
        }
        else
            i++;
    }
    credit();
}//    ��  ��
void credit() {
    GotoXY(6, 2);
    printf("Credit");
    Sleep(1000);
    GotoXY(6, 4);
    printf("Maze Generator.");
    GotoXY(6, 5);
    printf("Made by 1208 �ŵ���");
    GotoXY(6, 7);
    printf("Conami command : w w s s a d a d b a ");
    GotoXY(6, 8);
    printf("< Game over >");
    GotoXY(6, 53);
    exit(0);
}
int movingallowed(int x, int y) {//������ �� �ִ� ������ ��ȯ�Ѵ�.
    if (mazeline[x][y] == 1 || mazeline[x][y] == 2)
        return 1;
    else
        return 0;
}
void printcaric(int x, int y) {//ĳ���͸� ����Ѵ�. ĳ���ʹ� ������ϰ� ���� ��Ʈ�̴�.
    GotoXY(x, y);
    printf("��");
}
void afterimagedeleter(int x, int y) {//ĳ������ �����ڸ��� ����� ���� �Լ�
    GotoXY(x, y);
    printf("  ");
}
int mazesolved(void) {//ĳ���Ͱ� ���������� �����ߴ��� Ȯ���ϴ� �Լ� - ĳ������ ��ǥ�� ���������� ��ǥ(����)�� ������ Ȯ���Ѵ�.
    if (caricX == finX && caricY == finY)
        return 1;
    else
        return 0;
}
//Ÿ�̸� �Լ�
double betweentime;
void timerstart() {
    betweentime = 0;
    start = clock();
}//Ÿ�̸� ���� �ð� ����
double timerend() {
    end = clock();//Ÿ�̸� ����ð� ����
    timepassed = (double)(end - start) / CLOCKS_PER_SEC; //�ʴ��� ��ȯ
    return timepassed;//�ð� ���� ��ȯ
}