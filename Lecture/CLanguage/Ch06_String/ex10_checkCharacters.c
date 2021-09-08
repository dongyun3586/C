#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 

void countCharactersByType(char* str, int* alp, int* digit, int* specialChar);

int main()
{
    char str[str_size] = "Count total number of alphabets, digits and special characters!@#1234";
    int alp, digit, specialChar;
    alp = digit = specialChar = 0;

    countCharactersByType(str, &alp, &digit, &specialChar);
    printf("문자열 안의 알파벳 : %d\n", alp);
    printf("문자열 안의 숫자 : %d\n", digit);
    printf("문자열 안의 특수문자 : %d\n", specialChar);

    return 0;
}

void countCharactersByType(char* str, int* alp, int* digit, int* specialChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            (*alp)++;
        else if (str[i] >= '0' && str[i] <= '9')
            (*digit)++;
        else
            (*specialChar)++;
    }
}