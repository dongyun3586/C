#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a + b > c){
        if(a == b && b == c)
            printf("Á¤»ï°¢Çü");
        else if(a == b || b == c || c == a)
            printf("ÀÌµîº¯»ï°¢Çü");
        else if(a*a + b*b == c*c)
            printf("Á÷°¢»ï°¢Çü");
        else
            printf("»ï°¢Çü");
    }else{
        printf("»ï°¢Çü¾Æ´Ô");
    }


    return 0;
}
