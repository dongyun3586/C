#include <stdio.h>
const int MAX = 4;  // Global declaration.

int main()
{
    char arr[][9] = { "Google", "Amazon", "Facebook", "Apple" };
    char* names[] = { "Google", "Amazon", "Facebook", "Apple" };

    for (int i = 0; i < MAX; i++)
        printf("Value of arr[%d] = %s\n", i, arr[i]);

    printf("\n");

    for (int i = 0; i < MAX; i++)
        printf("Value of *(names + %d) = %s\n", i, *(names + i));

    return 0;
}