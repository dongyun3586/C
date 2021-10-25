#include <stdio.h>
#define MAX_SIZE 100 // Maximum string size

void trimLeading(char* str);

int main()
{
    char str[MAX_SIZE];

    printf("Enter any string: ");
    gets(str);

    printf("%s\n", str);
    trimLeading(str);
    printf("%s\n", str);
    return 0;
}

void trimLeading(char* str)
{
    int index, i, j;
    index = 0;

    /* Find last index of whitespace character */
    while (str[index] == ' ')
        index++;

    if (index != 0) // Shit all trailing characters to its left
    {
        for (i = 0; str[i + index] != '\0'; i++)   // str[i + index] != '\0'
            str[i] = str[i + index];
        str[i] = '\0'; // Make sure that string is NULL terminated
    }
}