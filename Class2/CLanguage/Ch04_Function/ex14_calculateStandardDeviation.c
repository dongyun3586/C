#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <math.h>       // double pow( double base, double exponent ), double sqrt( double arg );
#include <time.h>

void generateRandomNum(double arr[], int length);
void print1DArray(double arr[], int length);
double calculateSD(double arr[], int length);

#define ARRAY_LENGTH 20

int main() {
    double numArr[ARRAY_LENGTH];
    int length = sizeof(numArr) / sizeof(numArr[0]);    // �迭�� ũ��

    // ���� �迭 ����
    printf("0~100 ������ ���� ���� %d�� ����\n", ARRAY_LENGTH);
    generateRandomNum(numArr, length);

    // �迭 ���
    print1DArray(numArr, length);

    // ǥ�� ���� ���
    printf("ǥ�� ���� = %.5f\n", calculateSD(numArr, length));
    return 0;
}

// ���� �迭 ���� �Լ�
void generateRandomNum(double arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = (double)rand() / RAND_MAX * 100;
    }
}

// 1���� �迭 ��� �Լ�
void print1DArray(double arr[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%.2f\n", arr[i]);
    printf("\n");
}

// ǥ������ ��� �Լ�
double calculateSD(double arr[], int length) {
    double sum = 0.0, mean, sd = 0.0;
    // ���
    for (int i = 0; i < length; i++)
        sum += arr[i];
    mean = sum / length;
    printf("���: %lf\n", mean);

    // �л�
    for (int i = 0; i < length; i++)
        sd += pow(arr[i] - mean, 2);
    sd /= length;
    printf("�л�: %lf\n", sd);

    // ǥ�������� return
    return sqrt(sd);
}