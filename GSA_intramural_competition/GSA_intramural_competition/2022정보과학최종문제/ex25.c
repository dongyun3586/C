#include<stdio.h>

void main(void) {
  int i, j, n, score[13];
  int maxIdx, minIdx, sum = 0;
  float avg;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &score[i]);
  maxIdx = 0, minIdx = 0;
  for (i = 1; i < n; i++) {
    if (score[maxIdx] < score[i])
      maxIdx = i;
    if (score[minIdx] > score[i])
      minIdx = i;
  }
  for (i = 0; i < n; i++) {
    if (i != maxIdx && i != minIdx)
      sum = sum + score[i];
  }
  avg = sum / (float)(n - 2);
  printf("%.2f", avg);
}