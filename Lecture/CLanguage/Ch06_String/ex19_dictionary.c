#include <stdio.h>
#include <string.h>

#define WORDS 5

void main()
{
    char dic[WORDS][2][30] = {
        {"computer", "컴퓨터"},
        {"language", "언어"},
        {"dictionary", "사전"},
        {"android", "인간의 모습을 한 로봇"},
        {"array", "배열"}
    };
    char word[30];
    printf("단어를 입력하시오: ");
    scanf("%s", word);

    for (int i = 0; i < WORDS; i++) {
        if (strcmp(dic[i][0], word) == 0) {
            printf("%s: %s\n", word, dic[i][1]);
            return 0;
        }
    }
    printf("%s는 사전에 없습니다.\n", word);

    return 0;
}