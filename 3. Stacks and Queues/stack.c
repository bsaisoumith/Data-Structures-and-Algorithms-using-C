// stack implementation using static array

#include<stdio.h>

#define MAX 5

typedef struct stack
{
    int a[MAX];
    int top;
}STACK;

void init(STACK* s);
void push(STACK* s, int ele);
int pop(STACK* s,int* del_ele);
int isFUll(STACK *s);
int isEmpty(STACK *s);
int peek(STACK* s);
void display(STACK* s);


int main()
{
    STACK s;
    init(&s);   // s.top = -1;
    int choice;
    do
    {
        printf("1. push 2. pop 3. full or not 4. empty or not 5. peek 6. display 7. exit\nEnter your choice\n");
        scanf("%d",&choice);
        int ele, res, del_ele, data;
        switch(choice)
        {
            case 1:
                printf("enter the element u want to push to stack\n");
                scanf("%d",&ele);
                push(&s,ele);
                break;
            case 2:
                res = pop(&s,&del_ele);
                if(res != -1)
                    printf("deleted element is %d\n",del_ele);
                break;
            case 3:
                if(isFull(&s))
                    printf("The stack is full, You cannot insert more elements\n");
                else
                    printf("You can insert more elements\n");
                break;
            case 4:
                if(isEmpty(&s))
                    printf("The stack is full, You cannot delete elements\n");  
                else
                    printf("You can delete and insert more elements\n"); 
                break;
            case 5:
                data = peek(&s);
                if(data != -1)
                    printf("element at top is %d\n",data);
                else
                    printf("Stack is empty, cannot get any element\n");
                break;
            case 6:
                display(&s);
                break;
            default: printf("exiting from here\n");
        }
    }while(choice<8);
    return 0;
}

void init(STACK* s)
{
    s->top = -1;
}

void push(STACK *s, int ele)
{
    if(isFull(s))
        printf("You cannot add more elements\n");
    else
    {
        s->top++;
        s->a[s->top] = ele;

        // s->a[++s->top] = ele;
    }
}

int pop(STACK *s,int *del_ele)
{
    //if(s->top == -1)
    if(isEmpty(s))
    {
        printf("There are no elements to pop\n");
        return -1;
    }   
    else
    {
        *del_ele = s->a[s->top];
        s->top--;
        return 0;

       // above statements can be merged   *del_ele = s->a[s->top--];
    }
}

int isFull(STACK* s)
{
    return s->top == MAX-1;
}

int isEmpty(STACK* s)
{
    return s->top == -1;
}

int peek(STACK* s)
{
    if(isEmpty(s))
    {
        return -1;
    }
    return s->a[s->top];
}

void display(STACK* s)
{
    if(isEmpty(s))
    {
        printf("No elements to display\n");
    }
    else
    {
        printf("The elements are displayed below\n");
        for(int i = s->top; i >= 0; i--)
        {
            printf("%d\t",s->a[i]);
        }        
    }
    printf("\n");
}