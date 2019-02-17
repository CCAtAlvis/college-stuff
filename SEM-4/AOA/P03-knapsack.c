//
// Knapsack Problem
//
// we have n objects and knapsack with capacity m, for each object i
// in 1<=i<=n have profit value pi and weight value wi
//
// objective: to obtain a filling of knapsack
// that maximizes the total profit
//
// since the capacity is m, it should follow constrain
// maximize sum: pi*Xi 1<=i<=n
// sum capicity: wi*Xi < capacity
//
// algorithm: calculate pi/wi value and sort in descending order
// now give priority to highest pi/wi till either item or
// knapsack capicity is reached
// repeate the step till the knapsack is filled
//

#include<stdio.h>
#include<conio.h>

#define MAX 50

struct item
{
    float profit, weight, ratio, frac;
} ip[MAX], temp;

void main()
{
    int i,j,k,n;
    float cap, profit;
    clrscr();

    // take user input
    printf("enter capacity of knapsack: ");
    scanf("%f",&cap);

    printf("enter number of items: ");
    scanf("%d",&n);

    printf("enter profit and weight of items: \n");
    for (i=0;i<n;i++)
    {
        printf("profit: ");
        scanf("%f", &ip[i].profit);
        printf("weight: ");
        scanf("%f", &ip[i].weight);
        printf("\n");
    }

    // find profit to weight ratio
    for (i=0;i<n;i++)
        ip[i].ratio = ip[i].profit / ip[i].weight;

    // sorting
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if ( ip[j].ratio < ip[j+1].ratio )
            {
                temp = ip[j+1];
                ip[j+1] = ip[j];
                ip[j] = temp;

            }
        }

    // printf("\n\n");
    // for (i=0;i<n;i++)
    // {
    // 	printf("%f ",ip[i].ratio);
    // }

    i = 0;
    profit = 0;
    while (cap > 0)
    {
        if (i == n)
            break;

        if ( ip[i].weight < cap )
        {
            cap -= ip[i].weight;
            ip[i].frac = 1;
            profit += ip[i].profit;
            i++;
        }
        else
        {
            ip[i].frac = cap/ip[i].weight;
            profit += ip[i].profit*ip[i].frac;
            break;
        }
    }

    for (i=0;i<n;i++)
    {
        printf("%2f ", ip[i].frac);
    }


    printf("\n\nTotal profit: %2f", profit);
    getch();
}
