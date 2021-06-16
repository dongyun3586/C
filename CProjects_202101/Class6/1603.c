#include<stdio.h>
#include<stdlib.h> // ���� ���� rand(), srand() �Լ� ���
#include<time.h> //time() �Լ� ���
#include<Windows.h> //�ܼ�â ���� �Լ� system("cls") ���
#include<conio.h> //Ű���� ���� �Լ� _kbhit(), _getch() ���

int Start(); //���� ȭ�� ��� �Լ�
int Rule(); //��Ģ ȭ�� ��� �Լ�
int Game3(); //3�ڸ� ���ھ߱� ����
int Game4(); //4�ڸ� ���ھ߱� ����
int Game5(); //5�ڸ� ���ھ߱� ����
int Choose(); //ȭ�� ����

void gotoxy(int x, int y) { //�ܼ�â���� Ŀ���� ��ǥ ������ ���� �Լ�
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
    Start();
    Choose();
}

int Start() {
    printf("������������������������������������������������\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                          ���ھ߱�                                        ��\n"); //����
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n"); //���� ����
    printf("��                                           2:��Ģ                                         ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                               1603 �赿���\n"); //�̸�
    printf("������������������������������������������������\n");
}

int Choose() {
    while (1) {
        if (_kbhit()) { //_kbhit(): ��ҿ� 0, Ű���带 ������ 1
            switch (_getch()) { //_getch(): ����ڰ� ���� ������ �ƽ�Ű �ڵ� ��ȯ
            case 49: //49: 1�� �ƽ�Ű�ڵ�
                system("cls"); //�ܼ�â ������ ȭ�� ����
                Start();
                break;
            case 50: //50: 2�� �ƽ�Ű�ڵ�
                system("cls");
                Rule();
                break;
            case 51: //51: 3�� �ƽ�Ű�ڵ�
                system("cls");
                Game3();
                break;
            case 52: //52: 4�� �ƽ�Ű�ڵ�
                system("cls");
                Game4();
                break;
            case 53: //53: 5�� �ƽ�Ű�ڵ�
                system("cls");
                Game5();
                break;
            }
        }
    }
}

