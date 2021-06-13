#include <stdio.h>
int sumArr(int arr[], int start, int len);
void printArray(int arr[], int start, int len);

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int N = sizeof(arr) / sizeof(int);

    printf("�迭 ��ҵ��� ��: %d\n", sumArr(arr, 0, N));

    printf("�迭�� ��� ��� ���\n");
    printArray(arr, 0, N);

    return 0;
}

int sumArr(int arr[], int start, int len) {
    if (start == len - 1)
        return arr[start];
    return arr[start] + sumArr(arr, start + 1, len);
}

void printArray(int arr[], int start, int len) {
    if (start == len - 1) {
        printf("%d", arr[start]);
        return;
    }

    printf("%d, ", arr[start]);
    printArray(arr, start + 1, len);
}