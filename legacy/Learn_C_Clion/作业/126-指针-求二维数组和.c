#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int m, n;
    int i,j;

    scanf("%d,%d", &m, &n);

    /*
     *  a[i] = malloc(n*sizeof(int)) >> *(a+i) = malloc(n*sizeof(int))
     *
     *  free(a[i]) >> free(*(a+i))

     */
    int **a = malloc(m * sizeof(int*));

    for (i = 0; i < m; i++) {
        *(a + i) = (int*)malloc(n * sizeof(int));
    }

    int sum = 0;
    /*
     *  *(a + i) >> a[i]
     *  *(*(a + i) + j) >> a[i][j]
     *  (*(a + i) + j) >> &a[i][j]

     */

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", (*(a + i) + j));
        }
    }

    for (i =0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum += *(*(a + i) + j);
        }
    }

    printf("sum=%d\n", sum);


    for (i = 0; i < m; i++) {
        free(*(a + i));
    }
    free(a);

    return 0;
}