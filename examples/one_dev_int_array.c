#include <stdio.h>  // putchar printf
#include <stdlib.h>  // malloc, free

#define LEN 10  // 数组长度

/**
 * @author: KuroiGengetsu
 * 一些 int 型数组的测试
 * LEN      数组长度
 * test_int 如何指向一维数组
 * reversed 翻转一个数组
 * print_array 打印数组
 * sorted 返回排好序的数组
 */

void test_int(void);
void reversed(int *array, int len);
void print_array(int *array, int len);

int * sorted(int *array, int len);

int main() {
    test_int();

    int array[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(array, LEN);

    reversed(array, LEN);
    print_array(array, LEN);

    int * sorted_array = sorted(array, LEN);
    print_array(sorted_array, LEN);
    free(sorted_array);

    return 0;
}


/**
 * test_int()
 * 如何指向一维数组, 如何指向一维数组的某个元素
 * :parameters: void
 * :return: void
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


/**
 * reversed
 * 翻转一个数组
 * :parameters:
 *     int *array: 数组名
 *     int len:    数组长度
 * :return: void
 */

void reversed(int * array, int len) {
    int *head, *end;
    head = array;
    end = array + len - 1;
    while(head < end) {
        int tmp;
        tmp = *head;
        *head = *end;
        *end = tmp;
        head++;
        end--;
    }

    /* 交换两个数, 请无视, 也尽量不要用。
    while(head < end) {
        *head ^= *end ^= *head ^= *end;
        head++;
        end--;
    }
    */
}


/**
 * print_array
 * 打印一个数组, 用空格隔开, 最后一个数字后打印换行
 * :parameters:
 *     int *array: 数组名
 *     int len:    数组长度
 * :return: void
 */

void print_array(int *array, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d", *array++);  // array[i]  // 先访问, 后自增
        (i == len - 1) ? putchar('\n') : putchar(' ');  // 数字间打印空格, 打印完数字打印换行
    }
}


/**
 * sorted
 * 返回排顺序的数组
 * :parameters:
 *     int *array: 数组名
 *     int len:    数组长度
 * :return:
 *     int* : 一个动态分配的排好序的数组
 */

int *sorted(int *array, int len) {
    int * result = malloc(sizeof(int) * len);

    // 复制所有元素
    for(int i = 0; i < len; i++)
        result[i] = array[i];

    // 排序
    for(int i = 0; i < len; i++) {
        for(int j = i+1; j < len; j++) {
            if(result[i] > result[j]) {
                int tmp;
                tmp = result[j];
                result[j] = result[i];
                result[i] = tmp;
            }
        }
    }

    return result;
}
