#include<stdio.h>
#define LENGTH 12

int stringChange(char str[], int maxLength, char* newStr, int from);

int main() {
	char str[LENGTH] = "Hello world";
	printf("%s\n", str);

	stringChange(str, LENGTH, "i!", 1);
	printf("%s\n", str);
	stringChange(str, LENGTH, "C Programming Language", 0);
	printf("%s\n", str);

	return 0;
}

int stringChange(char str[], int maxLength, char* newStr, int from) {
	int i = 0;
	for (i = 0; newStr[i] != '\0' && from + i < maxLength; i++)
		str[from + i] = newStr[i];
	str[from + i] = '\0';
	return i;
}