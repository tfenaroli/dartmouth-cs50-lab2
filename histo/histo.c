#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int main() {

    int binCount = 16;
    int binRange = binCount;
    int binSize = 1;
    int bins[binCount];

    for (int i=0; i<binCount; i++) {
        bins[i] = 0;
    }

    printf("16 bins of size %d for range [0, %d)\n", binSize, binRange);
    int val;
    while (scanf("%d", &val) == 1) {
        if (val < 0) {
            continue;
        }
        while (val > binRange - 1) {
            binSize *= 2;
            binRange *= 2;
            for (int i=0; i<(binCount/2); i++) {
                bins[i] = bins[i*2] + bins[i*2 + 1];
            }
            for (int i=(binCount/2); i<(binCount); i++) {
                bins[i] = 0;
            }
            printf("16 bins of size %d for range [0, %d)\n", binSize, binRange);
        }
        int k = 0;
        int counter = (binSize - 1);
        while (val > counter) {
            counter += (binSize);
            k++;
        }
        bins[k]++;
    }

    int intervalStart = 0;
    int intervalEnd = binSize - 1;

    for (int i=0; i<binCount; i++) {   
        printf("[% 6d:% 6d] ", intervalStart, intervalEnd);
        for (int j=0; j<bins[i]; j++) {
            printf("*");
        }
        printf("\n");
        intervalStart += binSize;
        intervalEnd = intervalStart + (binSize - 1);
    }
    return 0;
}