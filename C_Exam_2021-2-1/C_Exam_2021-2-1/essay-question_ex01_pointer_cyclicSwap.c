#include <stdio.h>

void cyclicSwap(int* a, int* b, int* c);

int main() {
    int a, b, c;

    printf("정수 3개 입력 : ");
    scanf("%d %d %d", &a, &b, &c);

    printf("a = %d b = %d c = %d\n", a, b, c);
    cyclicSwap(&a, &b, &c);
    printf("a = %d b = %d c = %d\n", a, b, c);

    return 0;
}

void cyclicSwap(int* n1, int* n2, int* n3) {
    int temp;
    temp = *n2;
    *n2 = *n1;
    *n1 = *n3;
    *n3 = temp;
}