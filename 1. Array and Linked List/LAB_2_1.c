// To create an orderly doubly linked list and search for the given information

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
	NODE *head;         // not self referential structure 
}DLIST;


void init_list(DLIST* dli);
void insert(DLIST *dli, int ele);
NODE* getNode(int ele);
void display(DLIST* dli);
void sort(DLIST* dli);
int search(DLIST* dli,int ele);

int main()
{
    DLIST dli;
    init_list(&dli);
    int n;
    printf("How many elements do u want to store:\n");
    scanf("%d",&n);
    int ele;
    for(int i=0;i<n;i++)
    {
        printf("enter the element:\n");
	    scanf("%d", &ele);
	    insert(&dli, ele); 
    }

    printf("The elements in the given list which are not sorted:\n");
    display(&dli);
    sort(&dli);
    printf("The elements in the given list which are sorted:\n");
    display(&dli);

    int a;
    do
    {   printf("Do u want to know the position of elements in new list[yes = 0/No = 1]:\n");
        scanf("%d",&a);
        if(a == 0)
        {
            printf("Enter the element that u want find the position: \n");
            scanf("%c",&ele);
            int key = search(&dli,ele);
		    if(key == -1)
			    printf("NO element found in the list\n"); 
		    else
			    printf("The element %d found at position %d\n",ele,key);
        }
    }while (a < 1);

    /* char a; 
    do
    {   printf("Do u want to know the position of elements in new list:");
        a = getchar();
        if(a == 'y')
        {
            printf("Enter the element that u want find the position:\n");
            scanf("%d",&ele);
            int key = search(&dli,ele);
		    if(key == -1)
			    printf("NO element found in the list\n"); 
		    else
			    printf("The element %d found at position %d\n",ele,key);
        }
    }while (a != 'n'); */
    return 0;
}

void init_list(DLIST* dli)
{
	dli->head = NULL;
}

void insert(DLIST *dli, int ele)
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
        while(p->next != NULL )
        {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
    }
}

NODE* getNode(int ele)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = ele;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void display(DLIST* dli)
{
	NODE *p = dli->head;
	while(p != NULL)
	{
		printf("%d\t",p->info);
		p = p->next;
	}
    printf("\n");
}

void sort(DLIST* dli)
{
    NODE *p = NULL;
    NODE *q = NULL;
    int temp; 
    
    for(p = dli->head; p->next != NULL; p = p->next)
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

int search(DLIST* dli,int ele)
{
    NODE *p = dli->head;
    int pos = 0;
    while(p != NULL)
    {
        if(p->info == ele)
        {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