int Rule() {
    printf("������������������������������������������������\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                             ��Ģ                                         ��\n");
    printf("��                                                                                          ��\n");
    printf("��                      0. ��ǥ: ��ǻ�Ͱ� ������ ���� ���� Ƚ���� ���߱�                    ��\n");
    printf("��                         1. ��Ʈ����ũ(S): �ش� ���ڿ� ��ġ�� ����                        ��\n");
    printf("��                          2. ��(B): �ش� ���ڴ� ������ ��ġ�� �ٸ�                        ��\n");
    printf("��                      3. �ƿ�(Out): �Է� ���� ��� ���ڰ� ���信 ����                     ��\n");
    printf("��                       (���÷� ���� 530�� �� 135�� 1S 1B, 246�� �ƿ�)                     ��\n");
    printf("��                                   4.�Է��� ���� ���� ����                                ��\n");
    printf("��                         (�׷��� ������ �ܼ�â�� ��Ʈ�� �� �� ����)                       ��\n");
    printf("��                  ���÷��� �ڸ������� ���� �Է½� �׸�ŭ ���� �о����Ƿ� ����             ��\n");
    printf("��                      6. �õ� Ƚ���� 44�� �ǰų� ���⶧ ���� ��� �ݺ�                    ��\n");
    printf("��                       7.��ǻ�Ͱ� ������ ���ڸ� ���߸� ����, ��������                     ��\n");
    printf("��                              8.44ȸ �̳��� �� ���߸� ���ӿ���                            ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
    printf("��                                         1:ó������                                       ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                                                                          ��\n");
    printf("������������������������������������������������\n");
}

int Game3() {
    int num[3], awn, arr[3]; //num�� ����� �� ����(�迭), awn�� �Է� ��, arr�� awn�� �� �ڸ� ���� �迭
    srand(time(NULL));
    num[0] = rand() % 10; //���� �ڸ� ���� ����
    while (1) { //���� �ڸ� ���� ����
        num[1] = rand() % 10;
        if (!(num[1] == num[0]))
            break;
    }
    while (1) { //���� �ڸ� ���� ����
        num[2] = rand() % 10; `
            if (!(num[2] == num[0] || num[2] == num[1]))
                break;
    }
    int count = 0;
    printf("������������������������������������������������\n");
    printf("��                                                                                          ��\n");
    printf("��                                         3�ڸ�                                            ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                                                                          ��\n");
    printf("������������������������������������������������\n");
    for (int i = 4; i < 48; i++) { //�� ��ȸ 44��
        if (i <= 25) { //���� ��ȸ
            gotoxy(12, i);
            int Strike = 0, Ball = 0;
            scanf("%3d", &awn); //�� �Է�
            arr[0] = awn / 100; //�Է��� �� ���� �ڸ� ����
            arr[1] = (awn / 10) % 10; //�Է��� �� ���� �ڸ� ����
            arr[2] = awn % 10; //�Է��� �� ���� �ڸ� ����
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++; //���� ���ڿ� ��ġ
                        else Ball++; //���� ���ڴ� �����ϳ� �ٸ� ��ġ
                    }
                }
            }
            gotoxy(25, i);
            count++;
            if (Ball == 0 && Strike == 0) printf("Out"); //��ġ�ϴ� ���ڰ� ����
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 3) { //����� ����
                system("cls");
                printf("������������������������������������������������\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ***����***                                        ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                             ��ǻ�Ͱ� ������ ���ڸ� ������ϴ�                            ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ����: %d%d%d                                         ��\n", num[0], num[1], num[2]);
                printf("��                                     �õ� Ƚ��: %2dȸ                                      ��\n", count);
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
                printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("������������������������������������������������\n");
                break; //�ٽ� Choose() �Լ��� �̵�
            }
        }
        if (i > 25) { //�Ĺ� ��ȸ
            count++;
            gotoxy(58, i - 22);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%3d", &awn);
            arr[0] = awn / 100;
            arr[1] = (awn / 10) % 10;
            arr[2] = awn % 10;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(71, i - 22);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 3) {
                system("cls");
                printf("������������������������������������������������\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ***����***                                        ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                             ��ǻ�Ͱ� ������ ���ڸ� ������ϴ�                            ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ����: %d%d%d                                         ��\n", num[0], num[1], num[2]);
                printf("��                                     �õ� Ƚ��: %2dȸ                                      ��\n", count);
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                  3/4/5�� ���� �����ϼ���                                  ��\n");
                printf("��                                    1:ó������, 2:��Ģ                                   ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("������������������������������������������������\n");
                break;
            }
        }
        if (i == 47) { //������ ��ȸ ���н�
            system("cls");
            printf("������������������������������������������������\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                      ***���� ����***                                     ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                    44ȸ �ȿ� ��ǻ�Ͱ� ������ ���ڸ� ������ ���߽��ϴ�.                   ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                        ����: %d%d%d                                         ��\n", num[0], num[1], num[2]);
            printf("��                                     �õ� Ƚ��: 44ȸ                                      ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
            printf("��                                   1: ó������, 2:��Ģ                                    ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("������������������������������������������������\n");
            break;
        }
    }
}

int Game4() { //Game3�� ��ü�� ������ ����
    int num[4], awn, arr[4];
    srand(time(NULL));
    num[0] = rand() % 10;
    while (1) {
        num[1] = rand() % 10;
        if (!(num[1] == num[0]))
            break;
    }
    while (1) {
        num[2] = rand() % 10;
        if (!(num[2] == num[0] || num[2] == num[1]))
            break;
    }
    while (1) {
        num[3] = rand() % 10;
        if (!(num[3] == num[0] || num[3] == num[1] || num[3] == num[2]))
            break;
    }
    int count = 0;
    printf("������������������������������������������������\n");
    printf("��                                                                                          ��\n");
    printf("��                                         4�ڸ�                                            ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                                                                          ��\n");
    printf("������������������������������������������������\n");
    for (int i = 4; i < 48; i++) {
        if (i <= 25) {
            gotoxy(12, i);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%4d", &awn);
            arr[0] = awn / 1000;
            arr[1] = (awn / 100) % 10;
            arr[2] = (awn / 10) % 10;
            arr[3] = awn % 10;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(25, i);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 4) {
                system("cls");
                printf("������������������������������������������������\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ***����***                                        ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                             ��ǻ�Ͱ� ������ ���ڸ� ������ϴ�                            ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ����: %d%d%d%d                                        ��\n", num[0], num[1], num[2], num[3]);
                printf("��                                     �õ� Ƚ��: %2dȸ                                      ��\n", count);
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
                printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("������������������������������������������������\n");
                break;
            }
        }
        if (i > 25) {
            count++;
            gotoxy(58, i - 22);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%4d", &awn);
            arr[0] = awn / 1000;
            arr[1] = (awn / 100) % 10;
            arr[2] = (awn / 10) % 10;
            arr[3] = awn % 10;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(71, i - 22);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 3) {
                system("cls");
                printf("������������������������������������������������\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ***����***                                        ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                             ��ǻ�Ͱ� ������ ���ڸ� ������ϴ�                            ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ����: %d%d%d%d                                        ��\n", num[0], num[1], num[2], num[3]);
                printf("��                                     �õ� Ƚ��: %2dȸ                                      ��\n", count);
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
                printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("������������������������������������������������\n");
                break;
            }
        }
        if (i == 47) {
            system("cls");
            printf("������������������������������������������������\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                      ***���� ����***                                     ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                    44ȸ �ȿ� ��ǻ�Ͱ� ������ ���ڸ� ������ ���߽��ϴ�.                   ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                        ����: %d%d%d%d                                        ��\n", num[0], num[1], num[2], num[3]);
            printf("��                                     �õ� Ƚ��: 44ȸ                                     ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
            printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("������������������������������������������������\n");
            break;
        }
    }
}

int Game5() { //Game3�� ��ü���� ������ ����
    int num[5], awn, arr[5];
    srand(time(NULL));
    num[0] = rand() % 10;
    while (1) {
        num[1] = rand() % 10;
        if (!(num[1] == num[0]))
            break;
    }
    while (1) {
        num[2] = rand() % 10;
        if (!(num[2] == num[0] || num[2] == num[1]))
            break;
    }
    while (1) {
        num[3] = rand() % 10;
        if (!(num[3] == num[0] || num[3] == num[1] || num[3] == num[2]))
            break;
    }
    while (1) {
        num[4] = rand() % 10;
        if (!(num[4] == num[0] || num[4] == num[1] || num[4] == num[2] || num[4] == num[3]))
            break;
    }
    int count = 0;
    printf("������������������������������������������������\n");
    printf("��                                                                                          ��\n");
    printf("��                                         5�ڸ�                                            ��\n");
    printf("��                                                                                          ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                           |                                              ��\n");
    printf("��                                                                                          ��\n");
    printf("������������������������������������������������\n");
    for (int i = 4; i < 48; i++) {
        if (i <= 25) {
            gotoxy(12, i);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%5d", &awn);
            arr[0] = awn / 10000;
            arr[1] = (awn / 1000) % 10;
            arr[2] = (awn / 100) % 10;
            arr[3] = (awn / 10) % 10;
            arr[4] = awn % 10;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(25, i);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 5) {
                system("cls");
                printf("������������������������������������������������\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ***����***                                        ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                             ��ǻ�Ͱ� ������ ���ڸ� ������ϴ�                            ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ����: %d%d%d%d%d                                       ��\n", num[0], num[1], num[2], num[3], num[4]);
                printf("��                                     �õ� Ƚ��: %2dȸ                                      ��\n", count);
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
                printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("������������������������������������������������\n");
                break;
            }
        }
        if (i > 25) {
            count++;
            gotoxy(58, i - 22);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%5", &awn);
            arr[0] = awn / 10000;
            arr[1] = (awn / 1000) % 10;
            arr[2] = (awn / 100) % 10;
            arr[3] = (awn / 10) % 10;
            arr[4] = awn % 10;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(71, i - 22);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 5) {
                system("cls");
                printf("������������������������������������������������\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ***����***                                        ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                             ��ǻ�Ͱ� ������ ���ڸ� ������ϴ�                            ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                        ����: %d%d%d%d%d                                       ��\n", num[0], num[1], num[2], num[3], num[4]);
                printf("��                                     �õ� Ƚ��: %2dȸ                                      ��\n", count);
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
                printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("��                                                                                          ��\n");
                printf("������������������������������������������������\n");
                break;
            }
        }
        if (i == 47) {
            system("cls");
            printf("������������������������������������������������\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                      ***���� ����***                                     ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                    44ȸ �ȿ� ��ǻ�Ͱ� ������ ���ڸ� ������ ���߽��ϴ�.                   ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                        ����: %d%d%d%d%d                                       ��\n", num[0], num[1], num[2], num[3], num[4]);
            printf("��                                      �õ� Ƚ��: 44ȸ                                     ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                  3/4/5�� ���� �����ϼ���                                 ��\n");
            printf("��                                    1:ó������, 2:��Ģ                                    ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("��                                                                                          ��\n");
            printf("������������������������������������������������\n");
            break;
        }
    }
}
