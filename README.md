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

> 源代码见于 [type_size.c]() 或在 `CppReference.chm` 搜索 `Numeric limits`

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
|1| `++ --` | 前缀自增与自减 | 从左到右 |`
|| `()` | 函数调用 ||`
|| `[]` | 数组下标 ||`
|| `.` | 结构体与联合体成员访问 ||`
|| `->` | 结构体与联合体成员通过指针访问 ||`
|| `(type){list}` | 复合字面量(C99) ||`
|||||
|2| `++ --` | 后缀自增与自减 | 从右到左 |`
|| `+ -` | 一元加与减(正负号) ||`
|| `! ~` | 逻辑非与逐位非 ||`
|| `(type)` | 类型转换 ||`
|| `*` | 间接访问运算符(解引用) ||`
|| `&` | 取址 ||`
|| `sizeof` | 取大小 ||`
|| `_Alignof` | 对齐要求(C11) ||`
|||||
|3| `* / %` | 乘法 除法 模(取余) | 从左到右 |`
|4| `+ -` | 加减法 ||`
|5| `<< >>` | 逐位左移及右移 ||`
|6| `< <=`<br />`> >=` | 小于 小于等于<br />大于 大于等于 ||`
|7| `== !=` | 相等 不等于 ||`
|8| `&` | 逐位与 ||`
|9| `^` | 逐位异或 ||`
|10| `|` 逐位或 ||`
|11| `&&` | 逻辑与 ||`
|12| `||` | 逻辑或 ||`
|||||
|13| `?:` | 三元条件 |从右到左|`
|||||
|14| `=` | 赋值 |从右到左|`
|| `+= -=` | 以和及差赋值 ||`
|| `*= /= %=` | 以积 商 余数赋值 ||`
|| `<<= >>=` | 以逐位左移及逐位右移赋值 ||`
|| `&= ^= |=` 以逐位与、异或及或赋值 ||`
|||||
|15| `,` | 逗号 |从左到右|`

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
| `c || a` | 1 | a为真 |
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
| `a > c || ++a > b` | 1 | 因为 `||` 为左结合性， 所以先计算 `a > c`， 为真， 这里由于 `||` 的短路， 所以不再计算右边的值， 所以表达式的值为1， 并且 由于没有计算右边的表达式， 所以 `a` 并没有自增 |
| `a > c && ++a > b` | 1 | `&&` 左结合性， 先计算左边的表达式， `a > c` 为 1， 然后计算右边的表达式， `++a`, 即 a先自增, 然后 `a > b` 为真(这里的a是已经自增的a), `1 && 1` 所以为 1 |
| `a -= d > 20 ? c++ : d--` | 7 | `-=` 是右结合性， 所以先计算右边的， 右边是个三目运算符， 由于 `d > 20` 为假， 所以三目运算符的的结果为 `d--`, 由于是后缀自减， 所以运算完之后 d 才自减。 总的来说就是 `a -= 3`, 所以表达式的值为 7。 运算完该表达式之后， c 的值不变， d 的值自减。 |
| `a -= a += a /= a *= 99` | 0 | 这些赋值操作符都是右结合性， 所以从最右端开始算: 首先, `a *= 99`, a 的值变为 `990`, 接着 `a /= 990`, a 变为 `1`, 然后 `a += 1`, a 变为 `2`, 然后 `a -= 2`, a 变为0。注意在运算的过程中a被赋值了好几次 |
| `a = d > 20 ? c++ : d-- && c == 0 || a < 0` | 1 | 先计算的是三目运算符, 由于 `d > 20` 为假, 所以三目运算符的结果是 `d--`, 然后 `d && c == 0` 为真， 因此 `||` 被短路，所以 `a = 1`  |

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

`'a'` 是字符, `"a"` 是字符串 `a\0`

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

例题都是 [CodeWars](http://www.codewars.com/r/C7F7sA) 上的题

## 例一 Sentence Smash

编写函数 `char *smash(const char **words, size_t count)`, 让一个二维字符串数组中的字符串都拼接在一起并用空格隔开, 返回这个新字符串。
例如, 传入 `"hello", "world"`, 返回 `"hello world"`

源代码见 [Sentence_Smash.c](https://github.com/KuroiGengetsu/MyCodeWars/blob/master/C_code/Sentence_Smash.c);

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

# 17. 全局变量 and 局部变量

# 18. 宏替换 and 带参宏替换

# 19. 结构体

# 20. 使用结构体指针访问结构体成员

# 21. 文件操作

# 23. 十进制 and 十六进制

# 30. 指针 and 二维数组

# 33. 对结构体变量成员进行读写操作

# 34. 读写文本文件

# 36. 水仙花数

# 38. 函数原型的语法特点

# 41. 预处理

# 44. static 静态局部变量

# 47. 读取文件中数据 + 统计正负数

