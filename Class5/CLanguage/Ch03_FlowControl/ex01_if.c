#include<stdio.h>

int main() {

	// 1. ���๮���� �ϳ��� ��� { } ���� ����
	int number;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &number);

	if (number > 0) 
		printf("\n����Դϴ�.");
	
	printf("\n�۾�1 ����\n\n");

	// 2. ���๮���� �� �̻��� ��� { } ���
	int score;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	char grade;

	if (score >= 90) {
		grade = 'A';
		printf("\n����� ������ %d���̰�, ������ %c�Դϴ�.", score, grade);
	}
	printf("\n�۾�2 ����\n\n");

	// 3. ��(0�� �ƴ�)�� ����(0)
	if (0)
		printf("'0'�� ����\n");
	if (1)
		printf("'1'�� ��\n");				// '1'�� ��
	if (2)
		printf("'2'�� ��\n");				// '2'�� ��
	if (-1)
		printf("'-1'�� ��\n");				// '-1'�� ��
	if ('a')
		printf("'a'�� ��\n");				// 'a'�� ��
	if ("�ȳ��ϼ���")
		printf("\"�ȳ��ϼ���\"�� ��\n");	// "�ȳ��ϼ���"�� ��

	return 0;
}