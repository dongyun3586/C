#include<stdio.h>

int main() {
	int inputNum, jungdap, count=0;

	// 1~100 ������ ���� ���� ���� �� ����
	srand(time(NULL));
	jungdap = rand() % 100 + 1;

	// ���� ���
	printf("jungdap: %d\n", jungdap);
	
	printf("1~100������ ���ڸ� �����ϴ� �����Դϴ�.\n");
	
	while (1) {
		// ����ڿ��� 1~100������ ������ �Է¹ޱ�
		printf("1~100������ �� �Է�: ");
		scanf("%d", &inputNum);

		// ���� Ƚ�� 1 ���� ��Ű��
		count++;

		// ����ڰ� �Է��� ���� ���� ��
		if (jungdap < inputNum)
			printf("Ʋ�Ƚ��ϴ�. %d ���� �۽��ϴ�.\n", inputNum);
		else if (jungdap > inputNum)
			printf("Ʋ�Ƚ��ϴ�. %d ���� Ů�ϴ�.\n", inputNum);
		else {
			printf("�����Դϴ�.\n");
			break;
		}
	}

	printf("\n%d������ �������ϴ�.\n", count);

	return 0;
}