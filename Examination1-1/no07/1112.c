#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h_now, m_now, h_alr, m_alr, h, m;

	printf("���� �ð�: ");
	scanf("%d %d", &h_now, &m_now);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h_alr, &m_alr);

	if (m_now > m_alr) {
		h_alr -= 1;
		m_alr += 60;
	}
	if (h_now > h_alr)
		h_alr += 24;
	h = h_alr - h_now;
	m = m_alr - m_now;

	printf("%d�ð� %d�� ", h, m);

	return 0;
}