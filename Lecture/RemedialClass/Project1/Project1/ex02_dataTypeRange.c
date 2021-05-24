#include <stdio.h>
#include <limits.h>  // 자료형의 최댓값과 최솟값이 정의된 헤더 파일
#include <float.h>

int main() {
    printf("\nStorage size for char : %d \n", sizeof(char));
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);

    printf("\nStorage size for short : %d \n", sizeof(short));
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);

    printf("\nStorage size for int : %d \n", sizeof(int));
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);

    printf("\nStorage size for long : %d \n", sizeof(long));
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);

    printf("\nStorage size for float : %d \n", sizeof(float));
    printf("FLT_MIN     :   %f\n", (float)FLT_MIN);
    printf("FLT_MAX     :   %f\n", (float)FLT_MAX);
    printf("-FLT_MIN    :   %f\n", (float)-FLT_MIN);
    printf("-FLT_MAX    :   %f\n", (float)-FLT_MAX);

    printf("\nStorage size for double : %d \n", sizeof(double));
    printf("DBL_MIN     :   %lf\n", (double)DBL_MIN);
    printf("DBL_MAX     :   %lf\n", (double)DBL_MAX);
    printf("-DBL_MAX     :  %lf\n", (double)-DBL_MAX);

    return 0;
}