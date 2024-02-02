#include<stdio.h>

int linear_search(int *a, int n, int key);

int main()
{
    int key = 100;
    int a[100] = {22,55,77,99,25,90,100};
    int n = 7;
    int pos = linear_search(a,n,key);
    printf("%d",pos);
    return 0;
}

int linear_search(int *a, int n, int key)
{
    int i; 
    int found = 0; 
    int pos = -1;
    for(i = 0; i< n; i++)
    {
        if(a[i]==key && found == 0)
        {
            found = 1;
            pos = i;
        }
    }
    return pos;
}


