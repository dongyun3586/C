#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h1, m1, h2, m2, h, m;

	scanf("%d %d", &h1, &m1);
	scanf("%d %d", &h2, &m2);

	if (h1 >= h2 && m1 > m2) {
		h1 -= 12;
		h2 += 12;
		h = h2 - h1;
		m = 60 + m2 - m1;
	}
	else if (h1 > h2 && m1 <= m2) {
		h1 -= 12;
		h2 += 12;
		h = h2 - h1;
		m = m2 - m1;
	}
	else if (h1 <= h2 && m1 <= m2) {
		h = h2 - h1;
		m = m2 - m1;
	}
	else if (h1<h2 && m1>m2) {
		h = h2 - h1 - 1;
		m = 60 + m2 - m1;
	}

	
	printf("%d�ð� %d�� ", h, m);

	return 0;
}