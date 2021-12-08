#pragma once

//게임 진행을 하기 위해 필요한 헤더파일
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//맵을 로딩할때 편리한 변수들
#define MAPX 3
#define MAPY 2
#define MAPWIDTH 25
#define MAPHEIGHT 20

//플레이어가 누르는 방향키를 아스키코드로 변환, 저장
#define LEFTKEY 75
#define RIGHTKEY 77
#define TOPKEY 72
#define DOWNKEY 80

void CursorView() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //cersorInfo라는 커서의 정보를 관리하는 구조체 변수 정의
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    system("mode con cols=62 lines=25");
    SetConsoleTitle(TEXT("스네이크 게임               1209염예찬 정보 프로젝트"));
}

void gotoxy(int xloc, int yloc, char* string) { //x값을 2x로 변경 (가로가 세로보다 길이가 좀더 짧음), 좌표값에 바로 문자열을 입력할 수 있도록 printf함수 삽입  
    COORD pos = { 2 * xloc, yloc };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", string);
}