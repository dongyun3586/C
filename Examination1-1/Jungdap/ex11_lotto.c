#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* �ζǹ�ȣ ��� */
int main() {
#pragma region ����
    /*for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d ", rand());
        }
        printf("\n");
    }*/
#pragma endregion

#pragma region �ش�
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++)
            printf("%2d ", rand() % 45 + 1);

        printf("\n");
    }
#pragma endregion


    return 0;
}