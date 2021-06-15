#include <stdio.h>
#include <stdlib.h>

void mibun(int n, int gaesu[]);
void jeokbun(int n, int gaesu[], int sangsu);
void printmibunshik(int n, int gaesu[]);
void printshik(int n, int gaesu[]);

int main()
{
    int n, k, choice, c;
    int gaesu[10] = { 0 };
    //차수 배열이 없는 이유 : 어차피 최고차항의 차수는 입력받고 입력받는 계수에 0이 포함돼 있으므로, 식의 차수는 연속적임. 그러므로 반복문에서 연속된 정수로 표현 가능.
    printf("*** 정말 대단한 미적분 대신해주는 프로그램 ***\n\n");

    printf("1.미분\n");
    printf("2.적분\n");
    printf("3.종료\n\n");
    printf("선택해 주십시오 : ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 3) //지정한 범위 내의 대답이 아니라면 다시 입력할 것을 요구
    {
        printf("범위 내에서 선택해 주십시오 : ");
        scanf("%d", &choice);
    }
    if (choice == 3)//'프로그램 종료'를 선택하면 종료
        exit(0);

    printf("식의 차수를 입력하십시오 : ");
    scanf("%d", &n);

    printf("식의 계수를 차례대로 입력하십시오(0을 포함합니다) :\n");
    for (int i = n; i >= 0; i--)
        scanf("%d", &gaesu[i]);//번거로운 과정 없이 배열에 값 즉시 집어넣기

    switch (choice)
    {
    case 1://미분의 경우
        printf("몇 번 미분하시겠습니까? : ");
        scanf("%d", &k);
        printf("\n");
        for (int i = 1; i <= k; i++) //제시받은 횟수만큼 반복문을 돌려 미분하고 그 결과 출력하기
        {
            mibun(n, gaesu);
            printf("%d번 미분 : ", i);
            printshik(n, gaesu);
            n--;//식의 최대 차수를 1 줄여 다음 미분 진행에 차질 없도록 함(함수들이 작동하는 방식이 최고차항의 차수에 영향을 받는다)
        }
        break;
    case 2://적분의 경우
        printf("정수로 적분되게 입력하십시오.\n");
        printf("몇 번 적분하시겠습니까? : ");
        scanf("%d", &k);
        for (int i = 1; i <= k; i++) //제시받은 횟수만큼 반복문을 돌려 적분하고 그 결과 출력하기
        {
            printf("\n적분 상수를 입력하십시오 : ");
            scanf("%d", &c);//정해지지 않은 적분상수를 입력받아 현재 적분의 결과나 다음 적분에 활용한다.
            n++;//식의 최대 차수를 1 늘려 최고차항을 적분해 나오는 항이 들어갈 공간을 만든다.
            jeokbun(n, gaesu, c);
            printf("%d번 적분 : ", i);
            printshik(n, gaesu);
        }
        break;
    }//3번의 경우 이미 앞에서 프로그램을 종료하는 코드를 넣어두었으므로 경우가 2가지이다.
    printf("\n");
    return 0;
}

void mibun(int n, int gaesu[])
{
    for (int i = 0; i <= n; i++)
    {
        gaesu[i] = gaesu[i + 1] * (i + 1);//i가 현재 다루는 항의 차수 - 1이기도 하므로 식을 미분하는 법에 따라 현재 계수에 i + 1을 곱해 준다.
        //미분을 1번 진행하고 나면 본래의 상수항은 사라지고, 식의 항의 계수가 1개 줄어드므로 윗줄과 같은 코드를 작성했다.
        gaesu[i + 1] = 0;//그다음 계산을 진행하기 위해 다음 계산 결과가 들어갈 배열의 자리를 비워 준다.
    }
}

void jeokbun(int n, int gaesu[], int sangsu)
{
    for (int i = n + 1; i > 0; i--)//i가 0부터 시작하지 않는 이유는 미분 함수와 동일하다. 하지만 n + 1인 이유는 적분을 하면 전체 식의 항의 개수가 1개 늘어나기 때문이다.
    {
        gaesu[i] = gaesu[i - 1] / i;//i가 현재 식의 차수를 나타내므로, 식을 적분하는 법에 맞추어 계산을 해 준다.
                                    //계산 과정 : 새로운 계수 = 이전의 계수 * (1 / 이전의 차수), 새로운 차수 = 이전의 차수 + 1
    }
    gaesu[0] = sangsu;//배열의 첫 부분, 그러니까 적분의 과정을 끝내면 비게 되는 상수항 부분은 위에서 입력받은 적분 상수를 대입해 준다.
}

void printshik(int n, int gaesu[])
{
    for (int i = n; i >= 0; i--) //식의 차수가 n차이므로, n + 1개의 항을 출력해야 한다. 여기서 i가 0이 아니라 n부터 시작하는 것은
                                 //현재 guesu 배열에 입력되어 있는 식이 원래의 식과 역순이기 때문이다.
    {
        if (gaesu[i] == 1 && i > 0)//만약 현재 다루는 배열의 위치에 저장된 값, 즉 계수가 0이고 i가 0보다 크다면(상수항이 아니라면) 계수 부분을 빼고 출력한다.
        {
            printf("X^%d + ", i);
        }
        else if (gaesu[i] != 0)//항의 계수가 0이 아니라면 다음을 수행한다.
        {
            printf("%d", gaesu[i]);//현재 계수를 출력하기 위해 배열에 들어 있는 값을 출력해 준다.
            if (i > 1)//i가 1보다 클 때, 즉 다음에 나오는 항이 상수항이 아닐 때에는 현재 차수를 i로써 출력해 준다.
            {
                printf("X^%d + ", i);
            }
            else if (i == 1)//만약 i = 1, 즉 다음에 나오는 항이 상수항일 때에는 X^1이라고 출력되지 않기 위해 다른 경우로 따로 취급해 준다.
            {
                printf("X + ");
            }
        }
    }
    printf("\n");
}