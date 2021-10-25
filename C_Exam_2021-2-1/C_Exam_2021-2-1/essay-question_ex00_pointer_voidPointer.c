#include <stdio.h>

#define TYPE_INT 1
#define TYPE_FLOAT 2

void swap(void* n1, void* n2, int type);

int main()
{
    int n1 = 100, n2 = 200;
    float n3 = 1.5, n4 = 2.5;

    printf("%d %d\n", n1, n2);
    printf("%.1f %.1f\n", n3, n4);

    swap(&n1, &n2, TYPE_INT);
    swap(&n3, &n4, TYPE_FLOAT);

    printf("%d %d\n", n1, n2);
    printf("%.1f %.1f\n", n3, n4);

    return 0;
}

void swap(void* n1, void* n2, int type)
{
    int t_int;
    float t_float;

    switch (type) {
    case TYPE_INT:
        t_int = *(int*)n1;
        *(int*)n1 = *(int*)n2;
        *(int*)n2 = t_int;
        break;
    case TYPE_FLOAT:
        t_float = *(float*)n1;
        *(float*)n1 = *(float*)n2;
        *(float*)n2 = t_float;
        break;
    }
}