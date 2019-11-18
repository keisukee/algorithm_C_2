#include <stdio.h>
#include <stdlib.h>

#define distance(x, y) (x*x + y*y)
#define in_range(r1, range) (r1 <= range)
#define abs(a) ((a >= 0)? a : -a))

typedef struct {
  int x;
  int y;
} StopCoordinate;

typedef struct {
  int x;
  int y;
  int is_caught; // 0だったら捕まっていない。1だったらゲットされる
} NokemonCoordinate;


int main(void) {
  int i, j, k, n;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int stops, population, range;
    int x, y;
    int get_count = 0;
    scanf("%d %d %d", &stops, &population, &range);

    StopCoordinate stop_locations[stops];
    for (j = 0; j < stops; j++) {
      scanf("%d %d", &x, &y);
      stop_locations[j].x = x;
      stop_locations[j].y = y;
    }

    NokemonCoordinate nokemon_locations[population];
    for (j = 0; j < population; j++) {
      scanf("%d %d", &x, &y);
      nokemon_locations[j].x = x;
      nokemon_locations[j].y = y;
      nokemon_locations[j].is_caught = 0;
    }

    for (j = 0; j < stops; j++) {
      for (k = 0; k < population; k++) {
        int x_distance = (stop_locations[j].x - nokemon_locations[k].x);
        int y_distance = (stop_locations[j].y - nokemon_locations[k].y);
        int distance_to_nokemon = distance(x_distance, y_distance);

        if (distance_to_nokemon <= range*range)
          nokemon_locations[k].is_caught = 1;
      }
    }

    for (k = 0; k < population; k++) {
      if (nokemon_locations[k].is_caught == 1) get_count++;
    }
    printf("%d\n", get_count);
  }
  return 0;
}


// 問題文
// 巷ではノケモンGOと呼ばれるゲームが流行っている。 ノケモンGOは、主人公がノケストップと呼ばれる場所を順に移動し、ノケモンを沢山集めることが目的である。

// ある日、主人公のサトツは、 N 個のノケストップを順に訪れた。 これらのうちの i 個目のノケストップは、座標 (p_i, q_i) に存在する。

// また、ノケモンはフィールド上に M 匹おり、それぞれ座標 (x_i,y_i) にいる。

// ノケストップに滞在中、サトツはノケストップからの距離が L の範囲内（ちょうど L や 0 も含む）にいるノケモンを全て収集することができる。 なお、社会的要請により、ノケモンGOでは移動中にノケモンを捕まえようとすることが禁止されている。

// この日にサトツが集めることのできるノケモンは最大で何匹か答えよ。

// 制約
// 1 <= N <= 500
// 0 <= M <= 500
// 0 <= L <= 2 × 10^4
// -10^4 <= p_i, q_i, x_i, y_i <= 10^4
// 与えられる値は全て整数である。

// 入力
// 1つの入力ファイルは複数のテストケースからなる。

// 入力ファイルの最初の1行目にはテストケースの個数 T が記される (1 <= T <= 50)。

// 2行目以降には、 T 個のテストケースが記述されており、各テストケースは次の形式で表される。

// N M L
// p_1 q_1
// p_2 q_2
// :
// p_N q_N
// x_1 y_1
// x_2 y_2
// :
// x_M y_M
// (p_i, q_i) は i 個目のノケストップの座標。

// (x_i, y_i) は i 匹目のノケモンのいる座標。

// 出力
// 各テストケースに対して、サトツが何匹ノケモンを集めることのできるかを1行ずつ出力せよ。

// 入力例
// 2
// 3 5 2
// 0 5
// 6 5
// 6 3
// -1 6
// -1 7
// 2 3
// 4 2
// 6 4
// 1 2 0
// 3 0
// 2 0
// 3 0
// 出力例
// 2
// 1
// 1ケース目は以下の図のようなノケストップとノケモンの配置である。 2ケース目のように、ノケストップにノケモンがいることもある。