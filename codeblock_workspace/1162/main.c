#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);

    if((y - m + d)%10 == 0)
        printf("���");
    else
        printf("�׷�����");
    return 0;
}
