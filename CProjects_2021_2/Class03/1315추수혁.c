#include <stdio.h>
#include <Windows.h> //소리 출력, 시스템 배경 색 변경 위해 필요
#include <conio.h> // 콘솔 창 크기 변경에 필요
#include <gameux.h> // textcolor
#include <time.h> // time 변수 설정

#define G 1567.982 //도레미파"솔"

typedef struct {
    int nameunA;
    int nameunB;
    int A[2];
    int B[2];
    int p;
} _goBack;

void setting(); // 전체적 게임 진행
void mainhwamyeonGeurigi(); // 로비 화면 그리기
void loading(); // 로딩 화면 출력
void maping(char* name1, char* name2, int num1, int num2); //맵 그리기
void gameStart(char* name1, char* name2);  // 동전 튕기기
void printInfo(char* name1, char* name2, int su1, int su2); //맵 외에 경기 방법과 남은 카드 수 출력
void AcardPrinting(int* A); //플레이어 1 카드 출력
void BcardPrinting(int* B); //플레이어 2 카드 출력
void playing(int* nameunA, int* nameunB, _goBack* k); //키 입력 받고 카드 입력 시 보유 장수 감소

void textcolor(int color_number) { //글자색 설정(인터넷 참고)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y) { //gotoxy함수(인터넷 참고) 
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void main() {
    system("mode con cols=58 lines=16"); // 디버거 콘솔 크기
    system("color 3"); // 바탕 색깔 검은색으로. 더이상 불변
    setting();
}

void setting() { //게임의 전체적인 진행
    char playerA[6] = " ", playerB[6] = " "; //플레이어의 이름 저장할 문자열

    mainhwamyeonGeurigi();
    int i = 0;
    _goBack score[100] = { 0 };

    int a = _getch(); //시작 키 입력
    if (a == 'p') { //시작 키 입력 후 진행
        loading();
        printf("\n\n\n\n\n\n\n\n                Player A의 이름? \n\n\n\n\n\n\n\n");
        gets(playerA); // 플레이어 1 이름 입력
        printf("\n\n\n\n\n\n\n\n                Player B의 이름? \n\n\n\n\n\n\n\n");
        gets(playerB); // 플레이어 2 이름 입력
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(1000);
        gameStart(&playerA, &playerB); // 동전 튕기기
        int muchA = 28, muchB = 28; // 초기 두 플레이어가 가지고 있는 카드 수 설정
        maping(&playerA, &playerB, muchA, muchB); // 맵 그리기
        while (muchA > 0 && muchB > 0) { //두 사람이 보유하는 카드의 수가 0보다 큰 동안 이 반복문 진행
            if (((score[i].A[0] == score[i].B[0]) && (score[i].A[1] + score[i].B[1] == 3)) || ((score[i].A[0] != score[i].B[0]) && (score[i].A[1] == 4 || score[i].B[1] == 4))) { //같은 색의 5개가 모였을 때 종 치게 하는 조건문
                int s = _getch(); //플레이어 종 입력
                if (s == 'd') { //플레이어 1 종
                    muchA += score[i].p; //바닥에 깔린 카드 더하기
                    maping(&playerA, &playerB, muchA, muchB);//보유 카드 수 제외 맵 초기화
                }
                else if (s == 'k') { //플레이어 2 종
                    muchB += score[i].p;
                    maping(&playerA, &playerB, muchA, muchB);
                }
                i++; // 계속 진행
            }
            playing(&muchA, &muchB, &score[i]); //카드 오픈하는 함수
            gotoxy(0, 10);
            printInfo(&playerA, &playerB, muchA, muchB); //플레이어 정보 출력
            printf("현재 p:%d", score[i].p);
        }
        if (muchA == 0) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n         %s 승!    \n\n\n\n\n\n\n\n", playerB);
        }
        if (muchB == 0) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n         %s 승!    \n\n\n\n\n\n\n\n", playerA);
        }
    }
    else {
        printf("\n\n\n\n\n\n\n                 이용해주셔서 감사합니다.\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n");
    }
}

