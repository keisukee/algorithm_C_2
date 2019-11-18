#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

#define MAX   101
#define TRIAL 20



int main(int argc, char **argv) {
  Item u, v;
  STinit(MAX);
  int allkeys[atoi(argv[1])];          //表にある全てのNを格納(入れた順で)))
  int allkeysindex=0;
  _Bool showtable = atoi(argv[2]);     //全表の値を表示するなら１、しないなら０

  //M=100の表に引数個の値を挿入する
  int cnt;
  for (cnt=0;  cnt<atoi(argv[1]) && cnt<2*MAX;  ) {
    int k = rand();
    key(u) = k;
    v = STsearch(k);

    if (key(v) != key(NULLitem)){
      //printf("Key %d is found in the table.\n", k);
    }
    else {
      cnt++;
      STinsert(u);
      allkeys[allkeysindex++] = key(u);
      //printf("Key %d is not found in the table.\n", k);
    }
  }

  //表の表示
  if(showtable) STshowAll();

  //平均探索回数の調査
  STprintSearchAverage(allkeys, atoi(argv[1]));

  //平均探索回数の調査(不成功探索)
  STprintSearchAverageFail(allkeys, atoi(argv[1]));

  return 0;
}
