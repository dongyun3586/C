#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int array[], int position);

int main()
{
    int array[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int position, c, length = 10, insertValue;

    // �迭 ��� 
    print1DArray(array, length);

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
    int insertValue, position;

    printf("\n���ο� ���� ��ġ �Է�:  ");
    scanf("%d %d", &insertValue, &position);

    // position���� length������ ��� ���������� ��ĭ�� �ű��
    for (int i = length - 1; i >= position - 1; i--)
        array[i + 1] = array[i];

    // position ��ġ�� insertValue �ֱ�
    array[position - 1] = insertValue;
}