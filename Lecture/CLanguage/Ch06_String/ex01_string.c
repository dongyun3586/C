#include <stdio.h>

int main()
{
    char str1[10] = { 'H', 'e', 'l', 'l', 'o' };    // 배열에 문자열 저장
    char str2[10] = "";                                 // 널문자로 문자열 초기화
    char* sp = "Hello";                             // 포인터 변수에 문자열 시작 주소 저장
    int count_str1 = 0, count_str2 = 0;

    printf("%d, %d\n", sizeof(str1), sizeof(sp));

    // 문자열 배열의 남은 공간은 NUll 문자로 채워진다.
    for (int i = 0; i < 10; i++) {
        printf("%c", str1[i]);
        if (str1[i] == '\0') count_str1++;
        if (str2[i] == '\0') count_str2++;
    }
    printf("%d %d\n", count_str1, count_str2);

    // 문자열 출력
    for (int i = 0; str1[i] != '\0'; i++)
        printf("%c\n", str1[i]);

    printf("%s %s\n", str1, sp);

    return 0;
}