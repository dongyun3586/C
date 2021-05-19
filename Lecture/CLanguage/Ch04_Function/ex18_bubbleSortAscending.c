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

    // ���� �迭 ����
    printf("1~100 ������ ���� ���� �迭 ����\n");
    generateRandomNum(numArr, size);

    // �ʱ� �迭 ���� ���
    printf("���� �� �迭\n");
    print1DArray(numArr, size);

    // �������� ����
    bubbleSortAscending(numArr, size);

    // ���ĵ� �迭
    printf("���� �� �迭\n");
    print1DArray(numArr, size);

    return 0;
}

// ���� �迭 ���� �Լ�
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
