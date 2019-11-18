#include <stdio.h>
#include <stdlib.h>
#define YEAR 2017
int main(void) {
  int d, n;
  int i = 0;
  int j = 0;

  scanf("%d", &d);

  for (i = 0; i < d; i++) {
    int quotient; // 割り算の商
    scanf("%d", &n);
    quotient = n % YEAR;

    for (j = n - 1; j > 0; j--) {
      // j %= YEAR;
      int r = j;
      if (r >= YEAR) {
        quotient = 0;
        break;
      }
      quotient = (quotient * r) % YEAR;
    }
    printf("%d\n", quotient);
  }
  return 0;
}
