//
// Created by ihyj on 2025/12/2.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

    char *a = "You are a student";

    char *b = (char*)malloc(strlen(a) + 1);

    strcpy(b,a);

    printf("a=%s\nb=%s\n",a,b);
    return 0;
}


