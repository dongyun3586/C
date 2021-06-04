#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int length);
void print1DArray(int arr[], int length);
int deleteDuplicateElements(int arr[], int length);

int main()
{
    int numArr[100];
    int length;

    printf("�������� ���� ����: ");
    scanf("%d", &length);

    // ���� �迭 ����
    printf("1~50 ������ ���� ���� �迭 ����\n");
    generateRandomNum(numArr, length);

    // �迭 �ʱ� ���� ���
    print1DArray(numArr, length);

    // �迭�� �ߺ��Ǵ� ��� ����
    length = deleteDuplicateElements(numArr, length);

    // �迭 �ߺ� ���� ���� ���
    print1DArray(numArr, length);

    return 0;
}

// ���� �迭 ���� �Լ�
void generateRandomNum(int arr[], int length)
{

}

void print1DArray(int arr[], int length) {
    printf("\n�迭 ũ��: %d\n", length);
    for (int i = 0; i < length; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}

int deleteDuplicateElements(int arr[], int length)
{

}