#include <stdio.h>

/* pf は，戻り値がvoid,引数がint1個の関数へのポインタ */

void func(void (*pf)(int), int x)
{
    pf(x);
}

void func_A(int n)
{
    printf("Aを使った処理 n = %d\n", n);
}

void func_B(int n)
{
    printf("Bを使った処理 n = %d\n", n);
}

int main()
{
    /* 例1：関数を指すポインタ変数 */
    void (*p)(int);     /* ポインタ変数を宣言 */

    p = func_A;
    p(1);                   /* ポインタを使って関数呼び出し */
    printf("p = %p\n", p);  /* アドレスを表示 */

    p = func_B;
    p(1);
    printf("p = %p\n", p);


    /* 例2：関数のアドレスを別の関数の引数として渡す */

    func(func_A, 10);   /* 関数名 func_A を引数として呼び出し． */
    func(func_B, 20);   /* 関数名 func_B を引数として呼び出し． */
    return 0;
}