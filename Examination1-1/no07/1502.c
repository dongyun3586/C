#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int hour, min, ahour, amin, phour, pmin;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &hour, &min);
	printf("\n");						// ���� -1
	printf("�˶� �ð�: ");
	scanf("%d %d", &ahour, &amin);
	printf("\n");						// ���� -1

	// �� ó�� [8��]
	if (hour > ahour) {
		phour = hour - ahour + 24;
	}
	else {
		phour = hour - ahour;
	}

	// �� ��� [3��]
	printf("%d�ð� %d�� ", phour, pmin);

	return 0;
}