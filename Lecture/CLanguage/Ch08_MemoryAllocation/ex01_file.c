#include<stdio.h>

int main() {
	char* fileName = "test.txt";	// C:/Users/Administrator/Desktop/
	FILE* fp = NULL;				// ���� ����ü �����͸� ������ �� �ִ� ������ ����
	fp = fopen(fileName, "w");		// ���� ���� ����(������ ������ ������)

	// ���� ���Ⱑ ������ ��� ó��
	if (fp == NULL) {
		printf("Fail to open the file - %s\n", fileName);
		return 0;
	}

	printf("The %s file was opened.\n", fileName);

	// ������ �̿��� � ����� �۾�...

	fclose(fp);						// ���� �ݱ�
	printf("The %s file was closed.\n", fileName);

}