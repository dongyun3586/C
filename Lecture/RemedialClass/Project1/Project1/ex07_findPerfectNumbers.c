#include <stdio.h>

int main()
{
    int a = 1, b = 10000, sum;

    printf("All Perfect numbers between %d to %d:\n", a, b);

    /* Iterate from 1 to end */
    for (int i = a; i <= b; i++)
    {
        sum = 0;
        for (int j = 1; j <= i / 2; j++)
            if (i % j == 0)
                sum += j;

        if (sum == i)
            printf("%d ", i);
    }

    return 0;
}