#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int ch, cm, ah, am;

	printf("���� �ð�: ");
	scanf("%d %d", &ch, &cm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	if (am < cm) {
		am = 60 + am;
		ah--;
	}
	if (ah < ch)
		ah = ah + 24;

	printf("%d�ð� %d�� ", ah-ch, am-cm);

	return 0;
}