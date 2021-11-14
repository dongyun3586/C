#include<stdio.h>

int main() {
	// 1. 문자 단위 파일 입력
	FILE* fp1 = fopen("test.txt", "w");
	if (!fp1) {
		printf("Fail to open the file as the write mode.\n");
		return 0;
	}

	fputc('A', fp1);
	fputc('B', fp1);
	fputc('C', fp1);

	fclose(fp1);

	// 2. 문자 단위 파일 출력
	FILE* fp2 = fopen("test.txt", "r");
	if (!fp2) {
		printf("Fail to open the file as the write mode.\n");
		return 0;
	}

	char c = 0;
	while ((c = fgetc(fp2)) != EOF)
		printf("%c", c);

	fclose(fp2);

	return 0;
}