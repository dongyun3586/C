#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h, m, h1, m1, h2, m2, t1, t2;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h1, &m1);

	t1 = h * 60 + m;
	t2 = h1 * 60 + m1;
	if (t1 > t2) {
		t2 += 1440;
		h2 = (t2 - t1) / 60;
		m2 = (t2 - t1) % 60;
		printf("%d�ð� %d�� ", h2,m2);
	}
	else if (t1 <= t2) {
		h2 = (t2 - t1) / 60;
		m2 = (t2 - t1) % 60;
		printf("%d�ð� %d�� ", h2, m2);
	}
	

	return 0;
}