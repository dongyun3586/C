#pragma once

//���� ������ �ϱ� ���� �ʿ��� �������
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//���� �ε��Ҷ� ���� ������
#define MAPX 3
#define MAPY 2
#define MAPWIDTH 25
#define MAPHEIGHT 20

//�÷��̾ ������ ����Ű�� �ƽ�Ű�ڵ�� ��ȯ, ����
#define LEFTKEY 75
#define RIGHTKEY 77
#define TOPKEY 72
#define DOWNKEY 80

void CursorView() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //cersorInfo��� Ŀ���� ������ �����ϴ� ����ü ���� ����
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    system("mode con cols=62 lines=25");
    SetConsoleTitle(TEXT("������ũ ����               1209������ ���� ������Ʈ"));
}

void gotoxy(int xloc, int yloc, char* string) { //x���� 2x�� ���� (���ΰ� ���κ��� ���̰� ���� ª��), ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����  
    COORD pos = { 2 * xloc, yloc };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", string);
}