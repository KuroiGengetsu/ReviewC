#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int m = 13;
    int n = 555;
    printf("m = %d, n = %d\n", m, n);
    swap(&m, &n);
    printf("m = %d, n = %d\n", m, n);
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
