#include<stdio.h>

int main() {

    int i;
    char str[6] = "apple";

    printf("The string is:");
    
    for (i = 0; str[i] != '\0'; i++)  //此行不要修改
    {
        putchar(str[i]);
    }

    printf("\n");
    






	return 0;
}