// Lab 3

#include<stdio.h>
#include<ctype.h>
#include<limits.h>
#include<string.h>

typedef struct stack
{
    char a[100];
    int top;
}STACK;

void init(STACK *s);
void infix_to_prefix(char* infix, char* prefix);
int prec(char st,char c);
int isEmpty(STACK* s);
void push(STACK *s, int ele);
char pop(STACK *s);
char peek(STACK* s);
int eval_prefix(char *prefix);
void reverse(char *str1);
void replaceCharacters(char *str);
int precedence(char ch);


int main()
{
    printf("Enter the valid infix expression:\n");
    char infix[100];
    char prefix[100];
    scanf("%s", infix);
    reverse(infix);
    replaceCharacters(infix);
    infix_to_prefix(infix, prefix);
    reverse(prefix);
    printf("The prefix expression is %s\n",prefix);
    int result = eval_prefix(prefix);
    if(result != INT_MAX)
        printf("Result is %d\n",result);
    return 0; 
}

void replaceCharacters(char *str) 
{
    int length = strlen(str);
    int i;

    for (i = 0; i < length; i++) 
    {
        switch (str[i])
        {
            case '(': str[i] = ')';
                        break;
            case ')': str[i] = '(';
                        break;
            default:
                        break;
        }
    }

}

void reverse(char *str)  
{   
    int i, len, temp;  
    len = strlen(str);     
    for (i = 0; i < len/2; i++)  
    {  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
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

int eval_prefix(char *prefix)
{
    STACK s;
    init(&s);
    float op2,op1,res;
    for(int i = strlen(prefix) - 1; i >= 0; i--)
    {
        if(isdigit(prefix[i]))              // to check a digit in the given string
            push(&s, prefix[i] - '0');      // where '2' is char not a int, we have to push float value into the stack so. '2' - '0' = asciof 2 (50) - asciof 0 (48) = 2
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            switch(prefix[i])
            {
                case '+' : res = op1+op2; break;
                case '-' : res = op1-op2; break;
                case '*' : res = op1*op2; break;
                case '/' : 
                    if(op2 == 0)
                    {
                        printf("Sorry, division by zero exception");
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

void infix_to_prefix(char* infix, char* prefix)
{
    int k = 0;
    STACK s;
    init(&s);
    for(int i=0; infix[i] != '\0'; i++)
    {
        if(isdigit(infix[i]))
        {
            // prefix[k+1] = infix[i];
            prefix[k] = infix[i];
            k++;
        }
        else
        {
            if(infix[i] == '(')
            {
                push(&s, infix[i]);
            }
            else if(infix[i] == ')')
            {
                while (!isEmpty(&s) && peek(&s) != '(') 
                {
                    prefix[k] = pop(&s);
                    k++;
                }
                pop(&s);
            }
            else
            {
                while (!isEmpty(&s) && precedence(infix[i]) < precedence(peek(&s))) 
                {
                    prefix[k] = pop(&s);
                    k++;
                }
                push(&s, infix[i]);
            }
        }
    }
    while(!isEmpty(&s))
    {
        prefix[k] = pop(&s);
        k++;
    }
    prefix[k] = '\0';
}


int precedence(char ch)
{
    if(ch == '*' || ch=='/')
        return 2;
    else if(ch == '+' || ch=='-')
        return 1; 
    else
        return 0;
}

