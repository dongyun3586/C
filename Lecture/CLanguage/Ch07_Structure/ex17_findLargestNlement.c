#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNum(float* arr, int n);
void printArr(float* arr, int n);
float findMaxNum(float* arr, int n);

int main()
{
    int n;
    float* element;
    printf(" Input total number of elements(1 to 100): ");
    scanf("%d", &n);
    element = (float*)malloc(sizeof(float) * n);

    if (element == NULL)
    {
        printf(" No memory is allocated.");
        exit(0);
    }

    // 배열에 랜덤 숫자 저장
    generateRandomNum(element, n);
    printArr(element, n);

    printf(" The Largest element is :  %2.1f \n\n", findMaxNum(element, n));
    return 0;
}

void generateRandomNum(float* arr, int n) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; ++i)
        arr[i] = ((float)rand() / (float)(RAND_MAX)) * 100;
}

void printArr(float* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%2.1f ", arr[i]);
    printf("\n");
}

float findMaxNum(float* arr, int n) {
    // 2. 배열 중 가장 큰 숫자 리턴
    for (int i = 1; i < n; i++)
        if (*arr < *(arr + i))
            *arr = *(arr + i);
    return *arr;
}