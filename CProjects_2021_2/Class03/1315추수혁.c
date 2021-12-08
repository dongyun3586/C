#include <stdio.h>
#include <Windows.h> //�Ҹ� ���, �ý��� ��� �� ���� ���� �ʿ�
#include <conio.h> // �ܼ� â ũ�� ���濡 �ʿ�
#include <gameux.h> // textcolor
#include <time.h> // time ���� ����

#define G 1567.982 //��������"��"

typedef struct {
    int nameunA;
    int nameunB;
    int A[2];
    int B[2];
    int p;
} _goBack;

void setting(); // ��ü�� ���� ����
void mainhwamyeonGeurigi(); // �κ� ȭ�� �׸���
void loading(); // �ε� ȭ�� ���
void maping(char* name1, char* name2, int num1, int num2); //�� �׸���
void gameStart(char* name1, char* name2);  // ���� ƨ���
void printInfo(char* name1, char* name2, int su1, int su2); //�� �ܿ� ��� ����� ���� ī�� �� ���
void AcardPrinting(int* A); //�÷��̾� 1 ī�� ���
void BcardPrinting(int* B); //�÷��̾� 2 ī�� ���
void playing(int* nameunA, int* nameunB, _goBack* k); //Ű �Է� �ް� ī�� �Է� �� ���� ��� ����

void textcolor(int color_number) { //���ڻ� ����(���ͳ� ����)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y) { //gotoxy�Լ�(���ͳ� ����) 
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void main() {
    system("mode con cols=58 lines=16"); // ����� �ܼ� ũ��
    system("color 3"); // ���� ���� ����������. ���̻� �Һ�
    setting();
}

void setting() { //������ ��ü���� ����
    char playerA[6] = " ", playerB[6] = " "; //�÷��̾��� �̸� ������ ���ڿ�

    mainhwamyeonGeurigi();
    int i = 0;
    _goBack score[100] = { 0 };

    int a = _getch(); //���� Ű �Է�
    if (a == 'p') { //���� Ű �Է� �� ����
        loading();
        printf("\n\n\n\n\n\n\n\n                Player A�� �̸�? \n\n\n\n\n\n\n\n");
        gets(playerA); // �÷��̾� 1 �̸� �Է�
        printf("\n\n\n\n\n\n\n\n                Player B�� �̸�? \n\n\n\n\n\n\n\n");
        gets(playerB); // �÷��̾� 2 �̸� �Է�
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(1000);
        gameStart(&playerA, &playerB); // ���� ƨ���
        int muchA = 28, muchB = 28; // �ʱ� �� �÷��̾ ������ �ִ� ī�� �� ����
        maping(&playerA, &playerB, muchA, muchB); // �� �׸���
        while (muchA > 0 && muchB > 0) { //�� ����� �����ϴ� ī���� ���� 0���� ū ���� �� �ݺ��� ����
            if (((score[i].A[0] == score[i].B[0]) && (score[i].A[1] + score[i].B[1] == 3)) || ((score[i].A[0] != score[i].B[0]) && (score[i].A[1] == 4 || score[i].B[1] == 4))) { //���� ���� 5���� ���� �� �� ġ�� �ϴ� ���ǹ�
                int s = _getch(); //�÷��̾� �� �Է�
                if (s == 'd') { //�÷��̾� 1 ��
                    muchA += score[i].p; //�ٴڿ� �� ī�� ���ϱ�
                    maping(&playerA, &playerB, muchA, muchB);//���� ī�� �� ���� �� �ʱ�ȭ
                }
                else if (s == 'k') { //�÷��̾� 2 ��
                    muchB += score[i].p;
                    maping(&playerA, &playerB, muchA, muchB);
                }
                i++; // ��� ����
            }
            playing(&muchA, &muchB, &score[i]); //ī�� �����ϴ� �Լ�
            gotoxy(0, 10);
            printInfo(&playerA, &playerB, muchA, muchB); //�÷��̾� ���� ���
            printf("���� p:%d", score[i].p);
        }
        if (muchA == 0) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n         %s ��!    \n\n\n\n\n\n\n\n", playerB);
        }
        if (muchB == 0) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n         %s ��!    \n\n\n\n\n\n\n\n", playerA);
        }
    }
    else {
        printf("\n\n\n\n\n\n\n                 �̿����ּż� �����մϴ�.\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n");
    }
}

void mainhwamyeonGeurigi() { //�κ� ȭ�� ������
    textcolor(14);
    printf("\n\n\n        000000000000000000000000000000000000000000\n");
    textcolor(15);
    printf("        0000000000                      0000000000\n");
    textcolor(14);
    printf("        0000000000      ");
    textcolor(11);
    printf("�� �� �� ��     ");
    textcolor(14);
    printf("0000000000\n");
    textcolor(15);
    printf("        0000000000                      0000000000\n");
    textcolor(14);
    printf("        000000000000000000000000000000000000000000\n");
    textcolor(15);
    printf("        000000000000000000000000000000000000000000\n");
    textcolor(14);
    printf("        0000000000                      0000000000\n");
    textcolor(15);
    printf("        0000000000  ");
    textcolor(11);
    printf("press <p> to start  ");
    textcolor(15);
    printf("0000000000\n");
    textcolor(14);
    printf("        0000000000                      0000000000\n");
    textcolor(15);
    printf("        000000000000000000000000000000000000000000\n\n\n");
}

