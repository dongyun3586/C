#include <stdio.h>

/* �� �Ƕ�̵� ��� */
int main() {
    int h;

    printf("����: ");
    scanf("%d", &h);

#pragma region 0, 0, 0
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < i; j++)  printf(" ");   // j <= i-1
        for (int j = 0; j < 2 * (h - i) - 1; j++)  // 2 * h - 1 - 2 * i
            printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region 0, 0, 2 * (h - i) - 1
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < i; j++)  printf(" ");   // j <= i-1
        for (int j = 2 * (h - i) - 1; j > 0; j--)  // 2 * h - 1 - 2 * i
            printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region 0, 0, 2 * h - 1
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < i; j++)  printf(" ");   // j <= i-1
        for (int j = 2 * h - 1; j > 2 * i; j--)  // 2 * h - 1 - 2 * i
            printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region 0, i, 2*(h-i)-1
    for (int i = 0; i < h; i++) {
        for (int j = i; j > 0; j--)  printf(" ");   // j <= i-1
        for (int j = 2 * (h - i) - 1; j > 0; j--)  // 2 * h - 1 - 2 * i
            printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region 1, 1, 1
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < i; j++) printf(" ");                // j <= i-1           
        for (int j = 1; j <= 2 * (h - i) + 1; j++) printf("*"); // 2*(h-i+1)-1
        printf("\n");
    }
#pragma endregion

#pragma region 1, 1, 2 * (h - i + 1) - 1
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < i; j++) printf(" ");                // j <= i-1           
        for (int j = 2 * (h - i + 1) - 1; j >= 1; j--) printf("*"); // 2 * (h - i) + 1
        printf("\n");
    }
#pragma endregion

#pragma region ��� 0���� ����
    for (int i = h; i > 0; i--) {       // i >= 1
        for (int j = h - i; j > 0; j--)          printf(" ");
        for (int j = 2 * i - 1; j > 0; j--)      printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region h, 0, 0
    for (int i = h; i >= 1; i--) {      // i > 0
        for (int j = 0; j < h - i; j++)         printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)    printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region h, 0, 1
    for (int i = h; i >= 1; i--) {      // i > 0
        for (int j = 0; j < h - i; j++)         printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)    printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region h, 0, 2*i-1
    for (int i = h; i >= 1; i--) {      // i > 0
        for (int j = 0; j < h - i; j++)         printf(" ");
        for (int j = 2 * i - 1; j >= 1; j--)    printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region h, 1, 1
    for (int i = h; i >= 1; i--) {  // i > 0
        for (int j = 1; j <= h - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region h, 1, 2*i-1
    for (int i = h; i >= 1; i--) {
        for (int j = 1; j <= h - i; j++) printf(" ");
        for (int j = 2 * i - 1; j >= 1; j--) printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region h, i, 1
    for (int i = h; i >= 1; i--) {  // i > 0
        for (int j = i; j < h; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
#pragma endregion

#pragma region Ư�� ���̽� 1308 ���ؿ�
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= 2 * h - 1; j++) {
            if (i == 1)
                printf("*");
            else if (j >= i && i + j <= 2 * h)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
#pragma endregion



#pragma region �ٸ� ���̽�
    //// �Ǵ� 
    //for (int i = h; i > 0; i--) {

    //    // ���� ��� => �Ƕ�̵� ���̺��� �ϳ� ������ŭ ���� ���
    //    for (int space = h; space > i; space--)
    //        printf(" ");

    //    // '*' ���
    //    for (int j = 1; j <= 2 * i - 1; j++)
    //        printf("*");

    //    printf("\n");
    //}
#pragma endregion
    return 0;
}