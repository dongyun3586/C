#include<stdio.h>
#include<math.h>

int main_ex06_quadraticEquation() {
	double a, b, c, dis;	// ���(coefficient)�� �Ǻ���(Discriminant)�� ��� ���� ����
	scanf("%lf %lf %lf", &a, &b, &c);	// double���� �Ǽ��� ����� ���� "%lf" �Ǵ� "%f"�� ��� ����� �� �ִ�. ������ �Է��� ���� ���� �ݵ�� "%lf"�� ����ؾ� �Ѵ�.

	if (a == 0)
		printf("�������� ���� %f �Դϴ�.", -c / b);
	else {
		dis = b * b - 4.0 * a * c;
		if (dis >= 0) {
			printf("�������� ���� %f�Դϴ�.\n", (-b + sqrt(dis)) / (2.0 * a));
			printf("�������� ���� %f�Դϴ�.\n", (-b - sqrt(dis)) / (2.0 * a));
		}
		else
			printf("�Ǳ��� �������� �ʽ��ϴ�. \n");
	}

	return 0;
}