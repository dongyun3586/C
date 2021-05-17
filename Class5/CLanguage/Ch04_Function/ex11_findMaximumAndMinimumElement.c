#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10], max;
    int arrCount = sizeof(arr) / sizeof(arr[0]);

    // 1. 배열에 1~1000 사이의 랜덤값 저장

    // 2. 배열의 모든 요소 출력하기

    // 3. 배열에서 가장 큰 값과 작은 값 찾기
    max = arr[0];

    // 4. 배열에서 가장 큰 값과 작은 값 출력
    printf("배열에서 가장 큰 값 = %d\n", max);

    return 0;
}