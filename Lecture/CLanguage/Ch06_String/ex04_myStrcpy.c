#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myStrcpy(char* dest, const char* src);

void main()
{
    char str1[100] = "Copy one string into another string.", str2[100] = "";

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);

    printf("\n*** str1를 str2에 복제 ***\n\n");
    int numberOfCharactersCopied = myStrcpy(str2, str1);

    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    printf("\n복제한 문자 수 : %d\n\n", numberOfCharactersCopied);
}

int myStrcpy(char* dest, const char* src) {
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return i;
}