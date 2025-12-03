#include <stdio.h>

int main() {
    int pageTable[20], pageNumber, offset;
    int logicalAddress, physicalAddress;
    int pageSize, numPages, i;

    printf("Enter page size (in bytes, power of 2): ");
    scanf("%d", &pageSize);

 
    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    printf("Enter frame number for each page:\n");
    for (i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter logical address: ");
    scanf("%d", &logicalAddress);

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    if (pageNumber >= numPages) {
        printf("\nInvalid logical address! Page number out of range.\n");
        return 0;
    }

    physicalAddress = pageTable[pageNumber] * pageSize + offset;

    printf("\n--- Paging Output ---");
    printf("\nPage Number : %d", pageNumber);
    printf("\nOffset      : %d", offset);
    printf("\nFrame No    : %d", pageTable[pageNumber]);
    printf("\nPhysical Address : %d\n", physicalAddress);

    return 0;
}
