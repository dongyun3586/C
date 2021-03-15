#include <stdio.h>
#include <limits.h>  // 자료형의 최댓값과 최솟값이 정의된 헤더 파일

int main_IntegerType() {
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
    return 0;
}

//CHAR_BIT:   8
//CHAR_MAX : 127
//CHAR_MIN : -128
//INT_MAX : 2147483647
//INT_MIN : -2147483648
//LONG_MAX : 2147483647
//LONG_MIN : -2147483648
//SCHAR_MAX : 127
//SCHAR_MIN : -128
//SHRT_MAX : 32767
//SHRT_MIN : -32768
//UCHAR_MAX : 255
//UINT_MAX : 4294967295
//ULONG_MAX : 4294967295
//USHRT_MAX : 65535