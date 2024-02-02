// To implement queues using two stacks

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *a;
    int top;
    int size;
}STACK;

void init(STACK *s1,STACK *s2,int n);
void enqueue(STACK *s1, int ele);
int dequeue(STACK *s1,STACK *s2);
int isFull(STACK *s1);
int isEmpty(STACK *s1);
void display(STACK *s);


int main()
{
    STACK s1;
    STACK s2;
    int n;
    printf("Enter the size of queue:\n");
    scanf("%d",&n);
    init(&s1,&s2,n);
    int choice,ele,del_ele;
    do{
        printf("1. enqueue 2. dequeue  3. display 4. exit\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter the element to be added to queue:\n");
                    scanf("%d",&ele);
                    enqueue(&s1,ele);
                    break;
            case 2: 
                    if(isEmpty(&s1))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = dequeue(&s1,&s2);
						printf("deleted element is %d\n", del_ele);
					}
					break;
                    
            case 3:
                    display(&s1);
                    break;
        }
    }while(choice<=3);

    return 0;
}

void init(STACK *s1,STACK *s2,int n)
{
    s1->top = s2->top = -1;
    s1->size = s2->size = n;
    s1->a = (int*)malloc(n*sizeof(int));
    s2->a = (int*)malloc(n*sizeof(int));
}

int isFull(STACK *s)
{
	return s->top == s->size-1;
}

int isEmpty(STACK *s)
{
	return (s->top == -1);
}

void enqueue(STACK *s, int ele)
{
    if(isFull(s))
        printf("You cannot add more elements\n");
    else
    {
        s->top++;
        s->a[s->top] = ele;
    }
}

int dequeue(STACK *s1,STACK *s2)
{
    /* s2->top++;
    while(s1->top != -1)    //while(!isEmpty(s1))
    {
        s2->a[s2->top] = s1->a[s1->top];
        s1->top--;
        s2->top++;
    }
    s2->top--;
    int r = s2->a[s2->top];
    s2->top--;
    s1->top++;
    while(s2->top != -1)      //while(!isEmpty(s2))
    {
        s1->a[s1->top] = s2->a[s2->top]; 
        s1->top++;
        s2->top--;
    }
    s1->top--;
    return r; */

    while(s1->top != -1)    //while(!isEmpty(s1))
    {
        s2->top++;
        s2->a[s2->top] = s1->a[s1->top];
        s1->top--;
    }
    int r = s2->a[s2->top];
    s2->top--;
    while(s2->top != -1)      //while(!isEmpty(s2))
    {
        s1->top++;
        s1->a[s1->top] = s2->a[s2->top]; 
        s2->top--;
    }
    return r;
}

void display(STACK *s)
{
    if(isEmpty(s))
		printf("no elements to display\n");
	else
	{
        printf("elements in the queue are listed below\n");
        for(int i = 0; i <= s->top; i++)
            printf("%d\t", s->a[i]);
	}
    printf("\n");
}



