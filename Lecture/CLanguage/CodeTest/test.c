#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 
// ① removeLeading( ) 함수 [8점]



// ② removeTrailing( ) 함수 [8점]



int main()
{
    char str[MAX_SIZE];
    printf("문자열 입력: ");
    gets(str);

    printf("입력된 문자열: '%s'\n", str);
    removeLeading(str);
    printf("앞쪽 공백 제거: '%s'\n", str);
    removeTrailing(str);
    printf("뒷쪽 공백 제거: '%s'\n", str);
    return 0;
}