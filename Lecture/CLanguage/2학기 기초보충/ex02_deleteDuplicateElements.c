#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void generateRandomNum(int arr[], int n);
void print1DArray(int arr[], int n);
int deleteDuplicateElements(int arr[], int n);

int main()
{
    int numArr[100];
    int n;

    printf("랜덤숫자 생성 개수: ");
    scanf("%d", &n);

    // 랜덤 배열 생성
    printf("1~50 사이의 랜덤 숫자 배열 생성\n");
    generateRandomNum(numArr, n);

    // 배열 초기 상태 출력
    print1DArray(numArr, n);

    // 배열의 중복되는 요소 제거
    n = deleteDuplicateElements(numArr, n);

    // 배열 중복 제거 상태 출력
    print1DArray(numArr, n);

    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }
}

void print1DArray(int arr[], int n) {
    printf("\n배열 크기: %d\n", n);
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}

int deleteDuplicateElements(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // 중복값 체크
            if (arr[i] == arr[j])
            {
                // 중복값 제거 
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;            // 배열 크기 1 감소
                j--;            // 새로 배치된 요소부터 다시 체크
            }
        }
    }
    return n;
}