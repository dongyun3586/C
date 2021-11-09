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

    printf("배열에 저장할 요소(elements)의 수: ");
    scanf("%d", &n);

    // 1. numArr[]에 n만큼 1~10 사이의 랜덤 숫자 채우기
    generateRandomNum(numArr, n);

    // 2. numArr[]의 초기 상태 출력
    print1DArray(numArr, n);

    // 3. numArr[] 값을 검사하여 freqArr[]에 빈도수 기록
    checkEqualValueInArray(numArr, freqArr, n);

    // 4. numArr[]의 빈도수 출력
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
    printf("1차원 배열 출력\n");
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
    printf("\n배열 요소들의 빈도수\n");
    for (int i = 0; i < n; i++)
        if (freqArr[i] > 0)
            printf("%2d : %2d번\n", numArr[i], freqArr[i]);
}