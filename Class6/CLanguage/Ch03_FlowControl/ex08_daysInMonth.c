#include<stdio.h>

int main_ex08_daysInMonth() {
	int month;

	printf("���� �Է��Ͻÿ�: ");
	scanf("%d", &month);

	switch (month) {			// switch���� ������� �ݵ�� ������ ����̾�� �Ѵ�.
	case 1:
	case 2:
		printf("���̴�\n");
		break;						// break�� ����� �����غ���.
	case 3:
		printf("ȯŸ\n");
		break;
	case 4:
		printf("��ī������Ʈ\n");
		break;
	default:						//  default�� : ���ǰ� ��ġ�ϴ� case�� ������ ����
		printf("default\n");
		break;
	}

	return 0;
}