#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE], word[MAX_SIZE];
    int i, index, found = 0;

    /* Input string and word from user */
    printf("Enter any string: ");
    gets(str);
    printf("Enter word to be searched: ");
    gets(word);


    /* Run loop from start to end of string */
    index = 0;
    while (str[index] != '\0')
    {

        /* If first character of word matches with the given string */
        if (str[index] == word[0])
        {
            /* Match entire word with current found index */
            i = 0;
            found = 1;
            while (word[i] != '\0')
            {
                if (str[index + i] != word[i])
                {
                    found = 0;
                    break;
                }

                i++;
            }
        }

        /* If the word is found then get out of loop */
        if (found == 1)
        {
            break;
        }

        index++;
    }

    /*  Print success message if the word is found */
    if (found == 1)
    {
        printf("\n'%s' is found at index %d.", word, index);
    }
    else
    {
        printf("\n'%s' is not found.", word);
    }

    return 0;
}