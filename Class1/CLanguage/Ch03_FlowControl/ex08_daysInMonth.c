// ��(1~12)�� �Է��ϸ� �ش� ���� �ϼ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include<stdio.h>

int main_ex08_daysInMonth() {
	int month;

	printf("�� ��?: ");
	scanf("%d", &month);

	switch (month) {			// switch���� ������� �ݵ�� ������ ����̾�� �Ѵ�.
	case 2:
		printf("28��\n");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("30��\n");
		break;
	default:						//  default�� : ���ǰ� ��ġ�ϴ� case�� ������ ����
		printf("31��\n");
		break;
	}

	return 0;
}