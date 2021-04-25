#include <stdio.h>

/* 역 피라미드 출력 */
int main() {
    int h;

    printf("높이: ");
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

#pragma region 모두 0으로 끝남
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

#pragma region 특별 케이스 1308 송준영
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



#pragma region 다른 케이스
    //// 또는 
    //for (int i = h; i > 0; i--) {

    //    // 공백 출력 => 피라미드 높이보다 하나 작은만큼 공백 출력
    //    for (int space = h; space > i; space--)
    //        printf(" ");

    //    // '*' 출력
    //    for (int j = 1; j <= 2 * i - 1; j++)
    //        printf("*");

    //    printf("\n");
    //}
#pragma endregion
    return 0;
}