#include<stdio.h>

/* 알람 시간 출력 1301 곽나영 */
int main() {
	int ph, pm, ah, am, t, finalh, finalm;

	printf("현재 시간: ");
	scanf("%d %d", &ph, &pm);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	if (ph * 60 + pm > ah * 60 + am) {
		ph - 24;
		t = ah * 60 + pm > ah * 60 + am;
		finalh = t / 60;
		finalm = t % 60;
		printf("%d시간 %d분 ", finalh, finalm);
	}
	else {
		t = ah * 60 + am - ph * 60 - pm;
		finalh = t / 60;
		finalm = t % 60;
		printf("%d시간 %d분 ", finalh, finalm);
	}

	

	return 0;
}