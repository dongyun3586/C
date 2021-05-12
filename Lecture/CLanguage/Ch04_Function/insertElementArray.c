#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int array[], int n);

int main()
{
    int array[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int position, c, n = 10, insertValue;

    // 배열 출력 
    print1DArray(array, n);

    // 배열에 새로운 요소 삽입
    insertElement(array, n++);

    // 배열 출력 
    print1DArray(array, n);

    return 0;
}

void print1DArray(int arr[], int length) {
    printf("1차원 배열 출력\n");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int array[], int n)
{
    int position, c, insertValue;

    printf("\n\n삽입을 원하는 위치와 값은?  ");
    scanf("%d %d", &position, &insertValue);

    // position부터 n까지이 요소 오른쪽으로 옮기기
    for (c = n - 1; c >= position - 1; c--)
        array[c + 1] = array[c];

    // position 위치에 insertValue 넣기
    array[position - 1] = insertValue;
}