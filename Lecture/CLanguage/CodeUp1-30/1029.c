//�Ǽ� 1���� �Է¹޾� �״�� ����غ���.
//(��, �ԷµǴ� �Ǽ��� ������ + -1.7 * 10 - 308 ~+ -1.7 * 10308 �̴�.)

#include<stdio.h>

int main_1029(void) {
	double d;
	scanf("%lf", &d); // double(long float) �������� �Է�
	printf("%.11lf", d);

	return 0;
}