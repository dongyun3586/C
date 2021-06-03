#include<stdio.h>

int main() {

	char strArr[][10] = { "H", "He", "Li","Be","B","C","N","O","F","Ne" };
	int r = sizeof(strArr) / sizeof(strArr[0]);
	printf("r=%d\n", r);
	
	for (int i = 0; i < r; i++)
		printf("strArr[%d] = %s\n", i, strArr[i]);

	return 0;
}