// 백준 1991번: 트리 순회
// https://www.acmicpc.net/problem/1991
#include <stdio.h>

#define SIZE 26
typedef char element;

typedef struct treeNode {
	element data;
	struct treeNode* left;
	struct treeNode* right;
} Node;

void order(Node* root) {
	if (root) {
		printf("%c", root->data);
		order(root->left);
		order(root->right);
	}
}

int main(void) {
	int n;
	char d, l, r;
	Node tree[SIZE];

	scanf("%d", &n);	getchar();

	for (int i = 0; i < n; i++) {
		scanf("%c %c %c", &d, &l, &r); getchar();
		tree[d - 65].data = d;
		if (l == '.')
			tree[d - 65].left = NULL;
		else
			tree[d - 65].left = &tree[l - 65];
		if (r == '.')
			tree[d - 65].right = NULL;
		else
			tree[d - 65].right = &tree[r - 65];
		//tree[d - 65].left = (l == '.') ? NULL : &tree[l - 65];
		//tree[d - 65].right = (r == '.') ? NULL : &tree[r - 65];
	}

	order(&tree[0]);
	printf("\n");
	return 0;
}



//void order(Node* root) {
//	if (root) {
//		order(root->left);
//		printf("%c", root->data);
//		order(root->right);
//	}
//}
//
//void order(Node* root) {
//	if (root) {
//		order(root->left);
//		order(root->right);
//		printf("%c", root->data);
//	}
//}