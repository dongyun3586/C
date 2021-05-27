#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int array[], int position);

int main()
{
    int array[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int position, c, length = 10;

    // 배열의 초기 상태 출력 
    print1DArray(array, length);

    // 배열에 새로운 요소 삽입 및 출력
    for (int i = 0; i < 2; i++) {
        insertElement(array, length++);      // 배열에 새로운 요소 삽입
        print1DArray(array, length);         // 배열 출력 
    }

    return 0;
}

void print1DArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int array[], int length)
{
    // 필요한 변수 선언
    int position, insertValue;

    // 필요한 값 입력받기
    printf("위치와 새로운 값 입력: ");
    scanf("%d %d", &position, &insertValue);

    // 처리 
    // 1. 들어갈 위치 이후의 요소가 모두 오른쪽으로 이동
    for (int i = length - 1; i >= position - 1; i--)
        array[i + 1] = array[i];

    // 2. 새로운 값 배열에 추가
    array[position - 1] = insertValue;
}