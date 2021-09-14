#include <stdio.h>

#define N 5
#define K 3

int A[] = { 1,2,3,4,5 };
int arr[5] = { 0 };

void printArray(int* arr);
void printCombination(int level, int s);

// n개 데이터에서 k개 뽑기
int main() {
	int arr[5];
	int level;		// 몇 번째를 선택하는가?

	printCombination(0, 0);

	return 0;
}

// s는 시작점: 전 level에서 선택한 상황에 따라 이후 level의 처리가 달라지기 때문에 시작 지점을 알려줘야 한다.
void printCombination(int level, int s) {
	printf("printCombination(%d, %d)\n", level, s);
	// 종료 조건 => level 3이면 모두 선택한 상황
	if (level == K) {
		printArray(arr);
		return;
	}

	// 내가 선택하는 것이 범위에 해당하기 때문에 반복문을 사용한다.
	// N=5, K=3, level=0 s~2 => N-K+level
	// N=5, K=3, level=1 s~3
	// N=5, K=3, level=2 s~4
	for (int i = s; i < N - K + level + 1; i++) {
		arr[level] = A[i];
		printCombination(level + 1, i + 1);
	}

	// 만약 N=5, K=2라면
	// N=5, K=2, level=0 s~3 => N-K+level
	// N=5, K=2, level=1 s~4
	// for(int i=0; i<N-1; i++)		=> 0~3까지
	//     for(int j=i+1; j<N; j++)	=> i+1~4까지
}

void printArray(int* arr) {
	for (int i = 0; i < K; i++)
		printf("%d ", arr[i]);
	printf("\n");
}