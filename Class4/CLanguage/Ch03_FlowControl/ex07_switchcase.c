#include<stdio.h>

int main_ex07_switchcase() {
	int buttonNum;

	printf("����� ��ư ��ȣ(1~4��)�� �����ϼ���: ");
	scanf("%d", &buttonNum);

	switch (buttonNum) {			// switch���� ������� �ݵ�� ������ ����̾�� �Ѵ�.
	case 1:
		printf("�ݶ�\n");
		break;						// break���� ������ switch ~ case���� �������´�.
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