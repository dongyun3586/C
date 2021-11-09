#include<stdio.h>

int main() {
	FILE* fp = fopen("test.txt", "w");

	if (!fp) {
		printf("Fail to open the file as the write mode.\n");
		return 0;
	}

	fputc('a', fp);
	fputc('B', fp);
	fputc('1', fp);

	fclose(fp);

	return 0;
}