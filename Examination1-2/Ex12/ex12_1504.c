#include <stdio.h>
#include <math.h>
int reverse(int num);

int main() {
    // ① 변수 선언 [2점]
    int num;

    // ② 입력 정보 안내 및 입력 받기 [2점]
    printf("양의 정수 입력: ");
    scanf("%d", &num);

    // ③ 처리 및 출력 [2점]
    printf("Reverse of %d = %d", num, reverse(num));

    return 0;
}

// ④ reverse 함수 [4점]
int reverse(int num) {
    if (num / 10 == 0)return num;
    return (int)pow(10, log10(num)) * (num % 10) + reverse(num / 10);
}