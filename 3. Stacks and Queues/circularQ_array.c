#include<stdio.h>
#define MAX 5

typedef struct Queue
{
	int a[MAX];
	int front, rear;
}QUE;

void initQ(QUE *pq);
void display(QUE *pq);
int isEmpty(QUE *pq);
int isFull(QUE *pq);
void enqueue(QUE *pq, int ele);
int dequeue(QUE *pq);

int main()
{
	QUE q;
	initQ(&q);
	int choice, ele;
	int del_ele;
	
	do{
		printf("1. enqueue 2. dequeue 3. display 4. isFull 5. isEmpty 6. exit\n Enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: if(isFull(&q))
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

void initQ(QUE *pq)
{
    pq->rear = pq->front = MAX - 1;
}

void display(QUE *pq)
{
    if(isEmpty(pq))
        printf("Q is empty\n");
    else
    {
        for(int i = (pq->front+1) % MAX; i <= pq->rear; i++)
        {
           printf("%d\t",pq->a[i]); 
        }
    }
    printf("\n");
}

int isEmpty(QUE *pq)
{
    return pq->front == pq->rear;
}

int isFull(QUE *pq)
{
    // return pq->rear == MAX - 2;        // problematic statement
    return (pq->rear+1) ==  pq->front;
}

void enqueue(QUE *pq, int ele)
{
    pq->rear = (pq->rear+1) % MAX;
    pq->a[pq->rear] = ele;
}

int dequeue(QUE *pq)
{
    pq->front = (pq->front+1) % MAX;
    int d = pq->a[pq->front];
    return d;
}
