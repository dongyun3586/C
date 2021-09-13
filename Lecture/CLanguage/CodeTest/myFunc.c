#include<stdio.h>

int myStrlen(const char* str) {
    int l = 0;
    while (str[l] != '\0')
        l++;
    return l;
}

int myStrcpy(char* dest, const char* src) {
    if (dest == NULL) return -1;
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return i;
}