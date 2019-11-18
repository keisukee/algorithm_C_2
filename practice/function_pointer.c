#include <stdio.h>

int addition(int x, int y);       // 足し算
int subtraction(int x, int y);    // 引き算

int main(void){
    int a = 3;
    int b = 5;
    int answer;
    int (*funcp)(int, int);

    funcp = addition;
    answer = (*funcp)(a, b);
    printf("a + b = %d\n", answer);

    funcp = subtraction;
    answer = (*funcp)(a, b);
    printf("a - b = %d\n", answer);

    return 0;
}

int addition(int x, int y) {
    return (x + y);
}

int subtraction(int x, int y) {
    return (x - y);
}