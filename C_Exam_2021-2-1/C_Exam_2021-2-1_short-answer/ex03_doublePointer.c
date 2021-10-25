#include <stdio.h>

int main()
{
    int arr[3][4] = { 0 };
    int r = sizeof(arr) / sizeof(arr[0]);   // r = 3
    int c = sizeof(arr[0]) / sizeof(int);   // c = 4
    int n = sizeof(arr) / sizeof(int);      // n = 12

    for (int i = 0; i < r; i++)             // 0 < 3
        for (int j = 0; j < c; j++)         // 0 < 4
            arr[i][j] = i * c + j + 1;

    for (int i = 0; i < n; i++)             // 0 < 12
        printf("%d ", *(*arr + i));         // arr[0]
    printf("\n");
    return 0;
}