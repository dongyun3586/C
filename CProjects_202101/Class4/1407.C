#include<stdio.h>
#include<stdlib.h>
#include<time.h>
vseprr(a, b)
{

    printf("VSEPR theory \n");
    printf(" 모양에서 비공유 전자쌍은 생략했습니다\n");
    while (1)
    {
        printf("SN수가 얼마인가요? : ");
        scanf("%d", &a);
        if (a < 2)
            printf("SN 수는 항상 2 이상입니다. \n");


        else if (a == 2)
        {
            printf("비공유 전자쌍이 몇개 입니까? : ");
            scanf("%d", &b);
            if (b != 0)
            {
                printf("그런 모형은 없습니다.\n"); return 0;
            }
            else
            {
                printf("선형입니다.\n\n ");
                printf("***  ***  ***\n"); printf(" *************\n"); printf(" ***  ***  ***\n"); return 1;
            }

        }
        else if (a == 3)
        {
            printf("비공유 전자쌍이 몇개 입니까? : ");
            scanf("%d", &b);
            if (b == 0)
            {
                printf("평면 삼각형 입니다.\n\n"); printf("    ***\n"); printf("    ***\n"); printf("     *\n"); printf("    ***\n"); printf("    ***\n"); printf(" ***   ***\n"); printf(" ***   ***\n");
                return 3;
            }
            else if (b == 1)
            {
                printf("굽은형입니다.\n\n"); printf("    ***\n"); printf("    ***\n"); printf(" ***   ***\n"); printf(" ***   ***\n");
                return 2;
            }
            else if (b > 1)
                printf("그런 모형은 없습니다.\n"); return 0;
        }
        else if (a == 4)
        {
            printf("비공유 전자쌍이 몇개 입니까? : ");
            scanf("%d", &b);
            if (b == 0)
            {
                printf("입체 도형인 사면체 형입니다.\n\n"); printf("     ***\n"); printf("     ***\n"); printf("      *\n"); printf("     ***\n"); printf("     ***\n"); printf(" ************\n");
                printf(" ***  *   ***\n"); printf(" *** ***  ***\n"); printf("     ***\n");
                return 4;
            }
            else if (b == 1)
            {
                printf("삼각 피라미드 형입니다.\n\n");
                printf("     ***\n"); printf("     ***\n"); printf(" ************\n");
                printf(" ***  *   ***\n"); printf(" *** ***  ***\n"); printf("     ***\n");
                return 5;
            }
            else if (b == 2)
            {
                printf("굽은형입니다.\n\n"); printf("    ***\n"); printf("    ***\n"); printf(" ***   ***\n"); printf(" ***   ***\n");
                return 2;
            }
            else if (b > 2)
                printf("그런 모형은 없습니다.\n"); return 0;
        }
        else if (a == 5)
        {
            printf("비공유 전자쌍이 몇개 입니까? : ");
            scanf("%d", &b);
            if (b == 0)
            {
                printf("삼각쌍뿔형입니다.\n\n"); printf("      ***\n"); printf("      ***\n"); printf("       *\n"); printf("       *  ***\n"); printf("      *******\n"); printf(" *** ****\n");
                printf(" *** *********\n"); printf("       *   ***\n"); printf("       *\n"); printf("      ***\n"); printf("      ***\n");
                return 6;
            }
            else if (b == 1)
            {
                printf("시소형입니다\n\n"); printf("      ***\n"); printf("      ***\n"); printf("       *\n"); printf("       *  ***\n"); printf("      *******\n"); printf("     ****\n");
                printf("     *********\n"); printf("       *   ***\n"); printf("       *\n"); printf("      ***\n"); printf("      ***\n");
                return 8;
            }
            else if (b == 2)
            {
                printf("T-자형입니다.\n\n");
                printf("      ***\n"); printf("      ***\n"); printf("       *\n"); printf("       *     \n"); printf(" *** ****    \n"); printf(" ********\n");
                printf(" *** ****     \n"); printf("       *      \n"); printf("       *\n"); printf("      ***\n"); printf("      ***\n");
                return 7;
            }
            else if (b == 3)
            {
                printf("선형입니다.\n\n");
                printf("      ***\n"); printf("      ***\n"); printf("       *\n"); printf("       *     \n"); printf("     ****    \n"); printf("     ****\n");
                printf("     ****     \n"); printf("       *      \n"); printf("       *\n"); printf("      ***\n"); printf("      ***\n");
                return 1;
            }
            else if (b > 3)
                printf("그런 모형은 없습니다.\n"); return 0;
        }
        else if (a == 6)
        {
            printf("비공유 전자쌍이 몇개 입니까? : ");
            scanf("%d", &b);
            if (b == 0)
            {
                printf("팔면체형입니다.\n\n"); printf("     ***\n"); printf("     ***\n"); printf("     ***\n"); printf("      *\n"); printf(" ***  *\n"); printf(" ***  *   ***\n"); printf("   ****** ***\n");
                printf("     ****\n"); printf("**** **** ***\n"); printf("***   *   ***\n"); printf("      *\n"); printf("      *\n"); printf("     ***\n"); printf("     ***\n"); printf("     ***\n");
                return 9;
            }
            else if (b == 1)
            {
                printf("사각뿔형입니다.\n\n");
                printf("     ***\n"); printf("     ***\n"); printf("     ***\n"); printf("      *\n"); printf(" ***  *\n"); printf(" ***  *   ***\n"); printf("   ****** ***\n");
                printf("     ****\n"); printf("**** **** ***\n"); printf("***       ***\n");
                return 10;
            }
            else if (b == 2)
            {
                printf("평면사각형입니다.\n\n");
                printf(" ***   \n"); printf(" ***      ***\n"); printf("   ****** ***\n");
                printf("     ****\n"); printf("**** **** ***\n"); printf("***       ***\n");
                return 11;
            }
            else if (b == 3)
            {
                printf("T-자형입니다.\n\n");
                printf("      ***\n"); printf("      ***\n"); printf("       *\n"); printf("       *     \n"); printf(" *** ****    \n"); printf(" ********\n");
                printf(" *** ****     \n"); printf("       *      \n"); printf("       *\n"); printf("      ***\n"); printf("      ***\n");
                return 7;
            }
            else if (b == 4)
            {
                printf("선형입니다.\n\n"); printf("   ***\n"); printf("   ***\n"); printf("   ***\n"); printf("    *\n"); printf("    *\n"); printf("    *\n"); printf("   ***\n"); printf("   ***\n");
                printf("   ***\n"); printf("    *\n"); printf("    *\n"); printf("    *\n"); printf("   ***\n"); printf("   ***\n"); printf("   ***\n");
                return 1;
            }
            else if (b > 4)
                printf("그런 모형은 없습니다.\n"); return 0;
        }
        else
            printf("SN 수가 7 이상이면 자연상태에서 거의 존재하지 않으므로 배제합니다.\n");
    }

}
int main()
{
    while (1)
    {
        printf("끝내고 싶으면 오른쪽 상단의 X를 누르세요 \n \n ");
        int n;
        printf("무얼 보겠습니까\n  1 : 모형  \n  2: 시험   ");
        scanf("%d", &n);
        if (n == 2)
        {
            int a, b, c, cnt = 0;
            printf("\n시험을 시작합시다.");
            printf("\n 몇 문제를 원하시나요?:");
            scanf("%d", &a);
            srand(time(NULL));

            printf("0: 없습니다 \n   1; 선형     \n   2: 굽은형   \n   3: 평면 삼각형 형     \n   4: 사면체 형  \n   5: 삼각뿔 형   \n  6: 삼각쌍뿔 형  \n   7: T 자형   \n 8:  시소형   \n    9: 팔면체 형    \n    10:   사각뿔 형    \n    11:평면 사각형 형 \n   ");
            for (int i = 1; i <= a; i++)
            {
                b = rand() % 5 + 2; c = b - (rand() % b + 1);
                int d;
                printf("\n비공유 전자쌍의 개수: %d \n SN수: %d  일때, 모형의 이름을 맞추시오\n", c, b);
                printf("\n 정답?: ");
                scanf("%d", &d);
                printf("\n 직접 답을 입력해서 확인 해 보세요 \n \n");
                if (vseprr(b, c) == d)
                {
                    printf("\n 정답! \n ");
                    cnt = cnt + 1;
                }
                else
                {
                    printf("\n 아니요  ");

                }




            }
            int f = (cnt / a) * 100;
            printf("정답률 = %d %", f);
        }

        else if (n == 1)
        {
            int a, b;
            while (1)
            {
                vseprr();
                printf(" \n\n 1: 계속 본다\n 2: 그만본다 ");
                printf("\n\n 더 보시겠습니까?:");
                scanf("%d", &a);
                if (a == 1)
                    continue;
                else
                    break;
            }

        }
    } return 0;
}
