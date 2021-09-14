#include <stdio.h>

#define N 5
#define K 3

int A[] = { 1,2,3,4,5 };
int arr[5] = { 0 };

void printArray(int* arr);
void printCombination(int level, int s);

// n�� �����Ϳ��� k�� �̱�
int main() {
	int arr[5];
	int level;		// �� ��°�� �����ϴ°�?

	printCombination(0, 0);

	return 0;
}

// s�� ������: �� level���� ������ ��Ȳ�� ���� ���� level�� ó���� �޶����� ������ ���� ������ �˷���� �Ѵ�.
void printCombination(int level, int s) {
	printf("printCombination(%d, %d)\n", level, s);
	// ���� ���� => level 3�̸� ��� ������ ��Ȳ
	if (level == K) {
		printArray(arr);
		return;
	}

	// ���� �����ϴ� ���� ������ �ش��ϱ� ������ �ݺ����� ����Ѵ�.
	// N=5, K=3, level=0 s~2 => N-K+level
	// N=5, K=3, level=1 s~3
	// N=5, K=3, level=2 s~4
	for (int i = s; i < N - K + level + 1; i++) {
		arr[level] = A[i];
		printCombination(level + 1, i + 1);
	}

	// ���� N=5, K=2���
	// N=5, K=2, level=0 s~3 => N-K+level
	// N=5, K=2, level=1 s~4
	// for(int i=0; i<N-1; i++)		=> 0~3����
	//     for(int j=i+1; j<N; j++)	=> i+1~4����
}

void printArray(int* arr) {
	for (int i = 0; i < K; i++)
		printf("%d ", arr[i]);
	printf("\n");
}