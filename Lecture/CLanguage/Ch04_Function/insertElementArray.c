#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int array[], int n);

int main()
{
    int array[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int position, c, n = 10, insertValue;

    // �迭 ��� 
    print1DArray(array, n);

    // �迭�� ���ο� ��� ����
    insertElement(array, n++);

    // �迭 ��� 
    print1DArray(array, n);

    return 0;
}

void print1DArray(int arr[], int length) {
    printf("1���� �迭 ���\n");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int array[], int n)
{
    int position, c, insertValue;

    printf("\n\n������ ���ϴ� ��ġ�� ����?  ");
    scanf("%d %d", &position, &insertValue);

    // position���� n������ ��� ���������� �ű��
    for (c = n - 1; c >= position - 1; c--)
        array[c + 1] = array[c];

    // position ��ġ�� insertValue �ֱ�
    array[position - 1] = insertValue;
}