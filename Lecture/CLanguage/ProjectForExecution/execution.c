#include <stdio.h>

int main() {
    int i=1, number, sum = 0;

    while (1) {
        printf("�����Է� %d: ", i);
        scanf("%d", &number);

        // ������ �ԷµǸ� ����ȴ�.
        if (number < 0)
            break;

        i++;
        sum += number;
    }

    printf("�հ� = %d", sum);

    return 0;
}