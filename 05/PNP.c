#include <stdio.h>
#define NUMBER 10000

int main(void) {
  int i, j, n;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int flg = 1; // 1だったらtrue（YES）, 0だったらfalse（NO）
    int a_count = 0;
    int np_count = 0;
    int n_flg = 0;
    int p_flg = 0;
    char text[NUMBER];
    for (j = 0; j < NUMBER; j++) {
      text[j] = 'X';
    }

    scanf("%s", text);
    for (j = 0; j < NUMBER; j++) {
      if (text[j] == 'X') break;
      if (text[j] == 'N' && text[j+1] == 'A') flg = 0;
      if (text[j] == 'A') a_count++;
      if (n_flg == 0 && text[j] == 'N') {
        n_flg = 1;
      } else if (p_flg == 0 && n_flg == 1 && text[j] == 'P') {
        n_flg = 0;
        np_count++;
      } else if (p_flg == 0 && n_flg == 0 && text[j] == 'P') {
        n_flg = 0;
        np_count++;
      }
    }

    if (a_count != 1 || np_count != 3) flg = 0;
    if (p_flg == 0 && n_flg == 1) flg = 0;
    if (flg == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}

// 1.Aの前はP
// 2.Aの後はN*P（Pは一個）
// 3.Aの前側は、Pが2つ

// 問題文
// P≠NP予想（P≠NPよそう、英: P is not NP）は、計算複雑性理論（計算量理論）におけるクラスPとクラスNPが等しくないという予想である。 P対NP問題（PたいNPもんだい、英: P versus NP）と呼ばれることもある。 理論計算機科学と現代数学上の未解決問題の中でも最も重要な問題の一つであり、 2000年にクレイ数学研究所のミレニアム懸賞問題の一つとして、この問題に対して100万ドルの懸賞金がかけられた。 Wikipedia「P≠NP予想」より
// 文字A、N、Pからなる文字列 S が与えられる。 与えられた文字列 S が、文字列PPAPからP = NPの置換を使って生成可能ならばYES、不可能ならばNOと出力せよ。
// P = NPの置換とは、PをNPに置き換える、または、NPをPに置き換えることである。
// 例えば、文字列NPPAPは、PPAP先頭のPをNPに置換することで、生成可能である。

// 制約
// 1 <= |S| <= 1000
// S はA、N、Pのみからなる。
// 入力
// 1つの入力ファイルは複数のテストケースからなる。

// 入力ファイルの最初の1行目にはテストケースの個数 T が記される (1 <= T <= 50)。

// 2行目以降には、$T$個のテストケースが記述されており、各テストケースは次の形式で表される。

// S
// 出力
// 各テストケースに対して、YESまたはNOを1行ずつ出力せよ。

// 入力例
// 3
// NPPAP
// PPNAP
// NNPNNPAP
// 出力例
// YES
// NO
// YES
// 出典 情報理工学科オリエンテーション 2017