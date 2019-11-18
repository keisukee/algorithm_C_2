#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct STnode* link;
struct STnode { Item item; link l, r; int N; };
static link head, z;

link NEW(Item item, link l, link r, int N)
{ link x = malloc(sizeof *x);
  x->item = item; x->l = l; x->r = r; x->N = N;
  return x;
}

void STinit()
{ head = (z = NEW(NULLitem, 0, 0, 0)); }

int STcount(void) { return head->N; }

Item searchR(link h, Key v)
{ Key t = key(h->item);
  if (h == z) return NULLitem;
  if eq(v, t) return h->item;
  if less(v, t) return searchR(h->l, v);
  else return searchR(h->r, v);
}

Item STsearch(Key v)
{ return searchR(head, v); }

link rotR(link h)
{
  link x = h->l;
  int a = x->l->N;
  int n = h->N;
  h->l = x->r; x->r = h;
  x->N = n;
  h->N = n - a;
  return x;
}

link rotL(link h)
{
  link x = h->r;
  int a = x->r->N;
  int n = h->N;
  h->r = x->l; x->l = h;
  x->N = n;
  h->N = n - a;
  return x;
}

link insertT(link h, Item item)
{ Key v = key(item);
  if (h == z) return NEW(item, z, z, 1);
  if (less(v, key(h->item)))
    { h->l = insertT(h->l, item); h = rotR(h); }
  else
    { h->r = insertT(h->r, item); h = rotL(h); }
  (h->N)++; return h;
}

void STinsert(Item item)
{ head = insertT(head, item); }

void sortR(link h, void (*visit)(Item))
{
  if (h == z) return;
  sortR(h->l, visit);
  visit(h->item);
  sortR(h->r, visit);
}

void STsort(void (*visit)(Item))
{ sortR(head, visit); }

void STshow(link h, int l)
{
  int i = 0;
  if (h != NULL) {
    STshow(h->r, l + 1);
    for (i = 0; i < l; i++)
      printf("\t");
    printf("(%d, %d)\n", key(h->item), h->N);
    STshow(h->l, l + 1);
  }
}

void STshowAll(void)
{ STshow(head, 0); }

// カウントを正しく計算するには，以下の関数を
// 修正する必要がある．
// InsertT: insertTの修正には，insertRが参考になる．
// ただし，insertTには木の回転操作（rotR,
// rotL）が含まれることに注意すること．

// rotL
// rotR