#include <stdio.h>
int main() {
    int number, sum = 0;

    for (int i = 1; i <= 5; i++) {
        printf("�����Է� %d: ", i);
        scanf("%d", &number);

        // ������ �ԷµǸ� ���� �ݺ����� �Ѿ��.
        if (number < 0)
            continue;

        sum += number;
    }

    printf("�հ� = %d", sum);

    return 0;
}