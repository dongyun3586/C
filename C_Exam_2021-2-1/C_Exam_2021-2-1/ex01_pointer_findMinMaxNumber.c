#include <stdio.h>
#define ARR_SIZE 10
void getMinMax(int* numbers, int* min, int* max);

int main()
{
    int arr[ARR_SIZE] = { 41, 67, 34, 90, 69, 24, 78, 58, 62, 64 };
    int min, max;

    getMinMax(arr, &min, &max);
    printf("ÃÖ¼Ú°ª: %d\n", min);
    printf("ÃÖ´ñ°ª: %d\n", max);

    return 0;
}

void getMinMax(int* numbers, int* min, int* max)
{
    *min = *max = *numbers;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (*min > numbers[i]) *min = numbers[i];
        if (*max < numbers[i]) *max = numbers[i];
    }
}



/*if (*(min) > *(numbers + i))
    *min = *(numbers + i);

if (*(max) < *(numbers + i))
    *max = *(numbers + i);*/