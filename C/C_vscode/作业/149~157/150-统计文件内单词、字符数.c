#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    char ch;
    int num_sign = 0, num_word = 0, in_word = 0;


    fp = fopen("in.txt", "r");

    if (fp == NULL) {
        printf("Error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) {
            if (!in_word) {
                num_word++;
                in_word = 1;
            }
        }
        else {
            in_word = 0;
        }
        num_sign++;
    }

    printf("%d %d\n", num_word, num_sign);

    fclose(fp);

    return 0;
}