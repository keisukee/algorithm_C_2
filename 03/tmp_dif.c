#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, d;
  int cities[100];

  while (1) {
    int d, temp, num;
    int dif = 0;
    for (i = 0; i < 100; i++) {
      cities[i] = 0; // 配列の初期化
    }

    scanf("%d", &d);
    if (d == 0) break;

    for (i = 0; i < d; i++) {
      scanf("%d", &num);
      cities[i] = num;
    }
    for (i = d - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {
        if (cities[i] < cities[j]) {
          temp = cities[i];
          cities[i] = cities[j];
          cities[j] = temp;
        }
      }
    }

    for (i = d - 1; i > 0; i--) {
      dif += cities[i] - cities[i-1];
    }
    printf("%d\n", dif);
  }
  return 0;
}


// あなたは、N 個の都市をそれぞれ 1回 ずつ旅行しようとしている。 都市を訪れる順番は様々考えられるが、訪れる都市の温度の変化が大きすぎると体調に響いて大変である。 したがって、隣り合う都市の温度差の絶対値の合計が、最も小さくなるような旅行をしたい。 
// それぞれの都市の気温データが与えられるので、温度差の合計の最小値を求めよ。
// 3
// 10 20 30
// 5
// -10 30 0 20 -30
// 0

