/* 10000�� ������ ���� ���ݰ� ����ڰ� �� �ݾ��� �Է��ϸ�
�Ž������� ������ ����ϴ� ���α׷� */

#include<stdio.h>

int main_ex06_operator() {
	// ���� ����
	int price, received_money, change;

	// ����� �Է°� �ޱ�
	printf("���� ����: ");
	scanf_s("%d", &price);
	printf("���� �ݾ�: ");
	scanf_s("%d", &received_money);

	// �Ž����� ���
	change = received_money - price;

	// �Ž����� ���
	printf("\n*** �Ž����� ***\n");
	printf("10000��: %d��\n", change / 10000);
	change = change % 10000;

	printf(" 5000��: %d��\n", change / 5000);
	change = change % 5000;

	printf(" 1000��: %d��\n", change / 1000);

	return 0;

}