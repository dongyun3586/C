#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int time, min, a, b;

	scanf("%d %d", &time, &min, &a,&b);

	int h, c;
	if (a > time)
		h = a - time;
	else
		h = a - time + 24;

	if (b > min)
		c = b - min;
	else {
		c = b - min + 60;
		h -= 1;
	}
		
	printf("%d�ð� %d�� %d %d", time,min,a,b);

	return 0;
}