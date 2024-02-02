#include<stdio.h>

void sort(int a[],int n);
void swap(int *x,int *y);
void disp(int a[],int n);
void read(int a[],int n);

int main()
{ 
    int a[100];
    int n;
    printf("enter the number of elements u want to sort\n");
    scanf("%d",&n);
    printf("enter %d elements\n",n);
    read(a,n);
    printf("before sorting\n");
    disp(a,n);
    sort(a,n);
    printf("after sorting\n");
    disp(a,n);
    return 0;
}

void read(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void disp(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int a[],int n)
{
    int i,pos,j;
    for(i = 0;i<n-1;i++)
    {
        pos = i;
        for(j = i+1;j<=n-1;j++)
        {
            if(a[pos]>a[j])
                pos = j;
        }
        if(pos != i) // think about this
            swap(&a[pos],&a[i]);
    }
}

