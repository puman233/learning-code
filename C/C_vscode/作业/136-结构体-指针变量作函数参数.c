#include <stdio.h>

struct Data {
    int a, b, c;
};

void func(struct Data *parm) {
    parm->a = 18;
    parm->b = 5;
    parm->c = parm->a * parm->b;
}
int main(int argc, char *argv[]) {

    struct Data arg;

    arg.a = 27, arg.b = 3, arg.c = arg.a + arg.b;
    func(&arg);
    printf("%d, %d, %d\n", arg.a, arg.b, arg.c);


    return 0;
}