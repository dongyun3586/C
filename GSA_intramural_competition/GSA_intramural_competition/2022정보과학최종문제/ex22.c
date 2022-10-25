#include <stdio.h>

int check(char* word) {
  int pd = 0;
  int len = strlen(word);
  while (pd < (int)(len / 2)) {
    if (word[pd] != word[len - pd - 1])
      return 0;
    pd++;
  }
  return 1;
}
int main(void) {
  int i, len, count = 0;
  char* memo[] = { "gwangju", "S", "level",
                 "science", "newjeans", "mom",
                 "dad", "success" };
  printf("%s", *(memo + 3));
  len = sizeof(memo) / sizeof(char*);
  for (i = 0; i < len; i++)
    if (check(memo[i]))
      count++;
  printf("%d", count);
}