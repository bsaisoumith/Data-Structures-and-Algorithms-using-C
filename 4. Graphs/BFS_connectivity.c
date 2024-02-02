#include<stdio.h>
#define MAX 10

int bfs(int a[MAX][MAX],int n,int visited[], int source, int destination);
void readGraph(int a[MAX][MAX], int n);

int main()
{
	int a[MAX][MAX] ;
	int visited[MAX] = {0};
	int n, source, destination;
	printf("enter the number of nodes\n");
	scanf("%d", &n);
	printf("enter the values in adjacency matrix\n");
	readGraph(a, n);
	printf("enter the source and destination\n");
	scanf("%d%d", &source, &destination);
	
	if(bfs(a,n,visited, source, destination))
	{
		printf("path exists between %d and %d\n", source, destination);
		
	}
	else
		printf(" No path exists between %d and %d\n", source, destination);
		
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

int bfs(int a[MAX][MAX],int n,int visited[], int source, int destination)
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
		//printf("%d\t", v);
		for(int i = 0; i < n ; i++)
		{
			if((a[v][i]) && visited[i] == 0)
			{
				if(i == destination)
					return 1;
				q[++r] = i;
				visited[i] = 1;
			}
		}
		
	}
	return 0;
}