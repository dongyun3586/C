#include <stdio.h>
#include <string.h>

void main()
{
    char filename[100];
    char s[100];

    for (int i = 1; i <= 10; i++) {
        strcpy(filename, "image");      // "image" ÃÊ±âÈ­
        sprintf(s, "%02d", i);
        strcat(filename, s);
        strcat(filename, ".jpg");
        printf("%s\n", filename);
    }

    return 0;
}