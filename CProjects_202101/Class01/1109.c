#include<stdio.h>/////
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void printsdoku();//맨 처음 화면 출력
void loading();//로딩 단어 출력
void printmunjea();//'문제를 생성중입니다....'출력
void easy();
void medium();
void hard();
void good();

int main() {
    system("color F1");

    printsdoku();
    srand(time(NULL));
    int chogihwa; // 스도쿠 완성했을때 다시 할껀지 말껀지 물어보기
    int n;//난이도 선택
    int m;// 난이도를 알맞게 선택했는지
    int num; // 스도쿠 빈칸에 들어갈 숫자
HAHA://난이도 잘못 골랐을 때 처음으로 다시 되돌아가게 함

    printf("난이도를 선택하세요\n1.초보  2.중급  3.고수\n");
    scanf("%d", &n);
    system("cls");//화면 비우기
    if (n == 1) {
        printf("초급자 난이도로 하시겠습니까?\n");
        printf("Yes = 1입력 / NO = 2입력\n");
        scanf("%d", &m);
        if (m == 1) {
            loading();
            system("cls");//화면 비우기
            easy();
            printf("초기화면으로 돌아가시려면 1을 누르세요... :");

            //초급 난이도 스도쿠 랜덤으로 뜨게 하기(종류는 한정적)
            scanf("%d", &chogihwa);
            if (chogihwa == 1) {
                system("cls");
                goto HAHA;

            }
            else {

            }
        }
        else if (m == 2) {
            system("cls");
            goto HAHA;//난이도 잘못 고른 경우 처음으로 돌아가기
        }

    }
    else if (n == 2) {
        printf("중급 난이도로 하시겠습니까?\n");
        printf("Yes = 1입력 / NO = 2입력\n");
        scanf("%d", &m);
        if (m == 1) {
            loading();//로딩중 표시 띄우기
            system("cls");
            medium();
            printf("초기화면으로 돌아가시려면 1을 누르세요... :");
            scanf("%d", &chogihwa);
            if (chogihwa == 1) {
                system("cls");
                goto HAHA;
            }
            else {

            }
        }
        else if (m == 2) {
            system("cls");
            goto HAHA;
        }

    }
    if (n == 3) {
        printf("고수 난이도로 하시겠습니까?\n");
        printf("Yes = 1입력 / NO = 2입력\n");
        scanf("%d", &m);
        if (m == 1) {
            loading();
            system("cls");
            hard();
            printf("초기화면으로 돌아가시려면 1을 누르세요... :");
            scanf("%d", &chogihwa);
            if (chogihwa == 1) {
                system("cls");
                goto HAHA;
            }
            else {

            }
        }
        else if (m == 2) {
            system("cls");
            goto HAHA;
        }

    }

    return 0;
}

