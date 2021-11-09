#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(32767)
#include <time.h>

void generateRandomNum(int numArr[], int n);
void print1DArray(int arr[], int n);
void checkEqualValueInArray(int numArr[], int freqArr[], int n);
void printFrequencyInArray(int numArr[], int freqArr[], int n);

int main()
{
    int numArr[100] = { 0 }, freqArr[100] = { 0 };
    int n;

    printf("�迭�� ������ ���(elements)�� ��: ");
    scanf("%d", &n);

    // 1. numArr[]�� n��ŭ 1~10 ������ ���� ���� ä���
    generateRandomNum(numArr, n);

    // 2. numArr[]�� �ʱ� ���� ���
    print1DArray(numArr, n);

    // 3. numArr[] ���� �˻��Ͽ� freqArr[]�� �󵵼� ���
    checkEqualValueInArray(numArr, freqArr, n);

    // 4. numArr[]�� �󵵼� ���
    printFrequencyInArray(numArr, freqArr, n);

    return 0;
}

void generateRandomNum(int numArr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        numArr[i] = rand() % 10 + 1;
    }
}

void print1DArray(int arr[], int n) {
    printf("1���� �迭 ���\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void checkEqualValueInArray(int numArr[], int freqArr[], int n) {
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        if (freqArr[i] != 0)
            continue;
        for (int j = i; j < n; j++)
        {
            if (numArr[i] == numArr[j]) {
                count++;
                freqArr[j] = -1;
            }
        }
        freqArr[i] = count;
    }
}

void printFrequencyInArray(int numArr[], int freqArr[], int n) {
    printf("\n�迭 ��ҵ��� �󵵼�\n");
    for (int i = 0; i < n; i++)
        if (freqArr[i] > 0)
            printf("%2d : %2d��\n", numArr[i], freqArr[i]);
}