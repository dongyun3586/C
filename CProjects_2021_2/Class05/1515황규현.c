#include<stdio.h>

void printArray(int(*arr)[50], int line, int row);
void printArrayf(float(*arr)[50], int line, int row);
int sumMatrix();
int mulMatrix();
int revMatrix();

int main() {
    int mod = 0;
    printf("*****1515 황규현*****\n");
    printf("행렬 계산 프로그램입니다.\n");
    printf("원하는 계산 모드를 선택해주세요\n");
    printf("1. 덧셈, 2. 곱셈, 3. 역행렬\n");
    printf("mod : ");
    scanf("%d", &mod);
    printf("\n");
    if (mod == 1) {
        sumMatrix();
    }
    else if (mod == 2) {
        mulMatrix();
    }
    else if (mod == 3) {
        revMatrix();
    }
    else {
        printf("잘못된 입력입니다.");
    }
    return 0;
}

int sumMatrix() {
    int a[50][50] = { 0 };
    int b[50][50] = { 0 };
    int sum[50][50] = { 0 };
    int line, row;
    int(*p)[50];

    printf("더할 두 행렬의 크기를 입력하세요(1~50)\n");
    printf("m*n\n");
    printf("m =");
    scanf("%d", &line);
    printf("n =");
    scanf("%d", &row);
    printf("첫 번째 행렬에 들어갈 정수들을 차례대로 입력해주세요\n");
    for (int i = 0; i < line; i++)
    {
        printf("%d행\n", i + 1);
        for (int j = 0; j < row; j++) {
            scanf("%d", &a[i][j]);
        }

    }
    printf("두 번째 행렬에 들어갈 정수들을 차례대로 입력해주세요\n");
    for (int k = 0; k < line; k++)
    {
        printf("%d행\n", k + 1);
        for (int l = 0; l < row; l++) {
            scanf("%d", &b[k][l]);
        }

    }
    for (int s = 0; s < line; s++)
    {
        for (int t = 0; t < row; t++) {
            sum[s][t] = a[s][t] + b[s][t];
        }
    }
    p = sum;
    printArray(p, line, row);
}

int mulMatrix()
{
    int a[50][50] = { 0 };
    int b[50][50] = { 0 };
    int c[50][50] = { 0 };
    int line, common, row;
    int(*p)[50] = c;

    printf("곱할 두 행렬의 크기를 입력하세요(1~50)\n");
    printf("m*n, n*l\n");
    printf("m =");
    scanf("%d", &line);
    printf("n =");
    scanf("%d", &common);
    printf("l =");
    scanf("%d", &row);
    printf("첫 번째 행렬에 들어갈 정수들을 차례대로 입력해주세요\n");
    for (int i = 0; i < line; i++)
    {
        printf("%d행\n", i + 1);
        for (int j = 0; j < common; j++) {
            scanf("%d", &a[i][j]);
        }

    }
    printf("두 번째 행렬에 들어갈 정수들을 차례대로 입력해주세요\n");
    for (int k = 0; k < common; k++)
    {
        printf("%d행\n", k + 1);
        for (int l = 0; l < row; l++) {
            scanf("%d", &b[k][l]);
        }
    }
    for (int i = 0; i < line; i++)

        for (int j = 0; j < row; j++)

            for (int k = 0; k < common; k++)

                c[i][j] += a[i][k] * b[k][j];


    printArray(p, line, row);
}

int revMatrix() {
    int a[2][2] = { 0 };
    float c[2][2] = { 0 };
    float(*p)[50] = c;
    printf("2*2 배열의 역행렬만 계산 가능합니다.\n");
    printf("행렬에 들어갈 정수들을 차례대로 입력해주세요\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%d행\n", i + 1);
        for (int j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }

    }
    float q = a[0][0];
    float w = a[0][1];
    float e = a[1][0];
    float r = a[1][1];
    float det = (q * r - w * e);
    if (det == 0) {
        printf("계산이 불가능한 행렬입니다.");
    }
    else {
        p[0][0] = r / det;
        p[0][1] = -(w / det);
        p[1][0] = -(e / det);
        p[1][1] = q / det;
        printArrayf(p, 2, 2);
    }
}

void printArray(int(*arr)[50], int line, int row) {
    for (int i = 0; i < line; i++) {

        printf("|");
        for (int j = 0; j < row; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("|");
        printf("\n");
    }
}
void printArrayf(float(*arr)[50], int line, int row) {
    for (int i = 0; i < line; i++) {

        printf("|");
        for (int j = 0; j < row; j++) {
            printf("%f  ", arr[i][j]);
        }
        printf("|");
        printf("\n");
    }
}