#include <stdio.h>
#define bitsword 32
#define digit(A, B) (((A) >> (bitsword-((B)+1))) & 1)

int main(void) {
  int b, d;
  d = 16777215;
  int show_digit = 7;
  b = digit(d, show_digit);
  printf("%dth bit of %d = %d\n", show_digit, d, b);
  return 0;
}