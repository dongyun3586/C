#include <stdio.h>

int main_ex22_breakExam() {
    int i, number, sum = 0;

    for (i = 1; i <= 10; ++i) {
        printf("�����Է� %d: ", i);
        scanf("%d", &number);

        // ������ �ԷµǸ� ����ȴ�.
        if (number < 0) 
            break;

        sum += number; 
    }

    printf("�հ� = %d", sum);

    return 0;
}