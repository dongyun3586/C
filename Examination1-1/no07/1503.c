#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int h, m, h2, m2, time, time2, t;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	// �� ó�� [8��]
	time = 60 * h + m;
	time2 = 60 * h2 + m2;

	if (time2 >= time) {
		t = time2 - time;
		printf("%d�ð� %d�� ", t/60, t%60);
	}
	else {
		t = time2 - time + 24;
		printf("%d�ð� %d�� ", t / 60, t % 60);
	}

	// �� ��� [3��]

	return 0;
}