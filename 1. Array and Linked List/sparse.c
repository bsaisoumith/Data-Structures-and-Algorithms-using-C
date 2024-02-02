#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int value, col;
	struct node *link;
}NODE;

typedef struct List
{
	struct List *down;
	NODE *head;
	NODE *right;
}MLIST;

void init_list(MLIST **pli);
void createList(MLIST **pli);
void displayList(MLIST **pli);

int main()
{
	MLIST *li;
	init_list(&li);
	createList(&li);
	displayList(&li);
	
}

void init_list(MLIST **pli)
{
	*pli = NULL;
}

void createList(MLIST **pli)
{
	int row = 0;
	MLIST *p;
	int choice;
	do
	{
	   // printf("do u like to add a row?\n");
		
		//scanf("%d", &choice);	  // this is added to the end of the loop. because even if user says 0 or no, one row is at least getting created.
		// please note this.
		MLIST *temp = malloc(sizeof(MLIST));
		temp->right = NULL;
		temp->head = NULL;
		temp->down = NULL;
		if(*pli == NULL)
		{
			*pli = temp;
			p = temp;
		}
		else
		{
			p->down = temp;
			p = temp;
		}
		printf("do u like to add a row %d?\n", ++row);
		scanf("%d", &choice);
	}while(choice);

	row = 0;
	p = *pli;
	while(p != NULL)
 	{
		printf("do u want to add entry to row %d", row);
		scanf("%d", &choice);
		if(choice)
		{
			do{
				NODE *temp = malloc(sizeof(NODE));
				temp->link = NULL;
				printf("enter column and value\n");
				scanf("%d%d",&(temp->col), &(temp->value));
				if(p->head == NULL)
				{
					p->right = p->head = temp;
				}
				else
				{
					p->right->link = temp;
					p->right = temp;
				}
			    printf("do u like to add more entries to the same row?");
		        scanf("%d", &choice);
		    }while(choice);
	    }
		row++;
		p = p->down;	 
	}	
}

void displayList(MLIST **pli)
{
	MLIST *p = *pli;
	int row = 0;
	while(p != NULL)
	{
		NODE *q = p->head;
		while( q != NULL)
		{
			printf("row = %d col = %d values = %d\n", row,q->col,q->value);
			q = q->link;	
		}
		row++;
		p = p->down;
	}
}