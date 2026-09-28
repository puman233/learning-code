#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **p, int n) {
    int i, j;
    char *temp = malloc(256 * sizeof(char));
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(*(p + j), *(p + j + 1)) > 0) {
                strcpy(temp, *(p + j));
                strcpy(*(p + j), *(p + j + 1));
                strcpy(*(p + j + 1), temp);
            }
        }
    }
    free(temp);
}

void read_line(char *s) {
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        *(s + i) = c;
        i++;
    }
    *(s + i) = '\0';
}


int main(int argc, char *argv[]) {
    // max n = 10
    int n;
    int i;

    scanf("%d",&n);
    getchar();

    char **s = malloc(n * sizeof(char*));

    for (i = 0; i < n; i++) {
        *(s + i) = (char *)malloc(256 * sizeof(char));
    }

    for (i = 0; i < n; i++) {
        read_line(*(s + i));
        // fgets(*(s + i), 256, stdin);

        // 去除末尾换行符
        // *(s + i)[strcspn(*(s + i), "\n")] = '\0';
    }

    // 此为第二种可行输入含空格字符串方法
    // for (i = 0; i < n; i++) {
    //     // scanf(" %[^\n]",*(s + i));   此方法可行
    // }

    sort(s, n);

    printf("Now,the sequence is:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", *(s + i));
    }

    for (i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);

    return 0;
}