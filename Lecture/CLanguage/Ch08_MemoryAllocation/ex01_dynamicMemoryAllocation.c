#include <stdio.h>   
#include <stdlib.h> 

void printP(int* p);

int main(void)
{
    int* p1 = malloc(4 * sizeof(int));  // allocates enough for an array of 4 int
    int* p2 = malloc(sizeof(int[4]));   // same, naming the type directly

    printP(p1);     // malloc( ) 함수는 메모리 할당에 실패하는 경우 NULL 반환
    printP(p2);

    free(p1);       // 메모리 해제
    free(p2);
}

void printP(int* p) {
    if (p != NULL) {
        for (int n = 0; n < 4; ++n)
            p[n] = n * n;
        for (int n = 0; n < 4; ++n)
            printf("p[%d] == %d\n", n, p[n]);
    }
}