#include<stdio.h>
#include<stdlib.h>  // rand(), srand() ����
#include<time.h>    // time() ����

int main() {
#pragma region 1. rand() ���
    //// �Լ�����: int rand (void) 
    //// �Լ����: Generate pseudo-random number [0 ~ RAND_MAX]

    //// rand() �Լ��� 0~32767 ������ �������� ��ȯ�Ѵ�.
    //printf("RAND_MAX : %d\n", RAND_MAX);  // RAND_MAX : 32767

    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //// => rand() �Լ��� ���α׷��� �����ɶ� ���� �������� ������ ���α׷��� ������ ������ѵ� ������ ���� ���ɴϴ�.
#pragma endregion

#pragma region 2. rand(), srand() ���
    //// �Լ�����: void srand(unsigned int seed) 
    //// �Լ����: Initialize random number generator.
    //// rand �Լ��� ���������� � srand�� �Ű������� ���� seed ���� �ش��ϴ� ���ڵ��� ��ȯ�Ѵ�.

    //// srand(seed)�� ���޵Ǵ� seed���� ������ rand()�Լ��� �����ϴ� ���������� ����.
    //srand(100);
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //printf("\n");

    //srand(100);
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
    //printf("\n");

    //// srand(seed)�� ���޵Ǵ� seed���� �ٸ��� rand()�Լ��� �����ϴ� �������鵵 �ٸ���.
    //srand(200);
    //for (int i = 0; i < 10; i++)
    //    printf("rand : %d\n", rand());
#pragma endregion

#pragma region 3. rand(), srand(), time() ���
    // �Լ�����: time_t time (time_t* timer)
    // �Լ����: UCT ���� 1970�� 1�� 1�� 0�� 0�� 0�� ���� ����� �ð��� ��(sec)�� ��ȯ�ϴ� �Լ�

    // ���α׷��� ������ �� ���� �ٸ� ���� ���ڸ� ��� ���ؼ��� �׻� ���ϴ� seed���� �̿��ϸ� �ȴ�.
    printf("%d\n", time(NULL));  
    printf("1970�� ���� �� �ʳ� ������? : %ld �� \n", time(NULL));

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("rand : %d\n", rand());
    printf("\n");
#pragma endregion

    return 0;
}