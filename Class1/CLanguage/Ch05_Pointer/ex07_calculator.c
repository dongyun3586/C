#include<stdio.h>

// ����� y���� ���ϱ�
int get_linearEquationParameter(int x1, int y1, int x2, int y2, float* slope, float* yintercept) {
	if (x1 == x2)
		return -1;
	else {
		*slope = (float)(y2 - y1) / (float)(x2 - x1);
		*yintercept = y1 - (*slope) * x1;
		return 0;
	}
}

int main() {
	float s, y;

	if (get_linearEquationParameter(1, 5, 2, 7, &s, &y) == -1)
		printf("�߸��� ��ǥ�Դϴ�.\n");
	else
		printf("y = %0.1fx + %0.1f\n", s, y);
	return 0;
}