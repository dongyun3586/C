#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int dan, d, jungdap, userdap, score = 0, n;

	printf("������ �� ����? ");
	scanf("%d", &n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		dan = rand() % 8 + 2;
		d = rand() % 8 + 1;
		jungdap = dan * d;

		printf("%d * %d = ", dan, d);
		scanf("%d", &userdap);

		if (userdap == jungdap) {
			printf("�����Դϴ�. \n");
			score++;
		}
		else
			printf("Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�. \n", jungdap);
	}

	printf("%d �� �� %d ���� �¾ҽ��ϴ�. \n", n, score);
	return 0;
}