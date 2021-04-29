#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a = 0, num = 0, b = 0, c = 1, d = 1;

    while (b == 0) {
        printf("입력 정수: ");
        scanf("%ld", &a);
        for (int i = 1; i < c; i++)
            d *= 10;
        num = num + a * d;
        d = 1;
        c += 1;
    }
    

    printf("출력 정수: %d ", num);

    return 0;
}