#include <stdio.h>
int myStrlen(const char* str);

int main(void)
{
    char str[] = "Hello world";
    printf("%s의 문자열 길이 : %d\n", str, myStrlen(str));
}

// myStrlen( ) 함수 정의
int myStrlen(const char* str) {
    int l = 0;
    while (str[l] != '\0')
        l++;
    return l;
}

