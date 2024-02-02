// stack implementation using dynamic array

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int *a;
	int top;
	int SIZE;
}STACK;

void init(STACK *s, int n);
void push(STACK *s, int ele);
int pop(STACK*,int*);
int isFull(STACK *s);
int isEmpty(STACK *s);
int peek(STACK*);
void display(STACK*);


int main()
{
	STACK s;
	int n;
	printf("what should be size of stack\n");
	scanf("%d", &n);
	init(&s,n); // s.top = -1;
	int choice;
	do{
		printf("1. push 2. pop 3.full or not 4. empty or not 5. peek 6.display 7. exit\nEnter your choice\n");
		int ele, res, del_ele, data;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter the element u want to push to stack\n");
					scanf("%d", &ele);
					push(&s,ele);
					break;
			case 2: res = pop(&s,&del_ele);
					if (res != -1)
						printf("deleted element is %d\n", del_ele);
					else
						printf("stack is empty, cannot pop elements\n");
					break;
			case 3: if(isFull(&s))
						printf("The stack is full, You cannot insert more elements\n");
					else
						printf("You can insert more elements\n");
					break;
			case 4: if(isEmpty(&s))
						printf("The stack is empty, You cannot delete\n");
					else
						printf("You can delete and insert more elements\n");break;
			case 5: data = peek(&s);
					if(data != -1)
						printf("element at the top is %d\n", data);
					else
					printf("stack is empty. cannot get any element\n");
					break;
					
			case 6: display(&s);
					break;
			default: printf("exiting\n");
			
		}
	}while(choice<=6);
	return 0;
}

void init(STACK *s, int n)
{
	s->top = -1;
	s->SIZE = n;
	s->a = malloc(n*sizeof(int));
}
void push(STACK *s, int ele)
{
	if(isFull(s))
	{	
		printf("u cannot add more elements\n");
	}
	else
	{
		s->top++;
		s->a[s->top] = ele;
		
		//s->a[++s->top] = ele;
	}
		
}
int pop(STACK* s,int* del_ele)
{
	//if(s->top == -1)
		if(isEmpty(s))
		{	
			return -1;
		}
		*del_ele = s->a[s->top];
		s->top--;
		return 1;
			
		//above two statements can be merged this way->	*del_ele = s->a[s->top--];
}

int isFull(STACK *s)
{
	//return s->top == MAX-1;
	return s->top == s->SIZE-1;
}
int isEmpty(STACK *s)
{
	return (s->top == -1);
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
		printf("no elements to display\n");
	}
	else
	{
		printf("elements in the stack are listed below\n");
		for(int i = s->top; i>=0; i--)
		{
			printf("%d\t", s->a[i]);
		}
	}
	printf("\n");
}