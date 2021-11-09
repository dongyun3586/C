#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(32767)
#include <time.h>
#include <string.h>

typedef struct {
    int num;
    int fre;
} Num;

void generateRandomNum(Num* numArr, int n);
void print1DArray(Num* numArr, int n);
void checkEqualValueInArray(Num* numArr, int n);
void printFrequencyInArray(Num* arr, int n);
void sortArray(Num arr[], int n);

int main()
{
    int n;
    printf("배열에 저장할 요소(elements)의 수: ");
    scanf("%d", &n);

    /*Num* numArr = (Num*)malloc(sizeof(Num) * n);
    memset(numArr, 0, sizeof(Num)*n);*/
    Num* numArr = (Num*)calloc(n, sizeof(Num));

    // 1. numArr[]에 n만큼 1~10 사이의 랜덤 숫자 채우기
    generateRandomNum(numArr, n);

    // 2. numArr[]의 초기 상태 출력
    print1DArray(numArr, n);

    // 3. numArr[] 값을 검사하여 freqArr[]에 빈도수 기록
    checkEqualValueInArray(numArr, n);

    // 4. numArr[]의 빈도수 출력
    printFrequencyInArray(numArr, n);

    // 5. 숫자 오름차순으로 정렬
    sortArray(numArr, n);

    // 4. numArr[]의 빈도수 출력
    printFrequencyInArray(numArr, n);

    return 0;
}

void generateRandomNum(Num* arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i].num = rand() % 10 + 1;
    }
}

void print1DArray(Num* arr, int n) {
    printf("1차원 배열 출력\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].num);
    printf("\n");
}

void checkEqualValueInArray(Num* arr, int n) {
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        if (arr[i].fre != 0)
            continue;
        for (int j = i; j < n; j++)
        {
            if (arr[i].num == arr[j].num) {
                count++;
                arr[j].fre = -1;
            }
        }
        arr[i].fre = count;
    }
}

void printFrequencyInArray(Num* arr, int n) {
    printf("\n배열 요소들의 빈도수\n");
    for (int i = 0; i < n; i++)
        if (arr[i].fre > 0)
            printf("%2d : %2d번\n", arr[i].num, arr[i].fre);
}

void sortArray(Num arr[], int n) {
    printf("\n*** 오름차순 정렬 ***\n");
    Num temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j].num > arr[j + 1].num) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}