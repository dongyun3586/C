#include <stdio.h>
void change(char* s, int n);
void main() {
  char codes[5][20] = { "gwangju", "science",
                        "academy",  "gifted",
                        "informatics" };
  int c;
  for (c = 0; c < 5; c++) {
    change(codes[c], c);
    printf("%s\n", codes[c]);
  }
}
void change(char* s, int n) {
  char temp;
  int i;
  int j = (strlen(s) - 1);
  for (i = n; i < j; i++) {
    temp = *(s + i);
    *(s + i) = *(s + j);
    *(s + j) = temp;
  }
}