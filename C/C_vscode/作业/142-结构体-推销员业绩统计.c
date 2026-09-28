#include <stdio.h>

struct saleStatistics {
    int salerId;
    int productId;
    float amount;

};


int main(int argc, char *argv[]) {

    int m, n, i, j, count = 0;
    float t;

    scanf("%d %d", &m, &n);

    struct saleStatistics sale_statistics[1000];

    while ( 1 ) {
        scanf("%d %d %f", &i, &j, &t);
        if (i == -1) {
            break;
        }
        // 将编号转换为下标（因为编号是从 1 开始）
        i--;
        j--;
        sale_statistics[count].salerId = i;
        sale_statistics[count].productId = j;
        sale_statistics[count].amount = t;
        count++;
    }

    float totalAmount[m][n];
    float rowAmount[m], colAmount[n];

    // 清零数组
    for (i = 0; i < m; i++) {
        rowAmount[i] = 0;
        for (j = 0; j < n; j++) {
            totalAmount[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        colAmount[i] = 0;
    }

    for (i = 0; i < count; i++) {
        totalAmount[sale_statistics[i].salerId][sale_statistics[i].productId] += sale_statistics[i].amount;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            rowAmount[i] += totalAmount[i][j];
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            colAmount[j] += totalAmount[i][j];
        }
    }

    printf("Sales Statistics:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f", totalAmount[i][j]);
        }
        printf("%8.2f\n", rowAmount[i]);
    }
    for (i = 0; i < n; i++) {
        printf("%8.2f", colAmount[i]);
    }
    printf("\n");


    return 0;
}