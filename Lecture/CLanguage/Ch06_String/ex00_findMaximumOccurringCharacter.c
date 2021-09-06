#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100    // 문자열 최대 길이
#define chr_no 255      // 아스키 코드 길이

void main()
{
    char str[str_size];
    int ch_fre[chr_no] = { 0 };
    int i = 0, max;
    int ascii;

    printf("문자열에서 가장 빈도수 높은 문자 찾기\n");
    printf("Input the string : ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        ascii = (int)str[i];    // 문자를 ascii 코드값으로 변환
        ch_fre[ascii] += 1;     // 해당 아스키 위치에 출현 빈도 저장
    }

    max = 0;
    for (int i = 0; i < chr_no; i++)
    {
        if (ch_fre[i] > ch_fre[max])
            max = i;
    }
    printf("'%c'가 %d회로 가장 많이 나타남.\n", max, ch_fre[max]);
}