void easy() {
    printmunjea();
    int wrongNum = 0;//정답과 비교해서 틀린 갯수
    int easyOne[9][9] = { {0,0,0,3,0,2,5,1,0},{0,2,0,0,1,0,0,0,4},{0,0,7,0,0,6,0,0,8},{1,0,0,9,0,0,4,0,6},{0,3,0,0,4,0,0,2,0},{5,0,9,0,0,7,0,0,3},{6,0,0,1,0,0,8,0,0},{7,0,0,0,2,0,0,3,0},{0,8,4,6,0,5,0,0,0} };
    int easyOne2[9][9] = { {4,6,8,3,9,2,5,1,7},{9,2,8,7,1,8,3,6,4},{3,1,7,4,5,6,2,9,8},{1,7,2,9,8,3,4,5,6},{8,3,6,5,4,1,7,2,9},{5,4,9,2,6,7,1,8,3}, {6,5,3,1,7,9,8,4,2},{7,9,1,8,2,4,6,3,5},{2,8,4,6,3,5,9,7,1} };
    int easyTwo[9][9] = { {6,1,0,0,0,5,4,0,3},{3,7,0,0,0,4,5,0,0},{0,0,4,7,0,0,0,1,6},{0,0,6,1,0,3,0,9,8},{0,0,0,0,0,0,0,0,0},{9,5,0,2,0,7,6,0,0},{4,8,0,0,0,1,3,0,0},{0,0,5,3,0,0,0,4,9},{7,0,3,8,0,0,0,5,1} };
    int easyTwo2[9][9] = { {6,1,8,9,2,5,4,7,3},{3,7,9,6,1,4,5,8,2},{5,2,4,7,3,8,9,1,6},{2,4,6,1,5,3,7,9,8},{8,3,7,4,6,9,1,2,5},{9,5,1,2,8,7,6,3,4},{4,8,2,5,9,1,3,6,7},{1,6,5,3,7,2,8,4,9},{7,9,3,8,4,6,2,5,1} };
    int easyThree[9][9] = { {0,0,2,0,0,0,5,0,0},{0,8,0,6,0,3,0,1,0},{6,0,0,0,5,0,0,0,8},{0,1,0,2,0,4,0,3,0},{0,0,4,0,0,0,8,0,0},{0,3,0,8,0,1,0,7,0},{7,0,0,0,1,0,0,0,4},{0,2,0,7,0,5,0,6,0},{0,0,3,0,0,0,2,0,0} };
    int easyThree2[9][9] = { {3,9,2,1,7,8,5,4,6},{4,8,5,6,2,3,7,1,9},{6,7,1,4,5,9,3,2,8},{8,1,7,2,9,4,6,3,5},{2,6,4,5,3,7,8,9,1},{5,3,9,8,6,1,4,7,2},{7,5,6,3,1,2,9,8,4},{9,2,8,7,4,5,1,6,3},{1,4,3,9,8,6,2,5,7} };
    //easyOne=문제 /// easyOne2=답
    system("cls");
    printf("문제 시작!!\n");
    Sleep(1000);
    system("cls");
    int random = 0;//81,82줄 -> 스도쿠 초보자 문제가 세 개 있기 때문에 이 중에 하나 랜덤 생성
    random = rand() % 3 + 1;
    if (random == 1) {
        int scan;//1을 눌러 정답입력창으로 이동///////////////////////////////////////////////////////////////////////
    random1:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", easyOne[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &easyOne[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (easyOne[i][j] != easyOne2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();

            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }

            }
        }
    }
    if (random == 2) {
        int scan;//1을 눌러 정답입력창으로 이동
    random2:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", easyTwo[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &easyTwo[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (easyTwo[i][j] != easyTwo2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1, easyTwo[i][j]);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }

            }
        }
    }
    if (random == 3) {
        int scan;//1을 눌러 정답입력창으로 이동
    random3:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", easyThree[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &easyThree[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (easyThree[i][j] != easyThree2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1, easyOne[i][j]);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }

            }
        }
    }
}


void medium() {
    printmunjea();
    int wrongNum = 0;//정답과 비교해서 틀린 갯수
    int mediumOne[9][9] = { {9,0,0,2,1,0,0,7,0 }, { 0,8,0,0,0,0,1,0,4 }, { 0,0,3,0,0,9,0,2,0 }, { 1,0,0,0,8,0,4,0,0 }, { 7,0,0,4,0,3,0,0,6 }, {0,0,8,0,7,0,0,0,9},{0,6,0,1,0,0,3,0,0},{5,0,2,0,0,0,0,8,0},{0,4,0,0,9,2,0,0,5} };
    int mediumOne2[9][9] = { {9,5,4,2,1,8,6,7,3},{2,8,7,5,3,6,1,9,4},{6,1,3,7,4,9,5,2,8},{1,2,6,9,8,5,4,3,7},{7,9,5,4,2,3,8,1,6},{4,3,8,6,7,1,2,5,9},{8,6,9,1,5,7,3,4,2},{5,7,2,3,6,4,9,8,1},{3,4,1,8,9,2,7,6,5} };
    int mediumTwo[9][9] = { {9,0,0,0,4,8,6,7,0},{0,1,0,0,0,0,0,0,0},{0,3,0,5,0,0,0,4,2},{0,5,0,6,0,0,7,0,0},{6,0,0,2,0,3,0,0,5},{0,0,1,0,0,9,0,2,0},{2,8,0,0,0,5,0,3,0},{0,0,0,0,0,0,0,5,0},{0,9,4,3,1,0,0,0,8} };
    int mediumTwo2[9][9] = { {9,2,5,1,4,8,6,7,3},{4,1,6,7,3,2,5,8,9},{7,3,8,5,9,6,1,4,2},{3,5,2,6,8,1,7,9,4},{6,4,9,2,7,3,8,1,5},{8,7,1,4,5,9,3,2,6},{2,8,7,9,6,5,4,3,1},{1,6,3,8,2,4,9,5,7},{5,9,4,3,1,7,2,6,8} };
    int mediumThree[9][9] = { {0,0,2,6,0,4,1,0,0},{0,1,0,0,0,0,0,2,0},{4,0,6,0,5,0,7,0,3},{1,0,0,2,0,8,0,0,5},{0,0,3,0,6,0,9,0,0},{2,0,0,3,0,1,0,0,4},{6,0,4,0,1,0,2,0,7},{0,7,0,0,0,0,0,3,0},{0,0,8,9,0,3,6,0,0} };
    int mediumThree2[9][9] = { {7,8,2,6,3,4,1,4,2},{3,1,5,7,8,9,9,2,1},{4,9,6,1,5,2,7,8,3},{1,6,9,2,4,8,3,7,5},{8,4,3,5,6,7,9,1,2},{2,5,7,3,9,1,8,6,4},{6,3,4,8,1,5,2,9,7},{9,7,1,4,2,6,5,3,8},{5,2,8,9,7,3,6,4,1} };
    //mediumOne=문제 /// mediumOne2=답
    system("cls");
    printf("문제 시작!!\n");
    Sleep(1000);
    system("cls");
    int random = 0;//81,82줄 -> 스도쿠 초보자 문제가 세 개 있기 때문에 이 중에 하나 랜덤 생성
    random = rand() % 3 + 1;
    if (random == 1) {
        int scan;//1을 눌러 정답입력창으로 이동///////////////////////////////////////////////////////////////////////
    random1:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", mediumOne[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &mediumOne[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (mediumOne[i][j] != mediumOne2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }

            }
        }
    }
    if (random == 2) {
        int scan;//1을 눌러 정답입력창으로 이동
    random2:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", mediumTwo[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &mediumTwo[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (mediumTwo[i][j] != mediumTwo2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }
            }
        }
    }
    if (random == 3) {
        int scan;//1을 눌러 정답입력창으로 이동
    random3:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", mediumThree[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &mediumThree[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (mediumThree[i][j] != mediumThree2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(800);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }
            }
        }
    }
}


