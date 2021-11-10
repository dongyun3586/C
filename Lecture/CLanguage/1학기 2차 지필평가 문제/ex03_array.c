#include <stdio.h>
#define SIZE 3
int func(int arr[], int n) {
    n *= 2;
    for (int i = 0; i < SIZE; i++)
        arr[i] *= 10;
    return n;
}
int main()
{
    int arr[3] = { 1,2,3 }, n;
    n = 5;

    printf("n=%d\n", func(arr, n));
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    return 0;
}