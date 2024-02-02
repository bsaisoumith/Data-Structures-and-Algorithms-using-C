#include<stdio.h>
#include<string.h>

// linear probing  vvimp
// Same roll number- delete is not fine in this code. please add more conditions.
// if roll numbers are resulting in same hash value, then this code works fine.

typedef struct Student
{
	int rno;
	char name[100];
	int mark;
}ST;

#define SIZE 4

void display(ST st[], int n);
void inittable(ST st[]);
int inserttotable(ST st[],int rno,char name[], int *n);
int deletefromtable(ST st[],int rollno, int *n);
int searchintable(ST st[],int rollno, int n, char name[]);

int main()
{
	ST st[SIZE];
	int n = 0;
	inittable(st);
	int choice, rollno;
	int ch;
	char name[100];
	do
	{
		printf("1. insert 2, delete 3 search 4. display\n enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("enter the rno and name\n");
					scanf("%d%s",&rollno, name);
					if(!inserttotable(st,rollno,name, &n))
						printf("table is full\n");
					else
						printf("data inserted to table\n");
			
					break;
			case 2: printf("enter the rno");
					scanf("%d",&rollno);
					if(!deletefromtable(st,rollno, &n))
						printf("nothong to delete\n");
					else
						printf("data deleted from the table\n");
					break;
			case 3: printf("enter the rno");
					scanf("%d",&rollno);
					if(!searchintable(st,rollno,n, name))
						printf("no elements to search/rollnumber not available\n");
					else
						printf("name is %s\n", name);
					break;
			case 4: display(st,n);break;
		}
		printf("do u like to continue? press 1\n");
		scanf("%d", &ch);
	}while(ch);
	return 0;
}

void inittable(ST st[])
{
	for(int i = 0 ; i < SIZE; i++)
	{
		st[i].mark = -1;
	}
}

int inserttotable(ST st[],int rno,char name[], int *n)
{
	if((*n) == SIZE)
	{
			return 0;
	}
	int index = rno % SIZE;              // if rno is 7. value of index is 3 because size is 4
	while(st[index].mark != -1)
	{
		index = (index+1) % SIZE;
	}
	st[index].rno = rno;
//	st[index].name = name;  // error
	strcpy(st[index].name,name);
	st[index].mark = 1;
	(*n)++;
	return 1;
}

void display(ST st[],int n)
{
	if(n == 0)
		printf("no student data available in the hash table\n");
	else
	{
		for(int i = 0 ; i < SIZE; i++)
		{
			if(st[i].mark == 1)
			{
				printf("%d %s\n", st[i].rno, st[i].name);
			}		
		}
	}
}

int deletefromtable(ST st[],int rollno, int *n)
{
	int i = 0;
	if(*n == 0)
	{
		return 0;
	}
	else
	{
		int index = rollno % SIZE;
		while(st[index].rno != rollno && i < *n)
		{
			index = (index+1) % SIZE;
			if(st[i].mark == 1)
			{
				i++;
			}
		}
		//while(st[index].mark != -1)
		if(st[index].rno == rollno  && st[index].mark == 1)
		{
			st[index].mark = -1;
			(*n)--;
			return 1;
		}
		return 0;	
	}
}

int searchintable(ST st[],int rollno, int n, char sname[])
{
	int i = 0;
	if(n == 0)
	{
		return 0;
	}
	else
	{	
		int index = rollno % SIZE;
		while(st[index].rno != rollno && i < n)
		{
			index = (index+1) % SIZE;
			if(st[i].mark == 1)
			{
				i++;
			}
		}
		if(st[index].rno == rollno  && st[index].mark == 1)
		{
			strcpy(sname,st[index].name);
			return 1;
		}
		return 0;		
	}
}