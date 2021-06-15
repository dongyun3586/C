#include <stdio.h>
#include <math.h>

int countDigitsOfNumber(int num);
int checkArmstrongNumber(int num, int n);
int reversNumber(int num);
void printArmstrongNumber(int num, int n);

int main() {
    int a = 1, b = 1000000, n, count = 0, i;
    printf("*** 1학년 1반 13번 이다연 ***\n");
    printf("*** 1~1000000 사이의 암스트롱수 ***\n\n");

    for (i = a; i <= b; i++) {
        n = countDigitsOfNumber(i);
        if (checkArmstrongNumber(i, n)) {
            printArmstrongNumber(i, n);
            count++;
        }
    }
    printf("\n1~1000000 사이의 암스트롱수는 %d개 ", count);
}

int countDigitsOfNumber(int num) {
    int n = 0;
    do {
        n++;
        num /= 10;
    } while (num != 0);

    return n;
}

int checkArmstrongNumber(int num, int n) {
    int i, k;
    double sum = 0;

    k = num;
    for (i = 1; i <= n; i++) {
        sum += pow(k % 10, n);
        k /= 10;
    }

    if (sum == num)
        return 1;
    else
        return 0;
}

int reversNumber(int num) {
    int i, k = 1, n, sum = 0;

    n = countDigitsOfNumber(num);
    for (i = 1; i < n; i++) {
        k *= 10;
    }
    for (i = 1; i <= n; i++) {
        sum += (num % 10) * k;
        num /= 10;
        k /= 10;
    }
    return sum;
}

void printArmstrongNumber(int num, int n) {
    int i, t;

    printf("%7d= ", num);
    num = reversNumber(num);

    t = countDigitsOfNumber(num);
    for (i = 1; i <= t; i++) {
        if (i < t)
            printf("%.0f + ", pow(num % 10, n));
        else
            printf("%.0f\n", pow(num % 10, n));
        num /= 10;
    }
}