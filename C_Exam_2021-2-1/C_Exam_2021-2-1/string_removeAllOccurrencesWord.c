#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

/* Function declaration */
void removeAll(char* str, char* toRemove);


int main()
{
    char str[MAX_SIZE];
    char toRemove[MAX_SIZE];

    /* Input string and word from user */
    printf("Enter any string: ");
    gets(str);
    printf("Enter word to remove: ");
    gets(toRemove);

    printf("String before removing '%s' : \n%s", toRemove, str);

    removeAll(str, toRemove);

    printf("\n\nString after removing '%s' : \n%s", toRemove, str);

    return 0;
}


/**
 * Remove all occurrences of a given word in string.
 */
void removeAll(char* str, char* toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for (i = 0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for (j = 0; j < toRemoveLen; j++)
        {
            if (str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */
        if (str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0')
        {
            found = 0;
        }

        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if (found == 1)
        {
            for (j = i; j <= stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
    }
}