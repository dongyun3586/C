#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void MainScreen();         //시작화면을 출력해줌
void GamePlay(int size);         //게임 화면을 출력해줌
void HowToPlay();            //게임방법을 출력해줌
void GameOver(int time, int size);            //게임오버창을 출력해줌
void Dig(int** minefield, int y, int x, int size);         //땅을 팠을 때 숫자가 0이면 근처의 땅을 파주는 함수

int main() {
    int size;      //지뢰밭의 한변의 길이

    MainScreen();      //메인화면 출력

    printf("지뢰밭의 한변의 길이는? : ");
    scanf("%d", &size);

    while (size < 10 || size >= 50) {
        system("cls");
        printf("다시 입력해 주세요, 지뢰밭의 한변의 길이는 10보다 크거나 50보다 작아야 됩니다.\n");
        scanf("%d", &size);
    }

    system("cls");

    GamePlay(size);      //게임화면으로 넘어가줌
}

void MainScreen() {         //메인화면
    printf("\n");
    printf("\n");
    printf("\n");
    printf("           지뢰찾기\n\n");
    printf("게임 시작 : enter\n");
    printf("게임 방법 : a");

    while (1) {
        if (getch() == 13) {         //엔터 누르면 MainScreen함수에서 나가서 게임화면으로 가줌
            system("cls");
            break;
        }
        else if (getch() == 97) {      //a누르면 게임방법 띄워줌
            system("cls");
            HowToPlay();
        }
    }
}

int** minefind;                             //전역변수로 드러난 땅의 위치를 저장해주기 위해 동적할당시켜줄 minefind를 지정해준다. 

void GamePlay(int size) {
    int** minefield;      //지뢰위치와 근처 지뢰개수 저장해줌

    minefield = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++)
        minefield[i] = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        memset(minefield[i], 0, sizeof(int) * size);

    for (int i = 0; i < size; i++) {        //지뢰밭으로 하얀색박스 출력해줌
        printf("%2d ", size - i);
        for (int j = 0; j < size; j++)
            printf("■");
        printf("\n");
    }

    printf("  ");
    for (int i = 0; i < size; i++)
        printf("%2d", i + 1);
    printf("\n");

    int mine;                     //지뢰위치 임시로 저장해줌
    srand(time(NULL));               //랜덤함수
    for (int i = 0; i < (size * size * 40) / 256; i++) {
        mine = rand() % (size * size);            //랜덤으로 위치 넣어줌

        if (minefield[mine / size][mine % size] == 1000)      //지뢰위치 중복안되게함
            i--;
        else
            minefield[mine / size][mine % size] = 1000;         //minefield 지뢰위치에 1000넣어줌
    }

    for (int i = 0; i < size; i++) {                  //근처 지뢰 개수 minefield 이차원 배열에 넣어줌
        for (int j = 0; j < size; j++) {
            if (minefield[i][j] != 1000) {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < size && y >= 0 && y < size && minefield[x][y] == 1000) {
                            minefield[i][j]++;                        // 위,아래,대각선에 지뢰있으면 +1 해줌
                        }
                    }
                }
            }
        }
    }
    int x, y;            //파헤칠 땅 좌표 입력받음
    int time_taken, start_time, end_time;                           // 걸린 시간 저장해준다

    minefind = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        minefind[i] = (int*)malloc(sizeof(int) * size);
        memset(minefind[i], 0, sizeof(int) * size);      //minefind 0으로 초기화
    }

    scanf("%d %d", &x, &y);  //파헤질 땅의 좌표 입력받음

    while (x <= 0 || x > size || y > size || y <= 0)
    {
        scanf("%d %d", &x, &y);
    }

    start_time = time(NULL);            //시작한 시간저장

    while (1) {
        if (x > size || y > size || x <= 0 || y <= 0)
            continue;

        minefind[size - y][x - 1] = 1;            //파헤친 땅엔 1 넣어줌
        if (minefield[size - y][x - 1] == 0)
            Dig(minefield, size - y, x - 1, size);

        system("cls");

        for (int i = 0; i < size; i++) {          //지뢰밭을 출력해준다.
            printf("%2d ", size - i);
            for (int j = 0; j < size; j++)
                if (minefind[i][j] == 1)
                    printf("%2d", minefield[i][j]);
                else
                    printf("■");
            printf("\n");
        }
        printf("   ");
        for (int i = 0; i < size; i++)
            printf("%2d", i + 1);
        printf("\n");

        if (minefield[size - y][x - 1] == 1000) {                  //지뢰를 밟는다면...
            system("cls");
            for (int i = 0; i < size; i++) {                       //모든 지뢰의 위치를 드러내준다
                for (int j = 0; j < size; j++)
                    if (minefield[i][j] == 1000)
                        printf(" *");
                    else if (minefind[i][j] == 1)
                        printf("%2d", minefield[i][j]);
                    else
                        printf("■");
                printf("\n");
            }
            GameOver(1, size);                        //게임패배를 띄워줌
            break;                              //나가기
        }

        int k = 1;            //게임 승리 여부를 저장해줌

        for (int i = 0; i < size; i++) {                         //만약 지뢰가 아닌 칸이 모두 열렸는지 확인
            for (int j = 0; j < size; j++) {
                if (minefield[i][j] != 1000 && minefind[i][j] == 0)
                    k = 0;              //지뢰가 들어있지 않고 열리지 않은 칸이 있으면 k에 0 넣어줌
            }
        }

        if (k == 1) {                    //k에 1이 들어있다면 게임 승리
            end_time = time(NULL);          //끝낸시간 저장
            time_taken = end_time - start_time;         //끝낸시간에서 시작시간을 빼줘서 걸린시간을 구해준다.
            GameOver(time_taken, size);             //게임 승리하도록 한다                    
            break;
        }
        scanf("%d %d", &x, &y);  //파헤질 땅의 좌표 입력받음

        while (x <= 0 || x > size || y > size || y <= 0)
        {
            scanf("%d %d", &x, &y);
        }
    }
}

