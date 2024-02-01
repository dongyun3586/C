#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);

    switch(a)
    {
    case 1:
    case 3:
    case 5:
    case 7:
        printf("oh my god");
        break;
    default:
        printf("enjoy");
        break;
    }
    return 0;
}
