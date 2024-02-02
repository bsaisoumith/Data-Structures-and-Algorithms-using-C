#include<stdio.h>
int mysearch(int a[],int low,int high,int key)
{

        /*
            Algorithm Binary_Search(list, item)
        1. Set L to 0 and R to n: 1
        2. if L > R, then Binary_Search terminates as unsuccessful
        3. else,Set m (the position in the mid element) to the floor of (L + R) / 2
        4. if Am < T, set L to m + 1 and go to step 2
        5. if Am > T, set R to m: 1 and go to step 2
        6. Now, Am == T, the search is done and return (m).  */

    /* binary search - iterative solution

    int pos = -1;
    int found = 0;

    // if found variable is not created, what is the problem. Think about it?

    while(low <= high && found == 0)
    {
        int mid = (low+high)/2;
        if(a[mid]==key)
            pos = mid; found = 1;
        else if(key<a[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return pos; */

    /*
        BinarySearch.(x:target;{a1,a2,…,an}:sorted list of items;
        1. begin:pos;end:pos
        2. mid:=(begin+end)/2
        3. If begin>end:return -1
        4. else if x==amid:return mid
        5. else if x<amid:return BinarySearch(x;{a1,a2,…,an};begin;mid-1)
        6. else return BinarySearch(x;{a1,a2,…,an};mid+1,end);   */

// Recursive solution
    if(low > high) // base condition
        return -1;
    else
    {
        int mid = (low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(key<a[mid])
            return mysearch(a,low,mid-1,key);
        else
            return mysearch(a,mid+1,high,key);
    }


}

int main()
{
    int a[5];
    int key; int n; int i;
    a[0]=10; a[1]=20; a[2]=30; a[3]=40; a[4]=50;
    printf("enter the element to be searched\n");
    scanf("%d",&key);
    int res = mysearch(a,0,5,key);
    if(res == -1)
        printf("not found");
    else
        printf("found at %d\n",res);
    return 0;
}