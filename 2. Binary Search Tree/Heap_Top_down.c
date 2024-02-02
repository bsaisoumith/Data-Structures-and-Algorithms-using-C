// debug this

#include<stdio.h>
#define MAX 100

void read(int *a, int n);
void display(int *a, int n);
void heapify(int *a, int n);

int main()
{
	int a[MAX];
	int n;
	printf("enter the number of nodes u want in the tree\n");
	scanf("%d", &n);
	printf("enter %d elements\n", n);
	read(a,n);
	heapify(a,n);                            // array is used so,in-place algorithm (no more memory locations are used other than temp) 
	printf("array after heapify\n");
	display(a,n);
	return 0;
}

void read(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}

void display(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void heapify(int *a, int n)
{
	printf("hello from heapify\n");
	int temp, c,p;
	for(int i = 1; i < n; i++)
	{
		c = i;
		temp = a[i];
		p = (c-1)/2;
		while(c > 0 &&  a[p] < temp)
		{		
			a[c] = a[p];
			//a[p] = temp;
			c = p;
			p = (c-1)/2;
			
		}
		a[c] = temp;
	}
}