#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define M 100
int n;
int random();
int percentage(i, b);
int human(i);
int win(int b[], int i);
int equal(int  b[], int i);
int lose(int b[], int i);

int main()
{
    int a[M], b[M], w;
    printf("�󸶳� �� �Ŵ�?");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("����,����,��");
        printf("%d��°\n", i);

        printf("human:");

        a[i] = random();
        w = 0;
        w = human();

        if (w == a[i])
        {
            equal(b, i);//��=1.�ָ�=0,����=2

        }
        else if ((w == 0) && (a[i] == 2) || (w == 1) && (a[i] == 0) || (w == 2) && (a[i] == 1))
        {
            win(b, i);
        }
        else if (((w == 0) && (a[i] == 1)) || ((w == 1) && (a[i] == 2)) || ((w == 2) && (a[i] == 0)))
        {
            lose(b, i);
        }
        if (a[i] == 1)
        {
            printf("computer:��\n");
        }
        if (a[i] == 2)
        {
            printf("computer:����\n");
        }
        if (a[i] == 0)
        {
            printf("computer:�ָ�\n");
        }


    }

    return 0;
}

int random()
{
    int k;
    srand(time(NULL));
    k = rand() % 3;
    return k;
}
//int percentage(int i,int b[M])
//{
    //printf("��������� Ȯ����?");
    //for(int j=1;j<=i;j++)
    //{

    //}
//}

int human()
{
    char c[M];

    scanf(" %s", &c);
    if ('r' == c[1])
    {
        return 0;
    }
    else if ('s' == c[1])
    {
        return 1;
    }
    else if ('p' == c[1])
    {
        return 2;
    }
}



int win(int  b[], int i)
{
    printf("����� �̰���ϴ�.\n");
    b[i] = 2;
    //percentage(i,b[i]);
    return i;


}
int equal(int  b[], int  i)
{
    printf("��屺��\n");
    b[i] = 1;
    // percentage(i,b[i]);
    return i;


}
int  lose(int b[], int i)
{
    printf("���� ����\n");
    b[i] = 0;
    //percentage(i,b[i]);
    return i;
}
