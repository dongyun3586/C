#include <stdio.h>
#include <string.h>

void main() {
    char str[150];
    int i, j;

    printf("Alphabet 이외의 문자 제거하기\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);

    // 문자열에서 알파벳 이외의 문자 제거
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) == 0) {
            for (int j = i; str[j] != '\0'; j++)
                str[j] = str[j + 1];
            i--;
        }
    }

    printf("최종 문자열 : %s\n", str);
}