#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int arr[], int length);

int main()
{
    int numArr[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int length = 10;

    // �迭 ��� 
    print1DArray(numArr, length);

    for (int i = 0; i < 2; i++) {
        insertElement(numArr, length++);      // �迭�� ���ο� ��� ����
        print1DArray(numArr, length);         // �迭 ��� 
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
    // ���� ����
    int position, insertValue;

    // �ʿ��� �� �Է¹ޱ�
    printf("��ġ, ���ο� �� �Է�:");
    scanf("%d %d", &position, &insertValue);

    // ó��
    // 1. �ڸ� Ȯ��(������ �ֵ��� �ڷ� �и���)
    for (int i = length - 1; i >= position - 1; i--)
        arr[i + 1] = arr[i];

    // 2. ���ο� �� �迭�� ����
    arr[position - 1] = insertValue;
}