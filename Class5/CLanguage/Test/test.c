#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	// ���� ����
	int dan, i, jungdap, userdap, score = 0, n;

	// ����� �Է� �ޱ�
	printf("�� ����? ");
	scanf("%d", &n);

	// ó��
	srand(time(NULL));
	for (int a = 0; a < n; a++) {
		dan = rand() % 8 + 2;	// 2~9
		i = rand() % 9 + 1;		// 1~9
		jungdap = dan * i;

		printf("%d * %d = ", dan, i);
		scanf("%d", &userdap);

		if (userdap == jungdap) {
			printf("�����Դϴ�. \n");
			score++;
		}
		else
			printf("Ʋ�Ⱦ��. ������ %d �Դϴ�. \n", jungdap);
	}

	// ���� ��� ���
	printf("%d ���� �� %d �� ����\n", n, score);

	return 0;
}
