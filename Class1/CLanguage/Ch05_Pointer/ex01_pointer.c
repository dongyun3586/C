#include<stdio.h>

int main() {
	int n = 100;
	double pi = 3.141592;

	int* p1 = NULL;        // NULL�� 0������ �ǹ��ϴ� ������ ���
	double* p2 = NULL;

	printf("%p %p\n", p1, p2);
	printf("%p %p\n", NULL, NULL);

	p1 = &n;
	p2 = &pi;
	printf("%p %p\n", &n, p1);
	printf("%p %p\n", &pi, p2);
	return 0;
}