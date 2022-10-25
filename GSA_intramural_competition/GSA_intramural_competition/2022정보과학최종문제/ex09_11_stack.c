#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int element;
element* stack;
int top = -1;
int n;

typedef struct commandType {
  char c[10];
  char cNum;
  int value;
}cType;

int isStackFull() {
  return (top == n - 1) ? 1 : 0;
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

void main(void) {
  scanf("%d", &n);
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

  for (int i = 0; i < n; i++) {
    switch (cArr[i].cNum) {
    case 1:
      push(cArr[i].value);
      break;
    case 2:
      printf("%d\n", pop());
      break;
    case 3:
      printf("%d\n", top + 1);
      break;
    case 4:
      printf("%d\n", isStackEmpty());
      break;
    case 5:
      printf("%d\n", peek());
      break;
    }
  }
}

/*
[실행 예시]
8
push 3
push 4
pop
peek
isEmpty
pop
size
isEmpty

[입력데이터1]
9
isEmpty
pop
peek
push 2
peek
pop
peek
pop
isEmpty

[입력데이터2]
11
push 1
push -2
peek
size
isEmpty
push -1
pop
peek
size
pop
pop
*/