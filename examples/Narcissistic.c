#include <stdio.h>
#include <math.h>
#define TEST 1  // 将它改为 1 来激活第二个函数, 但很慢

/**
 * 水仙花数: n 位数的水仙花数就是 每一位上数的 n 次方 再求和, 等于这个数本身
 * 函数 narcissistic3: 计算三位数的水仙花数
 * 函数 isnarrcissistic: 判断一个数是否是水仙花数, 位数超过 7 会很慢
 */

void narcissistic3();  // 求三位数的水仙花数
int isnarcissistic(int n);  // 求n位数的水仙花数

int main() {
    printf("narcissistic:\n");
    narcissistic3();

#if TEST
    printf("narcissistics:\n");
    // 判断一个数是否是水仙花数
    for(int i = 100; i < 10000000 ; i++) {
        if(isnarcissistic(i))
            printf("%d ", i);
    }
    putchar('\n');
#endif

    return 0;
}

void narcissistic3() {
    int digits[3];  // 三位数的每位上的数, 比如 123 就是 1, 2, 3
    for(int i = 100; i < 1000; i++) {
        digits[0] = i / 100;
        digits[1] = i % 100 / 10;
        digits[2] = i % 10;
        if(digits[0]*digits[0]*digits[0] + digits[1]*digits[1]*digits[1] + digits[2]*digits[2]*digits[2] == i) {
            printf("%d ", i);
        }
    }
    putchar('\n');
}

#if TEST
int isnarcissistic(int n) {  // 判断一个数是不是水仙花数
    int tmp, digits[15], k, sum;  // tmp: n 的拷贝, digits: 储存每个位数, k: 用来当做下标
    tmp = n;
    k = sum = 0;
    while(tmp) {  // 计算每个位的数, 该循环完成后 k 就是 n 有几位数
        digits[k++] = tmp % 10;
        tmp /= 10;
    }
    for(int i = 0; i < k; i++) {  // 计算每个位的k次方和
        sum += (int)(pow(digits[i], k) + 0.5);
    }
    if(sum == n)
        return 1;
    else
        return 0;
}
#endif
