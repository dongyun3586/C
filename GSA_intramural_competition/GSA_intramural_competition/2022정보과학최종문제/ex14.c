#include <stdio.h>
#include <string.h>

int main() {
  int i, j = 0;
  char input_words[101];
  int N;
  scanf("%d", &N);
  int count = N;
  for (i = 0; i < N; i++) {
    char first = '0';
    int Alphabet[26] = { 0, };
    scanf("%s", input_words);
    for (j = 0; input_words[j] != '\0'; j++) {
      if (first != input_words[j]) {
        first = input_words[j];
        Alphabet[input_words[j] - 'a'] += 1;
      }
      if (Alphabet[input_words[j] - 'a'] == 2) {
        count -= 1;
        break;
      }
    }
  }
  printf("%d", count);
  return 0;
}
/*
�Է�1
3
level
sos
rotator

�Է�2
3
happy
new
year

�Է�3
4
aba
abab
abcabc
a

�Է�4
2
yzyzy
zyzyz

*/