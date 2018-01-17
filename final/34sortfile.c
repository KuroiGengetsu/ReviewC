#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sorted(char *src);
char store[300000] = "";

int main() {
    FILE *fp = fopen("./test.txt", "r+");
    if(!fp) {
        printf("./test.txt error!\n");
        exit(1);
    }
    int ch;
    while((ch = fgetc(fp)) != EOF) {
        char tmp[2] = {ch, '\0'};
        strcat(store, tmp);
    }
    sorted(store);
    rewind(fp);
    fprintf(fp, "%s", store);
    fclose(fp);
    printf("%s\n", store);
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

