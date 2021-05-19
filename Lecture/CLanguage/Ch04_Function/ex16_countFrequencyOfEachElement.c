#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

void print1DArray(int arr[], int length);

int main()
{
    int numArr[10000], freq[10000];
    int size, count;

    printf("배열의 크기: ");
    scanf("%d", &size);

    // 배열에 1~10 사이의 랜덤 값 채우기
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        numArr[i] = rand() % 10 + 1;
        freq[i] = -1;
    }

    print1DArray(numArr, size);

    // 빈도수 기록하기
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (numArr[i] == numArr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("\n배열 요소들의 빈도수\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != 0)
            printf("%2d : %4d 번\n", numArr[i], freq[i]);

    return 0;
}

void print1DArray(int arr[], int length) {
    printf("1차원 배열 출력\n");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

