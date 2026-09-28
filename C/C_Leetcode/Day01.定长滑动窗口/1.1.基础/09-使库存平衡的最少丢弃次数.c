#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int minArrivalsToDiscard(int* arrivals, int arrivalsSize, int w, int m) {

    int i, res = 0;

    // 哈希表
    long long *fings = (long long*)calloc(100001, sizeof(long long));
    // int *kept = (int*)calloc(arrivalsSize, sizeof(int));

    for (i = 0; i < arrivalsSize; i++) {

        // 入窗口
        fings[arrivals[i]]++;

        // 出窗口
        // if (i >= w && kept[i - w] == 1) {
        if (i >= w){
            fings[arrivals[i - w]]--;
        }

        // // ++对应编号货物
        // int try_kept = arrivals[i];
        // fings[try_kept]++;

        // 超出限制
        if (fings[arrivals[i]] > m) {
            // 不加入
            fings[arrivals[i]]--;
            // kept[i] = 0;
            // 变为0 即丢掉此物品
            arrivals[i] = 0;
            res++;
        }
        else {
            // kept[i] = 1;
        }

    }


    // free(kept);
    free(fings);

    return res;
}


int main(int argc, char *argv[]) {



    return 0;
}