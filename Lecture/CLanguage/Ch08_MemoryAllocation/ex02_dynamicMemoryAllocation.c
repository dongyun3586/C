#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int* ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(sizeof(int) * n);

    // if memory cannot be allocated
    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (int i = 0; i < n; ++i) {
        printf("Enter elements %d : ", i + 1);
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", *(ptr + i));
        if (i != n - 1)printf(" + ");
    }
    printf(" = %d", sum);

    free(ptr);      // 동적으로 할당한 메모리 해제

    return 0;
}