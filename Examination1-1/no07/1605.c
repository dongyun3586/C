#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int nowh, nowm, alarmh, alarmm, a, b, timeh, timem, c, d;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &nowh, &nowm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &alarmh, &alarmm);

	a = 60 * nowh + nowm;		// a: ����ð� ������ ȯ���� ��
	b = 60 * alarmh + alarmm;	// b: �˶��ð� ������ ȯ���� ��

	if (a > b) {
		c = 1440 - a;
		d = b + c;
		timeh = d / 60;
		timem = d % 60;
	}
	else {
		d = b - a;
		timeh = d / 60;
		timem = d % 60;
	}

	// �� ��� [3��]
	printf("%d�ð� %d�� ", timeh, timem);

	return 0;
}