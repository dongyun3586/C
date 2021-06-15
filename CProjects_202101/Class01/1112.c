#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//Sleep, system
#define M 101

int digitnum(int n);//칸을 맞춰주기 위해 각 숫자의 자리수와 가장 큰 자리수를 갖는 수의 자리수를 구한다.
int magic_square(int a, int b, int n);//마방진을 채워넣는 부분
int magic_square_sum(int n);//가로.세로.대각선 합
void print_magic_square(int n);//마방진을 출력하는 부분

int main()
{
    int jin[M][M] = { 0 };//마방진을 만들 2차원 배열
    int num, banbok;

    printf("안녕하세요! 마방진을 만들어 드립니다.");
    Sleep(2000);//1000=1초, 2초 기다림
    printf("\n마방진은 가로, 세로, 대각선의 합이 같아지도록 정사각형 모양으로 배열한 것 입니다.\n");
    Sleep(3000);
    system("cls");//clear
    printf("몇개의 마방진을 만들까요? ");//반복
    scanf("%d", &banbok);
    system("cls");//clear

    printf("n*n마방진을 만들어 드립니다.\n");
    for (int i = 1; i <= banbok; i++)
    {
        printf("\n41이하의 홀수를 입력해 주세요.");//더 할수는 있지만 줄을 넘어가고, 100 이상으로 넘어가면 오버플로우가 생길 수 있다.
        scanf("%d", &num);
        while (num % 2 == 0 || num > 41)
        {
            printf("41이하의 홀수로 다시 입력해 주세요.");
            scanf("%d", &num);
        }

        printf("\n<%d번 마방진> %d*%d\n", i, num, num);
        printf("가로.세로 대각선 합 = %d\n\n", magic_square_sum(num));
        print_magic_square(num);//마방진 출력
        Sleep(1000);//1초 기다림
    }
    return 0;
}

//마방진을 채워넣는 부분
int magic_square(int x, int y, int n)
{
    int jin[M][M] = { 0 };//마방진을 만들 2차원 배열
    int a = 1, b = (n + 1) / 2; //시작지점 a->1행 b->가운데 열
    for (int i = 1; i <= n * n; i++)
    {
        jin[a][b] = i;//배열에 수를 채워 넣음

        a--;//상단으로 이동
        b++;//우측로 이동

        //행이 벗어났을 때
        if (a == 0)

        {
            a = n;//n행으로 옮김
        }

        //열이 벗어났을 때
        if (b == n + 1)
        {
            b = 1;//1열로 옮김
        }

        //행과 열이 모두 넘어갔을 때
        if (a == n && b == 1)
        {
            //1행 n열에서 우측 상단으로 이동하게 되면 행과 열이 모두 넘어감
            //n행 1열로 옮기면 이미 숫자가 채워져 있음
            //이를 모두 고려하여 코드를 짜기 어렵기 때문에 이 경우를 따로 빼서 생각함

            //1행 n열에서 넘어갔지만 n행 1열일때를 고려하는 이유=위의 if문에서 n행 1열이 되었기 때문
            //원래의 n행 1열일 때는 비워져있지 않아 아래로 이동하여 채워지는 경우이기에 아래의 if문에서 옮겨짐
            //따라서 이 if문에서는 영향을 받지 않음
            a = 2;
            b = n;
        }

        //칸이 비어있지 않을 때
        if (jin[a][b] != 0)
        {
            //우측 대각선으로 이동한 뒤에 원래의 위치보다 한 행 아래인 지점으로 이동
            //따라서 행만 1 더하는 것이 아니라 행은 2 더하고 열은 1 빼야함
            a += 2;
            b -= 1;
        }
    }
    return jin[x][y];//마방진 반환
}

//칸을 맞춰주기 위해 각 숫자의 자리수와 가장 큰 자리수를 갖는 수의 자리수를 구함
int digitnum(int n)
{
    int result = 0;

    while (n >= 1)
    {
        n /= 10;
        result++;
    }

    return result;//자리수 반환
}

//가로.세로.대각선 합
int magic_square_sum(int n)
{
    int result = 0;

    for (int i = 1; i <= n * n; i++)
    {
        result += i;
    }
    result /= n;

    return result;
}

//마방진을 출력하는 부분
void print_magic_square(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", magic_square(i, j, n));//숫자 출력

            //가장 큰 자리를 갖는 수와 칸수를 맞춰줌
            //따라서 빈칸의 개수 = 최대자리수-수의 자리수
            for (int k = 1; k <= digitnum(n * n) - digitnum(magic_square(i, j, n)); k++)
            {
                printf(" ");
            }
        }
        printf("\n\n");
    }
    printf("\n");
}
