#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100 

void generateRandomNum(int arr[], int length);
void printArray(char msg[], int arr[], int length);
int maximum(int array[], int index, int len);
int minimum(int array[], int index, int len);
void bubbleSort(int array[], int length);

int main()
{
    int array[SIZE], max, min;
    generateRandomNum(array, SIZE);
    printArray("초기 배열 상태", array, SIZE);
    bubbleSort(array, SIZE);
    printArray("정렬 후 배열 상태", array, SIZE);

    max = maximum(array, 0, SIZE);
    min = minimum(array, 0, SIZE);

    printf("Minimum element in array = %d\n", min);
    printf("Maximum element in array = %d\n", max);

    return 0;
}


void generateRandomNum(int arr[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++)
        arr[i] = rand() % 100 + 1;
}

void printArray(char msg[], int arr[], int length) {
    printf("%s\n", msg);
    for (int i = 0; i < length; i++)
        printf("%3d ", arr[i]);
    printf("\n\n");
}

void bubbleSort(int array[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int minimum(int array[], int index, int len)
{
    if (index == len - 1)
        return array[index];

    int min = minimum(array, index + 1, len);
    if (array[index] < min)
        return array[index];
    else
        return min;
}

int maximum(int array[], int index, int len)
{
    if (index == len - 1)
        return array[index];

    int max = maximum(array, index + 1, len);

    if (array[index] > max)
        return array[index];
    else
        return max;
}