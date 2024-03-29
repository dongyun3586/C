#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    char word[MAX_SIZE];
    int i, j, found, index;
    int stringLen, wordLen;


    /* Input string and word from user */
    printf("Enter any string: ");
    gets(str);
    printf("Enter word to remove: ");
    gets(word);

    stringLen = strlen(str);  // Length of string
    wordLen = strlen(word); // Length of word


    /*
     * Run loop from start to end of string - word length
     */
    index = -1;
    for (i = 0; i < stringLen - wordLen; i++)
    {
        // Match word at current position
        found = 1;
        for (j = 0; j < wordLen; j++)
        {
            // If word is not matched
            if (str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }

        // If word is found then update index
        if (found == 1)
        {
            index = i;
        }
    }

    // If word not found
    if (index == -1)
    {
        printf("'%s' not found.");
    }
    else
    {
        /*
         * Shift all characters from right to left
         */
        for (i = index; i <= stringLen - wordLen; i++)
        {
            str[i] = str[i + wordLen];
        }

        printf("String after removing last '%s': \n%s", word, str);
    }

    return 0;
}