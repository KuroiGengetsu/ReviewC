# 最后的复习

进行最后的复习, 所有的程序都放在 [final]() 文件夹中

## 目录

- [10.参数为数组的函数定义-一维数组排序](#48)

- [31.编写函数对字符串中的字符进行排序操作](#31)

- [34.读取一个文本排序后保存到源文件中](#34)

- [35.计算等差等比序列的和](#35)

- [36.求水仙花数](#36)

- [43.gets与scanf](#43)

- [48.一维数组排序](#48)

## 31

编写函数, 对字符串中的字符进行排序操作

```C
#include <stdio.h>
#include <string.h>

void sorted(char *src);

/**
 * 31. 编写函数, 对字符串中的字符进行排序操作
 */

int main() {
    char s[] = "awkudhawfawfbalwflihiscwbkjqn";
    printf("%s\n", s);
    sorted(s);
    printf("%s\n", s);
    return 0;
}

void sorted(char *src) {
    int len = strlen(src), i, j;
    for(i = 0; i < len; i++) {
        for(j = 0; j < i; j++) {
            if(src[i] < src[j]) {
                char tmp = src[j];
                src[j] = src[i];
                src[i] = tmp;
            }
        }
    }
}

```

## 34

如何 打开/读写文本文件, 结合31点, 编写程序读取一个文本文件, 排序后, 保存到源文件中

```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sorted(char *src);
char store[300000] = "";

int main() {
    FILE *fp = fopen("./test.txt", "r+");
    if(!fp) {
        printf("./test.txt error!\n");
        exit(1);
    }
    int ch;
    while((ch = fgetc(fp)) != EOF) {
        char tmp[2] = {ch, '\0'};
        strcat(store, tmp);
    }
    sorted(store);
    rewind(fp);
    fprintf(fp, "%s", store);
    fclose(fp);
    printf("%s\n", store);
}

void sorted(char *src) {
    int len = strlen(src), i, j;
    for(i = 0; i < len; i++) {
        for(j = 0; j < i; j++) {
            if(src[i] < src[j]) {
                char tmp = src[j];
                src[j] = src[i];
                src[i] = tmp;
            }
        }
    }
}
```

## 35

编写函数计算等差或者等比序列的和

```C
#include <stdio.h>
#include <math.h>

// an = a1 + (n-1)d, 其中 an 是第n项, a1 是第一项, n 是第几个, d 是公差
double sum_of_arithmetic(double a1, double d, double n) {
    double sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a1 + (i-1) * d;
    return sum;
}

// 等比序列的和 an = a1 * q^(n-1), an 是通项, a1 是首项, q 是公比
double sum_of_geometric(double a1, double q, double n) {
    double sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a1 * pow(q, i-1);
    return sum;
}

int main() {
    printf("%g\n", sum_of_arithmetic(1, 3, 5));
    printf("%g\n", sum_of_geometric(1, 3, 5));
    return 0;
}
```

#36

求水仙花数

```C
#include <stdio.h>

void narcissistic() {
    for(int i = 100; i < 1000; i++) {
        int a, b, c;
        a = i % 10 / 1;       // 个位数
        b = i % 100 / 10;     // 十位数
        c = i % 1000 / 100;   // 百位数
        if(a*a*a + b*b*b + c*c*c == i)
            printf("%d ", i);
    }
}

int main() {
    narcissistic();
    return 0;
}
```

# 43

`char src[100];`

`gets(src)` 和 `scanf("%s", src)` 的区别

对于

```txt
    Nice    to meet you!
It's a fine day today.
```

这段从键盘输入的两行, 注意 Nice 前面有四个空格

- `gets(src)` 可以读入 `    Nice    to meet you!`, 连同四个空格将第一行读进去

- `scanf("%s", src)` 可以读入 `Nice`

所以, gets 可以读入一行字符串, scanf 可以读入第一个单词

# 48

编写函数对一维数组进行排序

```C
// 从小到大
void sorted(int src[], int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            if(src[i] < src[j]) {
                int tmp = src[j];
                src[j] = src[i];
                src[i] = tmp;
            }
}
```
