#include <stdio.h>
#include <math.h>

struct point
{
    int x;
    int y;
};

void main()
{
    struct point p1, p2;
    int xdiff, ydiff;
    double dist;

    printf("첫번째 점의 좌표를 입력하시오(x y): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("두번째 점의 좌표를 입력하시오(x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    xdiff = p1.x - p2.x;
    ydiff = p1.y - p2.y;

    dist = sqrt((double)(xdiff * xdiff + ydiff * ydiff));
    printf("두 점간의 거리는 %f입니다.\n", dist);

    return 0;
}



