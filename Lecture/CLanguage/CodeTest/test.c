#include<stdio.h>

void print1DArray(int arr[], int n);
void insertElement(int arr[], int n);

int main()
{
    int numArr[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int n = 10;

    // �迭 ��� 
    print1DArray(numArr, n);

    for (int i = 0; i < 2; i++) {
        insertElement(numArr, n++);      // �迭�� ���ο� ��� ����
        print1DArray(numArr, n);         // �迭 ��� 
    }

    return 0;
}

void print1DArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int n)
{
    int p, v;
    printf("��ġ�� ���ο� �� �Է�: ");
    scanf("%d %d", &p, &v);

    for (int i = n - 1; i >= p - 1; i--)
        arr[i + 1] = arr[i];
    arr[p - 1] = v;
}