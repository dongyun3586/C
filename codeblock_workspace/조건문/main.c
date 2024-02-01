#include <stdio.h>
#include <stdlib.h>

void p(int n){
    if(n==0)
        return;
    printf("%d\n", n);
    p(n-1);

}


int main()
{
    int n;
    scanf("%d", &n);

    p(n);

    return 0;
}
