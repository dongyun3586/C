#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, days;
    scanf("%d", &m);

    // 30: 4, 6, 9, 11
    // 28: 2

    switch(m){
    case 2:
        days = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    default:
        days = 31;
        break;
    }

    printf("%d월의 일수는 %d입니다.\n", m, days);

    return 0;
}

