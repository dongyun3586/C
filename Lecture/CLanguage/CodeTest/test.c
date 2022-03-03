#include <stdio.h>

void printArray(int* arr, int n);
void swapArray(int** arr1, int** arr2);

int main()
{
    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 10,20,30,40,50 };

    int* p1 = arr1;
    int* p2 = arr2;

    printArray(p1, 5);
    printArray(p2, 5);

    swapArray(&p1, &p2);

    printArray(p1, 5);
    printArray(p2, 5);

    return 0;
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swapArray(int** arr1, int** arr2) {
    int* temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}