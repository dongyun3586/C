#include<stdio.h>
#include<stdlib.h>  // rand(), srand() ����
#include<time.h>    // time() ����

int main() {
	// rand()�Լ��� ���� ���� ������ ���� seed�� ����
	srand(time(NULL));

	// ���� ����
	int n, dan, su, jungdap, response, score = 0;

	// ������ ���� ��� ���� �Է¹ޱ�
	printf("������ �� ����? ");
	scanf("%d", &n);

	// ��� ������ŭ ������ ���� �ݺ� ���
	for (int i = 1; i <= n; i++) {
		// ���� ���� ����
		dan = rand() % 8 + 2;		// 0~7�� 2~9�� ����
		su = rand() % 9 + 1;		// 0~8�� 1~9�� ���� 
		jungdap = dan * n;

		// ������ ���� ���
		printf("%d * %d = ", dan, su);

		// ����� �Է�
		scanf("%d", &response);

		// ���� üũ
		if (response == jungdap) {
			printf("�����Դϴ�.\n\n");
			score++;
		}
		else
			printf("Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�.\n\n", jungdap);
	}

	// ��� ���
	printf("\n%d �� �� %d ���� �¾ҽ��ϴ�.\n", n, score);

	return 0;
}