#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int h1, h2, h, min1, min2, min;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &h1, &h2);
	printf("�˶� �ð�: ");
	scanf("%d %d", &min1, &min2);

	// �� ó�� [8��]
	if ((h2-h1) < 0)
		if ((min2 - min1) < 0) {
			min = min2 - min1 + 60;
			h = h2 - h1 + 23;
		}
		else {
			min = min2 - min1;
			h = h2 - h1 + 24;
		}
	else {
		if ((min2 - min1) < 0) {
			min = min2 - min1 + 60;
			h = h2 - h1 - 1;
		}
		else {
			min = min2 - min1;
			h = h2 - h1;
		}
	}

	printf("%d �ð� %d ��", h, min);
	

	return 0;
}