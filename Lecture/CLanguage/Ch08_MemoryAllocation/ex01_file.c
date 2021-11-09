#include<stdio.h>

int main() {
	char* fileName = "test.txt";
	FILE* fp = NULL;
	fp = fopen(fileName, "w");

	if (fp == NULL) {
		printf("Fail to open the file - %s\n", fileName);
		return 0;
	}
	else {
		printf("The %s file was opened.\n", fileName);
	}

	fclose(fp);
	printf("The %s file was closed.\n", fileName);
	
}