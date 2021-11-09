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
    scanf("%d", &n);    // 입체 기동장치 개수 입력(1 <= n <= 100)
    device* arr = (device*)malloc(sizeof(device) * n);

    // 둘째 줄부터 n+1째 줄까지 각 줄에 입체기동장치의 식별번호 a와 가스 보유량 b가 주어진다.
    // a는 중복 될 수 없지만 b는 중복될 수 있다. (1 <= a <= 100), (0 <= b <= 10,000)
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].id, &arr[i].gas);

    // 첫째 줄부터 n번째 줄까지 각 줄에 식별번호를 오름차순으로 정렬해 가스 보유량과 같이 출력한다.
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

    free(arr);  // 동적으로 할당한 메모리 해제

    return 0;
}