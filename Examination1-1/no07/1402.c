#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int now_h, now_min, al_h, al_min, al_al2, now_al2;

	printf("���� �ð�: ");
	scanf("%d %d", &now_h, &now_min);
	printf("�˶� �ð�: ");
	scanf("%d %d", &al_h, &al_min);

	now_al2 = now_h * 60 + now_min;
	al_al2 = al_h * 60 + al_min;
	if (al_al2 < now_al2) al_al2 += 24 * 60;
	printf("%d�ð� %d�� ", (al_al2 - now_al2) / 60, (al_al2 - now_al2) % 60);

	return 0;
}