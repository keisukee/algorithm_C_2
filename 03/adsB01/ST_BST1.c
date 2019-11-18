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

link insertR(link h, Item item)
{ Key v = key(item), t = key(h->item);
  if (h == z) return NEW(item, z, z, 1);
  if less(v, t)
    h->l = insertR(h->l, item);
  else h->r = insertR(h->r, item);
  (h->N)++; return h;
}

void STinsert(Item item)
{ head = insertR(head, item); }

void sortR(link h, void (*visit)(Item))
{
  if (h == z) return;
  sortR(h->l, visit);
  visit(h->item); // STsortが呼び出される, STsort(h->item)と同値
  sortR(h->r, visit);
}

void STsort(void (*visit)(Item))
{ sortR(head, visit); }

int max(int x, int y) {
  if (x > y) return x;
  else       return y;
}

// int STheight(link x, int h)
// {
  // int l = STheight(x->l, h);
  // int r = STheight(x->r, h);
  // if (x == NULL)
  //   return 0;
  // else
    // return 1 + max(STheight(x->l), STheight(x->r));
  // else if (STheight(x->l, h) < STheight(x->r, h))
  //   return STheight(x->r, h + 1);
  // else
  //   return STheight(x->l, h + 1);
// }

int heightR(link x)
{
  if (x == z)
    return 0;
  else
    return 1 + max(heightR(x->l), heightR(x->r));
}

int STheight()
{
  return heightR(head) - 1;
}

int ipathlengthR(link x, int level)
{
  if (x == z)
    return 0;
  else
    return level + ipathlengthR(x->r, level + 1) + ipathlengthR(x->l, level + 1);
}

int STipathlength()
{
  return ipathlengthR(head, 0);
}

int epathlengthR(link x, int level)
{
  if (x->r != NULL || x->l != NULL) // 内部節点のとき
    return epathlengthR(x->r, level + 1) + epathlengthR(x->l, level + 1);
  else // 外部節点の場合
    return level;
}
int STepathlength()
{
  return epathlengthR(head, 0);
}

// Stheight： 木の高さを表示
// Stipathlength： 木の内部道長を表示, link->l != NULL || link->r != NULL
// Stepathlength： 木の外部道長を表示, link->l == NULL && link->r == NULL