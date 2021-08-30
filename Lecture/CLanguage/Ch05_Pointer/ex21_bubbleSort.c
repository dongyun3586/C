#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void generateRandomNum(int arr[], int length);
void print1DArray(int arr[], int length);
void bubbleSortAscending(int arr[], int length, char* order, int(*fp)(int, int));
int ascendCompare(int a, int b);
int descendCompare(int a, int b);

int main()
{
    int numArr[20];
    int length = sizeof(numArr) / sizeof(int);

    // 1~100 ���� ���� �迭 ����
    generateRandomNum(numArr, length);

    // �ʱ� �迭 ���� ���
    printf("���� ��: ");
    print1DArray(numArr, length);
    printf("\n");

    // �������� ����
    bubbleSortAscending(numArr, length, "�������� ����", ascendCompare);

    // ���ĵ� �迭
    printf("\n���� ��: ");
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

void bubbleSortAscending(int arr[], int length, char* order, int(*comparer)(int, int))
{
    printf("%s\n", order);
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (comparer(arr[j], arr[j + 1]) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("%2d�ܰ� : ", i + 1);
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