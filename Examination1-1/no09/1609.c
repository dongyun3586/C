#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a = 0, b = 0, c = 0;

    printf("입력 정수: ");
    scanf("%d", &a);

    printf("출력 정수: ");
    while (1) {
        b = a % 10;
        c = (a - b) / 10;
        printf("%d", &b);
        
        if (b == 0)
            break;
    }

    return 0;
}