#include <stdio.h>

int main(int argc, char *argv[]) {

    char s[1000];

    int i = 0, c = 0, d = 0, others = 0;

    while ( 1 ) {
        char tc;
        scanf("%c", &tc);
        if (tc == '\n') {
            break;
        }
        s[i] = tc;
        i++;
    }

    s[i] = '\0';

    for (i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            c++;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            d++;
        }
        else {
            others++;
        }
    }

    printf("char=%d digit=%d others=%d\n", c, d, others);



    return 0;
}