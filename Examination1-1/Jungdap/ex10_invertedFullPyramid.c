#include <stdio.h>

/* �� �Ƕ�̵� ��� */
int main() {
    // �� ���� ���� �� ������ ���� �ּ�(����) [2��]
    int h;

    // �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
    printf("����: ");
    scanf("%d", &h);

    // �� ó�� �� ��� [10��]
    for (int i = h; i > 0; i--) {
        // ���� ��� => �Ƕ�̵� ���̺��� �ϳ� ������ŭ ���� ���
        for (int s = h - i; s > 0; s--)
            printf(" ");

        // '*' ���
        for (int j = 2 * i - 1; j > 0; j--)
            printf("*");

        printf("\n");
    }

#pragma region ��� 0���� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
            printf("*");
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