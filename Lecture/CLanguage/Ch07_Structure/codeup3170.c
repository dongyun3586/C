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
	// ���� �ڷῡ�� �� ã��
	for (int i = 0; i < dap_count; i++)
		if (strcmp(quiz_dap[i].word, str) == 0)
			return quiz_dap[i].num;

	// ���� �信 ������ ���
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(quizzes[i].word, str) == 0)
			sum += quizzes[i].num;
	}

	// ���ο� �� ����
	strcpy(quiz_dap[dap_count].word, str);
	quiz_dap[dap_count].num = sum;
	dap_count++;

	return sum;
}

int main() {
	int n, m;

	// 1) ù° �ٿ� N�� M�� �Էµȴ�.(1<=N,M<=100,000)
	scanf("%d %d", &n, &m);
	Quiz* quizzes = (Quiz*)malloc(sizeof(Quiz) * n);
	quiz_dap = (Quiz*)malloc(sizeof(Quiz) * m);
	w_type* words = (w_type*)malloc(sizeof(w_type) * m);
	int* dap = (int*)malloc(sizeof(int) * m);

	// 2) ��° �ٺ��� N�� ���� ���ڿ� S�� ���� k�� �Էµȴ�. 
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