#include <stdio.h>
#define MAX 10

int memoryBlock[MAX], pro[MAX];

void firstFit (int n, int p)
{
    int first[MAX], i, j;

    printf("\nFirst fit algorithm:\n");
    for (i=0; i<n; ++i)
        first[i] = memoryBlock[i];

    for (i=0; i<p; ++i)
    {
        for (j=0; j<n; ++j)
        {
            if (pro[i] < first[j])
            {
                first[j] -= pro[i];
                printf("process %d fits into memory block %d, final memory in block: %d\n", i+1, j+1, first[j]);
                break;
            }
        }
    }
    printf("\n\n\n");
}

void bestFit (int n, int p)
{
    int best[MAX], i, j, min, index;

    printf("\nBest fit algorithm:\n");
    for (i=0; i<n; ++i)
        best[i] = memoryBlock[i];

    for (i=0; i<p; ++i)
    {
        min = 9999;
        for (j=0; j<n; ++j)
        {
            if (pro[i] < best[j])
            {
                if (best[j] < min)
                {
                    index = j;
                    min = best[index];
                }
            }
        }
        best[index] -= pro[i];
        printf("process %d fits into memory block %d, final memory in block: %d\n", i+1, index+1, best[index]);
    }
    printf("\n\n\n");
}


void worstFit (int n, int p)
{
    int worst[MAX], i, j, max, index;

    printf("\nWorst fit algorithm:\n");
    for (i=0; i<n; ++i)
        worst[i] = memoryBlock[i];

    for (i=0; i<p; ++i)
    {
        max = 0;
        index = 0;
        for (j=0; j<n; ++j)
        {
            if (pro[i] < worst[j])
            {
                if (worst[j] > max)
                {
                    index = j;
                    max = worst[index];
                }
            }
        }
        worst[index] -= pro[i];
        printf("process %d fits into memory block %d, final memory in block: %d\n", i+1, index+1, worst[index]);
    }
    printf("\n\n\n");
}

void nextFit (int n, int p)
{
    int next[MAX], i, j, index, flag = 1;

    printf("\nNext fit algorithm:\n");
    for (i=0; i<n; ++i)
        next[i] = memoryBlock[i];

    for (i=0; i<p; ++i)
    {
        flag = 1;
        for (j=index; j<n; ++j)
        {
            if (pro[i] < next[j])
            {
                next[j] -= pro[i];
                flag = 0;
                printf("process %d fits into memory block %d, final memory in block: %d\n", i+1, j+1, next[j]);
                break;
            }
        }

        if (flag)
        {
            for (j=0; j<index; ++j)
            {
                if (pro[i] < next[j])
                {
                    next[j] -= pro[i];
                    printf("process %d fits into memory block %d, final memory in block: %d\n", i+1, j+1, next[j]);
                    break;
                }
            }   
        }
    }
    printf("\n\n\n");
}

void main ()
{
    int n, p, i;
    printf("enter no of partitions: ");
    scanf("%d", &n);

    printf("enter memory of each partition: ");
    for (i=0; i<n; ++i)
        scanf("%d", &memoryBlock[i]);

    printf("enter number of process: ");
    scanf("%d", &p);

    printf("enter memory of each process: ");
    for (i=0; i<p; ++i)
        scanf("%d", &pro[i]);

    firstFit(n, p);
    bestFit(n, p);
    worstFit(n, p);
    nextFit(n, p);

}
