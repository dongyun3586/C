#include <stdio.h>
#include <stdlib.h>
#define N 6
#define M 9
#define G 100
struct data
{
    char crray[N];
    int arr[N];
}s[M];
int r;
void input(void)
{
    FILE* fp1;
    int i, r;
    fp1 = fopen("input.txt", "r");
    fscanf(fp1, "%d", &r);
    for (i = 0; i < r; i++)
    {
        fscanf(fp1, "%s", s[i].crray);

        for (int j = 0; j < 6; j++)
        {
            fscanf(fp1, " %d ", &s[i].arr[j]);
        }

    }
    printf("%d\n", r);
    for (int j = 0; j < r; j++)
    {
        printf("%s ", s[j].crray);
        for (int k = 0; k < 6; k++)
        {
            printf("%d ", s[j].arr[k]);
            if (k == 5)
            {
                printf("\n");
            }
        }
    }

    fclose(fp1);
    return 0;
}
void plus(int* p)
{
    if (*p >= 9)
    {
        *p = 100;
    }
    else if (*p <= 8 && *p >= 6)
    {
        *p = 80;
    }
    else if (*p >= 3 && *p <= 5)
    {
        *p = 50;
    }
    else
    {
        *p = 20;

    }

}//��� ����� ���� ������ �ο��Ѵ�.
int judgement(int y)
{

    if (y >= 480)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}//������ ���� �հ� ���� ����
int main()
{
    printf("example\n");//�̰� ���ô�.
    input();
    int a[N + 2] = { 0 };

    int temp, i, n, sum = 0, d[G + 1], cnt = 0;
    char m[G + 1][9], temp_m[9];
    char b[M + 1];

    printf("input");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum = 0;
        scanf("%s", b);
        for (int j = 1; j <= 6; j++)
        {
            scanf("%d", &a[j]);
        }
        //a[1]=plus(a[1]);
        plus(&a[1]);
        //�޴´�.
        for (int j = 1; j <= 6; j++)
        {
            sum += a[j];
        }//������ ���Ѵ�.
        if (judgement(sum))
        {
            cnt++;
            d[cnt] = sum;
            strcpy(m[cnt], b);
        }
    }//���ο� �迭�� �հ��� ����� ������ �ִ´�.
    for (int i = 1; i < cnt; i++)
    {
        for (int j = i; j <= cnt; j++)
        {
            if (d[i] < d[j])
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
                strcpy(temp_m, m[i]);
                strcpy(m[i], m[j]);
                strcpy(m[j], temp_m);

            }

        }
    }//�̸��� ���� �ٲ�� �Ѵ�.
    printf("%d\n", cnt);
    for (i = 1; i <= cnt; i++)
    {
        printf("%s %d\n", m[i], d[i]);
    }

}//�������� ����Ѵ�



