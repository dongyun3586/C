#include<stdio.h>

int main_ex09_for() {

#pragma region printf() �Լ��� ���
	/*printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");
	printf("Hello World! \n");*/
#pragma endregion

#pragma region for�� ���
	for (int i = 1; i <= 10000; i++) {
		printf("Hello World! %d\n", i);
	}
	//printf("%d \n", i);
#pragma endregion

	return 0;
}