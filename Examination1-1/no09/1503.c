#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int num, sum, temp;

    printf("입력 정수: ");
    scanf("%d", &num);

    temp = num;
    while (temp > 0) {
        sum = sum + temp % 10;
        sum *= 10;
        temp /= 10;
    }
    sum /= 10;

    printf("출력 정수: %d", sum);
    return 0;
}