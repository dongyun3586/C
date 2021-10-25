#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 10
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

    //Microsoft   Google   Facebook  Apple  Amazon
    printf("*** 1학년 0반 0번 ○○○ ***\n");
    printf("문자열 입력 : ");
    gets(str);

    n = countWords(str);                            // 문자열 안의 단어의 개수 구하기
    // 입력된 단어가 없는 경우 처리 코드 추가

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

// 문자열에서 알파벳으로 시작하는 단어(연속된 문자열)의 개수 반환
int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;



    return wordCount;
}

// 단어 사이에 공백 하나만 남기고 제거
void removeDuplicateSpace(char* str) {
    
}

// 문자열을 공백을 기준으로 분리하여 문자열 배열에 저장
void spliteString(char* str, char strArr[][20]) {
    int a = 0, b = 0;
    
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
    
}