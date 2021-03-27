#include <stdio.h>

int main_ex11_factorsOfANumber() {
    int num, i;
    printf("양의 정수를 입력하시오: ");
    scanf("%d", &num);
    printf("%d의 약수는 : ", num);
    for (i = 1; i <= num; ++i) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}