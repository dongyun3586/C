#include <stdio.h>
#include <string.h>

int countWords(char* str);
void spliteString(char* str, char strArr[][20]);

int main()
{
    char str[100];
    char newString[20][20];
    int numberOfWords;

    printf("문자열 입력 : ");
    gets(str);

    numberOfWords = countWords(str);
    spliteString(str, newString);

    printf("공백으로 분리된 단어들\n");
    for (int i = 0; i < numberOfWords; i++)
        printf("%s\n", newString[i]);
    return 0;
}

int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isNewWord) {
                wordCount++;
                isNewWord = 0;
            }
        }
        else {
            isNewWord = 1;
        }
    }
    return wordCount;
}

void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    for (int i = 0; str[i] != '\0'; i++)          // for (int i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] == ' ')    // if (str[i] == ' ' || str[i] == '\0')
        {
            strArr[a][b] = '\0';
            a++;        // 다음 단어
            b = 0;      // 다음 단어를 위해 배열의 일차원 인덱스를 0으로 초기화
        }
        else
        {
            strArr[a][b] = str[i];
            b++;
        }
    }
    strArr[a][b] = '\0';
}