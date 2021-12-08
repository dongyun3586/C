#include<stdio.h>
#include<stdlib.h> // 난수 관련 rand(), srand() 함수 사용
#include<time.h> // time() 함수 사용
#include<Windows.h> // 콘솔창 함수 system("cls") 사용
#include<conio.h> // 키보드 함수 _kbhit(), _getch() 사용
#include<string.h> // 문자열 함수strcmp 함수 사용

// 화면 설정 관련
int Start(); // 시작 화면 출력 함수
int Rule(); // 규칙 화면 출력 함수
int Plate(); // 게임 판 출력 함수
int P1(); // 2인용 진행
int P2(); // 1인용 진행
int Choose(); // 화면 선택

 // 게임 관련
int Rand(); // 주사위 굴리는 함수
int IsFourCard(int a, int b, int c, int d, int e); // 받은 수 중 4개 이상이 같은지 판단하는 함수
int IsFullHouse(int a, int b, int c, int d, int e); // 받은 수 중 3개, 2개가 각각 같은지 판단하는 함수
int IsSStraight(int a, int b, int c, int d, int e); // 분은 수 중 4개 이상이 연속한지 판단하는 함수
int IsLStraight(int a, int b, int c, int d, int e); // 받은 수 5개가 연속한지 판단하는 함수

void gotoxy(int x, int y) { // 콘솔창에서 커서의 좌표 변경을 위한 함수
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
    Start();
    Choose();
}

int Start() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                    ■      ■                                 ■                                       ■\n");
    printf("■                     ■    ■                                  ■                                       ■\n");
    printf("■                      ■  ■       ■■■                      ■              ■                       ■\n");
    printf("■                        ■               ■        ■■■      ■ ■■      ■■■■                    ■\n");
    printf("■                        ■         ■■■■       ■           ■■  ■        ■                       ■\n");
    printf("■                        ■        ■     ■       ■           ■    ■        ■                       ■\n");
    printf("■                        ■         ■■■■        ■■■      ■    ■         ■■                    ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                           2: 규칙  3: 게임판                                           ■\n");
    printf("■                                              4: 1인용 시작                                             ■\n");
    printf("■                                              5: 2인용 시작                                             ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                              (규칙을 꼭 읽어보시고 시작해주시길 바랍니다)                              ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                             1603 김동빈■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int Choose() {
    while (1) {
        if (_kbhit()) { // _kbhit(): 평소에 0, 키보드를 누르면 1
            switch (_getch()) { // _getch(): 사용자가 누른 자판의 아스키 코드 반환
            case 49: // 49: 1의 아스키코드
                system("cls"); // 콘솔창 이전의 화면 제거
                Start();
                break;
            case 50: // 50: 2의 아스키코드
                system("cls");
                Rule();
                break;
            case 51: // 51: 3의 아스키코드
                system("cls");
                Plate();
                break;
            case 52: // 51: 3의 아스키코드
                system("cls");
                P1();
                break;
            case 53: // 52: 4의 아스키코드
                system("cls");
                P2();
                break;
            }
        }
    }
}

