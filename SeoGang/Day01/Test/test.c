#include<stdio.h>

int main() {
	// �迭�� ũ�⸦ 15�� �ø�
	int numArr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int n = sizeof(numArr) / sizeof(int);

	for (int i = 0; i < n; i++)    // �Ǽ��� ���ǽ��� �������� ������
	{
		printf("%d ", numArr[i]);
	}

	return 0;
}