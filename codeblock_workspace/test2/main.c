#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 함수원형: time_t time (time_t* timer)
    // 함수기능: UCT 기준 1970년 1월 1일 0시 0분 0초 부터 경과된 시간을 초(sec)로 반환하는 함수

    // 프로그램을 실행할 때 마다 다른 랜덤 숫자를 얻기 위해서는 항상 변하는 seed값을 이용하면 된다.
    printf("%d\n", time(NULL));
    printf("1970년 부터 몇 초나 지났나? : %ld 초 \n", time(NULL));

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("rand : %d\n", rand());
    printf("\n");
    return 0;
}
