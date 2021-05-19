#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int size);
void print1DArray(int arr[], int length);
int deleteDuplicateElements(int arr[], int size);

int main()
{
    int numArr[1000];
    int size;

    printf("�迭�� ũ��: ");
    scanf("%d", &size);

    // ���� �迭 ����
    printf("1~50 ������ ���� ���� �迭 ����\n");
    generateRandomNum(numArr, size);

    // �迭�� �ʱ� ���� ���
    print1DArray(numArr, size);

    // �迭���� �ߺ��� ��� ����
    size = deleteDuplicateElements(numArr, size);

    // �ߺ� ��� ���� �� �迭 ���� ���
    printf("\n�迭 ũ��: %d\n", size);
    print1DArray(numArr, size);

    return 0;
}

// ���� �迭 ���� �Լ�
void generateRandomNum(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1;
    }
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}

int deleteDuplicateElements(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // �ߺ��� ��Ҹ� �߰��ϸ�
            if (arr[i] == arr[j])
            {
                // �ߺ��� ��� �迭���� ���� 
                for (int k = j; k < size - 1; k++)
                    arr[k] = arr[k + 1];
                size--;     // �迭 ũ�� 1 ����
                j--;
            }
        }
    }
    return size;
}
