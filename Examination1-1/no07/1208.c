#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int hour, min, alhour, almin, lefthour, leftmin;

	printf("���� �ð�: ");
	scanf("%d %d", &hour, &min);
	printf("�˶� �ð�: ");
	scanf("%d %d", &alhour, &almin);

	lefthour = alhour - hour;
	leftmin = almin - min;
	if (lefthour < 0)
		lefthour += 23;
	if (leftmin < 0)
		leftmin += 60;
	printf("\n%d�ð� %d�� ", lefthour, leftmin);

	return 0;
}