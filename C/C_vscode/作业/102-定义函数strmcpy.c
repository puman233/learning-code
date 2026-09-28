//
// Created by ihyj on 2025/11/21.
//

#include <stdio.h>
#include <string.h>

void strmcpy(char s[], char t[], int m) {
    int i = 0, count = 0;
    for (i = m - 1; t[i] != '\0'; i++) {
        s[count] = t[i];
        count++;
    }
    s[count] = '\0';
}


int main(int argc, char *argv[]) {
    char t[100] = "", s[100];
    int m;

    printf("Input a string:");
    for (int i = 0; t[i] != '\n'; i++) {
        char c;
        scanf("%c", &c);
        if (c != '\n') {
            t[i] = c;
        }
        else {
            t[i] = '\0';
            break;
        }
    }
    printf("Input an integer:");
    scanf("%d", &m);

    strmcpy(s, t, m);

    printf("Output is:%s", s);




    return 0;
}




