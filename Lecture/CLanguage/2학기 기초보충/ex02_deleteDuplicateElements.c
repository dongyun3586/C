#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int n);
void print1DArray(int arr[], int n);
int deleteDuplicateElements(int arr[], int n);

int main()
{
    int numArr[100];
    int n;

    printf("�������� ���� ����: ");
    scanf("%d", &n);

    // ���� �迭 ����
    printf("1~50 ������ ���� ���� �迭 ����\n");
    generateRandomNum(numArr, n);

    // �迭 �ʱ� ���� ���
    print1DArray(numArr, n);

    // �迭�� �ߺ��Ǵ� ��� ����
    n = deleteDuplicateElements(numArr, n);

    // �迭 �ߺ� ���� ���� ���
    print1DArray(numArr, n);

    return 0;
}

// ���� �迭 ���� �Լ�
void generateRandomNum(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }
}

void print1DArray(int arr[], int n) {
    printf("\n�迭 ũ��: %d\n", n);
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}

int deleteDuplicateElements(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // �ߺ��� üũ
            if (arr[i] == arr[j])
            {
                // �ߺ��� ���� 
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;            // �迭 ũ�� 1 ����
                j--;            // ���� ��ġ�� ��Һ��� �ٽ� üũ
            }
        }
    }
    return n;
}