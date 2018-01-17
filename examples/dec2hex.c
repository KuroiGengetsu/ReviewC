#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // 在 hex2dec 中用到 strlen 函数

#define ISDIGIT(ch) ((ch) >= '0' && (ch) <= '9')
#define ISUPPER(ch) ((ch) >= 'A' && (ch) <= 'Z')
#define ISLOWER(ch) ((ch) >= 'a' && (ch) <= 'z')

char *hex(int n);  // hexadecimal 十六进制
char *oct(int n);  // octal 八进制
char *radix(int n, int base);  // 任意进制 2~36

int hex2dec(const char *src);

int main() {
    char *s = hex(255);
    printf("%s\n", s);
    free(s);

    s = oct(123);
    printf("%s\n", s);
    free(s);

    s = radix(255, 2);
    printf("%s\n", s);
    free(s);

    int n = hex2dec("FF");
    printf("%d\n", n);
    return 0;
}

char *hex(int n) {
    char HEX[] = "0123456789ABCDEF";
    char *result = (char *)malloc(sizeof(char) * 20);
    int k = 0;
    while(n) {
        result[k++] = HEX[n % 16];
        n /= 16;
    }
    result[k] = '\0';
    return result;
}

char *oct(int n) {
    char OCT[] = "01234567";
    char *result = (char *)malloc(sizeof(char) * 20);
    int k = 0;
    while(n) {
        result[k++] = OCT[n % 8];
        n /= 8;
    }
    result[k] = '\0';
    return result;
}

char *radix(int n, int base) {
    char BASE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *result = (char *)malloc(sizeof(char) * 20);
    int k = 0;
    while(n) {
        result[k++] = BASE[n % base];
        n /= base;
    }
    result[k] = '\0';
    return result;
}

int hex2dec(const char *src) {
    int bit, len, result;
    bit = 1;
    len = strlen(src);
    result = 0;
    for(int i = len-1; i >= 0; i--) {
        if(ISDIGIT(src[i]))
            result += (src[i] - '0') * bit;
        else if(ISUPPER(src[i]))
            result += (src[i] - 'A' + 10) * bit;
        else
            result += (src[i] - 'a' + 10) * bit;
        bit *= 16;
    }
    return result;
}
