#include <stdlib.h>
#include <time.h>//무작위적으로 퍼즐 생성
#include <stdio.h>
#include <conio.h>//getch함수를 사용하기 위해서

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SWAP(x,y) {int temp=x; x=y; y=temp;}//교체하는 함수

typedef struct Puzzle //구조체를 통해서 퍼즐을 정의한다.
{
    char base[3][3];
    int row;
    int col;
}Puzzle;//퍼즐을 구조체로 정의

void print_puzzle(Puzzle* puzzle)//퍼즐을 출력하는 함수
{
    int r, c;
    system("cls"); //그 전까지 있던 것들을 전부 비우는 함수(clean screen)
    for (r = 0; r < 3; r++)//전체 줄까지
    {
        for (c = 0; c < 3; c++)//전체 열까지
        {
            if (puzzle->base[r][c])//0이 아니라면
            {
                printf("%3d", puzzle->base[r][c]);//3자리 수로 맞춰준다.
            }
            else
            {
                printf("   ");//0일 경우에는 공백
            }
        }
        printf("\n");
    }
}

int is_ending(Puzzle* puzzle)//끝날 때를 알려준다
{
    int r, c;

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            if (puzzle->base[r][c] == r * 3 + c + 1)
            {
                break;
            }
        }
    }
    return (r == 2) && (c == 2);//위의 경우에 해당되지 않을 때
}

void init_puzzle(Puzzle* puzzle)//퍼즐을 랜덤으로 만들어 낸다.
{
    srand((unsigned)time(0));
    int rvalues[8] = { 1,2,3,4,5,6,7,8 };
    int rindex;
    for (int i = 0; i < 8; i++)
    {
        while (1)
        {
            rindex = rand() % 8;
            if (rvalues[rindex] != -1)//이미 쓰여진 것이므로 중복이 될 수 있어서 하지 않는다.
            {
                break;
            }
        }
        puzzle->base[i / 3][i % 3] = rvalues[rindex];//쓰여지지 않은 것이므로 값을 지정해준다.
        rvalues[rindex] = -1;// 이미 쓰여진 것이라는 표시를 한다.
    }
    puzzle->base[2][2] = 0;
    puzzle->row = 2;
    puzzle->col = 2;// 비워져 있는 칸이므로 이렇게 지정
}
int get_directionkey()
{
    int key = 0;
    key = _getch();
    if (key == 224)
    {
        return _getch();
    }
    return 0;
}
void move_puzzle(Puzzle* puzzle)
{
    int key;
    printf(">> 방향키 선택\n");
    printf("***1212 이정무 33퍼즐***\n");
    key = get_directionkey();//퍼즐을 움직인다

    char(*base)[3] = puzzle->base;
    switch (key)
    {
    case RIGHT:
        if (puzzle->col > 0)
        {
            SWAP(base[puzzle->row][puzzle->col], base[puzzle->row][puzzle->col - 1]);
            puzzle->col--;//오른쪽을 한다면, 오른쪽 칸으로 값을 옮긴다. 그 밑도 마찬가지로 한다.
        }
        return;
    case LEFT:
        if (puzzle->col < 2)
        {
            SWAP(base[puzzle->row][puzzle->col], base[puzzle->row][puzzle->col + 1]);
            puzzle->col++;
        }
        return;
    case UP:
        if (puzzle->row < 2)
        {
            SWAP(base[puzzle->row][puzzle->col], base[puzzle->row + 1][puzzle->col]);
            puzzle->row++;
        }
        return;
    case DOWN:
        if (puzzle->row > 0)
        {
            SWAP(base[puzzle->row][puzzle->col], base[puzzle->row - 1][puzzle->col]);
            puzzle->row--;
        }
        return;
    }
}
int main()
{
    Puzzle puzzle;
    Puzzle* ppuz = &puzzle;//퍼즐을 초기화
    init_puzzle(ppuz);
    while (!is_ending(ppuz))//퍼즐이 끝나지 않으면 계속한다.
    {
        print_puzzle(ppuz);
        move_puzzle(ppuz);
    }
    print_puzzle(ppuz);
    system("pause");
    return 0;
}