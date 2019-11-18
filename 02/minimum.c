#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  scanf("%d", &n);

  int i = 0;
  for (i = 0; i < n; i++) {
    int a, b, c, min;
    scanf("%d %d %d", &a, &b, &c);
    min = abs(a - b);
    if (min > abs(b - c)) min = abs(b - c);
    if (min > abs(c - a)) min = abs(c - a);
    printf("%d\n", min);
  }
}

// 問題文
// 3つの整数が与えられるので、それらのうち2つの整数を組み合わせて差の絶対値が最も小さくなるようにしたときの差の絶対値を求めよ。

// 制約
// NとAijは整数で与えられ、以下の制約を満たす。

// 1 <= N <= 100
// -10000 <= Aij <= 10000 (1 <= i <= N, 1 <= j <= 3)
// 入力
// 入力は以下の形式で与えられる。

// N
// A11 A12 A13
// A21 A22 A23
// :
// AN1 AN2 AN3

// 入力例
// 4
// 2 6 8
// 10 5 20
// -2 -6 2
// 1000 -200 -1500

// 出力例
// 2
// 5
// 4
// 1200