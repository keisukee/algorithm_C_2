#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define hl  h->l
#define hr  h->r
#define hll h->l->l
#define hlr h->l->r
#define hrl h->r->l
#define hrr h->r->r

typedef struct STnode* link;
struct STnode {
  Item item;
  link l, r;
  int N;
  int red;
};

static link head, z;

link NEW(Item item, link l, link r, int N, int red) {
  link x = malloc (sizeof *x);
  x->item = item;
  x->l = l;
  x->r = r;
  x->N = N;
  x->red = red;
  return x;
}

void STinit() {
  head = (z = NEW (NULLitem, 0, 0, 0, 0));
}

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

void fixN(link h) {
  int count = 1;
  if (h->l == z) {
    h->l->N = 1;
  } else {
    fixN(h->l);
    count += h->l->N;
  }

  if (h->r == z) {
    h->r->N = 1;
  } else {
    fixN(h->r);
    count += h->r->N;
  }
  h->N = count;
}


link RBinsert(link h, Item item, int sw) {
  Key v = key (item);
  if (h == z)
    return NEW(item, z, z, 1, 1);
  if ((hl->red) && (hr->red)) {
    h->red = 1;
    hl->red = 0;
    hr->red = 0;
  }
  if (less(v, key (h->item))) {
    hl = RBinsert(hl, item, 0);
    if (h->red && hl->red && sw)
      h = rotR (h);
    if (hl->red && hll->red) {
      h = rotR (h);
      h->red = 0;
      hr->red = 1;
    }
  } else {
    hr = RBinsert(hr, item, 1);
    if (h->red && hr->red && !sw)
      h = rotL(h);
    if (hr->red && hrr->red) {
      h = rotL(h);
      h->red = 0;
      hl->red = 1;
    }
  }
  fixN(h);
  return h;
}

void STinsert(Item item) {
  head = RBinsert(head, item, 0);
  head->red = 0;
}

void STshow(link h, int l)
{
  int i = 0;
  if (h != NULL) {
    STshow(h->r, l + 1);
    for (i = 0; i < l; i++)
      printf("\t");
    if (h->red == 1) {
      printf("(%d, %d, R)\n", key(h->item), h->N);
    } else {
      printf("(%d, %d, B)\n", key(h->item), h->N);
    }
    // printf("(%d, %d)\n", key(h->item), h->N);
    STshow(h->l, l + 1);
  }
}

void STshowAll(void)
{ STshow(head, 0); }

void RBLeafNodeCount(link h, int l) {
  int i = 0;
  if (h == z) return;
  if (h != NULL && (h->r != z || h->l != z)) {
    if (h->r->red == 1) {
      RBLeafNodeCount(h->r, l);
    } else {
      RBLeafNodeCount(h->r, l + 1);
    }

    if (h->l->red == 1) {
      RBLeafNodeCount(h->l, l);
    } else {
      RBLeafNodeCount(h->l, l + 1);
    }
  } else if (h->r == z && h->l == z) {
    printf("根から点(%d)に至る経路において出現した黒節点の数: %d\n", key(h->item), l);
  }
}

void RBLeafNodeCountAll(void) {
  RBLeafNodeCount(head, 1);
}