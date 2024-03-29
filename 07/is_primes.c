#include <stdio.h>
#include <math.h>

int is_prime(int number) {
  int i;
  int flg = 0;
  int limit = sqrt(number);

  for (i = 2; i <= limit; i++) {
    if (number % i == 0) flg = 1;
  }

  return flg;
}

int main(void) {
  int i, j, n;

  while (1) {
    int number;
    int flg = 0; // flg=1だったらYES、flg=0だったらNO
    scanf("%d", &number);

    int limit = sqrt(number);

    if (number == 0) break;

    for (i = 2; i <= limit; i++) {
      for (j = i; j <= number; j++) {
        if (j * i == number && is_prime(j) == 0 && is_prime(i) == 0) flg = 1;
      }
    }

    if (flg == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}



// 問題文
// 正の整数 N が与えられる。 N が 2 つの素数の積で表せる場合は "YES" そうでないならば "NO" を出力せよ。 なお、同じ 2 つの素数の積でも良いことに注意せよ。

// 入力
// 入力は複数のデータセットから成る。 各データセットは、以下の形式で与えられる。

// N
// N は素数の積で表されるか判定する整数を表す (1 <= N <= 10000)。

// 入力の終了は、"0"と書かれた1行によって示される。

// 出力
// それぞれのデータセットに対して、"YES" または "NO" を 1 行ずつ出力せよ。

// なお、入力の終了を示す"0"に対しては何も出力しないこと。

// 入力例
// 6
// 100
// 3
// 25
// 0
// 出力例
// YES
// NO
// NO
// YES