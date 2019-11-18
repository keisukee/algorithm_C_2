#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#define null(A) (key(st[A]) == key(NULLitem))
static int N, M;
static Item *st;



int hash(Key v, int M) {
  return v % M;
}



void STinit(int max) {
  int i;
  N = 0;
  M = max;
  st = malloc(M * sizeof (Item));
  for(i=0; i<M; i++) st[i] = NULLitem;
}



int STcount() {
  return N;
}





void STinsert(Item item) {
  Key v = key(item);
  int i = hash(v, M);
  while(!null(i)) i=(i+1)%M;
  st[i] = item;
  N++;
}




Item STsearch(Key v) {
  int i = hash(v, M);
  while(!null (i)){
    if eq(v, key(st[i]))   return st[i];
    else                   i=(i+1)%M;
  }
  return NULLitem;
}




void STdelete(Item item) {
  int j, i=hash(key(item), M);
  Item v;
  
  while(!null (i)){
    if eq(key(item), key(st[i]))   break;
    else                           i=(i+1)%M;
  }

  if(null(i)) return;
  st[i] = NULLitem;
  N--;

  for(j=i+1; !null(j); j=(j+1)%M, N--) {
      v = st[j];
      st[j] = NULLitem;
      STinsert (v);
    }
}



int CountSearchAverage(Key v, int ave){
  int i = hash(v, M);
  while(!null(i)){
    if eq(v, key(st[i])) {
      return ave;
    }
    else {
      i=(i+1)%M;
      ave++;
    }
  }
  return ave;
}



void STprintSearchAverageFail(Key* allkeys, int N){
  int i=0;
  int average=0;
  while(i<20){
    int k=rand();
    if(key(STsearch(k))==-1) {
      average += CountSearchAverage(k, 1);
      i++;
    }
  }
  printf("(==>) ANSER FOR LINEAR HASH (Fail) : %f\n\n", (double)average/20);
}


void STprintSearchAverage(Key* allkeys, int N){
  int i;
  int k=0;
  int average=0;
  for(i=0; i<N; i++){
    average+=CountSearchAverage(allkeys[i-k], 1);
    if(i==N-1) k=i;
  }
  printf("\n(==>) ANSER FOR LINEAR HASH : %f\n\n", (double)average/N);
}




void STshowAll(){
  int i;
  int setnu=1;                                //行番号を振るための数
  int Ncheck=0;                               //項目数を数えるための数
  printf("\n-------------------------------------------------------------------------------------------------\n");
  for(i=0; i<M; i+=4) {
    if(key(st[i])!=-1) Ncheck++;
    printf("|\t%3d：%7d\t|", setnu, key(st[i]));
    if(setnu==101) {
      printf("\n");
      break;
    }
    if(key(st[i+1])!=-1) Ncheck++;
    if(key(st[i+2])!=-1) Ncheck++;
    if(key(st[i+3])!=-1) Ncheck++;
    printf("\t%3d：%7d\t|", setnu+1, key(st[i+1]));
    printf("\t%3d：%7d\t|", setnu+2, key(st[i+2]));
    printf("\t%3d：%7d\t|\n", setnu+3, key(st[i+3]));
    setnu+=4;
  }
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Num of N in this table : %d\n", Ncheck);
  printf("Occupation alpha(N/M) is : alpha=%4.2f\n", (double)Ncheck/M);
}
