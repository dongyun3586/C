#include<stdio.h>

void print1DArray(int arr[], int length);
void insertElement(int array[], int position);

int main()
{
    int array[100] = { 1,2,3,4,5,6,7,8,9,10 };
    int position, c, length = 10, insertValue;

    // 배열 출력 
    print1DArray(array, length);

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
    int insertValue, position;

    printf("\n새로운 값과 위치 입력:  ");
    scanf("%d %d", &insertValue, &position);

    // position부터 length까지의 요소 오른쪽으로 한칸씩 옮기기
    for (int i = length - 1; i >= position - 1; i--)
        array[i + 1] = array[i];

    // position 위치에 insertValue 넣기
    array[position - 1] = insertValue;
}