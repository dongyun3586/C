#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int score = 0; // ����
int board[4][4] = { // ������
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};

void draw(void); // ���� �׸��� �Լ�
void new_num(void); // ���忡 2�� 4�� ���� �����ϴ� �Լ�
void check_game_over(void); // ���ӿ������� üũ

main() {
    int i, j, r; //for��
    int key; // �Է� key ��
    int act; // key�Է� �� ��ȭ ����

    new_num(); // �� ���� ����
    new_num(); // 2���� �� ����
    draw(); // �������� �׸�

    while (1) {
        key = getch(); //key �Է��� ����
        if (key == 0xE0 || key == 0) { //����Ű�� ��� key �Է½� 0xE0+Ű���� �ΰ� ���޵�
            key = getch(); // ó�� 0xE0 ����, 2��° key �� ���� �Ǵ�

            switch (key) { // switch-case �� : case�� LEFT, RIGHT, UP, DOWN 4��
            case LEFT: //1�� ��� (���� ȭ��ǥ)
                for (i = 0, act = 0; i < 4; i++) { //��� �� �˻�
                    for (j = 1; j <= 3; j++) { // 1~3�� �˻�
                        for (r = j; r > 0; r--) { //j�� r�� �����ϰ� ������ �о����
                            if (board[i][r] == 0 || board[i][r] > 10000) break; //���� 0�̰ų� 10000�ʰ� �� break
                            if (board[i][r - 1] != 0 && board[i][r - 1] != board[i][r]) break; //���ʰ��� 0�� �ƴϰ� �ش� ��ϰ� �ٸ� ��� break;
                            if (board[i][r - 1] == 0) board[i][r - 1] = board[i][r];    //�ڱ� ���ʰ��� 0�ΰ�� �ڱⰪ ����
                            else if (board[i][r] == board[i][r - 1]) { //�ڱ� ���ʰ��� ������ ��쿡
                                board[i][r - 1] *= 2; //�� ���� 2��� (���ϸ� 2�� �ŵ������� ��)
                                board[i][r - 1] += 10000; // �ӽ� +10000, �Լ� ���κп� �ٽ� ���� ���ҽ�Ŵ
                                score += 2 * (board[i][r]); //������ ����
                            }
                            board[i][r] = 0;     //���� ����� 0���� ����
                            act++; // action�� ������ �˸�(get_key �Լ� ����� �Ǵܵ�)
                        }
                    }
                }
                break;

            case RIGHT: //2�� ��� (������ ȭ��ǥ) 1���� �¿� ��ȯ ���� (r-1 �� r+1 ��)
                for (i = 0, act = 0; i < 4; i++) { //��� �� �˻�
                    for (j = 2; j >= 0; j--) { // 2~0�� �˻�
                        for (r = j; r < 3; r++) {
                            if (board[i][r] == 0 || board[i][r] > 10000) break;
                            if (board[i][r + 1] != 0 && board[i][r + 1] != board[i][r]) break;
                            if (board[i][r + 1] == 0) board[i][r + 1] = board[i][r];
                            else if (board[i][r] == board[i][r + 1]) {
                                board[i][r + 1] *= 2;
                                board[i][r + 1] += 10000;
                                score += 2 * (board[i][r]);
                            }
                            board[i][r] = 0;
                            act++;
                        }
                    }
                }
                break;

            case UP: //3�� ��� (���� ȭ��ǥ) 1���� �࿭ ��ȯ ���� (r-1�� j ������)
                for (j = 0, act = 0; j < 4; j++) { //��� �� �˻�
                    for (i = 1; i <= 3; i++) { // 1~3�� �˻�
                        for (r = i; r > 0; r--) {
                            if (board[r][j] == 0 || board[r][j] > 10000) break;
                            if (board[r - 1][j] != 0 && board[r - 1][j] != board[r][j]) break;
                            if (board[r - 1][j] == 0) board[r - 1][j] = board[r][j];
                            else if (board[r][j] == board[r - 1][j]) {
                                board[r - 1][j] *= 2;
                                board[r - 1][j] += 10000;
                                score += 2 * (board[r][j]);
                            }
                            board[r][j] = 0;
                            act++;
                        }
                    }
                }
                break;

            case DOWN:  //4�� ��� (�Ʒ��� ȭ��ǥ) 3���� ���� ��ȯ ���� (�տ� �ִ� r-1�� r+1��)
                for (j = 0, act = 0; j < 4; j++) { //��� �� �˻�
                    for (i = 2; i >= 0; i--) { // 2~0�� �˻�
                        for (r = i; r < 3; r++) {
                            if (board[r][j] == 0 || board[r][j] > 10000) break;
                            if (board[r + 1][j] != 0 && board[r + 1][j] != board[r][j]) break;
                            if (board[r + 1][j] == 0) board[r + 1][j] = board[r][j];
                            else if (board[r][j] == board[r + 1][j]) {
                                board[r + 1][j] *= 2;
                                board[r + 1][j] += 10000;
                                score += 2 * (board[r][j]);
                            }
                            board[r][j] = 0;
                            act++;
                        }
                    }
                }
                break;

            }
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (board[i][j] > 10000)
                    board[i][j] -= 10000; //�Ʊ� ���� 10000�� ��
            }
        }

        if (act > 0) { //act��ȣ�� �־��� ��쿡�� (������)
            new_num(); //���ο� ���ڸ� �ϳ� ����
            draw(); //�������� ���� �׸�
            check_game_over(); //���� ������ üũ
        }
    }
}

void draw(void) { // ������ �׸��� 4x4��
    int i, j;

    system("cls");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (board[i][j] == 0) printf("    ."); // ���� 0�̸� ��ó��
            else printf("%5d", board[i][j]); // ���� ���� ����
        }
        printf("\n");
    }
    printf("\n");
    printf("Score : %d \n", score); //������, ���� �Ʒ��� ����
}

void new_num(void) { // 2�� 4 ����, �� Ŭ������
    int i, j;
    int cnt;
    int* p0[16] = { 0 };

    for (i = 0, cnt = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            if (board[i][j] == 0) {
                p0[cnt] = &board[i][j];
                cnt++;
            }
    }

    *p0[rand() % (cnt)] = (rand() % 100 < 80) ? 2 : 4; //2�� ���� Ȯ�� 80%, 4�� ���� Ȯ�� 20% : 2�� �� ���� ���鵵�� ��
}

void check_game_over(void) { //���ӿ������� üũ
    int i, j;

    for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (board[i][j] == 0) return;
    for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) return;
    for (i = 0; i < 3; i++) if (board[i][3] == board[i + 1][3]) return;
    for (j = 0; j < 3; j++) if (board[3][j] == board[3][j + 1]) return;

    printf("Game Over..");
    exit(0);
}