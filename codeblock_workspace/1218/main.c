#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a + b > c){
        if(a == b && b == c)
            printf("���ﰢ��");
        else if(a == b || b == c || c == a)
            printf("�̵�ﰢ��");
        else if(a*a + b*b == c*c)
            printf("�����ﰢ��");
        else
            printf("�ﰢ��");
    }else{
        printf("�ﰢ���ƴ�");
    }


    return 0;
}
