#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int length);
void print1DArray(int arr[], int length);
int deleteDuplicateElements(int arr[], int length);

int main()
{
    int numArr[100];
    int length;

    printf("랜덤숫자 생성 개수: ");
    scanf("%d", &length);

    // 랜덤 배열 생성
    printf("1~50 사이의 랜덤 숫자 배열 생성\n");
    generateRandomNum(numArr, length);

    // 배열 초기 상태 출력
    print1DArray(numArr, length);

    // 배열의 중복되는 요소 제거
    length = deleteDuplicateElements(numArr, length);

    // 배열 중복 제거 상태 출력
    print1DArray(numArr, length);

    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++)
        arr[i] = rand() % 50 + 1;
}

void print1DArray(int arr[], int length) {
    printf("\n배열 크기: %d\n", length);
    for (int i = 0; i < length; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}

int deleteDuplicateElements(int arr[], int length)
{
    // 배열의 모든 요소 순회
    for (int i = 0; i < length - 1; i++) {
        // i와 중복 체크
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                // arr[j] 중복된 값 제거
                for (int k = j; k < length; k++)
                    arr[k] = arr[k + 1];
                length--;
                j--;
            }
        }
    }
    return length;
}