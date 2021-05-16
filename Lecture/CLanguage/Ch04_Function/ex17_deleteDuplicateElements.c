#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int size);
void print1DArray(int arr[], int length);

int main()
{
    int arr[1000];
    int size;

    printf("배열의 크기: ");
    scanf("%d", &size);

    // 랜덤 배열 생성
    printf("1~50 사이의 랜덤 숫자 배열 생성\n");
    generateRandomNum(arr, size);

    // 초기 배열 상태 출력
    print1DArray(arr, size);

    // Find duplicate elements in array
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

    // 중복 요소 제거 후 배열
    printf("\n배열 크기: %d\n", size);
    print1DArray(arr, size);

    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1;
    }
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