int Rule() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                   규칙                                                 ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                     목표: 12번의 차례동안 12칸을 채워 모든 칸 숫자 합이 더 큰 쪽이 승리                ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                           한 차례 동안의 진행                                          ■\n");
    printf("■                                 1. 주사위 5개(A, B, C, D, E)를 굴린다                                  ■\n");
    printf("■           2. 이중 다시 굴리고 주사위 이름을 scanf 형식으로 연달아 입력하고 나머지는 보관한다.          ■\n");
    printf("■                         (예: ACD(엔터) -> A, C, D 다시 굴림, 0 -> 다시 굴리기 종료)                    ■\n");
    printf("■                         3. 한 차례 동안 최대 2번까지 더 굴릴 수 있다(따라서 총 3번)                    ■\n");
    printf("■          4. 이렇게 굴려서 얻은 5개의 주사위 값으로 '게임 판'의 12 칸 중 무조건 한 칸만을 채운다        ■\n");
    printf("■                            (Sun Total, Bonus, Total은 자동으로 채워지는 칸이다)                        ■\n");
    printf("■                     5. 한 칸을 채우면 자신의 차례가 끝나고 상대에게 차례가 넘어간다                    ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                     채운 칸은 이후의 차례에 바꿀 수 없고 채우지 않은 다른 칸을 채운다                  ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                      모든 사람이 12 차례동안 12 개의 칸을 모두 채우면 게임 종료                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                          1: 처음으로  3: 게임판                                        ■\n");
    printf("■                                              4: 1인용 시작                                             ■\n");
    printf("■                                              5: 2인용 시작                                             ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int Plate() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                        ■\n");
    printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                      ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                 ■\n");
    printf("■   │   Aces    │    │    │ 나온 1들의 합        │   Choice  │    │    │  숫자들의 합(조건X)             ■\n");
    printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫ (예: 1 1 1 2 3 -> 3) ┣━━━━━━━━━━━╋━━━━╋━━━━┫  (예: 3 4 4 6 6 -> 18)          ■\n");
    printf("■   │   Duces   │    │    │ 나온 2들의 합        │4 of a Kind│    ┃    │  네 숫자가 같을 때, 숫자 합     ■\n");
    printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫ (예: 1 2 2 2 2 -> 8) ┣━━━━━━━━━━━╋━━━━╋━━━━┫  (예: 4 5 5 5 5 -> 24)          ■\n");
    printf("■   │   Threes  │    │    │ 나온 3들의 합        │ Full House│    │    │  셋, 둘이 각각 같을 때, 합      ■\n");
    printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫ (예: 1 2 2 4 5 -> 0) ┣━━━━━━━━━━━╋━━━━╋━━━━┫  (예: 3 3 3 6 6 -> 24)          ■\n");
    printf("■   │   Fours   │    │    │ 나온 4들의 합        │ S.Straight│    │    │  네 숫자가 연속시, 고정 15점    ■\n");
    printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                      ┣━━━━━━━━━━━┼━━━━╋━━━━┫  (예: 1 2 3 4 6 -> 15)          ■\n");
    printf("■   │   Fives   │    │    │ 나온 5들의 합        │ L.Straight│    │    │  모든 숫자가 연속시, 고정 30점  ■\n");
    printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                      ┣━━━━━━━━━━━╋━━━━╋━━━━┫  (예: 2 3 4 5 6 -> 30)          ■\n");
    printf("■   │   Sixes   │    │    │ 나온 6들의 합        │   Yacht   │    │    │  모든 숫자가 같을시, 고정 50점  ■\n");
    printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                      ┗━━━━━━━━━━━┻━━━━┻━━━━┛  (예: 1 1 1 1 1 -> 50)          ■\n");
    printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                      ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                 ■\n");
    printf("■   │ Sub Total │    │    │ 위 여섯 칸들의 합    │   Total   │    │    │  열두 칸들의 총합               ■\n");
    printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                      ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                 ■\n");
    printf("■   │   Bonus   │    │    │ Sub Total >= 63이면 +35                                                      ■\n");
    printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛ 그렇지 않으면 +0                                                             ■\n");
    printf("■                                                                                                        ■\n");
    printf("■       (4 of a Kind, Full House, S.Straight, L.straight, Yacht 각각 조건 불만족시 채우려하면 0점)       ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                          1: 처음으로  2: 규칙                                          ■\n");
    printf("■                                              4: 1인용 시작                                             ■\n");
    printf("■                                              5: 2인용 시작                                             ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int P1() {
    srand((unsigned int)time(NULL));
    int Aces = 0, Duces = 0, Threes = 0, Fours = 0, Fives = 0, Sixes = 0, Choice = 0, Four_Kind = 0, Full_House = 0, S_Straight = 0, L_Straight = 0, Yacht = 0;
    int used[13] = { 0, }; //  이미 사용한 칸의 번호를 저장
    for (int k = 0; k < 13; k++) {
        int dice[5];
        char re[5] = "FFFF";
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        int Sub_Total = Aces + Duces + Threes + Fours + Fives + Sixes;
        int Bonus = (Sub_Total >= 63) ? 35 : 0; // Sub_Total 값이 63 이상이면 +35, 미만이면 +0
        int Total = Sub_Total + Choice + Four_Kind + Full_House + S_Straight + L_Straight + Yacht + Bonus;
        if (k == 12) { //12번째 차례가 끝나면 출력되는 화면 & 1인용 게임 종료
            system("cls");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("■                                                                                                        ■\n");
            printf("■                                                 게임 종료 !                                            ■\n");
            printf("■                                                                                                        ■\n");
            printf("■   ┎━━━━━━━━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┒                                                              ■\n");
            printf("■  1│   Aces    │ %2d │ 7 │   Choice  │ %2d │                                                              ■\n", Aces, Choice);
            printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
            printf("■  2│   Duces   │ %2d │ 8 │4 of a Kind│ %2d ┃                                                              ■\n", Duces, Four_Kind);
            printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
            printf("■  3│   Threes  │ %2d │ 9 │ Full House│ %2d │                            총점                              ■\n", Threes, Full_House);
            printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
            printf("■  4│   Fours   │ %2d │ 10│ S.Straight│ %2d │                           %3d 점                             ■\n", Fours, S_Straight, Total);
            printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━┼━━━━┫                                                              ■\n");
            printf("■  5│   Fives   │ %2d │ 11│ L.Straight│ %2d │                                                              ■\n", Fives, L_Straight);
            printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
            printf("■  6│   Sixes   │ %2d │ 12│   Yacht   │ %2d │                                                              ■\n", Sixes, Yacht);
            printf("■   ┗━━━━━━━━━━━┻━━━━┛   ┗━━━━━━━━━━━┻━━━━┛                                                              ■\n");
            printf("■   ┎━━━━━━━━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┒                                                              ■\n");
            printf("■   │ Sub Total │ %3d│   │   Total   │ %3d│                                                              ■\n", Sub_Total, Total);
            printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┗━━━━━━━━━━━┻━━━━┛                                                              ■\n");
            printf("■   │   Bonus   │ +%2d│                                                                                   ■\n", Bonus);
            printf("■   ┗━━━━━━━━━━━┻━━━━┛                                                                                   ■\n");
            printf("■                                                                                                        ■\n");
            printf("■                                               1: 처음으로                                              ■\n");
            printf("■                                            2: 규칙  3: 게임판                                          ■\n");
            printf("■                                              4: 1인용 시작                                             ■\n");
            printf("■                                              5: 2인용 시작                                             ■\n");
            printf("■                                                                                                        ■\n");
            printf("■                                                                                                        ■\n");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            break;
        }
        system("cls");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("■                                                                                                        ■\n");
        printf("■   ┎━━━━━━━━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┒                                                              ■\n");
        printf("■  1│   Aces    │ %2d │ 7 │   Choice  │ %2d │                                                              ■\n", Aces, Choice);
        printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
        printf("■  2│   Duces   │ %2d │ 8 │4 of a Kind│ %2d ┃                                                              ■\n", Duces, Four_Kind);
        printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
        printf("■  3│   Threes  │ %2d │ 9 │ Full House│ %2d │                        당신의 주사위                         ■\n", Threes, Full_House);
        printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
        printf("■  4│   Fours   │ %2d │ 10│ S.Straight│ %2d │                A      B      C      D      E                 ■\n", Fours, S_Straight);
        printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━┼━━━━┫                                                              ■\n");
        printf("■  5│   Fives   │ %2d │ 11│ L.Straight│ %2d │                %d      %d      %d      %d      %d                 ■\n", Fives, L_Straight, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┫                                                              ■\n");
        printf("■  6│   Sixes   │ %2d │ 12│   Yacht   │ %2d │                                                              ■\n", Sixes, Yacht);
        printf("■   ┗━━━━━━━━━━━┻━━━━┛   ┗━━━━━━━━━━━┻━━━━┛                                                              ■\n");
        printf("■   ┎━━━━━━━━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┒                                                              ■\n");
        printf("■   │ Sub Total │ %3d│   │   Total   │ %3d│                                                              ■\n", Sub_Total, Total);
        printf("■   ┣━━━━━━━━━━━╋━━━━┫   ┗━━━━━━━━━━━┻━━━━┛                                                              ■\n");
        printf("■   │   Bonus   │ +%2d│                                                                                   ■\n", Bonus);
        printf("■   ┗━━━━━━━━━━━┻━━━━┛                                                                                   ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■           차례: %2d / 12             바꾸고 싶은 주사위 :                                               ■\n", k + 1);
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        for (int j = 0; j < 2; j++) { // 다시 굴리기 실행(최대 2회)
            gotoxy(60, 22);
            scanf("%s", re); // re는 다시 굴리고 싶은 주사위 이름을 저장해 놓은 문자열
            if (!(strcmp(re, "0"))) {
                char re[5] = "FFFF";
                break; // 다시 굴리고 싶은 re에 0이 입력 받으면 다시 굴리기 탈출
            }
            for (int i = 0; i < 5; i++) { //re에 A, B, C, D, E가 있는지 반복하며 switch-case로 분석, 있으면 다시 굴림
                switch (re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(60, 11);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(67, 11);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(74, 11);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(81, 11);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(88, 11);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char re[5] = "FFFF";
        }
        int num;
        while (1) { //  칸 입력 & 입력받은 칸 번호가 이전과 중복인지 판별
            int flag = 0; //  flag가 0이면 계속 진행, 1이면 재입력
            gotoxy(39, 24);
            printf("채우고 싶은 칸을 선택하십시오:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // 바꾸고 싶은 칸의 번호 입력
            for (int n = 0; n < 12; n++) {
                if (used[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("이미 채우거나 없는 칸입니다");
        }
        switch (num) { // 입력한 칸의 값 저장
        case 1:
            for (int m = 0; m < 5; m++) { // 1이 있는만큼 Aces에 더함
                if (dice[m] == 1)
                    Aces += dice[m];
            }
            used[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2가 있는만큼 Duces에 더함
                if (dice[m] == 2)
                    Duces += dice[m];
            }
            used[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3이 있는만큼 Threes에 더함
                if (dice[m] == 3)
                    Threes += dice[m];
            }
            used[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4가 있는만큼 Fours에 더함
                if (dice[m] == 4)
                    Fours += dice[m];
            }
            used[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5가 있는만큼 Fives에 더함
                if (dice[m] == 5)
                    Fives += dice[m];
            }
            used[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6이 있는만큼 Sixes에 더함
                if (dice[m] == 6)
                    Sixes += dice[m];
            }
            used[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // 받은 수를 모두 더함
                Choice += dice[m];
            used[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 네개 이상이 같은지 판별, 만족하면 모두 더함, 아니면 0점
                for (int m = 0; m < 5; m++)
                    Four_Kind += dice[m];
            }
            used[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3개, 2개 각각 같은지 판별, 만족하면 모두 더함, 아니면 0점
                for (int m = 0; m < 5; m++)
                    Full_House += dice[m];
            }
            used[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // 네개 이상이 연속한지 판별, 만족하면 15점, 아니면 0점
                S_Straight = 15;
            used[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5개 모두 연속한지 판별, 만족하면 30점, 아니면 0점
                L_Straight = 30;
            }
            used[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5개 모두 같은지 판별, 만족하면 50점, 아니면 0점
                Yacht = 50;
            used[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("이미 채우거나 없는 칸입니다");
        }
    }
}

int P2() {
    srand((unsigned int)time(NULL));
    int Aces1 = 0, Duces1 = 0, Threes1 = 0, Fours1 = 0, Fives1 = 0, Sixes1 = 0, Choice1 = 0, Four_Kind1 = 0, Full_House1 = 0, S_Straight1 = 0, L_Straight1 = 0, Yacht1 = 0;
    int Aces2 = 0, Duces2 = 0, Threes2 = 0, Fours2 = 0, Fives2 = 0, Sixes2 = 0, Choice2 = 0, Four_Kind2 = 0, Full_House2 = 0, S_Straight2 = 0, L_Straight2 = 0, Yacht2 = 0;
    int used1[13] = { 0, }; //  이미 사용한 칸의 번호를 저장
    int used2[13] = { 0, };
    for (int k = 0; k < 13; k++) {
        int dice[5];
        char re[5] = "FFFF";
        char Re[5] = "FFFF";
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        int Sub_Total1 = Aces1 + Duces1 + Threes1 + Fours1 + Fives1 + Sixes1;
        int Bonus1 = (Sub_Total1 >= 63) ? 35 : 0; // Sub_Total 값이 63 이상이면 +35, 미만이면 +0
        int Total1 = Sub_Total1 + Choice1 + Four_Kind1 + Full_House1 + S_Straight1 + L_Straight1 + Yacht1 + Bonus1;
        int Sub_Total2 = Aces2 + Duces2 + Threes2 + Fours2 + Fives2 + Sixes2;
        int Bonus2 = (Sub_Total2 >= 63) ? 35 : 0; // Sub_Total 값이 63 이상이면 +35, 미만이면 +0
        int Total2 = Sub_Total2 + Choice2 + Four_Kind2 + Full_House2 + S_Straight2 + L_Straight2 + Yacht2 + Bonus2;
        if (k == 12) { //12번째 차례가 끝나면 출력되는 화면 & 2인용 게임 종료
            if (Total1 != Total2) {
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                                        ■\n");
                printf("■                                                 게임 종료 !                                            ■\n");
                printf("■                                                                                                        ■\n");
                printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
                printf("■  1│   Aces    │ %2d │ %2d │ 7 │   Choice  │ %2d │ %2d │                                                    ■\n", Aces1, Aces2, Choice1, Choice2);
                printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
                printf("■  2│   Duces   │ %2d │ %2d │ 8 │4 of a Kind│ %2d ┃ %2d │                                                    ■\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
                printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
                printf("■  3│   Threes  │ %2d │ %2d │ 9 │ Full House│ %2d │ %2d │                            총점                    ■\n", Threes1, Threes2, Full_House1, Full_House2);
                printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
                printf("■  4│   Fours   │ %2d │ %2d │ 10│ S.Straight│ %2d │ %2d │                      %3d 점  ||  %3d 점            ■\n", Fours1, Fours2, S_Straight1, S_Straight2, Total1, Total2);
                printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┼━━━━┫                                                    ■\n");
                printf("■  5│   Fives   │ %2d │ %2d │ 11│ L.Straight│ %2d │ %2d │                           P%d 승리                  ■\n", Fives1, Fives2, L_Straight1, L_Straight2, (Total1 > Total2) ? 1 : 2);
                printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
                printf("■  6│   Sixes   │ %2d │ %2d │ 12│   Yacht   │ %2d │ %2d │                                                    ■\n", Sixes1, Sixes2, Yacht1, Yacht2);
                printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
                printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
                printf("■   │ Sub Total │ %3d│ %3d│   │   Total   │ %3d│ %3d│                                                    ■\n", Sub_Total1, Sub_Total2, Total1, Total2);
                printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
                printf("■   │   Bonus   │ +%2d│ +%2d│                                                                              ■\n", Bonus1, Bonus2);
                printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                                              ■\n");
                printf("■                                                                                                        ■\n");
                printf("■                                               1: 처음으로                                              ■\n");
                printf("■                                            2: 규칙  3: 게임판                                          ■\n");
                printf("■                                              4: 1인용 시작                                             ■\n");
                printf("■                                              5: 2인용 시작                                             ■\n");
                printf("■                                                                                                        ■\n");
                printf("■                                                                                                        ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break;
            }
            system("cls");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("■                                                                                                        ■\n");
            printf("■                                                 게임 종료 !                                            ■\n");
            printf("■                                                                                                        ■\n");
            printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
            printf("■  1│   Aces    │ %2d │ %2d │ 7 │   Choice  │ %2d │ %2d │                                                    ■\n", Aces1, Aces2, Choice1, Choice2);
            printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
            printf("■  2│   Duces   │ %2d │ %2d │ 8 │4 of a Kind│ %2d ┃ %2d │                                                    ■\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
            printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
            printf("■  3│   Threes  │ %2d │ %2d │ 9 │ Full House│ %2d │ %2d │                            총점                    ■\n", Threes1, Threes2, Full_House1, Full_House2);
            printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
            printf("■  4│   Fours   │ %2d │ %2d │ 10│ S.Straight│ %2d │ %2d │                     %3d 점  ||  %3d 점             ■\n", Fours1, Fours2, S_Straight1, S_Straight2, Total1, Total2);
            printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┼━━━━┫                                                    ■\n");
            printf("■  5│   Fives   │ %2d │ %2d │ 11│ L.Straight│ %2d │ %2d │                           무승부                   ■\n", Fives1, Fives2, L_Straight1, L_Straight2);
            printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
            printf("■  6│   Sixes   │ %2d │ %2d │ 12│   Yacht   │ %2d │ %2d │                                                    ■\n", Sixes1, Sixes2, Yacht1, Yacht2);
            printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
            printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
            printf("■   │ Sub Total │ %3d│ %3d│   │   Total   │ %3d│ %3d│                                                    ■\n", Sub_Total1, Sub_Total2, Total1, Total2);
            printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
            printf("■   │   Bonus   │ +%2d│ +%2d│                                                                              ■\n", Bonus1, Bonus2);
            printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                                              ■\n");
            printf("■                                                                                                        ■\n");
            printf("■                                               1: 처음으로                                              ■\n");
            printf("■                                            2: 규칙  3: 게임판                                          ■\n");
            printf("■                                              4: 1인용 시작                                             ■\n");
            printf("■                                              5: 2인용 시작                                             ■\n");
            printf("■                                                                                                        ■\n");
            printf("■                                                                                                        ■\n");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            break;
        }
        // P1차례
        system("cls");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("■                                                                                                        ■\n");
        printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
        printf("■  1│   Aces    │ %2d │ %2d │ 7 │   Choice  │ %2d │ %2d │                                                    ■\n", Aces1, Aces2, Choice1, Choice2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  2│   Duces   │ %2d │ %2d │ 8 │4 of a Kind│ %2d ┃ %2d │                당신의 주사위                       ■\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  3│   Threes  │ %2d │ %2d │ 9 │ Full House│ %2d │ %2d │        A      B      C      D      E               ■\n", Threes1, Threes2, Full_House1, Full_House2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  4│   Fours   │ %2d │ %2d │ 10│ S.Straight│ %2d │ %2d │        %d      %d      %d      %d      %d               ■\n", Fives1, Fives2, S_Straight1, S_Straight2, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┼━━━━┫                                                    ■\n");
        printf("■  5│   Fives   │ %2d │ %2d │ 11│ L.Straight│ %2d │ %2d │                                                    ■\n", Fives1, Fives2, L_Straight1, L_Straight2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  6│   Sixes   │ %2d │ %2d │ 12│   Yacht   │ %2d │ %2d │                                                    ■\n", Sixes1, Sixes2, Yacht1, Yacht2);
        printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
        printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
        printf("■   │ Sub Total │ %3d│ %3d│   │   Total   │ %3d│ %3d│                                                    ■\n", Sub_Total1, Sub_Total2, Total1, Total2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
        printf("■   │   Bonus   │ +%2d│ +%2d│                                                                              ■\n", Bonus1, Bonus2);
        printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                                              ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■           차례: %2d / 12  (P1 차례)  바꾸고 싶은 주사위 :                                               ■\n", k + 1);
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        for (int j = 0; j < 2; j++) { // 다시 굴리기 실행(최대 2회)
            gotoxy(60, 22);
            scanf("%s", re); // re는 다시 굴리고 싶은 주사위 이름을 저장해 놓은 문자열
            if (!(strcmp(re, "0"))) {
                char re[5] = "FFFF";
                break; // 다시 굴리고 싶은 re에 0이 입력 받으면 다시 굴리기 탈출
            }
            for (int i = 0; i < 5; i++) { //re에 A, B, C, D, E가 있는지 반복하며 switch-case로 분석, 있으면 다시 굴림
                switch (re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(62, 9);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(69, 9);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(76, 9);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(83, 9);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(90, 9);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char re[5] = "FFFF";
        }
        int num;
        while (1) { //  칸 입력 & 입력받은 칸 번호가 이전과 중복인지 판별
            int flag = 0; //  flag가 0이면 계속 진행, 1이면 재입력
            gotoxy(39, 24);
            printf("채우고 싶은 칸을 선택하십시오:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // 바꾸고 싶은 칸의 번호 입력
            for (int n = 0; n < 12; n++) {
                if (used1[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("이미 채우거나 없는 칸입니다");
        }
        switch (num) { // 입력한 칸의 값 저장
        case 1:
            for (int m = 0; m < 5; m++) { // 1이 있는만큼 Aces에 더함
                if (dice[m] == 1)
                    Aces1 += dice[m];
            }
            used1[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2가 있는만큼 Duces에 더함
                if (dice[m] == 2)
                    Duces1 += dice[m];
            }
            used1[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3이 있는만큼 Threes에 더함
                if (dice[m] == 3)
                    Threes1 += dice[m];
            }
            used1[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4가 있는만큼 Fours에 더함
                if (dice[m] == 4)
                    Fours1 += dice[m];
            }
            used1[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5가 있는만큼 Fives에 더함
                if (dice[m] == 5)
                    Fives1 += dice[m];
            }
            used1[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6이 있는만큼 Sixes에 더함
                if (dice[m] == 6)
                    Sixes1 += dice[m];
            }
            used1[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // 받은 수를 모두 더함
                Choice1 += dice[m];
            used1[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 네개 이상이 같은지 판별, 만족하면 모두 더함, 아니면 0점
                for (int m = 0; m < 5; m++)
                    Four_Kind1 += dice[m];
            }
            used1[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3개, 2개 각각 같은지 판별, 만족하면 모두 더함, 아니면 0점
                for (int m = 0; m < 5; m++)
                    Full_House1 += dice[m];
            }
            used1[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // 네개 이상이 연속한지 판별, 만족하면 15점, 아니면 0점
                S_Straight1 = 15;
            used1[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5개 모두 연속한지 판별, 만족하면 30점, 아니면 0점
                L_Straight1 = 30;
            }
            used1[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5개 모두 같은지 판별, 만족하면 50점, 아니면 0점
                Yacht1 = 50;
            used1[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("이미 채우거나 없는 칸입니다");
        }

        // P2차례
        for (int i = 0; i < 5; i++)
            dice[i] = Rand();
        Sub_Total1 = Aces1 + Duces1 + Threes1 + Fours1 + Fives1 + Sixes1;
        Bonus1 = (Sub_Total1 >= 63) ? 35 : 0; // Sub_Total 값이 63 이상이면 +35, 미만이면 +0
        Total1 = Sub_Total1 + Choice1 + Four_Kind1 + Full_House1 + S_Straight1 + L_Straight1 + Yacht1 + Bonus1;
        Sub_Total2 = Aces2 + Duces2 + Threes2 + Fours2 + Fives2 + Sixes2;
        Bonus2 = (Sub_Total2 >= 63) ? 35 : 0; // Sub_Total 값이 63 이상이면 +35, 미만이면 +0
        Total2 = Sub_Total2 + Choice2 + Four_Kind2 + Full_House2 + S_Straight2 + L_Straight2 + Yacht2 + Bonus2;
        system("cls");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("■                                                                                                        ■\n");
        printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
        printf("■  1│   Aces    │ %2d │ %2d │ 7 │   Choice  │ %2d │ %2d │                                                    ■\n", Aces1, Aces2, Choice1, Choice2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  2│   Duces   │ %2d │ %2d │ 8 │4 of a Kind│ %2d ┃ %2d │                당신의 주사위                       ■\n", Duces1, Duces2, Four_Kind1, Four_Kind2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  3│   Threes  │ %2d │ %2d │ 9 │ Full House│ %2d │ %2d │        A      B      C      D      E               ■\n", Threes1, Threes2, Full_House1, Full_House2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  4│   Fours   │ %2d │ %2d │ 10│ S.Straight│ %2d │ %2d │        %d      %d      %d      %d      %d               ■\n", Fives1, Fives2, S_Straight1, S_Straight2, dice[0], dice[1], dice[2], dice[3], dice[4]);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━┼━━━━┫                                                    ■\n");
        printf("■  5│   Fives   │ %2d │ %2d │ 11│ L.Straight│ %2d │ %2d │                                                    ■\n", Fives1, Fives2, L_Straight1, L_Straight2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┣━━━━━━━━━━━╋━━━━╋━━━━┫                                                    ■\n");
        printf("■  6│   Sixes   │ %2d │ %2d │ 12│   Yacht   │ %2d │ %2d │                                                    ■\n", Sixes1, Sixes2, Yacht1, Yacht2);
        printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
        printf("■   ┎━━━━━━━━━━━┳━━━━┳━━━━┒   ┎━━━━━━━━━━━┳━━━━┳━━━━┒                                                    ■\n");
        printf("■   │ Sub Total │ %3d│ %3d│   │   Total   │ %3d│ %3d│                                                    ■\n", Sub_Total1, Sub_Total2, Total1, Total2);
        printf("■   ┣━━━━━━━━━━━╋━━━━╋━━━━┫   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                    ■\n");
        printf("■   │   Bonus   │ +%2d│ +%2d│                                                                              ■\n", Bonus1, Bonus2);
        printf("■   ┗━━━━━━━━━━━┻━━━━┻━━━━┛                                                                              ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■           차례: %2d / 12  (P2 차례)  바꾸고 싶은 주사위 :                                               ■\n", k + 1);
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■                                                                                                        ■\n");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        for (int j = 0; j < 2; j++) { // 다시 굴리기 실행(최대 2회)
            gotoxy(60, 22);
            scanf("%s", Re); // Re는 다시 굴리고 싶은 주사위 이름을 저장해 놓은 문자열
            if (!(strcmp(Re, "0"))) {
                char re[5] = "FFFF";
                break; // 다시 굴리고 싶은 Re에 0이 입력 받으면 다시 굴리기 탈출
            }
            for (int i = 0; i < 5; i++) { //Re에 A, B, C, D, E가 있는지 반복하며 switch-case로 분석, 있으면 다시 굴림
                switch (Re[i]) {
                case 'A':
                    dice[0] = Rand();
                    gotoxy(62, 9);
                    printf("%d", dice[0]);
                    break;
                case 'B':
                    dice[1] = Rand();
                    gotoxy(69, 9);
                    printf("%d", dice[1]);
                    break;
                case 'C':
                    dice[2] = Rand();
                    gotoxy(76, 9);
                    printf("%d", dice[2]);
                    break;
                case 'D':
                    dice[3] = Rand();
                    gotoxy(83, 9);
                    printf("%d", dice[3]);
                    break;
                case 'E':
                    dice[4] = Rand();
                    gotoxy(90, 9);
                    printf("%d", dice[4]);
                    break;
                }
            }
            gotoxy(60, 22);
            printf("     ");
            char Re[5] = "FFFF";
        }
        while (1) { //  칸 입력 & 입력받은 칸 번호가 이전과 중복인지 판별
            int flag = 0; //  flag가 0이면 계속 진행, 1이면 재입력
            gotoxy(39, 24);
            printf("채우고 싶은 칸을 선택하십시오:        ");
            gotoxy(70, 24);
            scanf("%d", &num); // 바꾸고 싶은 칸의 번호 입력
            for (int n = 0; n < 12; n++) {
                if (used2[n] == num)
                    flag++;
            }
            if (!flag)
                break;
            gotoxy(39, 26);
            printf("이미 채우거나 없는 칸입니다");
        }
        switch (num) { // 입력한 칸의 값 저장
        case 1:
            for (int m = 0; m < 5; m++) { // 1이 있는만큼 Aces에 더함
                if (dice[m] == 1)
                    Aces2 += dice[m];
            }
            used2[k] = 1;
            break;
        case 2:
            for (int m = 0; m < 5; m++) { // 2가 있는만큼 Duces에 더함
                if (dice[m] == 2)
                    Duces2 += dice[m];
            }
            used2[k] = 2;
            break;
        case 3:
            for (int m = 0; m < 5; m++) { // 3이 있는만큼 Threes에 더함
                if (dice[m] == 3)
                    Threes2 += dice[m];
            }
            used2[k] = 3;
            break;
        case 4:
            for (int m = 0; m < 5; m++) { // 4가 있는만큼 Fours에 더함
                if (dice[m] == 4)
                    Fours2 += dice[m];
            }
            used2[k] = 4;
            break;
        case 5:
            for (int m = 0; m < 5; m++) { // 5가 있는만큼 Fives에 더함
                if (dice[m] == 5)
                    Fives2 += dice[m];
            }
            used2[k] = 5;
            break;
        case 6:
            for (int m = 0; m < 5; m++) { // 6이 있는만큼 Sixes에 더함
                if (dice[m] == 6)
                    Sixes2 += dice[m];
            }
            used2[k] = 6;
            break;
        case 7:
            for (int m = 0; m < 5; m++) // 받은 수를 모두 더함
                Choice2 += dice[m];
            used2[k] = 7;
            break;
        case 8:
            if (IsFourCard(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 네개 이상이 같은지 판별, 만족하면 모두 더함, 아니면 0점
                for (int m = 0; m < 5; m++)
                    Four_Kind2 += dice[m];
            }
            used2[k] = 8;
            break;
        case 9:
            if (IsFullHouse(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 3개, 2개 각각 같은지 판별, 만족하면 모두 더함, 아니면 0점
                for (int m = 0; m < 5; m++)
                    Full_House2 += dice[m];
            }
            used2[k] = 9;
            break;
        case 10:
            if (IsSStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) // 네개 이상이 연속한지 판별, 만족하면 15점, 아니면 0점
                S_Straight2 = 15;
            used2[k] = 10;
            break;
        case 11:
            if (IsLStraight(dice[0], dice[1], dice[2], dice[3], dice[4])) { // 5개 모두 연속한지 판별, 만족하면 30점, 아니면 0점
                L_Straight2 = 30;
            }
            used2[k] = 11;
            break;
        case 12:
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) // 5개 모두 같은지 판별, 만족하면 50점, 아니면 0점
                Yacht2 = 50;
            used2[k] = 12;
            break;
        default:
            gotoxy(39, 26);
            printf("이미 채우거나 없는 칸입니다");
        }
    }
}

int Rand() {
    int a = 7;
    while (!(a > 0 && a < 7)) { //0~32767 값중 1~6만 살리고 그중 하나 추첨
        a = rand();
    }
}

int IsFourCard(int a, int b, int c, int d, int e) {
    int count = 0; //여기서부터 a, b, c, d, e 중 4개 이상이 같은지 직접 판별(5가지 하드코딩), 만족하면 count++
    if (a == b && b == c && c == d)
        count++;
    if (a == b && b == d && d == e)
        count++;
    if (a == b && b == d && d == e)
        count++;
    if (a == c && c == d && d == e)
        count++;
    if (b == c && c == d && d == e)
        count++;
    return count;
}

int IsFullHouse(int a, int b, int c, int d, int e) {
    int count = 0; // 여기서부터 2개, 3개가 동시에 각각 같은지 직접 판별(10가지 하드코딩), 만족하면 count++
    if (a == b && c == d && d == e)
        count++;
    if (a == c && b == d && d == e)
        count++;
    if (a == d && b == c && c == e)
        count++;
    if (a == e && b == c && c == d)
        count++;
    if (b == c && a == d && d == e)
        count++;
    if (b == d && a == c && c == e)
        count++;
    if (b == e && a == c && c == d)
        count++;
    if (c == d && a == b && b == e)
        count++;
    if (c == e && a == b && b == d)
        count++;
    if (d == e && a == b && b == c)
        count++;
    return count;
}

int IsSStraight(int a, int b, int c, int d, int e) { // 1,2,3,4,5,6 의 개수를 각각 세어 1,2,3,4 / 2,3,4,5 / 3,4,5,6 쌍이 존재한지 판별
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    switch (a) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (b) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (c) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (d) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (e) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    return (one > 0 && two > 0 && three > 0 && four > 0 || two > 0 && three > 0 && four > 0 && five > 0 || three > 0 && four > 0 || five > 0 && six > 0);
}

int IsLStraight(int a, int b, int c, int d, int e) { // 1,2,3,4,5,6 의 개수를 각각 세어 1,2,3,4,5 / 2,3,4,5,6 쌍이 존재한지 판별
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    switch (a) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (b) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (c) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (d) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    switch (e) {
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        three++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    case 6:
        six++;
        break;
    }
    return (one > 0 && two > 0 && three > 0 && four > 0 && five > 0 || two > 0 && three > 0 && four > 0 && five > 0 && six > 0) ? 1 : 0;
}