//���� 2��(a, b)�� �Է¹޾� ��, ��, ��, ��, ������, ���� ���� �ڵ����� ����غ���.
//�� 0 <= a, b <= 2147483647, b�� 0�� �ƴϴ�.

#include<stdio.h>

int main_1045(void) {
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a + b);
	printf("%lld\n", a - b);
	printf("%lld\n", a * b);
	printf("%lld\n", a / b);
	printf("%lld\n", a % b);
	printf("%.2f\n", (float)a / (float)b);

	return 0;
}