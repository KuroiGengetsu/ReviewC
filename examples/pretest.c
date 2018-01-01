#include <stdio.h>

int main() {
    printf("__FILE__:`%s` compiled in __LINE__ `%d` on __DATE__ `%s` at __TIME__ `%s` with __STDC__ `%d`",
         __FILE__, __LINE__, __DATE__, __TIME__, __STDC__);
         /*
         __FILE__:`pretest.c` compiled in __LINE__ `5` on __DATE__ `Jan  1 2018` at __TIME__ `15:49
:01` with __STDC__ `1`
         */
    return 0;
}
