#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// https://codeup.kr/problem.php?id=1805&rid=0

typedef struct device {
    int id;
    int gas;
} device;

void differenceBetweenTimePeriod(struct TIME t1, struct TIME t2, struct TIME* diff);

int main() {
    int n;
    scanf("%d", &n);    // ��ü �⵿��ġ ���� �Է�(1 <= n <= 100)
    device* arr = (device*)malloc(sizeof(device) * n);

    // ��° �ٺ��� n+1° �ٱ��� �� �ٿ� ��ü�⵿��ġ�� �ĺ���ȣ a�� ���� ������ b�� �־�����.
    // a�� �ߺ� �� �� ������ b�� �ߺ��� �� �ִ�. (1 <= a <= 100), (0 <= b <= 10,000)
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].id, &arr[i].gas);

    // ù° �ٺ��� n��° �ٱ��� �� �ٿ� �ĺ���ȣ�� ������������ ������ ���� �������� ���� ����Ѵ�.
    device temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j].id > arr[j + 1].id) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].id, arr[i].gas);

    free(arr);  // �������� �Ҵ��� �޸� ����

    return 0;
}