#include <stdio.h>
int main() {
    int number, sum = 0;

    for (int i = 1; i <= 5; i++) {
        printf("정수입력 %d: ", i);
        scanf("%d", &number);

        // 음수가 입력되면 다음 반복으로 넘어간다.
        if (number < 0)
            continue;

        sum += number;
    }

    printf("합계 = %d", sum);

    return 0;
}