#include <stdio.h>
#include <string.h>

int minimumRecolors(char* blocks, int k) {

    int n = strlen(blocks);
    int i, find = 0;

    for (i = 0; i < k;i++) {
        if (blocks[i] == 'W') {
            find++;
        }
    }

    int minFind = find;

    if (n == k) {
        return minFind;
    }

    for (i = k; i < n; i++) {
        if (blocks[i] == 'W') {
            find++;
        }
        if (blocks[i - k] == 'W') {
            find--;
        }
        if (minFind > find) {
            minFind = find;
        }
    }
    return minFind;
}


int main(int argc, char *argv[]) {

    return 0;
}