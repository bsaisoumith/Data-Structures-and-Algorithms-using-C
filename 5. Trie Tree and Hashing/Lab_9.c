// Implement collision handling using Separate chaining [insertion, deletion, search and display]

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 4

typedef struct Student
{
	int rno;
	char name[20];
	struct Student *link;
}ST;

void inittable(ST *s[]);
int insertrecord(ST *s[], int rollno, char *name);
int deleterecord(ST *s[], int rollno);
void display(ST *s[]);
int searchrecord(ST *s[], int rollno, char *name);

int main()
{
	ST *s[SIZE];
	inittable(s);
	int choice, rollno;
	char name[100];
	do
	{
		printf("1. insert 2. delete 3. search  4. display. Enter your choice:\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:printf("enter the rollno and name\n");
				scanf("%d%s", &rollno, name);
				if(insertrecord(s, rollno, name));
					printf("inserted to table successfully\n");
				break;
			case 2:printf("enter the rollno\n");
				scanf("%d", &rollno);
				if(deleterecord(s, rollno))
					printf("deleted record from table successfully\n");
				else
					printf("no nodes to delete\n");
				break;
			case 3:printf("enter the rollno\n");
				scanf("%d", &rollno);
				if(searchrecord(s, rollno, name))
					printf("Got record from table successfully. name is %s\n", name);
				else
					printf("search unsuccessful\n");
				break;
			case 4:display(s);
					break;
		}
	}while(choice<5);
	return 0;	
}

void inittable(ST *s[])
{
	for(int i = 0 ; i < SIZE; i++)
	{
		s[i] = NULL;
	}
}

int insertrecord(ST *s[], int rollno, char *name)
{
	int index = rollno % SIZE;
	ST *temp = malloc(sizeof(ST));
	if(temp == NULL)
	{
		return 0;
	}
	temp->rno = rollno;
	strcpy(temp->name, name);
	temp->link = NULL;
	if(s[index] == NULL)
		s[index] = temp;
	else
	{
		temp->link = s[index];
		s[index] = temp;
	}
	return 1;
}

void display(ST *s[])
{
	
	for(int i = 0 ; i < SIZE; i++)
	{
		if(s[i] == NULL)
			printf("S[%d]:NULL\n",i);
		else
		{
			printf("S[%d]:",i);
			ST *p = s[i];
			while(p!= NULL)
			{
				printf("%d %s ",p->rno, p->name);
				p = p->link;
			}
			printf("NULL\n");	
		}	
	}
}

int deleterecord(ST *s[], int rollno)
{
	int index = rollno % SIZE;
	if(s[index] == NULL)
		return  0;
	ST *p = s[index];
	ST *q = NULL;
	while(p != NULL && p->rno != rollno)
	{
		q = p;
		p = p->link;
	}
	if(p != NULL)
	{
		
		if(q != NULL)
		{
			q->link = p->link;
			free(p);
		}
		else{
			
			s[index] = p->link;
			free(p);
		}
		return 1;
	}
}

int searchrecord(ST *s[], int rollno, char *name)
{
	int index = rollno % SIZE;
	if(s[index] == NULL)
	{
		return  0;
	}	
	ST *p = s[index];
	while(p != NULL && p->rno != rollno)
	{
		p = p->link;
	}
	if(p != NULL)
	{
		if(p->rno == rollno)
		{
			strcpy(name,p->name);			
		}
		return 1;
	}
	/* while(p != NULL)
	{
		if(p->rno == rollno)
			strcpy(name,p->name);	
		p = p->link;
		return 1;
	} */
	
}



