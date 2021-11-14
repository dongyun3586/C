#include<stdio.h>

int main() {
	char* fileName = "test.txt";	// C:/Users/Administrator/Desktop/
	FILE* fp = NULL;				// 파일 구조체 포인터를 저장할 수 있는 포인터 변수
	fp = fopen(fileName, "w");		// 쓰기 모드로 열기(파일이 없으면 생성됨)

	// 파일 열기가 실패한 경우 처리
	if (fp == NULL) {
		printf("Fail to open the file - %s\n", fileName);
		return 0;
	}

	printf("The %s file was opened.\n", fileName);

	// 파일을 이용한 어떤 입출력 작업...

	fclose(fp);						// 파일 닫기
	printf("The %s file was closed.\n", fileName);

}