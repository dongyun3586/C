#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 20
#define MAXCHAR 20

int countWords(char* str);
void removeDuplicateSpace(char* str);
void spliteString(char* str, char strArr[][20]);
void printStringArray(char strArr[][MAXCHAR], int n);
void sortStringArray(char strArr[][MAXCHAR], int n);

int main()
{
    char str[400] = "";
    char strArr[MAXWORDS][MAXCHAR];

    //Samsung     Microsoft    Google   Facebook  Apple Amazon
    printf("문자열 입력 : ");
    gets(str);

    int n = countWords(str);                    // 문자열 안의 단어의 개수 구하기
    removeDuplicateSpace(str);                  // 단어와 단어 사이의 중복되는 공백 제거
    printf("공백 제거 후 문자열 : %s\n", str);
    spliteString(str, strArr);                  // 문자열 안의 단어들을 문자열 배열에 저장하기
    printf("정렬 전 문자열 배열 : ");
    printStringArray(strArr, n);                   // 문자열 배열의 단어들 출력
    sortStringArray(strArr, n);                    // 문자열 배열의 단어들 정렬
    printf("정렬 후 문자열 배열 : ");
    printStringArray(strArr, n);                   // 문자열 배열의 단어들 출력

    return 0;
}

// 주어진 문자열에서 알파벳으로 시작하는 연속된 문자열의 개수 반환
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

        /*if (isalpha(str[i]) && isNewWord) {
            wordCount++;
            isNewWord = 0;
        }
        else if (!isalpha(str[i])) {
            isNewWord = 1;
        }*/
    }
    return wordCount;
}

// 문자열 중간의 두 개 이상의 연속된 공백이 있는 경우 하나만 남기고 제거
void removeDuplicateSpace(char* str) {
    int start, end;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            start = i;
            for (end = i; str[end] == ' '; end++);
            if (end - start > 1)
                strcpy(str + start + 1, str + end);
            //strcpy(&str[start + 1], &str[end]);
        }
    }
}

// 문자열을 공백을 기준으로 분리하여 문자열 배열에 저장
void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    for (int i = 0; str[i] != '\0'; i++)          // for (int i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] != ' ')    // if (str[i] == ' ' || str[i] == '\0')
        {
            strArr[a][b] = str[i];
            b++;
        }
        else
        {
            strArr[a][b] = '\0';
            a++;        // 다음 단어
            b = 0;      // 다음 단어를 위해 배열의 일차원 인덱스를 0으로 초기화
        }
    }
    strArr[a][b] = '\0';
}

// 문자열 배열에 저장된 모든 요소 출력
void printStringArray(char strArr[][MAXCHAR], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", strArr[i]);
    printf("\n");
}

// 문자열 배열의 저장된 요소들을 ASCII CODE 순서대로 정렬
void sortStringArray(char(*strArr)[MAXCHAR], int n) {
    char t[MAXCHAR];
    char* temp=t;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (strcmp(strArr[j], strArr[j + 1]) > 0) {
                strcpy(temp, strArr[j]);
                strcpy(strArr[j], strArr[j + 1]);
                strcpy(strArr[j + 1], temp);
            }
        }
    }
}