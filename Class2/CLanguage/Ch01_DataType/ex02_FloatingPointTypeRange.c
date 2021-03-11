#include <stdio.h>
#include <float.h>

int main_ex02_FloatingPointTypeRange(int argc, char** argv) {
    printf("Storage size for float : %d \n", sizeof(float));
    printf("FLT_MAX     :   %f\n", (float)FLT_MAX);
    printf("FLT_MIN     :   %f\n", (float)FLT_MIN);
    printf("-FLT_MAX    :   %f\n", (float)-FLT_MAX);
    printf("-FLT_MIN    :   %f\n", (float)-FLT_MIN);

    printf("Storage size for double : %d \n", sizeof(double));
    printf("DBL_MAX     :   %f\n", (double)DBL_MAX);
    printf("DBL_MIN     :   %f\n", (double)DBL_MIN);
    printf("-DBL_MAX     :  %f\n", (double)-DBL_MAX);
    return 0;
}