void hard() {
    printmunjea();
    int wrongNum = 0;//정답과 비교해서 틀린 갯수
    int hardOne[9][9] = { {5,3,0,0,8,0,0,2,1},{6,0,0,0,0,0,0,0,4},{0,0,2,6,0,4,9,0,0},{0,0,8,0,0,0,7,0,0},{7,0,0,0,9,0,0,0,2},{0,0,3,0,0,0,8,0,0},{0,0,7,9,0,3,2,0,0},{3,0,0,0,0,0,0,0,9},{8,9,0,0,6,0,0,4,5} };
    int hardOne2[9][9] = { {5,3,4,7,8,9,6,2,1},{6,7,9,1,3,2,5,8,4},{1,8,2,6,5,4,9,3,7},{9,1,8,4,2,6,7,5,3},{7,6,5,3,9,8,4,1,2},{2,4,3,5,7,1,8,9,6},{4,5,7,9,1,3,2,6,8},{3,2,6,8,4,5,1,7,9},{8,9,1,2,6,7,3,4,5} };
    int hardTwo[9][9] = { {0,3,0,0,0,5,0,0,0},{0,0,5,1,0,0,3,0,0},{8,0,0,0,4,0,0,6,0},{0,2,0,0,0,1,0,0,5},{0,0,3,0,8,0,1,0,0},{5,0,0,6,0,0,0,2,0},{0,6,0,0,3,0,0,0,9},{0,0,8,0,0,7,2,0,0},{0,0,0,9,0,0,0,3,0} };
    int hardTwo2[9][9] = { {7,3,6,8,2,5,9,4,1},{2,4,5,1,6,9,3,7,8},{8,1,9,7,4,3,5,6,2},{9,2,4,3,7,1,6,8,5},{6,7,3,5,8,2,1,9,4},{5,8,1,6,9,4,7,2,3},{1,6,7,2,3,8,4,5,9},{3,9,8,4,5,7,2,1,6},{4,5,2,9,1,6,8,3,7} };
    int hardThree[9][9] = { {0,0,2,4,0,0,0,0,0},{0,0,9,5,0,0,0,2,4},{0,0,0,0,0,3,0,5,6},{0,3,4,0,7,0,0,0,0},{0,2,7,0,0,0,4,6,0},{0,0,0,0,5,0,9,7,0},{2,8,0,7,0,0,0,0,0},{6,7,0,0,0,9,1,0,0},{0,0,0,0,0,8,2,0,0} };
    int hardThree2[9][9] = { {7,5,2,4,8,6,3,9,1},{3,6,9,5,1,7,8,2,4},{1,4,8,9,2,3,7,5,6},{9,3,4,6,7,2,5,1,8},{5,2,7,8,9,1,4,6,3},{8,1,6,3,5,4,9,7,2},{2,8,1,7,3,5,6,4,9},{6,7,3,2,4,9,1,8,5},{4,9,5,1,6,8,2,3,7} };
    //hardOne=문제 /// hardOne2=답
    system("cls");
    printf("문제 시작!!\n");
    Sleep(1000);
    system("cls");
    int random = 0;//81,82줄 -> 스도쿠 초보자 문제가 세 개 있기 때문에 이 중에 하나 랜덤 생성
    random = rand() % 3 + 1;
    if (random == 1) {
        int scan;//1을 눌러 정답입력창으로 이동///////////////////////////////////////////////////////////////////////
    random1:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", hardOne[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &hardOne[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (hardOne[i][j] != hardOne2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }
            }
        }
    }
    if (random == 2) {
        int scan;//1을 눌러 정답입력창으로 이동
    random2:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", hardTwo[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &hardTwo[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (hardTwo[i][j] != hardTwo2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }
            }
        }
    }
    if (random == 3) {
        int scan;//1을 눌러 정답입력창으로 이동
    random3:
        printf("0에 들어갈 수를 채워넣으세요\n정답을 입력하려면 1을 누르세요\n\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d  ", hardThree[i][j]);
            }
            printf("\n\n");
        }
        scanf("%d", &scan);
        if (scan == 1) {
            system("cls");
            printf("정답을 입력하세요(9X9)\n");
            for (int i = 0; i < 9; i++) {////여기부터
                for (int j = 0; j < 9; j++) {
                    scanf("%d", &hardThree[i][j]);
                }////여기까지 답 입력(모두 다 입력)
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (hardThree[i][j] != hardThree2[i][j]) {
                        wrongNum++;
                        printf("**%d번째 줄 %d번째 칸이 틀렸습니다**\n", i + 1, j + 1);
                        Sleep(500);
                    }
                }
            }
            if (wrongNum == 0) {
                system("cls");
                printf("모두 맞추셨습니다!!\n");
                good();
            }
            else {
                system("cls");
                printf("오답이 있으므로 즉시 종료합니다..");
                Sleep(1000);
                system("cls");
                for (int i = 1; i <= 100; i++) {
                    printf(" FAIL ");
                }

            }
        }
    }
}





