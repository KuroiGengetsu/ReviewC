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
    mystruct *sy[20];
};

int main() {
    long distance = 10000;
    struct COMPLEX comp;
    comp.a = 3;
    comp.b[5] = 17;
    comp.lp = &distance;
    comp.s.a = 13;
    comp.s.b = 'H';
    comp.s.c = 3.14;
    printf("comp.a = %d, comp.b[5] = %d, *comp.lp = %ld, comp.s.a = %d, comp.s.b = %c, comp.s.c = %g\n",
        comp.a, comp.b[5],
        *comp.lp,  // 注意这里的 `.` 操作符优先级比 间访运算符 `*` 高, 不放心你可以加上括号 *(comp.lp)
        comp.s.a, comp.s.b, comp.s.c);  // 不放心你可以加上括号, 如 (comp.s).a 等等
    return 0;
}