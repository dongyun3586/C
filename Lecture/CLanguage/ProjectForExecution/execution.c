#include <stdio.h>

int main() {
    int i=1, number, sum = 0;

    while (1) {
        printf("정수입력 %d: ", i);
        scanf("%d", &number);

        // 음수가 입력되면 종료된다.
        if (number < 0)
            break;

        i++;
        sum += number;
    }

    printf("합계 = %d", sum);

    return 0;
}