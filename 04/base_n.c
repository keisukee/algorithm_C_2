#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void base_n(int, int);

int main(void) {
  int i, j, n;
  char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    char buf[1024];
    char ss[1024];
    int decimal_num, base_n_num;
    scanf("%d %d", &base_n_num, &decimal_num);

    base_n(base_n_num, decimal_num);
    printf("\n");
  }
  return 0;
}

void base_n(int base, int decimal) {
  char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if (decimal > 0) {
    int remain; // 余り0だったら、table[0], 余り16だったら、table[16]
    remain = decimal % base;
    decimal /= base;
    base_n(base, decimal);
    printf("%c", table[remain]);
  }
}

// 問題文
// 日常、我々は数として10進数に多く触れている。
// 一方で、コンピュータの世界では2進数や16進数などが多く使われる。
// 例えば、10進数における5は2進数で表すと101であるし、10進数における140は16進数で表すと8Cである。

// 10進数で表された数を、指定された基数(n進数でいうところのn)に変換したとき、どう表されるか求めよ。

// 制約
// 入力は以下の条件をすべて満たす。

// 1 <= N <= 100
// 1 <= i <= N を満たすすべての整数iについて、
// 2 <= Bi <= 32
// 1 <= Ti <= 1,000,000,000

// N
// B1 T1
// B2 T2
// :
// BN TN
// 補足
// この問題の制約上、出力は最大でも30文字を超えない。
// 基数が11以上の場合、各桁に利用する数値は0〜9および下記の表のように大文字のアルファベットを用いよ。
// 文字	A	B	C	D	E	F	G	H	I	J	K
// 表す数値(10進数)	10	11	12	13	14	15	16	17	18	19	20
// 文字	L	M	N	O	P	Q	R	S	T	U	V
// 表す数値(10進数)	21	22	23	24	25	26	27	28	29	30	31
// 入力例 1
// 2
// 2 5
// 16 140
// 出力例 1
// 101
// 8C
// 問題文にも示した通り、10進数における5は2進数では101、10進数における140は16進数では8Cと表される。

// 入力例 2
// 4
// 16 43
// 3 73
// 11 42
// 32 32582057
// 出力例 2
// 2B
// 2201
// 39
// V2AD9