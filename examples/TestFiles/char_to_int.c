#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_int();

int *read_ints();

int main() {
    puts();
    int value = read_int();
    printf("\nvalue = %d\n", value);
    return 0;
}

// 读取正整数或 0
int read_int() {
    int value = 0;  // 用于返回最终的值
    int ch;  // 用于读取字符, 注意它的类型应该是 int

    while( (ch = getchar()) != EOF  &&  isdigit(ch)) {  // 注意下面的算法, 适用于将字符串转换为正整数
        value *= 10;
        value += ch - '0';
    }

    ungetc(ch, stdin);  //把非数字字符退回到流中, 这样它就不会丢失
    return value;
}
