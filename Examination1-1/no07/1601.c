#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int a, b, c, d, t1, t2, t;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	// �� ó�� [8��]
	t1 = 60 * a + b;
	t2 = 60 * c + d;
	t = t2 - t1;

	// �� ��� [3��]
	if(t>=0)
		printf("%d�ð� %d�� ", t/60, t%60);
	else {
		t += 1440;
		printf("%d�ð� %d�� ", t / 60, t % 60);
	}

	return 0;
}