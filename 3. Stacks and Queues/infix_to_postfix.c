#include<stdio.h>
#include<ctype.h>
#include<limits.h>

typedef struct stack
{
    char a[100];
    int top;
}STACK;

void init(STACK *s);
void infix_to_postfix(char* infix, char* postfix);
int prec(char st,char c);
int isEmpty(STACK* s);
void push(STACK *s, int ele);
char pop(STACK *s);
char peek(STACK* s);
int eval_postfix(char *postfix);
void infix_to_postfix(char* infix, char* postfix);
int prec(char st,char c);

int main()
{
    printf("Enter the valid infix expression:\n");
    char infix[100];
    char postfix[100];
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("The postfix expression is %s\n",postfix);
    int result = eval_postfix(postfix);
    if(result != INT_MAX)
    {
        printf("Result is %d\n",result);
    }
    return 0;
}

int eval_postfix(char *postfix)
{
    STACK s;
    init(&s);
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        float op2,op1,res;
        if(isdigit(postfix[i]))              // to check a digit in the given string
            push(&s, postfix[i] - '0');      // where '2' is char not a int, we have to push float value into the stack so. '2' - '0' = asciof 2 (50) - asciof 0 (48) = 2
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(postfix[i])
            {
                case '+' : res = op2+op1; break;
                case '-' : res = op1-op2; break;
                case '*' : res = op2*op1; break;
                case '/' : 
                    if(op1 == 0)
                    {
                        printf("Sorry, division by zer exception");
                        return INT_MAX;                                 // or use the exit(0) to stop the complete execution of program
                    }
                    else
                        res = op1/op2;
                    break;
            }
            push(&s,res);
        }
    }
    return pop(&s);
}

void infix_to_postfix(char* infix, char* postfix)
{
    int k = 0;
    STACK s;
    init(&s);
    for(int i=0; infix[i] != '\0'; i++)
    {
        if(isdigit(infix[i]))
        {
            // postfix[k+1] = infix[i];
            postfix[k] = infix[i];
            k++;
        }
        else
        {
            while (!isEmpty(&s) && prec(infix[i],peek(&s))) 
            {
                    postfix[k] = pop(&s);
                    k++;
            }
            if(infix[i] == ')')
            {
                
                pop(&s);
            }
            else
            {
                push(&s, infix[i]);
            }
        }
    }
    while( !isEmpty(&s))
    {
        postfix[k] = pop(&s);
        k++;
    }
    postfix[k] = '\0';
}
int prec(char st,char c)
{
	switch(c)
	{
		case '+':
		case '-': if(st == '(')
					return 0;
				  return 1;
		case '*':
		case '/':if((st == '+') || (st == '-')|| (st == '('))
					return 0;
				 return 1;
		
		case '(':return 0;
		case ')': if(st == '(')
					return 0;
				   return 1;
				   
				 // return (st != '(');
				
	}
}

void init(STACK *s)
{
    s->top = -1;
}

int isEmpty(STACK* s)
{
    return s->top == -1;
}

void push(STACK *s, int ele)
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

char peek(STACK* s)
{
    return s->a[s->top];
}