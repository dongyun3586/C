#include<stdio.h>

int main() {
#pragma region 1. 바이너리 파일 쓰기
	char* fileName = "binary.bin";
	int data[5] = { 10,20,30,40,50 };
	FILE* fp = NULL;

	if (!(fp = fopen(fileName, "wb"))) {
		fprintf(stderr, "Fail to open the file - %s\n", fileName);
		exit(1);
	}

	size_t n = fwrite(data, sizeof(int), 5, fp);
	printf("Success to write %d objects.\n", n);

	fclose(fp);
#pragma endregion

#pragma region 2. 바이너리 파일 읽기
	int buf[5] = { 0 };
	fp = fopen("binary.bin", "rb");
	if (!fp) {
		fprintf(stderr, "Fail to open the file - %s\n", fileName);
		exit(1);
	}

	n = fread(buf, sizeof(int), 5, fp);
	printf("Success to read %d objects.\n", n);
	for (int i = 0; i < 5; i++)
		printf("%d ", buf[i]);

	fclose(fp);
#pragma endregion

	return 0;
}