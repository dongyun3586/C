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

    // 1~100 ���� ���� �迭 ����
    generateRandomNum(numArr, n);

    // �ʱ� �迭 ���� ���
    printf("���� �� �迭 ����\n");
    print1DArray(numArr, n);

    // �������� ����
    bubbleSortAscending(numArr, n);

    // ���ĵ� �迭
    printf("���� �� �迭 ����\n");
    print1DArray(numArr, n);

    return 0;
}

// ���� �迭 ���� �Լ�
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