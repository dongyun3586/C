#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int l(int a, int b)
{
    if (b == 1)
    {
        printf("%d ", a);//�̰Ŵ� ���߸� ���� �����ִ� ��  
    }
    else
    {
        printf("w "); //����ĥ ���� ��� ���� �����ִ� �� 
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
    int num[7] = { 0 };//�� //1���� 9���� ����
    int n[7] = { 0 }; //�� �� 
    int nun[7] = { 0 }; //�� 
    int m[7] = { 0 };//�˹� 
    int white[7] = { 0 };//Ʈ�� 1 �޽� 0 
    int black[7] = { 0 };//Ʈ�� 1 �޽� 0 
    int Data, p, q, r, o, s, tum = 0;


    srand(time(NULL));
    r = rand() % 8;//��� ī�� ���� 
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
    for (int i = 0; i < r - 1; i++)//ū���ڰ� ������ ����  
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
    for (int i = 0; i < 6 - r; i++)//ū ���� ������ ���� 
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
    while (tum != 7)//�̰��� ��� r�� ������ 7-r���� �� ���� ũ������� �迭�ϴ� �ڵ� (result���ٰ�) 
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
    printf("�ٺ�ġ �ڵ������ �����ϰڽ��ϴ�.\n");
    for (int i = 0; i < 7; i++)//�ϴ� �������ڸ��� ���� �����ִ� �� 
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
//��� r�� ������ 7-r�� �ϳ����ٰ� ����ְ� ũ�� �迭 ��Ŀ�� 10�� �ٸ��� 