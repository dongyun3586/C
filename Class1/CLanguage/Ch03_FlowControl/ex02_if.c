#include<stdio.h>

int main_ex02_if() {
	int n; // �ʿ��� ���� ����

	// �� �Է¹ޱ�
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &n);

	// �Ǵ�
	if (n<0)
		n = -n;

	// ���밪 ���
	printf("���밪�� %d �Դϴ� \n", n);
	return 0;
}