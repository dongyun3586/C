#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h1, h2, m1, m2, a, b, t, h, m;

	printf("���� �ð�: ");
	scanf("%d %d", &h1, &m1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	a = h1 * 60 + m1;	// ����ð� ������ ȯ��
	b = h2 * 60 + m2;	// �˶��ð� ������ ȯ��

	if (b >= a)			// �˶� ȯ�갪�� ũ��
		t = b - a;		// ���� t = �˶� - ����
	else {
		a = 1440 - a;	// �˶��� = 24�ð��� - �˶���
		t = a + b;
	}
	h = t / 60;
	m = t % 60;
	printf("%d�ð� %d�� ", h, m);

	return 0;
}