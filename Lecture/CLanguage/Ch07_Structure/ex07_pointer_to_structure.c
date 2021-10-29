#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void movePlus(Point* p) {
    (*p).x++;
    (*p).y++;
}

void moveMinus(Point* p) {
    p->x--;
    p->y--;
}

int main()
{
    Point p1 = { 10, 10 };
    printf("x=%d, y=%d\n", p1.x, p1.y);
    movePlus(&p1);
    printf("x=%d, y=%d\n", p1.x, p1.y);
    moveMinus(&p1);
    printf("x=%d, y=%d\n", p1.x, p1.y);

    return 0;
}