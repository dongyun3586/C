// *이 게임의 아이디어는 1209 염예찬이 고안한게 절대 아니라는 것을 밝힙니다

#include <stdio.h> 
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define Tree_Bottom_Y 19 //장애물의 y축방향으로 최대 위치를 치환한다
#define Tree_Bottom_X 90 //장애물의 x축방향으로 최대 위치를 치환한다
#define Dino_Bottom_Y 12 //공룡의 y축방향으로 최대 위치를 치환한다

int getKey(void) { // 키가 눌렸음을 감지했을때 어느 키가 눌렸는지 확인하는 함수이다
    int pressedkey = _getch();
    return pressedkey;
}

void SetConsole() { //콘솔창의 크기 및 콘솔창 상단에 뜨는 프로젝트 이름 설정
    system("mode con:cols=100 lines=25");
    system("title 1209염예찬 정보프로젝트");
}

void Clear(void) { //system("cls")를 매번 쓰기 귀찮아서 Clear()이라는 새로운 함수를 만들어서 사용한다
    system("cls");
}

void CursorView(char show) { //캐럿을 없에기 위해 함수를 만들었다
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


void gotoxy(int x, int y) //콘솔창에서 특정 위치로 가기 위해 함수를 만들었다
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void printDino(int dinoY) { //공룡을 콘솔창에서 출력하는 함수이다

    gotoxy(0, dinoY);

    static int flag = 1; //공룡의 다리를 표현하기 위해 flag를 정의하고 0과 1을 번갈아가는 경우에서 공룡의 발을 출력합니다

    printf("        $$$$$$$ \n");
    printf("       $$ $$$$$$\n");
    printf("       $$$$$$$$$\n");
    printf("$      $$$      \n");
    printf("$$     $$$$$$$  \n");
    printf("$$$   $$$$$     \n");
    printf(" $$  $$$$$$$$$$ \n");
    printf(" $$$$$$$$$$$    \n");
    printf("  $$$$$$$$$$    \n");
    printf("    $$$$$$$$    \n");
    printf("     $$$$$$     \n");
    if (flag)
    {
        printf("     $    $$$    \n");
        printf("     $$          ");
        flag = 0;
    }
    else
    {
        printf("     $$$  $     \n");
        printf("          $$    ");
        flag = 1;
    }

}

void printJumpingDino(int dinoY) { //공룡을 콘솔창에서 출력하는 함수이다

    gotoxy(0, dinoY);

    printf("        $$$$$$$ \n");
    printf("       $$ $$$$$$\n");
    printf("       $$$$$$$$$\n");
    printf("$      $$$      \n");
    printf("$$     $$$$$$$  \n");
    printf("$$$   $$$$$     \n");
    printf(" $$  $$$$$$$$$$ \n");
    printf(" $$$$$$$$$$$    \n");
    printf("  $$$$$$$$$$    \n");
    printf("    $$$$$$$$    \n");
    printf("     $$$$$$     \n");
    printf("     $    $$$    \n");
    printf("     $$          ");
}

void printTreeType1(int treex) { //첫번째 타입의 함수를 출력하는 함수입니다
    gotoxy(treex, Tree_Bottom_Y);
    printf("    $$$$");
    gotoxy(treex, Tree_Bottom_Y + 1);
    printf("$$$  $$");
    gotoxy(treex, Tree_Bottom_Y + 2);
    printf(" $   $$  $$$");
    gotoxy(treex, Tree_Bottom_Y + 3);
    printf(" $   $$   $");
    gotoxy(treex, Tree_Bottom_Y + 4);
    printf(" $   $$   $");
    gotoxy(treex, Tree_Bottom_Y + 5);
    printf(" $   $$   $");
}

void printTreeType2(int treex) { //2번째 타입의 장애물을 출력하는 함수입니다
    gotoxy(treex, Tree_Bottom_Y);
    printf("$$$$");
    gotoxy(treex, Tree_Bottom_Y + 1);
    printf(" $$");
    gotoxy(treex, Tree_Bottom_Y + 2);
    printf(" $$");
    gotoxy(treex, Tree_Bottom_Y + 3);
    printf(" $$");
    gotoxy(treex, Tree_Bottom_Y + 4);
    printf(" $$");
    gotoxy(treex, Tree_Bottom_Y + 5);
    printf(" $$");
}

void printTreeType3(int treex) { //3번째 타입의 장애물을 출력하는 함수입니다
    gotoxy(treex, Tree_Bottom_Y);
    printf("  $$$$$");
    gotoxy(treex, Tree_Bottom_Y + 1);
    printf("  $$$$$");
    gotoxy(treex, Tree_Bottom_Y + 2);
    printf("  $$$$$$");
    gotoxy(treex, Tree_Bottom_Y + 3);
    printf(" $$$$$$$");
    gotoxy(treex, Tree_Bottom_Y + 4);
    printf("$$$$$$$$");
    gotoxy(treex, Tree_Bottom_Y + 5);
    printf("$$$$$$$$");
}


int main(void) {


    CursorView(0); //캐럿이 안보이게 CursorView함수에 0을 넣어줬다
    srand(time(NULL)); //제대로 된 난수 생성을 위해 만들어줬다

    SetConsole();
    printf("\n\n\n\n\n\n\t\t\t\t------- z를 눌러 시작하세요 -------\n\n\t\t\t\t\t   점프하기: z");
    while (1) {

        if (_getch() == 'z') { //z를 누르면 시작하게 되어있음
            break;
        }

    }
    Clear();

START:  //게임이 끝나고 x키를 눌렀을 때 이쪽으로 다시 오게 만든다


    int treex = Tree_Bottom_X; //장애물의 x축상에서 위치를 추적하기 위해 만든 변수니다
    int dinoy = Dino_Bottom_Y; //장애물의 y축상에서 위치를 추적하기 위해 만든 변수이다
    int treeTypeRNG = 1; //장애물의 종류를 랜덤으로 정하는 함수이다



    int isatBottom = 1;
    int treeSpeed = 3; //나무가 움직이는 초기 속도를 지정해준다
    int score = 0;


    while (1) { //게임 플레이어가 원할때 까지 게임을 종료시키지 않기 위해 무한 while문을 사용한다

        printf("점수: %d", score);

        if (_kbhit()) { //키를 눌렀는지 확인하고, z키를 눌렀을때 "점프 상태"를 활성해준다
            if (getKey() == 'z') {
                isatBottom = 0;
                score++;
                if (score % 5 == 0) {
                    treeSpeed += 1;
                }
            }
        }

        if (dinoy <= 12 && treex <= treeSpeed) { //만약 나무가 공룡쪽으로 가까이 다가가고 공룡이 점프를 하지 않아 y값이 작다면 충돌한다고 처리해준다
            system("cls");

            //게임 종료 화면을 띄운다

            printf("\n\n\n\n\n\n\t\t\t\t\t최종 점수: %d", score);
            printf("\n\n\n\n\t\t\t\t     종료: z   다시하기 x");
            while (1) {
                if (_getch() == 'z') { //z를 누르면 게임이 끝난다
                    return 0;
                }
                else if (_getch() == 'x') {
                    goto START; //x를 누르면 START으로 이동, 게임을 시작하기 전으로 다시 간다
                }
            }
            break;


        }

        if (isatBottom == 1) { //공룡이 바닥상태(z키를 누르지 않은 상태)일 경우

            printDino(dinoy); //일단 공룡을 출력해준다

            if (treeTypeRNG == 1) { // treeTypeRNG가 1일때 나무 1타입을 출력하고, 2일때 나무 2타입을 출력하고, 3일때 나무 3타입을 출력한다
                printTreeType1(treex);
            }
            else if (treeTypeRNG == 2) {
                printTreeType2(treex);
            }
            else if (treeTypeRNG == 3) {
                printTreeType3(treex);
            }

            treex -= treeSpeed; //나무의 진행속도만큼 treex에 할당되어있는 값을 감소해줌으로서 gotoxy에서 x값을 감소기키고 점점 공룡쪽으로 가까이 오게 한다
            if (treex <= 0) { //treex가 0 이하이면 콘솔창에 나오지 않기때문에 그냥 treex 변수를 초기화해준다
                treex = Tree_Bottom_X;
                treeTypeRNG = rand() % 3 + 1; //나무의 종료인 treeTypeRNG를 다시 생성해서 장애물의 타입을 바꿔준다
                Sleep(treeSpeed * 10 + 10); //treeSpeed가 계속 커지면 나무가 다가오는 속도가 점점 빨라져서 무조건 충돌하기 때문에 나무가 사라질때마다 조금의 쉬는시간을 준다
            }

            Sleep(80);
            Clear();
        }


        else if (isatBottom == 0) { //공룡이 점프하는 상황
            for (int i = 1; i <= 6; i++) { //공룡이 점프하기 때문에 gotoxy에서 y값을 변화시켜주면서 올라가게한다
                printJumpingDino(dinoy - i);

                if (treeTypeRNG == 1) {
                    printTreeType1(treex);
                }
                else if (treeTypeRNG == 2) {
                    printTreeType2(treex);
                }
                else if (treeTypeRNG == 3) {
                    printTreeType3(treex);
                }

                treex -= treeSpeed; //이부분도 위와 똑같이 나무를 출력해준다
                if (treex <= 0) {
                    treex = Tree_Bottom_X;
                    treeTypeRNG = rand() % 3 + 1;
                    Sleep(treeSpeed * 10 + 10);
                }

                Sleep(80); //한 상태를 출력한 뒤 그 화면을 지워버리고 다시 새로운 상황을 뽑아준다
                Clear();

            }
            for (int i = 5; i >= 1; i--) { //공룡이 내려갈 때 y값을 변화시켜주면서 내려가게한다
                printJumpingDino(dinoy - i);

                if (treeTypeRNG == 1) { //위에 장애물을 생성하고 공룡쪽으로 이동하는 코드와 동일하다
                    printTreeType1(treex);
                }
                else if (treeTypeRNG == 2) {
                    printTreeType2(treex);
                }
                else if (treeTypeRNG == 3) {
                    printTreeType3(treex);
                }

                treex -= treeSpeed;
                if (treex <= 0) {
                    treex = Tree_Bottom_X;
                    treeTypeRNG = rand() % 2 + 1;
                    Sleep(treeSpeed * 20 + 10);
                }

                Sleep(80);
                Clear();
            }

        }
        isatBottom = 1; //점프하는 동작을 완료한 후에 다시 바닥 상태에 있다고 정의해준다
    }


}