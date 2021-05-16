#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int size);
void print1DArray(int arr[], int length);

int main()
{
    int arr[20];
    int size = 20, temp;

    // 랜덤 배열 생성
    printf("1~100 사이의 랜덤 숫자 배열 생성\n");
    generateRandomNum(arr, size);

    // 초기 배열 상태 출력
    print1DArray(arr, size);

    // Find duplicate elements in array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // 정렬된 배열
    print1DArray(arr, size);

    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
