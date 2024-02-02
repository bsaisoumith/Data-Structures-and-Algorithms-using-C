#include<stdio.h>

struct date
{
int dd;int mm;int yy;
};
typedef struct date date_t;
void read(date_t*);
void disp(const date_t*);
int is_month_matching(const date_t *,int);
int is_date_in_order(const date_t *,const date_t *);

struct event
{
char event_name[10];
date_t event_date;
};
typedef struct event event_t;
void read_event(event_t*);
void display_event(const event_t*);
int is_event_in_month(const event_t*,int);
int is_event_in_order(const event_t* lhs,const event_t* rhs);

void read_event_array(event_t*,int);
void display_event_array(const event_t*,int);
int count_of_events_in_month(const event_t[],int,int);

int main()
{
    event_t e[1000];
    printf("how many events you want to create\n");
    int n;
    scanf("%d",&n);
    printf("enter event details\n");
    read_event_array(e,n);
    printf("Details of events entered by the user are here\n");
    display_event_array(e,n);
    int mon;
    printf("If you want to know the count of events in paarticular month,enter the month number between 1 and 12\n");
    scanf("%d",&mon);
    if (mon<1 || mon>12)
        printf("this month number is invalid\n");
    else
        printf("number of events in month number %d are %d\n",mon,count_of_events_in_month(e,n,mon));
    int i,j;
    printf("enter two event numbers to check whether they are in order\n");
    scanf("%d %d",&i,&j);
    if(i>=0 && i<n && j>=0 && j<n)
    {
        if(is_event_in_order(&e[i],&e[j]))
            printf("in order\n");
        else
            printf("Not in order\n");
    }
    else 
    {
        printf("entered event number is not valid");
    }
    printf("THANK YOU\n");
    return 0;
}

void read(date_t* d)
{
    scanf("%d %d %d",&(d->dd),&(d->mm),&(d->yy));
}

void disp(const date_t* d)
{
    printf("%d/%d/%d\n",d->dd,d->mm,d->yy);
}

int is_month_matching(const date_t *d,int month)
{
    return (d->mm == month);
}

int is_date_in_order(const date_t *lhs,const date_t *rhs)
{
    return lhs->dd < rhs->dd;
}

void read_event(event_t* e)
{
    printf("enter the name of the event\n");
    scanf("%s",e->event_name);
    printf("enter the date\n");
    read(&(e->event_date));
}

void display_event(const event_t* e)
{
    printf("%s\t",e->event_name);
    disp(&(e->event_date));
}

int is_event_in_month(const event_t* e,int month)
{
    return is_month_matching(&(e->event_date),month);
}
int is_event_in_order(const event_t* e1,const event_t* e2)
{
    return is_date_in_order(&(e1->event_date),&(e2->event_date));
}

void read_event_array(event_t *e,int n)
{ 
    int i;
    for(i = 0; i< n; i++)
    {
        read_event(&(e[i])); // e+i is pointer notation
    }
}

void display_event_array(const event_t *e,int n )
{
    int i;
    for(i = 0; i< n; i++)
    {
        display_event(&(e[i])); // e+i
    }
}

int count_of_events_in_month(const event_t *e,int n, int month)
{
    int i;
    int count = 0;
    for(i = 0; i< n; i++)
    {
        if(is_event_in_month(&(e[i]),month)) 
            count++;
    }
    return count;
}