void HowToPlay() {                       //게임방법
    printf("1. 게임 시작을 하면 지뢰밭의 한변의 길이를 입력해준다.\n");
    printf("2. 입력받은 크기의 지뢰밭을 출력해주고 각 흰색 블럭의 위치를 입력하기 쉽게 xy좌표축도 함께 출력해주다. 가로축이 y축이고 세로축이 x축이다.\n");
    printf("3. 파헤칠 땅의 좌표를 입력해주고(x좌표 y좌표) 그 위치의 땅을 파헤쳐준다.");
    printf("4. 입력받은 좌표의 땅이 열리면 위,아래,대각선에 위치하는 지뢰의 개수를 출력해준다.");
    printf("5. 지뢰를 밟으면 모든 지뢰의 위치를 드러내고 게임오버된다.");
    printf("6.지뢰가 들어있지 않은 모든 땅을 드러내게 된다면 게임을 승리하고 걸린 시간을 출력해준다,\n");
    printf("돌아가려면 space바");

    while (1)
        if (getch() == ' ')         //스페이스바 누르면 돌아감
            break;

    system("cls");
    MainScreen();
}

void GameOver(int time, int size) {
    if (time == 1)
        printf("게임 패배\n");
    else
        printf(" 게임 승리!, 걸린 시간 %d분 %d초", time / 60, time % 60);             //걸린 시간을 출력해준다.
}

void Dig(int** minefield, int y, int x, int size) {                  //입력받은 위치의 minefield에 저장된 값이 0이라면 근처의 땅을 모두 파헤쳐준다.
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (y + i >= 0 && y + i < size && x + j >= 0 && x + j < size) {
                if (minefind[y + i][x + j] == 0) {  // 파헤진 땅이 아닌경우만
                    minefind[y + i][x + j] = 1;                 // minefind에 파헤친 위치에 1을 넣어줌

                    if (minefield[y + i][x + j] == 0)
                        Dig(minefield, y + i, x + j, size);
                }
            }
        }
    }
}