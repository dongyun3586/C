#include<stdio.h>
#include<stdlib.h>  // rand(), srand() ����
#include<time.h>    // time() ����
#include<ctype.h>

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
        int a;

        // ���� ��� �� ����� �Է� �ޱ�
        printf("%2d * %2d = ", dan, su);
        a = scanf("%d", &userdap);
        printf("%d\n", a);
        /*if (isdigit(userdap)) {
            printf("����");
        }
        else
            printf("���� �ƴ�");*/

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