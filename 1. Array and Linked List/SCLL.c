#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int info;
	struct node *link;   // self referential structure
	
}NODE;

/* typedef struct list
{
	NODE *head;        // not self referential structure 
}CLIST;
 */

typedef struct list
{
	NODE *last;        // not self referential structure 
}CLIST;


void init_list(CLIST* cli);
void insertatfront(CLIST* cli, int ele);
void display(CLIST* cli);

int main()
{
    CLIST cli;
	init_list(&cli);     // passing address of cli
    int choice;
    printf("1. insert at front  2. insertatlast 3. insertat position 4. display 5. delfront 6:exit\n ");
    int ele, pos, del_ele, dele_ele,dele_elem,elem,posi;
    do{
		printf("enter your choice:\n");
		scanf("%d", &choice);
    
		switch(choice)
		{
			case 1:
				printf("enter the element:\n");
				scanf("%d", &ele);
				insertatfront(&cli, ele);break;
            case 4: display(&cli); break;
            default: printf("exiting from here\n");
		}}while(choice<=12);
        init_list(&cli);  // li->head = NULL;
	return 0;
}

/* void init_list(CLIST* cli)
{
	cli->head = NULL;
}

void insertatfront(CLIST* cli, int ele)
{
	NODE*temp = (NODE*)malloc(sizeof(NODE));
	temp->info=ele;
    if(cli->head == NULL)
    {
        cli->head = temp;
        temp->link = cli->head; // temp->link = temp;
    }
    else
    {
        NODE *p= cli->head;
        temp->link = cli->head;
        while(p->link != cli->head)
        {
            p=p->link;
        }
        p->link = cli->head; // p->link = temp;
        cli->head = temp; 
    }
}

void display(CLIST* cli)
{
	NODE *p = cli->head;
	if(p == NULL)
		printf("No nodes to display\n");
	else
	{
		while(p->link = cli->head)
		{
			printf("%d\t",p->info);
			p = p->link;
		}
	}
    printf("%d\t",p->link);
    printf("\n");
} */

void init_list(CLIST* cli)
{
	cli->last = NULL;
}

void insertatfront(CLIST* cli, int ele)
{
	NODE*temp = (NODE*)malloc(sizeof(NODE));
	temp->info=ele;
    if(cli->last == NULL)
    {
        temp->link = temp;
        cli->last = temp;
        temp->link = cli->last; // temp->link = temp;
    }
    else
    {
        temp->link = temp;
        cli->last->link = temp; 
    }
}

void display(CLIST* cli)
{
	if(cli->last->link == NULL)
		printf("No nodes to display\n");
	else
	{
        NODE *p = cli->last->link;
		while(p->link != cli->last)
		{
			printf("%d\t",p->info);
			p = p->link;
		}
        printf("%d\t",p->info);   
	}
    printf("\n");
}


// insert at front , insert at last, delete at front, delete at last




