#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int arr[], int length);

int main()
{
    int numArr[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int length = 10;

    // 배열 출력 
    print1DArray(numArr, length);

    for (int i = 0; i < 2; i++) {
        insertElement(numArr, length++);      // 배열에 새로운 요소 삽입
        print1DArray(numArr, length);         // 배열 출력 
    }

    return 0;
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int length)
{
    int insertValue, position;

    printf("\n위치와 새로운 값 입력:  ");
    scanf("%d %d", &position, &insertValue);

    // position부터 length까지의 요소 오른쪽으로 한칸씩 옮기기
    for (int i = length - 1; i >= position - 1; i--)
        arr[i + 1] = arr[i];

    // position 위치에 insertValue 넣기
    arr[position - 1] = insertValue;
}