#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {  // 用于链表的结构体
    int data;
    struct _NODE *next;
} NODE;

// 创建一个有 n 个子结点的链表, 他们的 data 就是各自的编号, 比如说第一个结点的 data 是 1
NODE *create_chain(int n);

// 用于打印所有结点编号
void print_chain(NODE *head);

// 用于找到幸存者
void find_survivor(NODE *head, int k);

// 主函数, 先输入总数 num, 再输入计数的次数 k
int main() {
    int num, k;

    puts("Please input the number of items:");  // 总数 num
    scanf("%d", &num);
    puts("Please input the k places:");  // 计数的次数 k
    scanf("%d", &k);

    NODE *head = create_chain(num);  // 创建环式链表
    find_survivor(head, k);  // 找到幸存者
    printf("The survivor is: ");
    print_chain(head);  // 打印

    free(head->next);
    free(head);
    return 0;
}


// 创建链表
NODE *create_chain(int n) {
    NODE *tmp, *head = (NODE*)malloc(sizeof(NODE));
    tmp = head;
    int index = 1;  // 用于编号
    while(n--) {
        NODE *store = (NODE*)malloc(sizeof(NODE));
        store->data = index++;
        tmp->next = store;
        tmp = store;
    }
    tmp->next = head->next;  // 成为一个环, 最后一个结点指向第一个结点
    return head;
}


// 打印链表
void print_chain(NODE *head) {
    NODE *tmp = head->next;
    while(tmp->next != head->next) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);  // 打印最后一个数据
}

// 寻找幸存者
void find_survivor(NODE *head, int k) {
    NODE *walker = head->next;
    head->data = walker->data;  // head 的 data 用于存放它指向的那个结点的 data, 好辨认

    while(head->next->next != head->next) {
        int count = k-1;

        while(--count) {  // 每次这个循环完之后, walker 都会指向 要踢出去的那个结点 `前` 的那个结点
            walker = walker->next;
        }

        NODE *trash = walker->next;  // trash 用于被踢出去的那个结点
        walker->next = trash->next;  // 踢出去
        if(trash->data == head->data)  // 如果刚好是 head 所指向的那个结点
            head->next = trash->next;  // 更新 head 指向 被踢出去结点的后一个结点
        free(trash);  // 释放垃圾

        walker = walker->next;  // walker 从walker 的下一个结点开始数
    }
}

