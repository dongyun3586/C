#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h1, m1, h2, m2;

	printf("���� �ð�: ");
	scanf("%d %d", &h1, &m1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	if (h1 < h2) {
		if (m1 < m2)
			printf("%d�ð� %d�� ", h2 - h1, m2 - m1);
		else
			printf("%d�ð� %d�� ", h2 - h1 - 1, m2 + 60 - m1);
	}
	else {
		if (m1 < m2)
			printf("%d�ð� %d�� ", h2 +24-h1, m2 - m1);
		else
			printf("%d�ð� %d�� ", h2 - h1 +23, m1-m2);
	}
	

	return 0;
}