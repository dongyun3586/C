#include<stdio.h>

int main() {
	// rand()�Լ��� ���� ���� ������ ���� seed�� ����
	srand(time(NULL));

	// ���� ����
	int inputNum, jungdap, count=0;

	// 1~100 ������ ���� ���� ����
	jungdap = rand() % 100 + 1;

	// ���� �Ұ� ���ڿ� ���
	printf("1~100������ ���ڸ� �����ϴ� �����Դϴ�.\n");

	// �׽�Ʈ�� ���� ���� ���
	printf("\n����: %d\n\n", jungdap);
	
	// ������ ���� �� ���� �ݺ� ����
	while (1) {
		// ���� Ƚ�� 1 ���� ��Ű��
		count++;

		// ����ڿ��� 1~100������ ������ �Է¹ޱ�
		printf("������?: ");
		scanf("%d", &inputNum);

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

	// ���� Ƚ�� ���
	printf("\n%d�� ���� �������ϴ�.\n", count);

	return 0;
}