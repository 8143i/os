#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("\nTotal head movement (FCFS) = %d\n", total);

    return 0;
}
