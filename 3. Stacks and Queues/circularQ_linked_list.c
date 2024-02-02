#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

typedef struct QUEUE
{
    NODE *front;
    NODE *rear;
}QUE;

void display(QUE *pq);
int isEmpty(QUE *pq);
void enqueue(QUE *pq,int ele);
int dequeue(QUE *pq);
void initQ(QUE *pq);

int main()
{
    QUE q;
	initQ(&q);
	int choice, ele;
	int del_ele;
    do{
		printf("1. enqueue 2. dequeue 3. display 4. isEmpty 5. exit\n enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
					printf("enter the element\n");
					scanf("%d", &ele);
					enqueue(&q,ele);
					break;
			case 2: if(isEmpty(&q))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = dequeue(&q);
						printf("deleted element is %d\n", del_ele);
					}
					break;
			case 3:if(isEmpty(&q))
                    {
                        printf("No nodes to display\n");
                    }
                    else
                    {
                        display(&q);
                    }
					break;	
			case 4: if(isEmpty(&q))
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
    pq-> front = pq->rear = NULL;
}

int isEmpty(QUE *pq)
{
    return pq->rear == NULL;
}

void enqueue(QUE *pq,int ele)
{
    NODE *temp =(NODE*)malloc(sizeof(NODE));
    temp->info = ele;
    temp->next = temp;
    if(isEmpty(pq))
    {
        pq->rear = pq->front = temp;
    }
    else
    {
        pq->rear->next = temp;
        pq->rear = temp;
        pq->rear->next = pq->front;
    }
}

int dequeue(QUE *pq)
{
    int d = pq->front->info;
    if(pq->rear == pq->front)
    {
        free(pq->rear);
        initQ(pq);
    }
    else
    {
        NODE *p = pq->front;
        pq->front = p->next;   // pq->front = pq->front->next
        pq->rear->next = pq->front;
        free(p);
    }
    return d;
}

void display(QUE *pq)
{
    NODE *p = pq->front;
    while(p->next != pq->front)
    {
        printf("%d\t",p->info);
        p = p->next;
    }
    printf("%d",p->info);
    printf("\n");
}


