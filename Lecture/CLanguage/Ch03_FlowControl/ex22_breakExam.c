#include <stdio.h>

int main_ex22_breakExam() {
    int number, sum = 0;

    while (1) {
        printf("�����Է�: ");
        scanf("%d", &number);

        // ������ �ԷµǸ� ����ȴ�.
        if (number < 0)
            break;

        sum += number;
    }

    printf("�հ� = %d", sum);

    return 0;
}