#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Rectangle {
    int x1, y1;
    int x2, y2;
};

int main()
{
    struct Rectangle rect;
    int width, height, area;

    printf("사각형의 좌표 입력(x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &rect.x1, &rect.y1, &rect.x2, &rect.y2);

    width = abs(rect.x2 - rect.x1);
    height = abs(rect.y2 - rect.y1);
    area = width * height;

    printf("사각형의 넓이 : %d\n", area);

    return 0;
}