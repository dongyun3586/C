#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void swapPoint(Point* a, Point* b) {
    Point temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    Point p1 = { 10, 10 };
    Point p2 = { 20, 20 };
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);

    swapPoint(&p1, &p2);
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);

    return 0;
}