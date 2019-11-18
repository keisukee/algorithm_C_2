#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#define null(A) (key(st[A]) == key(NULLitem))
static int N, M;
static Item *st;
static int count = 0;

int hash(Key v, int M) {
  return v % M;
}

void STinit(int max) {
  int i;
  N = 0;
  M = 2 * max;
  st = malloc(M * sizeof (Item));
  for (i = 0; i < M; i++)
    st[i] = NULLitem;
}

int STcount() {
  return N;
}

void STinsert(Item item) {
  Key v = key(item);
  int i = hash(v, M);
  while (!null(i))
    i = (i + 1) % M;
  st[i] = item;
  N++;
  printf("N = %d\n", N);
  printf("M = %d\n", M);
  printf("a = %f\n", (double)N/M);
  printf("count = %d\n", count);
}

Item STsearch (Key v) {
  int i = hash (v, M);

  while (!null(i))
    if eq(v, key(st[i])) {
      printf("hoge\n");
      return st[i];
    } else {
      i = (i + 1) % M;
    }
  return NULLitem;
}

void STdelete(Item item) {
  int j, i = hash(key(item), M);
  Item v;
  while (!null (i))
    if eq(key(item), key(st[i]))
      break;
    else
      i = (i + 1) % M;
  if (null(i))
    return;
  st[i] = NULLitem;
  N--;
  for (j = i + 1; !null (j); j = (j + 1) % M, N--) {
    v = st[j];
    st[j] = NULLitem;
    STinsert (v);
  }
}

void search(int number) {
  int i;
  for (i = 0; i < M; i++) {
    if (key(st[i]) == number) {
      printf("%dは%dで見つかりました\n", number, i);
      return;
    }
  }
  printf("%dは見つかりませんでした\n")
}
// 線形探査法