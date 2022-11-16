#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()

#define EXPRESSION_SIZE 100

typedef char element;

typedef struct  stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();
int precedence(char op);
void infix_to_postfix(element* exp, element* postfix_exp);
element evalPostfix(element* postfix_exp);

int main(void) {
	printf("** ���� ǥ�� �� ���� ǥ�� ��ȯ **\n\n");

	char* expArr[] = { "1+2", "1+2*3", "1*2+3", "(1+2)*3", "4*3-2/1", "5*(4-3)+6/2", "2*((8-2)/2)*5" };
	element postfix_exp[EXPRESSION_SIZE];
	int n = sizeof(expArr) / sizeof(char*);

	for (int i = 0; i < n; i++) {
		printf("���� ǥ���: %s\n", expArr[i]);
		infix_to_postfix(expArr[i], postfix_exp);
		printf("���� ǥ���: %s\n", postfix_exp);
		printf("��� ���: %d\n", evalPostfix(postfix_exp));
		printf("-----------------------------\n");
	}

	return 0;
}

// ������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	if (temp == NULL)return;
	temp->data = item;
	temp->link = top;     // ���� ��带 top�� ���� ����
	top = temp;           // top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		return(top->data);  // ���� top�� ���� ��ȯ
	}
}

// ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

// �������� �켱���� ��ȯ�ϴ� �Լ�
int precedence(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ�⸦ ���� ǥ��� ��ȯ�ϴ� �Լ�
void infix_to_postfix(element* exp, element* postfix_exp) {
	// 1. ���� ���� �� ���� �ʱ�ȭ
	top = NULL;
	char ch, top_op;
	int p = 0;
	int n = strlen(exp);

	// 2. ǥ������ ���(����)����ŭ �ݺ�ó��
	for (int i = 0; i < n; i++) {
		ch = exp[i];
		switch (ch) {
			// 1. �������� ���
		case '+': case '-': case '*': case '/':
			// �� ������ �ƴϰ�, ������ �����ڰ� ch ���� �켱������ ���ų� ������ �����ڸ� ����.
			if (!isStackEmpty() && precedence(ch) <= precedence(peek())) {
				postfix_exp[p++] = pop();
			}
			push(ch);
			break;
			// 2. ���� ��ȣ�� ���
		case '(':
			push(ch);
			break;
			// 3. �ݴ� ��ȣ�� ���
		case ')':
			while ((top_op = pop()) != '(')
				postfix_exp[p++] = top_op;
			break;
			// 4. �ǿ������� ���
		default:
			postfix_exp[p++] = ch;
			break;
		}
	}

	// 3. ���ÿ� �����ִ� �����ڸ� ����Ѵ�.
	while (!isStackEmpty())
		postfix_exp[p++] = pop();
	postfix_exp[p] = '\0';
}

element evalPostfix(element* postfix_exp) {
	// 1. ���� ���� �� ���� �ʱ�ȭ
	top = NULL;
	char ch, op1, op2;
	int value;

	// 2. ǥ������ ���(����)����ŭ �ݺ�ó��
	for (int i = 0; postfix_exp[i] != '\0'; i++) {
		ch = postfix_exp[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			op2 = pop();
			op1 = pop();
			switch (ch) {
			case '+': push(op1 + op2); break;
			case '-': push(op1 - op2); break;
			case '*': push(op1 * op2); break;
			case '/': push(op1 / op2); break;
			}
		}
		else {
			value = ch - '0';
			push(value);
		}
	}

	// 3. ���� exp�� ���� ó���� ��ģ �� ���ÿ� ���� �ִ� ������� pop�Ͽ� ��ȯ
	return pop();
}