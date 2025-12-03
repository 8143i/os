#include <stdio.h>

int main() {
    int b, p, i, j, worst;

    printf("Enter number of memory blocks: ");
    scanf("%d", &b);
    int block[b];

    printf("Enter size of each block:\n");
    for (i = 0; i < b; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    int process[p];

    printf("Enter size of each process:\n");
    for (i = 0; i < p; i++)
        scanf("%d", &process[i]);

    int allocation[p];
    for (i = 0; i < p; i++)
        allocation[i] = -1;

    for (i = 0; i < p; i++) {
        worst = -1;
        for (j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < p; i++) {
        printf("P%d\t%d\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
