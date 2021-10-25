#include <stdio.h>
#include <string.h>

#define MAXWORDS 20
#define MAXCHAR 20

void splitStringBySpace(char* str, char strArr[][MAXCHAR]);
void printStringArray(char strArr[][MAXCHAR]);
void sortStringArray(char strArr[][MAXCHAR]);

int main()
{
    char str[400];
    char strArr[MAXWORDS][MAXCHAR] = { '\0' };
    int i, a = 0, b = 0;
    printf("���ڿ� �Է� : ");
    gets(str);

    splitStringBySpace(str, strArr);
    printStringArray(strArr);
    sortStringArray(strArr);
    printStringArray(strArr);

    return 0;
}

void splitStringBySpace(char* str, char strArr[][MAXCHAR]) {
    int a, b;
    a = b = 0;
    for (int i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            strArr[a][b] = '\0';
            a++;        // ���� �ܾ�
            b = 0;      // ���� �ܾ ���� 0���� �ʱ�ȭ
        }
        else
        {
            strArr[a][b] = str[i];
            b++;
        }
    }
}

void printStringArray(char strArr[][MAXCHAR]) {
    printf("strArr�� ��� �ܾ� ���\n");
    for (int i = 0; i < MAXWORDS; i++) {
        if (strArr[i][0] != '\0')
            printf("%s\n", strArr[i]);
    }
}

void sortStringArray(char strArr[][MAXCHAR]) {
    char temp[MAXCHAR];
    for (int i = 1; i < MAXWORDS; ++i) {
        for (int j = 0; j < MAXWORDS - i; j++) {
            if (strcmp(strArr[j], strArr[j + 1]) > 0) {
                strcpy(temp, strArr[j]);
                strcpy(strArr[j], strArr[j + 1]);
                strcpy(strArr[j + 1], temp);
            }
        }
    }
}