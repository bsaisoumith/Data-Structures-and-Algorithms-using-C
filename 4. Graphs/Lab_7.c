/* Using any graph traversal, do the following
           A) Check if there exists a cycle in a given graph
           B) Find shortest path from source to destination */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool visited[MAX];
bool hasCycle;
int parent[MAX];
int shortestPath[MAX];
int pathLength;


void dfs(int a[MAX][MAX], int currentVertex, int parent, int n);
bool hasCycleInGraph(int a[MAX][MAX], int n);
void readGraph(int a[MAX][MAX], int n);
void init(int n);
void enqueue(int queue[], int* rear, int vertex);
int dequeue(int queue[], int* front);
bool isQueueEmpty(int front, int rear);
void bfs(int a[MAX][MAX],int src, int dest, int n);
int printShortestPath(int src, int dest);

int main() 
{
    int a[MAX][MAX];
	int visited[MAX] = {0};
	int n;
	printf("enter the number of nodes\n");
	scanf("%d", &n);
	printf("enter the values in adjacency matrix\n");
	readGraph(a, n);
    if (hasCycleInGraph(a, n)) 
	{
        printf("The graph contains a cycle.\n");
    } 
	else 
	{
        printf("The graph does not contain a cycle.\n");
    }

    int src, dest;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    init(n);
    pathLength = 0;
    bfs(a,src, dest, n);
    if(!printShortestPath(src, dest))
    {
        printf("There is no shortest path\n");
    }   
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

bool hasCycleInGraph(int a[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        visited[i] = false;
    }
    hasCycle = false;

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            dfs(a, i, -1, n);
            if(hasCycle) 
            {
                return true;
            }
        }
    }
    return false;
}

void dfs(int a[MAX][MAX], int currentVertex, int parent, int n) 
{
    visited[currentVertex] = true;
    for (int i = 0; i < n; i++) 
    {
        if (a[currentVertex][i]) 
        {
            if (!visited[i]) 
            {
                dfs(a, i, currentVertex, n);
            } 
            else if (i != parent) 
            {
                hasCycle = true;
                return;
            }
        }
    }
}

void init(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        visited[i] = false;
        parent[i] = -1;
    }
}

void enqueue(int queue[], int* rear, int vertex) 
{
    queue[++(*rear)] = vertex;
}

int dequeue(int queue[], int* front) 
{
    return queue[(*front)++];
}

bool isQueueEmpty(int front, int rear) 
{
    return front > rear;
}

void bfs(int graph[MAX][MAX],int src, int dest, int n) 
{
    int queue[MAX];
    int front = 0, rear = -1;
    
    visited[src] = true;
    enqueue(queue, &rear, src);

    while (!isQueueEmpty(front, rear)) 
    {
        int currentVertex = dequeue(queue, &front);

        if (currentVertex == dest) 
        {
            int vertex = dest;
            while (vertex != src) 
            {
                shortestPath[pathLength++] = vertex;
                vertex = parent[vertex];
            }
            shortestPath[pathLength++] = src;
            return;
        }
        for (int i = 0; i < n; i++) 
        {
            if (graph[currentVertex][i] && !visited[i]) 
            {
                visited[i] = true;
                parent[i] = currentVertex;
                enqueue(queue, &rear, i);
            }
        }
    }
}

int printShortestPath(int src, int dest) 
{
    if(shortestPath[0] == 0)
    {
        return 0;
    }
    else
    {
        printf("Shortest path from %d to %d: ", src, dest);
        for (int i = pathLength - 1; i >= 0; i--) 
        {
            printf("%d ", shortestPath[i]);
        }
        printf("\n");
        return 1;
    }
}



