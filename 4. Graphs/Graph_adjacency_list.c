// implementation of graph using adjacency list

#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

typedef struct nodes
{
	int info;
	struct node* next;
}NODE;

void init_graph(NODE *s[], int n);
void create_graph(NODE *s[], int n);
void display_graph(NODE *s[], int n);
void addEdge(NODE *s[],int src, int dest);
void destroy_graph(NODE *s[], int );

int main()
{
	int n;
	printf("enter the number of nodes u want in the graph\n");
	scanf("%d", &n);
	NODE *s[MAX];
	init_graph(s,n);
	create_graph(s,n);
	display_graph(s,n);
	destroy_graph(s, n);
	return 0;
}

void init_graph(NODE *s[],int n)
{
	for(int i = 0; i < n ; i++)
	{
		s[i] = NULL;
	}
}

void create_graph(NODE *s[], int n)
{
	int choice;
	do{
		int src, dest;
		printf("enter the src and destination\n");
		scanf("%d%d", &src, &dest);
		addEdge(s,src,dest);
		printf("do u want to add more nodes? Press 1\n");
		scanf("%d", &choice);
	}while(choice);
}

void addEdge(NODE *s[],int src, int dest)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = dest;
	temp->next = s[src-1];
	s[src-1] = temp;
}

void display_graph(NODE *s[], int n)
{
	
	for(int i = 0; i < n; i++)
	{
		NODE *p = s[i];
		printf("s[%d]-->", i);
		while(p != NULL)
		{
			printf("%d\t", p->info);
			p = p->next;
		}
		printf("\n");	
	}
}

void destroy_graph(NODE *s[], int n)
{
	NODE *p, *q;
	for(int i = 0; i < n ; i++)
	{
		p = s[i];
		while(p != NULL)
		{
			q = p;
			printf("%d deleted\n", q->info);
			p = p->next;
			free(q);	
		}
		s[i] = NULL;	
	}
}
