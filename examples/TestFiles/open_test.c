#include <stdio.h>
#include <stdlib.h>

/**
 * 用于测试文件打开和关闭, 将文本中的内容打印到 stdout 中
 */

int main(void) {
    FILE *fp = fopen("test.txt", "r");  // 注意 是 "r", 不是 'r'
    if(fp == NULL) {  // 也可以写成 if(!fp)
        perror("test.txt");
        return EXIT_FAILURE;
    }

    int c;  // 注意读取字符的时候要声明为 int 类型, 而不是 char 类型; 主要原因是为了处理 EOF, 因为有些编译器的 char 类型是 0~255, 而 常量 EOF 一般是 -1
    while(  (c = fgetc(fp))  !=  EOF) {  // 用于将文件的内容打印到 标准输出(stdout) 中
        putchar(c);
    }

    // 用于检测是否读入完毕
    if(ferror(fp))  // ferror 函数检查给定的流是否有错误, 如果没有就返回 0, 否则返回非零数字
        puts("I/O error when reading");
    else if(feof(fp))  // feof 检查给定的流是否到达了文件尾部(end of file), 也就是EOF
        puts("End of file reached successfully");

    if( fclose(fp) != 0) {  // 检查是否成功关闭
        perror("fclose");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
