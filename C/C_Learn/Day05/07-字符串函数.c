////
//// Created by ihyj on 2025/11/15.
////
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define SIZE 80
//#define BUGSIZE 13
//#define MAX 20
//char* s_gets(char* st, int n);
//
//int mycmp(const char*s1, const char *s2) {
//    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
//        s1++;
//        s2++;
//    }
//    return *s1 - *s2;
//}
//
//// 数组版本
//char *mycpy(char* dst, const char* src) {
//
//    int i = 0;
//    while (src[i] != '\0') {
//        dst[i] = src[i];
//        i++;
//    }
//    // 补全结尾的 \0
//    dst[i] = '\0';
//    return dst;
//}
//// 指针版本
//char *mycpypro(char *dst, const char *src) {
//    char *ret = dst;
//    while (*dst++ = *src++);
//    *dst = '\0';
//    return ret;
//}
//
//
//int main() {
//
//    // 返回 s 的字符串长度
//    // 不包括结尾的 \0
//    char line[6] = "Hello";
//    // 5
//    printf("strlen=%lu\n", strlen(line));
//    // 6
//    printf("sizeof=%lu\n", sizeof(line));
//
//    // strlen() 函数用于统计字符串的长度
//    // strcmp 比较字符串长度
//    char s1[] = "abc";
//    char s2[] = "def";
//    char s3[] = "Abc";
//    char s4[] = "abc ";
//
//    /*
//     *不相等返回 它们的差值
//     *  相等返回 0
//     *
//     *  但是由于编译环境不同
//     *  大的返回1
//     *  相等返回0
//     *  小的返回-1
//     */
//    printf("%d\n", strcmp(s1, s2));
//    printf("%d\n", strcmp(s2, s3));
//    printf("%d\n", strcmp(s3, s1));
//    printf("%d\n", strcmp(s4, s1));
//    // 模拟其他编译环境
//    printf("\n");
//    printf("%d\n", mycmp(s1, s2));
//    printf("%d\n", mycmp(s2, s3));
//    printf("%d\n", mycmp(s3, s1));
//    printf("%d\n", mycmp(s4, s1));
//
//
//    // strcpy 复制函数
//    /*
//     *  char *strcpy(char *restrict dst, const char* restrict src);
//     *  把 src 的字符串复制（覆盖）到 dst
//     *  restrict 表明 src 和dst 不重叠（C99 标准）
//     *  返回 dst
//     *
//     */
//
//    char cp1[] = "Hello";
//    char cp2[] = "World";
//    char cpt[6] = "";
//
//    printf("%s\n", cp1);
//    printf("%s\n", cp2);
//    strcpy(cpt, cp1);
//    printf("cp1=%s\n", strcpy(cp1, cp2));
//    strcpy(cp1, cpt);
//    strcpy(cpt, cp2);
//    printf("cp2=%s\n", strcpy(cp2, cp1));
//    strcpy(cp2, cpt);
//    strcpy(cpt, cp1);
//    printf("cp1=%s\n", mycpypro(cp1, cp2));
//    strcpy(cp1, cpt);
//
//
//    // strchr 从左到右搜索单个字符
//    // strrchr 从右到左搜索单个字符
//    char s[] = "Hello World";
//    char *p = strchr(s, 'H');
//    // 输出 Hello World
//    // 意思是从左到右找到第一个H后输出后面的字符
//    printf("%s\n", p);
//    char *p2 = strchr(s, 'l');
//    // llo World
//    printf("%s\n", p2);
//    char *t = (char*)malloc(strlen(p) + 1);
//    strcpy(t, p);
//    printf("%s\n", t);
//    free(t);
//
//
//    // strstr 字符串找字符串   找到该字符串并输出以后的字符串
//    //  char *strstr(const char *s1, const char *s2)
//    char *p3 = strstr(s, "Hello");
//    printf("%s\n", p3);
//    char *p4 = strstr(s, "World");
//    printf("%s\n", p4);
//
//    
//    // strcat()（用于拼接字符串）函数接受两个字符串作为参数
//    char flower[SIZE];
//    char addon[] = "'s smell like old shoes.";
//
//    puts("What is your favorite flower?");
//    if (s_gets(flower, SIZE))
//    {
//		strcat(flower, addon);  // 将 addon 拼接到 flower 的末尾
//        puts(flower);
//        puts(addon);
//    }
//    else
//        puts("End of file encountered!");
//    puts("bye");
//
//    // strcat() 函数无法检查第1个数组是否能容纳第2个字符串
//	char bug[BUGSIZE];
//	int available;
//
//    puts("What is your favorite flower?");
//    s_gets(flower, SIZE);
//    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
//        strcat(flower, addon);
//    puts(flower);
//    puts("What is your favorite bug?");
//    s_gets(bug, BUGSIZE);
//    available = BUGSIZE - strlen(bug) - 1;
//    strncat(bug, addon, available);
//    puts(bug);
//
//
//    /*
//    * sprintf()函数
//    *   该函数和printf() 类似，但是它是把数据写入字符串，而不是打印在显示器上
//	*   sprintf()函数的第1个参数是目标字符串的地址
//    */
//
//    char first[MAX];
//    char last[MAX];
//    char formal[2 * MAX + 10];
//    double prize;
//
//    puts("Enter your first name:");
//    s_gets(first, MAX);
//    puts("Enter your last name:");
//    s_gets(last, MAX);
//    puts("Enter your prize money:");
//    scanf("%lf", &prize);
//    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
//    puts(formal);
//
//
//
//
//    return 0;
//}
//
//// 读取一行输入，去掉换行符
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    int i = 0;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        while (st[i] != '\n' && st[i] != '\0')
//            i++;
//        if (st[i] == '\n')
//            st[i] = '\0';
//        else
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}
//
//
