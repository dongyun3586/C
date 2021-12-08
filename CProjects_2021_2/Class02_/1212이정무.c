#include <stdlib.h>
#include <time.h>//������������ ���� ����
#include <stdio.h>
#include <conio.h>//getch�Լ��� ����ϱ� ���ؼ�

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SWAP(x,y) {int temp=x; x=y; y=temp;}//��ü�ϴ� �Լ�

typedef struct Puzzle //����ü�� ���ؼ� ������ �����Ѵ�.
{
    char base[3][3];
    int row;
    int col;
}Puzzle;//������ ����ü�� ����

void print_puzzle(Puzzle* puzzle)//������ ����ϴ� �Լ�
{
    int r, c;
    system("cls"); //�� ������ �ִ� �͵��� ���� ���� �Լ�(clean screen)
    for (r = 0; r < 3; r++)//��ü �ٱ���
    {
        for (c = 0; c < 3; c++)//��ü ������
        {
            if (puzzle->base[r][c])//0�� �ƴ϶��
            {
                printf("%3d", puzzle->base[r][c]);//3�ڸ� ���� �����ش�.
            }
            else
            {
                printf("   ");//0�� ��쿡�� ����
            }
        }
        printf("\n");
    }
}

int is_ending(Puzzle* puzzle)//���� ���� �˷��ش�
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
    return (r == 2) && (c == 2);//���� ��쿡 �ش���� ���� ��
}

void init_puzzle(Puzzle* puzzle)//������ �������� ����� ����.
{
    srand((unsigned)time(0));
    int rvalues[8] = { 1,2,3,4,5,6,7,8 };
    int rindex;
    for (int i = 0; i < 8; i++)
    {
        while (1)
        {
            rindex = rand() % 8;
            if (rvalues[rindex] != -1)//�̹� ������ ���̹Ƿ� �ߺ��� �� �� �־ ���� �ʴ´�.
            {
                break;
            }
        }
        puzzle->base[i / 3][i % 3] = rvalues[rindex];//�������� ���� ���̹Ƿ� ���� �������ش�.
        rvalues[rindex] = -1;// �̹� ������ ���̶�� ǥ�ø� �Ѵ�.
    }
    puzzle->base[2][2] = 0;
    puzzle->row = 2;
    puzzle->col = 2;// ����� �ִ� ĭ�̹Ƿ� �̷��� ����
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
    printf(">> ����Ű ����\n");
    printf("***1212 ������ 33����***\n");
    key = get_directionkey();//������ �����δ�

    char(*base)[3] = puzzle->base;
    switch (key)
    {
    case RIGHT:
        if (puzzle->col > 0)
        {
            SWAP(base[puzzle->row][puzzle->col], base[puzzle->row][puzzle->col - 1]);
            puzzle->col--;//�������� �Ѵٸ�, ������ ĭ���� ���� �ű��. �� �ص� ���������� �Ѵ�.
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
    Puzzle* ppuz = &puzzle;//������ �ʱ�ȭ
    init_puzzle(ppuz);
    while (!is_ending(ppuz))//������ ������ ������ ����Ѵ�.
    {
        print_puzzle(ppuz);
        move_puzzle(ppuz);
    }
    print_puzzle(ppuz);
    system("pause");
    return 0;
}