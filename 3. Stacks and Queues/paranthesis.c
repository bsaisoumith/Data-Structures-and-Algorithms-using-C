#include<stdio.h>

typedef struct stack
{
    char a[100];
    int top;
}STACK;

int check_parentheses(char *p_exp);
void init(STACK *s);
void push(STACK *s, char ele);
char pop(STACK *s);
int isEmpty(STACK* s);

int main()
{
    printf("Enter the expression with parentheses\n");
    char exp[100];
    scanf("%s",exp);
    int result = check_parentheses(exp);
    if(result == 0)  // if(!result)
    {
        printf("Invalid\n");
    }
    else
    {
        printf("Valid\n");
    }
    return 0;
}

int check_parentheses(char *p_exp)
{
    STACK s;
    init(&s);
    for(int i=0; p_exp[i] != '\0'; i++)
    {
        if(p_exp[i] == '{' || p_exp[i] == '(' || p_exp == '[')
        {
            push(&s,p_exp[i]);
        }
        else if (p_exp[i] == '}' || p_exp[i] == ')' || p_exp == ']')
        {
            if(isEmpty(&s))
            {
                return 0;
            }   
            else
            {
                switch(p_exp[i])
                {
                    case '}': 
                        if(pop(&s) != '{')
                            return 0;
                        break;

                    case ')': 
                        if(pop(&s) != '(')
                            return 0;
                        break;

                    case ']': 
                        if(pop(&s) != '[')
                            return 0;
                        break;
                }
            }
        }
    }
    return isEmpty(&s);
}

void init(STACK *s)
{
    s->top = -1;
}

void push(STACK *s, char ele)
{
        s->top++;
        s->a[s->top] = ele;

        // s->a[++s->top] = ele;
}

char pop(STACK *s)
{
        char del_ele = s->a[s->top];
        s->top--;
        return del_ele;
}

int isEmpty(STACK* s)
{
    return s->top == -1;
}





