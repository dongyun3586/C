#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int array[], int position);

int main()
{
    int array[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int position, c, length = 10;

    // �迭�� �ʱ� ���� ��� 
    print1DArray(array, length);

    // �迭�� ���ο� ��� ���� �� ���
    for (int i = 0; i < 2; i++) {
        insertElement(array, length++);      // �迭�� ���ο� ��� ����
        print1DArray(array, length);         // �迭 ��� 
    }

    return 0;
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int array[], int length)
{
    // �ʿ��� ���� ����
    int position, insertValue;

    // �ʿ��� �� �Է¹ޱ�
    printf("��ġ�� ���ο� �� �Է�: ");
    scanf("%d %d", &position, &insertValue);

    // ó�� 
    // 1. �� ��ġ ������ ��Ұ� ��� ���������� �̵�
    for (int i = length - 1; i >= position - 1; i--)
        array[i + 1] = array[i];

    // 2. ���ο� �� �迭�� �߰�
    array[position - 1] = insertValue;
}