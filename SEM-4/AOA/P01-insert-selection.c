#include<stdio.h>

void main()
{
    int sel[1000], i, j, n, inr[1000], temp, selIndex;
    
    // counters
    int cFor, cWhile;

    printf("enter number of numbers: ");
    scanf("%d",&n);

    printf("enter numbers: ");
    for (i=0; i<n; i++)
        scanf("%d",&sel[i]);

    // clone arrays
    for (i=0; i<n; i++)
        inr[i] = sel[i];

    // insertion sort
    cFor = 0;
    cWhile = 0;

    for (i=1; i<n; i++)
    {
        temp = inr[i];
        j = i-1;

        while ( inr[j] > temp && j >= 0 )
        {
            inr[j+1] = inr[j];
            j--;
            cWhile++;
        }

        inr[j+1] = temp;
        cFor++;
    }

    printf("\nSorted numbers (using insertion sort): ");
    for (i=0; i<n; i++)
        printf("%d ",inr[i]);

    printf("\nCounter For: %d \t While: %d", cFor, cWhile);


    // selection count
    cFor = 0;
    cWhile = 0;

    for (i=0; i<n; i++)
    {
        selIndex = i;
        for (j=i+1; j<n; j++)
        {
            if ( sel[j] < sel[selIndex] )
                selIndex = j;

            cWhile++;
        }

        temp = sel[i];
        sel[i] = sel[selIndex];
        sel[selIndex] = temp;

        cFor++;
    }

    printf("\nSorted numbers (using selection sort): ");
    for (i=0; i<n; i++)
        printf("%d ",sel[i]);

    printf("\nCounter For: %d \t nested For: %d", cFor, cWhile);
}

/*
// Output
BEST CASE:
10
1 2 3 4 5 6 7 8 9 10

Sorted numbers (using insertion sort): 1 2 3 4 5 6 7 8 9 10 
Counter For: 9 	 While: 0
Sorted numbers (using selection sort): 1 2 3 4 5 6 7 8 9 10 
Counter For: 10 	 nested For: 45


WORST CASE:
10
10 9 8 7 6 5 4 3 2 1

Sorted numbers (using insertion sort): 1 2 3 4 5 6 7 8 9 10 
Counter For: 9 	 While: 45
Sorted numbers (using selection sort): 1 2 3 4 5 6 7 8 9 10 
Counter For: 10 	 nested For: 45



BEST CASE:
100
1 ... 100

Sorted numbers (using insertion sort):
Counter For: 99 	 While: 0
Sorted numbers (using selection sort):
Counter For: 100 	 nested For: 4950

WORST CASE
100
100 ... 1

Sorted numbers (using insertion sort):
Counter For: 99 	 While: 4950
Sorted numbers (using selection sort):
Counter For: 100 	 nested For: 4950
*/
