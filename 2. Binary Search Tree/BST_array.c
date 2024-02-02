#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct bst_array
{
    int info;
    int used;
}NODE;

void initTree(NODE *t);
void createTree(NODE *t);
void displayTree(NODE *t);

int main()
{
    NODE t[MAX];
    initTree(t);
    createTree(t);
    displayTree(t);
    return 0;
}

void initTree(NODE *t)    // void initTree(NODE t[])
{
    for(int i = 0; i < MAX; i++)
    {
        t[i].used = 0;     // t[i]. = array notation  // *(t+1). is pointer notation
    }
}

void createTree(NODE *t)
{
    printf("Enter the root node data:\n");
    scanf("%d",&(t[0].info));
    t[0].used = 1;
    int ch;
    do{
        printf("Enter one more node data:\n");
        int temp;
        scanf("%d",&temp);
        int p = 0;
        while(p < MAX && t[p].used == 1)            // evertime p shd be start with 0 and the values of that index with the temp.
        { 
            if(temp <= t[p].info)
            {
                p = 2*p+1;
            }
            else
            {
                p = 2*p+2;
            }
        }
        if(p >= MAX)
        {
            printf("array out of bound\n");
            exit(0);
        }
        else
        {
            t[p].info = temp;
            t[p].used = 1;
        }
        printf("Do u want to add more elements press 1\n");
        scanf("%d",&ch);
    }while(ch == 1);
}

void displayTree(NODE *t)
{
    for(int i = 0; i < MAX; i++)
    {
        if(t[i].used == 1)
        {
            printf("%d\t",t[i].info);
            t[i].used = 0;
        }
    }
}


