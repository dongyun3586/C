#include <stdio.h>
#include <stdlib.h>                     
#include <time.h>

int score = 0;

void sijak();
void wrong(int nanido);

int main() {
    printf("*******1515 황규현*******\n");
    printf("*******틀린글자찾기*******\n\n");
    sijak();
    return 0;
}

void sijak() {
    int input, nanido;

    printf("1. 게임하기, 2.종료\n");
    scanf("%d", &input);

    //범위를 만족할 때까지 계속 입력받는다.
    while (input != 1 && input != 2) {
        printf("다시 입력해주세요 : ");
        scanf("%d", &input);
    }

    if (input == 2)
        return;
    else {
        char a[70][70] = { 0 };
        printf("난이도 선택\n1.하, 2.중 3.상 4.극악 \n");
        scanf("%d", &nanido);
    }

    //함수로 보낸다.
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

    printf("좌표를 입력하세요");
    scanf("%d %d", &userx, &usery);

    if (x == userx && y == usery) {
        printf("정답입니다!\n");
        score++;
        printf("score : %d\n", score);
    }
    else {
        printf("오답입니다\n");
        printf("정답은 %d, %d입니다.\n", x, y);
        score--;
        printf("score : %d\n", score);
    }

    printf("1. 다시하기\n");
    printf("2. 처음으로\n");
    printf("3. 종료하기\n");
    int choice;
    scanf("%d", &choice);

    while (choice < 1 || choice>3) {
        printf("다시 입력 : ");
        scanf("%d", &choice);
    }

    switch (choice) {
    case 1:wrong(nanido); break;
    case 2:sijak(); break;
    case 3:break;
    }
}