void mainhwamyeonGeurigi() { //로비 화면 프린팅
    textcolor(14);
    printf("\n\n\n        000000000000000000000000000000000000000000\n");
    textcolor(15);
    printf("        0000000000                      0000000000\n");
    textcolor(14);
    printf("        0000000000      ");
    textcolor(11);
    printf("할 리 갈 리     ");
    textcolor(14);
    printf("0000000000\n");
    textcolor(15);
    printf("        0000000000                      0000000000\n");
    textcolor(14);
    printf("        000000000000000000000000000000000000000000\n");
    textcolor(15);
    printf("        000000000000000000000000000000000000000000\n");
    textcolor(14);
    printf("        0000000000                      0000000000\n");
    textcolor(15);
    printf("        0000000000  ");
    textcolor(11);
    printf("press <p> to start  ");
    textcolor(15);
    printf("0000000000\n");
    textcolor(14);
    printf("        0000000000                      0000000000\n");
    textcolor(15);
    printf("        000000000000000000000000000000000000000000\n\n\n");
}

void loading() { // 로딩중 표시
    printf("\n\n\n\n\n\n\n                   Please waiting..                   \n\n\n\n\n\n\n\n");
    Beep(G, 300);
    Sleep(100);
    printf("\n\n\n\n\n\n\n                   Please waiting....                   \n\n\n\n\n\n\n\n");
    Beep(G, 300);
    Sleep(100);
    printf("\n\n\n\n\n\n\n                   Please waiting......                   \n\n\n\n\n\n\n\n");
    Beep(G, 300);
    Sleep(100);
    printf("\n\n\n\n\n\n\n                   Please waiting..                   \n\n\n\n\n\n\n\n");
    Sleep(400);
    printf("\n\n\n\n\n\n\n                   Please waiting....                   \n\n\n\n\n\n\n\n");
    Sleep(400);
    printf("\n\n\n\n\n\n\n                   Please waiting......                   \n\n\n\n\n\n\n\n");
    Sleep(200);
}

void maping(char* name1, char* name2, int num1, int num2) {
    char map[10][59] = {
       {"0000000000000000000000000000000000000000000000000000000000"},
       {"0000000000000000000000000000000000000000000000000000000000"},
       {"0001111111111100111111111110000111111111110011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100100000000010000100000000010011111111111000"},
       {"0001111111111100111111111110000111111111110011111111111000"},
       {"0000000000000000000000000000000000000000000000000000000000"}
    };

    system("cls"); //맵 깔끔히 출력 위해 한번 화면 모두 지우기
    int h, w;

    for (h = 0; h < 10; h++) {
        for (w = 0; w < 59; w++) {
            char temp = map[h][w];
            if (temp == '0')
                printf(" ");
            else
                printf("%c", temp);
        }
    }
    printf("\n");
    printInfo(name1, name2, num1, num2);
}

void printInfo(char* name1, char* name2, int su1, int su2) {
    printf("\n      %s   남은카드 : %d장       %s  남은카드 : %d장 \n\n", name1, su1, name2, su2);
    printf("          종 치기 : d                 종 치기 : k\n");
    printf("        카드 뒤집기 : a             카드 뒤집기 : h \n");
}

void gameStart(char* name1, char* name2) {
    int a;
    printf("                동전 튕기는 중....\n");
    Sleep(3000);
    srand(time(NULL));
    a = rand() % 2;
    if (a == 0) {
        printf("\n                   %s 선!\n\n\n\n\n\n\n", name1);
        Sleep(3000);
    }
    else {
        printf("\n                %s 선!\n\n\n\n\n\n\n", name2);
        Sleep(3000);
    }
}

