#include <stdio.h>
int checkPerfectNumber(int num);
int main()
{
    int a = 1, b = 10000, sum;
    printf("All Perfect numbers between %d to %d:\n", a, b);

    for (int i = a; i <= b; i++)
        if (checkPerfectNumber(i)) {
            printf("%4d = 1", i);
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    printf(" + %d", j);
                }

            }
            printf("\n");
        }

    return 0;
}

int checkPerfectNumber(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            sum += i;
    }
    if (sum == num)
        return 1;
    return 0;
}