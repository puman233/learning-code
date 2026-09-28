//
// Created by ihyj on 2025/11/19.
//

#include <stdio.h>

int is;

long int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

long int factmn(int n, int m) {
    /*
     * (7-5)!
     * 2!
     * (6-5)!
     * 1!
     */

    int d = n - m;
    if (d == 0) {
        return 1;
    }
    return d * factmn(n - 1, m);
}



int main(int argc, char *argv[]) {
    long int n,m;

    printf("  1-Combination\n");
    printf("  2-Permutation\n");
    printf("===================\n");

    printf("Please Select(1,2): ");
    scanf("%d",&is);
    printf("Enter m: ");
    scanf("%ld",&m);
    printf("Enter n: ");
    scanf("%ld",&n);

    long int d1 = 0, d2 = 0, d3 = 0, csum = 0, asum = 0;
    if (is == 1) {
        // C
        d1 = fact(n);
        d2 = fact(m);
        d3 = factmn(n, m);
        csum = d1 / (d2 * d3);
        printf("C(%ld,%ld)=%ld\n", n, m, csum);
    }
    else if (is == 2) {
        // A
        d1 = fact(n);
        d3 = factmn(n, m);
        asum = d1 / d3;
        printf("A(%ld,%ld)=%ld\n", n, m, asum);
    }



    return 0;
}


