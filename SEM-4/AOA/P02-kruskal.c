#include <stdio.h>
#include <conio.h>
# define MAX 20
int adj[MAX][MAX];
int visited[MAX];
struct edge
{
    int wt;
    int v1;
    int v2;
}e[MAX*MAX],temp;
void sort(int n)
{
    int i,flag,j;
    flag = 0;
    for(i=0;i<n-1;i++)
    {
        flag = 0;
        for(j=i+1;j<n;j++)
            if(e[i].wt>e[j].wt)
            {
                temp = e[j];
                e[j] = e[i];
                e[i] = temp;
                flag  =1;
            }
        if(flag==0)
            break;
    }
}
void kruskal(int eindex)
{
    int i;
    for(i=0;i<eindex;i++)
    {
        if((visited[e[i].v1]!=1)||(visited[e[i].v2]!=1))
        {
            if(visited[e[i].v1]!=1)
                visited[e[i].v1]=1;
            if(visited[e[i].v2]!=1)
                visited[e[i].v2]=1;
            printf("\nEdge added : %d-----%d with weight %d\n",e[i].v1+1,e[i].v2+1,e[i].wt);
        }
    }
}
void main()
{
    int i,n,j;
    int eindex = -1;
    clrscr();
    printf("Enter no. of vertices");
    scanf("%d",&n);
    printf("Enter the weights of adjecency");
    for(i = 0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("Enter weight between %d vertex and %d vertex ",(i+1),(j+1));
            scanf("%d",&adj[i][j]);
            if(adj[i][j]!=0)
            {
                eindex++;
                e[eindex].wt = adj[i][j];
                e[eindex].v1 = i;
                e[eindex].v2 = j;

            }
        }
        printf("\n");
    }
    sort(eindex);
    kruskal(eindex);
    getch();
}