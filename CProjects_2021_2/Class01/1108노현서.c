#include<stdio.h>
#include<windows.h>
#include<conio.h> //kbhit
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#define GEOY 12
#define OBSY 20
#define OBSX 45

//�ܼ��� ���ϴ� �Լ�
void SetConsoleView()
{
    system("mode con:cols=100 lines=25"); //�ܼ� ũ��(100�� ����, 25�� ����)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);//���� ���� ����
    system("title Ceometry Dash. By RoHyeonseo.");//�ֿܼ� �ߴ� ���α׷��� ����
}

//Ŀ���� ��ġ �̵� �Լ�
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���� Ű�� ��ȯ
int key()
{
    if (_kbhit() != 0) //���� � Ű�� ��������
    {
        return _getch(); //getch()�� �Է¹޾Ƽ� ��ȯ
    }
    return 0;
}

//ĳ���� ����
void character(int y)
{
    gotoxy(0, y);
    printf(" \n");
    printf("\n");
    printf("\n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("    &&&&&&&&    \n");
    printf("    && && &&    \n");
    printf("    &&&&&&&&    \n");
    printf("    &&    &&    \n");
    printf("    &&&&&&&&    \n");
}

//��ֹ� ����
void obstacle(int x)
{
    srand(time(NULL)); //�ð��� ���� ���κ��� ��µǰ� �ȵǰ� �����غ�
    int i = rand() % 3 + 1;
    gotoxy(x, OBSY);
    if (i == 3 || i == 2 || i == 1)printf("\n");
    else printf(" !! ");
    gotoxy(x, OBSY + 1);
    if (i == 2 || i == 1)printf("\n");
    else printf(" !! ");
    gotoxy(x, OBSY + 2);
    if (i == 1)printf("\n");
    else printf(" !! ");
    gotoxy(x, OBSY + 3);
    printf(" !! ");
    gotoxy(x, OBSY + 4);
    printf(" !! ");

}


//���ӿ��� �Լ�
void  gameover(const int score)
{
    system("cls"); //�ܼ��� �����ϰ� ����
    int x = 18;
    int y = 8;
    gotoxy(x, y);
    printf("---------------------------");
    gotoxy(x, y + 1);
    printf("*****G A M E O V E R*******");
    gotoxy(x, y + 2);
    printf("---------------------------");
    gotoxy(x, y + 5);
    printf("���� : %d", score);

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

int bump(const int obsx, const int geoy)
{
    gotoxy(0, 0);
    printf("obsx : %d, geoy : %d", obsx, geoy);
    if (obsx <= 8 && obsx >= 4 && geoy > 8)
        //��ֹ��� x��ǥ�� 4���� 8 ����(���� ���� ��) �϶� y��ǥ�� 8���� ũ��(8 ��ġ���� �Ʒ� ������)
    {
        return 1;//�浹�ߴ� o
    }
    return 0; //�浹 ���ߴ�
}

int jumpup(int* score, int* jumpscore) //jump �Ҷ����� score,jumpscore ��ο� ������ ������
//�� ������ �ѹ��� �ٲٱ� ���� ������ ���
{
    *score += 10; *jumpscore += 10;
}

int main()
{
    SetConsoleView();

    while (1)
    {
        int status = 0; //������ ���� ����(���� ���̸� 1, �ƴϸ� 0)
        int geoy = GEOY; //ĳ������ �ʱ� y��
        int obsx = OBSX; //��ֹ��� �ʱ� x��(������)

        int score = 0, jumpscore = 0;//����
        clock_t start, now;  //1�ʸ��� ���� �� �� �ʿ��� ����  
        start = clock();

        while (1)  //gameoverâ�� ������ ������ �ϳ� �� �������
        {
            if (bump(obsx, geoy))
                break;
            character(geoy);        //ĳ���� ����(�Ź� �������� �����������! Ŀ���� ��ġ�� �Ź� �ٲ�ϱ�)
            obstacle(obsx);        //��ֹ� ����

            if (key() == ' ')//�����̽��ٸ� ������
            {
                status = 1;    //������ ��        
            }

            if (status) //���� ���� ���̸�
            {
                geoy -= 3; //ĳ���͸� ���� �÷���(y���� �۾������� ������)
                jumpup(&score, &jumpscore);
            }
            else
            {
                geoy += 3; //���� ���� �ƴϸ� �Ʒ��� �����ֱ�
            }
            if (geoy >= GEOY)
            {
                geoy = GEOY; //�ٵ� ���� �ʱ� ���º��� �Ʒ� ������ �ʱⰪ���� ��� �̵������ֱ�
            }

            //��ֹ�
            obsx -= 2; //��ֹ��� �������� �̵�(x Ŀ������ ����)
            if (obsx <= 0)
            {
                obsx = OBSX;
            }

            if (geoy <= 3)
            {
                status = 0;
            }

            now = clock();            //����ð� �޾ƿ���
            if (((now - start) / 1000) >= 1)    // ��� ����ߴ� �ð��� ���� �ð��� ���̰� 1�ʰ� ������
            {
                score++;    //���� �߰�
                now = clock();    //���۽ð� �ʱ�ȭ
            }
            Sleep(60);
            system("cls");    //������� �� �����ֱ�

            gotoxy(11, 0);
            printf("Score : %d ", score);
        }
        gameover(score + jumpscore);
    }
    return 0;
}