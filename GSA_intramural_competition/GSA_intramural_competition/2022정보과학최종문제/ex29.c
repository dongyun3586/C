#include <stdio.h>
void reverse(char*);
void main(void) {
	char str[15];
	gets(str);
	reverse(str);
}
void reverse(char* str) {
	char addr = *str;
	if (addr) {
		reverse(++str);
		printf("%c", addr);
	}
}