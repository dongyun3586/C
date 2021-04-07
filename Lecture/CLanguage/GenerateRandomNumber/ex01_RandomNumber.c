#include<stdio.h>
#include<stdlib.h>  // rand(), srand() ����
#include<time.h>    // time() ����

int main() {
#pragma region 1. rand() ���
    // �Լ�����: int rand (void) 
    // �Լ����: Generate pseudo-random number [0 ~ RAND_MAX]

    // rand() �Լ��� 0~32767 ������ �������� ��ȯ�Ѵ�.
    printf("RAND_MAX : %d\n", RAND_MAX);  // RAND_MAX : 32767

    for (int i = 0; i < 10; i++)
        printf("rand : %d\n", rand());
    // => rand() �Լ��� ���α׷��� �����ɶ� ���� �������� ������ ���α׷��� ������ ������ѵ� ������ ���� ���ɴϴ�.
#pragma endregion

#pragma region 2. rand(), srand() ���
    //// �Լ�����: void srand (unsigned int seed) 
    //// �Լ����: Initialize random number generator.
    //// rand �Լ��� ���������� � srand�� �Ű������� ���� seed ���� �ش��ϴ� ���ڵ��� ��ȯ�Ѵ�.

    //// srand(seed)�� ���޵Ǵ� seed���� ������ rand()�Լ��� �����ϴ� ���������� ����.
    //srand(100);
    //for (int i = 0; i < 10; i++)
    //    printf("%5d ", rand());
    //printf("\n\n");

    //srand(100);
    //for (int i = 0; i < 10; i++)
    //    printf("%5d ", rand());
    //printf("\n\n");

    //// srand(seed)�� ���޵Ǵ� seed���� �ٸ��� rand()�Լ��� �����ϴ� �������鵵 �ٸ���.
    //srand(200);
    //for (int i = 0; i < 10; i++)
    //    printf("%5d ", rand());
    //printf("\n\n");
#pragma endregion

#pragma region 3. rand(), srand(), time() ���
    //// �Լ�����: time_t time (time_t* timer)
    //// �Լ����: UCT ���� 1970�� 1�� 1�� 0�� 0�� 0�� ���� ����� �ð��� ��(sec)�� ��ȯ�ϴ� �Լ�

    //// ���α׷��� ������ �� ���� �ٸ� ���� ���ڸ� ��� ���ؼ��� �׻� ���ϴ� seed���� �̿��ϸ� �ȴ�.
    //printf("%d\n", time(NULL));  
    //printf("1970�� ���� �� �ʳ� ������? : %ld �� \n", time(NULL));

    //srand(time(NULL));
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //printf("\n");
#pragma endregion

#pragma region 4. ���ϴ� ������ ���� ����
    //srand(time(NULL));

    //// 0 ~ 10 ������ ����
    //printf("*** 0 ~ 10 ������ ���� ***\n");
    //for (int i = 0; i < 20; i++)
    //    printf("%2d ", rand() % 11);
    //printf("\n\n");

    //// 1 ~ 10 ������ ����
    //printf("*** 1 ~ 10 ������ ���� ***\n");
    //for (int i = 0; i < 20; i++)
    //    printf("%2d ", rand() % 10 + 1);
    //printf("\n\n");

    //// 2 ~ 9 ������ ����
    //printf("***2 ~ 9 ������ ���� ***\n");
    //for (int i = 0; i < 20; i++)
    //    printf("%2d ", rand() % 8 + 2);
    //printf("\n\n");

#pragma endregion


    return 0;
}