void AcardPrinting(int* A) {
    int cards[56][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {1,0}, {1,0}, {1,0}, {1,0}, {1,0}, {1,1}, {1,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {2,0}, {2,0}, {2,0}, {2,0}, {2,0}, {2,1}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {2,4}, {3,0}, {3,0}, {3,0}, {3,0}, {3,0}, {3,1}, {3,1}, {3,1}, {3,2}, {3,2}, {3,2}, {3,3}, {3,3}, {3,4} };
    int t, color, number;

    srand(time(NULL));
    t = rand() % 56;
    color = cards[t][0];
    number = cards[t][1];

    int a, b;
    a = color;
    b = number;

    if (a == 0 && b == 0) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 1 && b == 0) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 2 && b == 0) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 3 && b == 0) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("  "); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("  "); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 0 && b == 1) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 1) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 1) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 1) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 0 && b == 2) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 1 && b == 2) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 2 && b == 2) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 3 && b == 2) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("  "); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("  "); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 0 && b == 3) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 3) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 3) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 3) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("  "); textcolor(15);

    }
    else if (a == 0 && b == 4) {
        gotoxy(9, 4); textcolor(11);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(11);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(11);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(11);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(11);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 1 && b == 4) {
        gotoxy(9, 4); textcolor(12);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(12);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(12);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(12);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(12);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 2 && b == 4) {
        gotoxy(9, 4); textcolor(13);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(13);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(13);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(13);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(13);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    else if (a == 3 && b == 4) {
        gotoxy(9, 4); textcolor(14);
        gotoxy(9, 4); printf("■"); textcolor(15);
        gotoxy(11, 6); textcolor(14);
        gotoxy(11, 6); printf("■"); textcolor(15);
        gotoxy(11, 4); textcolor(14);
        gotoxy(11, 4); printf("■"); textcolor(15);
        gotoxy(9, 6); textcolor(14);
        gotoxy(9, 6); printf("■"); textcolor(15);
        gotoxy(10, 5); textcolor(14);
        gotoxy(10, 5); printf("■"); textcolor(15);
    }
    A[0] = a, A[1] = b;
}

void BcardPrinting(int* B) {
    int cards[56][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {1,0}, {1,0}, {1,0}, {1,0}, {1,0}, {1,1}, {1,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {2,0}, {2,0}, {2,0}, {2,0}, {2,0}, {2,1}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {2,4}, {3,0}, {3,0}, {3,0}, {3,0}, {3,0}, {3,1}, {3,1}, {3,1}, {3,2}, {3,2}, {3,2}, {3,3}, {3,3}, {3,4} };
    int t, color, number;

    srand(time(NULL));
    t = rand() % 56;
    color = cards[t][0];
    number = cards[t][1];

    int a, b;
    a = color;
    b = number;

    if (a == 0 && b == 0) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 1 && b == 0) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 2 && b == 0) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 3 && b == 0) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("  "); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("  "); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 0 && b == 1) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 1) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 1) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 1) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 0 && b == 2) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 1 && b == 2) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 2 && b == 2) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 3 && b == 2) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("  "); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("  "); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 0 && b == 3) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 1 && b == 3) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 2 && b == 3) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("  "); textcolor(15);
    }
    else if (a == 3 && b == 3) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("  "); textcolor(15);

    }
    else if (a == 0 && b == 4) {
        gotoxy(17, 4); textcolor(11);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(11);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(11);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(11);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(11);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 1 && b == 4) {
        gotoxy(17, 4); textcolor(12);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(12);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(12);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(12);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(12);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 2 && b == 4) {
        gotoxy(17, 4); textcolor(13);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(13);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(13);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(13);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(13);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    else if (a == 3 && b == 4) {
        gotoxy(17, 4); textcolor(14);
        gotoxy(17, 4); printf("■"); textcolor(15);
        gotoxy(19, 6); textcolor(14);
        gotoxy(19, 6); printf("■"); textcolor(15);
        gotoxy(19, 4); textcolor(14);
        gotoxy(19, 4); printf("■"); textcolor(15);
        gotoxy(17, 6); textcolor(14);
        gotoxy(17, 6); printf("■"); textcolor(15);
        gotoxy(18, 5); textcolor(14);
        gotoxy(18, 5); printf("■"); textcolor(15);
    }
    B[0] = a, B[1] = b;
}

void playing(int* nameunA, int* nameunB, _goBack* k) {

    int a = _getch();

    if (a == 'a') {
        AcardPrinting(k->A);
        (*nameunA)--;
        k->nameunA = *nameunA;
        (k->p)++;
    }
    else if (a == 'h') {
        BcardPrinting(k->B);
        (*nameunB)--;
        k->nameunB = *nameunB;
        (k->p)++;
    }
}