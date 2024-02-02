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
void inOrder(TREE *pt);
void preOrder(TREE *pt);
void postOrder(TREE *pt);
void destroyTree(TREE *pt);
void inord(NODE* p);
void preord(NODE* p);
void postord(NODE* p);
void destroyNode(NODE *r);
void inOrder_iterative(TREE *pt);
void minimum(TREE *pt);
void maximum(TREE *pt);
void height(TREE *pt);
void leafcount(TREE *pt);
int ht(NODE *t);
int count(NODE *t);

int main()
{
    TREE t;
    initTree(&t);
    createTree(&t);

    // using the recursive method
    printf("using preorder:\n");
    preOrder(&t);
    printf("using inorder:\n");
    inOrder(&t);
    printf("using postorder:\n");
    postOrder(&t);

    printf("\n\n");

    // using the iterative method
    printf("using inorder:\n");
    inOrder_iterative(&t);

    minimum(&t);
    maximum(&t);
    height(&t);
    leafcount(&t);

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

void inord(NODE* p)
{
    if(p != NULL)
    {
        inord(p->left);
        printf("%d\t",p->info);
        inord(p->right);
    }
}

void inOrder(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to display\n");
    }
    else
    {
        inord(pt->root);
    }
    printf("\n");
}

void preord(NODE* p)
{
    if(p != NULL)
    {
        printf("%d\t",p->info);
        preord(p->left);
        preord(p->right);
    }
}

void preOrder(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to display\n");
    }
    else
    {
        preord(pt->root);
    }
    printf("\n");
}

void postord(NODE* p)
{
    if(p != NULL)
    {
        postord(p->left);
        postord(p->right);
        printf("%d\t",p->info);
    }
}

void postOrder(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to display\n");
    }
    else
    {
        postord(pt->root);
    }
    printf("\n");
}

void destroyTree(TREE *pt)
{
    destroyNode(pt->root);
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


void minimum(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to find\n");
    }
    else
    {
        NODE *t = pt->root; 
        while(t->left != NULL)
        {
            t = t->left;
        }
        printf("Minimum element in a tree: %d\n",t->info); 
    }
}

void maximum(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to find\n");
    }
    else
    { 
        NODE *t = pt->root; 
        while(t->right != NULL)
        {
            t = t->right;
        }
        printf("Maximum element in a tree: %d\n",t->info); 
    }
}

void height(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to find\n");
    }
    else
    {
        printf("Height of a tree: %d\n",ht(pt->root));
    }
}

int ht(NODE *t)
{
    if(t == NULL)
    {
            return -1;
    }
    if((t->left==NULL)&&(t->right==NULL))
    {
        return 0;
    }
    return (1+max(ht(t->left),ht(t->right)));
}

void leafcount(TREE *pt)
{
    if(pt->root == NULL)
    {
        printf("No nodes to find\n");
    }
    else
    {
        printf("Number of leaves in a tree: %d\n",count(pt->root));
    }
}

int count(NODE *t)
{
    if(t == NULL)
    {
           return 0;
    }
    if((t->left == NULL) && (t->right == NULL))
    {
        return 1;
    }
    int l = count(t->left);
    int r = count(t->right);
    return(l+r); 
}


// max element in tree  - rightmost leaf
// min element in tree - leftmost leaf
// search element 
// itertive approach for preorder and postorder