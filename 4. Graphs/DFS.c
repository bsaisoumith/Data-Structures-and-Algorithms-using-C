// implementation of dfs traversal for a graph

#include<stdio.h>
#define MAX 10

void dfs(int a[MAX][MAX],int n,int visited[], int source);
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
	printf("dfs traversal for this graph is\n");
	dfs(a,n,visited, source);
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

void dfs(int a[MAX][MAX],int n,int visited[], int source)
{
	int top = -1;
	int s[n];
	s[++top]= source;
//	visited[source] = 1;
	//printf("%d", s[top]);
	int flag;
	while(top != -1)
	{
		flag = 0;
		source = s[top];  // 60
		int i;
		for(i = 0; i < n; i++)
		{
			if(a[source][i] && !visited[source])
			{
				flag =1;
				printf("hello");
				break;
				//jhf
			}
		//	jdhfgh
		}
		printf("flag value is %d\n", flag);
		if(flag)
		{
			s[++top] = i;
			visited[i] = 1;
			printf("%d", i);
		}
		else
		{
			top--;
		}
	}
}