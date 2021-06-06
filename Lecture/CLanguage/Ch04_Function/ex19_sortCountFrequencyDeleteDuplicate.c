#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int size);
void print1DArray(int arr[], int length);
void bubbleSortAscending(int arr[], int size);
void countFrequencyElements(int arr[], int freq[], int size);
int deleteDuplicateElements(int arr[], int size);

int main()
{
    int numArr[100], freq[100] = { 0 };
    int size = sizeof(numArr) / sizeof(int);

    // 랜덤 배열 생성
    generateRandomNum(numArr, size);

    // 초기 배열 상태 출력
    printf("초기 배열의 크기 : %d\n", size);
    print1DArray(numArr, size);

    // 오름차순 정렬
    bubbleSortAscending(numArr, size);

    // 정렬된 배열 상태 출력
    printf("정렬 후 배열 상태\n");
    print1DArray(numArr, size);

    // 중복된 요소의 개수 출력
    countFrequencyElements(numArr, freq, size);

    // 배열에서 중복 요소 제거
    size = deleteDuplicateElements(numArr, size);

    // 중복 요소 제거 후 배열 상태 출력
    printf("\n\n중복 요소를 제거한 배열의 크기: %d\n", size);
    print1DArray(numArr, size);
    return 0;
}

// 1~10 사이의 랜덤 배열 생성 함수
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

void bubbleSortAscending(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void countFrequencyElements(int arr[], int freq[], int size) {
    int count;

    // 빈도수 기록하기
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
        if (freq[i] != -1)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("\n배열 요소들의 빈도수\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != -1)
            printf("%3d : %3d번 ", arr[i], freq[i]);
}

int deleteDuplicateElements(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // 중복된 요소를 발견하면
            if (arr[i] == arr[j])
            {
                // 중복된 요소 배열에서 제거 
                for (int k = j; k < size - 1; k++)
                    arr[k] = arr[k + 1];
                size--;     // 배열 크기 1 감소
                j--;
            }
        }
    }
    return size;
}


