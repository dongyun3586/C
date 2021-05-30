#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

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
        if (freq[i] == 0)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("배열 요소들의 빈도수\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != -1)
            printf("%3d : %3d번 ", arr[i], freq[i]);
}

int deleteDuplicateElements(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
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