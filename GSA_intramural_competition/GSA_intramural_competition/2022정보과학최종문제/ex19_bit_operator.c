#include <stdio.h>
int X, K;
long long ans;
int i;
int j = 0;

void main() {
  scanf("%d%d", &X, &K);
  for (i = 0;; i++) {
    if (!((X >> i) & 1)) {
      ans |= ((K >> j) & 1) << i;
      j++;
      if (!(K >> j)) break;
    }
  }
  printf("%lld\n", ans);
}