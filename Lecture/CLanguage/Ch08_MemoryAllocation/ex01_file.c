#include<stdio.h>

int main() {
	char* fileName = "C:/Users/Administrator/Desktop/test.txt";
	FILE* fp = NULL;
	fp = fopen(fileName, "w");

	if (fp == NULL) {
		printf("Fail to open the file - %s\n", fileName);
		return 0;
	}
	else {
		printf("The %s file was opened.\n", fileName);
	}

	// 파일을 이용한 어떤 입출력 작업...

	fclose(fp);
	printf("The %s file was closed.\n", fileName);

}