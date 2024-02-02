// Implement Bottom up heap construction for a Min heap(Ascending heap)

#include<stdio.h>
#define MAX 100

void read(int *a, int n);
void display(int *a, int n);
void heapify(int *a, int n, int i);
void bottomUp(int *a, int n);


int main()
{
	int a[MAX];
	int n;
	printf("enter the number of nodes u want in the tree:\n");
	scanf("%d", &n);
	printf("enter %d elements:\n", n);
	read(a,n);
    printf("array before heapify:\n");
    display(a,n);
	bottomUp(a,n);                      // array is used so,in-place algorithm (no more memory locations are used other than temp) 
	printf("array after heapify:\n");
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

void bottomUp(int *a, int n)
{
    int l = (n/2)-1;                       // Index of the last non-leaf node
    for (int i = l; i >= 0; i--) 
    {
        heapify(a, n, i);
    }
}

void heapify(int *a, int n, int i)
{
    int index = i;                   
    int left = 2 * i + 1;             
    int right = 2 * i + 2;              

    if (left < n && a[left] < a[index])
    {
        index = left;
    }

    if (right < n && a[right] < a[index])
    {
        index = right;
    }
     
    if (index != i) 
    {
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
        heapify(a, n, index);
    } 
}
