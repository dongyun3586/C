#include <stdio.h>
#include <stdlib.h>
#include <string.h>    

typedef int element;
element* stack;
int top = -1;
int size;

typedef struct commandType {
	char c[10];
	char cNum;
	int value;
}cType;

int isStackFull() {
	return (top == size - 1) ? 1 : 0;
}

int isStackEmpty() {
	return (top == -1) ? 1 : 0;
}

void push(element item) {
	if (isStackFull()) {
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	return (isStackEmpty()) ? -1 : stack[top--];
}

element peek() {
	return (isStackEmpty()) ? -1 : stack[top];
}

// 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

int main(void) {
	int n;
	scanf("%d", &n);

	size = n;
	cType* cArr = (cType*)malloc(sizeof(cType) * n);
	stack = (element*)malloc(sizeof(element) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s", cArr[i].c);
		if (strcmp(cArr[i].c, "push") == 0) {
			cArr[i].cNum = 1;
			scanf("%d", &cArr[i].value);
		}
		else if (strcmp(cArr[i].c, "pop") == 0) {
			cArr[i].cNum = 2;
		}
		else if (strcmp(cArr[i].c, "size") == 0) {
			cArr[i].cNum = 3;
		}
		else if (strcmp(cArr[i].c, "isEmpty") == 0) {
			cArr[i].cNum = 4;
		}
		else if (strcmp(cArr[i].c, "peek") == 0) {
			cArr[i].cNum = 5;
		}
	}

	// 명령어 처리 push(1), pop(2), size(3), empty(4), top(5)
	int sum = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		switch (cArr[i].cNum) {
		case 1:
			push(cArr[i].value); //printStack();
			break;
		case 2:
			temp = pop(); //printStack();
			sum += temp;
			printf("%d\n", temp);
			break;
		case 3:
			sum += top + 1;
			printf("%d\n", top + 1);
			break;
		case 4:
			sum += isStackEmpty();
			printf("%d\n", isStackEmpty());
			break;
		case 5:
			sum += peek();
			printf("%d\n", peek());
			break;
		}
	}
	printf("sum = %d\n", sum);
	return 0;
}