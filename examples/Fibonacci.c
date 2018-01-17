#include <stdio.h>
#include <stdlib.h>
#define N 13

// #define USING_FUNCTION_2  // 通过取消注释来激活第二个 fib 函数, 并让第一个 fib 函数失效

/**
 * 斐波那契数列: 从 1, 1 开始: 1 1 2 3 5 8... 下一个数是上两个数的和, 来源于兔子无限繁殖的故事...
 * 函数 fib: 给定一个数 n, 返回第n个斐波那契数
 * 函数 fibs: 给定一个数 n, 返回前n个斐波那契数
 */

int fib(int n);
int *fibs(int n);

int main() {
    for(int i = 1; i <= N; i++) {
        printf("%d ", fib(i));
    }
    putchar('\n');
    int *result = fibs(N);
    for(int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');
    free(result);
    return 0;
}

#ifndef USING_FUNCTION_2
int fib(int n) {
    if(n == 1 || n == 2)
        return 1;
    else
        n -= 2;
    int a, b, c;  // 原理: a, b, c 三个数; 每次循环 之后, abc的值就变成了 b, c, a + b
    a = b = c = 1;
    while(n--) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
#endif

#ifdef USING_FUNCTION_2
int fib(int n) {
    if(n < 3)
        return 1;
    else
        n -= 2;
    int a, b;
    a = b = 1;
    while(n--) {  // 原理: a b 两个数, 每次循环之后, 他们的值变为 b, a+b
        b = a + b;
        a = b - a;
    }
    return b;
}
#endif

int *fibs(int n) {
    int *result = (int *)calloc(n, sizeof(int)), num = n;
    // int *result = (int *)malloc(sizeof(int) * n);
    while(n) {
        result[num - n] = fib(num - n + 1);
        n--;
    }
    return result;
}
