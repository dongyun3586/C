#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(32767)
#include <time.h>

void generateRandomNum(int numArr[], int length);
void print1DArray(int arr[], int length);
void checkEqualValueInArray(int numArr[], int freqArr[], int length);
void printFrequencyInArray(int numArr[], int freqArr[], int length);

int main()
{
    int numArr[100] = { 0 }, freqArr[100] = { 0 };
    int length;

    printf("�迭�� ������ ���(elements)�� ��: ");
    scanf("%d", &length);

    // 1. numArr[]�� length��ŭ 1~10 ������ ���� ���� ä���
    generateRandomNum(numArr, length);

    // 2. numArr[]�� �ʱ� ���� ���
    print1DArray(numArr, length);

    // 3. numArr[] ���� �˻��Ͽ� freqArr[]�� �󵵼� ���
    checkEqualValueInArray(numArr, freqArr, length);

    // 4. numArr[]�� �󵵼� ���
    printFrequencyInArray(numArr, freqArr, length);

    return 0;
}

void generateRandomNum(int numArr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        numArr[i] = rand() % 10 + 1;
    }
}

void print1DArray(int arr[], int length) {
    printf("1���� �迭 ���\n");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void checkEqualValueInArray(int numArr[], int freqArr[], int length) {
    int count;
    for (int i = 0; i < length; i++)
    {
        count = 1;
        for (int j = i + 1; j < length; j++)
        {
            if (numArr[i] == numArr[j]) {
                count++;
                freqArr[j] = -1;
            }
        }
        if (freqArr[i] == 0)
            freqArr[i] = count;
    }
}

void printFrequencyInArray(int numArr[], int freqArr[], int length) {
    printf("\n�迭 ��ҵ��� �󵵼�\n");
    for (int i = 0; i < length; i++)
        if (freqArr[i] > 0)
            printf("%2d : %4d ��\n", numArr[i], freqArr[i]);
}