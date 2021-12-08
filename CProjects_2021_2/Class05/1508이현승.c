#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void MainScreen();         //����ȭ���� �������
void GamePlay(int size);         //���� ȭ���� �������
void HowToPlay();            //���ӹ���� �������
void GameOver(int time, int size);            //���ӿ���â�� �������
void Dig(int** minefield, int y, int x, int size);         //���� ���� �� ���ڰ� 0�̸� ��ó�� ���� ���ִ� �Լ�

int main() {
    int size;      //���ڹ��� �Ѻ��� ����

    MainScreen();      //����ȭ�� ���

    printf("���ڹ��� �Ѻ��� ���̴�? : ");
    scanf("%d", &size);

    while (size < 10 || size >= 50) {
        system("cls");
        printf("�ٽ� �Է��� �ּ���, ���ڹ��� �Ѻ��� ���̴� 10���� ũ�ų� 50���� �۾ƾ� �˴ϴ�.\n");
        scanf("%d", &size);
    }

    system("cls");

    GamePlay(size);      //����ȭ������ �Ѿ��
}

void MainScreen() {         //����ȭ��
    printf("\n");
    printf("\n");
    printf("\n");
    printf("           ����ã��\n\n");
    printf("���� ���� : enter\n");
    printf("���� ��� : a");

    while (1) {
        if (getch() == 13) {         //���� ������ MainScreen�Լ����� ������ ����ȭ������ ����
            system("cls");
            break;
        }
        else if (getch() == 97) {      //a������ ���ӹ�� �����
            system("cls");
            HowToPlay();
        }
    }
}

int** minefind;                             //���������� �巯�� ���� ��ġ�� �������ֱ� ���� �����Ҵ������ minefind�� �������ش�. 

void GamePlay(int size) {
    int** minefield;      //������ġ�� ��ó ���ڰ��� ��������

    minefield = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++)
        minefield[i] = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        memset(minefield[i], 0, sizeof(int) * size);

    for (int i = 0; i < size; i++) {        //���ڹ����� �Ͼ���ڽ� �������
        printf("%2d ", size - i);
        for (int j = 0; j < size; j++)
            printf("��");
        printf("\n");
    }

    printf("  ");
    for (int i = 0; i < size; i++)
        printf("%2d", i + 1);
    printf("\n");

    int mine;                     //������ġ �ӽ÷� ��������
    srand(time(NULL));               //�����Լ�
    for (int i = 0; i < (size * size * 40) / 256; i++) {
        mine = rand() % (size * size);            //�������� ��ġ �־���

        if (minefield[mine / size][mine % size] == 1000)      //������ġ �ߺ��ȵǰ���
            i--;
        else
            minefield[mine / size][mine % size] = 1000;         //minefield ������ġ�� 1000�־���
    }

    for (int i = 0; i < size; i++) {                  //��ó ���� ���� minefield ������ �迭�� �־���
        for (int j = 0; j < size; j++) {
            if (minefield[i][j] != 1000) {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < size && y >= 0 && y < size && minefield[x][y] == 1000) {
                            minefield[i][j]++;                        // ��,�Ʒ�,�밢���� ���������� +1 ����
                        }
                    }
                }
            }
        }
    }
    int x, y;            //����ĥ �� ��ǥ �Է¹���
    int time_taken, start_time, end_time;                           // �ɸ� �ð� �������ش�

    minefind = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        minefind[i] = (int*)malloc(sizeof(int) * size);
        memset(minefind[i], 0, sizeof(int) * size);      //minefind 0���� �ʱ�ȭ
    }

    scanf("%d %d", &x, &y);  //������ ���� ��ǥ �Է¹���

    while (x <= 0 || x > size || y > size || y <= 0)
    {
        scanf("%d %d", &x, &y);
    }

    start_time = time(NULL);            //������ �ð�����

    while (1) {
        if (x > size || y > size || x <= 0 || y <= 0)
            continue;

        minefind[size - y][x - 1] = 1;            //����ģ ���� 1 �־���
        if (minefield[size - y][x - 1] == 0)
            Dig(minefield, size - y, x - 1, size);

        system("cls");

        for (int i = 0; i < size; i++) {          //���ڹ��� ������ش�.
            printf("%2d ", size - i);
            for (int j = 0; j < size; j++)
                if (minefind[i][j] == 1)
                    printf("%2d", minefield[i][j]);
                else
                    printf("��");
            printf("\n");
        }
        printf("   ");
        for (int i = 0; i < size; i++)
            printf("%2d", i + 1);
        printf("\n");

        if (minefield[size - y][x - 1] == 1000) {                  //���ڸ� ��´ٸ�...
            system("cls");
            for (int i = 0; i < size; i++) {                       //��� ������ ��ġ�� �巯���ش�
                for (int j = 0; j < size; j++)
                    if (minefield[i][j] == 1000)
                        printf(" *");
                    else if (minefind[i][j] == 1)
                        printf("%2d", minefield[i][j]);
                    else
                        printf("��");
                printf("\n");
            }
            GameOver(1, size);                        //�����й踦 �����
            break;                              //������
        }

        int k = 1;            //���� �¸� ���θ� ��������

        for (int i = 0; i < size; i++) {                         //���� ���ڰ� �ƴ� ĭ�� ��� ���ȴ��� Ȯ��
            for (int j = 0; j < size; j++) {
                if (minefield[i][j] != 1000 && minefind[i][j] == 0)
                    k = 0;              //���ڰ� ������� �ʰ� ������ ���� ĭ�� ������ k�� 0 �־���
            }
        }

        if (k == 1) {                    //k�� 1�� ����ִٸ� ���� �¸�
            end_time = time(NULL);          //�����ð� ����
            time_taken = end_time - start_time;         //�����ð����� ���۽ð��� ���༭ �ɸ��ð��� �����ش�.
            GameOver(time_taken, size);             //���� �¸��ϵ��� �Ѵ�                    
            break;
        }
        scanf("%d %d", &x, &y);  //������ ���� ��ǥ �Է¹���

        while (x <= 0 || x > size || y > size || y <= 0)
        {
            scanf("%d %d", &x, &y);
        }
    }
}

