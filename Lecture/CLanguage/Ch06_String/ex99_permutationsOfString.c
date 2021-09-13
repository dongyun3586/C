#include <stdio.h>
#include <string.h>

void changePosition(char* ch1, char* ch2)
{
    printf("changePosition(\'%c\', \'%c\')\n", *ch1, *ch2);
    char tmp;
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}

void charPermu(char* cht, int stno, int endno)
{
    printf("charPermu(\"%s\", %d, %d)\n", cht, stno, endno);
    int i;

    if (stno == endno)
        printf("%s\n", cht);
    else
    {
        for (i = stno; i <= endno; i++)
        {
            changePosition((cht + stno), (cht + i));
            charPermu(cht, stno + 1, endno);
            changePosition((cht + stno), (cht + i));
        }
    }
}

int main()
{
    char str[10];
    printf("문자열 순열 출력하기 :\n");
    printf("문자열 입력 : ");
    scanf("%s", str);
    int n = strlen(str);

    charPermu(str, 0, n - 1);

    printf("\n\n");
    return 0;
}