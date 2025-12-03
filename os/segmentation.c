#include <stdio.h>

int main() {
    int segmentTable[20][2];   
    int numSegments;
    int segNo, offset, logicalAddress;
    int physicalAddress;

    printf("Enter number of segments: ");
    scanf("%d", &numSegments);

    printf("Enter Base and Limit for each segment:\n");
    for (int i = 0; i < numSegments; i++) {
        printf("Segment %d Base: ", i);
        scanf("%d", &segmentTable[i][0]);
        printf("Segment %d Limit: ", i);
        scanf("%d", &segmentTable[i][1]);
    }

    printf("\nEnter logical address (segment_number offset): ");
    scanf("%d %d", &segNo, &offset);

    if (segNo < 0 || segNo >= numSegments) {
        printf("\nInvalid Segment Number!\n");
        return 0;
    }

    if (offset >= segmentTable[segNo][1]) {
        printf("\nSegmentation Fault: Offset out of range!\n");
        return 0;
    }

    physicalAddress = segmentTable[segNo][0] + offset;

    printf("\n--- Segmentation Output ---\n");
    printf("Segment Number : %d\n", segNo);
    printf("Offset         : %d\n", offset);
    printf("Base Address   : %d\n", segmentTable[segNo][0]);
    printf("Limit          : %d\n", segmentTable[segNo][1]);
    printf("Physical Address = %d\n", physicalAddress);

    return 0;
}
