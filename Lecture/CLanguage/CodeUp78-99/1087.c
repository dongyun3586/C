// 1086 : [기초-종합] 그림 파일 저장용량 계산하기

#include<stdio.h>
int main_1087()
{
    int input_num, sum = 0, i=0;
    scanf("%d", &input_num);
    while (sum < input_num) {
        sum += ++i;
    }

    printf("%d", sum);

    return 0;
}
