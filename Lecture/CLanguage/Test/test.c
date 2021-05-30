#include <stdio.h>

#define SIZE 3 // Size of the matrix

void print2DArray(int arr[][SIZE], int row, int column);
void addMatrices(int A[][SIZE], int B[][SIZE], int C[][SIZE]);
void subtractMatrices(int A[][SIZE], int B[][SIZE], int C[][SIZE]);
void multiplyMatrices(int A[][SIZE], int B[][SIZE], int C[][SIZE]);

int main()
{
    int A[SIZE][SIZE] = { 1,2,3,4,5,6,7,8,9 };
    int B[SIZE][SIZE] = { 9,8,7,6,5,4,3,2,1 };
    int C[SIZE][SIZE] = { 0 };

    int row, col, i, sum;

    // 행렬 A와 B 출력
    printf("행렬 A\n");
    print2DArray(A, SIZE, SIZE);
    printf("행렬 B\n");
    print2DArray(B, SIZE, SIZE);

    // 행렬의 덧셈
    addMatrices(A, B, C);
    printf("행렬 A, B의 덧셈 결과\n");
    print2DArray(C, SIZE, SIZE);

    // 행렬의 뺄셈
    subtractMatrices(A, B, C);
    printf("행렬 A, B의 뺄셈 결과\n");
    print2DArray(C, SIZE, SIZE);

    // 행렬의 곱셈
    multiplyMatrices(A, B, C);
    printf("행렬 A, B의 곱셈 결과\n");
    print2DArray(C, SIZE, SIZE);

    return 0;
}

void print2DArray(int arr[][SIZE], int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int A[][SIZE], int B[][SIZE], int C[][SIZE])
{
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            C[row][col] = A[row][col] + B[row][col];
    }
}

void subtractMatrices(int A[][SIZE], int B[][SIZE], int C[][SIZE])
{
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            C[row][col] = A[row][col] - B[row][col];
    }
}

void multiplyMatrices(int A[][SIZE], int B[][SIZE], int C[][SIZE])
{
    int sum;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            sum = 0;    // Multiply row of first matrix to column of second matrix and store sum of product of elements in sum.
            for (int i = 0; i < SIZE; i++)
                sum += A[row][i] * B[i][col];
            C[row][col] = sum;
        }
    }
}









