#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_BINS 100

void firstFit(int items[], int n, int binCapacity) {
    int binRemaining[MAX_BINS];
    int binCount = 0;
    for (int i = 0; i < MAX_BINS; i++)
        binRemaining[i] = binCapacity;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < binCount; j++) {
            if (binRemaining[j] >= items[i]) {
                binRemaining[j] -= items[i];
                break;
            }
        }
        if (j == binCount) {
            binRemaining[binCount] -= items[i];
            binCount++;
        }
    }

    printf("Total bins used: %d\n", binCount);
    for (int i = 0; i < binCount; i++) {
        printf("Bin %d remaining capacity: %d\n", i + 1, binRemaining[i]);
    }
}

int main() {
    int items[] = {4, 8, 1, 4, 2, 1};
    int n = sizeof(items) / sizeof(items[0]);
    int binCapacity = 10;

    firstFit(items, n, binCapacity);

    return 0;
}
