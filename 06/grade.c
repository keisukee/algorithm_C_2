#include <stdio.h>

int main(void) {
  int i, j, n;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int attend_score = 0;
    int exam_score = 0;
    int score = 0;
    scanf("%d %d", &attend_score, &exam_score);
    score = attend_score + exam_score;

    if (score >= 90) {
      printf("A+\n");
    } else if (score >= 80) {
      printf("A\n");
    } else if (score >= 70) {
      printf("B\n");
    } else if (score >= 60) {
      printf("C\n");
    } else if (score > 0) {
      printf("F\n");
    } else if (score == 0) {
      printf("G\n");
    }
  }
  return 0;
}

// 問題文
// 早稲田大学では、主にA+、A、B、C、F、Gの成績で評価を行っている。 ある授業を担当しているサカモト教授は、毎年以下のとおりに点数をつけ、その点数に応じて成績を決めている。

// 点数評価
// 出席点は、授業への参加内容に応じて20点満点で評価する。
// 理解度確認試験の点数を80点満点とする。
// 成績評価
// 成績評価は、出席点と理解度確認試験の合計点に応じて、以下のとおりに評価する。

// 合計点	成績
// 90 ~ 100	A+
// 80 ~ 89	A
// 70 ~ 79	B
// 60 ~ 69	C
// 1 ~ 59	F
// 0	G
// この講義を受講した学生の出席点と理解度確認試験の点数が与えられるので、上記の評価基準に従ってその学生の成績を判定せよ。

// 入力
// 入力は、以下の形式で表される。

// N
// A 1 E 1
// A 2 E 2
// :
// A N E N

// ここでNは講義を受講した学生の人数、A iはi番目の学生の出席点、E iはi番目の学生の理解度確認試験の点数を表す。

// 制約
// 入力は、以下の条件をすべて満たす。

// 1 <= N <= 1000
// 1 <= i <= N を満たすすべての整数iについて、
// 0 <= A i <= 20
// 0 <= E i <= 80
// 出力
// 出力は、各学生に対する成績判定を1行で出力せよ。

// 入力例
// 3
// 12 70
// 20 80
// 5 30
// 出力例
// A
// A+
// F