void loading() {
    printf("로");
    Sleep(200);
    printf("딩");
    Sleep(200);
    printf("중");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(1500);
}



void printsdoku() {
    printf("★");
    Sleep(200);
    printf("☆");
    Sleep(200);
    printf("★");
    Sleep(200);
    printf("스");
    Sleep(200);
    printf("도");
    Sleep(200);
    printf("쿠");
    Sleep(200);
    printf("★");
    Sleep(200);
    printf("☆");
    Sleep(200);
    printf("★");
    printf("\n");
}

void printmunjea() {
    printf("문");
    Sleep(200);
    printf("제");
    Sleep(200);
    printf("를");
    Sleep(200);
    printf("생");
    Sleep(200);
    printf("성");
    Sleep(200);
    printf("중");
    Sleep(200);
    printf("입");
    Sleep(200);
    printf("니");
    Sleep(200);
    printf("다");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".\n");

}

void good() {
    printf("■■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■□□□□□□□□□■■\n");
    printf("■■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■■□□□□□□□□■■\n");
    printf("■■□□□□□□□□□□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□■■□□□□□□□■■\n");
    printf("■■□□□□□□□□□□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□■■□□□□□□■■\n");
    printf("■■□□□□□□□□□□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□■■□□□□□■■\n");
    printf("■■□□□□□□□□□□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□■■□□□□■■\n");
    printf("■■□□■■■■■■■□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□□■■□□□■■\n");
    printf("■■□□■■■■■■■□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□□■■□□□■■\n");
    printf("■■□□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□■■□□□□■■\n");
    printf("■■□□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□■■□□□□□■■\n");
    printf("■■□□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□■■□□□□□□■■\n");
    printf("■■□□□□□□□■■□□□□■■□□□□□□■■□□□□■■□□□□□□■■□□□□■■□■■□□□□□□□□□\n");
    printf("■■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■■□□□□□□□□■■\n");
    printf("■■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■■■■■■■■□□□□■■■□□□□□□□□□■■\n");
}