#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int myStrlen(const char* str);
//int myStrcpy(char* dest, const char* src);
char* myStrcat(char* dest, const char* src);

int main()
{
    char str1[100] = "Let's ";
    char str2[100] = "go!!!";
    printf("str1 : %s\n", str1);

    if (myStrcat(str1, str2) == NULL) return -1;
    printf("str1 : %s\n", str1);

    return 0;
}

// 함수들 정의
char* myStrcat(char* dest, const char* src) {
    if (dest == NULL) return NULL;
    int len = myStrlen(dest);
    myStrcpy(&dest[len], src);
}
