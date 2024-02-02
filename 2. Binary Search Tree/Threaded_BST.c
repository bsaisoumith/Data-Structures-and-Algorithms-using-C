#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
    int rthread;
}NODE;

typedef struct Tree
{
    NODE *root;
}TREE;

void init (TREE *pt);
void createTree(TREE *pt);
void io_iterative(TREE *pt);     
void setRight(NODE *q,NODE *temp);
void setLeft(NODE *q,NODE *temp);

int main()
{
    TREE t;
    init(&t);
    createTree(&t);
    io_iterative(&t);   // in order iterative
    return 0;
}

void init (TREE *pt)
{
    pt->root = NULL;
}

void createTree(TREE *pt)
{
    printf("Enter the root node's info:\n");
    NODE*temp = (NODE*)malloc(sizeof(NODE));
    scanf("%d",&(temp->info));
    temp->left = temp->right = NULL;
    temp->rthread = 1;
    pt->root = temp;
    int choice;
    do{
        printf("please enter next node's info:\n");
        temp = (NODE*)malloc(sizeof(NODE));
        scanf("%d",&(temp->info));
        temp->left = temp->right = NULL;
        temp->rthread = 1;
        NODE *p, *q;
        p = pt->root;
        while(p != NULL)
        {
            q = p;
            if(temp->info <= p->info)
            {
                p = p->left;
            }
            else if(p->rthread)
            {
                break;
            }
            else
            {
                p = p->right;
            }
        }
        if(p == NULL)
        {
            setLeft(q,temp);
        }
        else
        {
            setRight(q,temp);
        }
        printf("Do u want to enter more nodes. Press 1\n");
        scanf("%d",&choice);
    }while(choice);

}

void io_iterative(TREE *pt)
{
    NODE *p = pt->root;
    NODE *q;
    while(p != NULL)
    {
        q = NULL;
        while(p != NULL)
        {
            q = p;
            p = p->left;
        }
        if(q != NULL)
        {
            printf("%d\t",q->info);
            p = q->right;
        }
        while(q->rthread && p != NULL)
        {
            printf("%d\t",p->info);
            q = p;
            p = p->right;
        }
    }
}

void setRight(NODE *q,NODE *temp)
{
    temp->right = q->right;
    q->right = temp;
    q->rthread = 0;
}

void setLeft(NODE *q,NODE *temp)
{
    q->left = temp;
    temp->right = q;
}