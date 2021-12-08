#include<stdio.h>
#include<stdlib.h> // ���� ���� rand(), srand() �Լ� ���
#include<time.h> // time() �Լ� ���
#include<Windows.h> // �ܼ�â �Լ� system("cls") ���
#include<conio.h> // Ű���� �Լ� _kbhit(), _getch() ���
#include<string.h> // ���ڿ� �Լ�strcmp �Լ� ���

// ȭ�� ���� ����
int Start(); // ���� ȭ�� ��� �Լ�
int Rule(); // ��Ģ ȭ�� ��� �Լ�
int Plate(); // ���� �� ��� �Լ�
int P1(); // 2�ο� ����
int P2(); // 1�ο� ����
int Choose(); // ȭ�� ����

 // ���� ����
int Rand(); // �ֻ��� ������ �Լ�
int IsFourCard(int a, int b, int c, int d, int e); // ���� �� �� 4�� �̻��� ������ �Ǵ��ϴ� �Լ�
int IsFullHouse(int a, int b, int c, int d, int e); // ���� �� �� 3��, 2���� ���� ������ �Ǵ��ϴ� �Լ�
int IsSStraight(int a, int b, int c, int d, int e); // ���� �� �� 4�� �̻��� �������� �Ǵ��ϴ� �Լ�
int IsLStraight(int a, int b, int c, int d, int e); // ���� �� 5���� �������� �Ǵ��ϴ� �Լ�

void gotoxy(int x, int y) { // �ܼ�â���� Ŀ���� ��ǥ ������ ���� �Լ�
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
    printf("�������������������������������������������������������\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                    ��      ��                                 ��                                       ��\n");
    printf("��                     ��    ��                                  ��                                       ��\n");
    printf("��                      ��  ��       ����                      ��              ��                       ��\n");
    printf("��                        ��               ��        ����      �� ���      �����                    ��\n");
    printf("��                        ��         �����       ��           ���  ��        ��                       ��\n");
    printf("��                        ��        ��     ��       ��           ��    ��        ��                       ��\n");
    printf("��                        ��         �����        ����      ��    ��         ���                    ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                           2: ��Ģ  3: ������                                           ��\n");
    printf("��                                              4: 1�ο� ����                                             ��\n");
    printf("��                                              5: 2�ο� ����                                             ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                              (��Ģ�� �� �о�ð� �������ֽñ� �ٶ��ϴ�)                              ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                             1603 �赿���\n");
    printf("�������������������������������������������������������\n");
}

int Choose() {
    while (1) {
        if (_kbhit()) { // _kbhit(): ��ҿ� 0, Ű���带 ������ 1
            switch (_getch()) { // _getch(): ����ڰ� ���� ������ �ƽ�Ű �ڵ� ��ȯ
            case 49: // 49: 1�� �ƽ�Ű�ڵ�
                system("cls"); // �ܼ�â ������ ȭ�� ����
                Start();
                break;
            case 50: // 50: 2�� �ƽ�Ű�ڵ�
                system("cls");
                Rule();
                break;
            case 51: // 51: 3�� �ƽ�Ű�ڵ�
                system("cls");
                Plate();
                break;
            case 52: // 51: 3�� �ƽ�Ű�ڵ�
                system("cls");
                P1();
                break;
            case 53: // 52: 4�� �ƽ�Ű�ڵ�
                system("cls");
                P2();
                break;
            }
        }
    }
}

