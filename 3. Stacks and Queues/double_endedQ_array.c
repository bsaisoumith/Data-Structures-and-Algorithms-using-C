#include<stdio.h>
#define MAX 5

typedef struct Queue
{
	int a[MAX];
	int front, rear;
}QUE;

void initQ(QUE *q);
int isEmpty(QUE *q);
int isFull(QUE* q);
void display(QUE* q);
void insertRear(QUE *q,int ele);
void insertFront(QUE *q,int ele);

int main()
{
	QUE q;
	initQ(&q);
	int choice, ele;
	int del_ele;
	
	do{
		printf("1. insertrear 2. deleterear 3. insertfront 4. deleteFront 5. display 6. isFull 7. isEmpty 8.exit\nEnter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: if(isFull(&q))
						printf("q is full, cannot enter more elements\n");
					else
					{	printf("enter the element\n");
						scanf("%d", &ele);
						insertRear(&q,ele);
					}
					break;
			case 2: if(isEmpty(&q))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = deleteRear(&q);
						printf("deleted element is %d\n", del_ele);
					}
					break;
			case 3: if(isFull(&q))
					printf("q is full, cannot enter more elements\n");
					else
					{	printf("enter the element\n");
						scanf("%d", &ele);
						insertFront(&q,ele);
					}
					break;
			
			case 4: if(isEmpty(&q))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = deleteFront(&q);
						printf("deleted element is %d\n", del_ele);
					}
					break;
			case 5: display(&q);
					break;
			case 6: if(isFull(&q))
						printf("It is full\n");
					else
						printf("Not full\n");
					break;
			case 7:if(isEmpty(&q))
						printf("It is empty\n");
					else
						printf("Not Empty\n");
					break;
			default: printf("exit\n");
		}	
	}while(choice<8);
	return 0;
}

void initQ(QUE *q)
{
	q->front = q->rear = -1;
}

int isEmpty(QUE *q)
{
	return q->rear == -1;
}

int isFull(QUE* q)
{
	return (q->rear+1) % MAX == q->front;
}

void display(QUE* q)
{
	if(isEmpty(q))
		printf("empty, cannot display\n");
	else
	{
		int i;
		for(i = q->front; i  != q->rear; i = (i+1) % MAX)
			printf("%d\t", q->a[i]);
		printf("%d\n", q->a[i]);
	}
}

void insertRear(QUE *q,int ele)
{
	if(isEmpty(q))
	{
		q->front++;
		q->rear++;
		q->a[q->rear] = ele;
	}
	else
	{
		q->rear = (q->rear+1)%MAX;
		q->a[q->rear] = ele;
	}
}

void insertFront(QUE *q,int ele)
{
	if(isEmpty(q))
	{
		q->front++;
		q->rear++;
		q->a[q->front] = ele;
	}
	else
	{
		q->front = (q->front-1+MAX) % MAX;
		q->a[q->front] = ele;
	}
}

int deleteRear(QUE *q)
{
	int ele = q->a[q->rear];
	if(q->front == q->rear)
	{
		q->front = q->rear = -1;
		
	}
	else
	{
		q->rear = (q->rear-1+MAX) % MAX;
	}
	return ele;
}

int deleteFront(QUE *q)
{
	int ele = q->a[q->front];
	if(q->front == q->rear)
	{
		q->front = q->rear = -1;
		
	}
	else
	{
		q->front = (q->front+1)%MAX;
	}
	return ele;
}