void HowToPlay() {                       //���ӹ��
    printf("1. ���� ������ �ϸ� ���ڹ��� �Ѻ��� ���̸� �Է����ش�.\n");
    printf("2. �Է¹��� ũ���� ���ڹ��� ������ְ� �� ��� ���� ��ġ�� �Է��ϱ� ���� xy��ǥ�൵ �Բ� ������ִ�. �������� y���̰� �������� x���̴�.\n");
    printf("3. ����ĥ ���� ��ǥ�� �Է����ְ�(x��ǥ y��ǥ) �� ��ġ�� ���� �������ش�.");
    printf("4. �Է¹��� ��ǥ�� ���� ������ ��,�Ʒ�,�밢���� ��ġ�ϴ� ������ ������ ������ش�.");
    printf("5. ���ڸ� ������ ��� ������ ��ġ�� �巯���� ���ӿ����ȴ�.");
    printf("6.���ڰ� ������� ���� ��� ���� �巯���� �ȴٸ� ������ �¸��ϰ� �ɸ� �ð��� ������ش�,\n");
    printf("���ư����� space��");

    while (1)
        if (getch() == ' ')         //�����̽��� ������ ���ư�
            break;

    system("cls");
    MainScreen();
}

void GameOver(int time, int size) {
    if (time == 1)
        printf("���� �й�\n");
    else
        printf(" ���� �¸�!, �ɸ� �ð� %d�� %d��", time / 60, time % 60);             //�ɸ� �ð��� ������ش�.
}

void Dig(int** minefield, int y, int x, int size) {                  //�Է¹��� ��ġ�� minefield�� ����� ���� 0�̶�� ��ó�� ���� ��� �������ش�.
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (y + i >= 0 && y + i < size && x + j >= 0 && x + j < size) {
                if (minefind[y + i][x + j] == 0) {  // ������ ���� �ƴѰ�츸
                    minefind[y + i][x + j] = 1;                 // minefind�� ����ģ ��ġ�� 1�� �־���

                    if (minefield[y + i][x + j] == 0)
                        Dig(minefield, y + i, x + j, size);
                }
            }
        }
    }
}