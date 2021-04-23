#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n, m, c = 0, i;

    printf("입력 정수: ");
    scanf("%d", &n);

    m = n;
    while (m > 0) {
        m /= 10;
        c++;
    }

    printf("출력 정수: ");
    for(i=0;i<c;i++)
        printf("%d", n / (10 ^ i) - (n / (10 ^ (i + 1))) * 10);

    return 0;
}