#include<stdio.h>
#include<stdlib.h>  // rand(), srand() ����
#include<time.h>    // time() ����

int main() {
    // 1. ���� ����
    int dan, i, jungdap, userdap, score = 0, n;

    // 2. ����� �Է� �ޱ�
    printf("������ �� ����? ");
    scanf("%d", &n);

    // 3. ó��
    srand(time(NULL));
    for (int a = 0; a < n; a++) {
        dan = rand() % 8 + 2;   // 2~9
        i = rand() % 9 + 1;     // 1~9
        jungdap = dan * i;

        printf("%d * %d = ", dan, i);
        scanf("%d", &userdap);

        if (userdap == jungdap) {
            printf("�����Դϴ�. \n");
            score++;
        }
        else
            printf("Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�.\n", jungdap);
    }

    // 4. ��� ���
    printf("%d �� �� %d�� �¾ҽ��ϴ�. \n", n, score);

    return 0;
}