#include <stdio.h>
#include <string.h>
void main() {
    char str[150];
    int i, j;

    // www.W3School.com
    printf("Alphabet 이외의 문자 제거하기\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);

    for (i = 0; str[i] != '\0'; ++i)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            for (j = i; str[j] != '\0'; ++j)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }

    /* for (i = 0; str[i] != '\0'; ++i)
     {
         if (!(isalpha(str[i])))
             strcpy(&str[i], &str[i + 1]);

     }*/

    printf("최종 문자열 : %s\n", str);
}