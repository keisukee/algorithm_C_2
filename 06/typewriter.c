#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(void) {
  int i, n;
  char alphabets[26] = "abcdefghijklmnopqrstuvwxyz";
  // ASCII: a = 97, z = 122

  for (;;) {
    scanf("%d", &n);
    if (n == 0) break;
    n += 100;
    char *orders = (char *)malloc(sizeof(char) * n);
    scanf("%s", orders);

    // for (i = 0; i < MAX; i++) {
    //   types[i] = '!';
    // }
    // types[0] = 'a'; // 初期設定

    char types[MAX] = "";
    int latest = 0;
    int current_position = 0;
    for (i = 0; i < MAX; i++) {

      if (orders[i] == '+') {
        if (alphabets[current_position] == 'z')
          current_position = 0;
        else
          current_position++;
      } else if (orders[i] == '-') {
        if (alphabets[current_position] == 'a')
          current_position = 25;
        else
          current_position--;
      } else if (orders[i] == '.') {
        types[latest] = alphabets[current_position];
        latest++;
      }
    }
    printf("%s\n", types);
  }

  return 0;
}

// 問題文
// クマのシゲノブくんは、おもちゃのタイプライターを持っている。
// このタイプライターは、aからzまでの小文字のアルファベットで構成されるリールと、それを操作するための3つのボタンからなる。
// ボタンは、リールを1つ前にまわすボタン、後ろにまわすボタン、現在のリールの文字を出力するボタンである。
// ある日、友達であるウサギのアズサくんに手紙を書こうとしたシゲノブくんは、タイプライターが壊れてしまっていることに気がついた。
// 急ぎの用事でタイプライターを修理に出す暇のないシゲノブくんは、 プログラマーであるあなたに「タイプライターと同じ操作で動かすことができるプログラム」を作って欲しいと頼んできた。

// +, -, . の３種類の記号からなる命令列が与えられるので、出力される文字列を求めよ。記号が表す意味は以下の通りである。

// +: リールを1つ前にまわす。(a->b, b->c, ..., y->z, z->a)
// -: リールを1つ後ろにまわす。(z->y, y->x, ..., b->a, a->z)
// .: 現在のリールの文字を1つ出力する。
// なお、リールは初めaを表示している。

// 入力
// 入力は複数のデータセットから成る。 各データセットは、以下の形式で与えられる。

// L
// S
// 1行目に、命令列の長さLが与えられる (1 <= L <= 500)。

// 2行目に、命令列Sが与えられる。 Sは'+', '-', '.'のみから構成される。

// 入力の終了は、"0"と書かれた1行によって示される。

// 出力
// 各データセットに対して、タイプライターが出力する文字列を1行ずつ出力せよ。

// ただし、リールは各データセットの初めごとにaを示すように戻る。

// なお、入力の終了を示す"0"に対しては何も出力しないこと。