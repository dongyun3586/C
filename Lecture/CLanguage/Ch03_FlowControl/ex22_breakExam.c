#include <stdio.h>

int main_ex22_breakExam() {
    int i, number, sum = 0;

    for (i = 1; i <= 10; ++i) {
        printf("정수입력 %d: ", i);
        scanf("%d", &number);

        // 음수가 입력되면 종료된다.
        if (number < 0) 
            break;

        sum += number; 
    }

    printf("합계 = %d", sum);

    return 0;
}