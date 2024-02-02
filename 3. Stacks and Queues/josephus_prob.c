#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

typedef struct Queue
{
    NODE *front;
    NODE *rear;
}QUE;

void initQ(QUE *q);
void create(QUE *q);
void display(QUE *q);
int winner(QUE *q, int start, int skip);

int main()
{
    QUE q;
    initQ(&q);
    create(&q);
    display(&q);
    int start,skip;
    printf("Enter the start and skip values:\n");
    scanf("%d%d",&start,&skip);
    printf("Winner is %d\n",winner(&q,start,skip));
    return 0;
}

int winner(QUE *pq, int start, int skip)
{
    int count = 1;
    NODE *p = pq->front;
    NODE *q = pq->rear;         // if we not initialize q to pq->rear when start and skip is 1 and it will be dangling till next while loop where code crashes for q->next

    while(count != start)
    {
        q = p;
        p = p->next;
        count++;
    }

    while(p != p->next)     // There is only one node
    {
        for(int i = 1; i != skip; i++)
        {
            q = p;
            p = p->next;
        }
        printf("%d killed\n",p->info);
        q->next = p->next;
        free(p);
        p = q->next;
    }
    return p->info;
}

void initQ(QUE *q)
{
    q->front = q->rear = NULL;
}

void create(QUE *q)
{
    int n;
    int i = 1;
    printf("How many nodes u want to enter to circle:\n");
    scanf("%d",&n);
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->info = 1;
    temp->next = temp;
    q->front = q->rear = temp;
    for(i=2; i<= n; i++)
    {
        temp = (NODE*)malloc(sizeof(NODE));
        temp->info = i;
        temp->next = q->front;
        q->rear->next = temp;
        q->rear = temp;
    }
}

void display(QUE *q)
{
    NODE *p = q->front;
    do    
    {
        printf("%d\t",p->info);
        p = p->next;
    }while(p != q->front);
    printf("\n");
}



