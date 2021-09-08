#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char str[100]; /* Declares a string of size 100 */
    int l, i;

    printf("입력된 문자열 : ");
    //fgets(str, sizeof str, stdin);
    gets(str);
    l = strlen(str);

    printf("뒤집힌 문자열 : ");
    for (i = l; i >= 0; i--)
        printf("%c", str[i]);

    printf("\n");
}