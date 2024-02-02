#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *prev;   // self referential structure
    struct node *next;	
}NODE;

typedef struct list
{
	NODE *head;  // not self referential structure 
}DLIST;

void init_list(DLIST* dli);
void insertatfront(DLIST *dli, int ele);
void insertLast(DLIST *dli, int ele);
void insertatpos(DLIST* dli,int ele,int pos);
void display(DLIST* dli);
NODE* getNode(int ele);
void delfront(DLIST *dli,int *del_ele);
void delback(DLIST* dli, int *del_ele);
void deletefrompos(DLIST* dli,int *del_ele,int pos);
void deletealternate(DLIST* dli);
void reverseorder(DLIST *dli);


int main()
{
	DLIST dli;
	init_list(&dli);  // or li.head = NULL  // head is always inside list its a pointer to structrue 
	printf("1. insert at front  2. insertatlast 3. insertat position 4. display 5. delfront 6. delete at last \n 7. Delete at position 8. Delete at alternate 9. Reverse order 10. exit\n ");
	int choice;
	int ele, pos, del_ele;
	do{
		printf("enter your choice:\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("enter the element:\n");
				scanf("%d", &ele);
				insertatfront(&dli, ele);
                break;
			case 2: 
				 printf("enter the element:\n");
				 scanf("%d", &ele);
				 insertLast(&dli, ele);
                break;
			case 3:
				 printf("enter the element and position:\n");
				 scanf("%d  %d", &ele, &pos);
				 insertatpos(&dli,ele,pos);
					break;
			case 4: display(&dli);
                    break;
			case 5: delfront(&dli, &del_ele);
				    if(del_ele != -1)
					    printf("deleted element is %d\n", del_ele);
					break;
            case 6: delback(&dli, &del_ele);
                    if(del_ele != -1)
					    printf("deleted element is %d\n", del_ele);
					break;
            case 7: 
                    printf("enter the position:\n");
					scanf("%d",&pos);
                    deletefrompos(&dli,&del_ele,pos);
                    if(del_ele != -1)
						printf("deleted element is %d\n", del_ele);
					break;
			case 8:
					deletealternate(&dli);
					break;
			case 9:
					reverseorder(&dli);
					break;
			default: printf("exiting from here\n");
		}
	}while(choice<=13);
	// destroylist(&li);
	init_list(&dli);  // li->head = NULL;
	return 0;
}

void init_list(DLIST* dli)
{
	dli->head = NULL;
}

NODE* getNode(int ele)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    // int *p =  malloc(sizeof(int)); *p=7;
    temp->info = ele;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertatfront(DLIST *dli, int ele)
{
    NODE *temp = getNode(ele);
    NODE *p = dli->head;
    if(p == NULL)
    {
        temp->next = p;
        dli->head = temp;
    }
    else
    {
        temp->next = p;
        dli->head = temp;
        temp->next->prev = temp;
    }
}

void insertLast(DLIST *dli, int ele)
{
    NODE* temp = getNode(ele);
    NODE* p = dli->head;
    if( p == NULL)
    {
        dli->head = temp;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    
}

void insertatpos(DLIST* dli,int ele,int pos)
{
    NODE *temp = getNode(ele);
    NODE *p = dli->head;
    if( p == NULL)
    {
        dli->head = temp;
    }
    else if(pos == 0)
    {
        temp->next = p;
        dli->head = temp;
        p->prev = temp;
    }
    else
    {
        for(int i = 0; i<pos; i++)
        {
            p = p->next;
        }
        p->prev->next=temp;
        temp->next=p;
        temp->prev=p->prev;
        p->prev=temp;
    }
    printf("%d\n",p->info);
}

void display(DLIST* dli)
{
	NODE *p = dli->head;
	if(p == NULL)
		printf("No nodes to display\n");
	else
	{
		while(p != NULL)
		{
			printf("%d\t",p->info);
			p = p->next;
		}
	}
    printf("\n");
}

void delfront(DLIST* dli,int *del_ele)
{
    NODE *p = dli->head;
    if(p == NULL)
	{	printf("No nodes to delete\n");
		*del_ele = -1;
		return ;
	}
    dli->head = p->next;
    *del_ele = p->info;
    dli->head->prev == NULL;
    free(p);
}

void delback(DLIST* dli, int *del_ele)
{
    NODE *p = dli->head;
    if(p == NULL)
	{	printf("No nodes to delete\n");
		*del_ele = -1;
        return ;
	}
    else if(p->next == NULL)
	{
		*del_ele = p->info;
		dli->head = NULL;
		free(p);
	}
    else
	{
		while(p->next != NULL)
		{
		 	p=p->next;
		}
		// printf("%d %d\n",p->info);
		*del_ele = p->info;
		p->prev->next = NULL;
        p->prev = NULL;
		free(p);
	}
}

void deletefrompos(DLIST* dli,int *del_ele,int pos)
{
    NODE *p = dli->head;
	NODE *s = dli->head;
	int i=0;
	int count=0;
    while(s->next != NULL)
	{
		s = s->next;
		count++;
	}
    if(count < pos)
	{
		printf("the position is out of bound\n");
		*del_ele = -1;
		return ;
	}
    else if(pos == 0 && p == NULL)
	{
		printf("no nodes are there to delete\n");
		*del_ele = -1;
		return ;
	}
    else if(pos == 0)
	{
		if(p->next == NULL)
		{
			*del_ele = p->info;
        	dli->head == NULL;
			printf("%d",dli->head->info);
			free(p);
		}
		else
		{
			*del_ele = p->info;
			dli->head = p->next;
        	dli->head->prev = NULL;
			printf("%d",dli->head->info);
			free(p);
		}
	}
    else
	{	
		for(int i = 0; i<pos;i++ )
		{
			p = p->next;
		}
		// printf("%d %d\n",p->info);
		*del_ele = p->info;
		p->prev->next = p->next;
		if(p->next != NULL)
			p->next->prev = p->prev;
		free(p);
	}
}

void deletealternate(DLIST* dli)
{
	NODE *p = dli->head;
	NODE *q = dli->head->next;

	if(p == NULL)
	{
		printf("No nodes to delete\n");
		return ;
	}
	else if(p->next == NULL)
	{
		printf("There is only single node\n");
	}
	else
	{
		while(p != NULL && p->next != NULL)
		{
			p->next = q->next;
			printf("The deleted elements is: %d\n",q->info);
			p = p->next;
			if(p != NULL)
			{
				p->prev = q->prev;
				free(q);
				q = p->next;
			}
			else
		    	free(q);
		}
	}
}

void reverseorder(DLIST *dli) 
{
	NODE* prev, *cur, *nxt;
	prev = NULL;
	cur = nxt = dli->head;
	if(nxt == NULL)
	{
		printf("There are No nodes\n");
	}
	else
	{
		while(nxt != NULL)
		{
			nxt = nxt->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
			prev->prev = cur; 
		}
	}
	dli->head = prev;
}














// To create an orderes doubly linked list and search for the given information
// merge two ordered lists and display the merged list