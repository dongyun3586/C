#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void generateRandomNum(int arr[], int n);
void print1DArray(int arr[], int n);
void bubbleSortAscending(int arr[], int n);

int main()
{
    int numArr[20];
    int n = sizeof(numArr) / sizeof(int);

    // 1~100 랜덤 숫자 배열 생성
    generateRandomNum(numArr, n);

    // 초기 배열 상태 출력
    printf("정렬 전 배열 상태\n");
    print1DArray(numArr, n);

    // 오름차순 정렬
    bubbleSortAscending(numArr, n);

    // 정렬된 배열
    printf("정렬 후 배열 상태\n");
    print1DArray(numArr, n);

    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print1DArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n\n");
}

void bubbleSortAscending(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}