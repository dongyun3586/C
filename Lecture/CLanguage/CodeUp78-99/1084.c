// 1084 : [기초-종합] 빛 섞어 색 만들기

#include<stdio.h>

int main_1084() {
    int i, j, k, c = 0;
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
        for (i = 0; i < r; i++)
            for (j = 0; j < g; j++)
                for (k = 0; k < b; k++)
                {
                    printf("%d %d %d\n", i, j, k);
                    c++;
                }

    printf("%d ", c);

	return 0;
}