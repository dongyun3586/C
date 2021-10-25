#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 20
#define MAXCHAR 20

int countWords(char* str);
void removeDuplicateSpace(char* str);
void spliteString(char* str, char strArr[][20]);
void printStringArray(char strArr[][MAXCHAR], int n);
void sortStringArray(char(*strArr)[MAXCHAR], int n);

int main()
{
    char str[400] = "";
    char strArr[MAXWORDS][MAXCHAR];
    int n = 0;

    printf("*** 1학년 1반 20번 홍길동 ***\n");
    //Microsoft   Google   Facebook  Apple  Amazon
    printf("문자열 입력 : ");
    gets(str);

    n = countWords(str);                        // 문자열 안의 단어의 개수 구하기
    if (n == 0) {
        printf("입력된 문자가 없습니다.\n");
        return 0;
    }
    removeDuplicateSpace(str);                      // 단어와 단어 사이의 중복되는 공백 제거
    printf("공백 제거 후 : %s\n", str);
    spliteString(str, strArr);                      // 문자열 안의 단어들을 문자열 배열에 저장하기
    printf("정렬 전 : ");
    printStringArray(strArr, n);                    // 문자열 배열의 단어들 출력
    sortStringArray(strArr, n);                     // 문자열 배열의 단어들 정렬
    printf("정렬 후 : ");
    printStringArray(strArr, n);                    // 문자열 배열의 단어들 출력

    return 0;
}

// 주어진 문자열에서 알파벳으로 시작하는 연속된 문자열의 개수 반환
int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;

    // 문자열의 모든 문자 검사
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) && isNewWord) {     // 현재 문자가 알파벳이고 새로운 단어이면
            wordCount++;
            isNewWord = 0;
        }
        else if (!isalpha(str[i])) {            // 현재 문자가 알파벳이 아니면
            isNewWord = 1;
        }
    }
    return wordCount;
}

// 문자열 중간의 두 개 이상의 연속된 공백이 있는 경우 하나만 남기고 제거
void removeDuplicateSpace(char* str) {
    int alphaIndex=0;
    // 문자열의 모든 문자 검사
    for (int i = 0; str[i] != '\0'; i++) {
        // 공백을 발견하면 이후의 알파벳 위치를 찾아 alphaIndex에 저장
        if (str[i] == ' ') {
            for (alphaIndex = i; str[alphaIndex] == ' '; alphaIndex++);
            // 공백이 2개 이상이면 공백 하나만 남기고 제거
            if (alphaIndex - i > 1)
                strcpy(&str[i + 1], &str[alphaIndex]);
        }
    }
}

// 문자열을 공백을 기준으로 분리하여 문자열 배열에 저장
void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        
        if (str[i] != ' ')          // 공백이 아니면 문자 하나씩 저장
        {
            strArr[a][b] = str[i];
            b++;
        }
        else                        // 공백이면 다음 단어로 넘어가는 처리
        {
            strArr[a][b] = '\0';    // 저장된 단어의 마지막에 '\0'문자 추가
            a++;                    // 2차원 index 증가
            b = 0;                  // 배열의 1차원 인덱스를 0으로 초기화
        }
    }
    strArr[a][b] = '\0';            // 문자열 끝에 도달하면 마지막 단어의 마지막에 '\0'문자 추가
}

// 문자열 배열에 저장된 모든 요소를 한 줄로 출력
void printStringArray(char strArr[][MAXCHAR], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", strArr[i]);
    printf("\n");
}

// 문자열 배열의 저장된 요소들을 ASCII CODE 순서대로 정렬
void sortStringArray(char(*strArr)[MAXCHAR], int n) {
    char temp[MAXCHAR];
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