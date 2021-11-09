#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX(32767)
#include <time.h>
#include <string.h>

typedef struct {
    int num;
    int fre;
} Num;

void generateRandomNum(Num* numArr, int n);
void print1DArray(Num* numArr, int n);
void checkEqualValueInArray(Num* numArr, int n);
void printFrequencyInArray(Num* arr, int n);
void sortArray(Num arr[], int n);

int main()
{
    int n;
    printf("�迭�� ������ ���(elements)�� ��: ");
    scanf("%d", &n);

    /*Num* numArr = (Num*)malloc(sizeof(Num) * n);
    memset(numArr, 0, sizeof(Num)*n);*/
    Num* numArr = (Num*)calloc(n, sizeof(Num));

    // 1. numArr[]�� n��ŭ 1~10 ������ ���� ���� ä���
    generateRandomNum(numArr, n);

    // 2. numArr[]�� �ʱ� ���� ���
    print1DArray(numArr, n);

    // 3. numArr[] ���� �˻��Ͽ� freqArr[]�� �󵵼� ���
    checkEqualValueInArray(numArr, n);

    // 4. numArr[]�� �󵵼� ���
    printFrequencyInArray(numArr, n);

    // 5. ���� ������������ ����
    sortArray(numArr, n);

    // 4. numArr[]�� �󵵼� ���
    printFrequencyInArray(numArr, n);

    return 0;
}

void generateRandomNum(Num* arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i].num = rand() % 10 + 1;
    }
}

void print1DArray(Num* arr, int n) {
    printf("1���� �迭 ���\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].num);
    printf("\n");
}

void checkEqualValueInArray(Num* arr, int n) {
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        if (arr[i].fre != 0)
            continue;
        for (int j = i; j < n; j++)
        {
            if (arr[i].num == arr[j].num) {
                count++;
                arr[j].fre = -1;
            }
        }
        arr[i].fre = count;
    }
}

void printFrequencyInArray(Num* arr, int n) {
    printf("\n�迭 ��ҵ��� �󵵼�\n");
    for (int i = 0; i < n; i++)
        if (arr[i].fre > 0)
            printf("%2d : %2d��\n", arr[i].num, arr[i].fre);
}

void sortArray(Num arr[], int n) {
    printf("\n*** �������� ���� ***\n");
    Num temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j].num > arr[j + 1].num) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}