#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void print1DArray(int arr[], int length);

int main()
{
    int numArr[10000], freq[10000];
    int size, count;

    printf("�迭�� ũ��: ");
    scanf("%d", &size);

    // �迭�� 1~10 ������ ���� �� ä���
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        numArr[i] = rand() % 10 + 1;
        freq[i] = -1;
    }

    print1DArray(numArr, size);

    // �󵵼� ����ϱ�
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (numArr[i] == numArr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("\n�迭 ��ҵ��� �󵵼�\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != 0)
            printf("%2d : %4d ��\n", numArr[i], freq[i]);

    return 0;
}

void print1DArray(int arr[], int length) {
    printf("1���� �迭 ���\n");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

