// implementation of bfs traversal for a graph

#include<stdio.h>
#define MAX 10

void bfs(int a[MAX][MAX],int n,int visited[], int source);
void readGraph(int a[MAX][MAX], int n);

int main()
{
	int a[MAX][MAX] ;
	int visited[MAX] = {0};
	int n, source;
	printf("enter the number of nodes\n");
	scanf("%d", &n);
	printf("enter the values in adjacency matrix\n");
	readGraph(a, n);
	printf("enter the source\n");
	scanf("%d", &source);
	printf("bfs traversal for this tree is\n");
	bfs(a,n,visited, source);
	return 0;
}

void readGraph(int a[MAX][MAX], int n)
{
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0 ; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void bfs(int a[MAX][MAX],int n,int visited[], int source)
{
	int r = -1;
	int f = 0;
	int q[n];
	q[++r] = source;
	visited[source] = 1;
	
	int v;
	while(f <= r)
	{
		v = q[f++];
		printf("%d\t", v);
		for(int i = 0; i < n ; i++)
		{
			if((a[v][i]) && visited[i] == 0)
			{
				q[++r] = i;
				visited[i] = 1;
			}
		}	
	}	
}


