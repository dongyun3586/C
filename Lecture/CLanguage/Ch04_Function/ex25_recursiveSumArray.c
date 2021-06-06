#include <stdio.h>
int sum(int arr[], int start, int len);

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int N = sizeof(arr) / sizeof(int);

    printf("배열의 요소들의 합: %d\n", sum(arr, 0, N));

    return 0;
}

int sum(int arr[], int start, int len)
{
    if (start == len)
        return 0;
    return arr[start] + sum(arr, start + 1, len);
}