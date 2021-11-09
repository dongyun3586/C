#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int num;
	int order;
} arr;

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int getIndex(int* sortNums, int num, int n) {
	for (int i = 0; i < n; i++)
		if (num == sortNums[i])
			return i;
	return 0;
}

int main() {
	int n;

	// 첫째 줄에 데이터의 개수 N이 입력된다. ( 1 <= N <= 50,000)
	scanf("%d", &n);
	arr* nums = (arr*)malloc(sizeof(arr) * n);
	int* sortNums = (int*)malloc(sizeof(int) * n);

	// 둘째 줄에 공백으로 분리되어 N개의 서로 다른 데이터가 입력된다. (값의 범위:0~500,000)
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i].num);

	for (int i = 0; i < n; i++)
		sortNums[i] = nums[i].num;

	// 버블소트 정렬
	/*int temp = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (sortNums[j] > sortNums[j + 1]) {
				temp = sortNums[j];
				sortNums[j] = sortNums[j + 1];
				sortNums[j + 1] = temp;
			}*/

			// 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
	qsort(sortNums, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		nums[i].order = getIndex(sortNums, nums[i].num, n);
		printf("%d ", nums[i].order);
	}

	return 0;
}