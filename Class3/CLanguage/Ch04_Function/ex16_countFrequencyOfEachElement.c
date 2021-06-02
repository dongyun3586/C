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

    printf("배열에 저장할 요소(elements)의 수: ");
    scanf("%d", &length);

    // 1. numArr[]에 length만큼 1~10 사이의 랜덤 숫자 채우기
    generateRandomNum(numArr, length);

    // 2. numArr[]의 초기 상태 출력
    print1DArray(numArr, length);

    // 3. numArr[] 값을 검사하여 freqArr[]에 빈도수 기록
    checkEqualValueInArray(numArr, freqArr, length);

    // 4. numArr[]의 빈도수 출력
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
    printf("1차원 배열 출력\n");
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
    printf("\n배열 요소들의 빈도수\n");
    for (int i = 0; i < length; i++)
        if (freqArr[i] > 0)
            printf("%2d : %4d 번\n", numArr[i], freqArr[i]);
}