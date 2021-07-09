#include <stdio.h>
#include <math.h>
int reverse(int num);

int main() {
    // ① 변수 선언 [2점]
    int n, n2;

    // ② 입력 정보 안내 및 입력 받기 [2점]
    printf("양의 정수 입력: ");
    scanf("%d", &n);

    // ③ 처리 및 출력 [2점]
    printf("Reverse of %d = %d", n, reverse(n));

    return 0;
}

// ④ reverse 함수 [4점]
int reverse(int num) {
    if (num == 0)return 0;
    int tmp = log10(num);
    int now = num / pow(10, tmp);
    return now + 10 * reverse(num % (int)pow(10, tmp));
}