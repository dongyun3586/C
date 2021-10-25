#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <ctype.h>

void generateRandomNum(char arr[], int n);
void printArray(char arr[], int n);
void bubbleSort(char arr[], int n, char* order, int(*fp)(char, char));
int ascendCompare(char a, char b);
int descendCompare(char a, char b);

int main()
{
    char numArr[10];
    int n = sizeof(numArr) / sizeof(char);

    // 랜덤 알파벳(소문자만) 생성
    generateRandomNum(numArr, n);

    // 초기 배열 상태 출력
    printf("정렬 전: ");
    printArray(numArr, n);

    // 오름차순 정렬
    printf("\n정렬 방법(오름차순=a, 내림차순=d) : ");
    char choice = getchar();
    if (choice == 'a')
        bubbleSort(numArr, n, "오름차순 정렬", ascendCompare);
    else if (choice == 'd')
        bubbleSort(numArr, n, "내림차순 정렬", descendCompare);

    // 정렬된 배열
    printf("\n정렬 후: ");
    printArray(numArr, n);

    return 0;
}

void generateRandomNum(char* arr, int n)
{
    srand(time(NULL));
    char ch;
    for (int i = 0; i < n; i++) {
        do {
            ch = rand() % 128;
        } while (isalpha(ch) == 0);
        arr[i] = tolower(ch);
    }
}

void printArray(char* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%c", *arr++);
    printf("\n");
}

void bubbleSort(char arr[], int n, char* order, int(*comparer)(char, char))
{
    printf("\n<%s>\n", order);
    int temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (comparer(arr[j], arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("%d단계 : ", i);
        printArray(arr, n);
    }
}

int ascendCompare(char a, char b) {
    if (a > b)
        return 1;
    else
        return 0;
}

int descendCompare(char a, char b) {
    if (a < b)
        return 1;
    else
        return -1;
}