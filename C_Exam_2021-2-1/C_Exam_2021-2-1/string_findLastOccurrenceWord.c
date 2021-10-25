#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    char word[MAX_SIZE];
    int i, j, index, found;
    int strLen, wordLen;

    /* Input string and word from user */
    printf("Enter any string: ");
    gets(str);
    printf("Enter any word to search: ");
    gets(word);

    index = -1;
    strLen = strlen(str);   // Find length of string
    wordLen = strlen(word);  // Find length of word


    /*
     * Runs a loop from starting index of string to
     * length of string - word length
     */
    for (i = 0; i <= strLen - wordLen; i++)
    {
        // Match word at current position
        found = 1;
        for (j = 0; j < wordLen; j++)
        {
            //If word is not matched
            if (str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }

        // If word have been found then store the current found index
        if (found == 1)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        printf("\n'%s' not found.", word);
    }
    else
    {
        printf("\nLast index of '%s' = %d", word, index);
    }

    return 0;
}