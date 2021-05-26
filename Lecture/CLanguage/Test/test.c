#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int length);
void print1DArray(int arr[], int length);
void bubbleSortAscending(int arr[], int length);
void countFrequencyElements(int arr[], int freq[], int length);
int deleteDuplicateElements(int arr[], int length);

int main()
{
    int numArr[100], freq[100] = { 0 };
    int length = sizeof(numArr) / sizeof(int);

    // 1. 1~100 사이의 랜덤 숫자 배열 생성
    generateRandomNum(numArr, length);

    // 2. 초기 배열 상태 출력
    print1DArray(numArr, length);

    // 3. 오름차순 정렬
    bubbleSortAscending(numArr, length);

    // 4. 정렬된 배열 상태 출력
    printf("정렬 후 배열 상태\n");
    print1DArray(numArr, length);

    // 5. 중복된 요소의 개수 출력
    countFrequencyElements(numArr, freq, length);

    // 6. 배열에서 중복 요소 제거
    length = deleteDuplicateElements(numArr, length);

    // 7. 중복 요소 제거 후 배열 상태 출력
    print1DArray(numArr, length);

    return 0;
}

// 1~10 사이의 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print1DArray(int arr[], int length) {
    printf("초기 배열의 크기 : %d\n", length);
    for (int i = 0; i < length; i++)
        printf("%3d ", arr[i]);
    printf("\n\n");
}

void countFrequencyElements(int arr[], int freq[], int length) {
    int count;

    // 빈도수 기록하기
    for (int i = 0; i < length; i++)
    {
        count = 1;
        for (int j = i + 1; j < length; j++)
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
    for (int i = 0; i < length; i++) {
        if (freq[i] != -1)
            printf("%3d : %3d번 ", arr[i], freq[i]);
    }
    printf("\n");
        
}

int deleteDuplicateElements(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            // 중복된 요소를 발견하면
            if (arr[i] == arr[j])
            {
                // 중복된 요소 배열에서 제거 
                for (int k = j; k < length - 1; k++)
                    arr[k] = arr[k + 1];
                length--;     // 배열 크기 1 감소
                j--;
            }
        }
    }
    return length;
}

void bubbleSortAscending(int arr[], int length)
{
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
