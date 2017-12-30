#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <math.h>  // sqrt

#define ROW 3
#define COLUMN 10
#define ZERO 1e-8

#define true 1
#define false 0
typedef _Bool bool;

/**
 * 测试二维数组, 主要采用 double 类型
 * ROW     行数
 * COLUMN  列数
 * test_double(void) 测试如何指向二维数组
 * getNumbers(int n) 给定一个数, 返回两个数组, 一个数组全是素数, 另一个全不是素数, 范围是小于等于给定的数
 *                   用 -1 表示每个数组的最后元素
 */

void test_double(void);

bool isReversed(double (*array)[COLUMN], int row, int column);

int ** getNumbers(int n);

int main() {
    test_double();

    double array[ROW][COLUMN] = {
        {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0},
        {2.33, 66.6, 14.7, 25.4, 12.1, 12.1, 25.4, 14.7, 66.6, 2.33},
        {10.0, 9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1}
    };
    if(isReversed(array, ROW, COLUMN))
        printf("array is reversed.\n");
    else
        printf("array is not reversed.\n");


    int **numbers = getNumbers(40);
    int *primes = numbers[0];
    int *not_primes = numbers[1];

    while(*primes != -1)
        printf("%d ", *primes++);
    putchar('\n');

    while(*not_primes != -1)
        printf("%d ", *not_primes++);
    putchar('\n');

    free(numbers[0]);
    free(numbers[1]);
    free(numbers);
    return 0;
}

/**
 * test_double()
 * 测试如何指向二维数组
 * :parameters: void
 * :return: void
 */

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


/**
 * isReversed
 * 是否翻转
 * :parameters:
 *     array : 二维数组
 *     row   : 行数
 *     column: 列数
 * :return: true if it is reversed else false
 */

bool isReversed(double (*array)[COLUMN], int row, int column) {
    double *head, *end;
    // head = &array[0][0];
    head = *array;
    // end = &array[row-1][column-1];
    end = *(array + row-1 ) + column-1;

    while(head < end) {
        if(*head  -  *end  >  ZERO) { // 判断是否近似相等
            return false;  // return 0; 一旦不相等 就终止函数并返回假
        }
        head++;
        end--;
    }
    return true;  // return 1;
}


/**
 * getNumbers(int n)
 * 返回一个 int** 类型的动态二维数组
 * 包含有两个动态分配的 int* 类型 的子数组
 * 第一个数组全部都是素数
 * 第二个数组全部不是素数
 * 他们的范围是从 1 到给定的 n, 包括 n
 */

int ** getNumbers(int n) {
    int **result = malloc(sizeof(int*) * 2);  // 动态分配两个 int * 型 数组地址
    result[0] = malloc(sizeof(int) * n);  // 为第一个数组分配 n 个 int 型空间, 可以分配的大一点, 不必刚刚好
    result[1] = malloc(sizeof(int) * n);  // 为第二个数组分配 n 个 int 型空间

    int index1, index2;  // 用来控制两个数组的索引, 让他们不断自增就能实现数组索引的移动
    index1 = index2 = 0;

    for(int i = 1; i < n + 1; i++) {
        bool isPrime = true;

        // 判断是否是素数
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }

        // 如果是素数就保存到第一个数组中, 否则到第二个中
        if(isPrime)
            result[0][index1++] = i;
        else
            result[1][index2++] = i;
    }
    // 将结束时候的元素设为 -1, 为了标志结束
    result[0][index1] = result[1][index2] = -1;

    return result;
}
