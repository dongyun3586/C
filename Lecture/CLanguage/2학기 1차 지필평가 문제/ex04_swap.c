#include <stdio.h>

void swap(int* a, int* b);
void swapArr(char** arr1, char** arr2);

int main()
{
    int a = 10, b = 20;
    char* strArr[] = { "Apple", "Samsung" };

    char* p1 = strArr[0];
    char* p2 = strArr[1];

    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    printf("p1=%s, p2=%s\n", p1, p2);
    swapArr(&p1, &p2);
    printf("p1=%s, p2=%s\n", p1, p2);

    return 0;
}

// ① swap( ) 함수 정의 [8점]
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ② swapArr( ) 함수 정의 [8점]
void swapArr(char** arr1, char** arr2) {
    int* temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}