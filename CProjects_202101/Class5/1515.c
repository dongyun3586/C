#include <stdio.h>
#include <stdlib.h>                     
#include <time.h>

int score = 0;

void sijak();
void wrong(int nanido);

int main() {
    printf("*******1515 Ȳ����*******\n");
    printf("*******Ʋ������ã��*******\n\n");
    sijak();
    return 0;
}

void sijak() {
    int input, nanido;

    printf("1. �����ϱ�, 2.����\n");
    scanf("%d", &input);

    //������ ������ ������ ��� �Է¹޴´�.
    while (input != 1 && input != 2) {
        printf("�ٽ� �Է����ּ��� : ");
        scanf("%d", &input);
    }

    if (input == 2)
        return;
    else {
        char a[70][70] = { 0 };
        printf("���̵� ����\n1.��, 2.�� 3.�� 4.�ؾ� \n");
        scanf("%d", &nanido);
    }

    //�Լ��� ������.
    wrong(nanido);
}

void wrong(int nanido) {
    int i, j, x, y, size = 0;
    int userx, usery;
    char a[70][70] = { 0 };

    srand(time(NULL));
    switch (nanido) {
    case 1: size = 20;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++)
                a[i][j] = 'X';
        }
        x = rand() % size + 1;
        y = (rand() % size + 25) % size + 1;
        a[x][y] = 'V'; break;
        return x, y;
    case 2: size = 40;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++)
                a[i][j] = 'M';
        }
        x = rand() % size + 1;
        y = (rand() % size + 55) % size + 1;
        a[x][y] = 'N'; break;
        return x, y;
    case 3: size = 60;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++)
                a[i][j] = 'S';
        }
        x = rand() % size + 1;
        y = (rand() % size + 67) % size + 1;
        a[x][y] = '5'; break;
        return x, y;
    case 4:size = 60;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++)
                a[i][j] = 'I';
        }
        x = rand() % size + 1;
        y = (rand() % size + 67) % size + 1;
        a[x][y] = 'l'; break;
        return x, y;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf(" %c", a[i][j]);
        }
        printf("\n");
    }

    printf("��ǥ�� �Է��ϼ���");
    scanf("%d %d", &userx, &usery);

    if (x == userx && y == usery) {
        printf("�����Դϴ�!\n");
        score++;
        printf("score : %d\n", score);
    }
    else {
        printf("�����Դϴ�\n");
        printf("������ %d, %d�Դϴ�.\n", x, y);
        score--;
        printf("score : %d\n", score);
    }

    printf("1. �ٽ��ϱ�\n");
    printf("2. ó������\n");
    printf("3. �����ϱ�\n");
    int choice;
    scanf("%d", &choice);

    while (choice < 1 || choice>3) {
        printf("�ٽ� �Է� : ");
        scanf("%d", &choice);
    }

    switch (choice) {
    case 1:wrong(nanido); break;
    case 2:sijak(); break;
    case 3:break;
    }
}