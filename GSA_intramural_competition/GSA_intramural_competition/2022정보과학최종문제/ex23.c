#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 6
void main(void) {
  int i;
  int total = 0;
  char word[N + 1];
  struct Computer_Subject {
    char subject[20];
    int score;
  }
  CS[] = { {"Programming", 80},
         {"System_Analysis", 90},
         {"Database", 80},
         {"Architecture", 90},
         {"Network", 80},
         {"Internet", 90} };
  for (i = 0; i < N; i++) {
    word[i] = CS[i].subject[i];
  }
  word[i] = '\0';
  printf("%s", word);
}