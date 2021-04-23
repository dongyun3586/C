#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a, b, c, d, e, f = 0;

    printf("입력 정수: ");
    scanf("%d", &a);
    b = a; d = a;
    do {
        d /= 10;
        e++;
    } while (d > 0)

    for (int i = e; i > 0; i--) {
        c = b % 10;
        b /= 10;
        f = f + 10 * c;
    }

    printf("출력 정수: %d", f);

    return 0;
}