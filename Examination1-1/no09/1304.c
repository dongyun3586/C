#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n, a = 1, count = 1;

    printf("입력 정수: ");
    scanf("%d", &n);

    while (a != 0) {
        a = n;
        if ((a / 10) != 0) {
            count += 1;

        }
    }

    return 0;
}