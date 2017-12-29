#include <stdio.h>
#include <limits.h>
#include <float.h>

/**
 * 编译器: MinGW.org GCC-6.3.0-1
 * 打印一些数据类型的字节, 整数的范围参见如下:
 * 1 字节表示 -128~127 or 0~255
 * 2 字节表示 -32768~32767 or 0~65536
 * 4 字节表示 -2147483648~2147463647 or 0~4294967296
 * 8 字节表示 -92233720368547758087~92233720368547758088 or 0~18446744073709551616
 */


int main()
{
    printf("sizeof char = %d\n", sizeof(char));
    printf("sizeof short = %d\n", sizeof(short));  // short int
    printf("sizeof int = %d\n", sizeof(int));
    printf("sizeof long = %d\n", sizeof(long));  // long int
    printf("sizeof long long = %d\n", sizeof(long long));  // long long int

    printf("\n");
    printf("sizeof unsigned char = %d\n", sizeof(unsigned char));
    printf("sizeof unsigned short = %d\n", sizeof(unsigned short));
    printf("sizeof unsigned int = %d\n", sizeof(unsigned int));
    printf("sizeof unsigned long = %d\n", sizeof(unsigned long));
    printf("sizeof unsigned long long = %d\n", sizeof(unsigned long long));
    printf("\n");

    printf("sizeof float = %d\n", sizeof(float));
    printf("sizeof double = %d\n", sizeof(double));
    printf("sizeof long double = %d\n", sizeof(long double));
    printf("\n");

    printf("CHAR_BIT   = %d\n", CHAR_BIT);  // 一字节中有几位
    printf("MB_LEN_MAX = %d\n", MB_LEN_MAX);  // 多字节字符的最大字节数, 比如汉字的
    printf("\n");

    printf("CHAR_MIN   = %+d\n", CHAR_MIN);  // char 最小值
    printf("CHAR_MAX   = %+d\n", CHAR_MAX);  // char 最大值
    printf("SCHAR_MIN  = %+d\n", SCHAR_MIN);  // signed char 最小值
    printf("SCHAR_MAX  = %+d\n", SCHAR_MAX);  // signed char 最大值
    printf("UCHAR_MAX  = %u\n",  UCHAR_MAX);  // unsigned char 最大值
    printf("\n");

    printf("SHRT_MIN   = %+d\n", SHRT_MIN);  // short 最小值
    printf("SHRT_MAX   = %+d\n", SHRT_MAX);  // short 最大值
    printf("USHRT_MAX  = %u\n",  USHRT_MAX);  // unsigned short 最大值
    printf("\n");

    printf("INT_MIN    = %+d\n", INT_MIN);  // int 最小值
    printf("INT_MAX    = %+d\n", INT_MAX);  // int 最大值
    printf("UINT_MAX   = %u\n",  UINT_MAX);  // unsigned int 最大值
    printf("\n");

    printf("LONG_MIN   = %+ld\n", LONG_MIN);  // long 最小值
    printf("LONG_MAX   = %+ld\n", LONG_MAX);  // long 最大值
    printf("ULONG_MAX  = %lu\n",  ULONG_MAX);  // unsigned long 最大值
    printf("\n");

    printf("LLONG_MIN  = %+lld\n", LLONG_MIN);  // long long 最小值
    printf("LLONG_MAX  = %+lld\n", LLONG_MAX);  // long long 最大值
    printf("ULLONG_MAX = %llu\n",  ULLONG_MAX);  // unsigned long long 最大值
    printf("\n");

    printf("FLT_RADIX    = %d\n", FLT_RADIX);  // 所有浮点数的表示所使用的的基数(base), 一般为2
    printf("DECIMAL_DIG  = %d\n", DECIMAL_DIG);  // 不懂...
    printf("FLT_MIN      = %e\n", FLT_MIN);  // 所有浮点数的最小值 <= 这个极小值
    printf("FLT_MAX      = %e\n", FLT_MAX);  // 所有浮点数的最大值 >= 这个极大值
    // 至于下面的, ...
    printf("FLT_EPSILON  = %e\n", FLT_EPSILON);
    printf("FLT_DIG      = %d\n", FLT_DIG);
    printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    printf("FLT_MIN_EXP  = %d\n",  FLT_MIN_EXP);
    printf("FLT_MIN_10_EXP  = %d\n",  FLT_MIN_10_EXP);
    printf("FLT_MAX_EXP     = %d\n",  FLT_MAX_EXP);
    printf("FLT_MAX_10_EXP  = %d\n",  FLT_MAX_10_EXP);
    printf("FLT_ROUNDS      = %d\n",  FLT_ROUNDS);
    printf("FLT_EVAL_METHOD = %d\n",  FLT_EVAL_METHOD);
    printf("FLT_HAS_SUBNORM = %d\n",  FLT_HAS_SUBNORM);

    return 0;
}