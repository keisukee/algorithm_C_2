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


link splay(link h, Item item) {
  Key v = key (item);
  if (h == z)
    return NEW(item, z, z, 1);

  if (key(h->item) == v) // 追加
    return h;

  if (less(v, key (h->item))) {

    if (key(h->l->item) == v) // 追加
      return rotR(h);

    if (h->l == z)
      return NEW(item, z, h, h->N + 1);

    if (less(v, key (h->l->item))) {
      h->l->l = splay(h->l->l, item);
      h = rotR(h);
    } else {
      h->l->r = splay(h->l->r, item);
      h->l = rotL(h->l);
    }
    return rotR(h);
  } else {

    if (key(h->r->item) == v) // 追加
      return rotL(h);

    if (h->r == z)
      return NEW(item, h, z, h->N + 1);

    if (less(key(h->r->item), v)) {
      h->r->r = splay(h->r->r, item);
      h = rotL(h);
    } else {
      h->r->l = splay(h->r->l, item);
      h->r = rotR(h->r);
    }
    return rotL(h);
  }
}

void STinsert(Item item){
  head = splay(head, item);
}

void correctNodeCount(link h) {
  int count = 1;
  if (h->l == z) {
    h->l->N = 1;
  } else {
    correctNodeCount(h->l);
    count += h->l->N;
  }

  if (h->r == z) {
    h->r->N = 1;
  } else {
    correctNodeCount(h->r);
    count += h->r->N;
  }
  h->N = count;
}

void STNodeCount() {
  correctNodeCount(head);
}
