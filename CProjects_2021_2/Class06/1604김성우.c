#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>

void textcolor(int backcolor, int textcolor);
void drowing(char* t);
int randnumber(int i);
void painting(char b, char t);

int main()
{
    srand(time(NULL));
    system("mode con:cols=66 lines=48"); //ĵ���� ũ��
    system("color F0"); //ĵ���� ��� ����

    int num;

    printf("�׸��׸��� ��带 �����Ͻÿ�\n");
    printf("1:����� ���� 2:Artificial paintter\n");
    scanf("%d", &num);

    if (num == 1)
    {
        int back, text;
        printf("�׸��� ������ ���ڸ� �����Ͻÿ�\n");
        printf("BLACK=1, BLUE=2, GREEN=3, CYAN=4, RED=5\n");
        printf("MAGENTA=6, BROWN=7, LIGHTGRAY=8, DARKGRAY=9, LIGHTBLUE=10\n");
        printf(" LIGHTGREEN=11, LIGHTCYAN=12, LIGHTRED=13, LIGHTMAGENTA=14, YELLOW=15\n");
        printf("WHITE=16\n");

        printf("����: ");
        scanf("%s", &back);
        printf("���ڻ�: ");
        scanf("%s", &text);

        text--;
        back--;

        painting(back, text);
    }
    else if (num == 2)
    {
        char* p = (char*)malloc(32);
        printf("���Ǵ� ����: ");
        scanf("%s", p);
        drowing(p);

        free(p);
    }
    else
    {
        printf("�߸��� �Է��Դϴ�.");
    }
    return 0;
}

void textcolor(int backcolor, int textcolor)
{
    int color = backcolor + textcolor * 16;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
} //textcolor(���ڻ�,����)

void drowing(char* t)
{
    srand(time(NULL));
    for (int i = 0; i < 66 * 48; i++)
    {
        int j = 0, k = rand() % 50, e = 0;
        e += k;
        textcolor(randnumber(i), randnumber(i + 1));
        if (e < 66 * 48)
        {
            for (int i = j; i < e; i++)
            {
                printf("%c", *t);
            }
            j += e;
        }
        if (e > 66 * 47)
            break;
    }
    return 0;
}

int randnumber(int i)
{
    srand(time(NULL));
    int textcolor = 0;
    textcolor = ((rand() % 16) + i) % 16;
    return textcolor;
}

void painting(char b, char t)
{
    textcolor(b, t);
    for (int i = 0; i < 66; i++)
        printf("wow it's beatiful day isn't it? what a good day");
}