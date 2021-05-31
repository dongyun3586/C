#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void generateRandomNum(int arr[], int length);
void print1DArray(int arr[], int length);
void bubbleSortAscending(int arr[], int length);

int main()
{
    int numArr[20];
    int length = sizeof(numArr) / sizeof(int);

    // 1~100 랜덤 숫자 배열 생성
    generateRandomNum(numArr, length);

    // 초기 배열 상태 출력
    printf("정렬 전 배열 상태\n");
    print1DArray(numArr, length);

    // 오름차순 정렬
    bubbleSortAscending(numArr, length);

    // 정렬된 배열
    printf("정렬 후 배열 상태\n");
    print1DArray(numArr, length);

    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%2d ", arr[i]);
    printf("\n\n");
}

void bubbleSortAscending(int arr[], int length)
{
    int t;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}