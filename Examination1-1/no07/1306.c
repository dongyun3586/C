#include<stdio.h>

/* �˶� �ð� ��� 1301 ������ */
int main() {
	int ph, pm, ah, am, t, finalh, finalm;

	printf("���� �ð�: ");
	scanf("%d %d", &ph, &pm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	if (ph * 60 + pm > ah * 60 + am) {
		ph - 24;
		t = ah * 60 + pm > ah * 60 + am;
		finalh = t / 60;
		finalm = t % 60;
		printf("%d�ð� %d�� ", finalh, finalm);
	}
	else {
		t = ah * 60 + am - ph * 60 - pm;
		finalh = t / 60;
		finalm = t % 60;
		printf("%d�ð� %d�� ", finalh, finalm);
	}

	

	return 0;
}