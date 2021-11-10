#include <stdio.h>
#define SIZE 10
int bsearch(int arr[], int length, int findNum);

int main()
{
    int findNum, index;
    int numArr[] = { 3, 6, 7, 8, 11, 13, 16, 17, 18, 20 };

    printf("찾을 값: ");
    scanf("%d", &findNum);
    if (           가            )
        printf("%d은 배열의 %d 번째 위치\n", findNum, index + 1);
    else
        printf("%d은 배열에 없습니다.\n", findNum);
    return 0;
}

int bsearch(int arr[], int length, int findNum) {
    int low = 0, high = length - 1, mid, count = 0;
    while (low <= high) {
        printf("[%d %d]\n", low, high);
        mid = (low + high) / 2;
        if (findNum == arr[mid]) {
            return mid;
        }
        else if (findNum > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}