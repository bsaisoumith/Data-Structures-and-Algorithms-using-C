// merge two ordered lists and display the merged list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *prev;   // self referential structure
    struct node *next;
	
}NODE;

typedef struct list_1
{
	NODE *head;             // not self referential structure 
}DLIST_1;

typedef struct list_2
{
    NODE *head;             // not self referential structure 
}DLIST_2;


void init_list(DLIST_1* dli_1,DLIST_2* dli_2);
void insert_1(DLIST_1 *dli_1, int ele);
void insert_2(DLIST_2 *dli_2, int ele);
NODE* getNode(int ele);
void display(DLIST_1* dli_1,DLIST_2* dli_2);
void merge(DLIST_1* dli_1,DLIST_2* dli_2);
void sort(DLIST_1* dli_1);
void Display(DLIST_1* dli_1);

int main()
{
    DLIST_1 dli_1;
    DLIST_2 dli_2;
	init_list(&dli_1,&dli_2);

    insert_1(&dli_1, 7);
    insert_1(&dli_1, 17);
    insert_1(&dli_1, 23);
    insert_1(&dli_1, 73);
    insert_1(&dli_1, 94);
    
    insert_2(&dli_2, 6);
    insert_2(&dli_2, 80);
    insert_2(&dli_2, 45);

    display(&dli_1,&dli_2);
    merge(&dli_1,&dli_2);
    printf("The elements after merging both the list are: \n");
    Display(&dli_1);
    sort(&dli_1);
    printf("The newly ordered list is: \n");
    Display(&dli_1);
    return 0;
}

void init_list(DLIST_1* dli_1,DLIST_2* dli_2)
{
	dli_1->head = NULL;
    dli_2->head = NULL;
}

NODE* getNode(int ele)
{
    NODE* temp = malloc(sizeof(NODE));
    temp->info = ele;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert_1(DLIST_1 *dli_1, int ele)
{
    NODE *temp = getNode(ele);
    NODE *p = dli_1->head;
    if(p == NULL)
    {
        temp->next = p;
        dli_1->head = temp;
    }
    else
    {
        while(p->next != NULL )
        {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
    }
}

void insert_2(DLIST_2 *dli_2, int ele)
{
    NODE *temp = getNode(ele);
    NODE *p = dli_2->head;
    if(p == NULL)
    {
        temp->next = p;
        dli_2->head = temp;
    }
    else
    {
        while(p->next != NULL )
        {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
    }
}

void display(DLIST_1* dli_1,DLIST_2* dli_2)
{
    NODE *p = dli_1->head;
    printf("The elements in the first list are: \n");
	while(p != NULL)
	{
		printf("%d\t",p->info);
		p = p->next;
	}
    printf("\n");

    NODE *q = dli_2->head;
    printf("The elements in the second list are: \n");
	while(q != NULL)
	{
		printf("%d\t",q->info);
		q = q->next;
	}
    printf("\n");
}

void merge(DLIST_1* dli_1,DLIST_2* dli_2)
{
    NODE *p = dli_1->head;
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    dli_2->head->prev = p;
    p->next = dli_2->head;
}

void sort(DLIST_1* dli_1)
{
    NODE *p = NULL;
    NODE *q = NULL;
    int temp;
    
    for(p = dli_1->head; p->next != NULL; p = p->next)
    {
        for(q = p->next; q != NULL; q = q->next)
        {
            if(p->info > q->info)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
        }
    }
}

void Display(DLIST_1* dli_1)
{
    NODE *p = dli_1->head;
	while(p != NULL)
	{
		printf("%d\t",p->info);
		p = p->next;
	}
    printf("\n");
}