#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int dan, i, jungdap, userdap, n, count=0;

	printf("������ �� ��? ");
	scanf("%d", &n);

	srand(time(NULL));
	for (int a = 0; a < n; a++) {
		// ���� ���� ����
		dan = rand() % 8 + 2; // 2~9
		i = rand() % 9 + 1;	// 1~9
		jungdap = dan * i;

		// ����
		printf("%d * %d = ");
		scanf("%d", &userdap);

		// ���� ��
		if (jungdap == userdap) {
			printf("�¾ҽ��ϴ�. \n");
			count++;
		}
		else
			printf("Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�. \n", jungdap);
	}



	return 0;
}