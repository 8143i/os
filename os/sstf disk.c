#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, total = 0, min, idx;
    
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n], completed[n];

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        completed[i] = 0;  
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        min = 9999;
        idx = -1;

        for (j = 0; j < n; j++) {
            if (!completed[j]) {
                int distance = abs(req[j] - head);
                if (distance < min) {
                    min = distance;
                    idx = j;
                }
            }
        }

        total += min;      
        head = req[idx];    
        completed[idx] = 1; 
    }

    printf("\nTotal head movement (SSTF) = %d\n", total);

    return 0;
}
