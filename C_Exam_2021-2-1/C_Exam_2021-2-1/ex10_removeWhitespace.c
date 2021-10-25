#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

// 입력된 문자열의 앞/뒤 공백 제거
void removeLeadingSpace(char* str);
void removeTrailingSpace(char* str);

int main()
{
    char str[MAX_SIZE];
    printf("문자열 입력: ");
    gets(str);

    printf("입력된 문자열: '%s'\n", str);
    removeLeadingSpace(str);
    printf("앞쪽 공백 제거: '%s'\n", str);
    removeTrailingSpace(str);
    printf("뒷쪽 공백 제거: '%s'\n", str);

    return 0;
}

// ① removeLeadingSpace( ) 사용자 정의 함수 [8점]
void removeLeadingSpace(char* str) {
#pragma region 방법1
    //int index = 0, i;
    //// 공백이 아닌 문자 시작 위치 찾기
    //while (str[index] == ' ')
    //    index++;
    //// 앞쪽 공백 제거
    //for (i = 0; str[i + index] != '\0'; i++)
    //    str[i] = str[i + index];
    //str[i] = '\0'; // 문자열 마지막에 NULL 문자 저장
#pragma endregion

#pragma region 방법2
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') {
            strcpy(&str[0], &str[i]);
            break;
        }

#pragma endregion
}

// ② removeTrailingSpace( ) 사용자 정의 함수 [8점]
void removeTrailingSpace(char* str) {
#pragma region 방법1
    /*int index = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
            index = i;
    }
    str[index + 1] = '\0';*/
#pragma endregion

#pragma region 방법2
    int index = -1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') index = i;
    str[index + 1] = '\0';
#pragma endregion
}