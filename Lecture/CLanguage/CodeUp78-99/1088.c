// 1088 : [기초-종합] 3의 배수는 통과?

#include<stdio.h>
int main_1088()
{
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
    {
        if (i % 3 != 0)
            printf("%d ", i);
    }

    return 0;
}
