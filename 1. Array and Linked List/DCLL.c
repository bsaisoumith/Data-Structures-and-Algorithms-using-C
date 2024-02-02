#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node
{
	int info;
	struct node *prev;   // self referential structure
    struct node *next;
	
}NODE;

typedef struct list
{
	NODE *head;  // not self referential structure 
}CDLIST;

void init_list(CDLIST* cdli);
void insertatfront(CDLIST *cdli, int ele);
// void insertLast(DLIST *cdli, int ele);
// void insertatpos(DLIST* cdli,int ele,int pos);
void display(CDLIST* cdli);
NODE* getNode(int ele);


int main()
{
	CDLIST cdli;
	init_list(&cdli);  // or li.head = NULL  // head is always inside list its a pointer to structrue 
	printf("1. insert at front  2. insertatlast 3. insertat position 4. display 5. delfront 6:exit\n ");
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
				insertatfront(&cdli, ele);
                break;
			/* case 2: 
				 printf("enter the element:\n");
				 scanf("%d", &ele);
				 insertLast(&cdli, ele);
                break;
			case 3:
				 printf("enter the element and position:\n");
				 scanf("%d  %d", &ele, &pos);
				 insertatpos(&cdli,ele,pos);
					break; */
			case 4: display(&cdli);
                    break;
			case 5: // delfront(&li, &del_ele);
					// if(del_ele != -1)
					// 	printf("deleted element is %d\n", del_ele);
					break;
			default: printf("exiting from here\n");
		}
		
	}while(choice<=5);
	// destroylist(&li);
	init_list(&cdli);  // li->head = NULL;
	return 0;
}

void init_list(CDLIST* cdli)
{
	cdli->head = NULL;
}


void insertatfront(CDLIST *cdli, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->info = ele;
    if(cdli->head == NULL)
    {
        cdli->head = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else
    {
        cdli->head->prev = temp;
        temp->next = cdli->head;
        cdli->head->next = temp;
        cdli->head = temp;
        temp->prev = cdli->head->prev;
        
    }
}

void display(CDLIST* cdli)  
{
	NODE *p = cdli->head;
	if(p == NULL)
		printf("No nodes to display\n");
	else
	{
		while(p->next != cdli->head)
		{
			printf("%d\t",p->info);
			p = p->next;
		}
	}
    printf("\n");
}
