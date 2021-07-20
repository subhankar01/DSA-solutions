#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int top = -1;

void push(int *stack,int x)
{
    
    stack[++top] = x;
    
}

int pop(int *stack)
{
    return stack[top--];
    
}

int evaluatePostfix(int *stack,char* exp) 
{ 
    
  int i;
  
 
    for (i = 0; exp[i]!='\0'; ++i) 
    { 
         
        if(exp[i]==' '){continue; }
          
        
        else if (isdigit(exp[i])) 
        { 
            
              
            
            
            push(stack, exp[i] - '0');  
            
           
           
        } 
          
    
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': {push(stack, val2 + val1); break; }
            case '-': {push(stack, val2 - val1); break; }
            case '*': {push(stack, val2 * val1); break; }
            case '/': {push(stack, val2/val1); break; }
              
            } 
        } 
    } 
    return stack[0];

} 

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression");
   fgets(exp,100,stdin);
    e = exp;
    int n;
    printf("\nEnter size of stack \n");
    scanf("%d",&n);
    int *stack=(int *)malloc(n*sizeof(int));
    printf("\nThe evaulation is %d",evaluatePostfix(stack,e));
    return 0;
}
