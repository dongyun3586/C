#include <stdio.h>

int main_ex06_scanfExercise()
{
	int a, b, temp;

	printf("���� �� ���� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &a, &b);

	printf("a=%d, b=%d\n", a, b);
	// �� ������ �� ��ȯ�Ͽ� ����
	temp = a;
	a = b;
	b = temp;
	printf("a=%d, b=%d\n", a, b);
}