#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int ch, cm, ah, am, h, m;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &ch, &cm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	// �� ó�� [8��]
	if (ah < ch)
		h = ah + 24 - ch;
	else
		h = ah - ch;
	if (am < cm) {
		m = am + 60 - cm;
		h--;
		if (h < 0) h += 24;
	}
	else
		m = am - cm;

	// �� ��� [3��]
	printf("%d�ð� %d�� ", h, m);

	return 0;
}