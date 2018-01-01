#include <stdio.h>

/**
 * 静态链表
 */

typedef struct CHAIN {
    int           data;  // 拥有一个 int 型 成员 data
    struct CHAIN  *next;  // 拥有一个指向 CHAIN 结构体的 结构体指针 next
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
