// modify to delete the second element as well
// abstract data type says implementation of queue using linked list should contain two pointers

// In this case if u delete one element from the fully filled queue, after deleting it we cannot insert new element 

#include<stdio.h>
#define MAX 3

typedef struct Queue
{
	int a[MAX];
	int front, rear;
}QUE;

void display(QUE *pq);
int isEmpty(QUE *pq);
int isFull(QUE *pq);
void enqueue(QUE *pq, int ele);
void initQ(QUE *pq);
int dequeue(QUE *pq);

int main()
{
	QUE q;
	initQ(&q);
	int choice, ele;
	int del_ele;
	
	do{
		printf("1. enqueue 2. dequeue 3. display 4. isFull 5. isEmpty 6. exit\n enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:if(isFull(&q))
						printf("q is full, cannot enter more elements\n");
					else
					{
						printf("enter the element\n");
						scanf("%d", &ele);
						enqueue(&q,ele);
					}
					break;
			case 2: if(isEmpty(&q))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = dequeue(&q);
						printf("deleted element is %d\n", del_ele);
					}
					break;
			case 3: display(&q);
					break;	
			case 4: if(isFull(&q))
						printf("q is full \n");
					else
						printf("q is not full\n");
					break;
			case 5: if(isEmpty(&q))
						printf("q is empty \n");
					else
						printf("q is not empty\n");
					break;
		}
	}while(choice<6);
	return 0;
}

int dequeue(QUE *pq)
{
	
	int a = pq->a[pq->front];
	pq->front++;

	/* if(pq->front == pq->rear)   // check this condition, it will try to replace the value without knowing to the client
	{
		pq->rear = -1;
		pq->front = 0;
	}	 */

	if(pq->front > pq->rear)   
	{
		pq->rear = -1;           // we can call init function
		pq->front = 0;		  
	}
	return a;
}

int isEmpty(QUE *pq)
{
	//return pq->rear == -1;
	return pq->front > pq->rear;
}

void initQ(QUE *pq)
{
	pq->front = 0;
	pq->rear = -1;
}

void enqueue(QUE *pq, int ele)
{	
		pq->rear++;
		pq->a[pq->rear] = ele;
}

int isFull(QUE *pq)
{
	return pq->rear == MAX-1;
}

void display(QUE *pq)
{
	if(isEmpty(pq))
		printf("no elements to display\n");
	else
	{
		printf("elements in the queue are\n");
		for(int i = pq->front; i <= pq->rear;i++)
		{
			printf("%d\t", pq->a[i]);
		}
		printf("\n");
	}
}