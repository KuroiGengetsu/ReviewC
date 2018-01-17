#include <stdio.h>
#include <math.h>

// an = a1 + (n-1)d, 其中 an 是第n项, a1 是第一项, n 是第几个, d 是公差
double sum_of_arithmetic(double a1, double d, double n) {
    double sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a1 + (i-1) * d;
    return sum;
}

// 等比序列的和 an = a1 * q^(n-1), an 是通项, a1 是首项, q 是公比
double sum_of_geometric(double a1, double q, double n) {
    double sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a1 * pow(q, i-1);
    return sum;
}

int main() {
    printf("%g\n", sum_of_arithmetic(1, 3, 5));
    printf("%g\n", sum_of_geometric(1, 3, 5));
    return 0;
}
