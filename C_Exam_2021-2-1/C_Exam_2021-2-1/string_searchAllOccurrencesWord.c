#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    char word[MAX_SIZE];
    int i, j, found;
    int strLen, wordLen;

    /* Input string and word from user */
    printf("Enter any string: ");
    gets(str);
    printf("Enter any word to search: ");
    gets(word);

    strLen = strlen(str);  // Find length of string
    wordLen = strlen(word); // Find length of word

    /*
     * Run a loop from starting index of string to
     * length of string - word length
     */
    for (i = 0; i < strLen - wordLen; i++)
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

        // If word have been found then print found message
        if (found == 1)
        {
            printf("'%s' found at index: %d \n", word, i);
        }
    }

    return 0;
}