#include<stdio.h>

enum Weather { SUNNY, CLOUD, RAIN, SNOW };

int main(void)
{
    int input;
    enum Weather wt;

    printf("오늘의 날씨를 입력해 주세요(SUNNY=0, CLOUD=1, RAIN=2, SNOW=3) : ");
    scanf("%d", &input);

    wt = input;

    switch (wt) {
    case SUNNY:
        printf("오늘의 날씨는 아주 맑아요!\n");
        break;
    case CLOUD:
        printf("오늘의 날씨는 흐리네요!\n");
        break;
    case RAIN:
        printf("오늘의 날씨는 비가 주룩주룩 오네요!\n");
        break;
    case SNOW:
        printf("오늘의 날씨는 하얀 눈이 내려요!\n");
        break;
    default:
        printf("정확한 상숫값을 입력해 주세요!\n");
        break;
    }

    printf("열거체 Weather의 각 상숫값은 %d, %d, %d, %d 입니다.\n", SUNNY, CLOUD, RAIN, SNOW);

    return 0;
}