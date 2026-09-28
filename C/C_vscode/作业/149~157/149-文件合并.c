#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp1, *fp2, *fp3;
    char ch;

    fp1 = fopen("data1.txt", "r+");

    fp2 = fopen("data2.txt", "r+");

    fp3 = fopen("data3.txt", "w+");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        printf("Error");
        fclose(fp1);
        fclose(fp2);
        return 0;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp3);

    }

    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);



    return 0;
}