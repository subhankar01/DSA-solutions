#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int top = -1;

void push(char *stack,char x)
{
    stack[++top] = x;
}

char pop(char *stack)
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    int n;
    printf("Enter the size of stack");
    scanf("%d",&n);
    char *stack=(char *)malloc(n*sizeof(char));

    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(stack,*e);
        else if(*e == ')')
        {
            while((x = pop(stack)) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop(stack));
            push(stack,*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop(stack));
    }return 0;
}
