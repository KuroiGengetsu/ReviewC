#include <stdio.h>
#include <stdlib.h>

// 结点结构体
typedef struct _NODE {
    int          data;
    struct _NODE *next;
} NODE;

// 创建长度为 len 的链表
NODE * create_chain(int len);

// 打印链表的值
void print_chain(NODE *head);

// 根据索引值插入值
void insert_node(NODE *head, int index, int value);

// 根据索引删除结点并返回所删除的结点的数据, 如果 index 为 0, 则删除最后一个结点
int pop(NODE *head, int index);

// 根据数据删除值
void delete_value(NODE *head, int value);

int main() {
    int len;
    puts("Please input the length of the chain:(better more than 3)");
    scanf("%d", &len);

    // 创建 长度为 len 的链表
    NODE *head = create_chain(len);
    print_chain(head);

    // 在链表中插入值
    int index, value;
    puts("please input index and value which you want to insert:");
    scanf("%d%d", &index, &value);
    insert_node(head, index, value);
    print_chain(head);

    // 测试pop(head, 0)
    int final = pop(head, 0);
    printf("final = %d\n", final);
    print_chain(head);

    // 测试pop(head, index2)
    int index2;
    puts("input the index of the value which you want to pop:");
    scanf("%d", &index2);
    int fetch = pop(head, index2);
    printf("fetch %d at index %d.\n", fetch, index2);
    print_chain(head);

    // 测试 delete_value
    puts("Please input the value you want to delete:");
    int value3;
    scanf("%d", &value3);
    delete_value(head, value3);
    print_chain(head);
    return 0;
}

NODE * create_chain(int len) {
    NODE *head, *link, *store;  // head 是头, link 用于链接链表, store用于创建新空间

    head = (NODE*)malloc(sizeof(NODE));  // 申请初始空间
    link = head;
    printf("Please input %d int numbers:\n", len);
    while(len--) {
        store = (NODE*)malloc(sizeof(NODE));  // 创建新空间
        scanf("%d", &store->data);  // 输入值
        link->next = store;  // 上一个结点的 next 指向 store
        link = store;  // link移到这个结点
    }
    link->next = NULL;  // 最后一个结点的 next 指向 NULL
    return head;  // 返回头
}

void print_chain(NODE *head) {
    int index = 0;
    puts("\nindex | value");
    while(head->next != NULL) {
        printf("%5d | %5d\n", index++, head->next->data);
        head = head->next;
    }
    putchar('\n');
}


void insert_node(NODE *head, int index, int value) {
    while(index--)
        head = head->next;
    NODE *store = (NODE*)malloc(sizeof(NODE));
    store->data = value;
    store->next = (head->next == NULL) ? NULL : head->next;
    head->next = store;
}

int pop(NODE *head, int index) {
    if(index == 0) {
        if(head->next == NULL) {
            puts("Your chain only has root node!");
            return -1;
        }
        while(head->next->next != NULL)
            head = head->next;
        int result = head->next->data;
        free(head->next);
        head->next = NULL;
        return result;
    } else {
        while(index--)
            head = head->next;
        if(head->next->next != NULL) {
            NODE *trash = head->next;
            head->next = trash->next;
            int tmp = trash->data;
            free(trash);
            return tmp;
        } else {
            int tmp = head->next->data;
            free(head->next);
            head->next = NULL;
            return tmp;
        }
    }
}

void delete_value(NODE *head, int value) {
    int index = 0;
    while(head->next != NULL)
        if(head->next->data != value) {
            head = head->next;
            index++;
        }
        else
            break;
    if(head->next == NULL) {
        printf("can't find %d in chain.\n", value);
        return;
    } else {
        printf("delete %d at index %d successfully!\n", value, index);
        NODE *trash = head->next;
        head->next = trash->next;
        free(trash);
    }
}
