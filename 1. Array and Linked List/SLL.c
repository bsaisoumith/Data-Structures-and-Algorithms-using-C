//implementation of List using linkedlist


typedef struct node
{
	int info;
	struct node *link;   // self referential structure
	
}NODE;

typedef struct list
{
	NODE *head;  // not self referential structure 
}LIST;

void init_list(LIST* li);
void insertatfront(LIST* li, int ele);
void display(LIST* li);
void insertLast(LIST *li, int ele);
void insertatpos(LIST* li,int ele,int pos);
void delfront(LIST *li, int *p_del_ele);
void deletefromLast(LIST *li, int *p_dele_ele);
void deletefrompos(LIST *li, int *p_dele_elem,int posi);
void deletealternate(LIST *li);
int search(LIST* li,int ele);
void reverseorder(LIST *li);
void sort(LIST *li);

#include<stdio.h>
#include<stdlib.h>

int main()
{
	LIST li;
	init_list(&li); // passing address of li
	printf("1. insert at front  2. insert at last 3. insert at position 4. display 5. delete front 6. delete last \n 7. delete at position 8.delete alternate 9. search key 10. reverse order 11.sort 12. exit\n");
	int choice;
	int ele, pos, del_ele, dele_ele,dele_elem,elem,posi;
	do{
		printf("enter your choice:\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("enter the element:\n");
					scanf("%d", &ele);
					insertatfront(&li, ele);
					break;
			case 2: printf("enter the element:\n");
					scanf("%d", &ele);
					insertLast(&li, ele);
					break;
			case 3:	printf("enter the element and position:\n");
					scanf("%d  %d", &ele, &pos);
					insertatpos(&li,ele,pos);
					break;
			case 4: display(&li);
					break;
			case 5: delfront(&li, &del_ele);
					if(del_ele != -1)
						printf("deleted element is %d\n", del_ele);
					break;
			case 6: deletefromLast(&li,&dele_ele);
					if(dele_ele != -1)
						printf("deleted element is %d\n", dele_ele);
					break;
			case 7: printf("enter the position:\n");
					scanf("%d",&posi);
					deletefrompos(&li,&dele_elem,posi);
				 	if(dele_elem != -1)
						printf("deleted element is %d\n", dele_elem);
					break;
			case 8:	deletealternate(&li);
					break;
			case 9: printf("enter the element:\n");
					scanf("%d", &ele);
					int key = search(&li,ele);
					if(key == -1)
						printf("NO key found in the list\n"); 
					else
						printf("The key %d found at position %d\n",ele,key + 1);
					break;
			case 10: reverseorder(&li);
					 break;
			case 11: sort(&li);
					 break;
			default: printf("exiting from here\n");
		}
	}while(choice<=12);
	// destroylist(&li);
	init_list(&li);  // li->head = NULL
	return 0;
}

void init_list(LIST* li)
{
	li->head = NULL;
}

void insertatfront(LIST* li, int ele)
{
	NODE*temp = (NODE*)malloc(sizeof(NODE));
	temp->info = ele;
	//temp->link = NULL;
	
	temp->link = li->head;
	li->head = temp;
}

