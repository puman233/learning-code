#include <stdio.h>
// #include <wchar.h>

int main(int argc, char *argv[]) {

    FILE *fp1, *fp2;
    float num[10];
    float oddNum[10];
    int i = 0, j = 0;

    fp1 = fopen("floatin.dat", "rb");
    fp2 = fopen("floatout.dat", "wb");

    fread(num, sizeof(float), 10, fp1);

    for (i = 0; i < 10; i+=2) {
        oddNum[j++] = num[i];
    }

    fwrite(oddNum, sizeof(float), j, fp2);

    // Hello World

    fclose(fp1);
    fclose(fp2);

    return 0;
}
