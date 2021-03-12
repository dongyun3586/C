#include<stdio.h>

int main_ex03_char(void) {
	char c1 = 'a', c2 = 'A', c3 = '0';
	printf("c1=%d, c2=%d, c3=%d \n", c1, c2, c3);
	printf("c1=%c, c2=%c, c3=%c \n", c1, c2, c3);

	c1 = 97;
	c2 = 65;
	c3 = 48;
	printf("c1=%d, c2=%d, c3=%d \n", c1, c2, c3);
	printf("c1=%c, c2=%c, c3=%c \n", c1, c2, c3);
	return 0;
}