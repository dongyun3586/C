#include <stdio.h>

/* 역 피라미드 출력 */
int main() {
    // ① 변수 선언 및 변수에 대한 주석(설명) [2점]
    int h;

    // ② 입력 정보 안내 및 입력 받기 [2점]
    printf("높이: ");
    scanf("%d", &h);

    // ③ 처리 및 출력 [10점]
    for (int i = h; i > 0; i--) {
        // 공백 출력 => 피라미드 높이보다 하나 작은만큼 공백 출력
        for (int s = h - i; s > 0; s--)
            printf(" ");

        // '*' 출력
        for (int j = 2 * i - 1; j > 0; j--)
            printf("*");

        printf("\n");
    }

#pragma region 모두 0부터 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
            printf("*");
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