void insertLast(LIST *li, int ele)
{
	NODE*temp = (NODE*)malloc(sizeof(NODE));
	temp->info = ele;
	temp->link = NULL;
	NODE *p = li->head;
	if(p == NULL)
		li->head = temp;
	else
	{
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

void insertatpos(LIST* li,int ele,int pos)
{
	NODE*temp = (NODE*)malloc(sizeof(NODE));
	temp->info = ele;
	temp->link = NULL;
	NODE *p = li->head;
	NODE *q;
	if(pos == 0)
	{
		temp->link = p;
		li->head = temp;
	}
	else
	{
		for(int i = 0; i<pos;i++ )
		{
			q = p;
			p = p->link;
		}
		q->link = temp;
		temp->link = p;
	}
    printf("%d %d\n",q->info,p->info);
}

void display(LIST* li)
{
	NODE *p = li->head;
	if(p == NULL)
		printf("No nodes to display\n");
	else
	{
		while(p != NULL)
		{
			printf("%d\t",p->info);
			p = p->link;
		}
	}
    printf("\n");
}

void delfront(LIST *li, int *p_del_ele)
{
	NODE *p = li->head;
	if(p == NULL)
	{	printf("No nodes to delete\n");
		*p_del_ele = -1;
		return ;
	}
	li->head = p->link;
	*p_del_ele = p->info;
	free(p);
}


void deletefromLast(LIST *li, int *p_dele_ele)
{
	NODE *p = li->head;
	NODE *q;
	if(p == NULL)
	{	printf("No nodes to delete\n");
		*p_dele_ele = -1;
		return ;
	}

	else if(p->link == NULL)
	{
		*p_dele_ele = p->info;
		li->head = NULL;
		free(p);
	}
	
	else
	{
		while(p->link != NULL)
		{
			q=p;
		 	p=p->link;
		}
		// printf("%d %d\n",p->info,q->info);
		*p_dele_ele = p->info;
		q->link = NULL;
		free(p);
	}

}

/* void deletefrompos(LIST *li, int *p_dele_elem,int posi)
{
	NODE *p = li->head;
	NODE *q;
	if(p == NULL)
	{	
		printf("No nodes to delete\n");
		*p_dele_elem = -1;
		return ;
	}
	else if(posi=0)
	{
		li->head = p->link;
		*p_dele_elem = p->info;
		free(p);
	}
	else
	{
		for(int i = 0; i<posi;i++ )
		{
			q = p;
			p = p->link;
		}
		q->link=p->link;
		printf("%d %d\n",p->info,q->info);
		*p_dele_elem = p->info;
		free(p); 

		while(i<posi-1)
		{
			p=p->link;
			printf("%d %d\n",p->info,q->info);
			i++;
		}
		q=p->link;
		p->link = q->link;
		printf("%d %d\n",p->info,q->info);
		*p_dele_elem = p->info;
		free(p); 
	}
} */

void deletefrompos(LIST *li, int *p_dele_elem,int posi)
{
	NODE *p = li->head;
	NODE *s = li->head;
	NODE *q;
	int i=0;
	int count=0;

	while(s->link != NULL)
	{
		s = s->link;
		count++;
	}

	if(count < posi)
	{
		printf("the position is out of bound\n");
		*p_dele_elem = -1;
		return ;
	}

	else if(posi == 0 && p == NULL)
	{
		printf("no nodes are there to delete\n");
		*p_dele_elem = -1;
		return ;
	}
	/* else if(posi == 0 && p->link == NULL)
	{
		li->head == p->link;
		*p_dele_elem = p->info;
		free(p);
	} */
	else if(posi == 0)
	{
		*p_dele_elem = p->info;   // li->head->info
		li->head = li->head->link;   // p->link
		free(p);
	}
	else
	{	
		for(int i = 0; i<posi;i++ )
		{
			q = p;
			p = p->link;
		}
		q->link = p->link;
		// printf("%d %d\n",p->info,q->info);
		*p_dele_elem = p->info;
		free(p);
	}
}

void deletealternate(LIST *li)
{
	NODE *p = li->head;
	NODE *q = li->head->link;
	if(p == NULL)
	{	printf("No nodes to delete\n");
		return ;
	}
	else if(p->link == NULL)
	{
		printf("There is only single node\n");
	}
	else
	{
		while(p != NULL && p->link != NULL)
		{
			p->link = q->link;
			printf("The deleted elements is: %d\n",q->info);
			free(q);
			p = p->link;
			if(p != NULL)
				q = p->link;
		}
	}
}

int search(LIST* li,int ele)
{
	NODE *p = li->head;
	int pos = 0;
	if(p == NULL)
	{
		printf("List is empty\n");
		return -1;	
	}
	else
	{
		while(p != NULL)
		{
			if(p->info == ele)
			{
				return pos;
			}
		p = p->link;
		pos++;
		}
		return -1;	
	}
}

void reverseorder(LIST *li)
{
	NODE* prev, *cur, *next;
	prev = NULL;
	cur = next = li->head;
	if(next == NULL)
	{
		printf("There are No nodes\n");
	}
		
	else
	{
		while(next != NULL)
		{
			next = next->link;
			cur->link = prev;
			prev = cur;
			cur = next;
		}
	}
	li->head = prev;
}

void sort(LIST *li)
{
	NODE *p = NULL;
	NODE *q = NULL;
	int temp;
	if(li->head == NULL)
	{
		printf("No nodes to swap\n");
	}
	else
	{
		for(p = li->head; p->link != NULL; p = p->link)
		{
			for(q = p->link; q != NULL; q = q->link)
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
}



// # write a function definition to deletefromLast(), deletefrompos() and deletefromaltposition()
// # also add a function search for a key in the list
// #also add a function to display the list in the reverse order



