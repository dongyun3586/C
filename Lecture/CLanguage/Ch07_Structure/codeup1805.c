#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct device {
    int id;
    int gas;
} device;

void differenceBetweenTimePeriod(struct TIME t1, struct TIME t2, struct TIME* diff);

int main() {
    int n;
    scanf("%d", &n);
    device* arr = (device*)malloc(sizeof(device) * n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].id, &arr[i].gas);

    device temp;
    //printf("temp : %p\n", &temp);
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

    free(arr);  // 동적으로 할당한 메모리 해제

    return 0;
}