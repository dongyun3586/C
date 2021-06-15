#include<stdio.h>
#include<math.h>
int main()
{
    int k, count = 0, x, j;
    printf("시험공부 준비됫나요\n");
    printf("학년 반 번호를 적어주세요\n");
    printf("시작합니다");
    do {
        printf("과목을 입력해주세요 : 1.수학 2.물리 "); //과목 선택
        scanf("%d", &k);
        switch (k)//k의 값에 따라서 과목을 선택한다.
        {
        case 1:
            printf("수학");
            break;
        case 2:
            printf("물리");
            break;
        }
        if (k == 1)//수학을 고른경우
        {
            for (int i = 0; i < 3; i++)//한 과목에서 3문제씩 내어야 한다.
            {
                scanf("%d", &x);
                switch (x)//입력한 문제 번호에 따라서 출제되어있는 문제를 출력하여 준다.
                {
                case 1://1번 문제
                    printf("x^2-y^2=1의 방정식을 가지는 쌍곡선의 초점의 좌표는 ? : 1.(2.0) 2.(sqrt(2),0) 3.(sqrt(3),0) 4,(12,10)");
                    scanf("%d", &j);
                    if (j == 2)//정답인경우
                    {
                        count++;
                        printf("정답입니다!");
                    }
                    else//오답인경우
                    {
                        printf("오답입니다. 정답은 2번입니다.");
                    }
                    break;//다음 문제로 넘어간다.
                case 2://2번문제
                    printf("sin15도의 값은? : 1)0.2588 2)1 3)0.4577 4)0.792");
                    scanf("%d", &j);
                    if (j == 1)
                    {
                        count++;
                        printf("정답입니다!");
                    }
                    else
                    {
                        printf("오답입니다. 정답은 1번입니다.");
                    }
                    break;
                case 3://3번 문제
                    printf("복소수 i^4은 무엇인가? : (1. 5),  (2. 3.1425), (3. 1 ), (4. 7.832)");
                    scanf("%d", &j);
                    if (j == 3)
                    {
                        count++;
                        printf("정답입니다!");
                    }
                    else
                    {
                        printf("오답입니다. 정답은 3번입니다.");
                    }
                }
            }
        }
        if (k == 2)//물리 과목
        {
            for (int i = 0; i < 3; i++)//3번 반복
            {
                scanf("%d", &x);
                switch (x)//문제 번호 출력
                {
                case 1://1번 문제
                    printf("공을 높이가 20m 인 곳에서 중력가속도 10m/s^2을 받으면서 자유낙하한다고 할때, 낙하후 이 공의 속도는? 1.4m/s 2.(1.98)m/s 3. 20m/s 4. 이호형한테 물어보세요 ");
                    scanf("%d", &j);
                    if (j == 3)
                    {
                        count++;
                        printf("정답입니다!");
                    }
                    else
                    {
                        printf("오답입니다. 정답은 3번입니다.");
                    }
                    break;
                case 2://2번 문제
                    printf("뉴턴의 법칙의 개수는? (1.1) (2. 4) (3. 3) (4. 1000)");
                    scanf("%d", &j);
                    if (j == 3)
                    {
                        count++;
                        printf("정답입니다!");
                    }
                    else
                    {
                        printf("오답입니다. 정답은 3번입니다.");
                    }
                    break;
                case 3://3번 문제
                    printf("물리 선생님의 수는? (1.1) (2.-1) (3. 3) (4.2)");
                    scanf("%d", &j);
                    if (j == 4)
                    {
                        count++;//점수 하나씩 올린다.
                        printf("정답입니다!");
                    }
                    else
                    {
                        printf("오답입니다. 정답은 4번입니다.");
                    }
                }
            }
        }
    } while (count < 5);//문제 다섯번 맞힐때까지
    printf("수고하셨습니다");
    return 0;
}

