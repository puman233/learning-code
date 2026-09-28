////
//// Created by ihyj on 2025/11/22.
////
//
//#include <stdio.h>
//
//void del(char s[]) {
//    int i, j;
//    for (i = 0; s[i] != '\0'; i++) {
//        for (j = i + 1; s[j] != '\0'; j++) {
//            if (s[i] == s[j] || s[i] == s[j] + 32 || s[i] == s[j] - 32) {
//                s[i] = ' ';
//                break;
//            }
//        }
//    }
//}
//
//int main(int argc, char *argv[]) {
//    char str[100];
//    int i;
//    scanf("%[^\n]", str);
//    del(str);
//    for (i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ') {
//            printf("%c", str[i]);
//        }
//    }
//
//    return 0;
//}
//
