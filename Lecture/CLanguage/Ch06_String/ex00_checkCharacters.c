#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 

void main()
{
    char str[str_size] = "Count total number of alphabets, digits and special characters";
    int alp, digit, splch, i;
    alp = digit = splch = i = 0;

    /*printf("Input the string : ");
    fgets(str, sizeof(str), stdin);*/

    /* 문자열의 문자 검사*/
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            alp++;
        else if (str[i] >= '0' && str[i] <= '9')
            digit++;
        else
            splch++;
        i++;
    }

    printf("문자열 안의 알파벳 : %d\n", alp);
    printf("문자열 안의 숫자 : %d\n", digit);
    printf("문자열 안의 특수문자 : %d\n", splch);
}