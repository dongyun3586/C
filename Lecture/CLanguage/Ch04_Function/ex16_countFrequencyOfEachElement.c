#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

int main()
{
    int arr[10000], freq[10000];
    int size, count;

    srand(time(NULL));
    printf("배열의 크기: ");
    scanf("%d", &size);

    // 배열에 1~10 사이의 랜덤 값 채우기
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10 + 1;
        freq[i] = -1;
    }

    // 빈도수 기록하기
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            /* If duplicate element is found */
            if (arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }

        /* If frequency of current element is not counted */
        if (freq[i] != 0)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("\n배열 요소들의 빈도수\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != 0)
            printf("%2d : %4d 번\n", arr[i], freq[i]);

    return 0;
}

