//
// Created by ihyj on 2025/12/2.
//

#include<stdio.h>

void copy_string(char *from, char *to) {

    for (; *from != '\0'; from++, to++) {
        *to = *from;
    }
    *to = '\0';

}

int main(int argc, char *argv[]) {

    char *a = "I am a teacher.";
    char *b = "You are a student.";

    char c[20];

    printf("string_a=%s\nstring_b=%s\n",a,b);
    b = c;
    copy_string(a, b);
    printf("string_a=%s\nstring_b=%s\n",a,b);

    return 0;
}



