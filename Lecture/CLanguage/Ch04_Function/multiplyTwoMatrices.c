#include <stdio.h>

#define SIZE 3 // Size of the matrix

void print2DArray(int arr[][SIZE], int row, int column);

int main()
{
    int A[SIZE][SIZE]; // Matrix 1 
    int B[SIZE][SIZE]; // Matrix 2
    int C[SIZE][SIZE]; // Resultant matrix

    int row, col, i, sum;

    // A 행렬에 1~9 저장 
    printf("행렬 A\n");
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++)
            A[row][col] = row * 3 + col + 1;
    }
    print2DArray(A, SIZE, SIZE);

    // B 행렬에 9~1 저장 
    printf("행렬 B\n");
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++)
            B[row][col] = (SIZE - 1 - row) * 3 + (SIZE - 1 - col) + 1;
    }
    print2DArray(B, SIZE, SIZE);

    // Multiply both matrices A*B
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            sum = 0;    
            for (i = 0; i < SIZE; i++)
                sum += A[row][i] * B[i][col];
            C[row][col] = sum;
        }
    }
    printf("행렬 AB\n");
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

