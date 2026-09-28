#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *s) {
    int len = 0;

    int i;
    for (i = 0; *(s + i) != '\0'; i++) {
        len++;
    }

    return len;
}


int main(int argc, char *argv[]) {

    char *s = malloc(80 * sizeof(char));

    printf("Please input s: ");
    scanf("%s", s);

    printf("The length of string is %d\n", mystrlen(s));

    free(s);

    return 0;
}