#include<stdio.h>

/* �˶� �ð� ��� 1301 ������ */
int main() {
	int c1, c2, a1, a2, ct, at, rt;

	printf("���� �ð�: ");
	scanf("%d %d", &c1, &c2);
	printf("�˶� �ð�: ");
	scanf("%d %d", &a1, &a2);

	ct = c1 * 60 + c2;
	at = a1 * 60 + a2;
	rt = (at - ct) % 1440;

	printf("%d�ð� %d�� ", rt/60, rt%60);

	return 0;
}