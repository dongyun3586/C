#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);

    int calrory = 0;

    switch(a){
        case 1:
            calrory += 400;
            break;
        case 2:
            calrory += 340;
            break;
        case 3:
            calrory += 170;
            break;
        case 4:
            calrory += 100;
            break;
        case 5:
            calrory += 70;
            break;
    }

    switch(b){
        case 1:
            calrory += 400;
            break;
        case 2:
            calrory += 340;
            break;
        case 3:
            calrory += 170;
            break;
        case 4:
            calrory += 100;
            break;
        case 5:
            calrory += 70;
            break;
    }


    if(calrory > 500)
        printf("angry");
    else
        printf("no angry");

    return 0;
}
