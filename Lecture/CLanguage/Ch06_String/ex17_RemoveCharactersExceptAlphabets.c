#include <stdio.h>
#include <string.h>
void main() {
    char str[150];
    int i, j;

    // www.W3School.com
    printf("Alphabet �̿��� ���� �����ϱ�\n");
    printf("���ڿ� �Է� : ");
    fgets(str, sizeof str, stdin);

    for (i = 0; str[i] != '\0'; ++i)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            for (j = i; str[j] != '\0'; ++j)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }

    /* for (i = 0; str[i] != '\0'; ++i)
     {
         if (!(isalpha(str[i])))
             strcpy(&str[i], &str[i + 1]);

     }*/

    printf("���� ���ڿ� : %s\n", str);
}