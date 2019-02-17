/*
	Kruskal's Algorithm
	===================

	Input Adjacency Matrix

	Store all Edges in Edge Array

	Sort above Edge array

	Select edge and add to MST if no cycle is formed
	> How to check that ?
	  - Check if both of these two nodes has been visited before
	    - checkCyclic does that

*/

#include<stdio.h>
#define MAX 10

int visited[MAX];
int n;
int graph[MAX][MAX];

struct edge {
	int v1, v2;
	int weight;
}edges[MAX*MAX];

int nOfEdge;

int isCycleFormed(int n1, int n2) {
	if(visited[n1] == 1 && visited[n2] == 1)
		return 1;
	else
		return 0;
}

void initGraph() {
	int i, j;
	for(i = 0; i < MAX; i++) {
		for(j = 0; j < MAX; j++) {
			graph[i][j] = 9999;
		}
		visited[i] = 0;
	}
}

void scanGraph() {
	int i, j;
        for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                        scanf("%d", &graph[i][j]);
                }
        }
}

void initEdgeStruct() {
	int i, j;
	int k = 0;
	for(i = 0; i < n; i++) {
		for(j = i; j < n; j++) {
			if(graph[i][j] < 9999) {
				edges[k].v1 = i;
				edges[k].v2 = j;
				edges[k].weight = graph[i][j];
				k++;
			}
		}
	}
	nOfEdge = k + 1;
}

void sortEdgeStruct() {
	int i, j;
	struct edge t;
	for(i = 0; i < nOfEdge; i++) {
		for(j = 0; j < nOfEdge - i - 1; j++) {
			if(edges[j].weight > edges[j+1].weight) {
				t = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = t;
			}
		}
	}
}

void createMST() {
	int l;
	initEdgeStruct();
	sortEdgeStruct();
	for(l = 0; l < nOfEdge; l++) {
		if(!isCycleFormed(edges[l].v1, edges[l].v2)) {
			printf("\n(%d, %d) -> %d", edges[l].v1 + 1 , edges[l].v2 + 1, edges[l].weight);
			visited[edges[l].v1] = 1;
			//visited[edges[l].v2] = 1;
		}
	}
}

void main() {
	printf("Enter the number of elements");
	scanf("%d", &n);
	initGraph();
	scanGraph();
	createMST();
}
