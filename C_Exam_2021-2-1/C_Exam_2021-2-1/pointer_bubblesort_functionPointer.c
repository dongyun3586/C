#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void generateRandomNum(int arr[], int length);
void print1DArray(int arr[], int length);
void bubbleSort(int arr[], int length, char* order, int(*fp)(int, int));
int ascendCompare(int a, int b);
int descendCompare(int a, int b);

int main()
{
    int numArr[10];
    int length = sizeof(numArr) / sizeof(int);

    // 1~100 랜덤 숫자 배열 생성
    generateRandomNum(numArr, length);

    // 초기 배열 상태 출력
    printf("정렬 전: ");
    print1DArray(numArr, length);
    printf("\n");

    // 오름차순 정렬
    printf("정렬 방법(오름차순=a, 내림차순=d) : ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'a')
        bubbleSort(numArr, length, "오름차순 정렬", ascendCompare);
    else if (choice == 'd')
        bubbleSort(numArr, length, "내림차순 정렬", descendCompare);

    // 정렬된 배열
    printf("\n정렬 후: ");
    print1DArray(numArr, length);

    return 0;
}

void generateRandomNum(int arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++)
        arr[i] = rand() % 100 + 1;
}

void print1DArray(int* arr, int length) {
    for (int i = 0; i < length; i++)
        printf("%02d ", *arr++);
    printf("\n");
}

void bubbleSort(int arr[], int length, char* order, int(*comparer)(int, int))
{
    printf("\n<%s>\n", order);
    int temp;
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < length - i; j++) {
            if (comparer(arr[j], arr[j + 1]) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("%d단계 : ", i);
        print1DArray(arr, length);
    }
}

int ascendCompare(int a, int b) {
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}

int descendCompare(int a, int b) {
    if (a < b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}