#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int hhour, hminute, ahour, aminute, dhour, dminute;

	printf("���� �ð�: ");
	scanf("%d %d", &hhour, &hminute);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ahour, &aminute);

	if (hhour > ahour) {
		dhour = ahour + 24 - hhour;
		if (hminute > aminute)
			aminute = aminute + 60 - hminute;
		else
			dminute = aminute - hminute;
	}
	else
		dhour = ahour - hhour;
	if (hminute > aminute)
		dminute = aminute + 60 - hminute;
	else
		aminute = aminute - hminute;
	printf("%d�ð� %d�� ", dhour, dminute);

	return 0;
}