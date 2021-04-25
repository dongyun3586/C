#include<stdio.h>

int main() {
	int sum = 0;

	for (int a = 0; a < 30; a++) {
		switch (a % 3 + 1) {
		case 1:
			sum += 1;
			break;
		case 2:
			sum += 2;
			break;
		case 3:
			sum += 3;
			break;
		}
	}

	printf("%d \n", sum);

	return 0;
}