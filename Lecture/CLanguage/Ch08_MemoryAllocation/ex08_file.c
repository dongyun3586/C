#include<stdio.h>

int main() {
	FILE* fp = fopen("test.txt", "w");
	fputs("1234567980", fp);
	fclose(fp);

	fp = fopen("test.txt", "r");

	fseek(fp, 3, SEEK_SET);
	printf("fssek(fp, 3, SEEK_SET) = %c\n", fgetc(fp));

	fseek(fp, -2, SEEK_END);
	printf("fssek(fp, -1, SEEK_END) = %c\n", fgetc(fp));

	fclose(fp);
	return 0;
}