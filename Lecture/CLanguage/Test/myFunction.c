#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

// 1~10 ������ ���� �迭 ���� �Լ�
void generateRandomNum(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%3d ", arr[i]);
    printf("\n\n");
}

void countFrequencyElements(int arr[], int freq[], int size) {
    int count;

    // �󵵼� ����ϱ�
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = -1;
            }
        }
        if (freq[i] == 0)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("�迭 ��ҵ��� �󵵼�\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != -1)
            printf("%3d : %3d�� ", arr[i], freq[i]);
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

void bubbleSortAscending(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}