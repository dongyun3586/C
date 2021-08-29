#include <stdio.h>
#include<string.h>

#define STRLEN 14

int main(void)
{
    char* src = "Take the test.";
    char dst[STRLEN + 1];   // +1 to accomodate for the null terminator

    strcpy(dst, src);
    dst[0] = 'M';
    printf("src = %s\ndst = %s\n", src, dst);

    src = malloc(sizeof(char) * 15);
    strcpy(src, "Hello world");
    printf("%s\n", src);
    free(src);
}