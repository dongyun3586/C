#include <stdio.h>

int main()
{
    char* p_char;
    int* p_int;
    double* p_double;

    p_char = (char*)10000;
    p_int = (int*)10000;
    p_double = (double*)10000;
    printf("%p, %p, %p\n", p_char, p_int, p_double);

    p_char++;
    p_int++;
    p_double++;
    printf("%p, %p, %p\n", p_char, p_int, p_double);
    printf("%p, %p, %p\n", p_char + 2, p_int + 2, p_double + 2);

    return 0;
}