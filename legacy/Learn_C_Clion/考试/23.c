#include <stdio.h>

int fac(int n) {

    if (n == 1) {
        return 1;
    }
    return n * fac(n - 1);
}

int main(int argc, char *argv[]) {

    int  n;
    long int y;
    printf("Input a integer number:");
    scanf("%d",&n);
    if(n>=0)
    {
        y=fac(n);
        printf("%d!=%ld",n,y);
    }
    else
        printf("data error!");



    return 0;
}