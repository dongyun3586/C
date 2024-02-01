#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(a>b)
        printf(">");
    else if(b>a)
        printf("<");
    else
        printf("=");
    return 0;
}
