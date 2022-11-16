// 백준 1991번: 트리 순회
// https://www.acmicpc.net/problem/1991
#include <stdio.h>
#include <stdlib.h>

#define SIZE 26
typedef char element;

typedef struct treeNode {
	element data;
	struct treeNode* left;
	struct treeNode* right;
} Node;

void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);

int main(void) {
	int n;
	char d, l, r;
	Node tree[SIZE];

	scanf("%d", &n);	getchar();

	// 입력 데이터 저장
	for (int i = 0; i < n; i++) {
		scanf("%c %c %c", &d, &l, &r); getchar();
		tree[d - 65].data = d;
		tree[d - 65].left = (l == '.') ? NULL : &tree[l - 65];
		tree[d - 65].right = (r == '.') ? NULL : &tree[r - 65];
	}

	preorder(&tree[0]);		printf("\n");
	inorder(&tree[0]);		printf("\n");
	postorder(&tree[0]);	printf("\n");

	return 0;
}

void preorder(Node* root) {
	if (root) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(Node* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}