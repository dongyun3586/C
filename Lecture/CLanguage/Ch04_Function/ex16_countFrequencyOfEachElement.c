#include <stdio.h>
#include <stdlib.h>     // srand(), rand() => 0 and RAND_MAX (0 and RAND_MAX included), RAND_MAX (32767)
#include <time.h>

int main()
{
    int arr[10000], freq[10000];
    int size, count;

    srand(time(NULL));
    printf("�迭�� ũ��: ");
    scanf("%d", &size);

    // �迭�� 1~10 ������ ���� �� ä���
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10 + 1;
        freq[i] = -1;
    }

    // �󵵼� ����ϱ�
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            /* If duplicate element is found */
            if (arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }

        /* If frequency of current element is not counted */
        if (freq[i] != 0)
            freq[i] = count;
    }

    // Print frequency of each element
    printf("\n�迭 ��ҵ��� �󵵼�\n");
    for (int i = 0; i < size; i++)
        if (freq[i] != 0)
            printf("%2d : %4d ��\n", arr[i], freq[i]);

    return 0;
}

