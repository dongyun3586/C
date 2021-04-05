#include <stdio.h>

int main_ex22_breakExam() {
    int number, sum = 0;

    while (1) {
        printf("정수입력: ");
        scanf("%d", &number);

        // 음수가 입력되면 종료된다.
        if (number < 0)
            break;

        sum += number;
    }

    printf("합계 = %d", sum);

    return 0;
}