void loading() { // �ε��� ǥ��
    printf("\n\n\n\n\n\n\n                   Please waiting..                   \n\n\n\n\n\n\n\n");
    Beep(G, 300);
    Sleep(100);
    printf("\n\n\n\n\n\n\n                   Please waiting....                   \n\n\n\n\n\n\n\n");
    Beep(G, 300);
    Sleep(100);
    printf("\n\n\n\n\n\n\n                   Please waiting......                   \n\n\n\n\n\n\n\n");
    Beep(G, 300);
    Sleep(100);
    printf("\n\n\n\n\n\n\n                   Please waiting..                   \n\n\n\n\n\n\n\n");
    Sleep(400);
    printf("\n\n\n\n\n\n\n                   Please waiting....                   \n\n\n\n\n\n\n\n");
    Sleep(400);
    printf("\n\n\n\n\n\n\n                   Please waiting......                   \n\n\n\n\n\n\n\n");
    Sleep(200);
}

void maping(char* name1, char* name2, int num1, int num2) {
    char map[10][59] = {
       {"0000000000000000000000000000000000000000000000000000000000"},
       {"0000000000000000000000000000000000000000000000000000000000"},
       {"0001111111111100111111111110000111111111110011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100111111111110000111111111110011111111111000"},
       {"0000000000000000000000000000000000000000000000000000000000"}
    };

    system("cls"); //�� ����� ��� ���� �ѹ� ȭ�� ��� �����
    int h, w;

    for (h = 0; h < 10; h++) {
        for (w = 0; w < 59; w++) {
            char temp = map[h][w];
            if (temp == '0')
                printf(" ");
            else
                printf("%c", temp);
        }
    }
    printf("\n");
    printInfo(name1, name2, num1, num2);
}

void printInfo(char* name1, char* name2, int su1, int su2) {
    printf("\n      %s   ����ī�� : %d��       %s  ����ī�� : %d�� \n\n", name1, su1, name2, su2);
    printf("          �� ġ�� : d                 �� ġ�� : k\n");
    printf("        ī�� ������ : a             ī�� ������ : h \n");
}

void gameStart(char* name1, char* name2) {
    int a;
    printf("                ���� ƨ��� ��....\n");
    Sleep(3000);
    srand(time(NULL));
    a = rand() % 2;
    if (a == 0) {
        printf("\n                   %s ��!\n\n\n\n\n\n\n", name1);
        Sleep(3000);
    }
    else {
        printf("\n                %s ��!\n\n\n\n\n\n\n", name2);
        Sleep(3000);
    }
}

void AcardPrinting(int* A) {
    int cards[56][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {1,0}, {1,0}, {1,0}, {1,0}, {1,0}, {1,1}, {1,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {2,0}, {2,0}, {2,0}, {2,0}, {2,0}, {2,1}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {2,4}, {3,0}, {3,0}, {3,0}, {3,0}, {3,0}, {3,1}, {3,1}, {3,1}, {3,2}, {3,2}, {3,2}, {3,3}, {3,3}, {3,4} };
    int t, color, number;

    srand(time(NULL));
    t = rand() % 56;
    color = cards[t][0];
    number = cards[t][1];

    int a, b;
    a = color;
    b = number;

    if (a == 0 && b == 0) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 1 && b == 0) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 2 && b == 0) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 3 && b == 0) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 0 && b == 1) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 1) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 1) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 1) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 0 && b == 2) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 1 && b == 2) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 2 && b == 2) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 3 && b == 2) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 0 && b == 3) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 3) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 3) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 3) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("  "); textcolor(15);

    }
    else if (a == 0 && b == 4) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 1 && b == 4) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 2 && b == 4) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    else if (a == 3 && b == 4) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("��"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("��"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("��"); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("��"); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("��"); textcolor(15);
    }
    A[0] = a, A[1] = b;
}

void BcardPrinting(int* B) {
    int cards[56][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {1,0}, {1,0}, {1,0}, {1,0}, {1,0}, {1,1}, {1,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {2,0}, {2,0}, {2,0}, {2,0}, {2,0}, {2,1}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {2,4}, {3,0}, {3,0}, {3,0}, {3,0}, {3,0}, {3,1}, {3,1}, {3,1}, {3,2}, {3,2}, {3,2}, {3,3}, {3,3}, {3,4} };
    int t, color, number;

    srand(time(NULL));
    t = rand() % 56;
    color = cards[t][0];
    number = cards[t][1];

    int a, b;
    a = color;
    b = number;

    if (a == 0 && b == 0) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 1 && b == 0) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 2 && b == 0) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 3 && b == 0) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 0 && b == 1) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 1) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 1) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 1) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 0 && b == 2) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 1 && b == 2) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 2 && b == 2) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 3 && b == 2) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 0 && b == 3) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 3) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 3) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 3) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("  "); textcolor(15);

    }
    else if (a == 0 && b == 4) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 1 && b == 4) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 2 && b == 4) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    else if (a == 3 && b == 4) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("��"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("��"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("��"); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("��"); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("��"); textcolor(15);
    }
    B[0] = a, B[1] = b;
}

void playing(int* nameunA, int* nameunB, _goBack* k) {

    int a = _getch();

    if (a == 'a') {
        AcardPrinting(k->A);
        (*nameunA)--;
        k->nameunA = *nameunA;
        (k->p)++;
    }
    else if (a == 'h') {
        BcardPrinting(k->B);
        (*nameunB)--;
        k->nameunB = *nameunB;
        (k->p)++;
    }
}