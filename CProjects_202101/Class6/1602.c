#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int l(int a, int b)
{
    if (b == 1)
    {
        printf("%d ", a);//이거는 맞추면 숫자 보여주는 거  
    }
    else
    {
        printf("w "); //못말칠 때는 계속 색깔만 보여주는 것 
    }

}
int v(int a, int b)
{
    if (b == 1)
    {
        printf("%d ", a);
    }
    else
    {
        printf("b ");
    }
}
int main(void)
{
    int temp;
    int result[7] = { 0 };
    int num[7] = { 0 };//흰 //1부터 9까지 숫자
    int n[7] = { 0 }; //흰 배 
    int nun[7] = { 0 }; //검 
    int m[7] = { 0 };//검배 
    int white[7] = { 0 };//트루 1 펄스 0 
    int black[7] = { 0 };//트루 1 펄스 0 
    int Data, p, q, r, o, s, tum = 0;


    srand(time(NULL));
    r = rand() % 8;//흰색 카드 갯수 
    for (int i = 0; i < r; i++)
    {
        while (i < r)
        {
            num[i] = rand() % 10 + 1;
            for (int j = 0; j < i; j++)
            {
                if (num[i] == num[j])
                {
                    i--;
                    break;
                }
            }
            i++;
        }
    }
    for (int i = 0; i < 7 - r; i++)
    {
        while (i < 7 - r)
        {
            nun[i] = rand() % 10 + 1;
            for (int j = 0; j < i; j++)
            {
                if (nun[i] == nun[j])
                {
                    i--;
                    break;
                }
            }
            i++;
        }
    }
    for (int i = 0; i < r - 1; i++)//큰숫자가 앞으로 가게  
    {
        for (int j = i + 1; j < r; j++)
        {
            if (num[i] < num[j])
            {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
    for (int i = 0; i < 6 - r; i++)//큰 숫자 앞으로 가게 
    {
        for (int j = i + 1; j < 7 - r; j++)
        {
            if (nun[i] < nun[j])
            {
                temp = nun[j];
                nun[j] = nun[i];
                nun[i] = temp;
            }
        }
    }
    while (tum != 7)//이것은 흰색 r개 검은색 7-r개를 한 번에 크기순으로 배열하는 코드 (result에다가) 
    {
        if (num[o] >= nun[s])
        {
            result[tum] = num[o];
            n[tum] = num[o];
            m[tum] = 0;
            o++;
            tum++;
        }
        else
        {
            result[tum] = nun[s];
            m[tum] = nun[s];
            n[tum] = 0;
            s++;
            tum++;
        }
    }
    printf("다빈치 코드게임을 시작하겠습니다.\n");
    for (int i = 0; i < 7; i++)//일단 시작하자마자 색깔 보여주는 거 
    {
        if (n[i] != 0)
        {
            l(n[i], white[i]);
        }
        else
        {
            v(m[i], black[i]);
        }
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", result[i]);
    }


    return 0;

}
//흰색 r개 검은색 7-r개 하나에다가 집어넣고 크기 배열 조커인 10만 다르게 