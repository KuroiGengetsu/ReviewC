#include <stdio.h>
#include <string.h>

void sorted(char *src);

/**
 * 31. 编写函数, 对字符串中的字符进行排序操作
 */

int main() {
    char s[] = "awkudhawfawfbalwflihiscwbkjqn";
    printf("%s\n", s);
    sorted(s);
    printf("%s\n", s);
    return 0;
}

void sorted(char *src) {
    int len = strlen(src), i, j;
    for(i = 0; i < len; i++) {
        for(j = 0; j < i; j++) {
            if(src[i] < src[j]) {
                char tmp = src[j];
                src[j] = src[i];
                src[i] = tmp;
            }
        }
    }
}
