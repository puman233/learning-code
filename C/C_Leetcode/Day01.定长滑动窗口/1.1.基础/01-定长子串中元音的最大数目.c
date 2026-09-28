#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowels(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    return 0;
}

// 以下为“滑动窗口”设计
// 时间复杂度为 O(n)
int maxVowels(char *s, int k) {

    int i;
    int find = 0;
    int maxVowels = 0;
    int n = strlen(s);

    for (i = 0; i < k; i++) {
        if (isVowels(s[i])) {
            find++;
        }
    }

    maxVowels = find;
    if (find == k) {
        return find;
    }

    for (i = k; i < n; i++) {
        if (isVowels(s[i])) {
            find++;
        }
        if (isVowels(s[i - k])) {
            find--;
        }
        if (find > maxVowels) {
            maxVowels = find;
        }
        if (maxVowels == k) {
            return k;
        }
    }

    return maxVowels;
}

// 以下时间复杂度为 O(n*k)
/*int maxVowels(char* s, int k) {

    int i, j;
    int find = 0;
    int maxVowels = 0;
    int n = strlen(s);
    for (i = 0; i <= n - k; i++) {
        find = 0;
        for (j = i; j < i + k; j++) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                find++;
            }
        }
        if (find > maxVowels) {
            maxVowels = find;
        }
        if (maxVowels == k) {
            break;
        }
    }

    return maxVowels;
}
*/


int main(int argc, char *argv[]) {

    // 元音
    // aeiou
    char *s = malloc(1024* sizeof(char));
    int k;

    scanf("%s", s);
    scanf("%d", &k);

    printf("%d\n", maxVowels(s, k));


    free(s);
    return 0;
}