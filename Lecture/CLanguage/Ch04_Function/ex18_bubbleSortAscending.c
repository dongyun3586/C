#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int size);
void print1DArray(int arr[], int length);
void bubbleSortAscending(int arr[], int size);

int main()
{
    int numArr[20];
    int size = sizeof(numArr) / sizeof(int);

    // 랜덤 배열 생성
    printf("1~100 사이의 랜덤 숫자 배열 생성\n");
    generateRandomNum(numArr, size);

    // 초기 배열 상태 출력
    printf("정렬 전 배열\n");
    print1DArray(numArr, size);

    // 오름차순 정렬
    bubbleSortAscending(numArr, size);

    // 정렬된 배열
    printf("정렬 후 배열\n");
    print1DArray(numArr, size);

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
    printf("\n\n");
}

void bubbleSortAscending(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
