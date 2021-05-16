#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10], max, min;
    int arrCount = sizeof(arr) / sizeof(arr[0]);

    // 1. 배열에 1~1000 사이의 랜덤값 저장
    srand(time(NULL));
    for (int i = 0; i < arrCount; i++)
        arr[i] = rand() % 1000 + 1;

    // 2. 배열의 모든 요소 출력하기
    for (int i = 0; i < arrCount; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    // 3. 배열에서 가장 큰 값과 작은 값 찾기
    max = min = arr[0];
    for (int i = 1; i < arrCount; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }

    // 4. 배열에서 가장 큰 값과 작은 값 출력
    printf("배열에서 가장 큰 값 = %d\n", max);
    printf("배열에서 가장 작은 값 = %d\n", min);

    return 0;
}