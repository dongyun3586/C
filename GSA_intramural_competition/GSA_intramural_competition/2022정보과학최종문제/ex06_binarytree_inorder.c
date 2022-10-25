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
    order(root->left);
    printf("%c", root->data);
    order(root->right);
  }
}

void main(void) {
  int n;
  char d, l, r;
  Node tree[SIZE];
  scanf("%d", &n); getchar();

  for (int i = 0; i < n; i++) {
    scanf("%c %c %c", &d, &l, &r); getchar();
    tree[d - 65].data = d;

    if (l == '.') tree[d - 65].left = NULL;
    else tree[d - 65].left = &tree[l - 65];
    if (r == '.') tree[d - 65].right = NULL;
    else tree[d - 65].right = &tree[r - 65];
  }

  order(&tree[0]);
  printf("\n");
}