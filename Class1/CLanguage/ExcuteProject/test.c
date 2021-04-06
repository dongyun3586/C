#include<stdio.h>
#include<stdlib.h>  // rand(), srand() 정의
#include<time.h>    // time() 정의

int main() {
#pragma region 1. rand() 사용
    //// 함수원형: int rand (void) 
    //// 함수기능: Generate pseudo-random number [0 ~ RAND_MAX]

    //// rand() 함수는 0~32767 사이의 정수값을 반환한다.
    //printf("RAND_MAX : %d\n", RAND_MAX);  // RAND_MAX : 32767

    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //// => rand() 함수는 프로그램이 생성될때 값이 정해지기 때문에 프로그램을 여러번 실행시켜도 동일한 값이 나옵니다.
#pragma endregion

#pragma region 2. rand(), srand() 사용
    //// 함수원형: void srand(unsigned int seed) 
    //// 함수기능: Initialize random number generator.
    //// rand 함수는 내부적으로 어떤 srand의 매개변수로 들어온 seed 값에 해당하는 숫자들을 반환한다.

    //// srand(seed)에 전달되는 seed값이 같으면 rand()함수가 생성하는 정수값들은 같다.
    //srand(100);
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //printf("\n");

    //srand(100);
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //printf("\n");

    //// srand(seed)에 전달되는 seed값이 다르면 rand()함수가 생성하는 정수값들도 다르다.
    //srand(200);
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
#pragma endregion

#pragma region 3. rand(), srand(), time() 사용
    // 함수원형: time_t time (time_t* timer)
    // 함수기능: UCT 기준 1970년 1월 1일 0시 0분 0초 부터 경과된 시간을 초(sec)로 반환하는 함수

    // 프로그램을 실행할 때 마다 다른 랜덤 숫자를 얻기 위해서는 항상 변하는 seed값을 이용하면 된다.
    printf("%d\n", time(NULL));  
    printf("1970년 부터 몇 초나 지났나? : %ld 초 \n", time(NULL));

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("rand : %d\n", rand());
    printf("\n");
#pragma endregion

    return 0;
}