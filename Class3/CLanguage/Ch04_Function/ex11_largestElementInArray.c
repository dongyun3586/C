#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10], max;
    int arrCount = sizeof(arr) / sizeof(arr[0]);

    // 1. �迭�� 1~1000 ������ ������ ����
    srand(time(NULL));
    for (int i = 0; i < arrCount; i++)
        arr[i] = rand() % 1000 + 1;

    // 2. �迭�� ��� ��� ����ϱ�
    for (int i = 0; i < arrCount; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    // 3. �迭���� ���� ū �� ã��
    max = arr[0];

    // 4. �迭���� ���� ū �� ���
    printf("�迭���� ���� ū �� = %d\n", max);

    return 0;
}