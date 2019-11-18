#include <stdio.h>
#include <stdlib.h>
#define MAX 35

int main(void) {
  int d, n;
  int i, j, k;

  scanf("%d", &d);
  for (i = 0; i < d; i++) {
    char words_block[MAX][MAX];
    int count = 0;

    for (j = 0; j < MAX; j++) {
      for (k = 0; k < MAX; k++) {
        words_block[j][k] = 'X'; // 配列の初期化
      }
    }

    scanf("%d", &n);

    for (j = 0; j < n; j++) {
      scanf("%s", words_block[j]);
    }

    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
        if (words_block[j][k] == 'W' && words_block[j][k+1] == 'S' && words_block[j][k+2] == 'D') count++;
        if (words_block[j][k] == 'D' && words_block[j][k+1] == 'S' && words_block[j][k+2] == 'W') count++;
        if (words_block[j][k] == 'W' && words_block[j+1][k] == 'S' && words_block[j+2][k] == 'D') count++;
        if (words_block[j][k] == 'D' && words_block[j+1][k] == 'S' && words_block[j+2][k] == 'W') count++;
      }
    }
    printf("%d\n", count);
  }
}

// 条件
// WSD, もしくはDSWを見つける
// array[N][N]のうち、array[i]...array[i+2]がWSD or DSW
// array[N][N]のうち、array[i][j]...array[i+2][j]がWSD or DSW
