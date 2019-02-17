#include <stdio.h>

void initStack (int stack[], int n) {
    int i;
    for (i=0; i<n; ++i)
        stack[i] = -1;
}

int findOcc (int stack[], int toFind, int start, int n) {
    int j;
    
}

void main () {
    // int pageSequence[100], pageCount;
    int pageSequence[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int pageCount = 20;

    int FIFOStack[3], n=3;
    int LRUStack[3][2], optimalStack[3];
    int hitCount=0, i, j, k, flag, leastUsed, firstOcc[3], optimalReplace;

    // printf("enter number of pages in sequence: ");
    // scanf("%d", &pageCount);

    // printf("enter the page sequence: ");
    // for (i=0; i<n; ++i)
    //     scanf("%d", &pageSequence[i]);

    // init the FIFOStack
    initStack(FIFOStack, n);

    // lets got for FIFO
    for (i=0; i<pageCount; ++i) {
        for (j=0; j<n; j++) {
            // check if page exist in cache
            if (FIFOStack[j] == pageSequence[i]) {
                hitCount++;
                flag = 1;
                break;
            }
        }

        if(!flag) {
            // now that the page doesn't exist
            // push it in
            for (j=0; j<n-1; ++j)
                FIFOStack[j] = FIFOStack[j+1];

            FIFOStack[n-1] = pageSequence[i];
        }

        flag = 0;
    }
    printf("Hit Count in FIFO: %d \n", hitCount);


    // init the LRUStack for LFU
    // initStack(LRUStack, n);
    hitCount = 0;
    for (i=0; i<n; ++i) {
        LRUStack[i][0] = -1;
        LRUStack[i][1] = 0;
    }

    for (i=0; i<pageCount; ++i) {
        for (j=0; j<n; j++) {
            // check if page exist in cache
            if (LRUStack[j][0] == pageSequence[i]) {
                hitCount++;
                flag = 1;
                LRUStack[j][1] = 1;
            } else {
                LRUStack[j][1]++;
            }
        }

        if(!flag) {
            // now that the page doesn't exist
            // push it in
            leastUsed = 0;
            for (j=0; j<n; ++j) {
                if (LRUStack[j][1] > LRUStack[leastUsed][1])
                    leastUsed = j;
            }

            LRUStack[leastUsed][0] = pageSequence[i];
            LRUStack[leastUsed][1] = 1;
        }

        flag = 0;
    }
    printf("Hit Count in LFU: %d\n", hitCount);


    // Most optimal page replacement algo!!!
    hitCount = 0;
    initStack(optimalStack, 3);

    for (i=0; i<pageCount; ++i) {
        for (j=0; j<n; j++) {
            // check if page exist in cache
            if (optimalStack[j] == pageSequence[i]) {
                hitCount++;
                flag = 1;
            }
        }

        if(!flag) {
            // now that the page doesn't exist
            // push it in
            leastUsed = 0;
            for (j=0; j<n; ++j) {
                firstOcc[j] = findOcc(pageSequence, optimalStack[j], i, pageCount);
            }

            if (firstOcc[0] > firstOcc[1]) {
                if(firstOcc[0] > firstOcc[2]) {
                    optimalReplace = 0;
                } else {
                    optimalReplace = 2;
                }
            } else {
                if(firstOcc[1] > firstOcc[2]) {
                    optimalReplace = 1;
                } else {
                    optimalReplace = 2;
                }                
            }

            optimalStack[optimalReplace] = pageSequence[i];
        }

        flag = 0;
    }
    printf("Hit Count in LFU: %d\n", hitCount);
}
