#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int num;
	int order;
} arr;

int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int getIndex(int* sortNums, int num, int n) {
	for (int i = 0; i < n; i++)
		if (num == sortNums[i])
			return i;
	return 0;
}

int main() {
	int n;

	// ù° �ٿ� �������� ���� N�� �Էµȴ�. ( 1 <= N <= 50,000)
	scanf("%d", &n);
	arr* nums = (arr*)malloc(sizeof(arr) * n);
	int* sortNums = (int*)malloc(sizeof(int) * n);

	// ��° �ٿ� �������� �и��Ǿ� N���� ���� �ٸ� �����Ͱ� �Էµȴ�. (���� ����:0~500,000)
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i].num);

	for (int i = 0; i < n; i++)
		sortNums[i] = nums[i].num;

	// �����Ʈ ����
	/*int temp = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (sortNums[j] > sortNums[j + 1]) {
				temp = sortNums[j];
				sortNums[j] = sortNums[j + 1];
				sortNums[j + 1] = temp;
			}*/

			// ������ �迭, ��� ����, ��� ũ��, �� �Լ��� �־���
	qsort(sortNums, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		nums[i].order = getIndex(sortNums, nums[i].num, n);
		printf("%d ", nums[i].order);
	}

	return 0;
}