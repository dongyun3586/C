#include<stdio.h>
#include<stdlib.h>  // rand(), srand() ����
#include<time.h>    // time() ����

int main() {
    // ���� ����
    int n, dan, su, jungdap, score = 0, userdap;

    // �ʿ��� �� �Է¹ޱ�
    printf("�� ����? ");
    scanf("%d", &n);

    // ó��
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        // ���� ���� ����
        dan = rand() % 18 + 2;  // 2~19
        su = rand() % 19 + 1;   // 1~19
        jungdap = dan * su;

        // ���� ��� �� ����� �Է� �ޱ�
        printf("%2d * %2d = ", dan, su);
        scanf("%d", &userdap);

        // ���� üũ
        if (jungdap == userdap) {
            printf("�����Դϴ�. \n");
            score++;
        }
        else
            printf("Ʋ�Ƚ��ϴ�. ������ %d\n", jungdap);
    }

    // ��� ���
    printf("%d�� �� %d ���� �¾ҽ��ϴ�.\n", n, score);

    return 0;
}