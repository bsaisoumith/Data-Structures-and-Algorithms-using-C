// Implement the iterative inorder,preorder,postorder traversal of a binary tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
}NODE;

typedef struct Tree
{
    NODE *root;
}TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inOrder_iterative(TREE *pt);
void preOrder_iterative(TREE *pt);
void postOrder_iterative(TREE *pt);
void destroyTree(TREE *pt);
void destroyNode(NODE *r);


int main()
{
    TREE t;
    initTree(&t);
    createTree(&t);
    printf("using inorder:\n");
    inOrder_iterative(&t);
    printf("using preorder:\n");
    preOrder_iterative(&t);
    printf("using postorder:\n");
    postOrder_iterative(&t);
    printf("deleting a tree:\n");
    destroyTree(&t);
    return 0;
}

void initTree(TREE *pt)
{
    pt->root = NULL;
}

void createTree(TREE *pt)
{
    int choice;
    do{
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        printf("enter the element:\n");
        scanf("%d", &(temp->info));
        temp->left = temp->right = NULL;
        if(pt->root == NULL)
        {
            pt->root = temp;
        }
        else
        {
            NODE *p = pt->root;
            NODE *q;
            while(p != NULL)
            {
                q = p;
                if(temp->info < p->info )
                {
                    p = p->left;
                }
                else
                {
                    p = p->right;
                }
            }
            if(temp->info <= q->info)
            {
                q->left = temp;
            }
            else
            {
                q->right = temp;
            } 
        }
        printf("do u want to enter more elements, press 1\n");
        scanf("%d",&choice);
    }while(choice == 1);
}

void inOrder_iterative(TREE *pt)
{
    NODE *s[100];
	int top = -1;
	NODE *current = pt->root;
	do{
		while(current != NULL)
		{
			s[++top] = current;
			current = current->left;
		}
		current = s[top--];
		printf("%d\t", current->info);
		current = current->right;
	}while(top != -1 ||  current != NULL);
    printf("\n");
}

void preOrder_iterative(TREE *pt)
{
    NODE *s[100];
    int top = -1;
    NODE *current = pt->root;
    do{
        while(current != NULL)
		{
			s[++top] = current;
            printf("%d\t", current->info);
			current = current->left;
		}
        current = s[top--];
        current = current->right;
    }while(top != -1 ||  current != NULL);
    printf("\n");
}

void postOrder_iterative(TREE *pt)
{
    NODE *s1[100];
    NODE *s2[100];
    int top1 = -1;
    int top2 = -1;
    NODE *current = pt->root;
    s1[++top1] = current;

    while(top1 != -1)
    {
        current = s1[top1];
        top1--;
        s2[++top2] = current;
        if(current->left != NULL)
            s1[++top1] = current->left;
        if(current->right != NULL)
            s1[++top1] = current->right;
    }

    while(top2 != -1)
    {
        printf("%d\t",s2[top2]->info);
        top2--;
    }
    printf("\n");
}

void destroyNode(NODE *r)
{
    if(r != NULL)
    {
        destroyNode(r->left);
        destroyNode(r->right);
        printf("%d\t",r->info);
        free(r);
    }
}

void destroyTree(TREE *pt)
{
    destroyNode(pt->root);
}


