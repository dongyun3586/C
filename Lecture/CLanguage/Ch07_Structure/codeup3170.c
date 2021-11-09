#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char w_type[100];


typedef struct {
	char word[100];
	int num;
} Quiz;
Quiz* quiz_dap;
int dap_count = 0;

int answer(Quiz* quizzes, char* str, int n) {
	// 기존 자료에서 답 찾기
	for (int i = 0; i < dap_count; i++)
		if (strcmp(quiz_dap[i].word, str) == 0)
			return quiz_dap[i].num;

	// 기존 답에 없으면 계산
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(quizzes[i].word, str) == 0)
			sum += quizzes[i].num;
	}

	// 새로운 답 저장
	strcpy(quiz_dap[dap_count].word, str);
	quiz_dap[dap_count].num = sum;
	dap_count++;

	return sum;
}

int main() {
	int n, m;

	// 1) 첫째 줄에 N과 M이 입력된다.(1<=N,M<=100,000)
	scanf("%d %d", &n, &m);
	Quiz* quizzes = (Quiz*)malloc(sizeof(Quiz) * n);
	quiz_dap = (Quiz*)malloc(sizeof(Quiz) * m);
	w_type* words = (w_type*)malloc(sizeof(w_type) * m);
	int* dap = (int*)malloc(sizeof(int) * m);

	// 2) 둘째 줄부터 N줄 동안 문자열 S와 정수 k가 입력된다. 
	for (int i = 0; i < n; i++)
		scanf("%s %d", &quizzes[i].word, &quizzes[i].num);

	for (int i = 0; i < m; i++) {
		scanf("%s", words[i]);
		dap[i] = answer(quizzes, words[i], n);
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", dap[i]);

	return 0;
}