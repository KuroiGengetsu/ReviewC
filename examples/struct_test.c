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
