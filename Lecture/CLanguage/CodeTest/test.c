#include <stdio.h>
#include <ctype.h>

void func();

int count = 0;

int main()
{
    char c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            count++;
            printf("main: %c\n", c);
            func();
        }
    }

    printf("count: %d\n", count);
    return 0;
}

void func() {
    char c;
    c = getchar();

    if (isalpha(c)) {
        count++;
        printf("func: %c\n", c);
    }
}