#include<stdio.h>

int main() {
	int n, sum=0;
	scanf("%d", &n);

	int i=0;
	while (sum < n) {
		i++;
		sum += i;
	}

	printf("%d\n", i);

	return 0;
}