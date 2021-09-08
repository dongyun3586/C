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
    printf("���ڿ� ���� ���ĺ� : %d\n", alp);
    printf("���ڿ� ���� ���� : %d\n", digit);
    printf("���ڿ� ���� Ư������ : %d\n", specialChar);

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