int Rule() {
    printf("�������������������������������������������������������\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                   ��Ģ                                                 ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                     ��ǥ: 12���� ���ʵ��� 12ĭ�� ä�� ��� ĭ ���� ���� �� ū ���� �¸�                ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                           �� ���� ������ ����                                          ��\n");
    printf("��                                 1. �ֻ��� 5��(A, B, C, D, E)�� ������                                  ��\n");
    printf("��           2. ���� �ٽ� ������ �ֻ��� �̸��� scanf �������� ���޾� �Է��ϰ� �������� �����Ѵ�.          ��\n");
    printf("��                         (��: ACD(����) -> A, C, D �ٽ� ����, 0 -> �ٽ� ������ ����)                    ��\n");
    printf("��                         3. �� ���� ���� �ִ� 2������ �� ���� �� �ִ�(���� �� 3��)                    ��\n");
    printf("��          4. �̷��� ������ ���� 5���� �ֻ��� ������ '���� ��'�� 12 ĭ �� ������ �� ĭ���� ä���        ��\n");
    printf("��                            (Sun Total, Bonus, Total�� �ڵ����� ä������ ĭ�̴�)                        ��\n");
    printf("��                     5. �� ĭ�� ä��� �ڽ��� ���ʰ� ������ ��뿡�� ���ʰ� �Ѿ��                    ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                     ä�� ĭ�� ������ ���ʿ� �ٲ� �� ���� ä���� ���� �ٸ� ĭ�� ä���                  ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                      ��� ����� 12 ���ʵ��� 12 ���� ĭ�� ��� ä��� ���� ����                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                          1: ó������  3: ������                                        ��\n");
    printf("��                                              4: 1�ο� ����                                             ��\n");
    printf("��                                              5: 2�ο� ����                                             ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("�������������������������������������������������������\n");
}

int Plate() {
    printf("�������������������������������������������������������\n");
    printf("��                                                                                                        ��\n");
    printf("��   �Ǧ�������������������������������������������                      �Ǧ�������������������������������������������                                 ��\n");
    printf("��   ��   Aces    ��    ��    �� ���� 1���� ��        ��   Choice  ��    ��    ��  ���ڵ��� ��(����X)             ��\n");
    printf("��   ���������������������������������������������� (��: 1 1 1 2 3 -> 3) ����������������������������������������������  (��: 3 4 4 6 6 -> 18)          ��\n");
    printf("��   ��   Duces   ��    ��    �� ���� 2���� ��        ��4 of a Kind��    ��    ��  �� ���ڰ� ���� ��, ���� ��     ��\n");
    printf("��   ���������������������������������������������� (��: 1 2 2 2 2 -> 8) ����������������������������������������������  (��: 4 5 5 5 5 -> 24)          ��\n");
    printf("��   ��   Threes  ��    ��    �� ���� 3���� ��        �� Full House��    ��    ��  ��, ���� ���� ���� ��, ��      ��\n");
    printf("��   ���������������������������������������������� (��: 1 2 2 4 5 -> 0) ����������������������������������������������  (��: 3 3 3 6 6 -> 24)          ��\n");
    printf("��   ��   Fours   ��    ��    �� ���� 4���� ��        �� S.Straight��    ��    ��  �� ���ڰ� ���ӽ�, ���� 15��    ��\n");
    printf("��   ����������������������������������������������                      ����������������������������������������������  (��: 1 2 3 4 6 -> 15)          ��\n");
    printf("��   ��   Fives   ��    ��    �� ���� 5���� ��        �� L.Straight��    ��    ��  ��� ���ڰ� ���ӽ�, ���� 30��  ��\n");
    printf("��   ����������������������������������������������                      ����������������������������������������������  (��: 2 3 4 5 6 -> 30)          ��\n");
    printf("��   ��   Sixes   ��    ��    �� ���� 6���� ��        ��   Yacht   ��    ��    ��  ��� ���ڰ� ������, ���� 50��  ��\n");
    printf("��   ����������������������������������������������                      ����������������������������������������������  (��: 1 1 1 1 1 -> 50)          ��\n");
    printf("��   �Ǧ�������������������������������������������                      �Ǧ�������������������������������������������                                 ��\n");
    printf("��   �� Sub Total ��    ��    �� �� ���� ĭ���� ��    ��   Total   ��    ��    ��  ���� ĭ���� ����               ��\n");
    printf("��   ����������������������������������������������                      ����������������������������������������������                                 ��\n");
    printf("��   ��   Bonus   ��    ��    �� Sub Total >= 63�̸� +35                                                      ��\n");
    printf("��   ���������������������������������������������� �׷��� ������ +0                                                             ��\n");
    printf("��                                                                                                        ��\n");
    printf("��       (4 of a Kind, Full House, S.Straight, L.straight, Yacht ���� ���� �Ҹ����� ä����ϸ� 0��)       ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                          1: ó������  2: ��Ģ                                          ��\n");
    printf("��                                              4: 1�ο� ����                                             ��\n");
    printf("��                                              5: 2�ο� ����                                             ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("�������������������������������������������������������\n");
}

int P1() {
    srand((unsigned int)time(NULL));
    int Aces = 0, Duces = 0, Threes = 0, Fours = 0, Fives = 0, Sixes = 0, Choice = 0, Four_Kind = 0, Full_House = 0, S_Straight = 0, L_Straight = 0, Yacht = 0;
    int used[13] = { 0, }; //  �̹� ����� ĭ�� ��ȣ�� ����
    for (int k = 0; k < 13; k++) {
        int dice[5];
        char re[5] = "FFFF";
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        int Sub_Total = Aces + Duces + Threes + Fours + Fives + Sixes;
        int Bonus = (Sub_Total >= 63) ? 35 : 0; // Sub_Total ���� 63 �̻��̸� +35, �̸��̸� +0
        int Total = Sub_Total + Choice + Four_Kind + Full_House + S_Straight + L_Straight + Yacht + Bonus;
        if (k == 12) { //12��° ���ʰ� ������ ��µǴ� ȭ�� & 1�ο� ���� ����
            system("cls");
            printf("�������������������������������������������������������\n");
            printf("��                                                                                                        ��\n");
            printf("��                                                 ���� ���� !                                            ��\n");
            printf("��                                                                                                        ��\n");
            printf("��   �Ǧ���������������������������������   �Ǧ���������������������������������                                                              ��\n");
            printf("��  1��   Aces    �� %2d �� 7 ��   Choice  �� %2d ��                                                              ��\n", Aces, Choice);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��  2��   Duces   �� %2d �� 8 ��4 of a Kind�� %2d ��                                                              ��\n", Duces, Four_Kind);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��  3��   Threes  �� %2d �� 9 �� Full House�� %2d ��                            ����                              ��\n", Threes, Full_House);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��  4��   Fours   �� %2d �� 10�� S.Straight�� %2d ��                           %3d ��                             ��\n", Fours, S_Straight, Total);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��  5��   Fives   �� %2d �� 11�� L.Straight�� %2d ��                                                              ��\n", Fives, L_Straight);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��  6��   Sixes   �� %2d �� 12��   Yacht   �� %2d ��                                                              ��\n", Sixes, Yacht);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��   �Ǧ���������������������������������   �Ǧ���������������������������������                                                              ��\n");
            printf("��   �� Sub Total �� %3d��   ��   Total   �� %3d��                                                              ��\n", Sub_Total, Total);
            printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
            printf("��   ��   Bonus   �� +%2d��                                                                                   ��\n", Bonus);
            printf("��   ������������������������������������                                                                                   ��\n");
            printf("��                                                                                                        ��\n");
            printf("��                                               1: ó������                                              ��\n");
            printf("��                                            2: ��Ģ  3: ������                                          ��\n");
            printf("��                                              4: 1�ο� ����                                             ��\n");
            printf("��                                              5: 2�ο� ����                                             ��\n");
            printf("��                                                                                                        ��\n");
            printf("��                                                                                                        ��\n");
            printf("�������������������������������������������������������\n");
            break;
        }
        system("cls");
        printf("�������������������������������������������������������\n");
        printf("��                                                                                                        ��\n");
        printf("��   �Ǧ���������������������������������   �Ǧ���������������������������������                                                              ��\n");
        printf("��  1��   Aces    �� %2d �� 7 ��   Choice  �� %2d ��                                                              ��\n", Aces, Choice);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��  2��   Duces   �� %2d �� 8 ��4 of a Kind�� %2d ��                                                              ��\n", Duces, Four_Kind);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��  3��   Threes  �� %2d �� 9 �� Full House�� %2d ��                        ����� �ֻ���                         ��\n", Threes, Full_House);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��  4��   Fours   �� %2d �� 10�� S.Straight�� %2d ��                A      B      C      D      E                 ��\n", Fours, S_Straight);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��  5��   Fives   �� %2d �� 11�� L.Straight�� %2d ��                %d      %d      %d      %d      %d                 ��\n", Fives, L_Straight, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��  6��   Sixes   �� %2d �� 12��   Yacht   �� %2d ��                                                              ��\n", Sixes, Yacht);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��   �Ǧ���������������������������������   �Ǧ���������������������������������                                                              ��\n");
        printf("��   �� Sub Total �� %3d��   ��   Total   �� %3d��                                                              ��\n", Sub_Total, Total);
        printf("��   ������������������������������������   ������������������������������������                                                              ��\n");
        printf("��   ��   Bonus   �� +%2d��                                                                                   ��\n", Bonus);
        printf("��   ������������������������������������                                                                                   ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��           ����: %2d / 12             �ٲٰ� ���� �ֻ��� :                                               ��\n", k + 1);
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("�������������������������������������������������������\n");
        for (int j = 0; j < 2; j++) { // �ٽ� ������ ����(�ִ� 2ȸ)
            gotoxy(60, 22);
            scanf("%s", re); // re�� �ٽ� ������ ���� �ֻ��� �̸��� ������ ���� ���ڿ�
            if (!(strcmp(re, "0"))) {
                char re[5] = "FFFF";
                break; // �ٽ� ������ ���� re�� 0�� �Է� ������ �ٽ� ������ Ż��
            }
            for (int i = 0; i < 5; i++) { //re�� A, B, C, D, E�� �ִ��� �ݺ��ϸ� switch-case�� �м�, ������ �ٽ� ����
                switch (re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(60, 11);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(67, 11);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(74, 11);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(81, 11);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(88, 11);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char re[5] = "FFFF";
        }
        int num;
        while (1) { //  ĭ �Է� & �Է¹��� ĭ ��ȣ�� ������ �ߺ����� �Ǻ�
            int flag = 0; //  flag�� 0�̸� ��� ����, 1�̸� ���Է�
            gotoxy(39, 24);
            printf("ä��� ���� ĭ�� �����Ͻʽÿ�:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // �ٲٰ� ���� ĭ�� ��ȣ �Է�
            for (int n = 0; n < 12; n++) {
                if (used[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("�̹� ä��ų� ���� ĭ�Դϴ�");
        }
        switch (num) { // �Է��� ĭ�� �� ����
        case 1:
            for (int m = 0; m < 5; m++) { // 1�� �ִ¸�ŭ Aces�� ����
                if (dice[m] == 1)
                    Aces += dice[m];
            }
            used[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2�� �ִ¸�ŭ Duces�� ����
                if (dice[m] == 2)
                    Duces += dice[m];
            }
            used[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3�� �ִ¸�ŭ Threes�� ����
                if (dice[m] == 3)
                    Threes += dice[m];
            }
            used[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4�� �ִ¸�ŭ Fours�� ����
                if (dice[m] == 4)
                    Fours += dice[m];
            }
            used[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5�� �ִ¸�ŭ Fives�� ����
                if (dice[m] == 5)
                    Fives += dice[m];
            }
            used[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6�� �ִ¸�ŭ Sixes�� ����
                if (dice[m] == 6)
                    Sixes += dice[m];
            }
            used[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // ���� ���� ��� ����
                Choice += dice[m];
            used[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // �װ� �̻��� ������ �Ǻ�, �����ϸ� ��� ����, �ƴϸ� 0��
                for (int m = 0; m < 5; m++)
                    Four_Kind += dice[m];
            }
            used[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3��, 2�� ���� ������ �Ǻ�, �����ϸ� ��� ����, �ƴϸ� 0��
                for (int m = 0; m < 5; m++)
                    Full_House += dice[m];
            }
            used[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // �װ� �̻��� �������� �Ǻ�, �����ϸ� 15��, �ƴϸ� 0��
                S_Straight = 15;
            used[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5�� ��� �������� �Ǻ�, �����ϸ� 30��, �ƴϸ� 0��
                L_Straight = 30;
            }
            used[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5�� ��� ������ �Ǻ�, �����ϸ� 50��, �ƴϸ� 0��
                Yacht = 50;
            used[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("�̹� ä��ų� ���� ĭ�Դϴ�");
        }
    }
}

int P2() {
    srand((unsigned int)time(NULL));
    int Aces1 = 0, Duces1 = 0, Threes1 = 0, Fours1 = 0, Fives1 = 0, Sixes1 = 0, Choice1 = 0, Four_Kind1 = 0, Full_House1 = 0, S_Straight1 = 0, L_Straight1 = 0, Yacht1 = 0;
    int Aces2 = 0, Duces2 = 0, Threes2 = 0, Fours2 = 0, Fives2 = 0, Sixes2 = 0, Choice2 = 0, Four_Kind2 = 0, Full_House2 = 0, S_Straight2 = 0, L_Straight2 = 0, Yacht2 = 0;
    int used1[13] = { 0, }; //  �̹� ����� ĭ�� ��ȣ�� ����
    int used2[13] = { 0, };
    for (int k = 0; k < 13; k++) {
        int dice[5];
        char re[5] = "FFFF";
        char Re[5] = "FFFF";
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        int Sub_Total1 = Aces1 + Duces1 + Threes1 + Fours1 + Fives1 + Sixes1;
        int Bonus1 = (Sub_Total1 >= 63) ? 35 : 0; // Sub_Total ���� 63 �̻��̸� +35, �̸��̸� +0
        int Total1 = Sub_Total1 + Choice1 + Four_Kind1 + Full_House1 + S_Straight1 + L_Straight1 + Yacht1 + Bonus1;
        int Sub_Total2 = Aces2 + Duces2 + Threes2 + Fours2 + Fives2 + Sixes2;
        int Bonus2 = (Sub_Total2 >= 63) ? 35 : 0; // Sub_Total ���� 63 �̻��̸� +35, �̸��̸� +0
        int Total2 = Sub_Total2 + Choice2 + Four_Kind2 + Full_House2 + S_Straight2 + L_Straight2 + Yacht2 + Bonus2;
        if (k == 12) { //12��° ���ʰ� ������ ��µǴ� ȭ�� & 2�ο� ���� ����
            if (Total1 != Total2) {
                system("cls");
                printf("�������������������������������������������������������\n");
                printf("��                                                                                                        ��\n");
                printf("��                                                 ���� ���� !                                            ��\n");
                printf("��                                                                                                        ��\n");
                printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
                printf("��  1��   Aces    �� %2d �� %2d �� 7 ��   Choice  �� %2d �� %2d ��                                                    ��\n", Aces1, Aces2, Choice1, Choice2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��  2��   Duces   �� %2d �� %2d �� 8 ��4 of a Kind�� %2d �� %2d ��                                                    ��\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��  3��   Threes  �� %2d �� %2d �� 9 �� Full House�� %2d �� %2d ��                            ����                    ��\n", Threes1, Threes2, Full_House1, Full_House2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��  4��   Fours   �� %2d �� %2d �� 10�� S.Straight�� %2d �� %2d ��                      %3d ��  ||  %3d ��            ��\n", Fours1, Fours2, S_Straight1, S_Straight2, Total1, Total2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��  5��   Fives   �� %2d �� %2d �� 11�� L.Straight�� %2d �� %2d ��                           P%d �¸�                  ��\n", Fives1, Fives2, L_Straight1, L_Straight2, (Total1 > Total2) ? 1 : 2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��  6��   Sixes   �� %2d �� %2d �� 12��   Yacht   �� %2d �� %2d ��                                                    ��\n", Sixes1, Sixes2, Yacht1, Yacht2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
                printf("��   �� Sub Total �� %3d�� %3d��   ��   Total   �� %3d�� %3d��                                                    ��\n", Sub_Total1, Sub_Total2, Total1, Total2);
                printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
                printf("��   ��   Bonus   �� +%2d�� +%2d��                                                                              ��\n", Bonus1, Bonus2);
                printf("��   ����������������������������������������������                                                                              ��\n");
                printf("��                                                                                                        ��\n");
                printf("��                                               1: ó������                                              ��\n");
                printf("��                                            2: ��Ģ  3: ������                                          ��\n");
                printf("��                                              4: 1�ο� ����                                             ��\n");
                printf("��                                              5: 2�ο� ����                                             ��\n");
                printf("��                                                                                                        ��\n");
                printf("��                                                                                                        ��\n");
                printf("�������������������������������������������������������\n");
                break;
            }
            system("cls");
            printf("�������������������������������������������������������\n");
            printf("��                                                                                                        ��\n");
            printf("��                                                 ���� ���� !                                            ��\n");
            printf("��                                                                                                        ��\n");
            printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
            printf("��  1��   Aces    �� %2d �� %2d �� 7 ��   Choice  �� %2d �� %2d ��                                                    ��\n", Aces1, Aces2, Choice1, Choice2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��  2��   Duces   �� %2d �� %2d �� 8 ��4 of a Kind�� %2d �� %2d ��                                                    ��\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��  3��   Threes  �� %2d �� %2d �� 9 �� Full House�� %2d �� %2d ��                            ����                    ��\n", Threes1, Threes2, Full_House1, Full_House2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��  4��   Fours   �� %2d �� %2d �� 10�� S.Straight�� %2d �� %2d ��                     %3d ��  ||  %3d ��             ��\n", Fours1, Fours2, S_Straight1, S_Straight2, Total1, Total2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��  5��   Fives   �� %2d �� %2d �� 11�� L.Straight�� %2d �� %2d ��                           ���º�                   ��\n", Fives1, Fives2, L_Straight1, L_Straight2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��  6��   Sixes   �� %2d �� %2d �� 12��   Yacht   �� %2d �� %2d ��                                                    ��\n", Sixes1, Sixes2, Yacht1, Yacht2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
            printf("��   �� Sub Total �� %3d�� %3d��   ��   Total   �� %3d�� %3d��                                                    ��\n", Sub_Total1, Sub_Total2, Total1, Total2);
            printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
            printf("��   ��   Bonus   �� +%2d�� +%2d��                                                                              ��\n", Bonus1, Bonus2);
            printf("��   ����������������������������������������������                                                                              ��\n");
            printf("��                                                                                                        ��\n");
            printf("��                                               1: ó������                                              ��\n");
            printf("��                                            2: ��Ģ  3: ������                                          ��\n");
            printf("��                                              4: 1�ο� ����                                             ��\n");
            printf("��                                              5: 2�ο� ����                                             ��\n");
            printf("��                                                                                                        ��\n");
            printf("��                                                                                                        ��\n");
            printf("�������������������������������������������������������\n");
            break;
        }
        // P1����
        system("cls");
        printf("�������������������������������������������������������\n");
        printf("��                                                                                                        ��\n");
        printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
        printf("��  1��   Aces    �� %2d �� %2d �� 7 ��   Choice  �� %2d �� %2d ��                                                    ��\n", Aces1, Aces2, Choice1, Choice2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  2��   Duces   �� %2d �� %2d �� 8 ��4 of a Kind�� %2d �� %2d ��                ����� �ֻ���                       ��\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  3��   Threes  �� %2d �� %2d �� 9 �� Full House�� %2d �� %2d ��        A      B      C      D      E               ��\n", Threes1, Threes2, Full_House1, Full_House2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  4��   Fours   �� %2d �� %2d �� 10�� S.Straight�� %2d �� %2d ��        %d      %d      %d      %d      %d               ��\n", Fives1, Fives2, S_Straight1, S_Straight2, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  5��   Fives   �� %2d �� %2d �� 11�� L.Straight�� %2d �� %2d ��                                                    ��\n", Fives1, Fives2, L_Straight1, L_Straight2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  6��   Sixes   �� %2d �� %2d �� 12��   Yacht   �� %2d �� %2d ��                                                    ��\n", Sixes1, Sixes2, Yacht1, Yacht2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
        printf("��   �� Sub Total �� %3d�� %3d��   ��   Total   �� %3d�� %3d��                                                    ��\n", Sub_Total1, Sub_Total2, Total1, Total2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��   ��   Bonus   �� +%2d�� +%2d��                                                                              ��\n", Bonus1, Bonus2);
        printf("��   ����������������������������������������������                                                                              ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��           ����: %2d / 12  (P1 ����)  �ٲٰ� ���� �ֻ��� :                                               ��\n", k + 1);
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("�������������������������������������������������������\n");
        for (int j = 0; j < 2; j++) { // �ٽ� ������ ����(�ִ� 2ȸ)
            gotoxy(60, 22);
            scanf("%s", re); // re�� �ٽ� ������ ���� �ֻ��� �̸��� ������ ���� ���ڿ�
            if (!(strcmp(re, "0"))) {
                char re[5] = "FFFF";
                break; // �ٽ� ������ ���� re�� 0�� �Է� ������ �ٽ� ������ Ż��
            }
            for (int i = 0; i < 5; i++) { //re�� A, B, C, D, E�� �ִ��� �ݺ��ϸ� switch-case�� �м�, ������ �ٽ� ����
                switch (re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(62, 9);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(69, 9);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(76, 9);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(83, 9);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(90, 9);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char re[5] = "FFFF";
        }
        int num;
        while (1) { //  ĭ �Է� & �Է¹��� ĭ ��ȣ�� ������ �ߺ����� �Ǻ�
            int flag = 0; //  flag�� 0�̸� ��� ����, 1�̸� ���Է�
            gotoxy(39, 24);
            printf("ä��� ���� ĭ�� �����Ͻʽÿ�:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // �ٲٰ� ���� ĭ�� ��ȣ �Է�
            for (int n = 0; n < 12; n++) {
                if (used1[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("�̹� ä��ų� ���� ĭ�Դϴ�");
        }
        switch (num) { // �Է��� ĭ�� �� ����
        case 1:
            for (int m = 0; m < 5; m++) { // 1�� �ִ¸�ŭ Aces�� ����
                if (dice[m] == 1)
                    Aces1 += dice[m];
            }
            used1[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2�� �ִ¸�ŭ Duces�� ����
                if (dice[m] == 2)
                    Duces1 += dice[m];
            }
            used1[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3�� �ִ¸�ŭ Threes�� ����
                if (dice[m] == 3)
                    Threes1 += dice[m];
            }
            used1[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4�� �ִ¸�ŭ Fours�� ����
                if (dice[m] == 4)
                    Fours1 += dice[m];
            }
            used1[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5�� �ִ¸�ŭ Fives�� ����
                if (dice[m] == 5)
                    Fives1 += dice[m];
            }
            used1[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6�� �ִ¸�ŭ Sixes�� ����
                if (dice[m] == 6)
                    Sixes1 += dice[m];
            }
            used1[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // ���� ���� ��� ����
                Choice1 += dice[m];
            used1[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // �װ� �̻��� ������ �Ǻ�, �����ϸ� ��� ����, �ƴϸ� 0��
                for (int m = 0; m < 5; m++)
                    Four_Kind1 += dice[m];
            }
            used1[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3��, 2�� ���� ������ �Ǻ�, �����ϸ� ��� ����, �ƴϸ� 0��
                for (int m = 0; m < 5; m++)
                    Full_House1 += dice[m];
            }
            used1[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // �װ� �̻��� �������� �Ǻ�, �����ϸ� 15��, �ƴϸ� 0��
                S_Straight1 = 15;
            used1[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5�� ��� �������� �Ǻ�, �����ϸ� 30��, �ƴϸ� 0��
                L_Straight1 = 30;
            }
            used1[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5�� ��� ������ �Ǻ�, �����ϸ� 50��, �ƴϸ� 0��
                Yacht1 = 50;
            used1[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("�̹� ä��ų� ���� ĭ�Դϴ�");
        }

        // P2����
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        Sub_Total1 = Aces1 + Duces1 + Threes1 + Fours1 + Fives1 + Sixes1;
        Bonus1 = (Sub_Total1 >= 63) ? 35 : 0; // Sub_Total ���� 63 �̻��̸� +35, �̸��̸� +0
        Total1 = Sub_Total1 + Choice1 + Four_Kind1 + Full_House1 + S_Straight1 + L_Straight1 + Yacht1 + Bonus1;
        Sub_Total2 = Aces2 + Duces2 + Threes2 + Fours2 + Fives2 + Sixes2;
        Bonus2 = (Sub_Total2 >= 63) ? 35 : 0; // Sub_Total ���� 63 �̻��̸� +35, �̸��̸� +0
        Total2 = Sub_Total2 + Choice2 + Four_Kind2 + Full_House2 + S_Straight2 + L_Straight2 + Yacht2 + Bonus2;
        system("cls");
        printf("�������������������������������������������������������\n");
        printf("��                                                                                                        ��\n");
        printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
        printf("��  1��   Aces    �� %2d �� %2d �� 7 ��   Choice  �� %2d �� %2d ��                                                    ��\n", Aces1, Aces2, Choice1, Choice2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  2��   Duces   �� %2d �� %2d �� 8 ��4 of a Kind�� %2d �� %2d ��                ����� �ֻ���                       ��\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  3��   Threes  �� %2d �� %2d �� 9 �� Full House�� %2d �� %2d ��        A      B      C      D      E               ��\n", Threes1, Threes2, Full_House1, Full_House2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  4��   Fours   �� %2d �� %2d �� 10�� S.Straight�� %2d �� %2d ��        %d      %d      %d      %d      %d               ��\n", Fives1, Fives2, S_Straight1, S_Straight2, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  5��   Fives   �� %2d �� %2d �� 11�� L.Straight�� %2d �� %2d ��                                                    ��\n", Fives1, Fives2, L_Straight1, L_Straight2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��  6��   Sixes   �� %2d �� %2d �� 12��   Yacht   �� %2d �� %2d ��                                                    ��\n", Sixes1, Sixes2, Yacht1, Yacht2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��   �Ǧ�������������������������������������������   �Ǧ�������������������������������������������                                                    ��\n");
        printf("��   �� Sub Total �� %3d�� %3d��   ��   Total   �� %3d�� %3d��                                                    ��\n", Sub_Total1, Sub_Total2, Total1, Total2);
        printf("��   ����������������������������������������������   ����������������������������������������������                                                    ��\n");
        printf("��   ��   Bonus   �� +%2d�� +%2d��                                                                              ��\n", Bonus1, Bonus2);
        printf("��   ����������������������������������������������                                                                              ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��           ����: %2d / 12  (P2 ����)  �ٲٰ� ���� �ֻ��� :                                               ��\n", k + 1);
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("��                                                                                                        ��\n");
        printf("�������������������������������������������������������\n");
        for (int j = 0; j < 2; j++) { // �ٽ� ������ ����(�ִ� 2ȸ)
            gotoxy(60, 22);
            scanf("%s", Re); // Re�� �ٽ� ������ ���� �ֻ��� �̸��� ������ ���� ���ڿ�
            if (!(strcmp(Re, "0"))) {
                char re[5] = "FFFF";
                break; // �ٽ� ������ ���� Re�� 0�� �Է� ������ �ٽ� ������ Ż��
            }
            for (int i = 0; i < 5; i++) { //Re�� A, B, C, D, E�� �ִ��� �ݺ��ϸ� switch-case�� �м�, ������ �ٽ� ����
                switch (Re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(62, 9);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(69, 9);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(76, 9);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(83, 9);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(90, 9);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char Re[5] = "FFFF";
        }
        while (1) { //  ĭ �Է� & �Է¹��� ĭ ��ȣ�� ������ �ߺ����� �Ǻ�
            int flag = 0; //  flag�� 0�̸� ��� ����, 1�̸� ���Է�
            gotoxy(39, 24);
            printf("ä��� ���� ĭ�� �����Ͻʽÿ�:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // �ٲٰ� ���� ĭ�� ��ȣ �Է�
            for (int n = 0; n < 12; n++) {
                if (used2[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("�̹� ä��ų� ���� ĭ�Դϴ�");
        }
        switch (num) { // �Է��� ĭ�� �� ����
        case 1:
            for (int m = 0; m < 5; m++) { // 1�� �ִ¸�ŭ Aces�� ����
                if (dice[m] == 1)
                    Aces2 += dice[m];
            }
            used2[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2�� �ִ¸�ŭ Duces�� ����
                if (dice[m] == 2)
                    Duces2 += dice[m];
            }
            used2[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3�� �ִ¸�ŭ Threes�� ����
                if (dice[m] == 3)
                    Threes2 += dice[m];
            }
            used2[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4�� �ִ¸�ŭ Fours�� ����
                if (dice[m] == 4)
                    Fours2 += dice[m];
            }
            used2[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5�� �ִ¸�ŭ Fives�� ����
                if (dice[m] == 5)
                    Fives2 += dice[m];
            }
            used2[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6�� �ִ¸�ŭ Sixes�� ����
                if (dice[m] == 6)
                    Sixes2 += dice[m];
            }
            used2[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // ���� ���� ��� ����
                Choice2 += dice[m];
            used2[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // �װ� �̻��� ������ �Ǻ�, �����ϸ� ��� ����, �ƴϸ� 0��
                for (int m = 0; m < 5; m++)
                    Four_Kind2 += dice[m];
            }
            used2[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3��, 2�� ���� ������ �Ǻ�, �����ϸ� ��� ����, �ƴϸ� 0��
                for (int m = 0; m < 5; m++)
                    Full_House2 += dice[m];
            }
            used2[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // �װ� �̻��� �������� �Ǻ�, �����ϸ� 15��, �ƴϸ� 0��
                S_Straight2 = 15;
            used2[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5�� ��� �������� �Ǻ�, �����ϸ� 30��, �ƴϸ� 0��
                L_Straight2 = 30;
            }
            used2[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5�� ��� ������ �Ǻ�, �����ϸ� 50��, �ƴϸ� 0��
                Yacht2 = 50;
            used2[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("�̹� ä��ų� ���� ĭ�Դϴ�");
        }
    }
}

int Rand() {
    int a = 7;
    while (!(a > 0 && a < 7)) { //0~32767 ���� 1~6�� �츮�� ���� �ϳ� ��÷
        a = rand();
    }
}

int IsFourCard(int a, int b, int c, int d, int e) {
    int count = 0; //���⼭���� a, b, c, d, e �� 4�� �̻��� ������ ���� �Ǻ�(5���� �ϵ��ڵ�), �����ϸ� count++
    if (a == b && b == c && c == d)
        count++;
    if (a == b && b == d && d == e)
        count++;
    if (a == b && b == d && d == e)
        count++;
    if (a == c && c == d && d == e)
        count++;
    if (b == c && c == d && d == e)
        count++;
    return count;
}

int IsFullHouse(int a, int b, int c, int d, int e) {
    int count = 0; // ���⼭���� 2��, 3���� ���ÿ� ���� ������ ���� �Ǻ�(10���� �ϵ��ڵ�), �����ϸ� count++
    if (a == b && c == d && d == e)
        count++;
    if (a == c && b == d && d == e)
        count++;
    if (a == d && b == c && c == e)
        count++;
    if (a == e && b == c && c == d)
        count++;
    if (b == c && a == d && d == e)
        count++;
    if (b == d && a == c && c == e)
        count++;
    if (b == e && a == c && c == d)
        count++;
    if (c == d && a == b && b == e)
        count++;
    if (c == e && a == b && b == d)
        count++;
    if (d == e && a == b && b == c)
        count++;
    return count;
}

int IsSStraight(int a, int b, int c, int d, int e) { // 1,2,3,4,5,6 �� ������ ���� ���� 1,2,3,4 / 2,3,4,5 / 3,4,5,6 ���� �������� �Ǻ�
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    switch (a) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (b) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (c) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (d) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (e) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    return (one > 0 && two > 0 && three > 0 && four > 0 || two > 0 && three > 0 && four > 0 && five > 0 || three > 0 && four > 0 || five > 0 && six > 0);
}

int IsLStraight(int a, int b, int c, int d, int e) { // 1,2,3,4,5,6 �� ������ ���� ���� 1,2,3,4,5 / 2,3,4,5,6 ���� �������� �Ǻ�
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    switch (a) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (b) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (c) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (d) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (e) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    return (one > 0 && two > 0 && three > 0 && four > 0 && five > 0 || two > 0 && three > 0 && four > 0 && five > 0 && six > 0) ? 1 : 0;
}