#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

typedef struct node
{
    char info;
    struct node *left;
    struct node *right;
}NODE;

typedef struct tree 
{
    NODE *root;
}TREE;

typedef struct stack
{
   NODE *s[MAX];
   int top; 
}STACK;

void init_tree(TREE *t);
void init_stack(STACK *ps);
void push(STACK *ps,NODE *temp);
NODE* pop(STACK *ps);
void display(STACK* );
int evaluate_tree(TREE* t);
int eval(NODE *r);


int main()
{   
    TREE tobj;
    STACK sobj;
    char postfix[100];
    printf("Enter the valid postfix exrpession:\n");
    scanf("%d",&postfix);
    init_tree(&tobj);
    init_stack(&sobj);
    int i;
    while(postfix[i] != '\0')
    {
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        if(isdigit(postfix[i]))
        {
            temp->info = postfix[i] - '\0';
            temp->left = temp->right = NULL;
            push((&sobj),temp);
        }  
        else
        {
            temp->info = postfix[i];
            temp->left = temp->right = NULL;
            temp->right = pop(&sobj);
            temp->left = pop(&sobj);
            push(&sobj,temp);
        }
        i++;
    }
    tobj.root = pop(&sobj);
    printf("Result of evaluation is %d\n",evaluate_tree(&tobj));
    return 0;
}

void init_tree(TREE *t)
{
    t->root = NULL;
}

void init_stack(STACK* ps)
{
    ps->top = -1;
}

void push(STACK *ps, NODE* temp)
{
    if(ps->top == MAX-1)
        return;
    ps->top++;
    ps->s[ps->top] = temp;
}

NODE* pop(STACK* ps)
{
    NODE *t = ps->s[ps->top];
    ps->top--;
    return t;
}

int eval(NODE *r)
{
    int result;
    switch(r->info)
    {
        case '+': return eval(r->left) + eval(r->right);
            
        case '-': return eval(r->left) - eval(r->right);
                  
        case '*': return eval(r->left) * eval(r->right);
                  
        case '/': return eval(r->left) / eval(r->right);
                  
    }
}

int evaluate_tree(TREE *t)
{
    return eval(t->root);
}

/* void display(STACK *)
{

} */
