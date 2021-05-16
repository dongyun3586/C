﻿#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <math.h>       // double pow( double base, double exponent ), double sqrt( double arg );
#include <time.h>

void generateRandomNum(double arr[], int length);
void print1DArray(double arr[], int length);
double calculateSD(double arr[], int length);

#define ARRAY_LENGTH 20

int main() {
    double numArr[ARRAY_LENGTH];
    int length = sizeof(numArr) / sizeof(numArr[0]);    // 배열의 크기

    // 랜덤 배열 생성
    printf("0~100 사이의 랜덤 숫자 %d개 생성\n", ARRAY_LENGTH);
    generateRandomNum(numArr, length);

    // 배열 출력
    print1DArray(numArr, length);

    // 표준 편차 출력
    printf("표준 편차 = %.2f\n", calculateSD(numArr, length));
    return 0;
}

// 랜덤 배열 생성 함수
void generateRandomNum(double arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = (double)rand() / RAND_MAX * 100;
    }
}

// 1차원 배열 출력 함수
void print1DArray(double arr[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%.2f\n", arr[i]);
    printf("\n");
}

// 표준편차 계산 함수
double calculateSD(double arr[], int length) {
    double sum = 0.0, mean, SD = 0.0;

    // 평균 계산
    for (int i = 0; i < length; i++)
        sum += arr[i];
    mean = sum / length;
    printf("평균: %.2f\n", mean);

    // 표준편차 계산
    for (int i = 0; i < length; i++)
        SD += pow(arr[i] - mean, 2);
    SD /= length;
    printf("분산: %0.2f\n", SD);
    SD = sqrt(SD);

    return SD;
}