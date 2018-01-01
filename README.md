# C语言程序设计

# 1. 标识符

**标识符(inentifier)** 就是 **变量 、 函数 、 类型等** 的名字， 他们以 `大小写字母 、 数字 、 下划线_` 组成， 不能以数字开头。

C是一种  **大小写敏感的语言**。

下列C语言 `关键字` 是保留的， 不能作为标识符使用：

||||||
|:-:|:-:|:-:|:-:|:-:|
| auto | do | goto | signed | unsigned |
| break | double | if | sizeof | void |
| case | else | int | static | volatile |
| char | enum | long | struct | while |
| const | extern | register | switch |
| continue | float | return | typedef |
| default | for | short | union |

# 2. 基本数据类型的范围

在C语言中， 仅有4中基本数据类型—— **整型 、 浮点型 、 指针 、 聚合类型（数组、结构体、共同体等）**。

## 整型

整型包括 **字符 、 短整型 、 整型 、 长整型**， 他们分别都分为 **有符号(signed)** 和 **无符号(unsigned)** 两种版本。

> 整型值之间相互之间大小的规则：
`长整型至少应该和整型一样长， 而整型至少应该和短整型一样长`

注意： `标准并没有规定长整型必须比短整型长， 只是规定它不得比短整型短`

> 源代码见于 [type_size.c](https://github.com/KuroiGengetsu/ReviewC/blob/master/examples/type_size.c) 或在 `CppReference.chm` 搜索 `Numeric limits`

我的输出结果如下:

```
/**
 * 1 字节表示 -128~127 or 0~255
 * 2 字节表示 -32768~32767 or 0~65536
 * 4 字节表示 -2147483648~2147463647 or 0~4294967296
 * 8 字节表示 -92233720368547758087~92233720368547758088 or 0~18446744073709551616
 */

sizeof char = 1
sizeof short = 2
sizeof int = 4
sizeof long = 4
sizeof long long = 8

sizeof unsigned char = 1
sizeof unsigned short = 2
sizeof unsigned int = 4
sizeof unsigned long = 4
sizeof unsigned long long = 8

sizeof float = 4
sizeof double = 8
sizeof long double = 12

CHAR_BIT   = 8
MB_LEN_MAX = 2

CHAR_MIN   = -128
CHAR_MAX   = +127
SCHAR_MIN  = -128
SCHAR_MAX  = +127
UCHAR_MAX  = 255

SHRT_MIN   = -32768
SHRT_MAX   = +32767
USHRT_MAX  = 65535

INT_MIN    = -2147483648
INT_MAX    = +2147483647
UINT_MAX   = 4294967295

LONG_MIN   = -2147483648
LONG_MAX   = +2147483647
ULONG_MAX  = 4294967295

LLONG_MIN  = -9223372036854775808
LLONG_MAX  = +9223372036854775807
ULLONG_MAX = 18446744073709551615

FLT_RADIX    = 2
DECIMAL_DIG  = 21
FLT_MIN      = 1.175494e-038
FLT_MAX      = 3.402823e+038
FLT_EPSILON  = 1.192093e-007
FLT_DIG      = 6
FLT_MANT_DIG = 24
FLT_MIN_EXP  = -125
FLT_MIN_10_EXP  = -37
FLT_MAX_EXP     = 128
FLT_MAX_10_EXP  = 38
FLT_ROUNDS      = 1
FLT_EVAL_METHOD = 2
FLT_HAS_SUBNORM = 1
```

# 3. 表达式的值 and 运算符的优先级

## 操作符优先级与结合性 Operator precedence and associativity

表如下:

| 优先级 | 操作符 | 描述 | 结合性 |
| :--: | :--: | :-- | :--: |
|1| `++ --` | 前缀自增与自减 | 从左到右 |
|| `()` | 函数调用 ||
|| `[]` | 数组下标 ||
|| `.` | 结构体与联合体成员访问 ||
|| `->` | 结构体与联合体成员通过指针访问 ||
|| `(type){list}` | 复合字面量(C99) ||
|||||
|2| `++ --` | 后缀自增与自减 | 从右到左 |
|| `+ -` | 一元加与减(正负号) ||
|| `! ~` | 逻辑非与逐位非 ||
|| `(type)` | 类型转换 ||
|| `*` | 间接访问运算符(解引用) ||
|| `&` | 取址 ||
|| `sizeof` | 取大小 ||
|| `_Alignof` | 对齐要求(C11) ||
|||||
|3| `* / %` | 乘法 除法 模(取余) | 从左到右 |
|4| `+ -` | 加减法 ||
|5| `<< >>` | 逐位左移及右移 ||
|6| `< <=`<br />`> >=` | 小于 小于等于<br />大于 大于等于 ||
|7| `== !=` | 相等 不等于 ||
|8| `&` | 逐位与 ||
|9| `^` | 逐位异或 ||
|10| `|` 逐位或 ||
|11| `&&` | 逻辑与 ||
|12| `\|\|` | 逻辑或 ||
|||||
|13| `?:` | 三元条件 |从右到左|
|||||
|14| `=` | 赋值 |从右到左|
|| `+= -=` | 以和及差赋值 ||
|| `*= /= %=` | 以积 商 余数赋值 ||
|| `<<= >>=` | 以逐位左移及逐位右移赋值 ||
|| `&= ^= \|=` 以逐位与、异或及或赋值 ||
|||||
|15| `,` | 逗号 |从左到右|

## 例题

根据下面变量的声明和初始化, 计算下列每个表达式的值。
每个表达式使用的是初始值，彼此间毫无关联。

```C
int a = 10, b = -25;
int c = 0, d = 3;
int e = 20;
```

| 表达式 | 值 | 说明 |
| :--: | :--: |:--|
| `b` | -25 |  |
| `b++` | -24 |  |
| `--a` | 9 |  |
| `a / 6` | 1 | a 是整型 |
| `a % 6` | 4 |  |
| `b % 10` | -5 |  |
| `a << 2` | 40 | `<<1` 相当于乘2, `<<2` 相当于乘4 |
| `b >> 3` | -4 | `>>1` 相当于除以2 |
| `a > b` | 1 | 真 |
| `b = a` | 10 | 把a赋值给b, 故为a的值 |
| `b == a` | 0 | 假 |
| `c && a` | 0 | c 为 0, 故为假。 除0外的所有数都是真， 包括正负浮点数 |
| `c \|\| a` | 1 | a为真 |
| `b ? a : c` | 10 | b为-25, 是真, 因此表达式为a的值 |
| `a += 2` | 12 |  |
| `a %= 6` | 4 |  |
| `d = a > b` | 1 | 操作符`>`的优先级高于赋值操作符`=`， 先计算 a > b 然后再赋值,   a > b 为真, 故 d = 1 |
| `a = b = c = d` | 3 | 因为 `=` 是右结合性， 因此从右向左计算， 最右边是 d, 因此 a b c 都被赋值为d, 故为3 |
| `e = d + (c = a + b) + c` | -27 | 优先性 `(c = a + b)` > `+` > `=`, 分析过程： 首先第一个 `=` 是右结合性， 所以先计算 `e = ` 右边的值， 当计算到 `d +` 时， 发现右边有个括号， 于是先计算括号里的， 括号里面是 `c = a + b`, 所以 c 被赋值为 -15, 继续， `d + -15 + -15` 为 -27， 因此e被赋值为-27; 经过这个式子之后， c 的值变为 -15。 |
| `a + b * 3` | -65 | 乘法`*` 优先于 加法`+` |
| `b >> a - 4` | -1 | `+` 优先于 `>>`, 因此先计算 `a - 4`, 再计算 `>>` |
| `a != b != c` | 1 | `!=` 是左结合性， 因此从左往右计算， 先计算 `a != b`， 为真， 所以 `a != b` 变成1， 然后 `1 != c` 也是真， 所以表达式的值为1 |
| `a != a == a` | 0 | `!=` 与 `==` 优先级相同， 由于都是左结合性， 所以从左边开始计算， 先计算 `a != a`, 为假， 也就是0, 然后 `0 == a` 为假, 故表达式的值为假， 也就是0 |
| `a != a != a` | 1 | `!=` 为左结合性， 所以先计算 左边的 `a != a`, 为假， 然后 `0 != a`， 为真， 所以表达式的值为1 |
| `a == a == a` | 0 | `==` 是左结合性， 所以先计算左边的 `a == a`, 为真， 也就是1， 然后 `1 == a` 为假， 因此表达式的值为0 |
| `d < a < e` | 1 | `<` 为左结合性， 所以先计算左边的值。 `d < a` 为真， 也就是1， 然后 `1 < e`也为真， 所以表达式的值为1 |
| `e > a > d` | 0 | `>` 为左结合性， 所以先计算左边的 `e > a`, 为真， 然后计算 `1 > d`, 为假， 所以表达式的值为0 |
| `a - 10 > b + 10` | 1 | 加减法优先于 `>` |
| `a > c \|\| ++a > b` | 1 | 因为 `\|\|` 为左结合性， 所以先计算 `a > c`， 为真， 这里由于 `||` 的短路， 所以不再计算右边的值， 所以表达式的值为1， 并且 由于没有计算右边的表达式， 所以 `a` 并没有自增 |
| `a > c && ++a > b` | 1 | `&&` 左结合性， 先计算左边的表达式， `a > c` 为 1， 然后计算右边的表达式， `++a`, 即 a先自增, 然后 `a > b` 为真(这里的a是已经自增的a), `1 && 1` 所以为 1 |
| `a -= d > 20 ? c++ : d--` | 7 | `-=` 是右结合性， 所以先计算右边的， 右边是个三目运算符， 由于 `d > 20` 为假， 所以三目运算符的的结果为 `d--`, 由于是后缀自减， 所以运算完之后 d 才自减。 总的来说就是 `a -= 3`, 所以表达式的值为 7。 运算完该表达式之后， c 的值不变， d 的值自减。 |
| `a -= a += a /= a *= 99` | 0 | 这些赋值操作符都是右结合性， 所以从最右端开始算: 首先, `a *= 99`, a 的值变为 `990`, 接着 `a /= 990`, a 变为 `1`, 然后 `a += 1`, a 变为 `2`, 然后 `a -= 2`, a 变为0。注意在运算的过程中a被赋值了好几次 |
| `a = d > 20 ? c++ : d-- && c == 0 \|\| a < 0` | 1 | 先计算的是三目运算符, 由于 `d > 20` 为假, 所以三目运算符的结果是 `d--`, 然后 `d && c == 0` 为真， 因此 `||` 被短路，所以 `a = 1`  |

# 4. 字符 and 转义字符

## 转义序列

| Escape sequence | 描述 | 表现 |
| :-- | :-- | :-- |
| `\'` | 单引号 *single quote* | byte `0x27` |
| `\"` | 双引号 *double quote* | byte `0x22` |
| `\?` | 问号 *question mark* | byte `0x3f` |
| `\\` | 反斜杠 *backslash* | byte `0x5c` |
| `\a` | 叮~ *audible bell* | byte `0x07` |
| `\b` | backspace, 可以删除前面的字符, 可叠加 | byte `0x08` |
| `\f` | 缩进大概7个空格 - *new page* | byte `0x0c` |
| `\n` | 换行 *newline* | byte `0x0a` |
| `\r` | 回车 *carriage return*, 就是把该行前面的字符都屏蔽, 如 `"awfa\rz"` 只会打印 `z` | byte `0x0d` |
| `\t` | 水平制表符 *horizontal tab* | byte `0x09` |
| `\v` | 垂直制表符 *vertical tab*, 可以将下一行第一个字符与本行最后一个字符后边对齐 | byte `0x0b` |
| `\nnn` | 八进制的转义字符(八进制没有8,9两个数字), `\0~\377`不会报错, 再高会超范围而编译失败, 其中`\0~\200` 为有效字符, `\201 ~ \377` 都是 `?` | byte nnn |
| `\xnn` | 十六进制的转义字符, `\x00~\xff` | byte nn |
| `\unnnn` | `\u1000~\uffff` | code point U+nnnn |
| `\Unnnnnnnn` | `\U000000a0~\U7fffffff` | code point U+nnnnnnnn |

## 字符 and 字符串

`'a'` 是字符

`"a"` 是字符串 `a\0`


字符及字符串

```C
char ch = 'a';  // 单个字符变量
ch = 'b';  // 可以改变

const char A = 'a';  // 字符常量, 只能赋值一次, 也就是只能初始化

char str[] = "world";  // 字符串, 定义的同时赋值, 可以不指定长度, 这里会分配6个字节: world\0
str[0] = 'k';  // 可以继续赋值

const char NJUPT[] = "http://www.njupt.edu.cn";  // 字符串常量, 用于那些不需要改变的字符串, 可以不指定长度, 会自动分配

char a[100];  // 字符串, 只定义
gets(a);  // 键盘输入一行, 可以有空格制表符, 遇到换行停止读取, 不会读入\n
scanf("%s", a);  // 键盘输入一个单词, 即从第一个非空白的字符开始到下一个空白结束, 空白指的是 空格, \t, \n
sprintf(a, "%dhello%d", 3, 4);  // 按照格式打印到字符串中 sprintf(目的字符串, 格式, 参数列表), 定义在 <stdio.h>

char *p = "CPP";  // 使用指针指向堆中的字符串
putchar(*p);  // 可以使用 间访运算符 访问第一个元素
putchar(*(p+1));  // 访问第二个元素
putchar(p[0]);  // 可以像数组一样用下标调用

```

二维字符串
```C
// 定义并初始化二维字符串, 第二维的数100不可少, 空间开大点可以, 字符串常量一般放在 main() 函数的外面
char URLS[][100] = {
    "http://mirrors.njupt.edu.cn/",
    "http://software.njupt.edu.cn/",
    "http://lib.njupt.edu.cn/",
    "http://mail.njupt.edu.cn/"
};
puts(URLS[0]);  // 打印第一维的字符串, 输出 `http://mirrors.njupt.edu.cn/`, 注意puts()会自动换行

char const (*p)[100] = URLS;
puts(p[3]);  // 可以像上边那样使用下标来使用它, 打印 http://mail.njupt.edu.cn/
puts(*(p + 3));  // 也可以这样使用

putchar(URLS[2][14]);  // 打印 p
putchar(   *( *(p+2) + 14)   );  // 打印 p
```

# 13. 指针表示数组元素

## 一维数组

源代码见 [./examples/one_dev_int_array.c](https://github.com/KuroiGengetsu/ReviewC/blob/master/examples/one_dev_int_array.c)

```C
/**
 * 用指针指向各种数组
 */

void test_int() {
    // 指向一个数组的方法
    int one_dev[10];  // 只定义, 还没有初始化
    int *p1 = one_dev;  // 指向数组头
    int *p2 = &one_dev[0];  // 指向数组头
    int *p3 = one_dev + 3;  // 指向数组第四个元素
    int *p4 = &one_dev[3];  // 指向数组第四个元素
    int *p_end = one_dev + 10 - 1;  // 指向数组尾, 10 是数组长度

    int *p6, *p7;
    p6 = one_dev;  // 指向数组头
    p7 = one_dev + 9;  // 指向数组尾

    *p1 = 1;  // one_dev[0] = 1;
    *(p1 + 1) = 2;  // one_dev[1] = 2;
    *(p1 + 9) = 10;  // one_dev[9] = 10;  // *p_end = 10;
    printf("one_dev[0] = %d, one_dev[1] = %d, one_dev[9] = %d\n", *p1, *(p1 + 1), *p_end);
    // return;  // return nothing
}
```

## 二维数组

如何用指针指向二维数组, 以及如何访问二维数组中的元素 或 修改元素的值
源代码见 [./examples/two_dev_double_array.c](https://github.com/KuroiGengetsu/ReviewC/blob/master/examples/two_dev_double_array.c)

```C
void test_double() {
    double arr[ROW][COLUMN] = {
        {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9},  // 由于只写了9个数, 所以最后一个数是 0
        {1.0, 4.0, 9.0, 16.0, 25.0, 36.0, 49.0, 64.0, 81.0, 100.0},
        {124.5, 314.1, 1e-3, 3.6e-4, 66.3, 22.3, 233.3, 16.4, 13.8, 1e-8}
    };

    // 指向二维数组
    double (*head)[COLUMN] = arr;  // head 指向二维数组arr头, 也就是 arr[0], 并不是 arr[0][0]
    double (*p1)[COLUMN] = arr + 1;  // p1 指向 二维数组第二行, 也就是 arr[1]
    double (*end)[COLUMN] = arr + ROW - 1;  // end 指向最后一行

    // 指向元素
    double *p2 = &arr[0][0];  // 指向第一个元素
    double *final_one = p2 + (COLUMN * 3) - 1;  // final_one 指向最后一个元素
    double *final_one2 = *end + COLUMN - 1;  // 指向最后一个元素, 注意 是 *end, 因为 end 多了一个维度

    // 访问, %g 既可以打印 %f, 又可以打印 %e, 会把末尾多余的0去掉
    printf("arr[1][4] = %g\n", *(*(head+1) + 4));  // 打印 25
    printf("arr[2][4] = %g\n", *(p2 + (COLUMN * 2) + 4)  );  // 打印 66.3
    printf("arr[2][9] = %g\n", *((*end) + 9));  // 打印 1e-008, 等同于 *final_one
    printf("arr[2][8] = %g\n", *(final_one2-1));  // 打印 13.8
}
```

## 例一 Sentence Smash

例题都是 [CodeWars](http://www.codewars.com/r/C7F7sA) 上的题

[Arrays](https://www.codewars.com/kata/search/c?beta=false&q=&r=-8&tags=Arrays)

编写函数 `char *smash(const char **words, size_t count)`, 让一个二维字符串数组中的字符串都拼接在一起并用空格隔开, 返回这个新字符串。
例如, 传入 `"hello", "world"`, 返回 `"hello world"`

源代码见 [Sentence_Smash.c](https://github.com/KuroiGengetsu/MyCodeWars/blob/master/C_code/Sentence_Smash.c)

```C
#include <stdio.h>
#include <stdlib.h>

char *smash(const char** words, size_t count) {
    char *result = malloc(sizeof(char) * 200);  // 稍微开大一点不要紧, 因为题目没有明确要求
    int k = 0;
    for(int i = 0; i < count; i++) {
        const char *s = words[i];  // 指向字符串的开头
        while(*s) {
            result[k++] = *s++;
        }
        result[k++] = ' ';
    }
    result[k-1] = '\0';  // 将最后一个空格替换成 '\0'
    return result;
}

int main()
{
    const cahr *words[] = {
        "hello", "world"
    };
    const char *expected = "hello world";  // 这种写法是在编译时就在堆里生成了常量 "hello world", 然后用指针指向它, 运行速度会稍微慢一些
    char *received = smash(words, sizeof(words) / sizeof(words[0]));
    printf("%s : %s\n", expected, received);
    free(received);

    return 0;
}


```

# 17. 全局变量 and 局部变量 (作用域 Scope)

每个变量在定义的时候都会有一个作用的区域，也就是只能在一定区域才能被访问。这个区域就叫做 **作用域(Scope)**

例如，函数的局部变量的作用域仅限于该函数的函数体，因此， 有两个特点:

* 其他无法通过这些变量的名字访问他们

* 可以给不同作用域的变量起同一个名字

作用域一共分为四种: *文件作用域*, *函数作用域*, *代码块作用域*, *原型作用域*

## 1. 代码块作用域 and 局部变量

位于一对花括号 `{}` 的所有语句称为一个代码块。 当代码块处于嵌套时， 内层定义的变量只能在内层访问， 而内层可以访问外层的变量。 如果有同名的变量， 那么 **内层的变量会屏蔽外层的变量**。 

实际上在代码块作用域中的变量就是平时所说的局部变量。

> 提示: 避免在嵌套的代码块中出现相同名字的变量名， 因为它只会增加调试程序的负担。

> 注意函数的形参也是在函数的代码块内, 注意不要重定义。

```C
void function(int a, int b) {  // a, b 作用于函数function代码块
    int c = 0;  // c 作用于函数function代码块
    while(c < 5) {  // while 代码块
        int a = 0;  // 作用于 while, 这里的 a 会屏蔽 上边的 a
        // 更多代码 ...
        c++;
    }
    for(int b = 1; b < 10; b++) {  // for 代码块, b 会屏蔽 外层的 b
        // ...
    }
}

```

## 2. 文件作用域(file scope) and 全局变量

在 **任何代码块之外** 声明的变量都具有 **文件作用域**， 这些变量也叫全局变量。

全局变量在一个文件中到处都可以访问(除非被屏蔽), 但是他们的范围不止局限于一个文件, 实际上, 使用 `#include` 指令包含进来的文件中的全局变量也是可以使用的, 就像是直接在该文件中定义的一样。

## 3. 原型作用域(prototype)

它只适用于在定义函数原型的时候声明的参数名。

```C
int add(int addend, int augend);  // 原型作用域, 你甚至可以定义为 int add(int, int);

int main() {
    // ...
}

int add(int a, int b) {  // 形参, 代码块作用域, 参数名没必要和函数原型保持一致
    return a + b;
}

```

## 4. 函数作用域(function scope) (没必要了解, 更不要使用)

***不建议使用，没必要了解***

***永远不要用到这个写法***

适用于语句标签， 用于 `goto` 语句。

> 遵循一个原则: 一个函数中的所有语句标签必须唯一。

`我不会给例子`

# 18. 宏替换 and 带参宏替换

## \#define

### 直接利用 \#define 替换

永远打印 **hello world!**

```C
#define do_forever for(;;)
// 如果一行写不下, 可以在一行的末尾加上 反斜杠 '\' 来在下一行继续写

int main() {
    do_forever {
        puts("hello world!");
    }
    return 0;
}
```

### 宏

\#define 允许将参数替换到文本中, 这种实现成为宏(macro), 格式:

`#define name(parameter-list) expression`

* **parameter-list** 就是参数列表, 用逗号分开, 他们可能出现在后面的表达式中, 要记住, 参数列表的左括号必须紧挨着name, 否则就会被当成要替换的表达式。

> 问题: 注意结尾不用写分号, 因为你在调用的时候肯定会补上一个分号的。 如果你在宏的表达式后面写了分号, 到时候就会出现两个分号, 虽然, 实际上没有什么影响。

#### 例子与问题:

1. `#define POW2(x)   x * x`<br />这个表达式会将 *x* 替换为 *x * x*, 看上去没问题, 比如 *POW2(4)* 就是 *4 * 4*, 但是, 当你使用 *POW(3+1)*时, 就会出问题了: 预处理器会将它替换为 *3+1 * 3+1*, 其结果是 7, 因为 \* 的优先级高, 并不是期待的 16。 解决的方案就是将所有的参数以及整个表达式用括号逐个括起来, 也就是 `#define POW2(x) ((x) * (x))`, 这样做就是万无一失了。

2. `#define PRINT(FORMAT, VALUE) printf("The value is"  FORMAT "\n", VALUE)`, 提示: 邻近的字符串常量会自动拼接, 因此这里的 *FORMAT* 必须由字符串常量给出, 就比如 `"%d"` 或 `"%c"` 之类的。 这样就可以直接打印一个值而不用写整个printf语句。

3. `#define ADD_TO_SUM( sum_number, value) sum ## sum_number += value`, 提示: \#\# 结构可以从分离的文本片段创建标识符。 这个例子的作用是将value 的值加到 sum_number 上。 比如 `ADD_TO_SUM(5, 25)` 就会将 25 加到 变量 `sum5`, 即 `sum5 += 25`, 这种使用方法必须可以拼成一个变量名， 否则就是非法的。

### 为什么使用宏

使用宏可以频繁地替换一些常用的表达式, 所以， 函数与宏有什么长处与短处？

1. 为什么有些语句不使用函数: <br />有时候, 使用函数进行一些简单的操作反而比直接使用表达式更加繁琐, 使用宏会在程序的规模和速度都有优势。

2. 使用宏可以完成一些函数无法做到的事情, 这是由于宏是与类型无关, 在写函数的时候, 传入的参数都要有类型, 而使用宏却并不需要类型, 这就是宏的强大之处。

这是一个完成求两个数最大值的宏：
`#define MAX(a, b)  ( (a) > (b)  ?  (a)  :  (b)  )`

这是一个动态分配空间的宏, (**注意结尾没有分号!**)：
`#define MALLOC(n, type)  ( (type *)malloc((n) * sizeof(type)) )`

```C
char *str = MALLOC(25, char);
// char *str = ( (char *)malloc((25) * sizeof(char)) );  // 会被替换为这个
```

### 带副作用的宏

<font color=red >当宏的参数在表达式中出现的次数多于 **1** 的时候, 就会很危险!!!</font>

```C
#define MAX(a ,b)  ((a) > (b) ? (a) : (b))
// ...
x = 5;
y = 8;
z = MAX(x++, y++);
printf("x = %d, y = %d, z = %d\n", x, y, z);
```

可以想象, 这个代码有多恐怖:

`z = ((x++) > (y++) ? (x++) : (y++))`

即使你了解了运算符的优先级, 你也未必能看懂这个代码执行的结果究竟是多少。 实际上， 较大的值自增了两次， 较小的值自增了一次。 在比较的时候， x 与 y 都自增, 比较晚之后, 较大的那个值会自增。

这和预期的结果并不一样, 本来只是期待比较完之后自增一次, 而实际上却自增了两次, 所以这很容易出现奇怪的结果。因此使用宏替换时要谨慎!

### 命名约定 -- **全部大写**

\#define 宏 的行为与函数还是有区别的, 为了让别人和自己能够清楚地认识到你在使用宏而不是函数, **统一约定宏的名称一律使用大写**, 这样就一目了然。

### 与函数进行比较

| 属性 | \#define宏 | 函数 |
| :- | :- | :- |
| 代码长度 | 每次使用宏时, 宏代码都被插入到程序中， 除了非常小的宏之外, 程序的长度都会大幅度增长 | 函数代码只出现于一个地方, 每次调用这个函数的时候, 都调用同一份代码 |
| 执行速度 | 更快 | 存在函数调用、返回的额外开销 |
| 操作符优先级 | 宏参数的求值是在所有周围表达式的上下文环境里, 除非他们加上括号, 否则邻近操作符的优先级可能会产生不可预料的结果 | 函数的参数只在调用时求值一次, 它的结果值传递给函数, 函数的返回值更容易预测 |
| 参数求值 | 参数每次用于宏定义时, 他们都将重新求值, 由于多次求值, 具有副作用的参数可能产生不可预料的结果 | 参数在函数被调用前只求值一次, 在函数中多次使用参数并不会导致多种求值过程, 参数的副作用并不会造成特殊的问题 |
| 参数类型 | 宏与类型无关, 只要对参数的操作是合法的, 它可以适用于任何参数类型 | 函数的参数与类型有关, 如果参数的类型不同, 就需要使用不同的函数, 即使他们执行的任务是相同的 |

# 19. 结构体

> C语言提供了两种 **聚合数据类型*(aggregate data type)*** : 数组和结构

结构也是值的集合, 但可以是不同的类型, 这些值被称为 **成员*(member)***。

一个结构中的成员的长度未必一样, 因此不能使用下标来访问成员, 相反, 每个成员都有各自的 **名字**, 可以通过他们的名字来访问。

## 基础知识

### 结构的声明

声明一个结构时, 必须包含所有成员的类型和名字, 语法如下:

`struct tag { member-list } variable-list ;`

?????? > 注意: *tag* 和 *variable-list* 至少出现一个, *tag* 就是结构体的标签, 也叫名字, *variable-list* 是这个结构体的变量列表, 每个结构体的变量就具有各自的成员。

#### 例子1

```C
// 两个不同的结构体
struct {
    int    a;
    char   b;
    float  c;
} x;  // 分号不要丢

struct {
    int    a;
    char   b;
    float  c;
} y[20], *z;  // 分号不要丢
```

这个例子有两个结构体, 虽然看上去他们的成员相同, 但实际上, 他们不是同一个结构体!。

第一个结构体声明了一个结构体变量 *x*, x 拥有 a, b, c 三个成员

第二个结构体声明了一个 **有20个结构体变量的数组** 和 一个 **结构体指针**。

需要注意的是: z 这个指针可以指向 y 中的任意一个元素, **但是**, **z 不能指向 x!**, 虽然他们看上去有同样的成员, 但即使是这样, `z = &x` 这样的语句也是非法的。

所以, 为了解决这个问题, 需要给结构体加上标签 ***tag***

#### 标签 tag

```C
struct mystruct {  // mystruct 就是标签
    int   a;
    char  b;
    float c;
};  // 分号不要丢

void test(void) {
    struct mystruct x;
    struct mystruct y[20], *z;
}
```

上面这个代码, 中, *mystruct* 就是这个结构体的标签, 用它声明的变量 x, y, z  现在属于同一个结构体的变量。 所以你可以让 z 指向 x: `z = &x;`, 这是完全合法的。

但是每次都使用 *struct mystruct* 来声明变量会显得太麻烦, 所以灵活运用 *typedef* 关键字可以更加有效:

```C
typedef struct {  // 标签可以省略
    int   a;
    char  b;
    float c;
} mystruct;  // mystruct 现在是一个变量类型, 可以用它来声明结构体变量

void test(void) {
    mystruct x, y[20], *z;
}
```

> 提示: 如果想在多个文件中使用同一个结构体, 那么就应该把该结构体的声明放在头文件中, 用的时候可以包含进来。

#### 结构成员 *member*

结构体成员可以是各种各样的类型, 如下所示:

```C
struct COMPLEX {
    int a;
    int b[20];
    long *lp;
    mystruct s;  // 使用的是上面的 typedef 的 mystruct
    mystruct *sp;
    mystruct *sy[20];
};
```

#### 直接访问

操作符 点: `.`

使用方法: **结构体变量名.成员名**

点操作符 `.` 和 下标操作符 `[]` 具有相同的优先级, 所以不必加上括号, 除非你不放心

例子:  源代码见[./examples/struct_test.c](https://github.com/KuroiGengetsu/ReviewC/blob/master/examples/struct_test.c)

```C
#include <stdio.h>

typedef struct {
    int   a;
    char  b;
    float c;
} mystruct;

struct COMPLEX {
    int a;
    int b[20];
    long *lp;
    mystruct s;
    mystruct *sp;
    mystruct sy[20];
};

int main() {
    long distance = 10000;

    struct COMPLEX comp; // 声明一个结构体变量
    comp.a = 3;  // 访问 整型成员变量 a 并赋值 3
    comp.b[5] = 17;  // 访问整型数组成员变量 b 的第六个元素, 并赋值 17, 你也可以这样写: (comp.b)[5]
    comp.lp = &distance;  // 将 长整型指针 成员变量 lp 指向 distance
    comp.s.a = 13;  // 访问 comp 的 mystruct类型成员变量 s 的成员变量 a 并赋值 13
    comp.s.b = 'H';  // 访问 comp 的 s 的成员变量 b 并赋值 'H'
    comp.s.c = 3.14;  // 访问 comp 的 s 的成员变量 c 并赋值 3.14
    comp.sy[0].a = 55;  // 访问 comp 的 mystruct 类型数组 sy 第一个元素 的成员 a 并赋值 55, 其他元素的访问类似
    printf("comp.a = %d, comp.b[5] = %d, *comp.lp = %ld, comp.s.a = %d, comp.s.b = %c, comp.s.c = %g\n",
        comp.a, comp.b[5],
        *comp.lp,  // 注意这里的 `.` 操作符优先级比 间访运算符 `*` 高, 不放心你可以加上括号 *(comp.lp)
        comp.s.a, comp.s.b, comp.s.c);  // 不放心你可以加上括号, 如 (comp.s).a 等等
    return 0;
}

```

#### 间接访问

如果你拥有一个结构体指针成员, 访问这个成员指向的结构体有两种方法:

* 先通过 **间访运算符 \*** 访问所指向的结构变量, 然后再通过 **点操作符 .** 访问成员

* 通过 **箭头操作符 ->** 操作符直接访问所指向的结构变量的成员

```C
typedef struct {
    int   a;
    char  b;
    float c;
} mystruct;

int main() {
    mystruct s;
    mystruct *sp = &s;

    // 第一种方法
    (*sp).a = 3;
    printf("(*sp).a = %d\n", (*sp).a);
    
    // 第二种方法
    sp -> a = 4;
    printf("sp -> a = %d\n", sp -> a);
    return 0;
}
```

#### 自引用

错误示范:

```C
struct SELF_REF {
    int               a;
    struct SELF_REF   b;  // 这里是错误的!!!!!
    int               c;
};
```

这种引用是非法的, 因为这样会构成一个无限的递归, 永无止境。

正确的示范:
```C
struct SELF_REF {
    int               a;
    struct SELF_REF   *b;  // 合法的
    int               c;
}
```

这个结构体的成员 b 可以指向 **同类型** 的其他结构体变量, 这种写法用于构建 **链表** 、 **树** 等高级结构。

陷阱:

```C
typedef struct {
    int        a;
    SELF_REF3  *b;  // 这是个陷阱, 因为 SELF_REF3 在后面才被定义。
    int        c;
} SELF_REF3;
```

所以要注意结构体 **标签** 的运用。

#### 不完整声明

或许以后, 你会想让两个结构体相互引用, 但是, 这该怎么写呢?

类似于函数的原型, 你可以在 **main()** 函数上面声明, 然后在 **main()** 后面具体实现, 结构体也可以这样:

```C
struct B;

struct A {
    struct B  *partner;
    // ... 其他成员
};

struct B {
    struct A  *partner;
    // ... 其他成员
};
```

#### 结构体的初始化

结构体的初始化类似于数组的初始化, 就是使用花括号:
```C
struct C {
    int          a;
    short        b[10];
    mystruct     other;
} x = {  // 我只是把它展开写而已
    3,
    {1, 2, 3, 4, 5},
    {1, 'a', 3.3}
};  // 分号不要丢
```

# 20. 使用结构体指针访问结构体成员

单向链表是最常见的高级数据结构, 用它来讲解结构体指针的使用是最好不过的了

## 静态链表

先给出静态链表的代码, 见 [struct_and_pointer.c](https://github.com/KuroiGengetsu/ReviewC/blob/master/examples/struct_and_pointer.c)

```C
#include <stdio.h>

/**
 * 静态链表
 */

typedef struct _NODE {
    int           data;  // 拥有一个 int 型 成员 data
    struct _NODE  *next;  // 拥有一个指向 CHAIN 结构体的 结构体指针 next, 这就是所谓的自引用
} NODE;  // NODE 现在是个变量名

void print_chain(NODE *head);

int main() {
    // 创建五个 NODE 变量
    NODE head, a, b, c, end;

    // 初始化他们 next 指针的指向
    head.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &end;
    end.next = NULL;

    // 初始化数据
    head.data = 0;
    a.data = 1;
    b.data = 2;
    c.data = 3;
    end.data = 4;

    print_chain(&head);  // 函数传入结构体变量可以写成这样, 因为形参是 NODE* 类型。
    return 0;
}

void print_chain(NODE *head) {
    while(head->next != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

```
| 结点名 *NODE* | 数据 *data* | 结构体指针 *next* |
|:-:|:-:|:-:|
| *head* | 0 | 指向 *a* |
| *a* | 1 | 指向 *b* |
| *b* | 2 | 指向 *c* |
| *c* | 3 | 指向 *end* |
| *end* | 4 | 指向 *NULL*, 即空指针 |

这里声明的 5 个结构体变量, 他们的 next 成员都指向下一个结构体变量, 这样就形成了一个链, 就是所谓的单向链表

值得注意的就是将最后的那个结点的 next 指向了 NULL, 这样也算做初始化了, 可以用来判断是否到结尾。

## 动态链表

动态链表主要从下面这四方面入手: **创建、打印、插入、删除**

源代码见[dynamic_chain.c](https://github.com/KuroiGengetsu/ReviewC/blob/master/examples/dynamic_chain.c)

## 例题 *Josephus 约瑟夫环*


# 21. 文件操作

# 23. 十进制 and 十六进制

# 30. 指针 and 二维数组

# 33. 对结构体变量成员进行读写操作

# 34. 读写文本文件

# 36. 水仙花数

# 38. 函数原型的语法特点

# 41. 预处理

## 预定义符号

| 符号 | 样例值 | 含义 |
|:--|:--|:--|
| `__FILE__` | `"pretest.c"` | 进行编译的源文件名 |
| `__LINE__` | `5` | 文件当前的行号 |
| `__DATE__` | `"Jan  1 2018"` | 编译的日期 |
| `__TIME__` | `"15:49:01"` | 编译的时间 |
| `__STDC` | `1` | 如果编译器遵循 *ANSI C*, 那么它的值就是 1, 否则未定义|

```C
#include <stdio.h>

int main() {
    printf("__FILE__:`%s` compiled in __LINE__ `%d` on __DATE__ `%s` at __TIME__ `%s` with __STDC__ `%d`",
         __FILE__, __LINE__, __DATE__, __TIME__, __STDC__);  // 第五行
    return 0;
}
```

会打印:

```C
"__FILE__:`pretestc` compiled in __LINE__ `5` on __DATE__ `Jan  1 2018` at __TIME__ `15:49:01` with __STDC__ `1`"
```


## 条件编译(conditional compilation)

可以选择性地编译某些语句

例如, 你希望一些 **测试或调试** 时使用的语句在项目写好之后不会生效, 但是在维护的时候却需要这些语句。 这个时候就可以使用条件编译, 非常的方便, 也很好用。

### \#if  \#elif \#endif

```C
#if constant-expression  // 如果为真将执行下面的语句, 直到 #endif
        statements  // 语句
        // ...
#endif
```

其中 *constant-expression* 是常量表达式, 和 条件语句 if类似。 

另外也可以采用 \#elif来实现多个分支, 就类似于 else if。

例如:

```C
#define DEBUG 1

// ... some code

#if DEBUG
    printf("x = %d, y = %d\n", x, y);
#endif

// ... some code

# if DEBUG
    printf("result = %d\n", result);
#endif
// ... some code
```

这样, 无论是编译它还是忽略它, 都非常的容易:

* 如果要编译它:<br />`#define DEBUG 1`

* 如果不编译: <br/>`#define DEBUG 0`

把所有的调试用语句都嵌套在各自的 `#if DEBUG` 和 `#endif`, 只需要在文件开头改变 DEBUG 的值就可以实现是否调试这一操作, 就像一个开关一样, 而且不编译的时候不会影响项目的最终结果, 因为编译器会无视不编译的代码块。 与 *注释/取消注释* 调试语句 相比, *条件编译* 方便多了。

### 如果定义:\#ifdef 和 如果没有定义\#ifndef

* \#ifdef symbol<br />\#ifdef 用于判断是否 **定义** 了什么 *宏* , 然后下面执行一些语句, 最后 `#endif`

* \#ifndef symbol<br />\#ifndef 用于判断是否 **没有定义** 什么 *宏* , 然后下面执行一些语句, 最后 `#endif`

```C
#ifndef MAX  // 判断是否没有定义了宏 MAX, 往往用于防止重定义
    #define MAX(a, b)  ((a) > (b) ? (a) : (b))  // 如果没有定义, 那么就定义MAX, 或者执行一些其他的语句。
#endif  // 如果定义了, 那么就结束 #ifndef
```

## 文件包含 \#include

* 包含函数库头文件: `#include <filename.h>`

* 包含本地文件: `#include "filename.h"`

比如, 现在有三个头文件 **a.h** 、 **b.h** 和 **x.h**:

假如 **a.h** 与 **b/h** 都包含了 **x.h**, 那么下面这种写法无疑会出现重定义:

```C
#include "a.h"
#include "b.h"
```

所以, 为了防止重定义, 应该在 **"x.h"** 中添加这样几行:

```C
// 写在文件开头:
#ifndef _X_H_
#define _X_H_ 1
// 也可以直接 #define _X_H_, 不用赋予初值也可以
/*
 * 所有要执行的代码以及要定义的宏
*/

// 写在文件结尾
#endif
```

至于这个宏如何明明, 在每个单词变成大写, 左右都加上一个下划线`_`, 再把 `.` 也用下划线替换就好了

这样, 在包含 **"b.h"** 的时候, 因为 `_X_H_` 已经被定义, 所以不会再一次执行 "x.h" 中的代码, 可以放心的使用了。

例如, 这是库函数文件 `stdio.h` 中的部分代码:

```C
#ifndef _STDIO_H
/*
 * ... 一些代码
 */
#define _STDIO_H
/*
 * ... 一些代码
 */
#endif  // 文件结尾
```

所以 `<stdio.h>` 可以被包含很多次也不会出现任何问题

# 44. static 静态局部变量

# 47. 读取文件中数据 + 统计正负数

