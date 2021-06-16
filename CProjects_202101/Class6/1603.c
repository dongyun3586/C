#include<stdio.h>
#include<stdlib.h> // 난수 관련 rand(), srand() 함수 사용
#include<time.h> //time() 함수 사용
#include<Windows.h> //콘솔창 관련 함수 system("cls") 사용
#include<conio.h> //키보드 관련 함수 _kbhit(), _getch() 사용

int Start(); //시작 화면 출력 함수
int Rule(); //규칙 화면 출력 함수
int Game3(); //3자리 숫자야구 진행
int Game4(); //4자리 숫자야구 진행
int Game5(); //5자리 숫자야구 진행
int Choose(); //화면 선택

void gotoxy(int x, int y) { //콘솔창에서 커서의 좌표 변경을 위한 함수
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
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                          숫자야구                                        ■\n"); //제목
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n"); //게임 시작
    printf("■                                           2:규칙                                         ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                               1603 김동빈■\n"); //이름
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int Choose() {
    while (1) {
        if (_kbhit()) { //_kbhit(): 평소에 0, 키보드를 누르면 1
            switch (_getch()) { //_getch(): 사용자가 누른 자판의 아스키 코드 반환
            case 49: //49: 1의 아스키코드
                system("cls"); //콘솔창 이전의 화면 제거
                Start();
                break;
            case 50: //50: 2의 아스키코드
                system("cls");
                Rule();
                break;
            case 51: //51: 3의 아스키코드
                system("cls");
                Game3();
                break;
            case 52: //52: 4의 아스키코드
                system("cls");
                Game4();
                break;
            case 53: //53: 5의 아스키코드
                system("cls");
                Game5();
                break;
            }
        }
    }
}

int Rule() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                             규칙                                         ■\n");
    printf("■                                                                                          ■\n");
    printf("■                      0. 목표: 컴퓨터가 설정한 수를 적은 횟수로 맞추기                    ■\n");
    printf("■                         1. 스트라이크(S): 해당 숫자와 위치가 같음                        ■\n");
    printf("■                          2. 볼(B): 해당 숫자는 같으나 위치가 다름                        ■\n");
    printf("■                      3. 아웃(Out): 입력 수의 모든 숫자가 정답에 없음                     ■\n");
    printf("■                       (예시로 답이 530일 때 135는 1S 1B, 246은 아웃)                     ■\n");
    printf("■                                   4.입력은 수를 적고 엔터                                ■\n");
    printf("■                         (그렇지 않으면 콘솔창이 흐트러 질 수 있음)                       ■\n");
    printf("■                  ※플레이 자릿수보다 많이 입력시 그만큼 끊어 읽어지므로 주의             ■\n");
    printf("■                      6. 시도 횟수가 44가 되거나 맞출때 까지 계속 반복                    ■\n");
    printf("■                       7.컴퓨터가 설정한 숫자를 맞추면 정답, 게임종료                     ■\n");
    printf("■                              8.44회 이내에 못 맞추면 게임오버                            ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
    printf("■                                         1:처음으로                                       ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                                                                          ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int Game3() {
    int num[3], awn, arr[3]; //num은 맞춰야 할 숫자(배열), awn은 입력 값, arr은 awn은 각 자리 숫자 배열
    srand(time(NULL));
    num[0] = rand() % 10; //백의 자리 숫자 고르기
    while (1) { //십의 자리 숫자 고르기
        num[1] = rand() % 10;
        if (!(num[1] == num[0]))
            break;
    }
    while (1) { //일의 자리 숫자 고르기
        num[2] = rand() % 10; `
            if (!(num[2] == num[0] || num[2] == num[1]))
                break;
    }
    int count = 0;
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                          ■\n");
    printf("■                                         3자리                                            ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                                                                          ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 4; i < 48; i++) { //총 기회 44번
        if (i <= 25) { //전반 기회
            gotoxy(12, i);
            int Strike = 0, Ball = 0;
            scanf("%3d", &awn); //수 입력
            arr[0] = awn / 100; //입력한 수 백의 자리 숫자
            arr[1] = (awn / 10) % 10; //입력한 수 십의 자리 숫자
            arr[2] = awn % 10; //입력한 수 일의 자리 숫자
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++; //같은 숫자와 위치
                        else Ball++; //같은 숫자는 존재하나 다른 위치
                    }
                }
            }
            gotoxy(25, i);
            count++;
            if (Ball == 0 && Strike == 0) printf("Out"); //일치하는 숫자가 없음
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 3) { //정답시 실행
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        ***정답***                                        ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                             컴퓨터가 설정한 숫자를 맞췄습니다                            ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        정답: %d%d%d                                         ■\n", num[0], num[1], num[2]);
                printf("■                                     시도 횟수: %2d회                                      ■\n", count);
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
                printf("■                                    1:처음으로, 2:규칙                                    ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break; //다시 Choose() 함수로 이동
            }
        }
        if (i > 25) { //후반 기회
            count++;
            gotoxy(58, i - 22);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%3d", &awn);
            arr[0] = awn / 100;
            arr[1] = (awn / 10) % 10;
            arr[2] = awn % 10;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(71, i - 22);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 3) {
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        ***정답***                                        ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                             컴퓨터가 설정한 숫자를 맞췄습니다                            ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        정답: %d%d%d                                         ■\n", num[0], num[1], num[2]);
                printf("■                                     시도 횟수: %2d회                                      ■\n", count);
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                  3/4/5를 눌러 시작하세요                                  ■\n");
                printf("■                                    1:처음으로, 2:규칙                                   ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break;
            }
        }
        if (i == 47) { //마지막 기회 실패시
            system("cls");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                      ***게임 오버***                                     ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                    44회 안에 컴퓨터가 설정한 숫자를 맞추지 못했습니다.                   ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                        정답: %d%d%d                                         ■\n", num[0], num[1], num[2]);
            printf("■                                     시도 횟수: 44회                                      ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
            printf("■                                   1: 처음으로, 2:규칙                                    ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            break;
        }
    }
}

int Game4() { //Game3과 전체적 구조는 같음
    int num[4], awn, arr[4];
    srand(time(NULL));
    num[0] = rand() % 10;
    while (1) {
        num[1] = rand() % 10;
        if (!(num[1] == num[0]))
            break;
    }
    while (1) {
        num[2] = rand() % 10;
        if (!(num[2] == num[0] || num[2] == num[1]))
            break;
    }
    while (1) {
        num[3] = rand() % 10;
        if (!(num[3] == num[0] || num[3] == num[1] || num[3] == num[2]))
            break;
    }
    int count = 0;
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                          ■\n");
    printf("■                                         4자리                                            ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                                                                          ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 4; i < 48; i++) {
        if (i <= 25) {
            gotoxy(12, i);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%4d", &awn);
            arr[0] = awn / 1000;
            arr[1] = (awn / 100) % 10;
            arr[2] = (awn / 10) % 10;
            arr[3] = awn % 10;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(25, i);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 4) {
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        ***정답***                                        ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                             컴퓨터가 설정한 숫자를 맞췄습니다                            ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        정답: %d%d%d%d                                        ■\n", num[0], num[1], num[2], num[3]);
                printf("■                                     시도 횟수: %2d회                                      ■\n", count);
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
                printf("■                                    1:처음으로, 2:규칙                                    ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break;
            }
        }
        if (i > 25) {
            count++;
            gotoxy(58, i - 22);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%4d", &awn);
            arr[0] = awn / 1000;
            arr[1] = (awn / 100) % 10;
            arr[2] = (awn / 10) % 10;
            arr[3] = awn % 10;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(71, i - 22);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 3) {
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        ***정답***                                        ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                             컴퓨터가 설정한 숫자를 맞췄습니다                            ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        정답: %d%d%d%d                                        ■\n", num[0], num[1], num[2], num[3]);
                printf("■                                     시도 횟수: %2d회                                      ■\n", count);
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
                printf("■                                    1:처음으로, 2:규칙                                    ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break;
            }
        }
        if (i == 47) {
            system("cls");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                      ***게임 오버***                                     ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                    44회 안에 컴퓨터가 설정한 숫자를 맞추지 못했습니다.                   ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                        정답: %d%d%d%d                                        ■\n", num[0], num[1], num[2], num[3]);
            printf("■                                     시도 횟수: 44회                                     ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
            printf("■                                    1:처음으로, 2:규칙                                    ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            break;
        }
    }
}

int Game5() { //Game3과 전체적인 구조는 같음
    int num[5], awn, arr[5];
    srand(time(NULL));
    num[0] = rand() % 10;
    while (1) {
        num[1] = rand() % 10;
        if (!(num[1] == num[0]))
            break;
    }
    while (1) {
        num[2] = rand() % 10;
        if (!(num[2] == num[0] || num[2] == num[1]))
            break;
    }
    while (1) {
        num[3] = rand() % 10;
        if (!(num[3] == num[0] || num[3] == num[1] || num[3] == num[2]))
            break;
    }
    while (1) {
        num[4] = rand() % 10;
        if (!(num[4] == num[0] || num[4] == num[1] || num[4] == num[2] || num[4] == num[3]))
            break;
    }
    int count = 0;
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                          ■\n");
    printf("■                                         5자리                                            ■\n");
    printf("■                                                                                          ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                           |                                              ■\n");
    printf("■                                                                                          ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 4; i < 48; i++) {
        if (i <= 25) {
            gotoxy(12, i);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%5d", &awn);
            arr[0] = awn / 10000;
            arr[1] = (awn / 1000) % 10;
            arr[2] = (awn / 100) % 10;
            arr[3] = (awn / 10) % 10;
            arr[4] = awn % 10;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(25, i);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 5) {
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        ***정답***                                        ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                             컴퓨터가 설정한 숫자를 맞췄습니다                            ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        정답: %d%d%d%d%d                                       ■\n", num[0], num[1], num[2], num[3], num[4]);
                printf("■                                     시도 횟수: %2d회                                      ■\n", count);
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
                printf("■                                    1:처음으로, 2:규칙                                    ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break;
            }
        }
        if (i > 25) {
            count++;
            gotoxy(58, i - 22);
            int Strike = 0, Ball = 0;
            count++;
            scanf("%5", &awn);
            arr[0] = awn / 10000;
            arr[1] = (awn / 1000) % 10;
            arr[2] = (awn / 100) % 10;
            arr[3] = (awn / 10) % 10;
            arr[4] = awn % 10;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (arr[j] == num[k]) {
                        if (j == k) Strike++;
                        else Ball++;
                    }
                }
            }
            gotoxy(71, i - 22);
            if (Ball == 0 && Strike == 0) printf("Out");
            else printf("%dS %dB", Strike, Ball);
            if (Strike == 5) {
                system("cls");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        ***정답***                                        ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                             컴퓨터가 설정한 숫자를 맞췄습니다                            ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                        정답: %d%d%d%d%d                                       ■\n", num[0], num[1], num[2], num[3], num[4]);
                printf("■                                     시도 횟수: %2d회                                      ■\n", count);
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
                printf("■                                    1:처음으로, 2:규칙                                    ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■                                                                                          ■\n");
                printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
                break;
            }
        }
        if (i == 47) {
            system("cls");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                      ***게임 오버***                                     ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                    44회 안에 컴퓨터가 설정한 숫자를 맞추지 못했습니다.                   ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                        정답: %d%d%d%d%d                                       ■\n", num[0], num[1], num[2], num[3], num[4]);
            printf("■                                      시도 횟수: 44회                                     ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                  3/4/5를 눌러 시작하세요                                 ■\n");
            printf("■                                    1:처음으로, 2:규칙                                    ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■                                                                                          ■\n");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            break;
        }
    }
}
