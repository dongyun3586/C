#include<stdio.h>

void main(void) {
  int i, j, temp, check;
  int num[6] = { 0, };
  srand(time(NULL));

  for (i = 0; i < 6; ) {
    temp = rand() % 45 + 1;
    check = 1;
    for (j = 0; j < 6; j++)
      if (num[j] == temp)
        check = 0;
    if (check == 1)
      num[i++] = temp;
  }
  for (i = 0; i < 6; i++)
    printf("%d  ", num[i]);
  printf("\n");
}