#include <stdio.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {

    int i, maxSatisfiedCustomer = 0, currSatisfiedCustomer = 0;

    // 先把全部老板不生气的顾客数加一遍
    for (i = 0; i < customersSize; i++) {
        if (!grumpy[i]) {
            currSatisfiedCustomer += customers[i];
        }
    }

    // 然后再滑动窗口，把 if 老板不生气的 minute 分钟顾客数加进去，减去
    for (i = 0; i < customersSize; i++) {

        if (i > minutes - 1 && grumpy[i - minutes]) {
            currSatisfiedCustomer -= customers[i - minutes];
        }

        if (grumpy[i]) {
            currSatisfiedCustomer += customers[i];
        }

        if (currSatisfiedCustomer > maxSatisfiedCustomer) {
            maxSatisfiedCustomer = currSatisfiedCustomer;
        }

    }

    return maxSatisfiedCustomer;

}

int main(int argc, char *argv[]) {
    return 0;
}