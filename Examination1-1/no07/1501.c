#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int h1, h2, m1, m2, h, m;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &h1, &m1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	// �� ó�� [8��]
	m = m2 - m1;
	if (m < 0)
		m += 60, h2--;
	h = h2 - h1;
	if (h < 0)
		h += 24;

	// �� ��� [3��]
	printf("%d�ð� %d�� ", h, m);

	return 0;
}