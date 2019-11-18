#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // toupper

int main(void) {
  const static char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int inRadix,outRadix;

  int i, j, n;
  inRadix = 10;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int sum = 0;
    static char buffer[20];
    static char s[20];

    scanf("%d %s", &outRadix, buffer);
    // 文字から数字へ
    for (i = 0; i<(int)strlen(buffer); i++) {
      char *tp = strchr(table, toupper(buffer[i]));
      int val;
      if (tp == NULL) {
        printf("入力された数値が不正です(%c)\n", buffer[i]);
        return -1;
      }
      val = tp - table; // ポインタ同士の差から値が分かる
      if (val >= inRadix) {
        printf("基数(%d)より大きい数字(%c)があります\n",inRadix,*tp);
        return -1;
      }
      sum *= inRadix; // 基数倍する
      sum += val;
      for (i = 0; i < 19 && sum >= 1; i++, sum /= outRadix) {
        s[i] = table[sum % outRadix];
      }

      s[i] = '\0'; // 一応
      for (i--; i >= 0; i--) {
        putchar(s[i]);
      }
      putchar('\n');

    }

    // printf("10進数は%d\n", sum);

  }

// for (;;) {
// printf("出力したい基数はいくつですか？\n");
// scanf("%d", &outRadix);

// if (outRadix >= 2 && outRadix <= 36) //エラー条件
// break;
// printf("基数の形は2～36の間でお願いします。\n");
// }

// for (;;) {
// printf("入力する基数はいくつか入力してください。\n");
// scanf("%d", &inRadix);

// if (inRadix >= 2 && inRadix <= 36) //エラー条件
// break;
// puts("基数の形は2～36の間でお願いします。");
// }

// for (;;) {
// printf("次に入力する%d進数の値を入れてください。\n", inRadix);
// printf("10=A~35=Zとしてください。\n");
// scanf("%s", buffer);
// if (strlen(buffer) <= 20) //エラー条件
// break;
// printf("桁数を減らしてください。\n");
// }

// 変換処理
// まず入力値を10進数に変換

  return 0;
}