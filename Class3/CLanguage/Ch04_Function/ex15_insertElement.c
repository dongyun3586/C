#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int arr[], int length);

int main()
{
    int numArr[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int length = 10;

    // 배열 출력 
    print1DArray(numArr, length);

    for (int i = 0; i < 2; i++) {
        insertElement(numArr, length++);      // 배열에 새로운 요소 삽입
        print1DArray(numArr, length);         // 배열 출력 
    }

    return 0;
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int length)
{

}