#include <stdio.h>
#include <string.h>

void main() {
    char str[150];
    int i, j;

    printf("Alphabet �̿��� ���� �����ϱ�\n");
    printf("���ڿ� �Է� : ");
    fgets(str, sizeof str, stdin);

    // ���ڿ����� ���ĺ� �̿��� ���� ����
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) == 0) {
            for (int j = i; str[j] != '\0'; j++)
                str[j] = str[j + 1];
            i--;
        }
    }

    printf("���� ���ڿ� : %s\n", str);
}