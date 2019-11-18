#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, n;

  char alphabets[100] = "abcdefghijklmnopqrstuvwxyz";
  n = 100;
  char *orders = (char *)malloc(sizeof(char) * n);
  orders[0] = 'z';
  orders[1] = 'a';
  orders[2] = 'c';

  printf("%c\n", alphabets[10]);
  printf("%c\n", alphabets[1]);
  printf("%c\n", alphabets[5]);
  printf("%c\n", alphabets[5] + 1);
  printf("%s\n", alphabets);
  printf("%s\n", orders);
  printf("%c\n", orders[1] + 1);
  printf("%c\n", orders[0] - 1);


  return 0;
}