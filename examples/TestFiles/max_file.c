#include <stdio.h>

/**
 * 用于打印当前编译器同时可以支持的文件最大数和最长合法文件名的长度, 定义于 <stdio.h> 中
 */

int main() {
    printf("FOPEN_MAX = %d\n", FOPEN_MAX);  // 参考: 20
    printf("FILENAME_MAX = %d\n", FILENAME_MAX);  // 参考: 260
    return 0;
}
