#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myStrlen(const char* str);
int myStrcpy(char* dest, const char* src);
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

int myStrlen(const char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int myStrcpy(char* dest, const char* src) {
    if (dest == NULL) return -1;
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return i;
}

char* myStrcat(char* dest, const char* src) {
    int lastIndex = myStrlen(dest);
    myStrcpy(&dest[lastIndex], src);

   /* int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[lastIndex + i] = src[i];
    dest[lastIndex + i] = '\0';*/

    return dest;
}