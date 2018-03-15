// Prim's algorithm
#include<stdio.h>
#define MAX 30

int g[MAX][MAX]; // store the graph

int rmat[MAX][2]; // root matrix to store least root
// 0: weight
// 1: root

int v[MAX]; // stored visited vertices

void init (int n)
{
    int i;

    for (i=0; i<n; i++)
    {
        rmat[i][0] = 9999;
        rmat[i][1] = 0;
        v[i] = 0;
    }
}

void prims (int n)
{
    int f=0, u = 0, i, min, minI;
    while (f < n)
    {
        min = 9999;

        for (i=0; i<n; i++)
        {
            if (g[u][i] != 9999)
            {
                if ( !v[i] )
                {
                    if ( rmat[i][0] > g[u][i] )
                    {
                        rmat[i][0] = g[u][i];
                        rmat[i][1] = u;
                    }
                }
            }
        }

        v[u] = 1;
        for (i=0; i<n; i++)
        {
            if ( rmat[i][0] < min && !v[i])
            {
                min = rmat[i][0];
                minI = i;
            }
        }

        u = minI;
        f++;
    }
}

void main ()
{
    int i, j, n;

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter the weight adj. matrix: (if no adj. enter 9999)\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &g[i][j]);

    init(n);
    prims(n);
    printf("\n\n");

    for (i=0; i<n; i++)
        printf(" %d |", i+1);
    printf("\n");

    for (i=0; i<n; i++)
        printf(" %d |", rmat[i][0]);
    printf("\n");

    for (i=0; i<n; i++)
        printf(" %d |", rmat[i][1]+1);

    getch();
}
