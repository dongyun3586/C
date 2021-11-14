#include<stdio.h>
#define BUFFER_SIZE 255

int main() {
	FILE* fpA = NULL, * fpB = NULL;
	char fileName[BUFFER_SIZE] = { 0 }, buf[BUFFER_SIZE] = { 0 };

	printf("Input file name: ");
	scanf("%s", fileName);
	if ((fpA = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Fail to open the input file = %s\n", fileName);
		exit(-1);
	}

	printf("New file name: ");
	scanf("%s", fileName);
	if ((fpB = fopen(fileName, "w")) == NULL) {
		fprintf(stderr, "Fail to open the input file - %s\n", fileName);
		exit(-1);
	}

	// File Copy fpA -> fpB
	while (fgets(buf, sizeof(buf), fpA) != NULL)	// buf로 fpA의 문자열 읽기
		fputs(buf, fpB);							// buf의 문자열을 fpB로 출력

	fclose(fpA);
	fclose(fpB);

	return 0;
}