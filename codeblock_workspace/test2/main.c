#include <stdio.h>
#include <stdlib.h>

int main()
{
    // �Լ�����: time_t time (time_t* timer)
    // �Լ����: UCT ���� 1970�� 1�� 1�� 0�� 0�� 0�� ���� ����� �ð��� ��(sec)�� ��ȯ�ϴ� �Լ�

    // ���α׷��� ������ �� ���� �ٸ� ���� ���ڸ� ��� ���ؼ��� �׻� ���ϴ� seed���� �̿��ϸ� �ȴ�.
    printf("%d\n", time(NULL));
    printf("1970�� ���� �� �ʳ� ������? : %ld �� \n", time(NULL));

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("rand : %d\n", rand());
    printf("\n");
    return 0;
}
