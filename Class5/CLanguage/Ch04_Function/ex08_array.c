#include<stdio.h>

int main() {
	// �迭 ���� �� �ʱ�ȭ 
	int arr1[5];					// �ʱ�ȭ ���� ����
	int arr2[5] = { 0,0,0,0,0 };	// arr2[5] = { 0 }
	int arr3[] = { 1,2,3,4,5 };		// �迭�� ������ �� ũ�� ���� ����

	// �迭�� Ư�� ��ҿ� �� ���� => �迭�̸�[index]�� ����
	arr1[0] = 0;
	arr1[1] = 1;

	// for������ �迭�� ��� ���(element) ����ϱ� 
	for (int i = 0; i < 5; i++)
		printf("arr1[%d] = %d\n", i, arr1[i]);

	for (int i = 0; i < 5; i++)
		printf("arr2[%d] = %d\n", i, arr2[i]);

	for (int i = 0; i < 5; i++)
		printf("arr3[%d] = %d\n", i, arr3[i]);

	return 0;
}