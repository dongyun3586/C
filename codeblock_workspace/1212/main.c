#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, temp;
    scanf("%d %d %d", &a, &b, &c);

    if(a>b && a>c){
        temp = a;
        a = c;
        c = temp;
    }
    else if(b>a && b>c){
        temp = b;
        b = c;
        c = temp;
    }


    if(a + b > c)
        printf("yes");
    else
        printf("no");
    return 0;
}
