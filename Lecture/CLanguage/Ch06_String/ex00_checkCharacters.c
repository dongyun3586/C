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

    /* ���ڿ��� ���� �˻�*/
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

    printf("���ڿ� ���� ���ĺ� : %d\n", alp);
    printf("���ڿ� ���� ���� : %d\n", digit);
    printf("���ڿ� ���� Ư������ : %d\n", splch);
}