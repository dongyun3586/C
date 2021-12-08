#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int map[10][10] = { 0 };
int car = 0;
int ax, ay;
int bx, by;
int cx, cy;
int dx, dy;
int ex, ey;
int flag = 0; // 게임 종료 조건 판단을 위한 flag


void GotoXY(int x, int y) {//커서의 위치를 x, y로 이동하는 함수
    COORD Pos;
    Pos.X = 2 * x; // x로 증가하는 간격이 짧아 2를 곱해준다
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {//어떤 키가 눌렸는지 반환하는 함수 - 엔터를 치지 않아도 바로 반환함
    if (_kbhit() != 0)
        return _getch();
    return 0;
}

void hor2(int x, int y, int n) {
    GotoXY(x, y);
    printf("%c %c", n + 65, n + 65);
    map[x][y] = n + 65;
    map[x + 1][y] = n + 65;
}

void hor3(int x, int y, int n) {
    GotoXY(x, y);
    printf("%c %c %c", n + 65, n + 65, n + 65);
    map[x][y] = n + 65;
    map[x + 1][y] = n + 65;
    map[x + 2][y] = n + 65;
}

void ver2(int x, int y, int n) {
    GotoXY(x, y);
    printf("%c", n + 65);
    GotoXY(x, y + 1);
    printf("%c", n + 65);
    map[x][y] = n + 65;
    map[x][y + 1] = n + 65;
}

void ver3(int x, int y, int n) {
    GotoXY(x, y);
    printf("%c", n + 65);
    GotoXY(x, y + 1);
    printf("%c", n + 65);
    GotoXY(x, y + 2);
    printf("%c", n + 65);
    map[x][y] = n + 65;
    map[x][y + 1] = n + 65;
    map[x][y + 2] = n + 65;
}

void makemap() {  // 차들의 x, y 좌표 값 지정, 배열에 그 값들을 저장 
    ax = 1;
    ay = 3;
    bx = 1;
    by = 4;
    cx = 3;
    cy = 1;
    dx = 6;
    dy = 4;
    ex = 5;
    ey = 1;
    hor2(1, 3, 19);
    hor3(1, 4, 1);
    ver3(3, 1, 3);
    ver3(6, 4, 4);
    hor2(5, 1, 5);
}

void carselect() { // 차 선택
    GotoXY(20, 20);
    printf("Select a car");
    while (1) {
        int gkd = GetKeyDown();
        if (gkd == 84) {
            car = 84;
            break;
        }

        else if (gkd == 66) {
            car = 66;
            break;
        }

        else if (gkd == 70) {
            car = 70;
            break;
        }
        else if (gkd == 69) {
            car = 69;
            break;
        }
        else if (gkd == 68) {
            car = 68;
            break;
        }

    }
}
void carmovever(int car, int* x, int* y, int size) { // 세로 차 이동
    while (1) {
        int gkd = GetKeyDown();
        if (gkd == 'w') {
            if (map[*x][*y - 1] == 0 && *y - 1 > 0) {
                GotoXY(*x, *y - 1);
                printf("%c", car);
                GotoXY(*x, *y + size - 1);
                printf(" ");
                map[*x][*y + size - 1] = 0;
                map[*x][*y - 1] = car;
                (*y)--;
            }
        }
        else if (gkd == 's') {
            if (map[*x][*y + size] == 0 && *y + size <= 6) {
                GotoXY(*x, *y);
                printf(" ");
                GotoXY(*x, *y + size);
                printf("%c", car);
                map[*x][*y] = 0;
                map[*x][*y + 3] = car;
                (*y)++;
            }
        }
        else if (gkd == 'p') { // p 키를 누르면 함수에서 빠져나가 다시 새로운 차를 선택할 수 있다
            break;
        }
    }
}

void carmovehor(int car, int* x, int* y, int size) // 가로 차의 이동
{
    while (1) {
        int gkd = GetKeyDown();
        if (gkd == 'd') {
            if (map[*x + size][*y] == 0 && *x + size <= 6) {
                GotoXY(*x, *y);
                printf(" ");
                for (int i = 0; i < size; i++)
                    printf(" %c", car);
                map[*x][*y] = 0;
                map[*x + size][*y] = car;
                (*x)++;
            }
        }
        else if (gkd == 'a') {
            if (map[*x - 1][*y] == 0 && *x - 1 > 0) {
                GotoXY(*x - 1, *y);
                for (int i = 0; i < size; i++)
                    printf("%c ", car);
                printf(" ");
                map[*(x)+size - 1][*y] = 0;
                map[*(x)-1][*y] = car;
                (*x)--;
            }
        }
        else if (gkd == 'p') {
            break;
        }
        if (ax == 5) {
            GotoXY(12, 2);
            flag = 1;
            break;
        }
    }


}
void caricmove(int n) { // 입력에 맞게 carmovehor, carmovever 함수 호출
    while (1) {
        int gkd = GetKeyDown();
        if (gkd == 'p') {
            break;
        }
        else if (n == 65) {

        }
        else if (n == 66) {
            carmovehor('B', &bx, &by, 3);
            break;
        }
        else if (n == 'F') {
            carmovehor('F', &ex, &ey, 2);
            break;
        }
        else if (n == 'E') {
            carmovever('E', &dx, &dy, 3);
            break;
        }
        else if (n == 'D') {
            carmovever('D', &cx, &cy, 3);
            break;
        }
        else if (n == 'T') {
            carmovehor('T', &ax, &ay, 2);
            break;
        }

        GotoXY(0, 10);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf(" %2d ", map[j][i]);
            }
            printf("\n");
        }
    }
}

int main() {
    makemap();

    GotoXY(20, 15);
    printf("러시아워 게임\n\n");
    printf("\t차를 선택할 때 차의 이름을 대문자로 입력하세요\n");
    printf("\t차를 바꿀 때 P 키를 누른 후 바꿀 차의 이름을 대문자로 입력하세요\n");
    printf("\tT 차가 게임판의 오른쪽 끝에 도달하면 게임이 끝납니다.\n");
    while (1) {
        carselect();
        GotoXY(20, 21);
        printf("car : %c", car);
        caricmove(car);
        if (flag == 1) { // flag가 1이 되면 성공하였다는 메세지 출력하고 프로그램 종료
            GotoXY(20, 10);
            printf("성공하셨습니다!!");
            break;
        }

    }
    GotoXY(20, 25);

}