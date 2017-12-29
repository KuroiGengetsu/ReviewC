#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *smash(const char **words, size_t count) {
    char *result = malloc(sizeof(char) * 200);
    int k = 0;
    for(int i = 0; i < count; i++) {
        const char * s = words[i];
        while(*s) {
            result[k++] = *s++;
        }
        result[k++] = ' ';
    }
    result[k-1] = '\0';
    return result;
}

int main()
{
    const char *words[] = {
        "hello", "world"
    };
    const char *expected = "hello world";
    char *received = smash(words, sizeof(words)/sizeof(words[0]));
    printf("%s : %s\n", expected, received);
    if(strcmp(expected, received) == 0)
        printf("Successfully!\n");
    free(received);

    return 0;
}
