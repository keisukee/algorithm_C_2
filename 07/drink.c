#include <stdio.h>
#define MAX 1000

int main(void) {
  int i, j, n;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int drinks;
    int total_cost = 0;
    int bottles_1_price = 120;
    int bottles_5_price = 360;
    int bottles_9_price = 600;
    int bottles_15_price = 960;
    int bottles_25_price = 1600;
    int bottles_50_price = 3000;
    int bottles_86_price = 5000;

    int bottles_1_count = 0;
    int bottles_5_count = 0;
    int bottles_9_count = 0;
    int bottles_15_count = 0;
    int bottles_25_count = 0;
    int bottles_50_count = 0;
    int bottles_86_count = 0;

    scanf("%d", &drinks);
    while (drinks >= 86) {
      drinks -= 86;
      bottles_86_count++;
    }
    while (drinks >= 50) {
      drinks -= 50;
      bottles_50_count++;
    }
    while (drinks >= 25) {
      drinks -= 25;
      bottles_25_count++;
    }
    while (drinks >= 15) {
      drinks -= 15;
      bottles_15_count++;
    }
    while (drinks >= 9) {
      drinks -= 9;
      bottles_9_count++;
    }
    while (drinks >= 5) {
      drinks -= 5;
      bottles_5_count++;
    }
    while (drinks >= 1) {
      drinks -= 1;
      bottles_1_count++;
    }
    total_cost += bottles_86_count * bottles_86_price;
    total_cost += bottles_50_count * bottles_50_price;
    total_cost += bottles_25_count * bottles_25_price;
    total_cost += bottles_15_count * bottles_15_price;
    total_cost += bottles_9_count * bottles_9_price;
    total_cost += bottles_5_count * bottles_5_price;
    total_cost += bottles_1_count * bottles_1_price;
    printf("%d\n", total_cost);
  }
  return 0;
}

// 問題文
// カズノリ君は「ラボライフ！」というゲームの熱狂的なプレイヤーである。

// このゲームはLP（ラボチク・ポイント）を消費してプレイをする。 LPは時間とともに回復するが、課金アイテムであるラボ力りょくドリンクを使うと、瞬時にLPを全回復することができ、ゲームを有利に進めることができる。

// 明日から、新しいイベント「りんりん♪輪講フェスティバル」が開催されることになった。 上位入賞報酬が欲しいカズノリ君は、ラボ力ドリンクの購入が不可欠だと考えている。 ラボ力ドリンクの価格表は以下のようになっている。

// 本数 (#Bottles)	値段 (Price)
// 1	120 Yen
// 5	360 Yen
// 9	600 Yen
// 15	960 Yen
// 25	1600 Yen
// 50	3000 Yen
// 86	5000 Yen
// イベントは定期的に開催されているので、報酬を手に入れるために必要なラボ力ドリンクのおおまかな本数はわかっている。 しかし、ラボ力ドリンクの買い方によっては同じ本数でもお金が無駄になってしまうことがある。

// そこでカズノリ君は、ある本数のラボ力ドリンクの購入に必要な最少の金額を求めるプログラムを作成してほしいとあなたに頼んできた。 なお、カズノリ君は常に各イベントに全力を注ぎ込むため、ラボ力ドリンクを余らせるような買い方はしないことに注意せよ。

// 制約
// 入力は、以下の条件をすべて満たす。

// 1 <= D <= 100
// 1 <= i <= D を満たすすべての整数iについて、
// 1 <= Ni <= 1000
// 入力
// 入力は以下の形式で表される。

// The input is given with the following format.

// D
//   N1
//   N2
//   :
//   ND
  
// ここで D はイベントの回数、 Ni は i 回目のイベントに必要なラボ力ドリンクの数を表す整数である。

// 出力
// 出力は、各イベントごとに指定された本数のラボ力ドリンクの購入に必要な最少の金額を出力せよ。

// 入力例
// 2
// 55
// 85
// 出力例
// 3360
// 5280
// 1回目のイベントでは、（50本+5本）として購入すると、最も金額が安くなる。
// 2回目のイベントでは、（50本+25本+9本+1本）として購入すると5360円となるが、（50本+15本+15本+5本）として購入すると5280円となり、これが最少の金額である。
// 86本5000円の方が安いが、カズノリ君はラボ力ドリンクを余らせるような買い方はしない。お金が勿体ない、本末転倒じゃないか、と思うかもしれないが、気にしてはいけない。