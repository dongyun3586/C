#include <stdio.h>
#include <string.h>

void changePosition(char* ch1, char* ch2)
{
    char tmp;
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}
void charPermu(char* cht, int stno, int endno)
{
    int i;
    if (stno == endno)
        printf("%s\n", cht);
    else
    {
        for (i = stno; i <= endno; i++)
        {
            printf("changePosition((%p + %d), (%p + %d)\n", cht, stno, cht, i);
            changePosition((cht + stno), (cht + i));
            printf("charPermu(%p, %d, %d)\n", cht, stno+1, endno);
            charPermu(cht, stno + 1, endno);
            printf("changePosition((%p + %d), (%p + %d)\n", cht, stno, cht, i);
            changePosition((cht + stno), (cht + i));
        }
    }
}

int main()
{
    char str[] = "abcd";
    printf("Pointer : Generate permutations of a given string :\n");
    printf("---------------------------------------------------\n");
    int n = strlen(str);
    printf(" The permutations of the string are : \n");

    printf("charPermu(%p, %d, %d)\n", str, 0, n - 1);
    charPermu(str, 0, n - 1);

    printf("\n\n");
    return 0;
}