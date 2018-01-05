#include <stdio.h>
#include <stdlib.h>  // malloc, free

#define ISDIGIT(ch) ((ch) >= '0' && (ch) <= '9')

// 动态链表
typedef struct _NODE {
    int data;
    struct _NODE *next;
} NODE;

// 从 stdin 的字符串中读出整数, 包括正负数
NODE *read_ints(void);

// 打印链表
void print_chain(NODE *head);
// 释放链表空间
void free_all(NODE *head);

// 输入一串字符, 以 EOF符号, 即(Ctrl+Z, 长得像 ^Z)结束, 一个不够就两个。
int main() {
    puts("Please input a string contains numbers:");
    NODE *head = read_ints();
    print_chain(head);
    free_all(head);
    return 0;
}

NODE *read_ints(void) {
    NODE *head = (NODE*)malloc(sizeof(NODE));  // 创建链表头
    NODE *linker = head;                       // 用于链接链表
    int ch;                                    // 读入字符
    _Bool isMinus = 0;                         // 判断是否是负数

    while((ch = getchar()) != EOF) {           // 整个输入循环
        if(ch == '-') {
            isMinus = 1;                       // 是负数就置为1
            continue;
        }
        else if(ISDIGIT(ch)) {                 // 如果是数字
            ungetc(ch, stdin);                 // 将这个数字写回 stdin
            int value = 0;                     // 存放整数值
            while( (ch = getchar()) != EOF && ISDIGIT(ch)) {  // 读入这个数字
                value *= 10;
                isMinus ? (value -= (ch - '0')) : (value += (ch - '0'));  // 负数减去, 正数加上
            }
            isMinus = 0;                       // 置 0
            ungetc(ch, stdin);                 // 把下一个字符返回, 因为可能是 '-' 号

            NODE *store = (NODE*)malloc(sizeof(NODE));  // 新结点
            store->data = value;               // 存放值
            linker->next = store;              // 链接该结点
            linker = store;                    // 移动 linker
        }
        else if(isMinus)  // 即 '-' 号后面并不是数字
            isMinus = 0;
    }
    linker->next = NULL;                       // 最后一个结点
    return head;
}

void print_chain(NODE *head) {
    int index = 0;
    printf("\nindex | value\n");
    while(head->next != NULL) {
        head = head->next;
        printf("%5d | %5d\n", index++, head->data);
    }
}

void free_all(NODE *head) {
    while(head->next != NULL) {
        NODE *trash = head;
        head = head->next;
        free(trash);
    }
    free(head);
}
