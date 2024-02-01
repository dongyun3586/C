#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y, m;
    scanf("%d %d", &y, &m);

    switch(m)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30");
        break;
    case 2:
        if(y%400==0 || y%4==0 && y%100!=0)
            printf("29");
        else
            printf("28");
        break;
    default:
        printf("31");
        break;

    }
    return 0;
}
