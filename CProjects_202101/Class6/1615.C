#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define W 119 // ����Ű �� �� Ű������ �ƽ�Ű �ڵ�
void PrintStartBoard();//���� ȭ�� ���
void PlayGame();//���� ����
void GameRule();//���� �� ����
void PrintPicture();//ȭ��ǥ �׸� ���
void gotoxy(int x, int y); //���α׿��� ���� �̵� �Լ�
void GameOver();//���� ����
void CleanPicture();//ȭ��ǥ �׸� �����
int main() {
    PrintStartBoard();
    while (1) {
        if (_kbhit())
        {
            if (_getch() == W) {
                system("cls");//W ������ ȭ�� ��� ����� ���� ����
                PlayGame();
                return 0;
                exit(1); // ���α׷� ����
            }
        }
    }
}
void PrintStartBoard() {
    printf("�������������������������������������������������������������\n");
    printf("��                                                                                                                    ��\n");
    printf("��  ��  ��  ��        ���           ��       ��������    �����     �� ��        ��        ��������    ��\n");
    printf("��  ��  ��  ��      ��    ��       ��  ��     ��                ��           �� ��        ��        ��                ��\n");
    printf("��  ����  ���    ��    ��     ��      ��   ��                ��           �� ��      ��  ��      ��                ��\n");
    printf("��  ��  ��  ��        ���           ��       ��                ��           �� ��    ��      ��    ��������    ��\n");
    printf("��  ����  ��                   ������   ��������    �����   ��� ��  ��          ��  ��                ��\n");
    printf("��                 ������                                   ��           �� ��                  ��                ��\n");
    printf("��  ��                           ������         ��          ��           �� ��                  ��������    ��\n");
    printf("��  ��                ���               ��         ��          ��           �� ��  ��������                    ��\n");
    printf("��  ��              ��    ��             ��   ��������    �����     �� ��                                    ��\n");
    printf("��  ������      ��    ��             ��                                  �� ��                  ��������    ��\n");
    printf("��                    ���                                                                                            ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                             PRESS W TO START!!!                =                                   ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("�������������������������������������������������������������\n");
}
void gotoxy(int x, int y)

{

    COORD pos = { x, y / 2 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void PlayGame() {
    GameRule();
    int random;
    int score = 0;
    clock_t StartClock, EndClock;//�ð� �����ϴ� ���
    float record;
    StartClock = clock();//���� �ð�
    while (1) {
        srand(time(NULL));
        random = rand() % 4;//0:up, 1:down, 2:left, 3: right
        PrintPicture(random);//random �� ���� �Ϳ� �´� ȭ��ǥ �׸�
        switch (random) {
        case 0://up
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        goto EXIT;//�°� �������Ƿ� ���� ����
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 1://down
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        goto EXIT;//�°� �������Ƿ� ���� ����
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 2://left
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        goto EXIT;//�°� �������Ƿ� ���� ����
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 3://right
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        goto EXIT;//�°� �������Ƿ� ���� ����
                    }
                }
            }
            break;

        }
    EXIT://��ø �ݺ����� ���������� �ؼ� ��¿ �� ���� ����߽��ϴ�.
        score++;
        CleanPicture();
        gotoxy(30, 0);
        printf("%d/30ȸ", score);//���������� ���� ȭ��ǥ ���� Ƚ�� ǥ��
        gotoxy(0, 0);//���� ȭ��ǥ ��� ��ġ�� ����
        if (score == 30) break;
    }
    EndClock = clock();//���� �ð�
    record = (float)(EndClock - StartClock) / CLOCKS_PER_SEC;//���=(���� �ð�-ó���ð�)/(�ʷ� ȯ��)
    system("cls");
    printf("%.3f�� �ɷȽ��ϴ�.", record);//����� ��°�ڸ����� ���
}
void GameRule() {
    printf("<GAME RULE>\n");
    printf("1. ���� ��� ȭ�鿡 ȭ��ǥ �� ���� �� �� ������ ���ɴϴ�!\n");
    printf("2. ȭ��ǥ �׸��� ���߾� ����Ű�� �����ֽø� �˴ϴ�!\n");
    printf("3. ���� �߸� ������ ���� �����Դϴ�~\n");
    printf("4. �ùٸ� Ű�� �����Ŵٸ� ���� �׸��� ��� ������, �ٷ� ���� ȭ�� Ű�� �����ø� �˴ϴ�.\n");
    printf("5. �� �׸��� 30�� ������, ���� ����� �����Ŵٸ� �������� ����� ���� �̴ϴ�.\n");
    printf("6. �׷� ����� ���ϴ�.\n");
    Sleep(3000);//3�� ����
    gotoxy(0, 20);
    printf("[COUNT DOWN]\n");//�Ʒ������� �������� ī��Ʈ�ٿ� 5�� ����
    for (int i = 5; i >= 0; i--) {
        gotoxy(0, 24);
        printf("%d", i);
        Sleep(1000);
    }
    system("cls");//���� ����� ���� ����
}
void PrintPicture(picture) {
    switch (picture) {
    case 0:
        printf("    ��\n");
        printf("  ����\n");
        printf("��  ��  ��\n");
        printf("    ��\n");
        printf("    ��\n");
        break;
    case 1:
        printf("    ��\n");
        printf("    ��\n");
        printf("��  ��  ��\n");
        printf("  ����\n");
        printf("    ��\n");
        break;
    case 2:
        printf("    ��\n");
        printf("  ��\n");
        printf("������\n");
        printf("  ��\n");
        printf("    ��\n");
        break;
    case 3:
        printf("    ��\n");
        printf("      ��\n");
        printf("������\n");
        printf("      ��\n");
        printf("    ��\n");
        break;
    }
}
void GameOver() {
    int x;
    system("cls");
    srand(time(NULL));
    x = rand() % 5;//�����ϰ� �������� ��� ���(�ɽ��ؼ� �־����ϴ�)
    switch (x) {
    case 0:
        printf("�߸� �����̽��ϴ�.. �̰� ���� Ŭ���̶�� �Ͻ� �̴ϱ�?\n������������������������\n");
        break;
    case 1:
        printf("�߸� �����̳׿�! ����Ͻʴϴ�!!\n���ϵ����~~~\n");
        break;
    case 2:
        printf("�߸� �����̽��ϴ�.. ������ �������!!\n");
        break;
    case 3:
        printf("�߸� �����̽��ϴ�. �� �� �� �õ��Ͻø� ���� ����� ���� �ſ���~~\nȭ����!!!\n");
        break;
    case 4:
        printf("�߸� �����̳׿�.. ����..... ��\n");
        break;
    }
    Sleep(2000);
    printf("������    ��  ��    ��    ��  ������  ������  \n");
    printf("        ��    ��  ��  ��  ��  ��      ��              ��  \n");
    printf("        ��    ��  ��  ��  ��  ��    ��  ��    ������  \n");
    printf("        ��    ��  ��  ��  ��  ��              ��          \n");
    printf("        ��    ��  ��    ��    ��      ��      ������  \n");
    printf("        �����  ��              ������              \n");
    printf("        ��    ��  ��     ����                 ��  ��    \n");
    printf("        ��    ��  ��     ��  ��       ��        ��  ��    \n");
    printf("        ��    ��  ��     ��  ��     ��  ��      ��  ��    \n");
    printf("        ��    ��  ��     ����       ��    ��������\n");
    exit(1);
}
void CleanPicture() {
    gotoxy(0, 0);
    printf("          \n");
    printf("          \n");
    printf("          \n");
    printf("          \n");
    printf("          \n");
    Sleep(50);//������ �־ ���ο� �׸��� ���� �� �÷��̾ Ȯ���ϰ� ��
    gotoxy(0, 0);
}